/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */
/* Copyright (C) 2011 Access Co. Ltd. All Rights Reserved.  */

#ifndef _DMPR_PRNSRV_CLIENT_H
#define _DMPR_PRNSRV_CLIENT_H

#define DMPR_PRNSRV_TAG_PARAM     SLIM_T("param")
#define DMPR_PRNSRV_TAG_ACTION		SLIM_T("action")
#define DMPR_PRNSRV_TAG_RESULT		SLIM_T("result")
#define DMPR_PRNSRV_TAG_PAPER     SLIM_T("paper")
#define DMPR_PRNSRV_TAG_ERROR     SLIM_T("error")
#define DMPR_PRNSRV_TAG_EVENT     SLIM_T("event")
#define DMPR_PRNSRV_TAG_ACTIONID  SLIM_T("actionID")

#define DMPR_PRNSRV_NONE_ANSWER   SLIM_T("none")
#define DMPR_PRNSRV_DEFAULT_ANSWER   SLIM_T("device-setting")

#define DMPR_PRNSRV_XML_HEADER		SLIM_T("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n")


#define DMPR_PRNSRV_MESSAGE_BYEBYE \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<request>\n" \
"<action name=\"ByeBye\"></action>\n" \
"</request>\n\n"

#define DMPR_PRNSRV_MESSAGE_GETMEDIAS \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<reqest>" \
"<action name=\"GetMedias\">\n" \
"</action>\n"\
"</reqest>\n\n"

#define DMPR_PRNSRV_MESSAGE_PRINTXHTML \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<reqest>\n" \
"<action name=\"PrintXHTML\"></action>\n" \
"</reqest>\n\n"

#define DMPR_PRNSRV_MESSAGE_CANCELPRINT \
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<reqest>" \
"<action name=\"CancelPrint\">\n" \
"</action>\n"\
"</reqest>\n\n"

enum dlna_dmpr_events_num
{
  DMPR_EVT_NUM_PRINT_STARTED = 0,
  DMPR_EVT_NUM_PRINT_COMPLETED = 1,
  DMPR_EVT_NUM_PRINT_CANCELED = 2,
  DMPR_EVT_NUM_PRINT_INIT_OK = 3,
  DMPR_EVT_NUM_PRINT_INIT_FAILED = 4,
  DMPR_EVT_NUM_PRINT_STATUS = 5,
  DMPR_EVT_NUM_PRINT_CONTENT_COMPLETE = 6,
  DMPR_EVT_NUM_PRINT_SHEETS_COMPLETED = 7,

  DMPR_EVT_NUM_PRINT_ADD_JOB = 8,
  DMPR_EVT_NUM_PRINT_UPD_JOB = 9,
  DMPR_EVT_NUM_PRINT_DEL_JOB = 10
} ;

slim_int
dmpr_prnsrv_alloc(struct dmpr *top);

slim_int
dmpr_prnsrv_start(struct dmpr *top);

slim_int
dmpr_prnsrv_stop(struct dmpr *top);

void
dmpr_prnsrv_free(struct dmpr *top);

slim_int
dmpr_prnsrv_sendCommand(struct dmpr *top, const slim_char* in_cmd);

slim_int
dmpr_prnsrv_recvCommand(struct dmpr *top, sXML** out_doc, slim_int action_id);

slim_int
dmpr_prnsrv_getMedias(struct dmpr *top, TDMPrMedia *in_media, TDMPrMedias *out_medias);

slim_int
dmpr_prnsrv_getMargins(struct dmpr *top, TDMPrMedia *in_media,TDMPrMargins *out_margins);

slim_int
dmpr_prnsrv_printXHTML(struct dmpr *top, TDMPrJob *in_job);

slim_int
dmpr_prnsrv_cancelPrint(struct dmpr *top, TDMPrJob *in_job);

void
medias_media_free(TDMPrMedias *out_medias);

slim_int
dmpr_prnsrv_get_first_free_id(struct dmpr *top);

#endif /* _DMPR_PRNSRV_CLIENT_H */
