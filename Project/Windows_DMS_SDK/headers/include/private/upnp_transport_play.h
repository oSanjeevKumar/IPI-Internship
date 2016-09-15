/*
 * upnp_transport_play.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_UPNP_TRANSPORT_PLAY_H
#define NFLC_UPNP_TRANSPORT_PLAY_H

#include <upnp_transport.h>

#ifdef DEVELOPMENT_ENABLE_UPNPTRANSPORT_SEEK
enum upnp_transport_seek_type {
  UT_SEEK_TIME = 1,
  UT_SEEK_BYTE
};

typedef enum upnp_transport_seek_type upnp_transport_seek_type_t;
#endif

enum upnp_transport_play_state {
  UT_PLAY_STATE_START = 0,
  UT_PLAY_STATE_IDLE = UT_PLAY_STATE_START,
  UT_PLAY_STATE_READY,
  UT_PLAY_STATE_PLAY,
  UT_PLAY_STATE_PAUSE,
  UT_PLAY_STATE_MAX,
};

typedef enum upnp_transport_play_state upnp_transport_play_state_t;


enum upnp_transport_play_op {
  UT_PLAY_OP_NONE = UT_STREAM_OP_NONE,
  UT_PLAY_OP_OPEN,
  UT_PLAY_OP_PLAY,
  UT_PLAY_OP_PAUSE,
  UT_PLAY_OP_SEEK,
  UT_PLAY_OP_STOP,
  UT_PLAY_OP_CLOSE,
  UT_PLAY_OP_MAX
};

typedef enum upnp_transport_play_op upnp_transport_play_op_t;


enum upnp_transport_play_event {
  UT_PLAYER_EVT_START = UPNP_TRANSPORT_EVENT_START + 0x100,
  UT_PLAYER_EVT_OP_RESULT,
  UT_PLAYER_EVT_NOTIFY,
  UT_PLAYER_EVT_STATE_UPDATE,
  UT_PLAYER_EVT_PROGRESS_UPDATE,
};

typedef enum upnp_transport_play_event upnp_transport_play_event_t;


enum upnp_transport_play_error {
  UT_PLAY_E_OK = 0,
  UT_PLAY_E_GERNIC,
  UT_PLAY_E_WOULDBLOCK,
  UT_PLAY_E_BUSY,
  UT_PLAY_E_INVALID_STATE,
  UT_PLAY_E_INVALID_PARAM,
  UT_PLAY_E_NO_MEMORY,
};

typedef enum upnp_transport_play_error upnp_transport_play_error_t;

enum upnp_transport_play_notify {
  UT_PLAY_NTY_EOS,
  UT_PLAY_NTY_INTERNAL_ERROR,
};

typedef enum upnp_transport_play_notify upnp_transport_play_notify_t;


struct ut_play_evt_op_result_param {
  upnp_transport_play_op_t op;
  upnp_transport_play_error_t result;
};

typedef struct ut_play_evt_op_result_param ut_play_evt_op_result_param_t;


struct ut_play_evt_notify_param {
  upnp_transport_play_notify_t details;
};

typedef struct ut_play_evt_notify_param ut_play_evt_notify_param_t;


struct ut_play_evt_state_update_param {
  upnp_transport_play_state_t state; /* new state */
};

typedef struct ut_play_evt_state_update_param ut_play_evt_state_update_param_t;


struct ut_play_evt_progress_update_param {
  slim_word duration;
  slim_int percent;
};

typedef struct ut_play_evt_progress_update_param ut_play_evt_progress_update_param_t;


struct upnp_transport_play_event_param {
  upnp_transport_play_event_t evt;
  union {
    ut_play_evt_op_result_param_t op_result;
    ut_play_evt_notify_param_t notify;
    ut_play_evt_state_update_param_t state_update;
    ut_play_evt_progress_update_param_t progress_update;
  } u;
};

typedef struct upnp_transport_play_event_param upnp_transport_play_event_param_t;

typedef struct _upnp_transport_play upnp_transport_play_t;

typedef slim_int (*upnp_transport_play_callback_t)(upnp_transport_play_t *in_player, 
                                                   void *in_user_data, 
                                                   upnp_transport_play_event_t in_event, 
                                                   upnp_transport_play_event_param_t *in_param);

struct event_param_list_node {
  struct event_param_list_node *next;
  struct event_param_list_node *prev;
  upnp_transport_play_event_param_t  e_param;
};

struct _upnp_transport_play {
  upnp_transport_t ut;
  /*slim_char *pinfo;*/
  upnp_transport_play_callback_t callback;
  void *user_data;
  void *progress;
  slim_bool stream_close;
  dlna_progress_handle e_dispatcher;
#ifdef DEVELOPMENT_ENABLE_SERVER_AND_RENDERER_PLAYSPEED
  upnp_player_play_speed_t ps;
#endif /*DEVELOPMENT_ENABLE_SERVER_AND_RENDERER_PLAYSPEED*/
#ifdef DEVELOPMENT_ENABLE_UPNPTRANSPORT_SEEK
	upnp_transport_seek_type_t seek_type;	
	dlna_uint64 seek_offset;
#endif
  List (struct event_param_list_node*) event_param_list;
};

upnp_transport_play_t*
upnp_transport_play_alloc (upnp_transport_manager_t *in_tm);

void
upnp_transport_play_free (upnp_transport_play_t *self);

#ifdef DEVELOPMENT_ENABLE_UPNPTRANSPORT_SEEK
slim_int
upnp_transport_play_seek (upnp_transport_play_t *self);
#endif

slim_int
upnp_transport_play_open (upnp_transport_play_t *self, slim_char *in_uri, slim_char *in_pinfo, upnp_transport_play_callback_t in_callback, void *in_user_data);

slim_int
upnp_transport_play_play (upnp_transport_play_t *self, slim_int in_speed);

slim_int
upnp_transport_play_pause (upnp_transport_play_t *self);

slim_int
upnp_transport_play_stop (upnp_transport_play_t *self);

/* seek time in seconds */
slim_int
upnp_transport_play_seek_time (upnp_transport_play_t *self, slim_int time_pos);

/* seek time in bytes */
slim_int
upnp_transport_play_seek_bytes (upnp_transport_play_t *self, slim_int byte_pos);

slim_int
upnp_transport_play_close (upnp_transport_play_t *self);

upnp_transport_play_state_t
upnp_transport_play_get_state (upnp_transport_play_t *self);

#endif  /* NFLC_UPNP_TRANSPORT_PLAY_H */
