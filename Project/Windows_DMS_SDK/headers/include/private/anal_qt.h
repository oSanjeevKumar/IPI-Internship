/*
 * anal_qt.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The abqte copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/*
 anal_qt.h : QuickTime analyzer header file.

 8/19-21/2008 buchi
*/

#ifndef NFLC_ANAL_QT_H
#define NFLC_ANAL_QT_H

#define ANAL_QT_SUPPORT_PROF /* Support Profile Atom */
#define ANAL_QT_SUPPORT_EXT_INFO /* Support extended info */
/* #define ANAL_QT_SUPPORT_INFO_ITUNES */ /* Support iTunes' info (obsoleted by ANAL_QT_SUPPORT_META) */
/* #define ANAL_QT_IGNORE_ZERO_SIZED_ATOM */ /* Ignore zero-sized atoms */ /* Don't define. */
#define ANAL_QT_ZERO_LEN_PATCH /* Patch for zero-length in some atoms. */
#define ANAL_QT_SUPPORT_META /* Support meta and ilst atoms created by iTunes. (Both are not defined in spec) */

/* Process status */
#define ANAL_QT_RET_OK (0) /* Successful */
#define ANAL_QT_RET_ERR (-1) /* Error */
#define ANAL_QT_RET_EOF (-2) /* EOF detected. (not an error) */

#ifdef ANAL_QT_SUPPORT_META
struct anal_qt_str {
	slim_char *str; /* Ponter to string */
	slim_byte is_utf8; /* str is UTF-8 or not */
};
typedef struct anal_qt_str ANAL_QT_STR;

#else /* !ANAL_QT_SUPPORT_META */
struct anal_qt_str {
	slim_char *str;
};
typedef struct anal_qt_str ANAL_QT_STR;
#endif /* ANAL_QT_SUPPORT_META */

/* QT file info */
struct qt_file_info {
	/* Common */
	slim_double duration; /* from mvhd.Duration and Time scale */
	slim_ulong cre_time; /* from mvhd.Creation time */

	/* Video */
	struct {
		slim_word fmt; /* from vide.stsd.Data format or prfl.vfmt */
		slim_long width; /* from vide.stsd.Width or prfl.mvsz */
		slim_long height; /* from vide.stsd.Height or prfl.mvsz  */
		slim_long depth; /* from vide.stsd.Depth */
#ifdef ANAL_QT_SUPPORT_PROF
		slim_ulong bps; /* bitrate from prfl.avvb */
		slim_double fps; /* framerate from prfl.tafr */
#endif /* ANAL_QT_SUPPORT_PROF */
	} video;

	/* Sound */
	struct {
		slim_word fmt; /* from soun.stsd.Data format or prfl.afmt */
		slim_short num_ch; /* from soun.stsd.Number of channels or prfl.achc */
		slim_short bits; /* from soun.stsd.Sample size */
		slim_half sps; /* samplerate from soun.stsd.Sample rate or prfl.ausr */
#ifdef ANAL_QT_SUPPORT_PROF
		slim_ulong bps; /* bitrate from prfl.avvb */
#endif /* ANAL_QT_SUPPORT_PROF */
	} sound;

	/* Comment */ /* from udta and/or ilst */
	struct {
		ANAL_QT_STR cpy; /* Copyright from (c)cpy */
		ANAL_QT_STR inf; /* Information from (c)inf */
		ANAL_QT_STR isr; /* ISRC code from (c)isr */
		ANAL_QT_STR mak; /* Creator or maker from (c)mak */
		ANAL_QT_STR nam; /* Title from (c)nam */
		ANAL_QT_STR day; /* Date from (c)day */
		ANAL_QT_STR com; /* Composer from (c)com */
		ANAL_QT_STR prf; /* Performers from (c)prf */

#ifdef ANAL_QT_SUPPORT_EXT_INFO
		ANAL_QT_STR alb; /* Album from (c)alb : Not defined in spec. */
		ANAL_QT_STR gen; /* Genre from (c)gnr : Not defined in spec. */
		ANAL_QT_STR cmt; /* Comment from (c)cmt : Not defined in spec.  */
		ANAL_QT_STR art; /* Artist from (c)ART : Not defined in spec.  */
/*		ANAL_QT_STR trk; */ /* Track number from (c)trk : Not defined in spec.  */
#ifdef ANAL_QT_SUPPORT_META
		slim_ulong trkn; /* Track number from trkn : Not defined in spec.  */
#endif /* ANAL_QT_SUPPORT_META */
#endif /* ANAL_QT_SUPPORT_EXT_INFO */
	} comment;
};

typedef struct qt_file_info QT_FILE_INFO;

slim_int anal_qt_process_qt(dlna_file_t qt_fp, QT_FILE_INFO *p_qfi_out, slim_ulong fsize);

#endif /* !NFLC_ANAL_QT_H */
