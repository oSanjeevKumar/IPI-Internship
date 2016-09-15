/*
 * dlna_hdrl.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_HDRL_H
#define NFLC_DLNA_HDRL_H

#include <dlna_up_api.h>
#include <dlna_client.h>


/* error code for CreateObject/DestroyObject, value defined by uPnP */
#define UPNP_E_NO_SUCH_OBJ            (701)
#define UPNP_E_RESTRICTED_OBJ         (711)
#define UPNP_E_RESTRICTED_PARENT_OBJ  (713)
#define UPNP_E_NO_SUCH_RESOURCE       (714)
#define UPNP_E_RESOURCE_ACCESS_DENIED (715)
#define UPNP_E_NO_SUCH_CONTAINER      (710)
#define UPNP_E_BAD_METADATA           (712)

/* HDRL Device class types */
#define HDRL_DEVTYPE_FLAG_NONE (0x00000000) /* not HDRL device. */
#define HDRL_DEVTYPE_FLAG_RCV  (0x00000001) /* HDRL RCV device. */
#define HDRL_DEVTYPE_FLAG_REC  (0x00000002) /* HDRL REC device. */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DLNA_SUPPORT_HDRL

slim_bool
dlna_upload_hdrl_capable (dlna_object_t *device);

slim_int
dlna_upload_hdrl_device_type (dlna_object_t *device, slim_int *out_dev_type);

/* Get the new object for .  */
slim_int
dlna_object_get_record_destinations (dlna_object_t *obj, TDLNAObjectEventHandler in_obj_eh, 
                                     void *in_arg);

slim_int
dlna_object_get_record_destinationInfo (dlna_object_t *obj, slim_char *des_id,
                                        TDLNAObjectEventHandler in_obj_eh, void *in_arg);

slim_int
dlna_object_get_record_containerID (dlna_object_t *obj, slim_char *des_id, 
                                    TDLNAObjectEventHandler in_obj_eh, void *in_arg,
                                    up_stream_param_t *in_param);

void
dlna_object_get_record_deslist_result (dlna_client_t *top, struct upnp_param_action *param);

void
dlna_object_get_record_desinfo_result (dlna_client_t *top, struct upnp_param_action *param);

void
dlna_object_get_record_containerID_result (dlna_client_t *top, struct upnp_param_action *param);

#endif /* DLNA_SUPPORT_HDRL */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DLNA_HDRL_H */
