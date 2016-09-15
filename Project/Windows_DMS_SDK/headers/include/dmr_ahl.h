/*
* dmr_ahl.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef DMR_AHL_H
#define DMR_AHL_H

#include <ahl.h>

/* dmrInstance_t is the instance of the library */
typedef void *dmrInstance_t;

typedef enum dmrEvent_ {
  DMR_ACTION_PREPARE_PLAYBACK = 0,
  DMR_ACTION_CLOSE_PLAYBACK,
  DMR_ACTION_PLAY,
  DMR_ACTION_PAUSE,
  DMR_ACTION_STOP,
  DMR_ACTION_SEEK,
  DMR_ACTION_SET_PLAY_SPEED,
  DMR_ACTION_VOLUME_CONTROL,
  DMR_ACTION_PREPARE_NEXT_PLAYBACK,
  DMR_ACTION_PLAY_NEXT,
  DMR_ACTION_SELECT_PRESET
} dmrEvent;

/* Callback function of application */
#ifdef WIN32
typedef void (__stdcall *dmrCallbackHandler) (void * in_arg, dmrEvent in_event, void *in_param);
#else
typedef void(*dmrCallbackHandler) (void * in_arg, dmrEvent in_event, void *in_param);
#endif

/* Initial parameter for NFLC dmr core initialization */
struct dmrInitParams {
  slim_char *configDirectory;       // Directory path in which DMR configuration XML file is located
  slim_half port;                   // DMR UPnP server port number
  dmrCallbackHandler callback;      // Callback function to inform application layer
  void *callbackArg;                // Argument specified by application layer that is used to call callback function
#ifdef ENABLE_WEBSOCKETINTERFACE
  slim_bool enableWebInterface;
  slim_int webInterfacePort;
  slim_char *webInterfaceDirectory;
#endif /* ENABLE_WEBSOCKETINTERFACE */
};

typedef struct dmrInitParams dmrInitParams_t;

/* Play state to inform NFLC dmr core about player status. */
typedef enum playState_ {
  PLAY_STATE_ERROR = -1,
  PLAY_STATE_PREPARED = 0,
  PLAY_STATE_CLOSED,
  PLAY_STATE_TRANSITIONING,
  PLAY_STATE_STOPPED,
  PLAY_STATE_PLAYING,
  PLAY_STATE_PAUSED,
  PLAY_STATE_FAST_FORWARD,
  PLAY_STATE_FAST_REWIND,
  PLAY_STATE_SLOW_FORWARD,
  PLAY_STATE_SLOW_REWIND,
  PLAY_STATE_TIME_SEEKED,
  PLAY_STATE_BYTE_SEEKED,
  PLAY_STATE_END_OF_MEDIA,
  PLAY_STATE_NEXT_PREPARED,
  PLAY_STATE_TRANSITIONING_NEXT,
  PLAY_STATE_END // Last item in list, no play state
} playState;

typedef enum contentType_ {
  CONTENT_TYPE_IMAGE = 0,
  CONTENT_TYPE_AUDIO,
  CONTENT_TYPE_VIDEO,
  CONTENT_TYPE_DOCUMENT
} contentType;

typedef enum seekType_ {
   SEEK_TYPE_ABS_TIME = 0,
   SEEK_TYPE_REL_TIME,
   SEEK_TYPE_ABS_BYTE,
   SEEK_TYPE_REL_BYTE
} seekType;

typedef enum trickMode_ {
  TRICK_MODE_DEFAULT = 0,
  TRICK_MODE_BY_TIMESEEK,
  TRICK_MODE_BY_BYTESEEK,
  TRICK_MODE_BY_PLAYSPEED,
  TRICK_MODE_BY_CONNECTION_STALLING
} trickMode;

typedef enum playSpeedType_ {
  PLAY_SPEED_TYPE_FAST_FORWARD = 0,
  PLAY_SPEED_TYPE_FAST_REWIND,
  PLAY_SPEED_TYPE_SLOW_FORWARD,
  PLAY_SPEED_TYPE_SLOW_REWIND
} playSpeedType;

typedef enum dmrVolumeControlCommand_ {
  VOLUME_CONTROL_SET_VALUE = 0,
  VOLUME_CONTROL_SET_VALUE_DB,
  VOLUME_CONTROL_SET_MUTESTATE,
  VOLUME_CONTROL_END // Last item in list, no control action
} dmrVolumeControlCommand;

typedef enum dmrPlayerErrorCode_ {
  PLAYER_ERROR_UNKNOWN = 0,
  PLAYER_ERROR_SERVER_DIED,
  PLAYER_ERROR_TIMEOUT,
  PLAYER_ERROR_RESOURCE_NOT_FOUND,
  PLAYER_ERROR_UNSUPPORTED_FORMAT,
  PLAYER_ERROR_MAX
} dmrPlayerErrorCode;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Function Declarations */

dmrInstance_t
dmrInitialize(dmrInitParams_t *in_params);

void 
dmrFinalize(dmrInstance_t in_instance);

slim_char *
dmrGetFriendlyName(dmrInstance_t in_instance);

returnValue 
dmrSetFriendlyName(dmrInstance_t in_instance, slim_char *in_friendlyName);

XMLBuffer 
dmrGetCurrentContentMetadata(dmrInstance_t in_instance);

returnValue
dmrNotifyPlayState(dmrInstance_t in_instance, playState in_playState, XMLBuffer in_player_info);

returnValue
dmrNotifyMuteState(dmrInstance_t in_instance, slim_char *in_channel, slim_int in_value);

returnValue
dmrNotifyVolumeState(dmrInstance_t in_instance, slim_char *in_channel, slim_int in_value, slim_int in_valueDB);


returnValue
dmrNotifyCurrentPlayPosition(dmrInstance_t in_instance, slim_int in_time, slim_int in_byte);

#ifdef ENABLE_WEBSOCKETINTERFACE
slim_int
webinterface_sendMessageDMRResponse(webinterfaceInstance_t *in_instance, slim_char *in_request, slim_int returnValue);
#endif /* ENABLE_WEBSOCKETINTERFACE */

returnValue
dmrGetCoreInfo(dmrInstance_t in_instance, XMLBuffer *out_info);

returnValue
dmrNotify(dmrInstance_t in_instance, notifyEvent in_event, XMLBuffer in_param);
returnValue
dmrStart(dmrInstance_t in_instance, XMLBuffer in_info);

returnValue
dmrStop(dmrInstance_t in_instance);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DMR_AHL_H*/
