/*
 * upnp_avts.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
#ifndef UPNP_AVTS_H
#define UPNP_AVTS_H

#include <upnp_player.h>

/*
 *  Action Result is either internal type (< 0) or SOAP AVTS type (>0)
 */

enum {
  AVT_EVENT_ACTION_RESULT,
};

/* AVT States are fully compliant to AVTS spec */
enum avt_state{
  AVT_STATE_NO_MEDIA = 0,
  AVT_STATE_STOPPED,
  AVT_STATE_PLAYING,
  AVT_STATE_PAUSED_PLAY,
  AVT_STATE_TRANSITION,
  AVT_STATE_END_OF_STREAM,
  AVT_STATE_MAX
};
typedef enum avt_state avt_state_t;

/* AVT Status are fully compliant to AVTS spec */
enum avt_status{
  AVT_STATUS_OK = 0,
  AVT_STATUS_ERROR_OCCURED
};
typedef enum avt_status avt_status_t;

struct upnp_avts_media_info {
  /* NrTracks */
  slim_char *tracks;
  /* MediaDuration */
  slim_char *duration;
  /* CurrentURI */
  slim_char *current_uri;
  /* CurrentURIMetaData */
  slim_char *current_uri_metadata;
  /* NextURI */
  slim_char *next_uri;
  /* NextURIMetaData */
  slim_char *next_uri_metadata;
  /* PlayMedium */
  slim_char *play_medium;
	/* medium_category */
	slim_char *medium_category;
  /* RecordMedium */
  slim_char *record_medium;
  /* WriteStatus */
  slim_char *write_status;
  /* PossiblePlaybackStorageMedia */
  slim_char *possible_playback_storage_media;
  /* PossiblePlaybackStorageMedia */
  slim_char *possible_record_storage_media;
};
typedef struct upnp_avts_media_info upnp_avts_media_info_t;

struct upnp_avts_transport_settings {
  /* CurrentPlayMode */
  slim_char *play_mode;
  /* CurrentRecordQualityMode */
  slim_char *rec_quality_mode;
	/* PosibleRecordQualityModes */
	slim_char *possible_rec_quality_mode;
};
typedef struct upnp_avts_transport_settings upnp_avts_transport_settings_t;

struct upnp_avts_transport_info {
  /* TransportState */
  slim_char *state;
  /* External TransportState */
  slim_char *X_state;
  /* TransportStatus */
  slim_char *status;
  /* CurrentSpeed */
  slim_char *current_speed;
};
typedef struct upnp_avts_transport_info upnp_avts_transport_info_t;

struct upnp_avts_position_info {
  /* Track */
  slim_char *current_track;
  /* TrackDuration */
  slim_char *track_duation; 
  /* TrackMetaData */
  slim_char *track_metadata;
  /* TrackURI */
  slim_char *current_track_uri;
  /* RelTime */
  slim_char *rel_time;
  /* AbsTime */
  slim_char *abs_time;
  /* RelCount */
  slim_char *rel_count;
  /* AbsCount */
  slim_char *abs_count;
};
typedef struct upnp_avts_position_info upnp_avts_position_info_t;

struct upnp_avts;
typedef slim_int (*upnp_avts_callback)(struct upnp_avts *in_avts, slim_int in_tid, slim_int in_event, slim_int in_result, slim_opaque in_arg);

struct av_transport
{
  /* UPnP AVTS instance. */
  struct upnp_avts *avts;

  /* Flags.  */
  slim_word flags;

  /* Transport index. */
  slim_int tid;

  slim_bool busy;

  /* Current transport state. */
  avt_state_t state;

  /* Current transport status. */
  avt_status_t status;

  /* URI.  */
  slim_char *uri;
  slim_char *next_uri;
  
  /* Content protocol information. */
  slim_char *pinfo;

  /*Content Title*/
  slim_char *title;

  /* Action being done. */
  void *action;

  /* UPnP Player Stream */
  uplayer_stream_handle stream;

  /* Content infomation */
  slim_word tracks;
  slim_char *duration;
  slim_char *byte_size;
  slim_bool controller_byte_seek;
  slim_bool controller_time_seek;
  
  /* First Track Information as default */
  slim_word track1_no;
  slim_word track1_duration;
  slim_char *track1_uri;

  slim_bool isPausableByConnectionStalling;
  slim_bool isPausableBySeek;

  slim_bool isByteSeekable;
  slim_bool isTimeSeekable;

  /* 
    * Service Variables 
    */

  /* For AVT:GetMediaInfo */
  struct sbuf s_NumberOfTracks;
  struct sbuf s_CurrentMediaDuration;
  struct sbuf s_CurrentURIMetaData; 
  struct sbuf s_NextURIMetaData; 
  sXML *s_CurrentURIMetaData_doc;
  sXML *s_NextURIMetaData_doc;

  /* For AVT:GetTransportInfo */
  struct sbuf s_TransportState;
  struct sbuf s_TransportPlaySpeed;

