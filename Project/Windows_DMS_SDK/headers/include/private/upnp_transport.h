/*
 * upnp_transport.h
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

#ifndef NFLC_UPNP_TRANSPORT_H
#define NFLC_UPNP_TRANSPORT_H

#include <upnp_player.h>
#define UPLOADER_TOLERANCE_TIMES_OF_HTTP_SESSION_ERROR (0)

struct uploader_peer_callback_delay {
  slim_int count;
  void *stream;
  dlna_uploader_event event;
  dlna_progress_handle e_uploader_peer_callback_delay;
};

typedef struct uploader_peer_callback_delay uploader_peer_callback_delay_t;


/* UPnP transport.  */
struct upnp_transport
{
  /* UPnP transport manager.  */
  struct upnp_transport_manager *tm;

  /* Flags.  */
  slim_word flags;

  /* Transport index.  */
  slim_int tid;

  /* current action */
  struct upnp_action_request *action;

  /* current operation */
  slim_int operation;

  slim_bool op_cancel;
  
  slim_bool error_handling;

  slim_bool end_of_media_handing;
  
  /* Transport old state.  */
  upnp_transport_state_t old_state;
  
  /* Transport current state.  */
  upnp_transport_state_t state;

  /* Error reason.  */
  slim_int error;

  /* session is done or not */
  slim_bool session_done;

  /* Title.  */
  slim_char *title;

  /* URI.  */
  slim_char *uri;
  
  /* importURI (for Upload) */
  slim_char *import_uri;

#ifdef HAVE_WMDRM
  /* SeekTime.  */
  slim_word seektime;
#endif /* HAVE_WMDRM */

  /* Contents-Type */
  slim_char *contents_type;
  
  /* contentFeature.dlna.org */
  slim_char *contents_feature;

  /* Content protocol information.  */
  slim_char *pinfo;

  /* Mime Type */
  slim_char *mime_type;

  /* Renderer UDN.  */
  slim_char *dmr_udn;

  /* Current path.  */
  slim_char *path;

  /* Current bytes.  */
  dlna_uint64 current_bytes;

  /* Total bytes.  */
  dlna_uint64 total_bytes;

  /* object size */
  dlna_uint64 size;

  /* Percent.  */
  slim_int percent;

  /* The times of http timeout during uploading operation. */
#ifdef DLNA_SUPPORT_UPLOADER
  slim_bool upload_ready;
  
  slim_int continue_wait_cnt;

  slim_int uploader_http_timeout_times;

  slim_int uploader_http_session_error_times;

  dlna_uploader_stream uploader_stream;

  slim_bool is_eos;
#endif
#if defined (DLNA_SUPPORT_DOWNLOADER) && defined (DLNA_SUPPORT_DOWNLOADER_PEER)
	dlna_downloader_stream downloader_stream;
	slim_char* download_path;
#endif /*defined (DLNA_SUPPORT_DOWNLOADER) && defined (DLNA_SUPPORT_DOWNLOADER_PEER)*/
  /* Duration.  */
  slim_word duration;

  /* Jump Target(parameter of dlnaDmpPlayJump).  */
  slim_char *jump_mode;
  slim_char *jump_target;

  /* Play speed */
  slim_char *play_speed;

#ifdef DEVELOPMENT_CLOCK_SYNC
  /* Presentation time */
  slim_char *presentation_time;
#endif /* DEVELOPMENT_CLOCK_SYNC */

  /* Player event and stream.  */
  dlna_player_stream stream;     /* ZZZ: used by new design */

  /* Buffer pointer passed by the player engine.  */
  slim_byte *buffer;

  /* Buffer size passed by the player engine.  */
  dlna_size_t buffer_size;

  /* HTTP client connection.  */
  struct http_client *hc;

  /* Events.  */
  dlna_progress_handle e_event[UPNP_TRANSPORT_EVENT_MAX];
  dlna_progress_handle e_ratelimit;
  dlna_progress_handle e_timer;
  dlna_progress_handle e_close_delay;
  dlna_progress_handle e_cancel_check_timer;
  
  /* used by new design of upnp_transport_xxx.c */
  slim_int stream_state;
  slim_int stream_op;
  dlna_player_callback stream_callback;
  void *stream_arg;

#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
  slim_opaque enc_ctx;
  slim_int drm_cci;
  uri_type to_url;
  slim_bool enc_inited;
  slim_int enc_init_check_cnt;

  slim_word uploaded_size;
#endif /* defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER) */

  /* UPnP Player Stream */
  uplayer_stream_handle uplayer_stream;
  
};

typedef struct upnp_transport upnp_transport_t;

/* UPnP transport manager.  */
struct upnp_transport_manager
{
  /* Event manager.  */
  dlna_progress em;

