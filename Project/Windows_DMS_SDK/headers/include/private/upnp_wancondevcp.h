/*
 * upnp_wancondevcp.h
 * Copyright (C) 2007 - 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* UPnP WANConnectionDevice Control Point.  */

#ifndef _UPNP_WANCONDEVCP_H
#define _UPNP_WANCONDEVCP_H


/* UPnP WCD Control Point.  */
struct upnp_wcdcp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_wcdcp_get_external_ip_address (struct upnp_device *device, void *in_session_data) ;

struct upnp_cp *
upnp_wcdcp_alloc (struct upnp_client *uc);

void
upnp_wcdcp_free (struct upnp_cp *cp);

slim_int
upnp_wcdcp_query (struct upnp_device *device, void *in_session_data, slim_char *in_var_name);
#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* _UPNP_WANCONDEVCP_H */
