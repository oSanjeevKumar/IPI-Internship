/*
* peer_push_server.c
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/


/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#include <dlna_peer.h>

#ifdef DLNA_SUPPORT_RUIPL
#include <nflc_sxml.h>
#include <dlna_memory.h>
#endif
#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
#include "mongoose.h"

struct mg_context *ctx = slim_nil;

static void *callback(enum mg_event event,
struct mg_connection *conn,
	const struct mg_request_info *request_info) {
	if (event == MG_NEW_REQUEST) {
		// Echo requested URI back to the client
		mg_send_file(conn, request_info->uri);
		return "";  // Mark as processed
	}
	else if (event == MG_HTTP_ERROR) {
		DLNA_LOG(DLNA_LOG_PEER_PUSH_SERVER, DLNA_LOG_LEVEL_DEBUG, "[DMC PUSH SErver] MG_HTTP_ERROR\n");
		return "";  // Mark as processed
	}
	else if (event == MG_EVENT_LOG) {
		DLNA_LOG(DLNA_LOG_PEER_PUSH_SERVER, DLNA_LOG_LEVEL_DEBUG, "[DMC PUSH SErver] MG_EVENT_LOG\n");
		return "";  // Mark as processed
	}
	else if (event == MG_REQUEST_COMPLETE) {
		DLNA_LOG(DLNA_LOG_PEER_PUSH_SERVER, DLNA_LOG_LEVEL_DEBUG, "[DMC PUSH SErver] MG_REQUEST_COMPLETE\n");
		return "";  // Mark as processed
	}
	else {
		return slim_nil;
	}
}

slim_opaque
dlnaDMCPushLocalServerStartPeer(slim_int* out_port)
{
	DLNA_LOG(DLNA_LOG_PEER_PUSH_SERVER, DLNA_LOG_LEVEL_DEBUG, "[DMC PUSH SErver] Entered dlnaDMCPushLocalServerStartPeer\n");
	const char *options[] = { "listening_ports", "8080", slim_nil };
	if (ctx == slim_nil) {
		ctx = mg_start(&callback, slim_nil, options);
	}
	*out_port = 8080;
	return (slim_opaque)ctx;
}

void
dlnaDMCPushLocalServerStoptPeer(slim_opaque server_context)
{
	DLNA_LOG(DLNA_LOG_PEER_PUSH_SERVER, DLNA_LOG_LEVEL_DEBUG, "[DMC PUSH SErver] Entered dlnaDMCPushLocalServerStoptPeer\n");
	mg_stop((struct mg_context *)server_context);
	ctx = slim_nil;
}
#endif /* DEVELOPMENT_DIRECT_DLNA_OBJECT */