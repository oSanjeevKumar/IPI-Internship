/*
 * rada_service.h
 * Copyright (C) 2007-2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _RADA_SERVICE_H
#define _RADA_SERVICE_H

#include <soap_server.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
rada_service_response_proc (slim_int in_event, slim_int in_result, struct rada *self, slim_int in_job_id, slim_int in_req_id);

struct rada_service_request *
rada_service_request_alloc (struct rada *self, struct upnp_action_request *in_r, slim_int in_rid) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RADA_SERVICE_H */
