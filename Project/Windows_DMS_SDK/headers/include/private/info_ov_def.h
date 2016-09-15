/*
 * info_ov_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Ogg Vorbis file support defs for NFLC. */

#ifndef NFLC_INFO_OV_DEF_H
#define NFLC_INFO_OV_DEF_H

/* #define OV_DEBUG */ /* Debug mode */

/* File suffixes */
#define OV_SUFF_STR "ogg"

/* MIME type strings */

//#define OGG_AUDIO_MIMETYPE_STR "audio/ogg" /* Accepted by AV-LS300DW. */
#define OV_MIMETYPE_STR "application/ogg" /* Accepted by AV-LS300DW. */
//#define OV_MIMETYPE_STR "application/x-ogg"
//#define OV_MIMETYPE_STR "audio/x-vorbis"

/* DLNA profile strings */
#define OV_PROF_STR "OggVorbis" /* Not defined by DLNA : ZZZ */

/* DLNA pinfo strings */
//#define OV_PINFO_STR "http-get:*:" OV_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0;DLNA.ORG_FLAGS=00200000000000000000000000000000" /* Should examine params : ZZZ */
#define OV_PINFO_STR "http-get:*:" OV_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */

#endif /* NFLC_INFO_OV_DEF_H */
