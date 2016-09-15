/*
 * info_jpeg_scale.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_INFO_JPEG_SCALE_H
#define NFLC_INFO_JPEG_SCALE_H

/* JPEG rescale error codes.  */
#define JPEG_SCALE_ERR_CANT_OPEN_FILE      (-1)

/* JPEG scale calculation.  */
struct jpeg_scale
{
  /* JPEG scale type.  */
#define JPEG_SCALE_TYPE_NORMAL   (0)
#define JPEG_SCALE_TYPE_HALF     (1)
#define JPEG_SCALE_TYPE_QUAD     (2)
  slim_int type;

  /* Permillage of the scaling.  */
  slim_int permillage;

  /* New width and height.  */
  slim_word width;
  slim_word height;

  /* File size.  */
  dlna_size_t size;

  /* Modified time.  */
  dlna_time_t mtime;
};


struct jpeg_rescale_processing_interface;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef void (* _jpeg_rescale_interface_destory)(struct jpeg_rescale_processing_interface * obj);

typedef dlna_ret_t (* _jpeg_rescale_interface_routine)(struct jpeg_rescale_processing_interface *,
    slim_char *file_name_input,
    slim_char *file_name_output,
    struct jpeg_scale *scale);


struct jpeg_rescale_processing_interface *
jpeg_rescale_processing_create_whole_image(slim_word memory_limit);

struct jpeg_rescale_processing_interface *
jpeg_rescale_processing_create_line_by_line();


#ifdef __cplusplus
}
#endif /* __cplusplus */

struct jpeg_rescale_processing_interface
{
  _jpeg_rescale_interface_destory destory;
  _jpeg_rescale_interface_routine process;
};

#endif /* NFLC_INFO_JPEG_SCALE_H */
