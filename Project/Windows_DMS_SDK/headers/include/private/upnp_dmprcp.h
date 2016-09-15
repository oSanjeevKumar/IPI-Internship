/*
 * upnp_dmprcp.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
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

#ifndef _UPNP_DMPrCP_H
#define _UPNP_DMPrCP_H

/* UPnP Printer Control Point.  */
struct upnp_dmprcp
{
  /* Control point base structure.  */
  struct upnp_cp base;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_dmprcp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_dmprcp_free (struct upnp_cp *cp);
slim_int
upnp_dmprcp_create_uri_job (struct upnp_device *device, 
                slim_char *in_job_name, slim_char *in_doc_format, slim_int in_copies,
                upnp_dmpr_orientation in_orientation, slim_char *in_media_size,
                slim_char *in_media_type, slim_char *in_source_uri, upnp_dmpr_quality in_quality, void *in_session_data);

slim_int
upnp_dmprcp_create_jobv2 (struct upnp_device *device, TDLNAObjectDmprParam *param, void *in_session_data) ;
slim_int
upnp_dmprcp_get_media_list (struct upnp_device *device, slim_char *in_media_size, slim_char *in_media_type, void *in_session_data) ;
slim_int
upnp_dmprcp_get_margins (struct upnp_device *device, slim_char *in_media_size, slim_char *in_media_type, void *in_session_data) ;
slim_int
upnp_dmprcp_cancel_job (struct upnp_device *device, slim_int in_job_id, void *in_session_data);
slim_int
upnp_dmprcp_get_printer_attributes (struct upnp_device *device,void *in_session_data);
#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* _UPNP_DMPrCP_H */
