/*
 * http_session.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* HTTP session manager.  */

#ifndef NFLC_HTTP_SESSION_H
#define NFLC_HTTP_SESSION_H

#include <dlna_vector.h>
#include <nflc_http.h>
#include <contents_xml.h>

#ifdef HAVE_DTCP
#include <dtcp_base.h>
#endif /* HAVE_DTCP */



#define HTTP_SENDER_SET_CALLBACK(in_sender, in_callback, in_arg) \
            do { \
              (in_sender)->sender_callback = (in_callback); \
              (in_sender)->callback_arg = (in_arg); \
            } while(0);

            
/* HTTP event for callback.  */
enum http_event
{
  HTTP_EVENT_HEAD_CONTINUE,
  HTTP_EVENT_BODY_START,
  HTTP_EVENT_BODY_READ,
  HTTP_EVENT_BODY_WRITE,
  HTTP_EVENT_RECEIVE_DONE,
  HTTP_EVENT_SEND_DONE,
  HTTP_EVENT_TIMEOUT,
  HTTP_EVENT_SESSION_CLOSE,
  HTTP_EVENT_SESSION_ERROR,
  HTTP_EVENT_SESSION_PARTIAL_READ,
  HTTP_EVENT_OUT_OF_MEMORY,
  HTTP_EVENT_METHOD_ERROR,
  HTTP_EVENT_XML_ERROR
};

typedef enum http_event http_event_t;

/* HTTP stream structure.  */
struct upnp_http_stream
{
  /* Pointer to the buffer.  */
  slim_byte *buffer;

  /* Size of the buffer.  */
  slim_size size;

  /* Current pointer offset.  */
  slim_size current_offset;

  /* Current base offset.  */
  slim_size base_offset;
};

typedef struct upnp_http_stream upnp_http_stream_t;

/* stream set.  */
void
upnp_http_stream_set(upnp_http_stream_t *self, slim_byte *in_buffer, slim_int in_base_offset, slim_int in_size);

void
upnp_http_stream_clear(upnp_http_stream_t *self);

/* Forward current point.  */
slim_int
upnp_http_stream_forward(upnp_http_stream_t *self, slim_int in_size);

/* Stream buffer pointer and current point.  */
slim_char *
upnp_http_stream_get_buffer(upnp_http_stream_t *self);

/* Stream buffer pointer and current point.  */
slim_int
upnp_http_stream_buffer_forward(upnp_http_stream_t *self, slim_int in_size);

/* Stream current pointer.  */
slim_char *
upnp_http_stream_current_pointer(upnp_http_stream_t *self);

/* Stream remaing size.  */
slim_size
upnp_http_stream_remain_size(upnp_http_stream_t *self);

/* Terminate stream string.  */
void
upnp_http_stream_put_null(upnp_http_stream_t *self);


void
upnp_http_stream_set_new_buffer(upnp_http_stream_t *self, slim_byte *in_new_ptr, slim_int in_new_size);

#define HTTP_SESSION_UNUSE_MAX  (200)

/*  [30646_DLNA_Guideline_August_2009]
 *   DLNA Requirement [7.4.20.8]: An HTTP Client Endpoint must wait at least 30
 * seconds before closing the TCP connection if it has not received any response
 * from the HTTP Server Endpoint to an HTTP GET request for content.
 *   DLNA Requirement [7.4.81.2]: An HTTP Server Endpoint receiving a POST request must observe
 * at least 30 seconds of data inactivity before closing the TCP connection and assuming
 * that the HTTP Client Endpoint failed to transfer the content.
 *   Data inactivity is defined as the HTTP Server Endpoint not receiving content data
 * from the HTTP Client Endpoint even though there is an established TCP connection.
 *   This guideline works in conjunction with 7.4.80.7 because this guideline assumes Ideal
 * Network Conditions and also assumes that neither user-initiated causes nor out-ofband
 * system events cause the connection to be closed.
 * Comment: These guidelines specify a 5 minute timeout for stalled content transfer.
 */
