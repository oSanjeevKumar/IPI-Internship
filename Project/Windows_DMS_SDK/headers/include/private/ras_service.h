/*
 * ras_service.h
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

#ifndef _RAS_SERVICE_H
#define _RAS_SERVICE_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* RAS service base structure.  */
struct ra_service
{
  /* Backpoiner to the top ( RAC/RAS/RADA ).  */
  void *top;

  /* Service ID.  */
  slim_char *id;
	struct	http_client	*hc ;

	/* Member functions.  */
  slim_int (*start) (struct ra_service *);
  slim_int (*stop) (struct ra_service *);
  slim_int (*subscribe) (struct ra_service *, struct upnp_subscribe_request *);
  slim_int (*get_var) (struct ra_service *, struct upnp_query_variable *);
  slim_int (*action) (struct ra_service *, struct upnp_action_request *);

};


slim_int
ras_service_response_proc (slim_int in_event, slim_int in_result, struct ras *self, slim_int in_job_id, slim_int in_req_id);

struct ras_service_request *
ras_service_request_alloc (struct ras *self, struct upnp_action_request *in_r, slim_int in_rid) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RAS_SERVICE_H */