  /* DLNA Player peer.  */
  dlna_player player;

  /* DLNA Uploader peer.  */
  dlna_uploader uploader;
#if defined (DLNA_SUPPORT_DOWNLOADER) && defined (DLNA_SUPPORT_DOWNLOADER_PEER)
	/*DLNA Downloader peer*/
	dlna_downloader downloader;
#endif /*defined (DLNA_SUPPORT_DOWNLOADER) && defined (DLNA_SUPPORT_DOWNLOADER_PEER)*/
	
  /* UPnP top pointer.  */
  void *top;

  /* HTTP master.  */
  http_master_t *hm;

  /* Transport vector.  */
  struct _vector *v_ut;

  /* UPnP callback.  */
  upnp_callback_t callback;

  /* Device specific information.  */
  void *info;
  
  /* ZZZ:upnp_transport_uploader_peer_callback_delay... */
  uploader_peer_callback_delay_t uploader_peer_callback_delay;

  /* Player Manager */
  upnp_player_manager_t *player_mgr;
};

typedef struct upnp_transport_manager upnp_transport_manager_t;

#define UPNPTRANS_PLAYER_MINFO_MASK_PINFO     UPLAYER_MINFO_MASK_PINFO
#define UPNPTRANS_PLAYER_MINFO_MASK_URI         UPLAYER_MINFO_MASK_URI
#define UPNPTRANS_PLAYER_MINFO_MASK_PLAY_SPEED      UPLAYER_MINFO_MASK_PLAY_SPEED 
#define UPNPTRANS_PLAYER_MINFO_MASK_TRACK_NUM       UPLAYER_MINFO_MASK_TRACK_NUM 
#define UPNPTRANS_PLAYER_MINFO_MASK_CUR_TRACK         UPLAYER_MINFO_MASK_CUR_TRACK 
#define UPNPTRANS_PLAYER_MINFO_MASK_CUR_TRACK_URI   UPLAYER_MINFO_MASK_CUR_TRACK_URI 
#define UPNPTRANS_PLAYER_MINFO_MASK_URI                           UPLAYER_MINFO_MASK_URI                       
#define UPNPTRANS_PLAYER_MINFO_MASK_MEDIA_DURATION    UPLAYER_MINFO_MASK_DURATION  
#define UPNPTRANS_PLAYER_MINFO_MASK_TRACK_DURATION    UPLAYER_MINFO_MASK_TRACK_DURATION 
#define UPNPTRANS_PLAYER_MINFO_MASK_ABS_TIME_POS                 UPLAYER_MINFO_MASK_TIME_POS 
#define UPNPTRANS_PLAYER_MINFO_MASK_ABS_BYTE_POS                 UPLAYER_MINFO_MASK_BYTE_POS
#define UPNPTRANS_PLAYER_MINFO_MASK_REL_TIME_POS     UPLAYER_MINFO_MASK_TRACK_TIME_POS 
#define UPNPTRANS_PLAYER_MINFO_MASK_REL_BYTE_POS     UPLAYER_MINFO_MASK_TRACK_BYTE_POS

struct upnp_transport_player_info {
  slim_char *pinfo;
  slim_char *uri;
  slim_word duration;
  slim_word track_duration;
  slim_word abs_time_pos;
  slim_word abs_byte_pos;
  slim_word rel_time_pos;
  slim_word rel_byte_pos;
  slim_int play_speed;
  slim_int track_num;
  slim_int current_track;
  slim_char *current_track_uri;
  slim_word mask;    /* Indicate which params above are supported */
};
typedef struct upnp_transport_player_info upnp_transport_player_info_t;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_transport_event_add (upnp_transport_t *ut, upnp_transport_event_t event);

slim_int
upnp_transport_alloc (upnp_transport_manager_t *tm, slim_char *pinfo,
                      slim_char *uri, slim_char *title, 
                      slim_char *contents_type, 
                      slim_char *contents_feature,
                      slim_char *dmr_udn,
                      slim_char *res_size, 
                      slim_word flags, slim_int *tid);

slim_int upnp_transport_reopen (upnp_transport_manager_t *tm, slim_int tid, slim_char *pinfo,
                      slim_char *uri, slim_char *title, 
                      slim_char *contents_type, 
                      slim_char *contents_feature,
                      slim_char *dmr_udn,
                      slim_word flags);

slim_int
upnp_transport_set_avtransport_uri(upnp_transport_manager_t *tm,
                                                                      slim_int tid,
                                                                      slim_char *pinfo,
                                                                      slim_char *uri);
                                                                      
slim_int
upnp_transport_action_set (upnp_transport_t *ut, struct upnp_action_request *r);

void
upnp_transport_action_dispose (upnp_transport_t *ut);

