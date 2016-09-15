/*
 * upnp_ratacp.h
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

/* UPnP RATA Control Point.  */

#ifndef _UPNP_RATACP_H
#define _UPNP_RATACP_H


/* UPnP RATA Control Point.  */
struct upnp_ratacp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_ratacp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_ratacp_free (struct upnp_cp *cp);

slim_int
upnp_ratacp_get_transport_agent_capabilities (struct upnp_device *device, void *in_session_data);
slim_int
upnp_ratacp_get_supported_credential_delivery (struct upnp_device *device, void *in_session_data);
slim_int
upnp_ratacp_get_credentials_list (struct upnp_device *device, void *in_session_data) ;
slim_int
upnp_ratacp_get_profile_list (struct upnp_device *device, void *in_session_data) ;
slim_int
upnp_ratacp_add_profile (struct upnp_device *device, slim_char *in_profile, void *in_session_data) ;
slim_int
upnp_ratacp_edit_profile (struct upnp_device *device, slim_char *in_profile_id, slim_char *in_profile, void *in_session_data) ;
slim_int
upnp_ratacp_delete_profile (struct upnp_device *device,  slim_char *in_profile_id, void *in_session_data) ;
slim_int
upnp_ratacp_get_profile_config_info (struct upnp_device *device, slim_char *in_profile_id, void *in_session_data) ;
slim_int
upnp_ratacp_query (struct upnp_device *device, slim_char *in_var_name, void *in_session_data);
#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* _UPNP_RATACP_H */
