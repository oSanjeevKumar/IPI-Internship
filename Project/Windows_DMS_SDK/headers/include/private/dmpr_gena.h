/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */
/* Copyright (C) 2011 Access Co. Ltd. All Rights Reserved.  */

#ifndef _DMPR_GENA_H
#define _DMPR_GENA_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
dmpr_gena_printer_state_change(struct dmpr *top, struct upnp_subscribe_request *r) ;

void
dmpr_gena_media_sheets_completed_change (struct dmpr *top, struct upnp_subscribe_request *r);

void
dmpr_gena_job_end_state_change (struct dmpr *top, struct upnp_subscribe_request *r);

void
dmpr_gena_job_abort_state_change (struct dmpr *top, struct upnp_subscribe_request *r);

void
dmpr_gena_job_id_list_change (struct dmpr *top, struct upnp_subscribe_request *r);

void
dmpr_gena_content_complete_list_change (struct dmpr *top, struct upnp_subscribe_request *r);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_GENA_H */
