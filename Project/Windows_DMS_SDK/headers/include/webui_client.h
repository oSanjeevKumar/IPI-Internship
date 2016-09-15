/*
 * webui_client.h
 * Copyright (C) 2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef __WEBUI_CLIENT_H__
#define __WEBUI_CLIENT_H__

#include <webui_interface_client.h>
#include <parental_guidance.h>
#include <webui_defines.h>

slim_int
webui_client_get_server_state(slim_int *out_server_state);

slim_int
webui_client_set_server_state(slim_int in_server_state);

slim_int
webui_client_cds_browse(browse_request_info_t *browse_request, slim_char **out_result, slim_int in_max_str_size);

slim_int
webui_client_cds_search(search_request_info_t *search_request, slim_char **out_result, slim_int in_max_str_size);

slim_int
webui_client_get_friendly_name(slim_char *out_friendly_name,
                                    slim_int in_max_str_size);

slim_int
webui_client_set_friendly_name(slim_char *in_friendly_name);

slim_int
webui_client_get_storages(slim_char *out_path, slim_int in_max_str_size);

slim_int
webui_client_get_manufacturer(slim_char *manufacturer, 
                                  slim_int in_max_str_size);

slim_int
webui_client_get_model_name(slim_char *model_name, 
                                  slim_int in_max_str_size);

slim_int
webui_client_get_model_number(slim_char *model_number, 
                                      slim_int in_max_str_size);

slim_int
webui_client_get_model_url(slim_char *model_url, slim_int in_max_str_size);

slim_int
webui_client_get_images_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
webui_client_get_audios_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
webui_client_get_videos_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
webui_client_get_documents_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
webui_client_get_playlists_shared(slim_char *out_result, slim_int in_max_str_size);

slim_int
webui_client_get_index_mode(slim_int *out_index_mode);

slim_int
webui_client_set_index_mode(slim_int in_index_mode);

slim_int
webui_client_refresh_content_index(void);

slim_int
webui_client_stop_refresh_content_index(void);

slim_int
webui_client_set_content_share(dlna_dms_content_obj_t *in_content_obj);

slim_int
webui_client_get_refresh_state(void);

slim_int
webui_client_get_streaming_sessions_limit (slim_int *out_val);

slim_int
webui_client_set_streaming_sessions_limit (slim_int in_val);

#ifdef DEVELOPMENT_CONTENT_AGGREGATION

slim_int
webui_client_is_ca_enabled(slim_int *out_ca_enabled);

slim_int
webui_client_set_ca_enabled(slim_int in_ca_enable);

slim_int
webui_client_get_ca_db_mode(slim_int *out_val);

slim_int
webui_client_set_ca_db_mode(slim_int in_val);

slim_int
webui_client_get_ca_db_path(slim_char *out_path, slim_int in_max_str_size);

slim_int
webui_client_set_ca_db_path(slim_char *in_path);

slim_int
webui_client_get_ca_index_mode(slim_int *out_val);

slim_int
webui_client_set_ca_index_mode(slim_int in_val);

slim_int
webui_client_get_ca_device_list (ca_device_obj_t ** out_list);

slim_int
webui_client_set_ca_device_index_mode(slim_char *in_uuid, slim_int in_val);

slim_int
webui_client_get_ca_db_size_limit(slim_int *out_val);

slim_int
webui_client_set_ca_db_size_limit(slim_int in_val);

slim_int
webui_client_get_ca_purge_time(slim_int *out_val);

slim_int
webui_client_set_ca_purge_time(slim_int in_val);

slim_int
webui_client_get_ca_rescan_interval(slim_int *out_val);

slim_int
webui_client_set_ca_rescan_interval(slim_int in_val);

#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

#ifdef ENABLE_PARENTAL_GUIDANCE

slim_int
webui_client_get_default_client_level(slim_int *out_default_pc_client_val);

slim_int
webui_client_set_default_client_level(slim_int in_device_pg_level);

slim_int
webui_client_get_default_content_level(slim_int *out_content_pg_level);

slim_int
webui_client_set_default_content_level(slim_int in_content_pg_level);

slim_int
webui_client_set_content_pc_level(dlna_contents_pg_obj_t* in_request);

#endif

slim_int
webui_client_set_content_share_per_page(slim_int in_share_pp_val);

slim_int
webui_client_get_content_share_per_page(slim_int *out_share_pp_val);

#ifdef DMS_HTTP_SRV_AUTH

slim_int
webui_client_set_webui_admin_passwd(
                                          slim_char *out_WebUI_Admin_Passwd_Old, 
                                          slim_char *out_WebUI_Admin_Passwd_New);

slim_int
webui_client_get_auth_pwd(slim_char *in_Passwd);

#endif /* DMS_HTTP_SRV_AUTH */

slim_int
webui_client_get_content_list_max_value(slim_int *out_list_max_val);

slim_int
webui_client_get_content_tree(dlna_contents_tree_request_t* in_request, 
                                  dlna_contents_tree_response_t* out_result);

slim_bool
webui_client_get_content_child_count(slim_char *in_obj_id, slim_int *out_num);

slim_int
webui_client_get_content_idx_state(slim_int *out_idx_type, slim_int *out_idx_state);

#ifdef DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME
slim_int
webui_client_get_device_last_idx_time(slim_char *device_id, slim_char *out_last_idx_time);
slim_int
webui_client_get_device_time_or_state(slim_char *device_id, slim_char *out_time_state);
#endif /* DEVELOPMENT_DMS_STORAGE_LAST_INDEX_TIME */

slim_int
webui_client_get_selected_language( slim_char *out_write_buf, slim_int buf_size );
slim_int
webui_client_get_languages( slim_char *out_write_buf, slim_int buf_size );
slim_int
webui_client_set_language( const slim_char *language );

#ifdef DMS_CSYNC_APPS

slim_int
webui_client_get_dmslist(dlna_csync_dmslist_request_t** list, 
                            slim_int *list_num);

#endif /* DMS_CSYNC_APPS */

#ifdef ENABLE_PARENTAL_GUIDANCE

slim_bool
webui_client_getFirstParentalGuidanceLevel(
                              parental_guidance_level_info_t *out_first_level);

slim_bool
webui_client_getNextParentalGuidanceLevel(
                                  parental_guidance_level_info_t *in_prev_level, 
                                  parental_guidance_level_info_t *out_next_level);

slim_bool
webui_client_getFirstParentalGuidanceConnectedDevice(
                                   parental_control_device_t* out_first_device);

slim_bool
webui_client_getNextParentalGuidanceConnectedDevice(
                                const parental_control_device_t* in_prev_device, 
                                parental_control_device_t* out_next_device);

slim_bool
webui_client_setDevicePC(const parental_control_device_t * in_device);

#endif /* ENABLE_PARENTAL_GUIDANCE */

slim_bool
webui_client_add_publish_storage(slim_char *in_path);

slim_bool
webui_client_remove_publish_storage(slim_char *in_path);

#endif /* __WEBUI_CLIENT_H__ */

