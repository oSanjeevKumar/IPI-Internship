/*
 * contents_xml_cds.h
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

#ifndef NFLC_CONTENTS_XML_CDS_H
#define NFLC_CONTENTS_XML_CDS_H

#include <nflc_upnp.h>
#include <nflc_contents.h>
#include <contents_xml.h>
#include "http_session.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

typedef enum container_playlist_type{
  CONTAINER_TYPE_M3U,
  CONTAINER_TYPE_M3U8,
  CONTAINER_TYPE_PLS,
  CONTAINER_TYPE_WPL
}contents_container_type_t;

slim_int
contents_xml_body (cm_t *cm, struct sbuf *sbuf,
            contents_t *c, extended_flags_t * ext_flags);

void
contents_xml_filter_check (slim_char *filter, extended_flags_t *ext_flags);

slim_int
contents_xml_sort_check (slim_char *sort);


#if defined(DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION) && defined(ENABLE_SUBTITLE_SUPPORT)

void
contents_xml_video_subtitle_info_default (cm_t *cm, contents_t* c, video_subtitle_t *video_subtitle, struct sbuf *sbuf, slim_int ifindex, extended_flags_t * ext_flags);

#if defined(DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE) || defined(DEVELOPMENT_SAMSUNG_SUBTITLE)
void
content_xml_desc_header_empty(struct sbuf *sbuf,slim_char *in_resURI);

void
content_xml_desc_footer_empty(struct sbuf *sbuf);
#endif /* defined(DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE) || defined(DEVELOPMENT_SAMSUNG_SUBTITLE) */

#ifdef DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE
void
contents_xml_video_subtitle_info_wd_tv_live_hub (cm_t *cm, contents_t* c, video_subtitle_t *video_subtitle, struct sbuf *sbuf, slim_int ifindex, extended_flags_t * ext_flags);

void
contents_xml_video_subtitle_res_empty (cm_t *cm, contents_t* c, video_subtitle_t *video_subtitle, struct sbuf *sbuf, slim_int ifindex, extended_flags_t * ext_flags);
#endif /* DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE */

#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
void
contents_xml_video_subtitle_for_samsung_tv_res (cm_t *cm, contents_t* c, video_subtitle_t *video_subtitle, struct sbuf *sbuf, slim_int ifindex, extended_flags_t * ext_flags);
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */

#endif /* defined(DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION) && defined(ENABLE_SUBTITLE_SUPPORT) */

#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION
void
contents_xml_audio_default_res (cm_t *cm, struct sbuf *sbuf, contents_t *contents, slim_int ifindex, extended_flags_t * ext_flags, pinfo_t* pinfo);

void
contents_xml_audio_wav_res (cm_t *cm, struct sbuf *sbuf, contents_t *contents, slim_int ifindex, extended_flags_t * ext_flags, pinfo_t* pinfo);

void
contents_xml_audio_wav_res_xmrr (cm_t *cm, struct sbuf *sbuf, contents_t *contents, slim_int ifindex, extended_flags_t * ext_flags, pinfo_t* pinfo);

#endif /*DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION*/

slim_char *
id_delim_to_hex(slim_char *in_uri, slim_int *size);

void
content_xml_escape_id(slim_char *in_id, struct sbuf* sbuf);

slim_bool
#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION
contents_is_container_searchable(contents_t *c, extended_flags_t * ext_flags);
#else /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
contents_is_container_searchable(contents_t *c);
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_CONTENTS_XML_CDS_H */
