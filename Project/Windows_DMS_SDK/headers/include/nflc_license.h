/*
 * nflc_license.h
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

#ifndef DEVELOPMENT_ENABLE_SDK_EXPIRY
#define DEVELOPMENT_ENABLE_SDK_EXPIRY
#endif

#define LICENSE_FILE_NAME "sdk_license.dat"
#define ENCRYPT 1
#define DECRYPT 0
#define KEY_LEN 16
#define IV_LEN 16
#define KEY_VAL 897 //TODO
#define IV_VAL 798 //TODO

slim_int char_to_digit(slim_char c);
slim_int check_license_validity(slim_char* path);
