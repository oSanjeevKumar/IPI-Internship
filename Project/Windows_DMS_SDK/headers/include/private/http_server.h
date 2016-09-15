/*
 * http_server.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_HTTP_SERVER_H
#define NFLC_HTTP_SERVER_H

#include <upnp_server.h>

#if defined (DLNA_UPLOAD_AKE_AFTER_HTTP_POST) && defined (HAVE_DTCP)
struct dtcp_ake_arg {
  http_session_t *session;
  http_sender_t *sender;
  http_receiver_t *receiver;
};
typedef struct dtcp_ake_arg dtcp_ake_arg_t;
#endif /* defined (DLNA_UPLOAD_AKE_AFTER_HTTP_POST) && defined (HAVE_DTCP) */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
http_server_process (http_session_t *session, http_parser_t *parser,
                     http_message_t *http, http_receiver_t *receiver);

void
http_server_process_post (http_session_t *session, http_parser_t *parser,
                          http_message_t *http, http_receiver_t *receiver,
                          http_event_t event);

#ifdef DLNA_SUPPORT_RUISRC
void
http_server_process_ruisrc_post (http_session_t *in_session, 
                                      http_parser_t *in_parser,
                                      http_message_t *in_http_message, 
                                      http_receiver_t *in_receiver,
                                      enum http_event in_event);
#endif /* DLNA_SUPPORT_RUISRC */

slim_int
http_server_reader_header_process (http_session_t *session,
                                   http_receiver_t *receiver,
                                   http_message_t *http,
                                   slim_int has_body);
slim_int
http_server_init (struct upnp_document_type_t *out_media_map);

void
http_server_reply_100_continue(http_session_t *in_session, http_message_t *http_message);

void
http_server_send_error(http_session_t *session, slim_int error);

void
http_server_deinit (void);

#ifdef HAVE_DMS
slim_int
http_stream_session_add (http_master_t *hm, slim_char *mac, slim_char *uri);

void
http_stream_session_delete (http_master_t *hm, slim_char *mac, slim_char *uri);
#endif /* HAVE_DMS */

#ifdef DEVELOPMENT_ENABLE_CONCURRENT_VIEWING
slim_int
http_server_get_current_concurrent_viewing(http_master_t *hm, slim_char *uri);

slim_int
http_server_get_max_concurrent_viewing(slim_char *uri);

#endif /* DEVELOPMENT_ENABLE_CONCURRENT_VIEWING */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HTTP_SERVER_H */
