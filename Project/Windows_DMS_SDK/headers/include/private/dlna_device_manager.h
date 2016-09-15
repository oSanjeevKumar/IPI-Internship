/*
 * dlna_device_manager.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_DEVICE_MGR_H
#define NFLC_DLNA_DEVICE_MGR_H

#define UPLOAD_FLAG_NONE            (0)
#define UPLOAD_FLAG_AUDIO           (1 << 0)
#define UPLOAD_FLAG_IMAGE           (1 << 1)
#define UPLOAD_FLAG_AV              (1 << 2)
#define UPLOAD_FLAG_CHILD_CONTAINER (1 << 3)

#define UPLOAD_FLAG_DOCUMENT        (1 << 4)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
dlna_object_type_check (struct dlna_object *self, slim_char *type);

slim_bool
dlna_object_sub_type_check (struct dlna_object *self, slim_char *type);

struct dlna_object *
dlna_device_lookup_by_udn_with_type (struct dlna_client_tag *top, TDLNADeviceType type, slim_char *udn);

struct dlna_object *
dlna_device_lookup_by_udn (struct dlna_client_tag *top, slim_char *udn);

slim_char *
dlna_device_udn_lookup (struct dlna_object * self);

TDLNADeviceType
dlna_object_device_type (sXML *doc);

slim_int
dlna_device_get_by_doc (struct dlna_client_tag *top, TDLNADeviceType device_type, sXML *doc, void **out_obj);

slim_int
dlna_device_browse_callback (struct dlna_object *obj,
                            struct upnp_param_action *param);

slim_int
dlna_device_count (struct dlna_client_tag *top);

slim_int
dlna_device_available_count (struct dlna_client_tag *top);

slim_int
dlna_device_update (struct dlna_client_tag *top, struct upnp_param_device *param);

slim_int
dlna_device_byebye (struct dlna_client_tag *top, struct upnp_param_device *param);

slim_int
dlna_device_request_without_parameter (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh,
                                      void *in_arg, slim_char *action);

/* DLNA get search capabilities result.  */
slim_int
dlna_get_search_capabilities_result (dlna_client_t *top, struct upnp_param_action *param);

/* DLNA get sort capabiltities result.  */
slim_int
dlna_get_sort_capabilities_result (dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_get_pinfo_result (dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_get_system_update_id_result (dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_device_list_presets_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_select_preset_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_setvolume_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_getvolume_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_setvolume_db_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_getvolume_db_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_getvolume_db_range_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_setmute_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_getmute_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_get_service_description_result (dlna_client_t *top, struct upnp_param_action *in_param);

#ifdef DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2
slim_int
dlna_device_ping(dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_device_get_ping_result(dlna_client_t *top, struct upnp_param_action *param);

slim_int 
dlna_device_nslookup(dlna_client_t *top, struct upnp_param_action *param);

slim_int 
dlna_device_get_nslookup_result(dlna_client_t *top, struct upnp_param_action *param);

slim_int
dlna_device_traceroute_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_get_traceroute_result_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_get_test_ids_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_get_active_test_ids_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_get_test_info_result (dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_get_device_status(dlna_client_t *top, struct upnp_param_action *in_param);
/*@}*/

#endif /* DEVELOPMENT_ENABLE_BASIC_MANAGEMENT_2 */


#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1
slim_int
dlna_device_get_interface_info(dlna_client_t *top, struct upnp_param_action *in_param);
#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
slim_int
dlna_device_service_subscription(dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_service_renewal(dlna_client_t *top, struct upnp_param_action *in_param);

slim_int
dlna_device_service_release(dlna_client_t *top, struct upnp_param_action *in_param);
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_1 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_DEVICE_MGR_H */
