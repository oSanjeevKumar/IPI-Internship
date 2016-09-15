/*
 * media_helper.h
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef MEDIA_HELPER_H_
#define MEDIA_HELPER_H_

#define ANAL_MEDIA_RET_OK (0)
#define ANAL_MEDIA_RET_ERR (-1)
#define ANAL_MEDIA_RET_EOF (-2)


/* Read UI8 into *p_buf. */
slim_int
read_UI8(dlna_file_t media_fp, slim_byte *p_buf);

/* Read UI16 into *p_buf. */
slim_int
read_UI16(dlna_file_t media_fp, slim_half *p_buf);

/* Read UI24 into *p_buf. */
slim_int
read_UI24(dlna_file_t media_fp, slim_word *p_buf);
/* Read UI32 into *p_buf. */
slim_int
read_UI32(dlna_file_t media_fp, slim_word *p_buf);

/* Read DOUBLE into *p_buf. */
/* Assuming that double is stored in IEEE 754 format in the memory. : ZZZ */
slim_int
read_DOUBLE(dlna_file_t media_fp, slim_double *p_dbl_out);

/* Read a DWORD from MEDIA file media_fp and store into p_dword_out. */
slim_int
read_dword(dlna_file_t media_fp, slim_word *p_dword_out);

/* Read a WORD from media file media_fp and store into p_word_out. */
slim_int
read_word(dlna_file_t media_fp, slim_half *p_word_out);

/* Read a four char code (FCC) from media file media_fp and store into p_fcc_out. */
slim_int
read_fcc(dlna_file_t media_fp, slim_word *p_fcc_out);

/*** stdlib replacement functions. ***/
/* Replacement of feof(). */
slim_int
anal_media_feof(dlna_file_t in_desc);

/* Replacement of fseek(). */
dlna_off_t
anal_media_fseek(dlna_file_t in_desc, dlna_off_t off, slim_int origin);

/* Replacement of ftell(). */
dlna_off_t
anal_media_ftell(dlna_file_t in_desc);

/* Replacement of fread(). */
dlna_size_t
anal_media_fread(void *buf, dlna_size_t elsize, dlna_size_t num, dlna_file_t in_desc);

#endif /* MEDIA_HELPER_H_ */
