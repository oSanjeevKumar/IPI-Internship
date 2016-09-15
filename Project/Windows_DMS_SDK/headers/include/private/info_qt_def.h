/*
 * info_qt_def.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* QuickTime file support defs for NFLC. */

#ifndef NFLC_INFO_QT_DEF_H
#define NFLC_INFO_QT_DEF_H

/* #define QT_DEBUG */ /* Debug mode */
#define QT_SUPPORT_INFO_I18N /* Support I18N info :  Not complete. ZZZ */

/* File suffixes */
#define QT_SUFF_STR "mov"
#define QT_SUFF_STR_2 "qt"

/* MIME type strings */
#define QT_MIMETYPE_STR "video/quicktime"

/* DLNA profile strings (not defined by DLNA yet. ZZZ) */
#define QT_PROF_STR "QuickTime"

/* DLNA pinfo strings */
#define QT_PINFO_STR "http-get:*:" QT_MIMETYPE_STR ":DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */
//#define QT_PINFO_STR "http-get:*:" QT_MIMETYPE_STR ":" QT_PROF_STR ";DLNA.ORG_OP=01;DLNA.ORG_CI=0" /* Should examine params : ZZZ */

#endif /* NFLC_INFO_QT_DEF_H */
