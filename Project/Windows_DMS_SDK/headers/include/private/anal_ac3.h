/*
 * anal_ac3.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/*
 anal_ac3.h : AC-3 analyzer header file.

 8/4/2008 buchi
*/

#ifndef NFLC_ANAL_AC3_H
#define NFLC_ANAL_AC3_H

/* #define ANAL_AC3_DEBUG */ /* Debug mode */

/* Process status */
#define ANAL_AC3_RET_OK (0) /* Successful */
#define ANAL_AC3_RET_ERR (-1) /* Error */
#define ANAL_AC3_RET_EOF (-2) /* EOF detected. (not an error) */
//#define ANAL_AC3_RET_END_INFO (-3) /* End of AC-3 info detected. (not an error) */

/* AC-3 file info */
struct ac3_file_info {
	/* Info in syncinfo */
	slim_long sps; /* Sampling rate (Hz) */
	slim_int kbps; /* Bit rate (kbps) */
	slim_int frame_size; /* Frame size (Bytes/frame) */

	/* Info in bsi */
	slim_int num_ch; /* Number of channels */
	slim_byte copyrightb; /* Copyright bit */

	/* File info */
	slim_ulong num_frames; /* Total number of frames in the file. */
};

typedef struct ac3_file_info AC3_FILE_INFO;

slim_int anal_ac3_process_ac3(AC3_FILE_INFO *p_afi_out, dlna_file_t ac3_fp);
#endif /* NFLC_ANAL_AC3_H */
