/*
 * info_file.h
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

/* File information get routine.  */

#ifndef NFLC_INFO_FILE_H
#define NFLC_INFO_FILE_H

#include <dlna_int64.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

dlna_ret_t
file_info_get(slim_char *in_fname, dlna_uint64 *out_size,
    dlna_time_t *out_mtime);

#ifdef __cplusplus
}
#endif    /* __cplusplus */

#endif /* NFLC_INFO_FILE_H */
