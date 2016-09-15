/*
 * rada.h
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


#ifndef _RADA_H
#define _RADA_H

#include <gena_server.h>
#include <soap_server.h>
#include "nflc_ra_device.h"

#define RADA_SERVICE_SYNC	0 /* RADASync.  */
#define RADA_SERVICE_MAX	1

#define RADA_SERVICE_ID_SYNC	"RADASync"

#define RADA_SUCCESS	UPNP_SUCCESS


#ifdef NEVER
struct rada_service_request {
  struct rada_service_request *prev;
  struct rada_service_request *next;
  struct upnp_action_request base;
  slim_int  rid; /* Unique Request ID */
};
#endif

struct rada;

/* UI callback function type.  */
typedef slim_int (*rada_callback_t) (struct rada *top, sXML *doc);

/* RADA service base structure.  */
struct rada_service
{
  /* Backpoiner to the top.  */
  struct rada *top;
	struct	ra_device *radevice ;
  /* Sercice ID.  */
  slim_char *id;
	struct	http_client	*hc ;

	/* state variables */

	/* Member functions.  */
  slim_int (*start) (struct rada_service *);
  slim_int (*stop) (struct rada_service *);
  slim_int (*subscribe) (struct rada_service *, struct upnp_subscribe_request *);
  slim_int (*get_var) (struct rada_service *, struct upnp_query_variable *);
  slim_int (*action) (struct rada_service *, struct upnp_action_request *);
  slim_int (*notify) (struct ra_device *);

};

/* RADA structure.  */
struct rada
{
  /* UPnP server pointer.  */
  struct upnp_server *us;

  struct ra_device *radevice;
	struct	_rata	*rata ;
	/* UPnP client pointer.  */
  struct upnp_client *uc;
	//struct dlna_client_tag dlna_client ;

  /* String buffer.  */
  struct sbuf *sbuf;

  /* Callbacks.  */
  struct rada_service *(*service_lookup) (struct rada *, int);

  /* RADA services.  */
  struct rada_service *service[RADA_SERVICE_MAX];

  /* ssdp common module */
  //struct dlna_ssdp_tag *ssdp_common;

	/* printer peer event handler */
//	DMPrNotifyCallback notify_callback ;
	/* user space pointer */
	void *arg ;

	struct	sbuf	SystemInfo ;
	slim_int	SystemInfoUpdateID ;
	struct	sbuf	A_ARG_TYPE_FilterList ;
	struct	sbuf	A_ARG_TYPE_UUID ;

//	List(struct rada_service_request*) req_list;
    slim_int fl_is_ras ;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes.  */

/* API: Allocate DMPr.  */
struct rada*
rada_alloc (dlna_progress em, ra_device_callback_t callback, slim_half port,
	    slim_char *config_dir, slim_char *device_file, struct ra_device *top, slim_int fl_is_ras, slim_char *twine_path);

/* API: Free RADA.  */
void
rada_free (struct rada *top);

/* API: Start RADA.  */
slim_int
rada_start (struct rada *top);

/* API: Stop RADA.  */
slim_int
rada_stop (struct rada *top);

/* API: Start RADA ra service  */
slim_int
rada_start_ra_service (struct rada *top);

/* API: Stop RADA ra service */
slim_int
rada_stop_ra_service (struct rada *top);

/* API: Update RADA.  */
slim_int
rada_update (struct rada *top);

/* API: Shutdown twine in RADA.  */
slim_int
rada_shutdown (struct rada *top);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RADA_H */
