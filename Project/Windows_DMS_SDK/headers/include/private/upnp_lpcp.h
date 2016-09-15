/*
 * upnp_lpcp.h
 * Copyright (C) 2007-2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* UPnP Low Power Control Point.  */

#ifndef NFLC_UPNP_LPCP_H
#define NFLC_UPNP_LPCP_H

/* UPnP Low Power Control Point.  */
struct upnp_lpcp
{
  /* Control point base structure.  */
  struct upnp_cp base;

  /* Local renderer XML document.  */
  sXML *device_doc;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* UPnP EnergyManagement:1 5.5.2 GetInterfaceInfo */
slim_int
upnp_lpcp_ems_get_interface_info (struct upnp_device *in_device);

#ifdef DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION

/* UPnP EnergyManagement:1 5.5.3 ServiceSubscription */
slim_int
upnp_lpcp_ems_service_subscription (struct upnp_device *in_device,
		                             slim_char *in_uniqueServiceName,
							         slim_char *in_resourceUri,
							         slim_char *in_durationRequest);

/* UPnP EnergyManagement:1 5.5.4 ServiceRenewal */
slim_int
upnp_lpcp_ems_service_renewal (struct upnp_device *in_device,
						        slim_char *in_durationRequest,
		                        slim_char *in_serviceSubscriptionID);

/* UPnP EnergyManagement:1 5.5.5 ServiceRelease */
slim_int
upnp_lpcp_ems_service_release (struct upnp_device *in_device,
		                        slim_char *in_serviceSubscriptionID);

#endif /* DEVELOPMENT_ENABLE_ENERGY_MANAGEMENT_SUBSCRIPTION */

/* Control point allocate */
slim_int 
upnp_lpcp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

/* Control point de-allocate */
void
upnp_lpcp_free (struct upnp_cp *cp);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_UPNP_LPCP_H */