  /* For AVT:GetPositionInfo */
  struct sbuf s_CurrentTrack;
  struct sbuf s_CurrentTrackDuration;
  struct sbuf s_CurrentTrackURI;
  struct sbuf s_RelativeTimePosition;
  struct sbuf s_AbsoluteTimePosition;
  struct sbuf s_RelativeCounterPosition;
  struct sbuf s_AbsoluteCounterPosition;

  /* For AVT:GetCurrentTransportActions */
  struct sbuf s_CurrentTransportActions;

  /* DLNA controller-byte seek operation */
  struct sbuf s_X_DLNA_RelativeBytePosition;
  struct sbuf s_X_DLNA_AbsoluteBytePosition;
  struct sbuf s_X_DLNA_CurrentTrackSize;
  
  /* DLNA controller-time seek operation */
  struct sbuf s_X_DLNA_RelativeTimePosition;
};
typedef struct av_transport av_transport_t;

struct upnp_avts {
  upnp_server_t *us;

  slim_char *service_id;
  
  /* Transport vector.  */
  struct _vector *v_avt;

  /* Callback to action result.  */
  upnp_avts_callback callback;

  /* Argument of callback.  */
  slim_opaque callback_arg;

  /* UPnP Player Manager */
  upnp_player_manager_t *upm;

	/* Progres handle for LastChange event */
	dlna_progress_handle eLastChangeProgressHandle;

	/* LastChange event must be update */
	slim_bool updateLastChange;

	/* LastChange timer ongoing */
	slim_bool lastCahngeTimerOnging;
};
typedef struct upnp_avts upnp_avts_t;

/* AVT:GetTransportSettings */
slim_int
upnp_avts_action_GetTransportSettings (av_transport_t *self, upnp_avts_transport_settings_t *out_settings);

/* AVT:GetMediaInfo */
slim_int
upnp_avts_action_GetMediaInfo (av_transport_t *self, upnp_avts_media_info_t *out_info);

/* AVT:GetTransportInfo */
slim_int
upnp_avts_action_GetTransportInfo (av_transport_t *self, upnp_avts_transport_info_t *out_info);

/* AVT:GetPositionInfo */
slim_int
upnp_avts_action_GetPositionInfo (av_transport_t *self, upnp_avts_position_info_t *out_info);

/* AVT:GetCurrentTransportActions */
slim_int
upnp_avts_action_GetCurrentTransportActions (av_transport_t *self, slim_char **out_info);

/* AVT:X_DLNA_GetBytePositionInfo */
slim_int
upnp_avts_action_X_DLNA_GetBytePositionInfo (av_transport_t *self, 
                                             slim_char **out_track_size,
                                             slim_char **out_rel_byte,
                                             slim_char **out_abs_byte);

/* AVT:SetAVTransportURI */
slim_int
upnp_avts_action_SetAVTransportURI (av_transport_t *self, slim_char *in_pinfo, slim_char *in_uri);

/* AVT:SetNextAVTransportURI */
slim_int
upnp_avts_action_SetNextAVTransportURI (av_transport_t *self, slim_char *in_pinfo, slim_char *in_title, slim_char *in_uri);

/* AVT:Play */
slim_int
upnp_avts_action_Play(av_transport_t *self, slim_char *in_playspeed);

/* AVT:Pause */
slim_int
upnp_avts_action_Pause(av_transport_t *self);

/* AVT:Seek */
slim_int
upnp_avts_action_Seek(av_transport_t *self, slim_char *in_seek_mode, slim_char *in_target);

/* AVT:Next */
slim_int
upnp_avts_action_Next(av_transport_t *self);

/* AVT:Previous */
slim_int
upnp_avts_action_Previous(av_transport_t *self);

/* AVT:Stop */
slim_int
upnp_avts_action_Stop(av_transport_t *self);

void
upnp_avts_action_end (av_transport_t *self, slim_int in_result);

av_transport_t *
upnp_avts_transport_lookup (upnp_avts_t *in_avts, slim_int in_tid);

slim_int
upnp_avts_transport_alloc (upnp_avts_t *in_avts, slim_int *out_tid);

slim_int
upnp_avts_transport_free (upnp_avts_t *in_avts, slim_int in_tid);

#ifdef ENABLE_AHL
upnp_avts_t*
upnp_avts_alloc (upnp_server_t *us, slim_char *in_service_id, upnp_avts_callback in_callback, slim_opaque in_callback_arg, dmr_ahl_callback in_cb, slim_opaque in_ahl_cb_arg);
#else
upnp_avts_t*
upnp_avts_alloc (upnp_server_t *us, slim_char *in_service_id, upnp_avts_callback in_callback, slim_opaque in_callback_arg);
#endif /*ENABLE_AHL*/

void
upnp_avts_free (upnp_avts_t *self);

#ifdef ENABLE_AHL
void
upnp_avts_set_player_info(upnp_avts_t *self, slim_char *in_player_info);

void
upnp_avts_set_content_info(upnp_avts_t *self, slim_char *in_content_info);

void
upnp_avts_set_play_position(upnp_avts_t *self, slim_int in_time, slim_int in_byte);

void
upnp_avts_set_player_errcode(upnp_avts_t *self, slim_int in_error_code);

#endif /* ENABLE_AHL */

#endif /* UPNP_AVTS_H */
