/*
 * peer_dir_inotify.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DLNA peer directory inotify APIs. */

#include <dlna_peer.h>
#include "peer_thread.h"
#include "peer_dir_inotify.h"

#ifdef ENABLE_DCN_INOTIFY

dlna_dcn dlnaDCNAllocPeer(dlna_progress in_p,
						  dlna_dcn_callback in_callback,
						  is_file_excluded_callback is_file_excluded,
						  void *in_arg)
{
	dcn_inotify_notification *n = dlna_memory_alloc(sizeof(dcn_inotify_notification));
	if (!n) return slim_nil;
	dlna_memset(n, 0, sizeof(dcn_inotify_notification));

	n->em = in_p;
	n->h_timer = DLNA_INVALID_PROGRESS_HANDLE;
	n->pfn = in_callback;
	n->is_file_excluded = is_file_excluded;
	n->arg = in_arg;
	n->started = slim_false;
	n->thread_data.dir_handle = INVALID_HANDLE_VALUE;
	ListInit(&n->thread_data.notify_events);

	return (dlna_dcn)n;
}

// free the peer content directory service structure
void dlnaDCNFreePeer(dlna_dcn in_dcn)
{
	dcn_inotify_notification *n = (dcn_inotify_notification *)in_dcn;
	if (!n) return;
	dlnaDCNStopPeer(n);
	dlna_memory_free(n);
}

// start the peer content directory service
slim_int dlnaDCNStartPeer(dlna_dcn in_dcn,
						  slim_char *in_dir)
{
	dcn_inotify_notification *n = (dcn_inotify_notification *)in_dcn;
	if (!n || !in_dir || n->started) return -1;
	n->changes_thread = dlnaThreadAllocPeer(dcn_inotify_changes_thread_procedure, &n->thread_data);
	if (!n->changes_thread) return -1;
  //dlnaThreadSetPriority(n->changes_thread, THREAD_PRIORITY_BELOW_NORMAL);
	n->changes_mutex = dlnaThreadMutexAllocPeer();
	if (!n->changes_mutex) {
		dlnaThreadFreePeer(n->changes_thread);
		return -1;
	}
	n->thread_data.changes_mutex = n->changes_mutex;
	n->path = dlna_strdup(in_dir);
	n->thread_data.path = dlna_strdup(in_dir);
	if (dlnaThreadStartPeer(n->changes_thread) != SLIM_E_OK) {
		dlna_memory_free(n->thread_data.path);
		n->thread_data.path = slim_nil;
		dlna_memory_free(n->path);
		n->path = slim_nil;
		dlnaThreadMutexFreePeer(n->changes_mutex);
		dlnaThreadFreePeer(n->changes_thread);
		n->thread_data.changes_mutex = slim_nil;
		n->changes_mutex = slim_nil;
		n->changes_thread = slim_nil;
		return -1;
	}
	n->started = slim_true;
	dcn_inotify_register_timer(n);
	return 0;
}

// stop the peer content directory service
void dlnaDCNStopPeer(dlna_dcn in_dcn)
{
  DLNA_FUNC_ENTER(dlnaDCNStopPeer);
  dcn_inotify_notification *n = (dcn_inotify_notification *)in_dcn;
	if (!n || !n->started) return;
	dcn_inotify_unregister_timer(n);
	dcn_inotify_stop_thread(n);
	dcn_inotify_clean_thread_data(&n->thread_data);
	// dcn_inotify_finalize
	dcn_inotify_finalize(n);
  DLNA_FUNC_EXIT(dlnaDCNStopPeer);

}

int dcn_inotify_changes_thread_procedure(void *in_arg)
{
	dcn_inotify_thread_data *td = slim_nil;
	FILE_NOTIFY_INFORMATION *fni = slim_nil;
	dlna_mutex changes_mutex;
	HANDLE dir_handle;
	DWORD fni_bytes_read;

	if (!(td = (dcn_inotify_thread_data *)in_arg))
		return -1;
	changes_mutex = td->changes_mutex;

	fni = (FILE_NOTIFY_INFORMATION *)dlna_memory_alloc(DCN_NOTIFY_FNI_BUFFER_SIZE);
	if (!fni)
		return -1;

	dlnaThreadMutexLockPeer(changes_mutex);
	if (!dcn_inotify_get_dir_handle(td->path, &dir_handle)) {
		dlnaThreadMutexUnlockPeer(changes_mutex);
		return -1;
	}
	// preparing buffer for notify information 
	// save info in dcn_inotify_thread_data to close handle and free memory while killing thread
	td->fni = fni;
	td->dir_handle = dir_handle;
	dlnaThreadMutexUnlockPeer(changes_mutex);

	// main directory change notify loop
	while (slim_true) {
		// wait for notification
#if (_WIN32_WINNT <= 0x0602 /*_WIN32_WINNT_WIN8*/)
		ReadDirectoryChangesW(
			dir_handle,
			fni,
			DCN_NOTIFY_FNI_BUFFER_SIZE,
			TRUE,
			DCN_NOTIFY_FILTER,
			&fni_bytes_read,
			NULL,
			NULL);
#else
        //TODO:For windows phone directory changes needs to be implemented
#endif
		dlnaThreadMutexLockPeer(changes_mutex);
		dcn_inotify_add_notify_event(td, fni);
		dlnaThreadMutexUnlockPeer(changes_mutex);
	}
}

