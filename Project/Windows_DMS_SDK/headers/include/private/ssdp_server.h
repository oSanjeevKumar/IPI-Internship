/*
 * ssdp_server.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

/* SSDP server.  */

#ifndef NFLC_SSDP_SERVER_H
#define NFLC_SSDP_SERVER_H

#include <nflc_ssdp.h>

/* Forward decralation.  */
struct upnp_server;
struct upnp_interface;
struct ssdp_server_packet ;

/* SSDP server client.  */
struct ssdp_server_client
{
  /* Linked list.  */
  struct ssdp_server_client *next;
  struct ssdp_server_client *prev;

  /* SSDP client address and port.  */
  dlna_ip_addr addr;
  slim_half port;
  slim_word timeout;

  /* Which SSDP interface this client belongs to.  */
  struct ssdp_server_interface *ssi;

  /* Parameter of the SSDP cleint.  */
  struct ssdp_param event;

  dlna_progress_handle e_ssc_msearch_response_timer;
};

/* SSDP server interface.  */
struct ssdp_server_interface
{
  /* Interface.  */
  struct upnp_interface *ifp;

  /* Back pointer to the SSDP server.  */
  struct ssdp_server *ss;

  /* Description URL.  */
  slim_char *desc_url;

  /* SSDP client list.  */
  List(struct ssdp_server_client *) client_list;

  /* SSDP packet list.  */
  List(struct ssdp_server_packet *) packet_list;

};

struct ssdp_server_notify_tag {
  slim_int count;
  dlna_progress_handle e_notify;
};

typedef struct ssdp_server_notify_tag ssdp_server_notify_t;


struct ssdp_server_packet
{
  /* Linked list.  */
  struct ssdp_server_packet *next;
  struct ssdp_server_packet *prev;

  slim_char *buf ;
 
  slim_int sock ;
  dlna_ip_addr addr ;
  dlna_ip_addr local_addr ;
  slim_half    port;
  slim_int is_unicast ;
  slim_int repeat_count ;
  struct ssdp_server_interface *ssi;

  dlna_progress_handle e_packet_timer;
};


/* SSDP server.  */
struct ssdp_server
{
  /* UPnP back pointer.  */
  struct upnp_server *us;

  /* SSDP common module.  */
  dlna_ssdp_t *ssdp;
  slim_bool is_own_ssdp;

  /* SSDP server socket.  */
  slim_int sock_unicast;

  /* SSDP max-age advertisement started.  */
  slim_bool max_age_started;

  /* SSDP max-age value.  */
  slim_int max_age;

  /*SSDP NOTIFY Advertisement Interval*/
  slim_word notify_interval;

  /*SSDP NOTIFY Advertisment Message Delay*/
  slim_word notify_msg_delay;

  /*SSDP NOTIFY Advertisement Message Count*/
  slim_int notify_msg_copy_count;

  /* SSDP group address.  */
  dlna_ip_addr group;

  /* SSDP read buffer.  */
  slim_char buf[SSDP_MAX_PACKET_SIZE + 1];
  
  /* SSDP notify proc */
  struct ssdp_server_notify_tag notify;

  /* Events.  */
  dlna_progress_handle e_read_unicast;
  dlna_progress_handle e_ssdp_server_timer;

  /* SATIP implementation */
#ifdef DLNA_SUPPORT_SATIP
  dlna_progress_handle e_satip_defend_timer;
  dlna_progress_handle e_satip_device_id_timer;

  slim_int device_id;
  slim_int boot_id;

  slim_bool device_id_conflict;
  slim_bool is_first_ssdp_notify;
#endif /* DLNA_SUPPORT_SATIP */
  slim_int shutdown ;
};

/* SSDP server timer initial delay.  */
#define SSDP_SERVER_TIMER_DELAY	   (3)

/* SATIP server wait device ID defense period  */
#ifdef DLNA_SUPPORT_SATIP
#define SATIP_SERVER_DEVICE_ID_WAIT_PERIOD_SEC (5)
#endif

/* Prototypes.  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
ssdp_server_if_start (struct ssdp_server *ss, struct upnp_interface *ifp);

slim_int
ssdp_server_if_stop (struct ssdp_server *ss, struct upnp_interface *ifp);

struct ssdp_server_interface *
ssdp_server_if_lookup (struct ssdp_server *ss, slim_int ifindex);

slim_int
ssdp_server_start (struct ssdp_server *ss);

slim_int
ssdp_server_stop (struct ssdp_server *ss);

slim_int
ssdp_server_shutdown (struct ssdp_server *ss);

struct ssdp_server *
ssdp_server_alloc (struct upnp_server *us, dlna_ssdp_t *in_ssdp, upnp_callback_t in_callback, void *info);

void
ssdp_server_free (struct ssdp_server *ss);

/* SSDP server configuration API.  */
slim_int
ssdp_server_max_age_set (struct ssdp_server *ss, slim_int in_max_age);

slim_int
ssdp_server_max_age_unset (struct ssdp_server *ss);

slim_int
ssdp_server_t_stop(struct ssdp_server *ss);

slim_int
ssdp_server_t_start(struct ssdp_server *ss);

slim_int
ssdp_server_reset_advertisements (struct ssdp_server *ss);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SSDP_SERVER_H */