/* 35 = 30 (at least timer) + 2 (network delay) + 3 (recommend timer) */


#define HTTP_SESSION_TIMEOUT_SECOND         (10*60) /* in seconds. When we support connection stalling timeout for session min 5 minutes set to 10*/
#define HTTP_UPLOAD_SESSION_TIMEOUT_SECOND  (1*60) /* in seconds */

/* A delay time seconds given to session timer to read next TCP-IP data packet. */
#define HTTP_SESSION_TIMEOUT_DELAY_SECOND (5)

#define CONTENT_ACCESS_NOTIFY_UPDATE_SIZE (100)
#define HTTP_SESSION_TIMEOUT_RECEIVER_USEC (100*1000)
#define CONTENT_ACCESS_INVALID_ID SLIM_WORD_MAX 

/*
 * File duplicate open Retry Count and retry usec
 * Total retry time will be 3 sec (6 * 500 msec)
 */
#define HTTP_SESSION_FILE_RETRY_LIMIT    (6)
#define HTTP_SESSION_FILE_RETRY_USEC     (500*1000) /* 500 msec */

#ifdef DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP 
struct dlna_dtcp_snk
{
  TDTCP *p_dtcp;
  TDTCPDevice snk_dev;
};
typedef struct dlna_dtcp_snk  dlna_dtcp_snk_t;
#endif /* DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP */

/* Streaming session */
struct http_stream_session
{
  struct http_stream_session *next;
  struct http_stream_session *prev;
  struct http_master *hm;
  slim_char *mac;
  slim_char *uri;
};

/* HTTP master.  */
struct http_master
{
  /* Event manager.  */
  dlna_progress em;

  /* HTTP session.  */
  struct _vector *sessions;

  /* HTTP unused memory list.  */
  List (struct http_sender *) sender_unuse;
  List (struct http_receiver *) receiver_unuse;
  slim_int sender_unuse_max;
  slim_int receiver_unuse_max;

  /* UPnP argument such as UPnP server and UPnP client.  */
  void *upnp;

  /* User agent */
  slim_char *user_agent;
  slim_char *friendly_name;

#ifdef HAVE_DTCP
  TDTCPDevice dtcp_src_dev;
  TDTCPDevice dtcp_snk_dev;
#endif /* HAVE_DTCP */

  /* session id processing content access */
  /* todo: this variable is used to restrict one http_session which can notify content access. And SLIM_WORD_MAX is used for invalid. */
  slim_word content_access_callback_session_id;

#ifdef HAVE_DMS
  /* Maintains a list of open streaming sessions */
  List( struct http_stream_session *)http_stream_sessions;
#endif

  slim_word content_access_time;

#ifdef DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP
  dlna_dtcp_snk_t  dtcp_snk;
#endif /* DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP */
};

typedef struct http_master http_master_t;

/* HTTP file manager.  */
struct http_file
{
  /* File descriptor.  */
  dlna_file_t desc;

  /* File size.  */
  dlna_uint64 size;

  /* id of contents */
  slim_char *uri;

  /* file path of content */
  slim_char *path;

  /* file path of content */
  slim_char *storage_id;
};

#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING
/* HTTP sending stream manager.  */
struct http_stream
{
  /* stream_par is dlna_stream from dlnaOpenStreamPeer */
  /* stream_par == slim_nil is invalid state. */
  dlna_stream stream_par;

  /* live_content_par is dlna_live_content from dlnaLiveContentOpenPeer. */
  /* live_content_par == slim_nil is invalid state. */
  dlna_live_content live_content_par;

  dlna_uint64 size;

  /* getting stream state.  */
  slim_bool is_stream_end;

};
#endif /*DEVELOPMENT_ENABLE_HTTP_STREAMING*/

