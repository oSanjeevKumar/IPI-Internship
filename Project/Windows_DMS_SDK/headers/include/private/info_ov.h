/*
 * info_ov.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Ogg Vorbis file support for NFLC. */

#ifndef NFLC_INFO_OV_H
#define NFLC_INFO_OV_H

#include <info_ov_def.h> /* Import defs */

#define EMBEDDED_ALBUM_ART_URI_PREFIX_OGG  "/embeddedOGG"DEFAULT_DMSCONFIG_ID_DELIM

slim_bool register_media_info_ov(media_manager_t *mim);
slim_char*
get_ov_embedded_album_art_uri(slim_char* full_path, albumArtImage **embedded_image);
#endif /* NFLC_INFO_OV_H */
