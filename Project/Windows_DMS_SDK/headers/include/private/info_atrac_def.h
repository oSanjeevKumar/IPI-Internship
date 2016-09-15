/*
 * info_atrac_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* ATRAC file support defs for NFLC. */

#ifndef NFLC_INFO_ATRAC_DEF_H
#define NFLC_INFO_ATRAC_DEF_H

/*#define ATRAC_DEBUG*/ /* Debug mode */

/* File suffixes */
#define ATRAC_SUFF_STR "oma"
#define ATRAC_SUFF_STR_2 "aa3"

/* MIME type strings */
#define ATRAC_MIMETYPE_STR "audio/x-sony-oma"
//#define ATRAC_MIMETYPE_STR "audio/oma"

/* DLNA profile strings */
#define ATRAC_PROF_STR "ATRAC3plus"

/* DLNA pinfo strings */
//#define ATRAC_PINFO_STR "http-get:*:" ATRAC_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
#ifdef MEDIA_PROCESSING_EXTENSION
#define ATRAC_PINFO_STR "http-get:*:" ATRAC_MIMETYPE_STR ":DLNA.ORG_PN=" ATRAC_PROF_STR ";DLNA.ORG_OP=11;DLNA.ORG_CI=0"  /* Should examine params : ZZZ */
#else /* MEDIA_PROCESSING_EXTENSION */
#define ATRAC_PINFO_STR "http-get:*:" ATRAC_MIMETYPE_STR ":DLNA.ORG_PN=" ATRAC_PROF_STR ";DLNA.ORG_OP=01;DLNA.ORG_CI=0"  /* Should examine params : ZZZ */
#endif /* MEDIA_PROCESSING_EXTENSION */

#endif /* NFLC_INFO_ATRAC_DEF_H */
