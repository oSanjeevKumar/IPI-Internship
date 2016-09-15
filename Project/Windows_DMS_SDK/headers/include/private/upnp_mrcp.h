/*
 * upnp_mrcp.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* UPnP Media Renderer Control Point.  */

#ifndef NFLC_UPNP_MRCP_H
#define NFLC_UPNP_MRCP_H

/* UPnP Media Renderer Control Point.  */
struct upnp_mrcp
{
  /* Control point base structure.  */
  struct upnp_cp base;

  /* Local renderer XML document.  */
  sXML *device_doc;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
upnp_mrcp_avts_query (struct upnp_transport *ut, slim_char *in_var_name,
                      slim_char *id);

/* UPnP AVTransport:1 2.4.1 SetAVTransportURI.  */
slim_int
upnp_mrcp_avts_set_uri (struct upnp_transport *ut, slim_char *id,
                        sXML_Element *res);

/* UPnP AVTransport:1 2.4.2 SetNextAVTransportURI.  */
slim_int
upnp_mrcp_avts_set_next_uri (struct upnp_transport *ut, slim_char *id,
                        sXML_Element *res);

/* UPnP AVTransport:1 2.4.3 GetMediaInfo.  */
slim_int
upnp_mrcp_avts_get_media_info (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.4 GetTransportInfo.  */
slim_int
upnp_mrcp_avts_get_transport_info (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.5 GetPositionInfo.  */
slim_int
upnp_mrcp_avts_get_position_info (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.8 Stop.  */
slim_int
upnp_mrcp_avts_stop (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.9 Play.  */
slim_int
upnp_mrcp_avts_play (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.10 Pause.  */
slim_int
upnp_mrcp_avts_pause (struct upnp_transport *ut, slim_char *id);

#ifdef HAVE_WMDRM
/* UPnP AVTransport:1 2.4.11 SeekTime.  */
slim_int
upnp_mrcp_avts_seektime (struct upnp_transport *ut, slim_char *id);
#endif /* HAVE_WMDRM */

/* UPnP AVTransport:1 2.4.12 seek.  */
slim_int
upnp_mrcp_avts_seek (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.13 Next.  */
slim_int
upnp_mrcp_avts_next (struct upnp_transport *ut, slim_char *id);

/* UPnP AVTransport:1 2.4.14 Previous.  */
slim_int
upnp_mrcp_avts_previous (struct upnp_transport *ut, slim_char *id);

#ifdef USE_TRICK_PLAY
/* fast foward */
slim_int
upnp_mrcp_avts_fastfoward (struct upnp_transport *ut, slim_char *id);

/* rewind */
slim_int
upnp_mrcp_avts_rewind (struct upnp_transport *ut, slim_char *id);
#endif /* USE_TRICK_PLAY */

/* UPnP RenderingControl:1 2.4.1  ListPresets. */
slim_int
upnp_mrcp_rcs_list_presets(struct upnp_device *in_device, slim_char *in_instance_id);

/* UPnP RenderingControl:1 2.4.2  SelectPreset. */
slim_int
upnp_mrcp_rcs_select_preset(struct upnp_device *in_device, 
                            slim_char *in_instance_id, 
                            slim_char *in_preset_name);

/* UPnP RenderingControl:1 2.4.27 GetMute. */
slim_int
upnp_mrcp_rcs_get_mutestate(struct upnp_device *in_device, 
                            slim_char *in_instance_id,
                            slim_char *in_channel);

/* UPnP RenderingControl:1 2.4.28 SetMute. */
slim_int
upnp_mrcp_rcs_set_mutestate(struct upnp_device *in_device, 
                            slim_char *in_instance_id, 
                            slim_char *in_channel, 
                            slim_bool in_mute);

/* UPnP RenderingControl:1 2.4.29 GetVolume. */
slim_int
upnp_mrcp_rcs_get_volume(struct upnp_device *in_device, 
                         slim_char *in_instance_id,
                         slim_char *in_channel);

/* UPnP RenderingControl:1 2.4.30 SetVolume. */
slim_int
upnp_mrcp_rcs_set_volume(struct upnp_device *in_device, 
                         slim_char *in_instance_id, 
                         slim_char *in_channel, 
                         slim_int in_volume);

slim_int
upnp_mrcp_rcs_get_volume_db(struct upnp_device *in_device,
                           slim_char *in_instance_id,
                           slim_char *in_channel);

slim_int
upnp_mrcp_rcs_get_volume_db_range(struct upnp_device *in_device,
                                 slim_char *in_instance_id,
                                 slim_char *in_channel);

slim_int
upnp_mrcp_rcs_set_volume_db(struct upnp_device *in_device,
                           slim_char *in_instance_id,
                           slim_char *in_channel,
                           slim_int in_volume_db);

slim_int
upnp_mrcp_cms_get_protocol_info (struct upnp_device *in_device);

slim_int
upnp_mrcp_cms_get_current_connection_ids (struct upnp_device *in_device) ;

slim_int 
upnp_mrcp_alloc (struct upnp_client *uc, struct upnp_cp **out_cp);

void
upnp_mrcp_free (struct upnp_cp *cp);

slim_int
upnp_mrcp_startup_local_renderer (struct upnp_cp *cp);

#if defined (RA_USE_RID_HEADER) 
slim_int
upnp_mrcp_propagate_permission (struct upnp_device *device, void *session_param, slim_char *in_rid, slim_word in_permission) ;
slim_int
upnp_mrcp_revoke_permission (struct upnp_device *device, void *session_param, slim_char *in_rid) ;
#endif /* #if defined (RA_USE_RID_HEADER) */

#ifdef DLNA_SUPPORT_PROVISIONING 
slim_int
upnp_mrcp_propagate_properties (struct upnp_device *device, void *session_param, slim_char *in_properties) ;
#endif //#ifdef DLNA_SUPPORT_PROVISIONING 


#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif /* NFLC_UPNP_MRCP_H */