slim_int
upnp_transport_free (upnp_transport_manager_t *tm, slim_int tid);

upnp_transport_t *
upnp_transport_lookup (upnp_transport_manager_t *tm, slim_int tid);

upnp_transport_t *
upnp_transport_lookup_by_stream (upnp_transport_manager_t *tm,
                                 dlna_player_stream stream);

#if defined (DLNA_SUPPORT_UPLOADER)
upnp_transport_t *
upnp_transport_lookup_by_uploader_stream (upnp_transport_manager_t *tm,
                                 dlna_uploader_stream stream);
#endif /* defined (DLNA_SUPPORT_UPLOADER) */

#if defined (DLNA_SUPPORT_DOWNLOADER) && defined (DLNA_SUPPORT_DOWNLOADER_PEER)
upnp_transport_t *
upnp_transport_lookup_by_downloader_stream (upnp_transport_manager_t *tm,
																							dlna_downloader_stream stream);
#endif /*DLNA_SUPPORT_DOWNLOADER*/

upnp_transport_t *
upnp_transport_lookup_by_udn (upnp_transport_manager_t *tm,
                              slim_char *udn, slim_word in_flag);

slim_int
upnp_transport_set_flags (upnp_transport_t *ut);


slim_int
upnp_transport_close_http_client_delay (upnp_transport_t *ut);


#ifdef DLNA_SUPPORT_DOWNLOADER
/* Resume UPNP downloading */
slim_int
upnp_transport_download_resume (upnp_transport_manager_t *tm, slim_int tid);

/* Pause UPNP downloading */
slim_int
upnp_transport_download_pause (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_download_cancel (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_download (upnp_transport_manager_t *tm, slim_int tid);
#endif

#if defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER)
slim_int
upnp_transport_cci_set (upnp_transport_manager_t *tm, slim_int in_cci, slim_int in_tid);
#endif /* defined (HAVE_DTCP) && defined (DLNA_SUPPORT_UPLOADER) */

slim_int
upnp_transport_upload (upnp_transport_manager_t *tm, slim_int tid,
		       slim_char *in_to_uri);

slim_int
upnp_transport_play (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_pause (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_jump (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_stop (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_fastfoward(upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_rewind(upnp_transport_manager_t *tm, slim_int tid);

#ifdef HAVE_WMDRM
slim_int
upnp_transport_seektime (upnp_transport_manager_t *tm, slim_int tid);
#endif /* HAVE_WMDRM */

slim_int
upnp_transport_record (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_seek (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_next (upnp_transport_manager_t *tm, slim_int tid);

slim_int
upnp_transport_prev (upnp_transport_manager_t *tm, slim_int tid);

upnp_transport_manager_t *
upnp_transport_manager_alloc (dlna_progress em, http_master_t *hm, void *top,
                              upnp_callback_t callback, void *info,
                              dlna_player_display_param *p);

slim_int
upnp_transport_manager_free (upnp_transport_manager_t *tm);




/**************** ZZZ: re-designed APIs for DMC/DMP **********************/
#define UT_BASE(self) ((upnp_transport_t*)(self))
#define UT_STREAM_OBJ(self) (UT_BASE(self)->stream)

#define UT_SET_STREAM_STATE(stream, state) (UT_BASE(stream)->stream_state = (slim_int)(state))
#define UT_SET_STREAM_OP(stream, op) (UT_BASE(stream)->stream_op = (slim_int)(op))

#define UT_GET_STREAM_STATE(stream) (UT_BASE(stream)->stream_state)
#define UT_GET_STREAM_OP(stream) (UT_BASE(stream)->stream_op)

#define UT_CHECK_STREAM_STATE(stream, state) (!!(UT_BASE(stream)->stream_state == (slim_int)(state)))
#define UT_CHECK_STREAM_OP(stream, op) (!!((UT_BASE(stream)->stream_op == (slim_int)(op))))

#define UT_STREAM_STATE_INVALID (-1)
#define UT_STREAM_OP_NONE (0)

#define UT_SET_STREAM_OP_NONE(stream) UT_SET_STREAM_OP((stream), UT_STREAM_OP_NONE)


#define UPNP_TRANSPORT_EVENT_START (0x1000)

slim_int
upnp_transport_initialize(upnp_transport_manager_t *tm, upnp_transport_t *in_ut, slim_int in_flags,
                                                 dlna_player_callback stream_callback, void *stream_callback_arg);

void
upnp_transport_finalize(upnp_transport_manager_t *tm, upnp_transport_t *in_ut);

slim_int
upnp_transport_set_stream_uri (upnp_transport_t *self, slim_char *in_uri);

slim_int
upnp_transport_player_info_get (upnp_transport_t *ut, upnp_transport_player_info_t *out_info);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_TRANSPORT_H */
