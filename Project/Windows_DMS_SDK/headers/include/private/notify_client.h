/*
 * notify_client.h
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

#ifndef _NOTIFY_CLIENT_H
#define _NOTIFY_CLIENT_H

#ifdef DLNA_SUPPORT_RUIPL

//#include "ssdp.h"

/* Notify group.  */
#define NOTIFY_GROUP                 ((slim_char *) "239.255.255.246")

/* Notify port.  */
#define NOTIFY_PORT                  (7900)

#define NOTIFY_MAX_PACKET_SIZE                (2560)

struct upnp_interface;

struct upnp_param_notify
{

  /* UDN in SSDP packet.  */
  slim_char *usn;

	slim_int	event_type ;
	slim_char	*msg ;
	slim_char	*url ;
	sXML	*doc ;
	sXML	*profilelist ;
	slim_int	seq ;
	/* CEA-2014-B */
	slim_int	window_type ;
	slim_int	window_width ;
	slim_int	window_height ;
};


typedef slim_int (notify_client_packet_parse_proc_t) (void *arg, slim_char *buf,
                          slim_int length, slim_int type);

struct dlna_notify_tag {
  /* event manager */
  dlna_progress em;

  /* NOTIFY common socket (7900) */
  slim_int sock_multicast;

  void* notify_client;

  /* packet handle callback for notify_client */
  notify_client_packet_parse_proc_t *client_packet_parse_proc;

  /* Events. */
  dlna_progress_handle e_read_multicast;
};

typedef struct dlna_notify_tag dlna_notify_t;

typedef struct notify_message
{
	struct notify_message *next;
  struct notify_message *prev;

	slim_char *usn;
	slim_int	seq ;
	slim_char *url ;

} notify_message_t  ;

/* notify client structure.  */
struct notify_client
{
  /* UPnP client structure.  */
  struct upnp_client *uc;

  /* NOTIFY common module.  */
  dlna_notify_t *notify;
  
  List (struct notify_message *) messages;

};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

/* Prototypes.  */
slim_int
notify_client_start (struct notify_client *nc);

slim_int
notify_client_stop (struct notify_client *nc);

slim_int
notify_client_if_start (struct notify_client *nc, struct upnp_interface *ifp);

slim_int
notify_client_if_stop (struct notify_client *nc, struct upnp_interface *ifp);

slim_int
notify_client_suspend (struct notify_client *nc);

slim_int
notify_client_resume (struct notify_client *nc);

struct notify_client *
notify_client_alloc (struct upnp_client *uc);

void
notify_client_free (struct notify_client *nc);

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* DLNA_SUPPORT_RUIPL */

#endif /* _NOTIFY_CLIENT_H */
