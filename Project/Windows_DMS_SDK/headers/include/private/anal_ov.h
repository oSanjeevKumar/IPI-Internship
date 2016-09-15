/*
 * anal_ov.h
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
 anal_ov.h : Ogg Vorbis analyzer header file.

 8/5-6/2008 buchi
*/

#ifndef NFLC_ANAL_OV_H
#define NFLC_ANAL_OV_H

/* Process status */
#define ANAL_OV_RET_OK (0) /* Successful */
#define ANAL_OV_RET_ERR (-1) /* Error */
#define ANAL_OV_RET_EOF (-2) /* EOF detected. (not an error) */
#define ANAL_OV_RET_END_PKT (-3) /* End of Ogg packet. (not an error) */
#define ANAL_OV_RET_END_VHEAD (-4) /* End of Vorbis header. (not an error) */

struct ov_file_info {
	/* Identification packet */
	slim_byte audio_channels;
	slim_ulong audio_sample_rate;
	slim_word bitrate_maximum;
	slim_word bitrate_nominal;
	slim_word bitrate_minimum;
	slim_int blocksize0;
	slim_int blocksize1;
	slim_bool need_album_art;

	/* Comment packet */
	struct {
		slim_char *vendor;

		slim_char *title;
		slim_char *version;
		slim_char *album;
		slim_char *tracknumber;
		slim_char *artist;
		slim_char *performer;
		slim_char *copyright;
		slim_char *license;
		slim_char *organization;
		slim_char *description;
		slim_char *genre;
		slim_char *date;
		slim_char *location;
		slim_char *contact;
		slim_char *isrc;
		/*Covert art fields*/
		slim_char * cover_art;
		slim_char * cover_art_mime;

		slim_char *comment; /* mp3infp creates COMMENT field. */
	} comment;
};

typedef struct ov_file_info OV_FILE_INFO;

slim_int anal_ov_process_ov_header(OV_FILE_INFO *p_ofi_out, dlna_file_t ov_fp);
albumArtImage* ov_get_embedded_album_art_image(slim_char* full_path);

#endif /* NFLC_ANAL_OV_H */
