/*
 * dlna_transport_manager.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_TRANSPORT_MGR_H
#define NFLC_DLNA_TRANSPORT_MGR_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct dlna_object*
dlna_object_lookup_by_tid (dlna_client_t *top, slim_int  tid);

/*find a transport by udn firstly, and then close it*/
slim_int
dlna_transport_close_by_udn(dlna_client_t *top, slim_char *udn);

slim_int
dlna_object_transport_get (dlna_client_t *top, TDLNAObjectEventHandler in_obj_eh,
                      void *in_arg, dlna_object_t *dmr, dlna_object_t **out_play);

slim_int
dlna_object_transport_get2 (dlna_object_t *in_dmr, TDLNAObjectEventHandler in_obj_eh,
                      void *in_arg, dlna_object_t **out_play);

slim_int
dlna_object_play_get (struct dlna_object *obj, TDLNAObjectEventHandler in_obj_eh,
                      void *in_arg, struct dlna_object *dmr, slim_int in_res_index, dlna_object_t **out_play);

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
slim_int
dlna_object_direct_play_get (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh,
                      void *in_arg, dlna_object_t *dmr, dlna_object_t **out_play);
slim_int
dlna_object_direct_play_from_local_get (dlna_object_t *obj, slim_opaque in_album_art, TDLNAObjectEventHandler in_obj_eh,
                                            void *in_arg, dlna_object_t *dmr, dlna_object_t **out_play, slim_char **out_url);
slim_int
dlna_object_is_local_content(dlna_object_t *obj, slim_bool *out_is_local, slim_char **out_file_path);
#endif

slim_int
dlna_transport_lookup (dlna_client_t *top, slim_int in_types, 
                   dlna_object_t ** out_obj_array, slim_word in_obj_num);

slim_int
dlna_transport_get_state (dlna_client_t *top, dlna_object_t * obj, slim_int * out_state);
slim_int
dlna_transport_get_dlnaps (dlna_client_t *top, dlna_object_t * obj, slim_char** out_state);

#ifdef DLNA_SUPPORT_DOWNLOADER
slim_int
dlna_object_download_resume (dlna_object_t *obj);

slim_int
dlna_object_download_pause (dlna_object_t *obj);

slim_int
dlna_object_download_cancel (dlna_object_t *obj);

struct dlna_object *
dlna_object_download_get (struct dlna_object *obj, TDLNAObjectEventHandler in_obj_eh,
                            void *in_arg, slim_char* dest_path, slim_int in_res_index);

dlna_object_t*
dlna_object_download_file(dlna_client_t *obj, TDLNAEventHandler in_object, void *in_arg, slim_char *item, slim_char *url, slim_char *destinationPath);

#endif

struct dlna_object *
dlna_object_upload_get (struct dlna_object *obj,
                        TDLNAObjectEventHandler in_obj_eh, void *in_arg,
                        struct dlna_object *dms);

slim_int
dlna_object_thumbnail_get (struct dlna_object *obj,
                           TDLNAObjectEventHandler in_obj_eh,
                           void *in_arg, struct dlna_object *dmr, dlna_object_t **out_play);

slim_char *
dlna_object_prop_path_get (struct dlna_object *self);

slim_int
dlna_player_set_item_group(dlna_player in_player, dlna_item_group in_item_group);

dlna_item_group
dlna_player_get_item_group(dlna_player in_player);


/* DLNA SetAVTransportURI result. */
slim_int
dlna_set_avt_uri_action_result (dlna_client_t *top, struct upnp_param_action *in_param);

/* DLNA SetNextAVTransportURI result. */
slim_int
dlna_set_next_avt_uri_action_result (dlna_client_t *top, struct upnp_param_action *in_param);


/* DLNA Play result.  */
slim_int
dlna_play_action_result (dlna_client_t *top, struct upnp_param_action *in_param);


/* DLNA Stop result.  */
slim_int
dlna_stop_action_result (dlna_client_t *top, struct upnp_param_action *in_param);


/* DLNA AVT: pause result.  */
slim_int
dlna_pause_action_result (dlna_client_t *top, struct upnp_param_action *in_param);


/* DLNA Seek result.  */
slim_int
dlna_seek_action_result (dlna_client_t *top, struct upnp_param_action *param);

/* DLNA Play next result.  */
slim_int 
dlna_play_next_action_result (dlna_client_t *top, struct upnp_param_action *param);

/* DLNA Play previous result.  */
slim_int 
dlna_play_previous_action_result (dlna_client_t *top, struct upnp_param_action *param);


/* DLNA GetPositionInfo result.  */
slim_int
dlna_get_position_info_action_result (dlna_client_t *top, struct upnp_param_action *in_param);

/* DLNA GetTransportInfo result.  */
slim_int
dlna_get_transport_info_action_result (dlna_client_t *top, struct upnp_param_action *param);

slim_char *
generateGenericPinfo(slim_char *in_upnpClass);

slim_char *
generatePinfo(slim_char *in_fileName, slim_char *in_url, slim_char *in_upnpClass);

/* DLNA GetMediaInfo result.  */
slim_int
dlna_get_media_info_action_result (dlna_client_t *top, struct upnp_param_action *param);


void
dlna_query_result (dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_object_is_playable (dlna_object_t *ob, dlna_object_t *dmr, slim_int in_res_index);

slim_int
dlna_object_is_playable_by_caps (dlna_object_t *obj, slim_char *info, slim_int in_res_index);

slim_int
dlna_transport_variable_update (dlna_client_t *top, gena_notify_param_t *in_param);

/* DLNA contents updates.  */
slim_int
dlna_contents_update (dlna_client_t *top, struct upnp_param_transport *in_param);

slim_int
dlna_transport_play_update (dlna_client_t *top, struct upnp_param_transport *in_param);

slim_int
dlna_object_is_support_sort_criteria (dlna_object_t *obj, slim_char* in_sort_crt, slim_bool* out_is_support);

slim_int
dlna_object_is_support_search_capability (dlna_object_t *obj, slim_char* in_search_caps, slim_bool* out_is_support);

slim_int
dlna_object_get_support_search_capability (dlna_object_t *obj, slim_char *out_caps_buf, slim_int *inout_caps_buf_size);

slim_int
dlna_object_get_support_sort_criteria (dlna_object_t *obj, slim_char *out_crt_buf, slim_int *inout_crt_buf_size);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* NFLC_DLNA_TRANSPORT_MGR_H */
