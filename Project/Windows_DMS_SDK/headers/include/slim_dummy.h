/*
 * slim_dummy.h
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

#ifndef NFLC_SLIM_DUMMY_H
#define NFLC_SLIM_DUMMY_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h> /* intptr_t */

/*ZZZ:#ifdef SLIM_CONFIG_DEBUG*/
#define SLIM_ASSERT(test) ((test) ? (void)0 : dlnaDebugPrintfPeer(#test, __FILE__, __LINE__, 0, 0))
/*#else
#define SLIM_ASSERT(x)
#endif*/

#define SLIM_T(x)  ((slim_char *)x)
#define SLIM_C(x)  ((slim_char)x)

/* SLIM Debug Printf */
#define SLIM_DP(arg) dlnaDebugPrintfPeer arg

/* We use SLIM data types for DLNA implementation.  */

/*!
Signed 8-bit or higher
*/
/* slim_tiny -- Signed type.  Greater than or equal to 8 bit.  */
typedef char slim_tiny;

/*!
Signed 16-bit or higher
*/
/* slim_short -- Signed type.  Greater than or equal to 16 bit.  */
typedef short slim_short;

/*!
Signed 32-bit or higher
*/
/* slim_int -- Signed type.  Greater than or equal to 32 bit.  */
typedef int slim_int;

/* slim_bool -- Unsigned type.  Greater than or equal to 32 bit.  */
typedef unsigned int slim_bool;

/*!
Unsigned 8-bit
*/
/* slim_byte -- Unsigned 8 bit.  */
typedef unsigned char slim_byte;

/* slim_char -- Unsigned 8 bit.  */
typedef unsigned char slim_char;

/*!
Unsigned 16-bit
*/
/* slim_half -- Unsigned type.  Greater than or equal to 16 bit. */
typedef unsigned short slim_half;

/*!
Unsigned 32-bit
*/
/* slim_word -- Unsigned type.  Greater than or equal to 32 bit.  */
typedef unsigned int slim_word;

/* slim_ulong -- Unsigned type.  Greater than or equal to 32 bit.  */
typedef unsigned long slim_ulong;

/* slim_double -- Greater than or equal to double.  */
typedef double slim_double;

/* slim_opaue -- Enough size to store pointer or slim_int.  */
typedef void * slim_opaque;

/* slim_fixed_point -- Signed value.  Greater than or equal to 32
   bit.  */
typedef float slim_fixed_point;

/* slim_iaddr_word - signed address word in flexible size, platform dependent (32/64bit) */
typedef intptr_t   slim_iaddr_word;

/* slim_uiaddr_word - unsigned address word in flexible size, platform dependent (32/64bit) */
typedef uintptr_t  slim_uiaddr_word;

/* slim_cpu_word - unsigned CPU word, platform dependent (32/64bit) */
typedef uintptr_t  slim_cpu_word;

/* slim_size - unsigned size type, platform dependent (32/64bit) */
typedef size_t     slim_size;

#if __x86_64__
/*!
 Signed 64-bit
 */
typedef	long long  slim_int64;
#endif /* __x86_64__ */

/* SLIM variables.  */
#define slim_nil                      ((void *) 0)
/*!
0
*/
#define slim_false                               0
/*!
!slim_false
*/
#define slim_true                   (! slim_false)
/*!
(-2147483647-1)
*/
#define SLIM_INT_MIN               (-2147483647-1)
/*!
2147483647
*/
#define SLIM_INT_MAX                    2147483647
/*!
(-32767-1)
*/
#define SLIM_SHORT_MIN                  (-32767-1)
/*!
32767
*/
#define SLIM_SHORT_MAX                       32767
/*!
0xFFFFFFFF
*/
#define SLIM_WORD_MAX                   0xFFFFFFFF
/*!
SLIM_WORD_MAX
*/
#define SLIM_UINT_MAX                SLIM_WORD_MAX
/*!
0xFFFF
*/
#define SLIM_HALF_MAX                       0xFFFF
/*!
SLIM_HALF_MAX
*/
#define SLIM_USHORT_MAX              SLIM_HALF_MAX

/* SLIM return values.  */
enum
{
  SLIM_E_OK = 0,
  SLIM_E_GENERIC = -1,
  SLIM_E_WOULDBLOCK = -2,
  SLIM_E_NOTSUPPORTED = -3
};

#ifdef __cplusplus
#define SLIM_BEGIN_C_LINKAGE extern "C" {
#define SLIM_END_C_LINKAGE   }
#else
#define SLIM_BEGIN_C_LINKAGE
#define SLIM_END_C_LINKAGE
#endif

#ifndef SLIM_DLLIMPORT
#define SLIM_DLLIMPORT
#endif



#endif /* NFLC_SLIM_DUMMY_H */
