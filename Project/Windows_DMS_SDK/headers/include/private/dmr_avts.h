/*
 * dmr_avts.h
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

#ifndef NFLC_DMR_AVTS_H
#define NFLC_DMR_AVTS_H

#include <nflc_sxml.h>
#include <upnp_avts.h>

struct upnp_avts_state_info {
  struct upnp_avts_state_info *next;
  struct upnp_avts_state_info *prev;

	slim_char *sid;
	struct upnp_avts_media_info mediaInfo;
	struct upnp_avts_transport_info transportInfo;
	struct upnp_avts_position_info positionInfo;
	struct upnp_avts_transport_settings tarnsportSettings;
	slim_char *currentTransportAction;
};
typedef struct upnp_avts_state_info upnp_avts_state_info_t;


struct dmr_avts_request {
  struct dmr_avts_request *prev;
  struct dmr_avts_request *next;
  struct upnp_action_request base;
  slim_int tid; /* AVTransport ID*/
  slim_word rid; /* Unique Request ID */
};

/* ConnectionManager service.  */
struct dmr_avts
{
  /* DMR service base structure.  */
  struct dmr_service base;
  upnp_avts_t *avts;
  List(struct dmr_avts_request*) req_list;
	List(struct upnp_avts_state_info*) state;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

struct dmr_service *
dmr_avts_alloc (struct dmr *top);

slim_int
dmr_avts_free (struct dmr_service *service);

#ifdef ENABLE_AHL
void
dmr_avts_set_player_info(struct dmr_service *s);

void
dmr_avts_set_content_info(struct dmr_service *s, slim_char *in_content_info);

void
dmr_avts_set_current_play_position(struct dmr_service *s, slim_int in_time, slim_int in_byte);

void
dmr_avts_set_player_errcode(struct dmr_service *s, slim_int in_error_code);
#endif /* ENABLE_AHL */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMR_AVTS_H */
