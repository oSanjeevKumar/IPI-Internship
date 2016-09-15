/*
 * anal_tiff.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The abtiffe copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/*
 anal_tiff.h : TIFF analyzer header file.

 8/8/2008 buchi
*/

#ifndef NFLC_ANAL_TIFF_H
#define NFLC_ANAL_TIFF_H

/* Process status */
#define ANAL_TIFF_RET_OK (0) /* Successful */
#define ANAL_TIFF_RET_ERR (-1) /* Error */
#define ANAL_TIFF_RET_EOF (-2) /* EOF detected. (not an error) */
#define ANAL_TIFF_RET_END_HEAD (-3) /* End of TIFF header. (not an error) */

struct tiff_file_info {
	slim_int is_be; /* Byte order is big endian. */

	slim_word ImageWidth; /* width */
	slim_word ImageLength; /* height */
	slim_int SamplesPerPixel; /* samples per pel */
	slim_int BitsPerSample[3]; /* bits per sample */
	slim_int Compression;
	slim_int PhotometricInterpretation;

	struct {
		slim_char *Artist;
		slim_char *Copyright;
		slim_char *DateTime;
		slim_char *ImageDescription;
/*
		slim_char *Make;
		slim_char *Model;
		slim_char *Software;
*/
	} comment;
};

typedef struct tiff_file_info TIFF_FILE_INFO;

slim_int anal_tiff_process_tiff_header(TIFF_FILE_INFO *p_tfi_out, dlna_file_t tiff_fp);

#endif /* NFLC_ANAL_TIFF_H */

