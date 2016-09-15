/*
 * ssdp_client.h
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

#ifndef NFLC_SSDP_CLIENT_H
#define NFLC_SSDP_CLIENT_H

#include <nflc_ssdp.h>


struct ssdp_client_search_send_timer
{
  struct ssdp_client_search_send_timer *next;
  struct ssdp_client_search_send_timer *prev;
  
  struct ssdp_client *sc;

  slim_int msearch_if_index;
  
};
typedef struct ssdp_client_search_send_timer ssdp_client_search_send_timer_t;

/* SSDP client structure.  */
struct ssdp_client
{
  /* UPnP client structure.  */
  struct upnp_client *uc;

  /* SSDP common module.  */
  dlna_ssdp_t *ssdp;
  slim_bool is_own_ssdp;

  /* SSDP sockets.  */
  slim_int sock_unicast;

  /* SSDP search type.  */
  enum ssdp_search_type search_type;

  /* SSDP mx value.  */
  slim_int mx;

  /* SSDP destination address.  */
  dlna_ip_addr addr;
  slim_int port;

  /* SSDP M-SEARCH Messge Buffer */
  slim_char *msearch_buffer;

  /* M-Search message send progress. */
  List(ssdp_client_search_send_timer_t *) msearch_list;
  dlna_progress_handle e_msearch_send;
  dlna_progress_handle e_msearch_timer;

  /* Events.  */
  dlna_progress_handle e_ssdp_client_send;
  dlna_progress_handle e_ssdp_client_search;

  dlna_progress_handle e_ssdp_client_discover;
  slim_int client_discover_time_out;
};

/* SSDP device update handling delay.  */
#define SSDP_CLIENT_UPDATE_DELAY (1)

/* SSDP device search delay.  */
#define SSDP_CLIENT_DEVICE_SEARCH_DELAY  (5)
#define SSDP_CLIENT_DEVICE_SEARCH_INTERVAL (600)

#define SSDP_CLIENT_DEVICE_REMOVE_IF_DOWN_DELAY (60) /* in seconds */

#define SSDP_SEARCH_TYPE(S)                                                   \
  ((S)->search_type == SSDP_DEVICEALL                                         \
   ? (slim_char *) "ssdp:all" : (S)->uc->search_type)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

/* Prototypes.  */
slim_int
ssdp_client_start (struct ssdp_client *sc);

slim_int
ssdp_client_stop (struct ssdp_client *sc);

slim_int
ssdp_client_if_start (struct ssdp_client *sc, struct upnp_interface *ifp);

slim_int
ssdp_client_if_stop (struct ssdp_client *sc, struct upnp_interface *ifp);

void
ssdp_client_update_expiration_timer_all(struct ssdp_client *sc);

slim_int
ssdp_client_search (struct ssdp_client *sc);

slim_int
ssdp_client_suspend (struct ssdp_client *sc);

slim_int
ssdp_client_resume (struct ssdp_client *sc);

slim_int
ssdp_client_alloc (struct upnp_client *uc, dlna_ssdp_t *in_ssdp, struct ssdp_client **out_sc, 
                   upnp_callback_t in_callback, void *info);

void
ssdp_client_free (struct ssdp_client *sc);

slim_int
ssdp_device_download (struct upnp_client *uc, struct upnp_device *in_device);

slim_int
ssdp_client_persence_check_start (struct ssdp_client *sc, slim_int in_timeout);

slim_int 
ssdp_client_persence_check_stop (struct ssdp_client *sc);

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* NFLC_SSDP_CLIENT_H */
