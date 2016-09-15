/*
 * upnp_radacp.h
 * Copyright (C) 2015 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* UPnP Printer Control Point.  */

#ifndef _UPNP_RADACP_H
#define _UPNP_RADACP_H


/* UPnP RADA Control Point.  */
struct upnp_radacp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_radacp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);
void
upnp_radacp_free (struct upnp_cp *cp);
slim_int
upnp_radacp_sync_add_remote_devices (struct upnp_device *device, slim_char *in_uuid, TRADASyncDeviceInfo in_infos[], slim_int in_count, void *in_session_data);
slim_int
upnp_radacp_sync_remove_remote_devices (struct upnp_device *device, slim_char *in_uuid, TRADASyncDeviceInfo in_infos[], slim_int in_count, void *in_session_data);
slim_int
upnp_radacp_sync_set_ddd_location (struct upnp_device *device, slim_char *in_uuid, slim_char *in_ddd_location, void *in_session_data) ;
slim_int
upnp_radacp_sync_heartbeat_update (struct upnp_device *device, slim_char *in_uuid, void *in_session_data) ;
slim_int
upnp_radacp_sync_query (struct upnp_device *device, void *in_session_data, slim_char *in_var_name);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* _UPNP_RADACP_H */
