/*
 * upnp_mscp.h
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

/* UPnP Media Server Control Point.  */

#ifndef NFLC_UPNP_MSCP_H
#define NFLC_UPNP_MSCP_H

enum {
  UPNP_MSCP_LOCAL_ACTION_GETSORTCAPABILITIES,
  UPNP_MSCP_LOCAL_ACTION_GETSEARCHCAPABILITIES,
  UPNP_MSCP_LOCAL_ACTION_GETSYSTEMUPDATEID,
  UPNP_MSCP_LOCAL_ACTION_BROWSE,
  UPNP_MSCP_LOCAL_ACTION_SEARCH,
  UPNP_MSCP_LOCAL_ACTION_CREATE_OBJECT,
  UPNP_MSCP_LOCAL_ACTION_DESTROY_OBJECT,
  UPNP_MSCP_LOCAL_ACTION_UPDATE_OBJECT,
  UPNP_MSCP_LOCAL_ACTION_ACTION_MAX
};

typedef enum {
  UPNP_MSCP_BROWSE_FLAG_DIRECT_CHILDREN,
  UPNP_MSCP_BROWSE_FLAG_METADATA,
}upnp_mscp_brose_flag_t;

/* UPnP Media Server Control Point.  */
struct upnp_mscp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int 
upnp_mscp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_mscp_free (struct upnp_cp *cp);

slim_int
upnp_mscp_browse (struct upnp_client *uc, struct upnp_device *in_device, slim_char *in_id,
                            slim_int in_browse_flag, slim_char *in_filter,slim_int in_start, slim_int in_count,
                            slim_char *in_sort_crt, void *session_data);

#if defined (DLNA_SUPPORT_X_BROWSE)
slim_int
upnp_mscp_x_browse_container (struct upnp_client *uc, sXML *item,
                              slim_int in_start, slim_int in_count,
                              slim_char *in_sort_crt, void *session_data);
#endif /* defined (DLNA_SUPPORT_X_BROWSE) */

slim_int
upnp_mscp_search_contents (struct upnp_client *uc, struct upnp_device *device,
                           slim_char *in_id, slim_int in_start, slim_int in_count,
                           slim_char *in_criteria, slim_char *in_filter, 
                           slim_char *in_sort_crt, void *in_session_data);

slim_int
upnp_mscp_request_without_parameter (struct upnp_client *uc, struct upnp_device *device, 
                                     slim_char *action, void *in_session_data);
slim_int
upnp_mscp_request_service_without_parameter (struct upnp_client *uc, struct upnp_device *device, slim_char *in_service_type,
                                     slim_char *action, void *in_session_data);

#ifdef DLNA_SUPPORT_UPLOADER
/* Create Object.  */
slim_int
upnp_mscp_create_object (struct upnp_client *uc, struct upnp_device *device, void *session_data,
                        void *in_up_param, slim_char *parent_id, slim_int create_type);

/* Destroy Object */
slim_int
upnp_mscp_destroy_object (struct upnp_client *uc, struct upnp_device *device, void *session_data, slim_char *in_objectid);

/* Get Upload Profiles */
slim_int
upnp_mscp_get_upload_profiles (struct upnp_device *device, void *session_data, slim_char *in_profiles);

/* Update Object */
slim_int
upnp_mscp_update_object (struct upnp_client *uc, struct upnp_device *device, slim_char *object_id, 
                         upnp_update_param_t *upnp_current_param, upnp_update_param_t *upnp_new_param,
                         void *session_data);

#endif /* DLNA_SUPPORT_UPLOADER */


#ifdef DLNA_SUPPORT_SRS
/*
  X_CreateRecordSchedule action
*/
slim_int
upnp_mscp_xsrs_create_record_schedule (struct upnp_device *device, xsrs_create_rec_param_t *in_param, void * session_data);

/*
  X_GetConflictList action
*/
slim_int
upnp_mscp_xsrs_get_conflict_list (struct upnp_device *device, xsrs_get_cnflist_param_t *in_param, void *session_data);

/*
  X_DeleteRecordSchedule action
*/
slim_int
upnp_mscp_xsrs_delete_schedule (struct upnp_device *device, xsrs_del_rec_param_t *in_param, void * session_data);

/*
  X_GetRecordScheduleList action
*/
slim_int
upnp_mscp_xsrs_get_record_schedule_list (struct upnp_device *device, xsrs_get_reclist_param_t *in_param, void *session_data);

/*
  X_UpdateRecordSchedule action
*/
slim_int
upnp_mscp_xsrs_update_record_schedule (struct upnp_device *device, xsrs_update_rec_param_t *in_param, void *session_data);

#if 0
slim_int
upnp_mscp_xsrs_get_schedule (struct upnp_device *device, xsrs_get_reclist_param_t *in_param,  void *session_data);
#endif

/*
  X_GetTitleList action
*/
slim_int
upnp_mscp_xsrs_get_title_list (struct upnp_device *device, xsrs_get_tlist_param_t *in_param, void *session_data);

/*
  X_DeleteTitle action
*/
slim_int
upnp_mscp_xsrs_delete_title (struct upnp_device *device, xsrs_del_title_param_t *in_param, void *session_data);

/*
  X_UpdateTitle action
*/
slim_int
upnp_mscp_xsrs_update_title (struct upnp_device *device, xsrs_update_title_param_t *in_param, void *session_data);

#endif /* DNLA_SUPPORT_SRS */

#ifdef DLNA_SUPPORT_HDRL
slim_int
upnp_mscp_get_record_destinations (struct upnp_device *device, void *session_param);

slim_int
upnp_mscp_get_record_destinationInfo (struct upnp_device *device, void *session_param, slim_char *des_id);

slim_int
upnp_mscp_get_record_containerID (struct upnp_device *device, void *session_param, slim_char *des_id, upnp_upload_param_t *in_param);

#endif /* DLNA_SUPPORT_HDRL */


#if defined (RA_USE_RID_HEADER) 
slim_int
upnp_mscp_propagate_permission (struct upnp_device *device, void *session_param, slim_char *in_rid, slim_word in_permission) ;
slim_int
upnp_mscp_revoke_permission (struct upnp_device *device, void *session_param, slim_char *in_rid) ;
#endif /* #if defined (RA_USE_RID_HEADER) */

#ifdef DLNA_SUPPORT_PROVISIONING 
slim_int
upnp_mscp_propagate_properties (struct upnp_device *device, void *session_param, slim_char *in_properties) ;
#endif /* #ifdef DLNA_SUPPORT_PROVISIONING */



#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_UPNP_MSCP_H */
