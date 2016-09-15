/*
 * nflc_satip.h
 * Copyright (C) 2007-2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* vim: set tabstop=2:softtabstop=2:shiftwidth=2:expandtab */

#ifndef NFLC_SATIP_H
#define NFLC_SATIP_H

#include <dlna_peer.h>
#include <satip_api.h>
#include <dlna_client.h>
#include <upnp_server.h>

/* SATIP structure. */
typedef struct satip_
{
  /* UPnP server pointer.  */
  struct upnp_server *us;

  /* UPnP client pointer.  */
  struct upnp_client *uc;
  struct dlna_client_tag dlna_client;

  /* UI callback function.  */
  TSATIPEventHandler eh;

  /* UI callback arguments. */
  void *arg;

  /* UPnP transport manager.  */
  struct upnp_transport_manager *tm;

  /* SATIP device start-up parameters */
  TSATIPNewParam *param;
} satip;

/* SATIP start type. */
typedef enum satip_start_type_
{
  E_SATIP_START_SERVER = 0,   /* SATIP server */
  E_SATIP_START_CLIENT,       /* SATIP client */
  E_SATIP_START_SVRCLI,       /* SATIP server + client */
  E_SATIP_START_MAX
} satip_start_type;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes */

/* API: Allocate SATIP */
satip *
satip_alloc (TSATIPNewParam *in_param);

/* API: Free SATIP */
void
satip_free (satip *self);

/* API: Start SATIP according to start type */
slim_int
satip_start (satip *self, TSATIPEventHandler in_eh, void *in_arg, satip_start_type start);

/* API: Stop SATIP */
slim_int
satip_stop (satip *self, satip_start_type stop);

/* API: Set SATIP device friendly name */
slim_int
satip_set_friendly_name(satip *self, slim_char *in_friendly_name);

/* API: Get SATIP device friendly name */
slim_char *
satip_get_friendly_name(satip *self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SATIP_H */