slim_bool dcn_inotify_get_dir_handle(slim_char *path, HANDLE *handle)
{
	HANDLE tmp_handle;
	slim_int wide_path_len;
	TCHAR *wide_path = slim_nil;
	// changing path to wide
	wide_path_len = dlnaCS_UTF8_to_Wide(path, NULL, 0);
	if (wide_path_len <= 0) return slim_false;
	wide_path = (TCHAR *)dlna_memory_alloc(sizeof(TCHAR) * wide_path_len);
	dlnaCS_UTF8_to_Wide(path, wide_path, wide_path_len);
	// getting monitored directory handle
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	tmp_handle = CreateFile2(wide_path,
					  FILE_LIST_DIRECTORY,
					  FILE_SHARE_READ |
					  FILE_SHARE_WRITE |
					  FILE_SHARE_DELETE, OPEN_EXISTING, NULL);
#else
	tmp_handle = CreateFile(
	  wide_path,
	  FILE_LIST_DIRECTORY,
	  FILE_SHARE_READ |
	  FILE_SHARE_WRITE |
	  FILE_SHARE_DELETE,
	  NULL,
	  OPEN_EXISTING,
	  FILE_FLAG_BACKUP_SEMANTICS,
	  NULL);
#endif
	dlna_memory_free(wide_path);

	// determine if handle is correct
	if (!tmp_handle || tmp_handle == INVALID_HANDLE_VALUE)
		return slim_false;

	*handle = tmp_handle;
	return slim_true;
}

static slim_char* getSubfolderPath(slim_char *fullPath){
	slim_char* subFolderPath = slim_nil;
	slim_int subFolderPathLength = 0;
	if (fullPath){
		subFolderPath = dlna_strrstr(fullPath, PATH_SEPARATOR);
		if (subFolderPath){
			subFolderPathLength = dlna_strlen(fullPath) - dlna_strlen(subFolderPath);
			subFolderPath = (slim_char *)dlna_memory_alloc(subFolderPathLength + 1);
			if (subFolderPath){
				dlna_memset(subFolderPath, 0, subFolderPathLength + 1);
				dlna_strncpy(subFolderPath, fullPath, subFolderPathLength);
			}
		}
	}
	return subFolderPath;
}

static slim_bool checkSubfolderExist(slim_char *realtivePath, slim_char *fullPath){
	slim_bool ret = slim_false;
	dlna_stat fst;
	slim_char *temp;
	if ((fullPath) && (realtivePath) && (dlnaFileSystemStatPeer(fullPath, &fst) < 0)){
		temp = dlna_strstr(fullPath, realtivePath);
		if (temp) {
			temp = dlna_strstr(realtivePath, PATH_SEPARATOR);
			if (temp){
				return slim_true;
			}
		}
	}
	return ret;
}

void dcn_inotify_add_notify_event(dcn_inotify_thread_data *td, FILE_NOTIFY_INFORMATION *fni)
{
	DWORD fni_jump = 0;
	dcn_inotify_event_element *ee;
	slim_char *subFolderPath = slim_nil;
	do {
		// jump to another instance of FILE_NOTIFY_INFORMATION
		fni = (FILE_NOTIFY_INFORMATION *)(((char *)fni) + fni_jump);

		ee = (dcn_inotify_event_element *)dlna_memory_alloc(sizeof(dcn_inotify_event_element));
		if (!ee) continue;
		dlna_memset(ee, 0, sizeof(dcn_inotify_event_element));
		if (!(ee->path = dcn_inotify_get_relative_path(fni))) {
			dlna_memory_free(ee);
			continue;
		}
		if (!(ee->full_path = dcn_inotify_get_full_path(td->path, fni))) {
			dlna_memory_free(ee->path);
			dlna_memory_free(ee);
			continue;
		}
		
		ee->action = fni->Action;
    if (((ee->action == FILE_ACTION_REMOVED) || (ee->action == FILE_ACTION_RENAMED_OLD_NAME)) && (td->path)){
			if (!checkSubfolderExist(ee->path, ee->full_path)){
				dlna_strcpy(ee->full_path, td->path);
			}else{
				subFolderPath = getSubfolderPath(ee->full_path);
				if (subFolderPath){
					dlna_memory_free(ee->full_path);
					ee->full_path = subFolderPath;
				}
			}
    }
		ListAdd(&td->notify_events, ee);
	} while (fni_jump = fni->NextEntryOffset);
}

