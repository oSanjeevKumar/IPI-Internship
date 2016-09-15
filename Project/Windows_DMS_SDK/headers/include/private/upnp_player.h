/*
 * upnp_player.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef _UPNP_PLAYER_H
#define _UPNP_PLAYER_H

#include <http_session.h>
#ifdef ENABLE_AHL
#include <dlna_peer.h>
#endif

/* object handles face to upper layer */
typedef void *uplayer_stream_handle;

typedef struct upnp_player_manager upnp_player_manager_t;
typedef struct upnp_player_class upnp_player_class_t;
typedef struct upnp_player upnp_player_t;
typedef void *upnp_player_stream_t;

#define UPLAYER_ACTION_FLAG_PLAY       (1 << 0)
#define UPLAYER_ACTION_FLAG_PAUSE      (1 << 1)
#define UPLAYER_ACTION_FLAG_STOP       (1 << 2)
#define UPLAYER_ACTION_FLAG_NEXT       (1 << 3)
#define UPLAYER_ACTION_FLAG_PREVIOUS   (1 << 4)
#define UPLAYER_ACTION_FLAG_SEEK_TRACK (1 << 5)
#define UPLAYER_ACTION_FLAG_SEEKTIME   (1 << 6)  /* Defined by DLNA Guideline */
#define UPLAYER_ACTION_FLAG_SEEKBYTE   (1 << 7)  /* Defined by DLNA Guideline */

enum upnp_player_seek_mode {
  UPLAYER_SEEK_MODE_ABS_TIME,
  UPLAYER_SEEK_MODE_REL_TIME,
  UPLAYER_SEEK_MODE_ABS_COUNT,
  UPLAYER_SEEK_MODE_REL_COUNT,
  UPLAYER_SEEK_MODE_X_DLNA_REL_BYTE,
  UPLAYER_SEEK_MODE_TRACK_NR,
  UPLAYER_SEEK_MODE_enum_end,
};
typedef enum upnp_player_seek_mode upnp_player_seek_mode_t;

enum upnp_player_event {
  UPNP_PLAYER_EVENT_NONE = 0,

  /* callback event */
  UPNP_PLAYER_EVENT_OPEN,
  UPNP_PLAYER_EVENT_PLAY,
  UPNP_PLAYER_EVENT_PAUSE,
  UPNP_PLAYER_EVENT_SEEKTIME,
  UPNP_PLAYER_EVENT_SEEKBYTES, /* 5 */
  UPNP_PLAYER_EVENT_SEEKTRACK,
  UPNP_PLAYER_EVENT_STOP,
  UPNP_PLAYER_EVENT_PREPARE_NEXT,
  UPNP_PLAYER_EVENT_PLAY_NEXT,

  /* notify event */
  UPNP_PLAYER_EVENT_UPDATE, /* 10 */ /* Playback position update, including current track */
  UPNP_PLAYER_EVENT_EOS,
  UPNP_PLAYER_EVENT_ERROR,/* Internal Error of playback */
  UPNP_PLAYER_EVENT_TRANSITIONING,
  UPNP_PLAYER_EVENT_TRANSITIONING_NEXT,
  UPNP_PLAYER_EVENT_CLOSED, /* 15 */
  UPNP_PLAYER_EVENT_enum_end,
};
typedef enum upnp_player_event upnp_player_event_t;

enum upnp_player_stream_state {
  UPLAYER_STREAM_STATE_PLAYING,
  UPLAYER_STREAM_STATE_PAUSED,
  UPLAYER_STREAM_STATE_STOPPED,
};
typedef enum upnp_player_stream_state upnp_player_stream_state_t;





/* Used between UPlayer Manager and UPlayer */                                                                        
typedef slim_int (*upnp_player_callback) (upnp_player_stream_t in_stream, upnp_player_event_t in_event, 
                                                                        slim_int in_result, slim_opaque in_arg);

typedef slim_int (*dmr_peer_player_callback) (dlna_player_event in_event, void *in_arg, dlna_player_param *in_param);

struct upnp_player_play_speed {
  slim_int speed;
  slim_int speed_den;
#ifdef DEVELOPMENT_ENABLE_SERVER_AND_RENDERER_PLAYSPEED
  slim_bool play_speed_request;
#endif
};
typedef struct upnp_player_play_speed upnp_player_play_speed_t;


struct upnp_player_class {
  /* Name of class to be registered */
  slim_char *name;

