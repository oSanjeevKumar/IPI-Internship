/*
 * upnp_interface.h
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

#ifndef NFLC_UPNP_INTERFACE_H
#define NFLC_UPNP_INTERFACE_H

#include <nflc_upnp.h>

struct upnp_address
{
  struct upnp_address *next;
  struct upnp_address *prev;

  /* Interface back pointer.  */
  struct upnp_interface *ifp;

  /* Flags.  */
  slim_byte flags;
#define UPNP_ADDRESS_LINKLOCAL  (1 << 0)

  /* Prefix length.  */
  slim_byte prefixlen;

  /* Address.  */
  dlna_ip_addr addr;

  /* Member function.  */
  slim_int (*is_primary) (struct upnp_address *addr);
  slim_int (*is_linklocal) (struct upnp_address *addr);
};

struct upnp_interface
{
  struct upnp_interface *next;
  struct upnp_interface *prev;

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  struct upnp_interface *parent;
#endif /*DLNA_DMS_SUPPORT_IF_STORAGE_FILTER*/

  /* Interface manager back pointer.  */
  struct upnp_if_manager *ifm;

  /* Interface index. */
  slim_int ifindex;

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  /* Kernel interface index.  */
  slim_int kernel_ifindex;
#endif /*DLNA_DMS_SUPPORT_IF_STORAGE_FILTER*/

  /* Interface name.  */
  slim_char *name;

  /* Interface description.  */
  slim_char *desc;

#if defined (DEVELOPMENT_ENABLE_LPE) || defined (DEVELOPMENT_ENABLE_LPC)
  /* WakeOnPattern. */
  slim_char *wop;
  /* WakeSupportedTransport. */
  slim_int wst;
  /* MaxWaitOnDelay.  */
  slim_int wod;
  /* DozeDuration.  */
  slim_int doze;
#endif

  /* Interface flags.
   * bit  0 -  7: interface status
   * bit  8 - 15: interface type (for EMS)
   * bit 16 - 24: interface mode (for EMS)
   */
  slim_word flags;
#define UPNP_IF_UP            (1 << 0)
#define UPNP_IF_MULTICAST     (1 << 1)
#define UPNP_IF_UPNP_UP       (1 << 2)
#define UPNP_IF_UPNP_RUNNING  (1 << 3)
#define UPNP_IF_LOOPBACK      (1 << 4)
#define UPNP_IF_BROADCAST     (1 << 5)
#define UPNP_IF_POINTOPOINT   (1 << 6)
#define UPNP_IF_TYPE_ETHERNET           (1 << 8)
#define UPNP_IF_TYPE_WI_FI              (1 << 9)
#define UPNP_IF_TYPE_HOME_PNAOVER_COAX  (1 << 10)
#define UPNP_IF_TYPE_HOME_PLUG          (1 << 11)
#define UPNP_IF_TYPE_MOCA               (1 << 12)
#define UPNP_IF_TYPE_1905               (1 << 13)
#define UPNP_IF_TYPE_OTHER              (1 << 14)
#define UPNP_IF_MODE_UNIMPLEMENTED              (1 << 16)
#define UPNP_IF_MODE_IP_UP                      (1 << 17)
#define UPNP_IF_MODE_IP_UP_PERIODIC             (1 << 18)
#define UPNP_IF_MODE_IP_DOWN_NO_WAKE            (1 << 19)
#define UPNP_IF_MODE_IP_DOWN_WITH_WAKE_ON       (1 << 20)
#define UPNP_IF_MODE_IP_DOWN_WITH_WAKE_AUTO     (1 << 21)
#define UPNP_IF_MODE_IP_DOWN_WITH_WAKE_ON_AUTO  (1 << 22)

  /* MAC address.  */
  slim_byte mac[DLNA_ETHER_ADDR_LEN];

  /* Addresses.  */
  List(struct upnp_address *) ipv4;

  /* SSDP information.  */
  void *ssdp;

