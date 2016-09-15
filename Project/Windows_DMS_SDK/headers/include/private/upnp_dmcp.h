/*
 * upnp_dmcp.h
 * Copyright (C) 2007-2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* UPnP Device Management Control Point.  */

#ifndef NFLC_UPNP_DMCP_H
#define NFLC_UPNP_DMCP_H

/* UPnP Device Management Control Point.  */
struct upnp_dmcp
{
  /* Control point base structure.  */
  struct upnp_cp base;

  /* Local renderer XML document.  */
  sXML *device_doc;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* UPnP BasicManagement:2 2.5.3 GetDeviceStatus */
slim_int
upnp_dmcp_bms_get_device_status (struct upnp_device *in_device);

/* UPnP BasicManagement:2 2.5.6 Ping */
slim_int
upnp_dmcp_bms_ping (struct upnp_device *in_device,
                    slim_char *in_host,
                    slim_char *in_count,
                    slim_char *in_timeout,
                    slim_char *in_block,
                    slim_char *in_dscp);

/* UPnP BasicManagement:2 2.5.7 GetPingResult */
slim_int
upnp_dmcp_bms_get_ping_result (struct upnp_device *in_device, slim_char *in_id);

/* UPnP BasicManagement:2 2.5.8 NSLookup */
slim_int
upnp_dmcp_bms_nslookup (struct upnp_device *in_device,
                        slim_char *in_host,
                        slim_char *in_server,
                        slim_char *in_count,
                        slim_char *in_timeout);

/* UPnP BasicManagement:2 2.5.9 GetNSLookupResult */
slim_int
upnp_dmcp_bms_get_nslookup_result (struct upnp_device *in_device, slim_char *in_id);

/* UPnP BasicManagement:2 2.5.10 Traceroute */
slim_int
upnp_dmcp_bms_traceroute (struct upnp_device *in_device,
                          slim_char *in_host,
                          slim_char *in_timeout,
                          slim_char *in_block,
                          slim_char *in_count,
                          slim_char *in_dscp);

/* UPnP BasicManagement:2 2.5.11 GetTracerouteResult */
slim_int
upnp_dmcp_bms_get_traceroute_result (struct upnp_device *in_device, slim_char *in_id);

/* UPnP BasicManagement:2 2.5.19 GetTestIDs */
slim_int
upnp_dmcp_bms_get_test_ids (struct upnp_device *in_device);

/* UPnP BasicManagement:2 2.5.20 GetActiveTestIDs */
slim_int
upnp_dmcp_bms_get_active_test_ids (struct upnp_device *in_device);

/* UPnP BasicManagement:2 2.5.21 GetTestInfo */
slim_int
upnp_dmcp_bms_get_test_info (struct upnp_device *in_device, slim_char *in_id);

/* UPnP BasicManagement:2 2.5.22 CancelTest */
slim_int
upnp_dmcp_bms_cancel_test (struct upnp_device *in_device, slim_char *in_id);

/* Control point allocate */
slim_int 
upnp_dmcp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

/* Control point de-allocate */
void
upnp_dmcp_free (struct upnp_cp *cp);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_UPNP_DMCP_H */
