/* MD5.H - header file for MD5C.C
 */
#ifndef MD5_H
#define MD5_H

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.

License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.

License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.
These notices must be retained in any copies of any part of this
documentation and/or software.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* md5global.h is put at here. */

/* PROTOTYPES should be set to one if and only if the compiler supports
  function argument prototyping.
The following makes PROTOTYPES default to 0 if it has not already
  been defined with C compiler flags.
 */
#ifndef PROTOTYPES
#define PROTOTYPES 1
#endif

/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;

typedef signed char INT1;       /*  8 bits */
typedef short INT2;         /* 16 bits */
typedef int INT4;           /* 32 bits */
/* There is no 64 bit type */
typedef unsigned char UINT1;        /*  8 bits */
typedef unsigned short UINT2;       /* 16 bits */
typedef unsigned int UINT4;     /* 32 bits */
/* There is no 64 bit type */

/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
returns an empty list.
*/
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif

/* md5global.h ends at here. */

/* MD5 context. */
typedef struct {
  UINT4 state[4];                                   /* state (ABCD) */
  UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
  unsigned char buffer[64];                         /* input buffer */
} MD5_CTX;

void dlna_MD5Init PROTO_LIST ((MD5_CTX *));
void dlna_MD5Update PROTO_LIST ((MD5_CTX *, unsigned char *, unsigned int));
void dlna_MD5Final PROTO_LIST ((unsigned char [16], MD5_CTX *));

#ifdef __cplusplus
}
#endif

#endif /* MD5_H */
