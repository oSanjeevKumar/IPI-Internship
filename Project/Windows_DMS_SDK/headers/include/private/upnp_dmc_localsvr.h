/*
 * upnp_dmc_localsvr.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Local Server for UPnP DMC  */

#ifndef UPNP_DMC_LOCALSVR_H
#define UPNP_DMC_LOCALSVR_H

slim_opaque
upnp_dmc_localsvr_alloc (dlna_progress em, slim_char *in_config_dir);

void
upnp_dmc_localsvr_free (slim_opaque in_localsvr);

slim_int
upnp_dmc_localsvr_start (slim_opaque in_localsvr);

slim_int
upnp_dmc_localsvr_stop (slim_opaque in_localsvr);

slim_int
upnp_dmc_localsvr_get_port(slim_opaque in_localsvr, slim_int *out_port);

slim_int
upnp_dmc_localsvr_content_add (slim_opaque in_localsvr, slim_char *in_content_file_path, slim_char *in_content_pinfo, slim_opaque in_album_art, slim_opaque *out_media_context, slim_char ** out_content_uri);

slim_int
upnp_dmc_localsvr_content_remove (slim_opaque in_localsvr, slim_opaque in_media_context);

slim_int
upnp_dmc_localsvr_content_remove_by_url (slim_opaque in_localsvr, slim_opaque in_media_context, slim_char * in_url);

slim_char*
upnp_dmc_localsvr_content_get_filepath(slim_opaque in_localsvr, slim_opaque in_media_context);

slim_char*
upnp_dmc_localsvr_content_get_albumart_url(slim_opaque in_localsvr, slim_opaque in_media_context, slim_char **out_album_art_med_url);

#endif /* UPNP_DMC_LOCALSVR_H */
