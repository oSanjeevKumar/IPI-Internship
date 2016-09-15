/*
 * upnp_rascp.h
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

/* UPnP RAS Control Point.  */

#ifndef _UPNP_RASCP_H
#define _UPNP_RASCP_H


/* UPnP RAS Control Point.  */
struct upnp_rascp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_rascp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_rascp_free (struct upnp_cp *cp);

slim_int
upnp_rascp_query (struct upnp_device *device, void *in_session_data, slim_char *in_var_name);

/* RADA Config */
slim_int
upnp_rascp_radaconfig_get_system_info (struct upnp_device *device, void *id, void *in_session_data) ;
slim_int
upnp_rascp_radaconfig_edit_filter (struct upnp_device *device, slim_char *in_uuid, slim_char *in_target, slim_char *in_control_mode, slim_char *in_update_type, slim_char *in_access_credential_id, void *in_session_data) ;

/* KK add for RA:2
CreateVirtualDevice()
GetVirtualDevices()
DestroyVirtualDevices()
*/

/* InboundConnectionConfig */
typedef struct _ICC_Config_Info
{
	slim_char *dyn_dns_protocol ;
	slim_char *ip_addr ;
	slim_char *user_name ;
	slim_char	*password ;
	slim_char	*domain ;
	slim_char	*uri ;
	slim_char	*update_interval ;
} TICC_Config_Info;

slim_int
upnp_rascp_icc_get_dynamic_dns_supported_protocols (struct upnp_device *device, void *in_session_data) ;
slim_int
upnp_rascp_icc_set_dynamic_dns_config_info (struct upnp_device *device, TICC_Config_Info *in_config_info, void *in_session_data) ;
slim_int
upnp_rascp_icc_set_stun_server_address (struct upnp_device *device, slim_char *out_protocols, void *in_session_data) ;
slim_int
upnp_rascp_icc_get_network_topology_info (struct upnp_device *device, slim_char *out_protocols, void *in_session_data) ;


/* RATAConfig is in separate file as it is as well used by the RAClient device */


#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* _UPNP_RASCP_H */
