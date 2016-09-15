/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */
/* Copyright (C) 2011 Access Co. Ltd. All Rights Reserved.  */

#ifndef _DMPR_ACTION_H
#define _DMPR_ACTION_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
dmpr_action_get_job_attributes (struct dmpr_service *s, struct upnp_action_request *r) ;

slim_int
dmpr_action_cancel_job (struct dmpr_service *s, struct upnp_action_request *r) ;

slim_int
dmpr_action_get_printer_attributes (struct dmpr_service *s, struct upnp_action_request *r) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DMPR_ACTION_H */
