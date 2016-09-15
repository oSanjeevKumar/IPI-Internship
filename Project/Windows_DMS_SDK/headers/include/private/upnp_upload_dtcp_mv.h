/*
 * upnp_upload_dtcp_mv.h
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_UPNP_UPLOAD_DTCP_MV_H
#define NFLC_UPNP_UPLOAD_DTCP_MV_H

#if defined (DLNA_SUPPORT_UPLOADER_DTCP_MV) && defined (HAVE_DTCP)

typedef void * TUPnPUploadDTCPMove;

#define UPNP_UP_DTCP_MV_BUFFER_MAX_SIZE DLNA_HTTP_LARGE_BUFFER_SIZE

typedef enum {
  UPNP_UP_DTCP_MV_EV_READY,
  UPNP_UP_DTCP_MV_EV_SEND_DONE,
  UPNP_UP_DTCP_MV_EV_ERROR,
  UPNP_UP_DTCP_MV_EV_TIMEOUT,
  UPNP_UP_DTCP_MV_EV_CANCELLED,
  UPNP_UP_DTCP_MV_EV_CLOSED,
  UPNP_UP_DTCP_MV_EV_RESUME_OK,
  UPNP_UP_DTCP_MV_EV_RESUME_FAILED,
} TUPnPUploadDTCPMoveEvent;

struct TUPnPUploadDTCPMoveEventParam_ {
  slim_byte kxm_label;
};
typedef struct TUPnPUploadDTCPMoveEventParam_ TUPnPUploadDTCPMoveEventParam;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef slim_int (*TUPnPUploadDTCPMoveEventHandler)(TUPnPUploadDTCPMove self, TUPnPUploadDTCPMoveEvent in_event, TUPnPUploadDTCPMoveEventParam *in_param, void *in_arg);

TUPnPUploadDTCPMove
upnp_upload_dtcp_mv_open (struct upnp_client *uc, slim_char *in_uri, slim_char *in_dtcp_content_type,
                                      slim_char *in_content_features, TUPnPUploadDTCPMoveEventHandler in_eh, void *in_arg);

void 
upnp_upload_dtcp_mv_close (TUPnPUploadDTCPMove self);

slim_int 
upnp_upload_dtcp_mv_upload (TUPnPUploadDTCPMove self);

slim_int 
upnp_upload_dtcp_mv_set_data (TUPnPUploadDTCPMove self, slim_byte *in_buf, slim_word in_buf_len, slim_bool in_has_more);

slim_int 
upnp_upload_dtcp_mv_cancel (TUPnPUploadDTCPMove self);

slim_int 
upnp_upload_dtcp_mv_resume (TUPnPUploadDTCPMove self);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*DLNA_SUPPORT_UPLOADER && HAVE_DTCP*/

#endif /* NFLC_UPNP_UPLOAD_DTCP_MV_H */

