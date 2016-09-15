/*
 * webui_interface_server.h
 * Copyright (C) 2011-2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef __WEBUI_INTERFACE_SERVER_H__
#define __WEBUI_INTERFACE_SERVER_H__

#include <webui_interface.h>
#include <dlna_peer.h>
#include <parental_guidance.h>

#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#include <dms_publish_api.h>
#endif

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
#include <dms_api.h>
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

slim_int
webui_server(void *argc);

slim_int
webui_server_set_rebuild_state(slim_int rebuild_state);

slim_int
dms_get_server_state(slim_int *out_server_state);

slim_int
dms_set_server_state(slim_int in_server_state);

slim_int
dms_set_friendly_name(slim_char *in_friendly_name);

slim_int
dms_get_friendly_name(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_storages(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_images_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_audios_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_videos_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_documents_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_playlists_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_manufacturer(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_model_name(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_model_number(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_model_url(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_get_index_mode( slim_int *out_result);

slim_int
dms_set_index_mode(slim_int in_mode);

slim_int
dms_refresh_content_index(void);

slim_int
dms_stop_refresh_content_index(void);

slim_int
dms_get_content_tree(dlna_contents_tree_request_t *in_content_tree_obj,
                           dlna_contents_tree_response_t *out_content_tree_obj);

slim_int
dms_set_content_share(dlna_dms_content_obj_t *in_content_obj);

slim_int
dms_set_content_share_per_page(slim_int in_share_pp_val);

slim_int
dms_get_content_share_per_page(slim_int *out_share_pp_val);

slim_bool
dms_get_content_child_count(slim_char *in_obj_id, slim_int *out_num);

slim_int
dms_get_content_idx_state(slim_int *out_idx_type, slim_int *out_idx_state);

#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
slim_int
dms_get_device_last_idx_time(const slim_char *device_id, slim_char *out_last_idx_time);
slim_int
dms_get_device_time_or_state(const slim_char *device_id, slim_char *out_time_state);
#endif /* DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME */

int dms_get_selected_language( slim_char *out_write_buf, slim_int buf_size );
int dms_get_languages( slim_char *out_write_buf, slim_int buf_size );
int dms_set_language( const slim_char *language );

slim_int
dms_set_streaming_sessions_limit(slim_int in_session_count);

slim_int
dms_get_streaming_sessions_limit(slim_int *out_session_count);

#ifdef DMS_HTTP_SRV_AUTH

slim_int
dms_set_webui_admin_passwd(slim_char *in_WebUI_Admin_Passwd_Old, 
                                   slim_char *in_WebUI_Admin_Passwd_New);

slim_int
dms_get_auth_pwd(slim_char *in_passwd_str);

#endif // DMS_HTTP_SRV_AUTH

slim_int
dms_get_content_list_max_value(slim_int *out_list_max_val);

#ifdef ENABLE_PARENTAL_GUIDANCE

slim_int
dms_set_content_pc_level(dlna_contents_pg_obj_t *in_content_obj);

slim_int
dms_get_default_client_level(slim_int *out_pc_client_level);

slim_int
dms_set_default_client_level(slim_int in_default_pc_client_level_val);

slim_int
dms_get_default_content_level(slim_int *out_content_pg_level);

slim_int
dms_set_default_content_level(slim_int in_content_pg_level);

slim_bool
dms_get_first_pg_level(parental_guidance_level_info_t * out_first_level);

slim_bool
dms_get_next_pg_level(parental_guidance_level_info_t * in_prev_level, 
                          parental_guidance_level_info_t * out_next_level);

slim_bool
dms_get_first_pg_cd(parental_control_device_t *out_first_device);

slim_bool
dms_get_next_pg_cd(const parental_control_device_t* in_prev_device, 
                      parental_control_device_t *out_next_device);

slim_int
dms_get_pg_level_count(void);

slim_bool
dms_set_dev_pc(const parental_control_device_t* in_pc_device);

#endif /*ENABLE_PARENTAL_GUIDANCE*/

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
slim_int
dms_set_ca_enabled(slim_int in_ca_enabled);

slim_int
dms_get_ca_enabled(slim_int *out_ca_enabled);

slim_int
dms_set_ca_db_selection_mode(slim_int in_mode);

slim_int
dms_get_ca_db_selection_mode(slim_int *out_mode);

slim_int
dms_get_ca_db_path(slim_char *out_result, slim_int in_max_str_size);

slim_int
dms_set_ca_db_path(slim_char *in_path);

slim_int
dms_set_ca_index_mode(slim_int in_index);

slim_int
dms_get_ca_index_mode(slim_int *out_index);

slim_int
dms_get_ca_device_list (TDMSCADeviceObject **out_list);

slim_int
dms_set_ca_device_index_mode(slim_char *in_uuid, slim_int in_index);

slim_int
dms_set_ca_db_size_limit(slim_int in_size);

slim_int
dms_get_ca_db_size_limit(slim_int *out_size);

slim_int
dms_set_ca_purge_time(slim_int in_time);

slim_int
dms_get_ca_purge_time(slim_int *out_time);

slim_int
dms_set_ca_rescan_interval(slim_int in_interval);

slim_int
dms_get_ca_rescan_interval(slim_int *out_interval);
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

slim_int
dms_browse_content(sXML *in_request_doc, sXML **out_response_doc);

slim_int
dms_search_content(sXML *in_request_doc, sXML **out_response_doc);

slim_bool
dms_set_publish_storage_add(slim_char *in_path);

slim_bool
dms_set_publish_storage_remove(slim_char *in_path);

#endif /* __WEBUI_INTERFACE_SERVER_H__ */

