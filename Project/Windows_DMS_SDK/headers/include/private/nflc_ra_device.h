/*
 * nflc_ra_device.h
 * Copyright (C) 2015-16 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */


#ifndef _RA_DEVICE_H
#define _RA_DEVICE_H

#include <gena_server.h>
#include <soap_server.h>
#include <nflc_ra_def.h>

#define RA_DEVICE_SERVICE_MAX	4

#define RA_DEVICE_SERVICE_RADASYNC	0 /* RADASync.  */

#define RA_DEVICE_SERVICE_RATACONFIG	0 /* RATAConfig.  */
#define RA_DEVICE_SERVICE_RADACONFIG	1 /* RADAConfig.  */
#define RA_DEVICE_SERVICE_INBOUNDCONNECTIONCONFIG	2 /* InboundConnectionConfig.  */

#define RA_DEVICE_SERVICE_ID_RATACONFIG               (SLIM_T("RATAConfig"))
#define RA_DEVICE_SERVICE_ID_RADASYNC                 (SLIM_T("RADASync"))
#define RA_DEVICE_SERVICE_ID_RADACONFIG               (SLIM_T("RADAConfig"))
#define RA_DEVICE_SERVICE_ID_INBOUNDCONNECTIONCONFIG  (SLIM_T("InboundConnectionConfig"))

// APP events delivered by twine callback
#define TWINE_EVT_NOTIFY_CONNECTED 1000
#define TWINE_EVT_NOTIFY_DISCONNECTED 1001
#define TWINE_EVT_NOTIFY_ERROR 1002


enum rata_target_state {
  RATA_TARGET_STATE_DISCONNECTED=0,
  RATA_TARGET_STATE_CONNECTED=1
} ;


typedef struct rada_config_filter_list 
{
	struct rada_config_filter_list *next ;
	struct rada_config_filter_list *prev ;

	slim_char *uuid ;
	slim_char *credentialID ;
	slim_int visible ;

}rada_config_filter_list_t ;

typedef List(rada_config_filter_list_t  *) filter_list_t;

struct ra_device;

/* RAS service base structure.  */
struct ra_service
{
  /* Backpoiner to the top.  */
  struct ra_device *top;
	struct ra_device *radevice ;

  /* Service ID.  */
  slim_char *id;
  struct	http_client	*hc ;

	/* state variables */

	/* Member functions.  */
  slim_int (*start) (struct ra_service *);
  slim_int (*stop) (struct ra_service *);
  slim_int (*subscribe) (struct ra_service *, struct upnp_subscribe_request *);
  slim_int (*get_var) (struct ra_service *, struct upnp_query_variable *);
  slim_int (*action) (struct ra_service *, struct upnp_action_request *);
  slim_int (*notify) (struct ra_device *);

};

// Top level device structure shared by RAC and RAS
// 
struct ra_device
{
	/* UPnP server pointer.  */
	struct upnp_server *us;

	//struct dlna_client_tag dlna_client;

	/* UI callback function.  */
	ra_device_callback_t async_callback;
  void *callback_arg ;

	/* Callbacks.  */
	struct ra_service *(*service_lookup) (struct ra_device *, int);

	/* RAS services.  */
	struct ra_service *service[RA_DEVICE_SERVICE_MAX];
	
	void *arg ;

	struct rada *rada;
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RA_DEVICE_H */
