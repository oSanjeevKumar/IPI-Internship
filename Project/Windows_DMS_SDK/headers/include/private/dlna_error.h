/*
 * dlna_error.h
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

#ifndef NFLC_DLNA_ERROR_H
#define NFLC_DLNA_ERROR_H

enum dlna_return_types
{
  MINFO_BOGUS_FIRST = -9999, /* placeholder entry. Do not use.            */
  MINFO_OK               = -9998, /* OK return value                           */
  MINFO_NO               = -9997, /* Negative, but non-error return code       */
  MINFO_ENDBUFF          = -9996, /* End of buffer reached                     */
  MINFO_ERROR            = -9995, /* Error Return Value                        */
  MINFO_LAST_TYPE        = -9994, /* Last type placeholder.                    */
  MINFO_PES_FOUND        = -9993, /* PES packet data found.                    */
  MINFO_PES_NOT_FOUND    = -9992, /* PES packet data not found.                */
  MINFO_DUPLICATE        = -9991, /* Item duplicate                            */
  MINFO_DIFF             = -9990, /* Items differ                              */
  MINFO_NULL_FOUND       = -9989, /* NULL entry found, not error               */
  MINFO_FILE_OPEN_ERR    = -9988, /* Error oprning file                        */
  MINFO_FILE_STAT_ERR    = -9987, /* Error getting file stat                   */
  MINFO_FILE_ZERO_ERR    = -9986, /* Zero size file                            */
  MINFO_FILE_SEEK_ERR    = -9985, /* Error seeking file                        */    
  MINFO_FILE_SMALL_ERR   = -9984, /* File too small                            */
  MINFO_INVALID_HEAD_SIZE= -9983, /* Invalid header size                       */
  MINFO_INVALID_FILE     = -9982, /* File corrupt or invalid                   */
  MINFO_INVALID_FILE_REF = -9981, /* File referencehandle corrupt or invalid   */
  MINFO_INVALID_MARKER   = -9980, /* Corrupt marker Corrupt Marker             */
  MINFO_INVALID_SIG      = -9979, /* Corrupt marker Corrupt signature          */
  MINFO_INVALID_V2_VER   = -9978, /* corrupt ID3 v2 version data               */
  MINFO_UNKNOWN_V2_VER   = -9977, /* unknown ID3 v2 version data               */
  MINFO_UNKNOWN_STREAM_TYPE=-9976,/* unknown stream type (MPEG2)               */
  MINFO_INVALID_FRAME    = -9975, /* Unable to find frame name for ID3         */
  MINFO_NO_FRAME_NAME    = -9974, /* Unable to find frame name for ID3         */
  MINFO_INVALID_CHUNK_ID = -9973, /* corrupt or invalid chunk ID               */
  MINFO_INVALID_CHUNK_LEN= -9972, /* corrupt or invalid chunk Length           */
  MINFO_INVALID_CHUNK_TYPE=-9971, /* corrupt or invalid chunk Type indication  */
  MINFO_OUTOF_MEMORY     =-9970,  /* memory allocatin error                    */

  /********** This is a special case ***********/
  MINFO_SETJUMP_RETURN = 0,  /* setjump returns zero ONLY in special cases*/

  /* ZZZ: LAST_VALUE is always 1. */
  MINFO_LAST_VALUE           /* always the last enum member.              */

};

typedef enum dlna_return_types dlna_ret_t;

#endif /* NFLC_DLNA_DEBUG_H */
