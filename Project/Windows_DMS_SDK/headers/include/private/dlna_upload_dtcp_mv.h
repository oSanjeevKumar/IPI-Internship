/*
 * dlna_upload_dtcp_mv.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_DLNA_UPLOAD_DTCP_MV_H
#define NFLC_DLNA_UPLOAD_DTCP_MV_H

#include <dlna_up_api.h>
#include <nflc_upnp.h>

#define UP_DLNA_MANAGED_UPLOAD_CONTENT          (0x000001)
#define UP_DLNA_MANAGED_CREATE_CHILD_CONTAINER  (0x000002)
#define UP_DLNA_MANAGED_DESTROY_ITEM            (0x000004)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DLNA_SUPPORT_UPLOADER_DTCP_MV

enum TDLNAUploadDTCPMoveEvent_ { 
  DLNA_UP_DTCP_MV_EV_CREATED_OBJECT = 0,
  DLNA_UP_DTCP_MV_EV_MOVE_BEGIN,	
  DLNA_UP_DTCP_MV_EV_LOCAL_CONTENT_DELETED,
  DLNA_UP_DTCP_MV_EV_MOVE_END,	
  DLNA_UP_DTCP_MV_EV_PROGRESS,	
  DLNA_UP_DTCP_MV_EV_CANCELLED,	
  DLNA_UP_DTCP_MV_EV_ERROR
};
typedef enum TDLNAUploadDTCPMoveEvent_ TDLNAUploadDTCPMoveEvent;

typedef void *TDLNAUploadDTCPMoveObject;

struct TDLNAUploadDTCPMoveEventParam_ {
  dlna_uint64 current_byte;
  dlna_uint64 total_byte;
};
typedef struct TDLNAUploadDTCPMoveEventParam_ TDLNAUploadDTCPMoveEventParam;


typedef slim_int (*TDLNAUploadDTCPMoveObjectEventHandler)(TDLNAUploadDTCPMoveObject self, TDLNAUploadDTCPMoveEvent in_event, TDLNAUploadDTCPMoveEventParam *in_param, void *in_arg);

TDLNAUploadDTCPMoveObject
dlna_upload_dtcp_move_open (dlna_client_t *in_dc, TDTCP *in_dtcp, TDTCPDevice in_dtcp_device);


slim_int
dlna_upload_dtcp_move_upload_file(TDLNAUploadDTCPMoveObject *self , slim_char *in_full_path, dlna_object_t *in_device,
							dlna_object_t *in_parent_container, slim_int in_notify_kbsize, 
							TDLNAUploadDTCPMoveObjectEventHandler in_obj_eh, void *in_arg);


void
dlna_upload_dtcp_move_close (TDLNAUploadDTCPMoveObject self);

slim_int
dlna_upload_dtcp_move_cancel (TDLNAUploadDTCPMoveObject self);

#endif /* DLNA_SUPPORT_UPLOADER */

 
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* NFLC_DLNA_UPLOAD_DTCP_MV_H */