  /* Stream interfaces */
#ifdef ENABLE_AHL
slim_int (*stream_open)(upnp_player_t *self, slim_char *in_uri, slim_char *in_pinfo, slim_char* in_title,
                            upnp_player_callback in_callback, slim_opaque in_arg, upnp_player_stream_t *out_stream, dmr_ahl_callback in_cb, slim_opaque in_ahl_callback_arg);
#else
  slim_int (*stream_open)(upnp_player_t *self, slim_char *in_uri, slim_char *in_pinfo, slim_char* in_title,
                            upnp_player_callback in_callback, slim_opaque in_arg, upnp_player_stream_t *out_stream);
#endif /*ENABLE_AHL*/
  slim_int (*stream_open_next)(upnp_player_stream_t in_stream, slim_char *in_uri, slim_char *in_pinfo, slim_char *in_title);
  slim_int (*stream_play)(upnp_player_stream_t in_stream, upnp_player_play_speed_t in_speed, dlna_player_trickmode in_mode);
  slim_int (*stream_play_next)(upnp_player_stream_t in_stream);
  slim_int (*stream_pause)(upnp_player_stream_t in_stream);
  slim_int (*stream_pause_by)(upnp_player_stream_t in_stream, dlna_player_trickmode mode);
  slim_int (*stream_seektrack)(upnp_player_stream_t in_stream, slim_word in_target_track);
  slim_int (*stream_seektime)(upnp_player_stream_t in_stream, slim_int in_target_time, slim_bool b_relative);
  slim_int (*stream_seekbytes)(upnp_player_stream_t in_stream, dlna_uint64 in_target_bytes, slim_bool b_relative);
  slim_int (*stream_stop)(upnp_player_stream_t in_stream);
  void (*stream_close)(upnp_player_stream_t in_stream);
#ifdef DEVELOPMENT_CLOCK_SYNC  
  slim_int (*stream_syncstop)(upnp_player_stream_t in_stream, slim_word in_presentation_time);
  slim_int (*stream_syncplay)(upnp_player_stream_t in_stream, upnp_player_play_speed_t in_speed, slim_word in_presentation_time);
  slim_int (*stream_syncpause)(upnp_player_stream_t in_stream, slim_word in_presentation_time);
#endif /* DEVELOPMENT_CLOCK_SYNC */  

  slim_int (*stream_get_uri)(uplayer_stream_handle in_stream, slim_char **out_uri);
  slim_int (*stream_get_duration)(uplayer_stream_handle in_stream, slim_word *out_duration);
  slim_int (*stream_get_state)(uplayer_stream_handle in_stream, slim_int *out_state);
  slim_int (*stream_get_speed)(uplayer_stream_handle in_stream, upnp_player_play_speed_t *out_speed);
  slim_int (*stream_get_track_num)(uplayer_stream_handle in_stream, slim_word *out_track_num);
  slim_int (*stream_get_track_duration)(uplayer_stream_handle in_stream, slim_word *out_track_duration);
  slim_int (*stream_get_track_uri)(uplayer_stream_handle in_stream, slim_char **out_track_uri);
  slim_int (*stream_get_track_size)(uplayer_stream_handle in_stream, dlna_uint64 *out_track_size);
  slim_int (*stream_get_track_no)(uplayer_stream_handle in_stream, slim_word *out_track_no);
  slim_int (*stream_get_timepos)(uplayer_stream_handle in_stream, slim_bool in_abs, slim_word *out_timepos);
  slim_int (*stream_get_bytepos)(uplayer_stream_handle in_stream, slim_bool in_abs, dlna_uint64 *out_bytepos);
  slim_int(*stream_get_actions_list)(uplayer_stream_handle in_stream, slim_word *out_actions);
  slim_int(*stream_get_playspeed_list)(uplayer_stream_handle in_stream, upnp_player_play_speed_t *in_ps_buf, slim_int in_buf_len);

  /* Alloc player instance */
  slim_int (*player_alloc)(upnp_player_class_t *in_class, upnp_player_manager_t *in_upm, upnp_player_t **out_player);
  /* Free player instance */
  void (*player_free)(upnp_player_t *self);
  /* Class Interfaces */
  slim_bool (*is_pinfo_supported)(upnp_player_class_t *in_class, slim_char *in_pinfo);
};

struct upnp_player {
  upnp_player_class_t *player_class;
  upnp_player_manager_t *uplayer_mgr;
};

struct upnp_player_entry {
  struct upnp_player_entry *prev;
  struct upnp_player_entry *next;

  upnp_player_manager_t *upm;
  upnp_player_class_t *fclass;
  upnp_player_stream_t stream;
  upnp_player_t *player;
  upnp_player_callback cb;
  slim_opaque cb_arg;
};
typedef struct upnp_player_entry upnp_player_entry_t;

