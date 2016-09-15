/*
 * peer_uploader.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DLNA peer uploader APIs.  */

#include <dlna_peer.h>

#ifdef DLNA_SUPPORT_UPLOADER
#include "peer_uploader.h"

slim_int peer_uploader_read_file(peer_uploader_stream *upstream,
  slim_byte *out_buf, dlna_size_t in_length)
{
  if (fread(out_buf, in_length, 1, upstream->src) == 0)
	return SLIM_E_OK;
  return in_length;
}

slim_int peer_uploader_read_stream(peer_uploader_stream *upstream,
								   slim_byte *out_buf, dlna_size_t in_length)
{
	// todo: not implemented
	return peer_uploader_read_file(upstream, out_buf, in_length);
}

slim_int peer_uploader_event_open(void *in_arg)
{
	peer_uploader_stream *upstream = (peer_uploader_stream *)in_arg;
	if (!upstream) return SLIM_E_GENERIC;
	upstream->uploader->callback(DLNA_UPLOADER_OPEN, upstream->uploader->arg, (dlna_uploader_stream)upstream);
	EVENT_CANCEL (upstream->events[DLNA_UPLOADER_OPEN], upstream->uploader->progress);
	return SLIM_E_OK;
}

void peer_uploader_event_add(peer_uploader_stream *upstream, dlna_uploader_event event)
{
	EVENT_CANCEL(upstream->events[event], upstream->uploader->progress);
	switch (event)
	{
	case DLNA_UPLOADER_OPEN:
		EVENT_ADD_EVENT (upstream->events[event], upstream->uploader->progress, peer_uploader_event_open, upstream);
		break;
	}
}

dlna_uploader dlnaUploaderAllocPeer(dlna_progress in_progress, dlna_uploader_callback in_callback,
									void *in_callback_arg)
{
	if (!in_progress || !in_callback) {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "[dlnaUploaderAllocPeer] null pointer");
		return slim_nil;
	}

	peer_uploader *uploader = (peer_uploader *)dlna_memory_zeroalloc(sizeof(peer_uploader));
	if (!uploader) {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "[dlnaUploaderAllocPeer] out of memory");
		return slim_nil;
	}
	uploader->progress = in_progress;
	uploader->callback = in_callback;
	uploader->arg = in_callback_arg;
	return (dlna_uploader)uploader;
}

void dlnaUploaderFreePeer(dlna_uploader in_uploader)
{
	peer_uploader *uploader = (peer_uploader *)in_uploader;
	if (!uploader) return;
	dlna_memory_free(uploader);
	uploader = slim_nil;
}

dlna_uploader_stream dlnaUploaderOpenPeer(dlna_uploader in_uploader, slim_char *in_uri, slim_int in_flags)
{
	peer_uploader *uploader = (peer_uploader *)in_uploader;
	peer_uploader_stream *upstream = slim_nil;
	if (!uploader) {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "[dlnaUploaderOpenPeer] in_uploader null");
		return slim_nil;
	}
	upstream = (peer_uploader_stream *)dlna_memory_zeroalloc(sizeof(peer_uploader_stream));
	if (!upstream) {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "[dlnaUploaderOpenPeer] memory allocation");
		return slim_nil;
	}

	if (in_flags & DLNA_UPLOADER_FLAG_STREAM) {
		// todo: not implemented
		// file read is temporarly
		upstream->src = fopen((char *)(in_uri + 7), "rb");
		if (!upstream->src) {
			DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "[dlnaUploaderOpenPeer] error when opening stream file[%s]", in_uri);
			free (upstream);
			return slim_nil;
		}
		upstream->read_func = peer_uploader_read_stream;
	} else if (in_flags & DLNA_UPLOADER_FLAG_LOCAL) {
		upstream->src = fopen((char *)(in_uri + 7), "rb");
		if (!upstream->src) {
			DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "[dlnaUploaderOpenPeer] error when opening file[%s]", in_uri);
			free (upstream);
			return slim_nil;
		}
		upstream->read_func = peer_uploader_read_file;
	} else {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "dlnaUploaderOpenPeer->wrong_flag.");
		free(upstream);
		return slim_nil;
	}
	upstream->flags = in_flags;
	upstream->uploader = uploader;
	peer_uploader_event_add(upstream, DLNA_UPLOADER_OPEN);
	return (dlna_uploader_stream)upstream;
}

void dlnaUploaderClosePeer(dlna_uploader in_uploader, dlna_uploader_stream in_up_stream)
{
	peer_uploader *uploader = (peer_uploader *)in_uploader;
	peer_uploader_stream *upstream = (peer_uploader_stream *)in_up_stream;
	if (!uploader || !upstream) return;
	if (upstream->flags & DLNA_UPLOADER_FLAG_STREAM) {
		// todo: not implemented
		if (upstream->src) {
			fclose(upstream->src);
			upstream->src = slim_nil;
		}
	} else if (upstream->flags & DLNA_UPLOADER_FLAG_LOCAL) {
		if (upstream->src) {
			fclose(upstream->src);
			upstream->src = slim_nil;
		}
	} else {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "dlnaUploaderClosePeer->wrong_flag.");
	}

	upstream->uploader = slim_nil;
	upstream->read_func = slim_nil;
	free(upstream);
}

slim_int dlnaUploaderReadPeer(dlna_uploader_stream in_up_stream,
							  slim_byte *out_buf, dlna_size_t in_length)
{
	peer_uploader_stream *upstream = (peer_uploader_stream *)in_up_stream;
	if (!upstream || !upstream->read_func) {
		DLNA_LOG(DLNA_LOG_PEER_UPLOADER, DLNA_LOG_LEVEL_ERROR, "dlnaUploaderReadPeer Error!!!");
		return SLIM_E_GENERIC;
	}
	return upstream->read_func(upstream, out_buf, in_length);
}

#endif /* DLNA_SUPPORT_UPLOADER */
