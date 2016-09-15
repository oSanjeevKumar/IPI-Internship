/*
 * dmp_core.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DMP_CORE_H
#define NFLC_DMP_CORE_H

#include <dmp_api.h>
#ifdef DLNA_SUPPORT_RUIPL
#include <ruipl_core.h>
#endif /* DLNA_SUPPORT_RUIPL */

/* Struct for single global variable for the DMP client.  */
struct dmp
{
  /* UPnP client back pointer.  */
  struct upnp_client *uc;

  struct dlna_client_tag dlna_client;

  TDLNAEventHandler callback;
  void *arg;
#ifdef DLNA_SUPPORT_RUIPL
  ruipl_t *ruipl;
#endif /* DLNA_SUPPORT_RUIPL */

#ifdef DEVELOPMENT_DLNA_SUPPORT_DMPR
  struct upnp_server *us; 
#endif /*DEVELOPMENT_DLNA_SUPPORT_DMPR*/
#ifdef HAVE_DTCP
  TDTCP *dtcp;
#if defined(DLNA_SUPPORT_UPLOADER_DTCP_MV)
  TDTCPDevice up_dtcp_src_device;
#endif /*DLNA_SUPPORT_UPLOADER*/
#endif /*HAVE_DTCP*/

};

typedef struct dmp dmp_t;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

dmp_t *
dmp_alloc(dlna_progress in_p, dlna_player_display_param *p, slim_char *in_work_path, slim_char *in_config_path);

slim_int
dmp_free(dmp_t *top);

slim_int
dmp_start (dmp_t *top, TDMPEventHandler in_dmp_eh, void *in_arg);

slim_int
dmp_stop(dmp_t *top);

dlna_progress
dmp_get_progress(dmp_t *top);

dlna_player
dmp_get_player(dmp_t *top);

TDLNAObjectDRMType
dmp_object_get_drm_type(dlna_object_t *obj);

TDLNAObjectDRMType
dmp_object_get_drm_type_nth(dlna_object_t *obj, slim_int in_res_index);

TDLNAObjectOPType
dmp_object_get_op_type_nth(dlna_object_t *obj, slim_int in_res_index);

slim_int
dmp_object_get_res_prop_nth(dlna_object_t *obj, slim_int in_res_index, slim_char *in_name, slim_char **out_value_str, slim_int *out_value_len);

slim_int
dmp_object_get_pi_thum(dlna_object_t *obj, slim_int *out_value_len);

TDLNAObjectTransferMode
dmp_object_get_transfer_mode(dlna_object_t *obj, slim_int in_res_index);

slim_int
dmp_object_get_default_res_index(dlna_object_t *in_obj);

slim_int
dmp_set_friendly_name(dmp_t *dmp, slim_char *in_friendly_name);

slim_char *
dmp_get_friendly_name(dmp_t *dmp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMP_CORE_H */
