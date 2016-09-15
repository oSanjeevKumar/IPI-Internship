/*
 * nflc_player_api.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_PLAYER_API_H
#define NFLC_PLAYER_API_H

/*player event type*/
typedef enum
{
  NFLC_PLAYER_EVENT_OPERATION_RESULT,
  NFLC_PLAYER_EVENT_ERROR,
  NFLC_PLAYER_EVENT_STATUS_CHANGED,
} nflc_player_event_t;

/*player operation type*/
typedef enum
{
  NFLC_PLAYER_OP_SET_MEDIA_INFO,
  NFLC_PLAYER_OP_PLAY,
  NFLC_PLAYER_OP_PAUSE,
  NFLC_PLAYER_OP_STOP,  
} nflc_player_operation_t;

/*player API return code*/
typedef enum
{
  NFLC_PLAYER_SUCCESS     = 0,   
  NFLC_PLAYER_GENERIC_ERROR  = -1,
  NFLC_PLAYER_WOULDBLOCK     = -2,
  NFLC_PLAYER_INVALID_ARG    = -65535,
  NFLC_PLAYER_OUT_OF_MEMORY,
} nflc_player_return_t;

/* player error code, for callback parameter */
typedef enum
{
  NFLC_PLAYER_CB_SUCCESS = 0,   
  NFLC_PLAYER_CB_UNSUPPORT_FORMAT,
  NFLC_PLAYER_CB_CANNOT_CONNECT_SERVER,
  NFLC_PLAYER_CB_UNKNOWN,
} nflc_player_error_t;

/*player state*/
typedef enum
{
  NFLC_PLAYER_STATE_STOPPED = 0,   
  NFLC_PLAYER_STATE_PLAYING,
  NFLC_PLAYER_STATE_PAUSED,
  NFLC_PLAYER_STATE_FINISHED,  
  NFLC_PLAYER_STATE_UNKNOWN,
} nflc_player_state_t;

/*player stream handle*/
typedef void *nflc_player_stream;

/* Player display parameter.  */
struct _nflc_player_display_param
{
  /* Display X position.  */
  slim_word x;
  /* Display position.  */
  slim_word y;
  /* Width of the display.  */
  slim_word w;
  /* Height of the display.  */
  slim_word h;
};
typedef struct _nflc_player_display_param nflc_player_display_param_t;

/* Player callback parameter.  */
struct _nflc_player_param
{
  /* operation type*/
  nflc_player_operation_t operation;   /*for NFLC_PLAYER_EVENT_OPERATION_RESULT*/
  /*error code */
  nflc_player_error_t err;         /*for NFLC_PLAYER_EVENT_OPERATION_RESULT and NFLC_EVENT_PLAYER_ERROR*/ 
  /*current state*/
  nflc_player_state_t state;      /*for NFLC_PLAYER_EVENT_STATUS_CHANGED*/
};
typedef struct _nflc_player_param nflc_player_param_t;

/*player callback*/
typedef void (*nflc_player_callback_t) (nflc_player_stream s,
                                          nflc_player_event_t e,
                                          void *in_arg,
                                          nflc_player_param_t *in_param);


/* Player callback parameter.  */
struct _nflc_player_media_info
{
  /*media uri*/
  slim_char *uri;
  /*MIME type*/
  slim_char *type;
  /*DLNA resource attribute*/
  slim_char *dlna_res_attr;
};
typedef struct _nflc_player_media_info nflc_player_media_info_t;


#ifdef __cplusplus
extern "C" {
#endif

nflc_player_stream
nflc_player_open (nflc_player_callback_t cb, void *in_arg);

slim_int 
nflc_player_close (nflc_player_stream s);

slim_int
nflc_player_set_display_param (nflc_player_stream s, nflc_player_display_param_t *display);

slim_int
nflc_player_set_media_info (nflc_player_stream s, nflc_player_media_info_t *in_minfo, slim_word in_minfo_num);

slim_int
nflc_player_play (nflc_player_stream s, slim_int in_speed);

slim_int
nflc_player_stop (nflc_player_stream s);

slim_int
nflc_player_pause (nflc_player_stream s);

slim_int
nflc_player_get_status (nflc_player_stream s, nflc_player_state_t *out_state);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_PLAYER_API_H */
