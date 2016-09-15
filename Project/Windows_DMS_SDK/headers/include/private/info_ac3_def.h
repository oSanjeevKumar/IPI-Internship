/*
 * info_ac3_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* AC-3 file support defs for NFLC. */

#ifndef NFLC_INFO_AC3_DEF_H
#define NFLC_INFO_AC3_DEF_H

/* #define AC3_DEBUG */ /* Debug mode */

/* File suffixes */
#define AC3_SUFF_STR "ac3"

/* MIME type strings */
//#define AC3_MIMETYPE_STR "audio/ac3"
#define AC3_MIMETYPE_STR "audio/vnd.dolby.dd-raw"

/* DLNA profile strings */
#define AC3_PROF_STR "AC3"

/* DLNA pinfo strings */
//#define AC3_PINFO_STR "http-get:*:" AC3_MIMETYPE_STR ":" "DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
#ifdef MEDIA_PROCESSING_EXTENSION
#define AC3_PINFO_STR "http-get:*:" AC3_MIMETYPE_STR ":DLNA.ORG_PN=" AC3_PROF_STR ";DLNA.ORG_OP=11;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
#else /* MEDIA_PROCESSING_EXTENSION */
#define AC3_PINFO_STR "http-get:*:" AC3_MIMETYPE_STR ":DLNA.ORG_PN=" AC3_PROF_STR ";DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
#endif /* MEDIA_PROCESSING_EXTENSION */

#endif /* NFLC_INFO_AC3_DEF_H */
