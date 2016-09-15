/*
 * peer_downloader.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DLNA peer downloader APIs.  */

#include <dlna_peer.h>

#if defined (DLNA_SUPPORT_DOWNLOADER_PEER) && defined (DLNA_SUPPORT_DOWNLOADER)
#include <direct.h>
#include <peer_downloader.h>


void peer_downloader_try_create_directory(slim_char *file_path)
{
	if (!file_path) {
		DLNA_LOG(DLNA_LOG_PEER_DOWNLOADER, DLNA_LOG_LEVEL_ERROR, "[peer_downloader_try_create_directory] file path null");
		return;
	}
	slim_char *dir_path = slim_nil;
	slim_int len = strrchr(file_path, PATH_SEPARATOR_CHAR) - file_path;
	dir_path = dlna_memory_zeroalloc(len + 1);
	dlna_strncpy(dir_path, file_path, len);
	dlnaDownloaderCreateDownloadDir(dir_path);
	dlna_memory_free(dir_path);
}

slim_int peer_downloader_open_event(void *in_arg)
{
	peer_downloader_stream_t *dnstream = (peer_downloader_stream_t *)in_arg;
	if (!dnstream) return SLIM_E_GENERIC;
	EVENT_CANCEL(dnstream->e_event[DLNA_DOWNLOADER_OPEN], dnstream->downloader->em);
	dnstream->downloader->callback(DLNA_DOWNLOADER_OPEN, dnstream->downloader->callback_arg, (dlna_downloader_stream)dnstream);
	return SLIM_E_OK;
}

slim_int peer_downloader_close_event(void *in_arg)
{
	peer_downloader_stream_t *dnstream = (peer_downloader_stream_t *)in_arg;
	if (!dnstream) return SLIM_E_GENERIC;
	EVENT_CANCEL(dnstream->e_event[DLNA_DOWNLOADER_CLOSE], dnstream->downloader->em);
	fclose((FILE *)dnstream->desc);
	dnstream->desc = 0;
	dnstream->downloader->callback(DLNA_DOWNLOADER_CLOSE, dnstream->downloader->callback_arg, (dlna_downloader_stream)dnstream);
	if (dnstream->file_path) {
		dlna_memory_free(dnstream->file_path);
		dnstream->file_path = slim_nil;
	}
	dlna_memory_free(dnstream);
	return SLIM_E_OK;
}

slim_bool peer_downloader_event_add(peer_downloader_stream_t *dnstream, dlna_downloader_event event)
{
	if (!dnstream || dnstream->e_event[event] != DLNA_INVALID_PROGRESS_HANDLE) return slim_false;
	switch (event)
	{
	case DLNA_DOWNLOADER_OPEN:
		DLNA_LOG(DLNA_LOG_PEER_DOWNLOADER, DLNA_LOG_LEVEL_DEBUG, "[peer_downloader_event_add] Adding event DLNA_DOWNLOADER_OPEN");
		EVENT_ADD_EVENT(dnstream->e_event[event], dnstream->downloader->em, peer_downloader_open_event, dnstream);
		break;
	case DLNA_DOWNLOADER_CLOSE:
		DLNA_LOG(DLNA_LOG_PEER_DOWNLOADER, DLNA_LOG_LEVEL_DEBUG, "[peer_downloader_event_add] Adding event DLNA_DOWNLOADER_CLOSE");
		EVENT_ADD_EVENT(dnstream->e_event[event], dnstream->downloader->em, peer_downloader_close_event, dnstream);
		break;
	}
	return slim_true;
}

dlna_downloader dlnaDownloaderAllocPeer(dlna_progress in_progress, dlna_downloader_callback in_callback,
										void *in_callback_arg)
{
	if (!in_progress || !in_callback) {
		DLNA_LOG(DLNA_LOG_PEER_DOWNLOADER, DLNA_LOG_LEVEL_ERROR, "dlnaDownloaderAllocPeer null pointer");
		return slim_nil;
	}
	peer_downloader_t *downloader = (peer_downloader_t *)dlna_memory_zeroalloc(sizeof(peer_downloader_t));
	if (!downloader) return slim_nil;
	downloader->em = in_progress;
	downloader->callback = in_callback;
	downloader->callback_arg = in_callback_arg;
	return (dlna_downloader)downloader;
}

