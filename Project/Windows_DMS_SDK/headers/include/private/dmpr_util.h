/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */
/* Copyright (C) 2011 Access Co. Ltd. All Rights Reserved.  */

#ifndef _DMPR_UTIL_H
#define _DMPR_UTIL_H

#define DMPR_PRN_STATE_TAG              SLIM_T("PrinterState")
#define DMPR_PRN_STATE_REASONS_TAG      SLIM_T("PrinterStateReasons")
#define DMPR_JOB_ID_LIST_TAG            SLIM_T("JobIdList")
#define DMPR_JOB_ID_TAG                 SLIM_T("JobId")
#define DMPR_JOB_NAME_TAG               SLIM_T("JobName")
#define DMPR_JOB_ABORT_STATE_TAG        SLIM_T("JobAbortState")
#define DMPR_JOB_END_STATE_TAG          SLIM_T("JobEndState")
#define DMPR_AARG_MEDIA_LIST_TAG        SLIM_T("A_ARG_TYPE_MediaList")
#define DMPR_AARG_PRIN_ABORT_REASON_TAG SLIM_T("A_ARG_TYPE_PrinterAbortReason")
#define DMPR_AARG_PRIN_ATTR_LIST_TAG    SLIM_T("A_ARG_TYPE_CriticalAttributeList")
#define DMPR_MEDIA_TYPE_TAG             SLIM_T("MediaType")
#define DMPR_MEDIA_SIZE_TAG             SLIM_T("MediaSize")
#define DMPR_CRIT_ATTR_LIST_TAG         SLIM_T("CriticalAttributesList")
#define DMPR_PRINT_QUALITY_TAG          SLIM_T("PrintQuality")
#define DMPR_ORIENTATION_REQ_TAG        SLIM_T("OrientationRequested")
#define DMPR_JOB_ORIG_USER_NAME_TAG     SLIM_T("JobOriginatingUserName")
#define DMPR_DOCUMENT_FORMAT_TAG        SLIM_T("DocumentFormat")
#define DMPR_NUMBER_UP_TAG              SLIM_T("NumberUp")
#define DMPR_SIDES_TAG                  SLIM_T("Sides")
#define DMPR_COPIES_TAG                 SLIM_T("Copies")
#define DMPR_JOB_MEDIA_SHEETS_COMPL_TAG SLIM_T("JobMediaSheetsCompleted")
#define DMPR_CONTENT_COMPLETE_LIST_TAG  SLIM_T("ContentCompleteList")
#define DMPR_PAGE_MARGINS_SIZE          SLIM_T("PageMargins")
#define DMPR_SOURCE_URI_TAG             SLIM_T("SourceURI")
#define DMPR_DATA_SINK_TAG              SLIM_T("DataSink")

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
dmpr_map_printer_state_to_text(TDMPrPrinterState *in_state,
    struct sbuf *out_state, struct sbuf *out_reason);

slim_int
dmpr_map_job_state_to_text(TDMPrPrinterState *in_state,
    struct sbuf *out_state, struct sbuf *out_reason);

slim_int
dmpr_map_action_errorcode(slim_int in_code);

slim_int
dmpr_get_arguments_count(sXML * doc, slim_char *action_tag);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_UTIL_H */
