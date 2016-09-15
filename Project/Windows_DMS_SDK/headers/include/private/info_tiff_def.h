/*
 * info_tiff_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The abtiffe copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* TIFF file support defs for NFLC. */

#ifndef NFLC_INFO_TIFF_DEF_H
#define NFLC_INFO_TIFF_DEF_H

/* #define TIFF_DEBUG */ /* Debug mode */

/* File suffixes */
#define TIFF_SUFF_STR "tif"
#define TIFF_SUFF_STR_2 "tiff"

/* MIME type strings */
#define TIFF_MIMETYPE_STR "image/tiff"

/* DLNA profile strings */
#define TIFF_PROF_STR "TIFF" /* Not defined by DLNA : ZZZ */

/* DLNA pinfo strings */
#define TIFF_PINFO_STR "http-get:*:" TIFF_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0" PROTOCOL_INFO_DLNA_ORG_FLAGS_FOR_IMAGE/* Should examine params : ZZZ */

#endif /* NFLC_INFO_TIFF_DEF_H */
