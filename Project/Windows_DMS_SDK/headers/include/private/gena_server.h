/*
 * gena_server.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

/* GENA -- General Event Notification Architecture.  */

#ifndef NFLC_GENA_SERVER_H
#define NFLC_GENA_SERVER_H

#include <http_server.h>

struct upnp_server;

/* UPnP GENA sbuscribe request.  */
struct upnp_subscribe_request
{
  /* Service ID.  */
  slim_char *id;

  /* Subscribe ID */
  upnp_sid_t sid;
  /* String buffer for the reply.  */
  struct sbuf *sbuf;

  /* identification for whether is the initial request */
  slim_bool b_init;
};

struct upnp_subscribe_event
{
  /* Service ID.  */
  slim_char *id;

  /* event type */
  slim_int type;
  
  /* Subscribe ID */
  upnp_sid_t sid;
};

/* Subscribe.  */
struct gena_subscribe
{
  /* Linked list.  */
  struct gena_subscribe *next;
  struct gena_subscribe *prev;

  /* GENA server back pointer.  */
  struct gena_server *gs;

  /* Service information.  */
  struct upnp_service_info *service;

  /* GENA FSM state.  */
  slim_int state;

  //Initial notification sent
  slim_int notification_sent;

  /* SID of the subscription.  */
  upnp_sid_t sid;

  /* Event key.  */
  slim_int event_key;

  /* Send event key.  */
  slim_int send_event_key;

  /* Time out value.  */
  slim_int time_out;

  /* Delivery URL list.  */
  URL_list delivery_url;

  /* HTTP client connection.  */
  struct http_client *hc;

  /* GENA subscribe expiration timer. */
  dlna_progress_handle e_gena_subscribe_timer;
  dlna_progress_handle e_notify;

  /* Free gena subscription */
  dlna_progress_handle e_gena_subscriber_free_timer;
  slim_word subscriber_free_counter;
};

/* GENA server.  */
struct gena_server
{
  /* UPnP back pointer.  */
  struct upnp_server *us;

  /* GENA HTTP Response headers.  */
  slim_char *header;
  slim_int header_size;

  /* GENA subscribe request.  */
  struct upnp_subscribe_request r;

  /* Max number of subscription.  */
  slim_int subscribe_max;
};

/* UPnP GENA time out
 * UPnP spec UPnP-arch-DeviceArchitecture-v1 1-20081015: SHOULD be greater than or equal to 1800 seconds (30 minutes).
 * */
#define GENA_TIME_OUT_DEFAULT                     (1800)


/* Max subscription count.  */
#define GENA_MAX_SUBSCRIPTION                     (1024) /* max subscription per service */

#define GENA_E_NOTIFY_UNACCEPTED_REMOVE_SUB       (-9)

/* UPnP GENA event notification delay.  */
#define GENA_EVENT_NOTIFICATION_DELAY             (1)

/* Timer in miliseconds */
#define GENA_UNSUBSCRIBE_TIMER                    (100)

/* Safety Valve */
#define GENA_UNSUBSCRIBE_COUNT                    (30)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
gena_server_property_set (struct upnp_subscribe_request *r,
                          slim_char *name, slim_char *value);

slim_int
gena_server_event_notify (struct gena_server *gs, slim_char *service_id);

slim_int
gena_server_start (struct gena_server *gs);

slim_int
gena_server_stop (struct gena_server *gs);

struct gena_server *
gena_server_alloc (struct upnp_server *us);

void
gena_server_free (struct gena_server *gs);

void
gena_subscribe_free (struct gena_subscribe *s);

/* for upnp_server.c */
void
gena_server_process (http_session_t *session, http_message_t *http);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_GENA_SERVER_H */
