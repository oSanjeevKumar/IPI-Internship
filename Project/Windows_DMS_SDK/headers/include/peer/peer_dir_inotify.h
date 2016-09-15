#ifndef PEER_DIR_INOTIFY_H
#define PEER_DIR_INOTIFY_H

#ifdef ENABLE_DCN_INOTIFY

#define MAX_PATH_LEN				(1024)
#define DCN_NOTIFY_TIMEOUT			(1)
#define DCN_NOTIFY_FNI_BUFFER_SIZE	(sizeof(FILE_NOTIFY_INFORMATION) + sizeof(WCHAR) * 1023)
#define DCN_NOTIFY_FILTER				\
	(FILE_NOTIFY_CHANGE_FILE_NAME	|	\
	FILE_NOTIFY_CHANGE_DIR_NAME		|	\
	FILE_NOTIFY_CHANGE_ATTRIBUTES	|	\
	FILE_NOTIFY_CHANGE_SIZE			|	\
	FILE_NOTIFY_CHANGE_LAST_WRITE	|	\
	FILE_NOTIFY_CHANGE_LAST_ACCESS	|	\
	FILE_NOTIFY_CHANGE_CREATION		|	\
	FILE_NOTIFY_CHANGE_SECURITY)

typedef struct _dcn_inotify_event_element {
	struct _dcn_inotify_event_element *prev;
	struct _dcn_inotify_event_element *next;
	DWORD action;
	dcn_reaction_type reaction_type;
	slim_char *path;
	slim_char *full_path;
} dcn_inotify_event_element;

ListNamed(dcn_inotify_event_element *, dcn_inotify_event_elements_list);

typedef struct _dcn_inotify_thread_data {
	slim_char *path;
	dlna_mutex changes_mutex;
	struct dcn_inotify_event_elements_list notify_events;
	HANDLE dir_handle;
	FILE_NOTIFY_INFORMATION *fni;
} dcn_inotify_thread_data;

typedef struct _dcn_inotify_notification {
	dlna_progress em;							// progress
	dlna_progress_handle h_timer;					// handle to the timer event
	dlna_dcn_callback pfn;						// callback function to call when notification comes
	is_file_excluded_callback is_file_excluded;	// callback function to check if directory entry is on exclusion list
	void *arg;								// argument to be passed back to the caller
	slim_char *path;
	dlna_thread changes_thread;
	dlna_mutex changes_mutex;
	slim_bool started;							// true if start function was already called, false after call to stop function
	dcn_inotify_thread_data thread_data;
} dcn_inotify_notification;

int dcn_inotify_changes_thread_procedure(void *in_arg);
slim_bool dcn_inotify_get_dir_handle(slim_char *path, HANDLE *handle);
void dcn_inotify_add_notify_event(dcn_inotify_thread_data *td, FILE_NOTIFY_INFORMATION *fni);
slim_char *dcn_inotify_get_full_path(slim_char *path, FILE_NOTIFY_INFORMATION *fni);
slim_char *dcn_inotify_get_relative_path(FILE_NOTIFY_INFORMATION *fni);
void dcn_inotify_register_timer(dcn_inotify_notification *n);
void dcn_inotify_unregister_timer(dcn_inotify_notification *n);
slim_int dcn_inotify_timeout_procedure(void *in_arg);
dcn_inotify_event_element *dcn_inotify_if_is_new(dcn_inotify_notification *n, struct dcn_inotify_event_elements_list *list, dcn_inotify_event_element *ee);
void dcn_inotify_clear_events_list(struct dcn_inotify_event_elements_list *list);
void dcn_inotify_clean_thread_data(dcn_inotify_thread_data *td);
void dcn_inotify_stop_thread(dcn_inotify_notification *n);
void dcn_inotify_finalize(dcn_inotify_notification *n);
slim_bool dcn_inotify_exclude_file(slim_char *full_path);

#endif /* ENABLE_DCN_INOTIFY */

#endif /* PEER_DIR_INOTIFY_H */