/* HTTP sender parameter.  */
struct http_sender_param
{
  /* Flags for header presence.  */
  slim_word flags;
#define HTTP_PARAM_FLAG_CHUNKED              (1 << 0)
#define HTTP_PARAM_FLAG_TRAILERS             (1 << 1)
#define HTTP_PARAM_FLAG_RANGE                (1 << 2)
#define HTTP_PARAM_FLAG_TIME_SEEK            (1 << 3)
#define HTTP_PARAM_FLAG_PLAYSPEED            (1 << 4)
#define HTTP_PARAM_FLAG_REALTIME_INFO        (1 << 5)
#define HTTP_PARAM_FLAG_CONTENT_FEATURES     (1 << 6)
#define HTTP_PARAM_FLAG_TRANSFER_MODE        (1 << 7)
#define HTTP_PARAM_FLAG_DTCP_REQ             (1 << 8)
#define HTTP_PARAM_FLAG_DEVICE_FILE          (1 << 9)
#define HTTP_PARAM_FLAG_SCPD_FILE            (1 << 10)
#define HTTP_PARAM_FLAG_MEM_FILE             (1 << 11)
#define HTTP_PARAM_FLAG_PARTIAL_CONTENT      (1 << 12)
#define HTTP_PARAM_FLAG_ACCEPT_LANGUAGE      (1 << 13)
#define HTTP_PARAM_FLAG_DTCP_RANGE           (1 << 14)

#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
#define HTTP_PARAM_FLAG_CAPTION_INFO         (1 << 15)
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */

#define HTTP_PARAM_FLAG_AVAILABLE_SEEK_RANGE (1 << 16)
  /* HTTP Persistent connection.  */
  slim_int persistent;

  /* Range header.  */
  slim_char range_header[200];
  dlna_uint64 seek;
  dlna_uint64 file_size;
#ifdef HAVE_DTCP
  dlna_uint64 pcp_encrypted_size;
#endif /* HAVE_DTCP */
  struct sbuf file_name;

  /* Content length.  */
  dlna_uint64 content_length;
  
  /* file contents are built in memory */
  struct sbuf mem_file;
  
  /* Time seek range header exist.  */
  slim_char *time_range;
  dlna_timeval start_time;
  dlna_timeval end_time;
  slim_word duration;

#ifdef DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED
  /* PlaySpeed.dlna.org header exist.  */
  slim_char *play_speed;
  slim_bool show_rate; //flag to check if FrameRateInTrickMode.dlna.org header should be added to content
  slim_int  frame_rate;
#endif /* DEVELOPMENT_ENABLE_CVP_SERVER_PLAYSPEED */

  /* transferMode.dlna.org.  */
  http_transfer_mode_t transfer_mode;

  /* Contents pointer.  */
  contents_t *c;

};

typedef struct http_sender_param http_sender_param_t;

enum http_sender_event {
  HTTP_SENDER_EVENT_SEND_DONE = 0,
  HTTP_SENDER_EVENT_enum_end
};

/* HTTP sender callback.  */
typedef slim_int (*http_sender_callback_t) (struct http_sender* sender, void *arg, slim_int evt);

/* HTTP sender.  */
struct http_sender
{
  /* Linked list.  */
  struct http_sender *next;
  struct http_sender *prev;

  /* HTTP header.  */
  struct sbuf header;

  /* HTTP sender flags.  */
  enum http_sender_flag {
    HTTP_SENDER_FLAG_BODY_STR           = (1 << 0),
    HTTP_SENDER_FLAG_BODY_FILE          = (1 << 1),
    HTTP_SENDER_FLAG_BODY_CALLBACK      = (1 << 2),
    HTTP_SENDER_FLAG_CHUNKED            = (1 << 3),
    HTTP_SENDER_FLAG_CLOSE              = (1 << 4),
    HTTP_SENDER_FLAG_BODY_DTCP          = (1 << 5),
    HTTP_SENDER_FLAG_BODY_STREAM        = (1 << 6),
    HTTP_SENDER_FLAG_BODY_LIVE_CONTENT  = (1 << 7)
  } flags;