struct upnp_player_class_entry {
  struct upnp_player_class_entry *prev;
  struct upnp_player_class_entry *next;

  upnp_player_class_t *player_class;
};
typedef struct upnp_player_class_entry upnp_player_class_entry_t;

struct upnp_player_manager{
  dlna_progress em;
  http_master_t *hm;
  dmr_peer_player_callback cb;
  slim_opaque cb_arg;
#ifdef ENABLE_AHL
  dmr_ahl_callback ahl_cb;
  slim_opaque ahl_cb_arg;
  slim_char *playerInfo;
  slim_char *contentInfo;
  slim_int playTimePosition;
  slim_int playBytePosition;
  slim_int errorCode;
#endif /*ENABLE_AHL*/  
  List(upnp_player_entry_t*) player_list;
  List(upnp_player_class_entry_t*) player_class_list;
};


/* UPnP Player Manager APIs */
upnp_player_manager_t*
upnp_player_manager_alloc (dlna_progress in_em, http_master_t *in_hm);

void
upnp_player_manager_free (upnp_player_manager_t *in_upm);


/* UPnP Player APIs */

slim_int
upnp_player_stream_open (upnp_player_manager_t *in_upm, slim_char *in_uri, slim_char *in_pinfo, slim_char* title, upnp_player_callback in_callback, slim_opaque in_arg, uplayer_stream_handle *out_stream);

slim_int
upnp_player_stream_open_next (uplayer_stream_handle in_stream, slim_char *in_uri, slim_char *in_pinfo, slim_char *in_title);

slim_int
upnp_player_stream_play (uplayer_stream_handle in_stream, upnp_player_play_speed_t in_speed, dlna_player_trickmode in_mode);

slim_int
upnp_player_stream_play_next (uplayer_stream_handle in_stream);

slim_int
upnp_player_stream_pause (uplayer_stream_handle in_stream);

slim_int
upnp_player_stream_pause_by (uplayer_stream_handle in_stream, dlna_player_trickmode mode);

slim_int
upnp_player_stream_seektime (uplayer_stream_handle in_stream, slim_int in_target_time, slim_bool b_relative);

slim_int
upnp_player_stream_seekbytes (uplayer_stream_handle in_stream, dlna_uint64 in_target_bytes, slim_bool b_relative);

slim_int
upnp_player_stream_seektrack (uplayer_stream_handle in_stream, slim_word in_target_track/* 1 - N */);

slim_int
upnp_player_stream_stop (uplayer_stream_handle in_stream);

void
upnp_player_stream_close (uplayer_stream_handle in_stream);





slim_int
upnp_player_stream_get_uri (uplayer_stream_handle in_stream, slim_char **out_uri);

slim_int
upnp_player_stream_get_duration (uplayer_stream_handle in_stream, slim_word *out_duration);

slim_int 
upnp_player_stream_get_state (uplayer_stream_handle in_stream, slim_int *out_state);

slim_int
upnp_player_stream_get_speed (uplayer_stream_handle in_stream, upnp_player_play_speed_t *out_speed);

slim_int
upnp_player_stream_get_track_num (uplayer_stream_handle in_stream, slim_word *out_track_num);

slim_int
upnp_player_stream_get_track_duration (uplayer_stream_handle in_stream, slim_word *out_track_duration);

slim_int
upnp_player_stream_get_track_size (uplayer_stream_handle in_stream, dlna_uint64 *out_track_size);

slim_int
upnp_player_stream_get_track_uri (uplayer_stream_handle in_stream, slim_char **out_track_uri);

slim_int
upnp_player_stream_get_track_no (uplayer_stream_handle in_stream, slim_word *out_track_no /* 1 - N */);

slim_int
upnp_player_stream_get_timepos (uplayer_stream_handle in_stream, slim_bool in_abs, slim_word *out_timepos);

slim_int
upnp_player_stream_get_bytepos (uplayer_stream_handle in_stream, slim_bool in_abs, dlna_uint64 *out_bytepos);

slim_int
upnp_player_stream_get_actions_list (uplayer_stream_handle in_stream, slim_word *out_actions);

/*
  *  Return copied number (>=0) if successful,
  *  Return -1 indicates error occurs
  */
slim_int
upnp_player_stream_get_playspeed_list (uplayer_stream_handle in_stream, upnp_player_play_speed_t *in_ps_buf, slim_int in_buf_len);

/* Implemented UPnP Players */
upnp_player_class_t*
upnp_player_default_register (upnp_player_manager_t *in_upm);

upnp_player_class_t*
upnp_player_playlist_register (upnp_player_manager_t *in_upm);

#endif /* _UPNP_PLAYER_H */
