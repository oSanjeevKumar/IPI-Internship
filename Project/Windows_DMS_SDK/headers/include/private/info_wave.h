/*
 * info_wave.h
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

/* WAVE information get routine.  */

#ifndef NFLC_INFO_WAVE_H
#define NFLC_INFO_WAVE_H

/* WAVE chunk id size.  */
#define WAVE_CHUNK_ID_SIZE     (4)

/* WAVE length size.  */
#define WAVE_LENGTH_SIZE       (4)

/* WAVE file type size.  */
#define WAVE_FILE_TYPE_SIZE    (4)

/* data length */
#define RIFF_DATA_LEN_LONG     (4)
#define RIFF_DATA_LEN_SHORT    (2)

/* RIFF and FORM id string.  */
#define RIFF_ID_STR                       "RIFF"

/* WAVE id string.  */
#define WAVE_ID_STR                       "WAVE"

/* WAVE chunk ids.  */
#define FORMAT_ID_STR                     "fmt "
#define DATA_ID_STR                       "data"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_bool
register_media_info_wave(media_manager_t *mim);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_WAVE_H */