  /* State of HTTP sender.  */
  enum http_sender_state {
    HTTP_SENDER_STATE_INIT,
    HTTP_SENDER_STATE_HEADER,
    HTTP_SENDER_STATE_BODY,
    HTTP_SENDER_STATE_DONE
  } state;

  /* Union of body.  */
  union {
    /* String body.  */
    struct sbuf str;
    
    /* FILE or stream body.  */
    struct http_file file;
#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING
    struct http_stream stream;
#endif /*DEVELOPMENT_ENABLE_HTTP_STREAMING*/
  } body;

#ifdef HAVE_DTCP
  /* context of encryption */
  slim_opaque enc_ctx;
#endif /* HAVE_DTCP */
  slim_bool wav_change_endianess;
  /* Callback.  */
  http_sender_callback_t sender_callback;
  void *callback_arg;
};
typedef struct http_sender http_sender_t;

/* HTTP receiver. */
struct http_receiver
{
  /* Linked list.  */
  struct http_receiver *next;
  struct http_receiver *prev;

  /* Session.  */
  struct http_session *session;

  /* HTTP receiver flags.  */
  enum http_receiver_flag {
    HTTP_RECEIVER_FLAG_BODY_XML      = (1 << 0),
    HTTP_RECEIVER_FLAG_BODY_FILE     = (1 << 1),
    HTTP_RECEIVER_FLAG_BODY_CALLBACK = (1 << 2),
    HTTP_RECEIVER_FLAG_BODY_DONE     = (1 << 3),
    HTTP_RECEIVER_FLAG_CHUNKED       = (1 << 4),
    HTTP_RECEIVER_FLAG_CLOSE         = (1 << 5),
    HTTP_RECEIVER_FLAG_DELAYED_CLOSE = (1 << 6),
    HTTP_RECEIVER_FLAG_NO_CL         = (1 << 7)
  } flags;

  /* HTTP receiver state.  */
  enum http_receiver_state {
    HTTP_RECEIVER_STATE_HEADER,
    HTTP_RECEIVER_STATE_BODY,
    HTTP_RECEIVER_STATE_DONE
  } state;

  /* HTTP chunked state.  */
  enum http_receiver_chunked_state {
    HTTP_RECEIVER_CHUNK_SIZE,
    HTTP_RECEIVER_CHUNK_BODY,
    HTTP_RECEIVER_CHUNK_BODY_CR,
    HTTP_RECEIVER_CHUNK_BODY_LF,
    HTTP_RECEIVER_CHUNK_END
  } chunk_state;

  /* Content length in the HTTP header.  Even if this value is
     zero, when HTTP_RECEIVER_FLAG_CHUNKED is set, it has body.  */
  dlna_uint64 content_length;

  /* Total read length.  */
  dlna_uint64 total_length;

  /* Current chunk length.  */
  dlna_uint64 chunk_size;

  /* Current chunk read size.  */
  dlna_uint64 chunk_read_size;

  /* Current read size for callback.  */
  slim_word nbytes;

  /* Union of body.  */
  union {
    /* XML */
    sXML_UserData xml;

    /* FILE or stream body.  */
    struct http_file file;
  } body;

  /* HTTP method.  */
  enum http_method method;
};
typedef struct http_receiver http_receiver_t;


/* HTTP chunked encoding end marker.  */
#define HTTP_CHUNK_END                 "0\r\n\r\n"
#define HTTP_CHUNK_END_SIZE            (5)

/* HTTP read/write buffer size.  */
#define HTTP_CHUNK_BUFFER_SIZE        (20)

/* HTTP reader. */
struct http_reader
{
  /* Stream information. */
  upnp_http_stream_t http_stream;

  /* HTTP parser. */
  http_parser_t parser;

  /* Read event. */
  dlna_progress_handle e_http_reader_read;

  /* Read buffer. */
  slim_byte *buf;

  /* Read buffer. */
  slim_int buf_size;
};

