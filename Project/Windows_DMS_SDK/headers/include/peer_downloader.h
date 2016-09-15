/*
 * peer_downloader.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_PEER_DOWNLOADER_H
#define NFLC_PEER_DOWNLOADER_H

typedef struct peer_downloader peer_downloader_t;
typedef struct peer_downloader_stream peer_downloader_stream_t;


struct peer_downloader
{
	/* Progress.  */
	dlna_progress em;

	/* Uploader callback.  */
	dlna_downloader_callback callback;

	/* Uploader callback argument.  */
	void *callback_arg;
};


/* Content stream.  */
struct peer_downloader_stream
{
	struct peer_downloader *downloader;

	/* file descriptor */
	dlna_file_t desc;

	slim_int flags;
	
	/* Path name for the file.  */
	slim_char *file_path;

	/* Events.  */
	dlna_progress_handle e_event[DLNA_DOWNLOADER_EVENT_MAX];
};

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* NFLC_PEER_DOWNLOADER_H */
