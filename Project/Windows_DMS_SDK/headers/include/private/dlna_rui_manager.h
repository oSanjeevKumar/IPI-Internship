/*
 * dlna_rui_manager.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_RUI_MANAGER_H
#define NFLC_DLNA_RUI_MANAGER_H

#ifdef DLNA_SUPPORT_RUIPL
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <notify_client.h>
	
void
dlna_rui_get_uilist_by_url(struct dlna_client_tag *in_top, void *in_udn, slim_char *in_url);

dlna_object_t *
dlna_rui_create_ibox_device(struct dlna_client_tag *in_top, void *in_udn, slim_char *in_url, slim_char *in_name);

void
dlna_rui_free (dlna_object_t *obj);

slim_int
dlna_rui_get_ui_count (struct dlna_client_tag *in_top, dlna_object_t *in_device);

slim_int
dlna_rui_get_uilist (struct dlna_client_tag *in_top, dlna_object_t *in_device, dlna_object_t **out_ruis,
slim_int in_beg, slim_int in_num);

slim_char*
dlna_rui_get_ui_title (dlna_object_t *in_obj);

slim_char*
dlna_rui_get_ui_description (dlna_object_t *in_obj);

slim_char*
dlna_rui_get_ui_shortname (dlna_object_t *in_obj);

slim_char*
dlna_rui_get_udn (dlna_object_t *in_obj);

slim_int
dlna_rui_get_ui_uri_prolist_count (dlna_object_t *in_obj);

slim_char*
dlna_rui_get_ui_uri (dlna_object_t *in_obj, slim_int in_index);

slim_int
dlna_rui_get_ui_prolist (dlna_object_t *in_obj, slim_char *out_prolist, slim_int in_buf_len, slim_int in_index);

#ifdef DEVELOPMENT_DLNA_SUPPORT_RUIHPL
slim_int
dlna_rui_set_ui_lifetime (struct dlna_client_tag *top, slim_char *in_udn, slim_char *in_url, slim_char *in_lifetime);
#endif /* DEVELOPMENT_DLNA_SUPPORT_RUIHPL */

void
dlna_rui_remove_by_udn (struct dlna_client_tag *top, slim_char *udn);

void
dlna_rui_update (struct dlna_client_tag *in_top, struct upnp_param_rui *in_param);

void
dlna_rui_notify_update (struct dlna_client_tag *in_top, struct upnp_param_notify *in_param);

void
dlna_get_dlna_upload_profiles_result (dlna_client_t *top, struct upnp_param_action *in_action_param) ;

slim_int
dlna_ruis_get_compatible_uis_result (dlna_client_t *top, struct upnp_param_action *param) ;

slim_char*
dlna_rui_get_icon_uri (dlna_object_t *in_obj, slim_int in_index);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DLNA_SUPPORT_RUIPL */
#endif /* NFLC_DLNA_RUI_MANAGER_H */
