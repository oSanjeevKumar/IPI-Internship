/*
 * info_id3.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* ID3 tag information get routine.  */

#ifndef NFLC_INFO_ID3_H
#define NFLC_INFO_ID3_H

/* ID3 frame IDs.  These are based on ID3v2.4 frame IDs.  */
enum id3_frame_id {
    ID3_FRAME_ID_AENC,
    ID3_FRAME_ID_APIC,
    ID3_FRAME_ID_ASPI,
    ID3_FRAME_ID_COMM,
    ID3_FRAME_ID_COMR,
    ID3_FRAME_ID_ENCR,
    ID3_FRAME_ID_EQU2,
    ID3_FRAME_ID_ETCO,
    ID3_FRAME_ID_GEOB,
    ID3_FRAME_ID_GRID,
    ID3_FRAME_ID_LINK,
    ID3_FRAME_ID_MCDI,
    ID3_FRAME_ID_MLLT,
    ID3_FRAME_ID_OWNE,
    ID3_FRAME_ID_PRIV,
    ID3_FRAME_ID_PCNT,
    ID3_FRAME_ID_POPM,
    ID3_FRAME_ID_POSS,
    ID3_FRAME_ID_RBUF,
    ID3_FRAME_ID_RVA2,
    ID3_FRAME_ID_RVRB,
    ID3_FRAME_ID_SEEK,
    ID3_FRAME_ID_SIGN,
    ID3_FRAME_ID_SYLT,
    ID3_FRAME_ID_SYTC,
    ID3_FRAME_ID_TALB,
    ID3_FRAME_ID_TBPM,
    ID3_FRAME_ID_TCOM,
    ID3_FRAME_ID_TCON,
    ID3_FRAME_ID_TCOP,
    ID3_FRAME_ID_TDEN,
    ID3_FRAME_ID_TDLY,
    ID3_FRAME_ID_TDOR,
    ID3_FRAME_ID_TDRC,
    ID3_FRAME_ID_TDRL,
    ID3_FRAME_ID_TDTG,
    ID3_FRAME_ID_TENC,
    ID3_FRAME_ID_TEXT,
    ID3_FRAME_ID_TFLT,
    ID3_FRAME_ID_TIPL,
    ID3_FRAME_ID_TIT1,
    ID3_FRAME_ID_TIT2,
    ID3_FRAME_ID_TIT3,
    ID3_FRAME_ID_TKEY,
    ID3_FRAME_ID_TLAN,
    ID3_FRAME_ID_TLEN,
    ID3_FRAME_ID_TMCL,
    ID3_FRAME_ID_TMED,
    ID3_FRAME_ID_TMOO,
    ID3_FRAME_ID_TOAL,
    ID3_FRAME_ID_TOFN,
    ID3_FRAME_ID_TOLY,
    ID3_FRAME_ID_TOPE,
    ID3_FRAME_ID_TOWN,
    ID3_FRAME_ID_TPE1,
    ID3_FRAME_ID_TPE2,
    ID3_FRAME_ID_TPE3,
    ID3_FRAME_ID_TPE4,
    ID3_FRAME_ID_TPOS,
    ID3_FRAME_ID_TPRO,
    ID3_FRAME_ID_TPUB,
    ID3_FRAME_ID_TRCK,
    ID3_FRAME_ID_TRSN,
    ID3_FRAME_ID_TRSO,
    ID3_FRAME_ID_TSOA,
    ID3_FRAME_ID_TSOP,
    ID3_FRAME_ID_TSOT,
    ID3_FRAME_ID_TSRC,
    ID3_FRAME_ID_TSSE,
    ID3_FRAME_ID_TSST,
    ID3_FRAME_ID_TXXX,
    ID3_FRAME_ID_UFID,
    ID3_FRAME_ID_USER,
    ID3_FRAME_ID_USLT,
    ID3_FRAME_ID_WCOM,
    ID3_FRAME_ID_WCOP,
    ID3_FRAME_ID_WOAF,
    ID3_FRAME_ID_WOAR,
    ID3_FRAME_ID_WOAS,
    ID3_FRAME_ID_WORS,
    ID3_FRAME_ID_WPAY,
    ID3_FRAME_ID_WPUB,
    ID3_FRAME_ID_WXXX,
    ID3_FRAME_ID_obso
};

/* ID3 field types.  */
enum id3_field_type {
    ID3_FIELD_TEXT_ENCODING,
    ID3_FIELD_TEXT_STRING_ENCODED,
    ID3_FIELD_TEXT_STRING,
    ID3_FIELD_TEXT_STRING_LIST,
    ID3_FIELD_TEXT_FULL_STRING,
    ID3_FIELD_LANGUAGE,
    ID3_FIELD_INT8,
    ID3_FIELD_INT16,
    ID3_FIELD_INT24,
    ID3_FIELD_INT32,
    ID3_FIELD_INT32_PLUS,
    ID3_FIELD_BINARY,
    ID3_FIELD_DATE,
    ID3_FIELD_FRAME_ID,
};

enum id3_field_textencoding {
    ID3_FIELD_TEXTENCODING_ISO_8859_1 = 0x00,
    ID3_FIELD_TEXTENCODING_UTF_16     = 0x01,
    ID3_FIELD_TEXTENCODING_UTF_16BE   = 0x02,
    ID3_FIELD_TEXTENCODING_UTF_8      = 0x03,
    ID3_FIELD_TEXTENCODING_UNKNOWN    = 0x1F
};

/* Forward declaration.  */
struct id3_info;
struct id3_frame_info;

/* Callback function for the ID3.  */
typedef slim_int (*id3_info_callback_t) (struct id3_info *id3,
					 struct id3_frame_info *in_frame,
					 void * in_arg);

/* ID3 information structure.  */
struct id3_info
{
  /* Callback fucntion.  */
  id3_info_callback_t id3_info_callback;

  /* ID3v1 and ID3v2 tag.  */
  slim_int v1_tag_exists;
  slim_int v2_tag_exists;

  /* File descriptor of the file.  */
  dlna_file_t desc;

  /* ID3v2 tag length.  */
  slim_word length;

  /* ID3v2 version.  */
  slim_byte major_version;
  slim_byte minor_version;

  /* ID3v2 flags.  */
  slim_byte v2_flags;

  /* Frame length.  */
  slim_word frame_length;

  /* Frame value of ID3v1.  */
  slim_char *frame_val;

  /* File offset.  */
  dlna_off_t offset;
};

/* ID3 frame type.  */
struct id3_frame_info
{
  /* ID3 tag.  This is used for perfect hash key string.  */
  slim_char *name;

  /* Frame id.  */
  enum id3_frame_id id;

  /* Pointer to field type.  */
  const enum id3_field_type *field_type;

  /* Number of the field type.  */
  slim_byte field_num;
};

enum media_id3_get_routine {
	CHUNK_ROUTINE, /*invoke from riff files*/
	MP3_ROUTINE /*invoke from mp3 files*/
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_int
id3_info_get(struct id3_info *id3, slim_char *in_fname, void *in_arg,
		id3_info_callback_t in_callback, enum media_id3_get_routine invoke_param);

slim_char *
id3_frame_text_get (struct id3_info *id3, struct id3_frame_info *in_frame);

slim_char *
id3_frame_genre_get (struct id3_info *id3, struct id3_frame_info *in_frame);

slim_int
id3_frame_int_get (struct id3_info * id3, struct id3_frame_info * in_frame);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_ID3_H */
