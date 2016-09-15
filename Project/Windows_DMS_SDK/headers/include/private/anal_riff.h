/*
 * anal_riff.h
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
 anal_riff.h : RIFF analyzer header file.

 7/16-30/2008 buchi
*/

#ifndef NFLC_ANAL_RIFF_H
#define NFLC_ANAL_RIFF_H

/* #define ANAL_RIFF_DEBUG */ /* Debug mode */

/* Process status */
#define ANAL_RIFF_RET_OK (0) /* Successful */
#define ANAL_RIFF_RET_ERR (-1) /* Error */
#define ANAL_RIFF_RET_EOF (-2) /* EOF detected. (not an error) */
#define ANAL_RIFF_RET_END_INFO (-3) /* End of AVI info detected. (not an error) */

/* AVI header (avih chunk) data */
struct avih_data {
	slim_word dwMicroSecPerFrame; /* Frame rate (us/frame) */
	slim_word dwMaxBytesPerSec; /* (Max. bytes/s) */
	slim_word dwPaddingGranularity;
	slim_word dwFlags;
	slim_word dwTotalFrames; /* Total number of frames */
	slim_word dwInitialFrames; /* Start frame number */
	slim_word dwStreams; /* Number of streams */
	slim_word dwSuggestedBufferSize;
	slim_word dwWidth; /* Width */
	slim_word dwHeight; /* Height */
	slim_word dwReserved[4];
};

typedef struct avih_data AVIH_DATA;

/* Stream header (strh chunk) data */
struct strh_data {
	slim_word fccType; /* Stream type */
	slim_word fccHandler; /* Stream handler */
	slim_word dwFlags;
	slim_half wPriority; /* Priority of this stream */
	slim_half wLanguage;
	slim_word dwInitialFrames; /* Start frame number */
	slim_word dwScale; /* Scale */
	slim_word dwRate; /* Frame/Sample rate */
	slim_word dwStart; /* Start frame number */
	slim_word dwLength; /* Total number of frames */
	slim_word dwSuggestedBufferSize;
	slim_word dwQuality;
	slim_word dwSampleSize; /* Sample size */
	struct {
		slim_half left;
		slim_half top;
		slim_half right;
		slim_half bottom;
	} rcFrame;
};
typedef struct strh_data STRH_DATA;

/* Stream format for video (vids strf chunk) data */
struct vids_strf_data {
	slim_word biSize;
	slim_word biWidth; /* Width */
	slim_word biHeight; /* Height */
	slim_half biPlanes; /* Number of planes */
	slim_half biBitCount; /* Number of bits/pel */
	slim_word biCompression; /* 'FourCC': see http://www.fourcc.org/codecs.php */
	slim_word biSizeImage;
	slim_word biXPelsPerMeter;
	slim_word biYPelsPerMeter;
	slim_word biClrUsed;
	slim_word biClrImportant;
};
typedef struct vids_strf_data VIDS_STRF_DATA;

/* Stream format for audio (auds strf chunk) data */
struct auds_strf_data {
	slim_half wFormatTag; /* Format: 1: PCM, 0x55: MP3, etc. */
	slim_half nChannels; /* Number of channels */
	slim_word nSamplesPerSec; /* Sample rate (1/s) */
	slim_word nAvgBytesPerSec; /* Average bytes/s */
	slim_half nBlockAlign;
	slim_half wBitsPerSample; /* Bits/sample */
	slim_half cbSize; /* Number of continued data bytes */
};
typedef struct auds_strf_data AUDS_STRF_DATA;

struct aiff_comm_data {
	slim_half nChannels; /* Number of channels */
	slim_word numSampleFrames;
	slim_half sampleSize;
	slim_ulong nSamplesPerSec; /* Sample rate (1/s) */
	slim_half cbSize; /* Number of continued data bytes */
	slim_word commpresionType;
};
typedef struct aiff_comm_data AIFF_COMM_DATA;


/* RIFF file info (assuming only two(video+audio) streams) */
struct riff_file_info {
	slim_int avih_valid; /* If non-zero, avih is valid. */
	AVIH_DATA avih;

	struct _video { /* Video info */
		slim_int strh_valid; /* If non-zero, strh is valid. */
		STRH_DATA strh;
		slim_int strf_valid; /* If non-zero, strf is valid. */
		VIDS_STRF_DATA strf;

		slim_word movi_size; /* Size of movi list. */
	} video;

	struct _audio { /* Audio info */
		slim_int strh_valid; /* If non-zero, strh is valid. */
		STRH_DATA strh;
		slim_int strf_valid; /* If non-zero, strh is valid. */
		AUDS_STRF_DATA strf;

		slim_word data_size; /* Size of data chunk. */
	} audio;

	AIFF_COMM_DATA aiff_comm_chunk; /*AIFF COMM CHUNK STRUCT*/

	struct _info { /* Contents info */
		slim_char *icrd; /* ICRD */
		slim_char *ieng; /* IENG */
		slim_char *inam; /* INAM */
		slim_char *icop; /* ICOP */
		slim_char *ignr; /* IGNR */
		slim_char *icmt; /* ICMT */
		slim_char *iart; /* IART */
		slim_char *itrk; /* ITRK */
		slim_char *iprd; /* IPRD */
	} info;
};
typedef struct riff_file_info RIFF_FILE_INFO;

#ifndef  BYTE_ORDER_BIG_ENDIAN 
/* Make a four char. code (FCC) */
#define RIFF_MAKE_FCC(c1, c2, c3, c4) ((slim_word)(c1) | (((slim_word)(c2))<<8) | (((slim_word)(c3))<<16) | (((slim_word)(c4))<<24))

#else 
#define RIFF_MAKE_FCC(c1, c2, c3, c4) ((slim_word)(c4) | (((slim_word)(c3))<<8) | (((slim_word)(c2))<<16) | (((slim_word)(c1))<<24))
#endif /* BYTE_ORDER_BIG_ENDIAN */

slim_int anal_riff_process_riff(RIFF_FILE_INFO *p_rfi_out, dlna_file_t riff_fp);

#endif /* NFLC_ANAL_RIFF_H */
