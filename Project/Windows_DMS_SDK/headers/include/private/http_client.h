/*
 * http_client.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_HTTP_CLIENT_H
#define NFLC_HTTP_CLIENT_H

/* HTTP client.  */

#include <http_session.h>

struct http_client;

typedef slim_int (*http_client_make_buffer_t) (struct http_client *hc,
                                               http_sender_t *sender,
                                               slim_char *uri);

#define HTTP_AKE_SESSION_UP_CHECK      (2)
#define HTTP_AKE_MAX_SESSION_UP_CHECK  (22)

struct http_drm_client
{
  slim_int  cnt;
  slim_word ake_ip_addr;
  slim_half ake_port;

  /* AKE session create API */
  slim_bool (*create_ake_session) (slim_char *, slim_int, slim_word *, 
                                   slim_half *);
  slim_bool (*create_ake_session_pinfo) (slim_char *, slim_int, slim_word *,
                                         slim_half *);
};

typedef struct http_drm_client http_drm_client_t;


/* New HTTP client.  */
struct http_client
{
  /* HTTP master.  */
  http_master_t *hm;

  /* Event manager.  */
  dlna_progress em;

  /* HTTP client flags.  */
  slim_word flags;
#define HTTP_CLIENT_FLAG_STREAM       (1 << 0)

  /* HTTP session.  */
  http_session_t *session;

  /* HTTP method.  */
  http_method_t method;

  /* URL.  */
  uri_type url;

  /* HTTP sender parameter.  */
  http_sender_param_t sp;

  /* Callback.  */
  http_callback_t http_callback;
  http_client_make_buffer_t make_buffer;

  /* HTTP transfer mode.  */
  http_transfer_mode_t transfer_mode;
  http_drm_client_t dtcp;
  
  /* HTTP range request */
  http_range_t range;

#ifdef DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED
  /* HTTP Playspeed request */
  http_playspeed_t ps;
#endif /*DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED*/

  /* HTTP buffer size */
  slim_int http_buf_len;

  void *info;
#ifdef DLNA_SUPPORT_RUIPL
	slim_char 	*client_capability ;
#endif /* DLNA_SUPPORT_RUIPL */
};

typedef struct http_client http_client_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
http_client_alloc (http_master_t *hm,  slim_int in_http_buf_len,
                   http_callback_t http_callback,
                   void *info, struct http_client **out_hc);

slim_int
http_client_free (http_client_t *hc);

slim_int
http_client_timeout_set (http_client_t *hc, dlna_time_t timeout);

slim_int
http_client_connect (http_client_t *hc, http_method_t method,
                     slim_char *url_str);

slim_int
http_client_read (http_client_t *hc, slim_byte *out_buf, slim_int in_len);

slim_int
http_client_pause (http_client_t *hc);

slim_int
http_client_resume (http_client_t *hc);

#ifdef DLNA_SUPPORT_DOWNLOADER
slim_int
http_client_pause_download (http_client_t *hc);

slim_int
http_client_resume_download (http_client_t *hc);
#endif

slim_int
http_client_close (http_client_t *hc);

void
http_client_stream_mode_set (http_client_t *hc);

slim_int
http_client_transfer_mode_set (http_client_t *hc, http_transfer_mode_t mode);

slim_int
http_client_range_set (http_client_t *hc, http_range_t *in_range);

#ifdef DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED
slim_int
http_client_playspeed_set (http_client_t *hc, http_playspeed_t *in_playspeed);
#endif /*DEVELOPMENT_ENABLE_HTTP_CLIENT_PLAYSPEED*/

slim_char *
http_client_get_user_agent(http_client_t *hc);

slim_char *
http_client_get_friendly_name(http_client_t *hc);

slim_int
http_client_common_header(struct sbuf *sbuf);

slim_int
http_client_reader_header_process (http_session_t *session,
                                   http_receiver_t *receiver,
                                   http_message_t *http,
                                   slim_int has_body);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HTTP_CLIENT_H */
