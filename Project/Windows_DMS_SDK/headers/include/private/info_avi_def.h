/*
 * info_avi_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* AVI file support defs for NFLC. */

#ifndef NFLC_INFO_AVI_DEF_H
#define NFLC_INFO_AVI_DEF_H

/*#define AVI_DEBUG*/ /* Debug mode */

/* File suffixes */
#define AVI_SUFF_STR "avi"
#define DIVX_SUFF_STR "divx"

/* MIME type strings */
#define AVI_MIMETYPE_STR "video/avi"
/*#define AVI_MIMETYPE_STR "video/x-msvideo"*/ /* DiXiM does not support this type. */
/*#define AVI_MIMETYPE_STR "x-ms-avi"*/ /* Intel AV Renderer */
#define DIVX_MIMETYPE_STR "video/divx"
#define WAV_MIMETYPE_STR "audio/wav"

/* DLNA profile strings (not defined by DLNA yet. ZZZ) */
#define AVI_PROF_STR "AVI"
#define DIVX_PROF_STR "DivX"
#define WAV_PROF_STR "WAV"

/* DLNA pinfo strings */
#ifdef MEDIA_PROCESSING_EXTENSION
#define AVI_PINFO_STR "http-get:*:" AVI_MIMETYPE_STR ":DLNA.ORG_OP=11;DLNA.ORG_CI=0"/* Should examine params : ZZZ */
#define DIVX_PINFO_STR "http-get:*:" DIVX_MIMETYPE_STR ":DLNA.ORG_OP=11;DLNA.ORG_CI=0"
#else /* MEDIA_PROCESSING_EXTENSION */
#define AVI_PINFO_STR "http-get:*:" AVI_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0"/* Should examine params : ZZZ */
#define DIVX_PINFO_STR "http-get:*:" DIVX_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0"
#endif /* MEDIA_PROCESSING_EXTENSION */

#define WAV_PINFO_STR "http-get:*:" WAV_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */

/* FourCCs */
#	define FOURCC_DIV3 RIFF_MAKE_FCC('D', 'I', 'V', '3')
#	define FOURCC_DIV4 RIFF_MAKE_FCC('D', 'I', 'V', '4')
#	define FOURCC_DIVX RIFF_MAKE_FCC('D', 'I', 'V', 'X')
#	define FOURCC_DX50 RIFF_MAKE_FCC('D', 'X', '5', '0')
#endif /* NFLC_INFO_AVI_DEF_H */