/* HTTP writer. */
struct http_writer
{
  /* Stream information. */
  upnp_http_stream_t http_stream;

  /* Write event. */
  dlna_progress_handle e_http_writer_write;

  slim_byte *buf;

  /* Write buffer. */
  slim_byte *real_buf;

  slim_int buf_size;

#ifdef DEVELOPMENT_ENABLE_PREPARE_READ_BUFFER
  slim_byte *pre_real_buf; 
  slim_byte *pre_buf;
  slim_int pre_read_nbytes;
  dlna_thread pre_read_thread;
#endif
};

struct http_session_info_ptr 
{
  struct http_session_info_ptr *next;
  struct http_session_info_ptr *prev;
  slim_char *ptr;
  slim_word len;
  slim_char eemi;
};

/* Session information structure */
struct http_session_info
{
  List (struct http_session_info_ptr *) info;
};

/*
 * HTTP receiver callback function.  This is different between, server
 * and client.
 */
typedef slim_int (*http_callback_t) (struct http_session *in_session,
                                     struct http_receiver *in_receiver,
                                     http_event_t in_event);

typedef slim_int
(*http_reader_header_process_t) (struct http_session *in_session,
                                 struct http_receiver *in_receiver,
                                 http_message_t *in_http_message,
                                 slim_int in_has_body);

struct http_content_access
{
#define MAC_ADDRESS_STR_LEN     (24)

  /* client mac address */
  slim_char mac_address[MAC_ADDRESS_STR_LEN+1];

  /* method */
  enum content_access_method {
    CONTENT_ACCESS_METHOD_NONE = 0,
    CONTENT_ACCESS_METHOD_PLAY,
    CONTENT_ACCESS_METHOD_DOWNLOAD,
    CONTENT_ACCESS_METHOD_UPLOAD,
  } method;

  /* state */
  enum content_access_state {
//    CONTENT_ACCESS_STATE_NONE = -1,
    CONTENT_ACCESS_STATE_INIT       = 0,
    CONTENT_ACCESS_STATE_ACCEPT,
    CONTENT_ACCESS_STATE_BLOCK,
    CONTENT_ACCESS_STATE_DENY,
    CONTENT_ACCESS_STATE_CANCEL,
    CONTENT_ACCESS_STATE_TIMEOUT,
    CONTENT_ACCESS_STATE_SENDING_FORBIDDEN,
    CONTENT_ACCESS_STATE_CLOSE
    
  } state;

  /* content id */
  slim_int content_id;

  /* total bytes */
  dlna_uint64 total_bytes;

  /* current bytes */
  dlna_uint64 current_bytes;

  /* bytes previous notification */
  dlna_uint64 previous_bytes;

  slim_int chunked;
};
typedef struct http_content_access http_content_access_t;

struct http_file_retry_info_
{
  struct http_session *session;
  
  struct http_receiver *receiver;

  http_parser_t *parser;

  http_message_t *http;

  slim_int retry_cnt;

  dlna_progress_handle retry_timer;

};
typedef struct http_file_retry_info_ http_file_retry_info_t;

/* HTTP session.  */
struct http_session
{
  /* ID of the session.  */
  slim_word session_id;

  /* We need to have up layer pointer.  */
  struct http_master *hm;

  /* Event manager.  */
  dlna_progress em;

  /* Socket.  */
  slim_int sock;

#ifdef ENABLE_PARENTAL_GUIDANCE
  slim_int parental_guidance_level;
#endif /* ENABLE_PARENTAL_GUIDANCE */

  /* Interface index of the session.  */
  slim_int ifindex;

  /* HTTP session flags.  */
  enum http_session_flag {
    HTTP_SESSION_FLAG_STREAM        = (1 << 0),
    HTTP_SESSION_FLAG_PAUSE         = (1 << 1),
    HTTP_SESSION_FLAG_CLIENT        = (1 << 2),
    HTTP_SESSION_FLAG_LAST_PLUS_ONE
  } flags;

