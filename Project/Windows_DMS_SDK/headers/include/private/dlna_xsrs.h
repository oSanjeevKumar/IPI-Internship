/*
 * dlna_xsrs.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_XSRS_H
#define NFLC_DLNA_XSRS_H

#include <nflc_xsrs.h>
#include <dlna_client.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DLNA_SUPPORT_SRS

slim_int
dlna_object_get_xsrs_version (dlna_object_t *obj, slim_int *out_xsrs_var);

/*
  X_CreateRecordSchedule action
*/
slim_int
dlna_object_create_record_schedule (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_create_rec_param_t *in_param);

void
dlna_object_create_schedule_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_GetConflictList action
*/
slim_int
dlna_object_get_conflict_list (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_get_cnflist_param_t *in_param);

void
dlna_object_get_conflict_list_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_DeleteRecordSchedule action
*/
slim_int
dlna_object_delete_schedule (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_del_rec_param_t *in_param);

void
dlna_object_delete_schedule_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_GetRecordScheduleList action
*/
slim_int
dlna_object_get_record_schedule_list (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_get_reclist_param_t *in_param);

void
dlna_object_get_record_schedule_list_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_UpdateRecordSchedule action
*/
slim_int
dlna_object_update_record_schedule (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_update_rec_param_t *in_param);

void
dlna_object_update_record_schedule_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_GetTitleList action
*/
slim_int
dlna_object_get_title_list (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_get_tlist_param_t *in_param);

void
dlna_object_get_title_list_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_DeleteTitle action
*/
slim_int
dlna_object_delete_title (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_del_title_param_t *in_param);

void
dlna_object_delete_title_result (dlna_client_t *top, struct upnp_param_action *param);

/*
  X_UpdateTitle action
*/
slim_int
dlna_object_update_title (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_update_title_param_t *in_param);

void
dlna_object_update_title_result (dlna_client_t *top, struct upnp_param_action *param);

#if 0
slim_int
dlna_object_get_schedule (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, void *in_arg, xsrs_get_param_t *in_param);
#endif

#endif /* DLNA_SUPPORT_SRS */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* NFLC_DLNA_XSRS_H */
