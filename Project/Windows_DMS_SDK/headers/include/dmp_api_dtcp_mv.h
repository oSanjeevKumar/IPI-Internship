/*
 * dmp_api_dtcp_mv.h
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* DMP API for DTCP Move code.  */

#ifndef NFLC_DMP_API_DTCP_MV_H
#define NFLC_DMP_API_DTCP_MV_H

/**
 * @addtogroup datatypes
 */
/*@{*/

typedef void * TDMPUpDTCPMv;

/*@}*/

/**
 * @addtogroup enums
 */
/*@{*/

typedef enum{
  DMP_UP_DTCP_MV_EV_CREATED_OBJECT = 0,
  DMP_UP_DTCP_MV_EV_MOVE_BEGIN,
  DMP_UP_DTCP_MV_EV_LOCAL_CONTENT_DELETED,
  DMP_UP_DTCP_MV_EV_MOVE_END,
  DMP_UP_DTCP_MV_EV_PROGRESS,
  DMP_UP_DTCP_MV_EV_CANCELLED,
  DMP_UP_DTCP_MV_EV_ERROR,
} TDMPUpDTCPMvEvent;

/*@}*/

/**
 * @addtogroup macros
 */
/*@{*/

#define TDMPUpDTCPMvEventHandlerParam TDLNAUpDTCPMvEventHandleParam

/*@}*/

/**
 * @addtogroup structures
 */
/*@{*/

struct _TDLNAUpDTCPMvEventHandleParam
{
  slim_int err_code;
  slim_int percent; 
  dlna_uint64 current_bytes;
  dlna_uint64 total_bytes;
  slim_char *current_bytes_str;
  slim_char *total_bytes_str;
};
typedef struct _TDLNAUpDTCPMvEventHandleParam TDLNAUpDTCPMvEventHandleParam;

/*@}*/

/**
 * @addtogroup apis
 */
/*@{*/

typedef slim_int (*TDMPUploadDTCPMvEventHandler)(TDMPUpDTCPMv self, TDMPUpDTCPMvEvent in_event, void *in_arg, TDLNAUpDTCPMvEventHandleParam *in_param);

/*@}*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup apis
 */
/*@{*/

/*!
\brief
T.B.D.
*/
slim_int 
dlnaDmpUploadDtcpMvInitialize (TDMP self, TDTCP *in_dtcp, TDTCPDevice in_dtcp_src_mv_device);

/*!
\brief
T.B.D.
*/
void 
dlnaDmpUploadDtcpMvFinalize (TDMP self);

/*!
\brief
T.B.D.
*/
slim_int
dlnaDmpUploadDtcpMvOpen (TDMP self, slim_char *in_full_path, TDMPObject in_device, TDMPObject in_container,
                              TDMPUploadDTCPMvEventHandler in_eh, void *in_arg, TDMPUpDTCPMv *out_up_dtcp_mv);

/*!
\brief
T.B.D.
*/
void 
dlnaDmpUploadDtcpMvClose (TDMPUpDTCPMv self);

/*!
\brief
T.B.D.
*/
slim_int 
dlnaDmpUploadDtcpMvUploadFile (TDMPUpDTCPMv self);

/*!
\brief
T.B.D.
*/
slim_int 
dlnaDmpUploadDtcpMvCancel (TDMPUpDTCPMv self);

/*@}*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_DMP_API_DTCP_MV_H */
