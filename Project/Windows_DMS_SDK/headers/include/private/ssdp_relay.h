/*
 * ssdp_relay.h
 * Copyright (C) 2007-2012 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

/* SSDP relay.  */

#ifndef NFLC_SSDP_RELAY_H
#define NFLC_SSDP_RELAY_H

#include <nflc_ssdp.h>

/* Forward decralation.  */


struct upnp_server;
struct upnp_interface;
struct ssdp_relay_packet ;


struct ssdp_relay_notify_tag
{
  slim_int count;
  dlna_progress_handle e_notify;
};
typedef struct ssdp_relay_notify_tag ssdp_relay_notify_t;

/* SSDP server client.  */
struct ssdp_relay_client
{
  /* Linked list.  */
  struct ssdp_relay_client *next;
  struct ssdp_relay_client *prev;

  /* SSDP client address and port.  */
  dlna_ip_addr addr;
  slim_half port;
  slim_word timeout;

  /* Which SSDP interface this client belongs to.  */
  struct ssdp_relay_interface *ssi;

  /* Parameter of the SSDP cleint.  */
  struct ssdp_param event;

  rada_sync_system_info_device_info_t sysInfo ;
  dlna_progress_handle e_ssdp_relay_timer;
  struct ssdp_relay_notify_tag notify;

  dlna_progress_handle e_src_msearch_response_timer;

  slim_bool max_age_started;

  /* SSDP max-age value.  */
  slim_int max_age;
};

struct ssdp_relay_remote
{
  /* Linked list.  */
  struct ssdp_relay_remote *next;
  struct ssdp_relay_remote *prev;

  /* Which SSDP interface this client belongs to.  */
  struct ssdp_relay_interface *ssi;

  rada_sync_system_info_device_info_t sysInfo ;
  dlna_progress_handle e_ssdp_relay_timer;
  struct ssdp_relay_notify_tag notify;

  slim_bool max_age_started;

  /* SSDP max-age value.  */
  slim_int max_age;
  slim_int is_root ;
};


/* SSDP server interface.  */
struct ssdp_relay_interface
{
  /* Interface.  */
  struct upnp_interface *ifp;

  /* Back pointer to the SSDP server.  */
  struct ssdp_relay *sr;

  /* Description URL.  */
  slim_char *desc_url;

  /* SSDP client list.  */
  List(struct ssdp_relay_client *) client_list;

  /* SSDP packet list.  */
  List(struct ssdp_relay_packet *) packet_list;

};

struct ssdp_relay_packet
{
  /* Linked list.  */
  struct ssdp_relay_packet *next;
  struct ssdp_relay_packet *prev;

  slim_char *buf ;
 
  slim_int sock ;
  dlna_ip_addr addr ;
  dlna_ip_addr local_addr ;
  slim_half    port;
  slim_int is_unicast ;
  slim_int repeat_count ;
  struct ssdp_relay_interface *ssi;

  dlna_progress_handle e_packet_timer;
};


/* SSDP relay.  */
struct ssdp_relay
{
  /* UPnP back pointer.  */
  struct upnp_server *us;

  /* SSDP common module.  */
  dlna_ssdp_t *ssdp;
  slim_bool is_own_ssdp;
  slim_bool ssdp_relay_privacy;

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
  // handle on per client base  struct ssdp_server_notify_tag notify;
	struct ssdp_relay_notify_tag notify;

 /* Events.  */
  dlna_progress_handle e_read_unicast;
  dlna_progress_handle e_ssdp_relay_timer;

  //need to be handled on a per client base  dlna_progress_handle e_ssdp_relay_timer;

  /* SSDP client list.  */
  List(struct ssdp_relay_remote *) remote_list;

  slim_int shutdown ;
};

/* SSDP server timer initial delay.  */
#define SSDP_RELAY_TIMER_DELAY	   (3)

/* Prototypes.  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
ssdp_relay_if_start (struct ssdp_relay *sr, struct upnp_interface *ifp);

slim_int
ssdp_relay_if_stop (struct ssdp_relay *sr, struct upnp_interface *ifp);

struct ssdp_relay_interface *
ssdp_relay_if_lookup (struct ssdp_relay *sr, slim_int ifindex);

slim_int
ssdp_relay_start (struct ssdp_relay *sr);

slim_int
ssdp_relay_stop (struct ssdp_relay *sr);

slim_int
ssdp_relay_shutdown (struct ssdp_relay *sr);

struct ssdp_relay *
ssdp_relay_alloc (struct upnp_server *us, dlna_ssdp_t *in_ssdp, upnp_callback_t in_callback, void *info);

void
ssdp_relay_free (struct ssdp_relay *sr);

/* SSDP relay configuration API.  */
slim_int
ssdp_relay_max_age_set (struct ssdp_relay *sr, slim_int in_max_age);

slim_int
ssdp_relay_max_age_unset (struct ssdp_relay *sr);

slim_int
ssdp_relay_update(struct rada_sync *s , slim_int action, slim_char *usn);

slim_int
ssdp_relay_advertise(struct ssdp_relay_interface *ssi, 
										 slim_int advertise /* 0,1,-1 */,
										 enum ssdp_search_type in_search_type,
										 dlna_ip_addr *in_addr, slim_half in_port,
										 slim_char *in_device_type, slim_char *in_udn, slim_char *in_service_type ) ;

slim_int
ssdp_relay_set_privacy (struct rada_sync *s, slim_bool in_flag);

slim_int
ssdp_relay_get_privacy (struct rada_sync *s, slim_bool *out_flag);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SSDP_RELAY_H */
