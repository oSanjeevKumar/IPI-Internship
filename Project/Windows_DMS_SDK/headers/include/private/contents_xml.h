/*
 * contents_xml.h
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

#ifndef NFLC_CONTENTS_XML_H
#define NFLC_CONTENTS_XML_H

#include <nflc_upnp.h>
#include <nflc_contents.h>

/* DMS contents manager.  */

/* Browsing flags.  */
#define CONTENTS_XML_FLAG_META               (1 << 0)
#define CONTENTS_XML_FLAG_CHILD              (1 << 1)
#define CONTENTS_XML_FLAG_ID                 (1 << 2)
#define CONTENTS_XML_FLAG_ALLIP              (1 << 3)
#define CONTENTS_XML_FLAG_CHILD_COUNT        (1 << 5)
#define CONTENTS_XML_FLAG_REF_ID             (1 << 6)
#define CONTENTS_XML_FLAG_SEARCHABLE         (1 << 7)
#define CONTENTS_XML_FLAG_DLNAMANAGED        (1 << 8)
#define CONTENTS_XML_FLAG_UPNP_ALBUM         (1 << 9)
#define CONTENTS_XML_FLAG_UPNP_GENRE         (1 << 10)
#define CONTENTS_XML_FLAG_UPNP_ARTIST        (1 << 11)
#define CONTENTS_XML_FLAG_UPNP_TRACK_NUMBER  (1 << 12)
#define CONTENTS_XML_FLAG_UPNP_SEARCH_CLASS  (1 << 13)
#define CONTENTS_XML_FLAG_UPNP_CREATE_CLASS  (1 << 14)
#define CONTENTS_XML_FLAG_DC_DATE            (1 << 15)
#define CONTENTS_XML_FLAG_DC_CREATOR         (1 << 16)
#define CONTENTS_XML_FLAG_RES                (1 << 17)
#define CONTENTS_XML_FLAG_RES_SIZE           (1 << 18)
#define CONTENTS_XML_FLAG_RES_RESOLUTION     (1 << 19)
#define CONTENTS_XML_FLAG_RES_DURATION       (1 << 20)
#define CONTENTS_XML_FLAG_RES_BITRATE        (1 << 21)
#define CONTENTS_XML_FLAG_RES_SAMPLE_RATE    (1 << 22)
#define CONTENTS_XML_FLAG_RES_AUDIO_CHANNELS (1 << 23)
#define CONTENTS_XML_FLAG_RES_PINFO          (1 << 24)
#define CONTENTS_XML_FLAG_RES_IMPORT_URI     (1 << 25)
#define CONTENTS_XML_FLAG_RES_NOCHECK_LOOPBACK (1 << 26)
#define CONTENTS_XML_FLAG_RES_UNUSE_LOOPBACK   (1 << 27) 
#define CONTENTS_XML_FLAG_UPNP_ALBUMARTURI   (1 << 28) 
#define CONTENTS_XML_FLAG_UPNP_OBJECT_UPDATE_ID (1 << 29)
#define CONTENTS_XML_FLAG_UPNP_CONTAINER_UPDATE_ID (1 << 30)
#define CONTENTS_XML_FLAG_UPNP_TOTAL_DELETED_CHILD_COUNT (1 << 31)

#define CONTENTS_XML_EXTENDED_FLAG_ALL (1 << 0)
#define CONTENTS_XML_EXTENDED_FLAG_REFID (1 << 1)
#define CONTENTS_XML_EXTENDED_FLAG_UPNP_RATING (1 << 2)
#define CONTENTS_XML_EXTENDED_FLAG_UPNP_COMPOSER (1 << 3)
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus__ */

void
contents_xml_didl_header (struct sbuf *sbuf);

void
content_xml_didl_header_with_customizations (struct sbuf *in_sbuf,  extended_flags_t * ext_flags);

void
contents_xml_no_dlnanamespace_didl_header (struct sbuf *sbuf);

void
contents_xml_didl_footer (struct sbuf *sbuf);

void
contents_xml_item_for_dmu (struct sbuf *sbuf, slim_char *in_id, slim_char *in_parent_id, void *in_up_param);

void
contents_xml_container_for_dmu (struct sbuf *sbuf, slim_char *in_id, slim_char *in_parent_id, void *in_up_param);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_CONTENTS_XML_H */
