/*
 * upnp_ruiscp.h
 * Copyright (C) 2007-2014 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* UPnP RemoteUI Server Control Point.  */

#ifndef _UPNP_RUISCP_H
#define _UPNP_RUISCP_H

/* UPnP Media Server Control Point.  */
struct upnp_ruiscp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_ruiscp_level1_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_ruiscp_level1_free (struct upnp_cp *cp);


slim_int
upnp_ruiscp_level2_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_ruiscp_level2_free (struct upnp_cp *cp);


slim_int
upnp_ruiscp_get_compatible_uis (struct upnp_device *device, slim_char *profile, void *in_session_data) ;

slim_int
upnp_ruiscp_set_ui_lifetime (struct upnp_device *in_device, void *in_session_data, slim_char *in_ui, slim_char *in_lifetime);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* _UPNP_RUISCP_H */