  /* HTTP reader.  */
  struct http_reader reader;

  /* HTTP writer.  */
  struct http_writer writer;

  /* HTTP buffer length.  */
  slim_int http_buf_len;

  /* List of HTTP sender.  */
  List (struct http_sender *) sender_list;

  /* List of HTTP receiver.  */
  List (struct http_receiver *) receiver_list;

  /* HTTP ring buffer.  */
  struct http_ring_buffer_master *ring;

  /* HTTP receiver callback.  */
  http_callback_t http_callback;

  /* HTTP header process callback */
  http_reader_header_process_t http_header_process_callback;
  
  /* Callback argument.  */
  void *info;

  /* Session time out value.  */
  dlna_time_t timeout;

  /* Delayed close event.  */
  dlna_progress_handle e_http_session_delay;

  /* Time out handler.  */
  dlna_progress_handle e_http_session_timeout;
  dlna_progress_handle receiver_timer;

  dlna_progress_handle receiver_event;

  slim_int receiver_sock;

  http_content_access_t content_access;

  http_file_retry_info_t file_retry_info;


#if defined (DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION)\
  || defined (DLNA_SUPPORT_XMMRR)

  const slim_char * user_agent;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION DLNA_SUPPORT_XMMRR */


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION

  const slim_char * x_av_client_info;

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */

#ifdef DEVELOPMENT_ENABLE_CONCURRENT_VIEWING
  slim_bool http_is_streaming_now;
#endif /* DEVELOPMENT_ENABLE_CONCURRENT_VIEWING */

#if defined (RA_USE_RID_HEADER)
  slim_char *x_rid ;
  slim_word x_rid_permission ;
#endif //#if defined (RA_USE_RID_HEADER)

};

typedef struct http_session http_session_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct http_sender *
http_sender_get (http_session_t *session);

slim_int
http_sender_add (http_session_t *session, http_sender_t *sender);

void
http_sender_cancel (http_session_t *session, http_sender_t *sender);
            
slim_int
http_sender_file_open (http_session_t *session, http_message_t *http,
                       http_sender_t *sender, http_sender_param_t *param);
#if 0
slim_int
http_sender_album_playlist_open (http_session_t *session, http_message_t *http, struct sbuf *sbuf, contents_t *c);
#endif
slim_int
http_sender_xml_open (http_session_t *session, http_message_t *http,
                      http_sender_t *sender, sXML *doc);

slim_int
http_sender_start (http_session_t *session);

struct http_receiver *
http_receiver_get (http_session_t *session);

void
http_receiver_add (http_session_t *session, http_receiver_t *receiver);

slim_int
http_receiver_start (http_session_t *session);

slim_int
http_receiver_xml_prepare (http_receiver_t *receiver);

slim_int
http_receiver_file_prepare (struct http_receiver *receiver, http_sender_param_t *p);

void
http_receiver_callback_prepare (struct http_receiver *receiver);

slim_bool
http_receiver_is_chunked (struct http_receiver *receiver);

slim_byte *
http_receiver_ptr (struct http_receiver *receiver);

slim_int
http_receiver_length (struct http_receiver *receiver);

slim_bool
http_session_stream_mode_set (http_session_t *session);

void
http_session_stream_mode_unset (http_session_t *session);

slim_int
http_session_timeout_set (http_session_t *session, dlna_time_t timeout);

void *
http_session_arg (http_session_t *session);

slim_char *
http_session_get_user_agent(http_session_t *session);

http_session_t *
http_session_alloc(http_master_t *hm, slim_int sock, slim_int in_http_buf_len,
                   http_callback_t receiver_callback, void *info,
                   http_reader_header_process_t in_header_process_cb);

void
http_session_cancel (http_session_t *session);

void
http_session_close (http_session_t *session);

void
http_session_pause (http_session_t *session);

slim_int
http_session_resume (http_session_t *session);