void dlnaDownloaderFreePeer(dlna_downloader in_downloader)
{
	peer_downloader_t *downloader = (peer_downloader_t *)in_downloader;
	if (!downloader) return;
	dlna_memory_free(downloader);
}

dlna_downloader_stream dlnaDownloaderOpenPeer(dlna_downloader in_downloader, slim_char *download_path, slim_int in_flags)
{
	peer_downloader_t *downloader = (peer_downloader_t *)in_downloader;
	peer_downloader_stream_t *dnstream = slim_nil;
	if (!downloader) {
		DLNA_LOG(DLNA_LOG_PEER_DOWNLOADER, DLNA_LOG_LEVEL_ERROR, "dlnaDownloaderOpenPeer null pointer");
		return slim_nil;
	}

	dnstream = (peer_downloader_stream_t *)dlna_memory_zeroalloc(sizeof(peer_downloader_stream_t));
	if (!dnstream) return slim_nil;

	dnstream->desc = (dlna_file_t)fopen(download_path, "wb");
	if (!dnstream->desc) {
		peer_downloader_try_create_directory(download_path);
		dnstream->desc = (dlna_file_t)fopen(download_path, "wb");
	}
	if (!dnstream->desc) {
		dlna_memory_free(dnstream);
		return slim_nil;
	}
	dnstream->downloader = downloader;
	dnstream->file_path = dlna_strdup(download_path);
	dnstream->flags = in_flags;

	if (!peer_downloader_event_add(dnstream, DLNA_DOWNLOADER_OPEN)) {
		fclose((FILE *)dnstream->desc);
		dlna_memory_free(dnstream->file_path);
		dlna_memory_free(dnstream);
		return slim_nil;
	}

	return (dlna_downloader_stream)dnstream;
}

slim_int dlnaDownloaderClosePeer(dlna_downloader_stream in_down_stream)
{
	if (!peer_downloader_event_add((peer_downloader_stream_t *)in_down_stream, DLNA_DOWNLOADER_CLOSE))
		return SLIM_E_GENERIC;
	return SLIM_E_OK;
}

slim_int dlnaDownloaderWritePeer(dlna_downloader_stream in_stream,
								 slim_byte *in_buf, dlna_size_t in_length)
{
	peer_downloader_stream_t *dnstream = (peer_downloader_stream_t *)in_stream;
	if (!dnstream || !dnstream->desc || !in_buf) {
		DLNA_LOG(DLNA_LOG_PEER_DOWNLOADER, DLNA_LOG_LEVEL_ERROR, "dlnaDownloaderWritePeer null pointer");
		return;
	}

	return fwrite(in_buf, in_length, 1, (FILE *)dnstream->desc);
}

slim_int dlnaDownloaderStartPeer(dlna_downloader_stream in_stream)
{
	return SLIM_E_GENERIC;
}

slim_int dlnaDownloaderPausePeer(dlna_downloader_stream in_stream)
{
	return SLIM_E_GENERIC;
}

slim_int dlnaDownloaderStopPeer(dlna_downloader_stream in_stream)
{
	return SLIM_E_GENERIC;
}

slim_int dlnaDownloaderCreateDownloadDir(slim_char *in_path)
{
	slim_char *subdir_path = slim_nil;
	slim_int len = 0;
	slim_int ret;

	if (!in_path) return SLIM_E_GENERIC;

	if (in_path[strlen(in_path)] == PATH_SEPARATOR_CHAR)
		in_path[strlen(in_path)] = '\0';

	if (strlen(in_path) <= 2)
		return SLIM_E_OK;

	len = strrchr(in_path, PATH_SEPARATOR_CHAR) - in_path;
	subdir_path = dlna_memory_zeroalloc(len + 1);
	dlna_strncpy(subdir_path, in_path, len);
	ret = dlnaDownloaderCreateDownloadDir(subdir_path);
	dlna_memory_free(subdir_path);


	if (ret == SLIM_E_OK && mkdir((char *)in_path) == 0)
		return SLIM_E_OK;
	return SLIM_E_GENERIC;
}

#endif /* defined (DLNA_SUPPORT_DOWNLOADER_PEER) && defined (DLNA_SUPPORT_DOWNLOADER) */
