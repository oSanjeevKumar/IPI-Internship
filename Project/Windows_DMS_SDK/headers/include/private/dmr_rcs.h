/*
 * dmr_rcs.h
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

#ifndef NFLC_DMR_RCS_H
#define NFLC_DMR_RCS_H

struct rcs_channel_state_info {
  struct rcs_channel_state_info *next;
  struct rcs_channel_state_info *prev;

	dlna_volume_mute_state mute;
	slim_tiny volume;
	slim_int 	volume_db;
	slim_char *sid;
};
typedef struct rcs_channel_state_info rcs_channel_state_info_t;

struct rcs_channel_info_t
{
  dlna_player_channel id;
  dlna_volume_mute_state mute;
  slim_tiny volume;
  slim_int volume_db;
  slim_int min_vol_db;
  slim_int max_vol_db;
	List(rcs_channel_state_info_t *) state;
};
typedef struct rcs_channel_info_t rcs_channel_info_t;

struct rcs_volume_control_t
{
  void* handle;
  rcs_channel_info_t* channels;
  slim_int channels_num;
};

typedef struct rcs_volume_control_t rcs_volume_control_t;

#ifndef ENABLE_AHL
typedef void (* dmr_rcs_volume_state_callback) (dlna_volume_control_handle handle, dlna_volume_control_event event, void* param);
#else /* ENABLE_AHL */
typedef void (* dmr_rcs_volume_state_callback) (dlna_volume_control_event event, void* param);
#endif /* ENABLE_AHL */

/* RenderingControl service.  */
struct dmr_rcs
{
  /* DMR service base structure.  */
  struct dmr_service base;
  rcs_volume_control_t vc;

	/* Progres handle for LastChange event */
	dlna_progress_handle eLastChangeProgressHandle;

	/* LastChange event must be update */
	slim_bool updateLastChange;

	/* LastChange timer ongoing */
	slim_bool lastCahngeTimerOnging;

	/* Volume state callback to inform the core about changed volume setting */
	dmr_rcs_volume_state_callback volumeStateCallback;

  /* Presets value from media player for A_ARG_TYPE_PresetName */
  slim_char *presetName;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dmr_service *
dmr_rcs_alloc (struct dmr *top);

slim_int
dmr_rcs_free (struct dmr_service *service);

#ifdef ENABLE_AHL
void
dmr_rcs_set_player_info (struct dmr_service *service);
#endif /* ENABLE_AHL */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMR_RCS_H */
