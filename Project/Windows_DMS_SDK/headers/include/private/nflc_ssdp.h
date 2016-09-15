/*
 * nflc_ssdp.h
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

#ifndef NFLC_SSDP_H
#define NFLC_SSDP_H

#include <nflc_upnp.h>
#include <http_parser.h>

/* SSDP group.  */
#define NFLC_SSDP_GROUP                 ((slim_char *) "239.255.255.250")

/* SSDP port.  */
#define NFLC_SSDP_PORT                  (1900)

/* SSDP multicast packet TTL.  */
#define NFLC_SSDP_MULTICAST_TTL         (4)

/* SSDP multicast packet TTL for SAT>IP.  */
#ifdef DLNA_SUPPORT_SATIP
#define NFLC_SATIP_SSDP_MULTICAST_TTL   (2)
#endif /* DLNA_SUPPORT_SATIP */

/* SSDP packet copy number.  */
#define NFLC_SSDP_PACKET_COPY           (4)

/* SSDP Notify packet interval in seconds  */
#define NFLC_SSDP_NOTIFY_INTERVAL       (300)

/* SSDP Notify Message Delay in milliseconds (ms)*/
#define NFLC_SSDP_NOTIFY_MSG_DELAY      (200)

#define NFLC_SSDP_PACKET_HTTP_HEAD      SLIM_T("HTTP")

/* Default SSDP Cache-Control: max-age value.  */
#define NFLC_SSDP_MAX_AGE_DEFAULT    (1800)

/* ssdp server packet repeat count */
#define SSDP_REPETITION_COUNT 2
/* ssdp server delay in between repeats */
#define SSDP_PACKET_REPEAT_DELAY 100
/* ssdp server delay in between packets */
#define SSDP_PACKET_DELAY 20


/* SSDP packet parse type.  */
enum ssdp_parse_type
{
  SSDP_PARSE_CLIENT_SEND,
  SSDP_PARSE_CLIENT_RECV,
  SSDP_PARSE_SERVER
};

/* SSDP search type.  */
enum ssdp_search_type
{
  SSDP_ERROR          = -1,
  SSDP_ALL            =  0,
  SSDP_ROOTDEVICE,
  SSDP_DEVICEUDN,
  SSDP_DEVICETYPE,
  SSDP_DEVICEALL,
  SSDP_SERVICE
};

/* SSDP packet buffer size.  There is no specifiction for this.  Intel
   UPnP library uses 2500 as the value.  We might need to figure out
   this is OK or not.  */
#define SSDP_MAX_PACKET_SIZE                (2560)

/* Structure to store the SSDP information.  */
struct ssdp_param
{
  enum ssdp_search_type type;

  /* UDN in SSDP packet.  */
  slim_char udn[NFLC_LINE_SIZE];

  /* Device type in SSDP packet. */
  slim_char device_type[NFLC_LINE_SIZE];

  /* Service type in SSDP packet.  */
  slim_char service_type[NFLC_LINE_SIZE];
};

typedef slim_int (ssdp_client_packet_parse_proc_t) (void *arg, slim_char *buf,
                          slim_int length, slim_int type);

  /* packet handle callback for ssdp_server */
typedef slim_int (ssdp_server_packet_parse_proc_t) (void *in_ssdp_server, 
                              slim_char *in_buf, slim_int in_len, 
                              dlna_ip_addr *in_from, slim_half in_from_port);

struct dlna_ssdp_tag {
  /* event manager */
  dlna_progress em;

  upnp_callback_t ssdp_callback;

  void *info;
  /* SSDP common socket (1900) */
  slim_int sock_multicast;

  void* ssdp_client;

  void* ssdp_server;

  /* packet handle callback for ssdp_client */
  ssdp_client_packet_parse_proc_t *client_packet_parse_proc;

  /* packet handle callback for ssdp_server */
  ssdp_server_packet_parse_proc_t *server_packet_parse_proc;

  /* Events. */
  dlna_progress_handle e_read_multicast;
};

typedef struct dlna_ssdp_tag dlna_ssdp_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum ssdp_search_type
ssdp_type_fetch (slim_char *str);

slim_int
ssdp_service_fetch (slim_char *str, struct ssdp_param *param);

slim_int
ssdp_string_fetch (slim_char *str, struct ssdp_param *param);

slim_bool
ssdp_valid_message (http_message_t *message);

slim_int
ssdp_send_sock (dlna_ip_addr *addr, slim_half port);

slim_int
ssdp_recv_sock (slim_half port);

slim_int
ssdp_multicast_join (slim_int sock, dlna_ip_addr *addr, slim_int ifindex);

slim_int
ssdp_multicast_leave (slim_int sock, dlna_ip_addr *addr, slim_int ifindex);


/* dlna_ssdp_t object functions */

dlna_ssdp_t*
dlna_ssdp_alloc(dlna_progress in_p, upnp_callback_t in_callback, void *info);

void
dlna_ssdp_free(dlna_ssdp_t *self);

slim_int
ssdp_multicast_set_client(dlna_ssdp_t *self, void *in_ssdp_client, slim_half in_port,
                          ssdp_client_packet_parse_proc_t *in_client_packet_parse_proc);

void
ssdp_multicast_unset_client(dlna_ssdp_t *self, void *in_ssdp_client);

slim_int
ssdp_multicast_set_server(dlna_ssdp_t *self, void *in_ssdp_server, slim_half in_port,
                     ssdp_server_packet_parse_proc_t *in_server_packet_parse_proc);

void
ssdp_multicast_unset_server(dlna_ssdp_t *self, void *in_ssdp_server);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SSDP_H */