void
http_session_error (http_session_t *session);

slim_int
http_session_async_connect (http_session_t *session);

slim_int
http_session_delayed_close_register (http_session_t *session);

void
http_session_receiver_delayed_close (struct http_session *session);

slim_int
http_session_ring_buffer_read (struct http_session *session,
                               slim_byte *out_buf, slim_int in_len);

slim_int
http_session_ring_buffer_write (struct http_session *session, slim_byte *in_buf,
                        slim_int in_len);

void
http_session_extend_buffer(http_session_t *in_session, slim_int in_http_buf_len);

void
http_writer_extend_buffer(struct http_writer *in_writer, slim_int in_http_buf_len);

void
http_reader_extend_buffer(struct http_reader *in_reader, slim_int in_http_buf_len);

http_master_t *
http_master_alloc (dlna_progress em, void *upnp);

void
http_master_free (http_master_t *hm);

#ifdef DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP 
slim_bool
http_master_dtcp_snk_alloc (http_master_t *hm);

slim_bool
http_master_dtcp_snk_free (dlna_dtcp_snk_t *p_snk);
#endif /* DEVELOPMENT_DMP_DMR_DTCP_IP_FOR_CVP */

void
http_session_set_client_auth (http_session_t *session, dlna_ip_addr *in_addr);

slim_bool
http_session_init_notify (http_session_t *session, http_message_t *in_http, http_sender_param_t *in_p);

void
http_session_tidy_notify (http_session_t *in_session);

slim_int
http_session_content_access_state (http_session_t *in_session);

slim_int 
http_session_fire_open_event (http_session_t *in_session, dlna_uint64 *in_content_length);

void
http_session_fire_update_event (http_session_t *in_session);

void
http_session_fire_cancel_event (http_session_t *in_session);

void
http_session_fire_timeout_event (http_session_t *in_session);

void
http_session_fire_error_event (http_session_t *in_session, slim_int in_event);

void
http_session_fire_close_event (http_session_t *session);


void 
http_session_set_content_access_state (http_session_t *session, slim_int in_state);

void
http_session_set_content_access_total_bytes (http_session_t *session, http_sender_t *in_sender);

void
http_session_set_master_content_id (http_session_t *session, slim_int in_content_id);

slim_bool
http_session_isexpired_content_access_time (http_session_t *session);

void
http_session_update_content_access_time (http_session_t *session);


#if defined (DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION) \
  || defined(DLNA_SUPPORT_XMMRR)

void
http_session_user_agent_set(http_message_t *in_http, http_session_t *in_session);

void
http_session_x_av_clinet_info_set(http_message_t *in_http, http_session_t *in_session);

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION DLNA_SUPPORT_XMMRR*/


#if defined (RA_USE_RID_HEADER)
void
http_session_x_rid_info_set(http_message_t *in_http, http_session_t *in_session) ;
#endif //#if defined (RA_USE_RID_HEADER)


slim_int
http_write(slim_int in_desc, void *in_arg);

#ifdef DEVELOPMENT_ENABLE_HTTP_STREAMING
slim_int
http_sender_stream_open (http_session_t *session, http_message_t *http, http_sender_t *sender, http_sender_param_t *p);

void
http_stream_cancel(struct http_stream *stream);

slim_int
http_sender_stream_read(http_session_t *session, http_sender_t *sender, struct http_writer *writer);

void
http_sender_retry_stream_read(http_session_t *session);

#ifdef HAVE_DTCP
slim_int
http_sender_dtcp_stream_read(http_session_t *session, http_sender_t *sender, struct http_writer *writer);
#endif /*HAVE_DTCP*/

slim_int
http_sender_live_content_open (http_session_t *session, http_message_t *http, http_sender_t *sender, http_sender_param_t *p);

void
http_live_content_cancel(struct http_stream *stream);

#endif /*DEVELOPMENT_ENABLE_HTTP_STREAMING*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HTTP_SESSION_H */