slim_char *dcn_inotify_get_full_path(slim_char *path, FILE_NOTIFY_INFORMATION *fni) {
	slim_char *relative_path = slim_nil;
	slim_char *full_path = slim_nil;

	// convert FILE_NOTIFY_INFORMATION file name from wide character to utf8
	relative_path = dcn_inotify_get_relative_path(fni);
	if (!relative_path) return slim_nil;

	// concatenation notify_info with 'path' to get a full path of changed location
	full_path =
		(slim_char *)dlna_memory_alloc(
		dlna_strlen(path) +
		dlna_strlen(relative_path) + 2);
	if (!full_path) {
		dlna_memory_free(relative_path);
		return slim_nil;
	}
	dlna_strcpy(full_path, path);
	dlna_strcat(full_path, PATH_SEPARATOR);
	dlna_strcat(full_path, relative_path);
	dlna_memory_free(relative_path);
	return full_path;
}

slim_char *dcn_inotify_get_relative_path(FILE_NOTIFY_INFORMATION *fni) {
	slim_char *notify_path = slim_nil;

	// convert FILE_NOTIFY_INFORMATION file name from wide character to utf8
	notify_path = (slim_char *)dlna_memory_alloc((fni->FileNameLength / sizeof(TCHAR)) + 1);
	if (!notify_path) return slim_nil;
	dlnaCS_Wide_to_UTF8(fni->FileName, notify_path, fni->FileNameLength / sizeof(TCHAR));
	notify_path[fni->FileNameLength / sizeof(TCHAR)] = '\0';

	return notify_path;
}

void dcn_inotify_register_timer(dcn_inotify_notification *n)
{
	if (n->h_timer == DLNA_INVALID_PROGRESS_HANDLE)
		EVENT_ADD_TIMER(
		n->h_timer,
		n->em,
		dcn_inotify_timeout_procedure,
		n,
		DCN_NOTIFY_TIMEOUT);
}


void dcn_inotify_unregister_timer(dcn_inotify_notification *n)
{
	if (n->h_timer != DLNA_INVALID_PROGRESS_HANDLE) {
		EVENT_CANCEL(n->h_timer, n->em);
		n->h_timer = DLNA_INVALID_PROGRESS_HANDLE;
	}
}

slim_int dcn_inotify_timeout_procedure(void *in_arg)
{
	dcn_inotify_notification *n = (dcn_inotify_notification *)in_arg;
	dcn_inotify_event_element *ee, *del_ee, *new_ee;
	struct dcn_inotify_event_elements_list proccess_list;
	if (!n) return -1;
	n->h_timer = DLNA_INVALID_PROGRESS_HANDLE;
	ListInit(&proccess_list);

	dlnaThreadMutexLockPeer(n->changes_mutex);
	ListLoopForDel(&n->thread_data.notify_events, ee, del_ee) {
		if (new_ee = dcn_inotify_if_is_new(n, &proccess_list, ee)) {
			ListAdd(&proccess_list, new_ee);
		}
		dlna_memory_free(ee->path);
		dlna_memory_free(ee->full_path);
		ListDelete(&n->thread_data.notify_events, ee);
	}
	dlnaThreadMutexUnlockPeer(n->changes_mutex);

	ListLoopForDel(&proccess_list, ee, del_ee) {
		n->pfn(ee->full_path, n->arg, ee->reaction_type);
		dlna_memory_free(ee->path);
		dlna_memory_free(ee->full_path);
		ListDelete(&proccess_list, ee);
	}

	dcn_inotify_register_timer(n);
	return 0;
}

