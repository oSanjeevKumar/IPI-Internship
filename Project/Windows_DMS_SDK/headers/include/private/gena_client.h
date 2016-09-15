/*
 * gena_client.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_GENA_CLIENT_H
#define NFLC_GENA_CLIENT_H

/*
 * GENA - General Event Notification Architecture base client side
 * implementation.
 */

#define GENA_CLIENT_SUB_REQ_TIMEOUT_SECOND  (30)

/* UPnP spec UPnP-arch-DeviceArchitecture-v1 1-20081015: SHOULD be greater than or equal to 1800 seconds (30 minutes).*/
#define CP_MINIMUM_SUBSCRIPTION_TIME  (1800)

/* GENA client subscription.  */
struct gena_client_sub
{
  /* Linked list.  */
  struct gena_client_sub *next;
  struct gena_client_sub *prev;

  /* Flags.  */
  slim_byte flags;
#define GENA_CLIENT_FLAG_SUBSCRIBE    (1 << 0)
#define GENA_CLIENT_FLAG_UNSUBSCRIBE  (1 << 1)

  /* GENA client structure.  */
  struct gena_client *gc;

  /* URN for related device.  */
  slim_char *device_udn;

  slim_char *service_type;

  /* Gena server SID. */
  slim_char *sid;

  /* Url of client action. */
  slim_char *url;

  /* HTTP client.  */
  struct http_client *hc;

  /* Time out value.  */
  slim_int time_out;

  /* Renew timer.  */
  dlna_progress_handle e_gena_sub_renew_timer;

  slim_int retryCount;
};

/* GENA client.  */
struct gena_client
{
  /* UPnP client structure.  */
  struct upnp_client *uc;

  /* Subscription list.  */
  List (struct gena_client_sub *) sub_list;

  /* GENA accept socket.  */
  slim_int sock;

  /*GENA accept port*/
  slim_int port;

  /* HTTP parser.  */
  http_parser_t parser;

  /* Receive buffer.  */
  slim_byte buf[UPNP_READ_BUFSIZ];

  /* GENA events.  */
  dlna_progress_handle e_gena_client_accept;
};

struct gena_notify_param {
  slim_char  *device_udn;
  slim_char  *service_type;
  slim_char  *name;
  slim_char  *value;
};

typedef struct gena_notify_param gena_notify_param_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes.  */
slim_int
gena_client_subscribe (struct gena_client *gc, slim_char *in_device_urn, slim_char *in_service_type,
                       slim_char *url, slim_int time_out, struct gena_client_sub *in_sub);

struct gena_client_sub *
gena_client_subscription_lookup_by_url (struct gena_client *gc, slim_char *in_url);

struct gena_client_sub *
gena_client_subscription_lookup_by_udn_and_service(struct gena_client *gc, slim_char *in_udn, slim_char *in_service_type);

slim_int
gena_client_subscription_delete_by_device (struct upnp_device *in_device);

slim_int
gena_client_subscription_delete_by_device_and_service(struct upnp_device *in_device, struct upnp_service *service);

slim_int
gena_client_unsubscribe (struct gena_client *gc, struct gena_client_sub *sub);

slim_int
gena_client_start (struct gena_client *gc);

slim_int
gena_client_stop (struct gena_client *gc);

struct gena_client *
gena_client_alloc (struct upnp_client *uc);

void
gena_client_free (struct gena_client *gc);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_GENA_CLIENT_H */
