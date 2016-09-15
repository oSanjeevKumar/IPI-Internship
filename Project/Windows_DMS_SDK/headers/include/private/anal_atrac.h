/*
 * anal_atrac.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The abatrace copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/*
 anal_atrac.h : ATRAC analyzer header file.

 10/3-7,10/2008 buchi
*/

#ifndef NFLC_ANAL_ATRAC_H
#define NFLC_ANAL_ATRAC_H

/* Process status */
#define ANAL_ATRAC_RET_OK (0) /* Successful */
#define ANAL_ATRAC_RET_ERR (-1) /* Error */
#define ANAL_ATRAC_RET_EOF (-2) /* EOF detected. (not an error) */

/* ATRAC file info */
struct atrac_file_info {
	/* from AudioDataHeader */
	struct {
		slim_half e_id; /* E-ID */
		slim_byte content_id[24]; /* Content-ID */
		slim_byte codec_id; /* CODEC Id */
		slim_half kbps; /* Rate(kbps) */
		slim_half frame_size; /* [ATRAC3 & ATRAC3plus only] Frame Size (B) */
		slim_ulong freq; /* Frequency(Hz) */
		slim_byte num_ch; /* Channels */
		slim_byte emp; /* [ATRAC3 only] Emphasis */
		slim_byte word_len; /* [ATRAC AL only] WORDLEN */
		slim_double total_time; /* Total Time (s) */
		slim_ulong frame_count; /* Frame Count */
		slim_half spf; /* Samples/frame */
	} adh;

	/* from Metadata */
	/* Note: Strings are converted into and stored in UTF-8. */
	struct {
		slim_char *title; /* Title from TIT2 */
		slim_char *artist; /* Main Artist from TPE1 */
		slim_char *genre; /* Genre from TCON */
		slim_char *year; /* Year from TYER */
		slim_char *album; /* Album Title from TALB */
		slim_char *prgt; /* Phonogram Rights from TXXX:OMG_TPGMR */
		slim_char *date; /* Released Date from TXXX:OMG_TRLDA */
		slim_char *note; /* Text Liner Note from TXXX:OMG_TLNNT */
		slim_char *trkn; /* Track number from TXXX:OMG_TRACK */
#ifdef NOTDEF
		slim_char *time; /* Song Time from TLEN */
		slim_char *isrc; /* ISRC code from TSRC */
#endif /* NOTDEF */
	} meta;
};

typedef struct atrac_file_info ATRAC_FILE_INFO;

slim_int anal_atrac_process_atrac(dlna_file_t atrac_fp, ATRAC_FILE_INFO *p_afi_out, slim_ulong file_size);

#endif /* !NFLC_ANAL_ATRAC_H */
