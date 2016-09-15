/*
 * upnp_local.h
 * Copyright (C) 2012 ACCESS CO.,LTD.
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

#include <dlna_peer.h>
#include <dmp_api.h>

TDMPObject
upnp_local_get_object(dlna_object_t* obj,slim_char *in_uri, slim_char *in_pinfo, slim_char* in_title, TDLNAObjectEventHandler in_obj_eh, void *in_arg);

slim_int
upnp_local_close_object(dlna_object_t* obj);

slim_int
upnp_local_play_object(dlna_object_t* obj);

slim_int
upnp_local_pause_object(dlna_object_t* obj);

slim_int
upnp_local_pause_by_object(dlna_object_t* obj, dlna_player_trickmode mode);

slim_int
upnp_local_stop_object(dlna_object_t* obj);

slim_int
upnp_local_jump_object (dlna_object_t* obj, TUPNPObjectSeekParam *seek);

slim_int
upnp_local_seektime (dlna_object_t* obj, slim_int in_target_time, slim_bool b_relative);

slim_int
upnp_local_seekbytes (dlna_object_t* obj, dlna_uint64 in_target_bytes, slim_bool b_relative);

slim_int
upnp_local_seektrack (dlna_object_t* obj, slim_word in_target_track);

slim_int
upnp_local_get_state_object(dlna_object_t* obj, slim_int *out_state);

slim_int
upnp_local_fastplay_object(dlna_object_t* obj, slim_int in_speed, dlna_player_trickmode in_mode);

slim_int
upnp_local_slowplay_object(dlna_object_t* obj, slim_int in_speed, dlna_player_trickmode in_mode);

#endif
