/*
 * upnp_ems.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_UPNP_EMS_H
#define NFLC_UPNP_EMS_H

#include <dlna_peer.h>
#include <nflc_sxml.h>
#include <nflc_contents.h>
#include <upnp_interface.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef PARAMETER_NOT_USED
#define PARAMETER_NOT_USED(p) ((void)(p))
#endif /* PARAMETER_NOT_USED */

/* UPnP EnergyManagement:1 Service */
#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
struct upnp_ems_service_
{
  struct upnp_ems_service_ * next;
  struct upnp_ems_service_ * prev;
  slim_word serviceSubscriptionID;
  slim_char *duration;
  slim_char *uniqueServiceName;
  slim_char *resourceURI;
};
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */

typedef struct upnp_ems_service_ upnp_ems_service;

typedef void  (*upnp_ems_update_proc)(void *info);

typedef struct upnp_ems_
{
#ifdef HAVE_DMS
  /* Back-pointer to the top.  */
  struct dms *top;
#endif /* HAVE_DMS */
#ifdef HAVE_DMR
  struct dmr *top;
#endif /*HAVE_DMR*/

  /* Interface manager.  */
  struct upnp_if_manager *ifm;

  /* SOAP action.  */
  sXML *action_doc;

  /* SOAP result document.  */
  sXML *result_doc;

  void *info;

  /* Global service ID for service list */
  slim_word service_id;

  upnp_ems_update_proc update_callback;

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
  List(upnp_ems_service *)service_list;
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */

} upnp_ems;

/* memory alloc, free */
upnp_ems*
upnp_ems_alloc (struct upnp_if_manager *ifm, void *info, upnp_ems_update_proc in_update_callback);

slim_int
upnp_ems_free (upnp_ems *s);

/* UPnP EnergyManagement:1 5.5 Actions */
/* GetInterfaceInfo */
slim_int
upnp_ems_get_interface_info (upnp_ems *s);

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
/* ServiceSubscription */
slim_int
upnp_ems_service_subscription (upnp_ems *s);

/* ServiceRenewal */
slim_int
upnp_ems_service_renewal (upnp_ems *s);

/* ServiceRelease */
slim_int
upnp_ems_service_release (upnp_ems *s);
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */

/* UPnP EnergyManagement:1 5.3 State Variables */
/* NetworkInterfaeInfo */
slim_char *
upnp_ems_network_interface_info (upnp_ems *s);

/* ProxiedNetworkInterfaceInfo */
slim_char *
upnp_ems_proxied_network_interface_info (upnp_ems *s);

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION
/* A_ARG_TYPE_Duration */
slim_char *
upnp_ems_a_arg_type_duration (upnp_ems *s);

/* A_ARG_TYPE_ServiceSubscriptionID */
slim_char *
upnp_ems_a_arg_type_service_subscription_id (upnp_ems *s);

/* A_ARG_TYPE_UniqueServiceName */
slim_char *
upnp_ems_a_arg_type_unique_service_name (upnp_ems *s);

/* A_ARG_TYPE_URI */
slim_char *
upnp_ems_a_arg_type_uri (upnp_ems *s);
#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_EMS_H */

