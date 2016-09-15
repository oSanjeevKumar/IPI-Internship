/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */
/* Copyright (C) 2011 Access Co. Ltd. All Rights Reserved.  */

#ifndef _DMPR_VARS_H
#define _DMPR_VARS_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
dmpr_vars_set_printer_state(struct dmpr *top, TDMPrPrinterState *state) ;
void
dmpr_vars_set_job_abort_state(struct dmpr *top, TDMPrJob *job) ;
void
dmpr_vars_set_job_end_state(struct dmpr *top, TDMPrJob *job) ;
void
dmpr_vars_set_job_id_list(struct dmpr *top) ;
void
dmpr_vars_set_job_content_complete_list(struct dmpr *top) ;
void
dmpr_vars_set_job_parms(struct dmpr *top) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_UTIL_H */
