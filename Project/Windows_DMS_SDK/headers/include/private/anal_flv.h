/*
 * anal_flv.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The abflve copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/*
 anal_flv.h : FLV analyzer header file.

 8/13/2008 buchi
*/

#ifndef NFLC_ANAL_FLV_H
#define NFLC_ANAL_FLV_H

/* #define FLV_ANAL_ONLY_SC_DATA */ /* Analyze only Script Data. */
#define FLV_ANAL_ONLY_HEAD_OF_DATA /* Analyze only head of data. */

/* Process status */
#define ANAL_FLV_RET_OK (0) /* Successful */
#define ANAL_FLV_RET_ERR (-1) /* Error */
#define ANAL_FLV_RET_EOF (-2) /* EOF detected. (not an error) */
#define ANAL_FLV_RET_END_HEAD (-3) /* End of FLV header. (not an error) */

/* FLV file info */
struct flv_file_info {
#ifdef FLV_ANAL_ONLY_HEAD_OF_DATA
	slim_int audio_tag_read;
#endif /* FLV_ANAL_ONLY_HEAD_OF_DATA */
#ifndef FLV_ANAL_ONLY_SC_DATA
	/* Audio */
	slim_byte SoundFormat; /* (See FLV spec.) */
//	slim_byte SoundRate;
	slim_long SoundRate; /* Sample rate in Hz */
	slim_byte SoundSize; /* bits/sample */
	slim_byte SoundType; /* 0: Mono, 1: Stereo */
	
#ifdef FLV_ANAL_ONLY_HEAD_OF_DATA
	slim_int video_tag_read;
#endif /* FLV_ANAL_ONLY_HEAD_OF_DATA */
	/* Video */
/*	slim_byte FrameType; */
	slim_byte CodecID;
#endif /* !FLV_ANAL_ONLY_SC_DATA */

#ifdef FLV_ANAL_ONLY_HEAD_OF_DATA
	slim_int sd_tag_read;
#endif /* FLV_ANAL_ONLY_HEAD_OF_DATA */
	/* onMetaData */
	slim_double duration;
	slim_double width;
	slim_double height;
	slim_double videodatarate;
	slim_double framerate;
//	slim_double videocodecid;
#ifdef NOTDEF
	slim_double audiosamplerate;
	slim_double audiosamplesize;
	slim_int stereo;
#endif /* NOTDEF */
//	slim_double audiocodecid;
//	slim_double filesize;
};

typedef struct flv_file_info FLV_FILE_INFO;

slim_int anal_flv_process_flv(dlna_file_t flv_fp, FLV_FILE_INFO *p_ffi_out);
//slim_int anal_flv_process_flv(FLV_FILE_INFO *p_ffi_out, dlna_file_t flv_fp);

#endif /* !NFLC_ANAL_FLV_H */