  /* Member functions.  */
  slim_int (*is_up) (struct upnp_interface *);
  slim_int (*is_multicast) (struct upnp_interface *);
  slim_int (*is_upnp_up) (struct upnp_interface *);
  slim_int (*is_upnp_running) (struct upnp_interface *);
  slim_int (*is_loopback) (struct upnp_interface *);
  slim_int (*is_ethernet) (struct upnp_interface *);
  slim_int (*is_wifi) (struct upnp_interface *);
  slim_int (*is_broadcast) (struct upnp_interface *);
  slim_int (*is_pointopoint) (struct upnp_interface *);
  slim_int (*if_address_count) (struct upnp_interface *);
  struct upnp_address *(*if_primary_address) (struct upnp_interface *);
  struct upnp_address *(*if_linklocal_address) (struct upnp_interface *);
};

struct upnp_if_manager
{
  /* Event manager.  */
  dlna_progress em;

  /* Top back pointer.  */
  void *top;

  /* UPnP callback.  */
  upnp_callback_t upnp_ifm_callback;

  void *info;
  /* Interface vector.  */
  List (struct upnp_interface *) if_list;

  /* Callbacks.  */
  slim_int (*if_add) (struct upnp_if_manager *, struct upnp_interface *);
  slim_int (*if_delete) (struct upnp_if_manager *, struct upnp_interface *);
  slim_int (*if_up) (struct upnp_if_manager *, struct upnp_interface *);
  slim_int (*if_down) (struct upnp_if_manager *, struct upnp_interface *);
  slim_int (*if_address_up) (struct upnp_if_manager *, struct upnp_address *);
  slim_int (*if_address_down) (struct upnp_if_manager *, struct upnp_address *);
#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
  void (*if_assign_ifindex) (struct upnp_if_manager *, struct upnp_interface *);
  slim_int first_free_ifindex;
  slim_bool (*if_is_published) (struct upnp_if_manager *, slim_char *if_name);
#endif /*  DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */  
  
  List (struct upnp_netif_event *) upnp_netif_event_list;


};


struct upnp_netif_event
{
  struct upnp_netif_event *next;
  struct upnp_netif_event *prev;

  dlna_netif_event event;
  struct upnp_if_manager *ifm;
  dlna_progress_handle e_netif_event;

  union {
    dlna_interface i;
    dlna_prefix p;
  } u;
  
};

/* Macros.  */
#define UPNP_IF_NAME(I)                  ((I) ? (I)->name : (slim_char *) "(null)")

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct upnp_if_manager *
upnp_if_manager_alloc (dlna_progress em, void *top, upnp_callback_t callback, void *info);

void
upnp_if_manager_free (struct upnp_if_manager *ifm);

slim_int
dlnaNetIfAllocPeerCallbackProc(dlna_netif_event in_event, void *in_arg, void *in_param);

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
struct upnp_interface *
upnp_if_lookup_2(struct upnp_if_manager *ifm, slim_int ifindex);
#endif /*DLNA_DMS_SUPPORT_IF_STORAGE_FILTER*/

struct upnp_interface *
upnp_if_lookup (struct upnp_if_manager *ifm, slim_int ifindex);

struct upnp_interface *
upnp_if_lookup_by_address (struct upnp_if_manager *ifm, struct upnp_address *a);

#ifdef DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
dlna_ip_addr
upnp_if_apply_mask (struct upnp_address *a);
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */

struct upnp_interface *
upnp_if_lookup_by_dest (struct upnp_if_manager *ifm, struct upnp_address *a);

#if defined DLNA_DMS_SUPPORT_IF_STORAGE_FILTER
struct upnp_interface *
upnp_if_lookup_by_ifname(struct upnp_if_manager *ifm, slim_char *in_ifname);
#endif /* DLNA_DMS_SUPPORT_IF_STORAGE_FILTER */

struct upnp_interface *
upnp_if_lookup_by_socket (struct upnp_if_manager *ifm, slim_int sock);

struct upnp_address *
upnp_if_primary_address_by_ifindex (struct upnp_if_manager *ifm, slim_int ifindex);

slim_int
upnp_if_down(struct upnp_interface *ifp);

slim_int
upnp_if_up(struct upnp_interface *ifp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_INTERFACE_H */
