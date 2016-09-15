/*
 * info_exif.h
 * Copyright (C) 2007-2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2012. Access Company All Rights Reserved.  */

#include <dlna_peer.h>

#ifndef EXIF_API_H
#define EXIF_API_H

#define MAX_KEYWORDS_SIZE 1024

enum {
  EXIF_OK,
  EXIF_ERROR
};

slim_int
exifInitProcessing(const slim_char *in_path);

void
exifFinishProcessing();

slim_int
exifGetGPSData(slim_char *in_path, slim_double *out_latitude, slim_double *out_longitude);

slim_int
exifGetMtimeData(const slim_char *in_path, const slim_char *in_date_format, dlna_time_t *out_time);

slim_int
exifGetKeywords(const slim_char *in_path, slim_char *out_keywords);

slim_int
exifSaveThumbnail(slim_char * ThumbFileName);

slim_int
exifGetMaxKeywordsSize();

#endif /* EXIF_API_H */
