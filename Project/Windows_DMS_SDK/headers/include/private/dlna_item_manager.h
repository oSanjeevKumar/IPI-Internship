/*
 * dlna_item_manager.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_ITEM_MGR_H
#define NFLC_DLNA_ITEM_MGR_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
dlna_object_get_dtcp_info_by_pinfo (dlna_object_t *self, slim_char *in_pinfo, TDLNAResPropDtcpInfoParam *out_dtcp_info);

slim_char *
dlna_object_prop_get (struct dlna_object *self, slim_char *str, slim_char *attr_str);

slim_int
dlna_object_prop_get_res_count (dlna_object_t *self, slim_int *count);

#ifdef ENABLE_MOVIEDB_MOVIECOVER
slim_int
dlna_object_prop_get_coverurl(dlna_object_t *self, slim_char **out_coverurl);
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

#ifdef ENABLE_GPS_SUPPORT
slim_int
dlna_object_prop_get_exif_gps (dlna_object_t *self, slim_char **out_gps_latitude,
                              slim_char **out_gps_longitude);
#endif /* ENABLE_GPS_SUPPORT */

#ifdef ENABLE_SUBTITLE_SUPPORT
slim_int
dlna_object_prop_get_subtitle_count (dlna_object_t *self, slim_char *resURI, slim_int *count);

slim_int
dlna_object_prop_get_subtitle(dlna_object_t *self, slim_char *in_resURI, slim_int in_subtitle_index, TDLNASubtitle* out_subtitle);
#endif /* ENABLE_SUBTITLE_SUPPORT */

slim_int
dlna_object_prop_get_user_metadata_count (dlna_object_t *self, slim_int * out_count);

slim_int
dlna_object_prop_get_user_metadata(dlna_object_t *self, slim_int in_subtitle_index, slim_char ** out_name, slim_char ** out_value);

slim_int
dlna_object_prop_get_res_list (dlna_object_t *self, TDLNAResPropInfoParam *out_res_info, slim_int in_req_res_num, slim_int in_begin_res_index);

slim_int
dlna_object_prop_get_nth (dlna_object_t *self, slim_char *in_node_str, slim_char *in_attr_str, slim_int in_res_index,
                                               slim_char **out_nth);

slim_int
dlna_param_action_parse (struct upnp_param_action *param,
                        slim_int *count, slim_int *total, sXML **result_doc);

slim_int
dlna_object_browse (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh,
                    void *in_arg, slim_char *in_filter, slim_int in_beg, slim_int in_num,
                    slim_char *in_sort_crt);

#if defined(DLNA_SUPPORT_DMSCP) || defined(DEVELOPMENT_CONTENT_AGGREGATION)
                    
slim_int
dlna_object_browse_by_id(dlna_object_t *obj, slim_char* in_id, TDLNAObjectEventHandler in_obj_eh,
                    void *in_arg, slim_char *in_filter, slim_int in_beg, slim_int in_num,
                    slim_char *in_sort_crt);
#endif /* DLNA_SUPPORT_DMSCP || DEVELOPMENT_CONTENT_AGGREGATION */

#if defined (DLNA_SUPPORT_X_BROWSE)
slim_int
dlna_object_x_browse (struct dlna_object *obj, TDLNAObjectEventHandler in_obj_eh,
                      void *in_arg, slim_int in_beg, slim_int in_num,
                      slim_char *in_sort_crt);
#endif /* defined (DLNA_SUPPORT_X_BROWSE) */

slim_int
dlna_object_browse_metadata (dlna_client_t *top, dlna_object_t *in_device, slim_char *in_id, slim_char *in_filter,
                                       TDLNAObjectEventHandler in_obj_eh, void *in_arg, dlna_object_t **out_obj);

slim_int
dlna_browse_result (dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_search_result (dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_object_search (struct dlna_object *obj, TDLNAObjectEventHandler in_obj_eh,
                   void *in_arg, slim_int in_beg, slim_int in_num,
                   slim_char *in_criteria, slim_char *in_filter, slim_char *in_sort_crt);

void
dlna_object_request_cancel (dlna_client_t *top, dlna_object_t *obj);

#ifdef DEVELOPMENT_DIRECT_DLNA_OBJECT
dlna_object_t *
dlna_create_object_with_metadata(dlna_client_t *in_dlna_client, slim_char *in_uri, slim_char *in_mimeType,
                                 slim_char *in_title, slim_char *in_itemInfo);

dlna_object_t *
dlna_create_object_for_local_push(dlna_client_t *dlna_client, slim_char *file_path, slim_char *title, slim_opaque *out_album_art);
#endif /* DEVELOPMENT_DIRECT_DLNA_OBJECT */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_ITEM_MGR_H */