dcn_inotify_event_element *dcn_inotify_if_is_new(dcn_inotify_notification *n, struct dcn_inotify_event_elements_list *list, dcn_inotify_event_element *ee)
{
	dcn_inotify_event_element *ret_ee = slim_nil, *i_ee;
	slim_bool has = slim_false;
	
	if (!dlna_strncmp(ee->path, DMS_WINDOWS_XML, 4)){
	  return slim_nil;
	}
	dlna_stat stat;
    if (dlnaFileSystemStatPeer(ee->full_path, &stat) < 0) {
      DLNA_LOG(DLNA_LOG_PEER_DIR, DLNA_LOG_LEVEL_DEBUG, "Not valid path:%s ", ee->full_path);
      return slim_nil;
	}
	
    DLNA_LOG(DLNA_LOG_PEER_DIR, DLNA_LOG_LEVEL_DEBUG, "FullPath:%s, RelativePath:%s", ee->full_path, ee->path);
	
    if (n->is_file_excluded(n->arg, ee->full_path, stat.mode&_S_IFDIR)) {
      DLNA_LOG(DLNA_LOG_PEER_DIR, DLNA_LOG_LEVEL_DEBUG, "Skipped this path:%s for indexing", ee->full_path);
      return slim_nil;
	}
	
	switch (ee->action) {
	  case FILE_ACTION_ADDED:
	  case FILE_ACTION_MODIFIED:
	  case FILE_ACTION_RENAMED_NEW_NAME:
		  ee->reaction_type = DLNA_DCN_REACTION_TYPE_REINDEX;
		  break;
	  case FILE_ACTION_REMOVED:
	  case FILE_ACTION_RENAMED_OLD_NAME:
		ee->reaction_type = DLNA_DCN_REACTION_TYPE_DELETE;
		break;
	}
	ListLoop(list, i_ee) {
		if ((i_ee->reaction_type == ee->reaction_type) && !dlna_strcmp_nocase(i_ee->path, ee->path)) {
			has = slim_true;
			break;
		}
	}
	if (!has) {
		ret_ee = (dcn_inotify_event_element *)dlna_memory_alloc(sizeof(dcn_inotify_event_element));
		if (!ret_ee) return slim_nil;
		dlna_memset(ret_ee, 0, sizeof(dcn_inotify_event_element));
		ret_ee->action = ee->action;
		ret_ee->reaction_type = ee->reaction_type;
		ret_ee->full_path = ee->full_path;
		ret_ee->path = ee->path;
		ee->full_path = slim_nil;
		ee->path = slim_nil;
	}
	return ret_ee;
}

void dcn_inotify_clear_events_list(struct dcn_inotify_event_elements_list *list)
{
	dcn_inotify_event_element *ee, *tmp_ee;
	ListLoopForDel(list, ee, tmp_ee) {
		dlna_memory_free(ee->path);
		dlna_memory_free(ee->full_path);
		ListDelete(list, ee);
	}
}

void dcn_inotify_clean_thread_data(dcn_inotify_thread_data *td)
{
	dlna_memory_free(td->fni);
	td->fni = slim_nil;
	CloseHandle(td->dir_handle);
	td->dir_handle = INVALID_HANDLE_VALUE;
	dlna_memory_free(td->path);
	td->path = slim_nil;
	td->changes_mutex = slim_nil;
	dcn_inotify_clear_events_list(&td->notify_events);
}

void dcn_inotify_stop_thread(dcn_inotify_notification *n)
{
	thread_info *ti = (thread_info *)n->changes_thread;
	if (!ti) return;
	dlnaThreadMutexLockPeer(n->changes_mutex);
#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/)
	WaitForSingleObjectEx(ti->handle, INFINITE, slim_false);
#else
	TerminateThread(ti->handle, 0);
#endif
	dlnaThreadFreePeer(n->changes_thread);
	n->changes_thread = slim_nil;
	dlnaThreadMutexUnlockPeer(n->changes_mutex);
}

void dcn_inotify_finalize(dcn_inotify_notification *n)
{
	dlnaThreadMutexFreePeer(n->changes_mutex);
	n->changes_mutex = slim_nil;
	dlna_memory_free(n->path);
	n->path = slim_nil;
	n->started = slim_false;
}


void dlnaDCNAddDirectoryToWatchList(dlna_dcn in_dcn,
									slim_char *in_device_path,
									slim_char *in_path)
{ }

slim_int dlnaDCNGetRecentChangeIsDir(dlna_dcn in_dcn)
{
	return 0;
}

void dlnaDCNRemoveDirectoryFromWatchList(dlna_dcn in_dcn,
										 slim_char *in_dir)
{ }

slim_char *dlnaDCNGetRecentPath(dlna_dcn in_dcn)
{
	return slim_nil;
}

slim_int dlnaDCNGetChangeType(dlna_dcn in_dcn)
{
	return -1;
}

void dlnaDCNResetChanged(dlna_dcn in_dcn)
{ }

void dlnaDCNPause(dlna_dcn in_dcn)
{ }

void dlnaDCNResume(dlna_dcn in_dcn)
{ }

#endif /* ENABLE_DCN_INOTIFY */
