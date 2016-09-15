/*
 * info_flv_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* FLV file support defs for NFLC. */

#ifndef NFLC_INFO_FLV_DEF_H
#define NFLC_INFO_FLV_DEF_H

/*#define FLV_DEBUG*/ /* Debug mode */

/* File suffixes */
#define FLV_SUFF_STR "flv"

/* MIME type strings */
#define FLV_MIMETYPE_STR "video/x-flv"

/* DLNA profile strings (not defined by DLNA yet. ZZZ) */
#define FLV_PROF_STR "FLV"

/* DLNA pinfo strings */
#ifdef MEDIA_PROCESSING_EXTENSION
#define FLV_PINFO_STR "http-get:*:" FLV_MIMETYPE_STR ":DLNA.ORG_OP=11;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
#else /* MEDIA_PROCESSING_EXTENSION */
#define FLV_PINFO_STR "http-get:*:" FLV_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
#endif /* MEDIA_PROCESSING_EXTENSION */
//#define FLV_PINFO_STR "http-get:*:" FLV_MIMETYPE_STR ":" FLV_PROF_STR ";DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */

#endif /* NFLC_INFO_FLV_DEF_H */
