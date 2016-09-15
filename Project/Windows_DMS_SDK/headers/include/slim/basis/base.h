/*
	base.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/base.h 103   06/07/31 8:59 Someya $ */

#ifndef SLIM_BASE_H
#define SLIM_BASE_H

#ifndef SLIM_CONFIG_H
#include <slim/config/config.h>
#endif

/*                     */
/* C/C++ compatibility */
/*                     */

#ifdef __cplusplus
#define SLIM_BEGIN_C_LINKAGE extern "C" {
#define SLIM_END_C_LINKAGE   }
#else
#define SLIM_BEGIN_C_LINKAGE
#define SLIM_END_C_LINKAGE
#endif

SLIM_BEGIN_C_LINKAGE

/*                           */
/* basic types and constants */
/*                           */

/* null pointer */

#define slim_nil SLIM_CONFIG_CC_NIL

/* boolean */

typedef SLIM_CONFIG_CC_UI32 slim_bool;
#define slim_false 0
#define slim_true (!slim_false)

/* integral types */

typedef SLIM_CONFIG_CC_UI8JUST slim_byte;

typedef SLIM_CONFIG_CC_SI32 slim_int;
typedef SLIM_CONFIG_CC_SI16 slim_short;
typedef SLIM_CONFIG_CC_SI8 slim_tiny;
typedef SLIM_CONFIG_CC_UI32 slim_word;
typedef SLIM_CONFIG_CC_UI16 slim_half;
typedef SLIM_CONFIG_CC_SI64 slim_int64;

typedef SLIM_CONFIG_CC_IADDR     slim_iaddr_word;
typedef SLIM_CONFIG_CC_UIADDR    slim_uiaddr_word;
typedef SLIM_CONFIG_CC_UICPU     slim_cpu_word;
typedef SLIM_CONFIG_CC_SIZE      slim_size;

/* Integral types for optimization */
#define SLIM_CPU_BITS            SLIM_CONFIG_CC_UICPU_BITS


/* floating types */
typedef SLIM_CONFIG_CC_DOUBLE slim_double;

/* character and string */

typedef slim_byte slim_char;
#define SLIM_C(char_literal) (char_literal)
#define SLIM_T(text_literal) ((slim_char *)(text_literal))

/* opaque type */

struct slim_opaque_ {
  slim_iaddr_word fDummy;

};
typedef struct slim_opaque_ *slim_opaque;

/* fixed-point number */

typedef slim_int slim_fixed_point;
#define SLIM_FIXED_POINT(numer,denom)	(((numer) * 256) / (denom))
#define SLIM_FIXED_POINT_INT(n)			((n) / 256)
#define SLIM_FIXED_POINT_FRAC(n,mag)	(((n) < 0 ? -(-(n) % 256) : (n) % 256) * (mag) / 256)
#define SLIM_FIXED_POINT_MUL(n1,n2)		((n1) * (n2) / 256)
#define SLIM_FIXED_POINT_IMUL(n,i)		((n)*(i))
#define SLIM_FIXED_POINT_NUMER(n)		(n)
#define SLIM_FIXED_POINT_DENOM(n)		(256)

typedef slim_int slim_decimal_fixed_point;
#define SLIM_DECIMAL_FIXED_POINT(numer,denom)	(((numer) * 1000) / (denom))
#define SLIM_DECIMAL_FIXED_POINT_INT(n)			((n) / 1000)
#define SLIM_DECIMAL_FIXED_POINT_FRAC(n)		((n) < 0 ? (-(-(n) % 1000)) : ((n) % 1000))
#define SLIM_DECIMAL_FIXED_POINT_MUL(n1,n2)		((n1) * (n2) / 1000)
#define SLIM_DECIMAL_FIXED_POINT_IMUL(n,i)		((n)*(i))
#define SLIM_DECIMAL_FIXED_POINT_NUMER(n)		(n)
#define SLIM_DECIMAL_FIXED_POINT_DENOM(n)		(1000)
#define SLIM_DECIMAL_FIXED_POINT_FIGURE			(3)

/* limit */

#define SLIM_INT_MIN	(-2147483647-1)
#define SLIM_INT_MAX	2147483647
#define SLIM_SHORT_MIN	(-32767-1)
#define SLIM_SHORT_MAX	32767
#define SLIM_WORD_MAX	0xFFFFFFFF
#define SLIM_UINT_MAX	SLIM_WORD_MAX
#define SLIM_HALF_MAX	0xFFFF
#define SLIM_USHORT_MAX	SLIM_HALF_MAX
#define SLIM_INT64_MAX  0x7FFFFFFFFFFFFFFFLL

/* misc */
typedef void *slim_object;

#define SLIM_CONST SLIM_CONFIG_CC_CONST
#define SLIM_ROM SLIM_CONST

#define SLIM_PRIVATE static

struct slim_split_ss_ {
	slim_char *s;
	slim_int len;
};
typedef struct slim_split_ss_ slim_split_ss;

#ifdef SLIM_CONFIG_ENABLE_FILESYSTEM_PEER
/* file system */
typedef struct slim_dirent_ slim_dirent;
typedef struct slim_stat_ slim_stat;
#endif /* SLIM_CONFIG_ENABLE_FILESYSTEM_PEER */

/*                  */
/* peeker and poker */
/*                  */
/*
    SLIM_PEEK_nn_en_al(addr)
    SLIM_POKE_nn_en_al(addr,value)

    nn ... 16 | 32
    en ... NE | RE | LE | BE
           NE: native endian  RE: reverse endian  LE: little endian  BE: big endian
    al ... AL | UA
           AL: address is assumed to be aligned at (nn / 8).
           UA: address is not assumed to be aligned at (nn / 8).
*/
#define SLIM_PEEK_16_NE_AL(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_NE_AL((a)))
#define SLIM_PEEK_16_NE_UA(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_NE_UA((a)))
#define SLIM_PEEK_16_RE_AL(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_RE_AL((a)))
#define SLIM_PEEK_16_RE_UA(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_RE_UA((a)))
#define SLIM_PEEK_16_LE_AL(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_LE_AL((a)))
#define SLIM_PEEK_16_LE_UA(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_LE_UA((a)))
#define SLIM_PEEK_16_BE_AL(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_BE_AL((a)))
#define SLIM_PEEK_16_BE_UA(a) ((slim_half)SLIM_CONFIG_CC_PEEK_16_BE_UA((a)))
#define SLIM_PEEK_32_NE_AL(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_NE_AL((a)))
#define SLIM_PEEK_32_NE_UA(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_NE_UA((a)))
#define SLIM_PEEK_32_RE_AL(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_RE_AL((a)))
#define SLIM_PEEK_32_RE_UA(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_RE_UA((a)))
#define SLIM_PEEK_32_LE_AL(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_LE_AL((a)))
#define SLIM_PEEK_32_LE_UA(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_LE_UA((a)))
#define SLIM_PEEK_32_BE_AL(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_BE_AL((a)))
#define SLIM_PEEK_32_BE_UA(a) ((slim_word)SLIM_CONFIG_CC_PEEK_32_BE_UA((a)))

#define SLIM_POKE_16_NE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE_AL((a),(slim_half)(v))
#define SLIM_POKE_16_NE_UA(a,v) SLIM_CONFIG_CC_POKE_16_NE_UA((a),(slim_half)(v))
#define SLIM_POKE_16_RE_AL(a,v) SLIM_CONFIG_CC_POKE_16_RE_AL((a),(slim_half)(v))
#define SLIM_POKE_16_RE_UA(a,v) SLIM_CONFIG_CC_POKE_16_RE_UA((a),(slim_half)(v))
#define SLIM_POKE_16_LE_AL(a,v) SLIM_CONFIG_CC_POKE_16_LE_AL((a),(slim_half)(v))
#define SLIM_POKE_16_LE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE_UA((a),(slim_half)(v))
#define SLIM_POKE_16_BE_AL(a,v) SLIM_CONFIG_CC_POKE_16_BE_AL((a),(slim_half)(v))
#define SLIM_POKE_16_BE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE_UA((a),(slim_half)(v))
#define SLIM_POKE_32_NE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE_AL((a),(slim_word)(v))
#define SLIM_POKE_32_NE_UA(a,v) SLIM_CONFIG_CC_POKE_32_NE_UA((a),(slim_word)(v))
#define SLIM_POKE_32_RE_AL(a,v) SLIM_CONFIG_CC_POKE_32_RE_AL((a),(slim_word)(v))
#define SLIM_POKE_32_RE_UA(a,v) SLIM_CONFIG_CC_POKE_32_RE_UA((a),(slim_word)(v))
#define SLIM_POKE_32_LE_AL(a,v) SLIM_CONFIG_CC_POKE_32_LE_AL((a),(slim_word)(v))
#define SLIM_POKE_32_LE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE_UA((a),(slim_word)(v))
#define SLIM_POKE_32_BE_AL(a,v) SLIM_CONFIG_CC_POKE_32_BE_AL((a),(slim_word)(v))
#define SLIM_POKE_32_BE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE_UA((a),(slim_word)(v))

/*                */
/* utility macros */
/*                */

#define SLIM_MIN(x, y) ((x)<(y)?(x):(y))
#define SLIM_MAX(x, y) ((x)>(y)?(x):(y))
#define SLIM_ABS(n) ((n)>0?(n):-(n))
#define SLIM_POSITIVE_MOD(x, y) ((slim_int)((slim_word)(x)%(slim_word)(y)))
#define SLIM_POSITIVE_MOD_P2(x, y) ((slim_int)((slim_word)(x)&(slim_word)((y)-1)))

#define SLIM_ROUNDUP(x, y) ((((slim_int)(x)+((slim_int)(y)-1))/(slim_int)(y))*(slim_int)(y))
#define SLIM_ROUNDUP_P2(x, y) ((slim_int)(((slim_int)(x)+(slim_int)(y)-1)&~(slim_word)((y)-1)))
#define SLIM_ROUNDDOWN(x, y) ((slim_int)(x)/(slim_int)(y)*(slim_int)(y))
#define SLIM_ROUNDDOWN_P2(x, y) ((slim_word)((slim_word)(x)&~(slim_word)((y)-1)))

#define SLIM_ROUNDUP_U(x, y) ((((slim_word)(x)+((slim_word)(y)-1))/(slim_word)(y))*(slim_word)(y))
#define SLIM_ROUNDUP_U_P2(x, y) (((slim_word)(x)+(slim_word)(y)-1)&~(slim_word)((y)-1))
#define SLIM_ROUNDDOWN_U(x, y) ((slim_word)(x)/(slim_word)(y)*(slim_word)(y))
#define SLIM_ROUNDDOWN_U_P2(x, y) ((slim_word)(x)&~(slim_word)((y)-1))

#define SLIM_ROUNDUP_A_P2(x, y) ((void *)(((slim_uiaddr_word)(x)+(slim_uiaddr_word)(y)-1)&~(slim_uiaddr_word)((y)-1)))
#define SLIM_ROUNDDOWN_A_P2(x, y) ((void *)((slim_uiaddr_word)(x)&~(slim_uiaddr_word)((y)-1)))

#define SLIM_POWEROF2(n) (((slim_word)(n)&(slim_word)((n)-1)) == 0)
#define SLIM_ADDRESSALIGN(addr, n) (((slim_uiaddr_word)(addr)&(slim_uiaddr_word)((n)-1)) == 0)

#define SLIM_HOWMANY(x, y) (((slim_int)(x)+((slim_int)(y)-1))/(slim_int)(y))
#define SLIM_OFFSETOF(type, field) ((slim_uiaddr_word)&(((type *)0)->field))
#define SLIM_ARRAYSIZE(name) (sizeof(name)/sizeof(name[0]))

#define SLIM_PASTE(a, b) a##b

/*                         */
/* commonly used constants */
/*                         */

/* bitflag */

#define SLIM_FLAG_NONE	0 /* means no bit flag is on */

#define SLIM_STREAM_READ		0x00000001
#define SLIM_STREAM_WRITE		0x00000002
#define SLIM_STREAM_READWRITE	(SLIM_STREAM_READ|SLIM_STREAM_WRITE)
#define SLIM_STREAM_CREATE		0x00000004
#define SLIM_STREAM_TRUNCATE	0x00000008
#define SLIM_STREAM_EXCLUSIVE	0x00000010

#define SLIM_POLL_DONEBIT		1
#define SLIM_POLL_SIGBIT		2
#define SLIM_POLL_BITMASK		3
#define SLIM_POLL_SIGMASK		0xFFFFFFFC
#define SLIM_POLL_SIGSHIFT		2

#define SLIM_POLL_CONTINUE		0
#define SLIM_POLL_DONE			SLIM_POLL_DONEBIT
#define SLIM_POLL_BREAK			SLIM_POLL_SIGBIT
#define SLIM_POLL_ERROR			(SLIM_POLL_SIGBIT|SLIM_POLL_DONEBIT)
#define SLIM_POLL_SLEEP			(1 << SLIM_POLL_SIGSHIFT)

#define SLIM_POLL_FLAG(n)		((n)&SLIM_POLL_BITMASK)

#define SLIM_FLAG_OP(var,flag,val)	((val) ? ((var)->fFlag |= (flag)) : ((var)->fFlag &= ~(flag)))
#define SLIM_FLAG_CK(var,flag)		(((var)->fFlag & (flag)) != 0)

/* error */

enum {
	SLIM_E_OK						= 0,
	SLIM_E_GENERIC					= -1,
	SLIM_E_WOULDBLOCK				= -2,
	SLIM_E_IOSLEEP					= -3,
	SLIM_E_TIMEDOUT					= -4,
	SLIM_E_NOTFOUND					= -5,
	SLIM_E_NOMEM					= -6,
	SLIM_E_STRPIPE					= -7,
	SLIM_E_INVAL					= -8,
	SLIM_E_EOF				= -9,
	SLIM_E_NOTSUPPORTED				= -10,
	SLIM_E_FOUND					= -11,
	SLIM_E_enum_tail				= -12
};

/* seek */

enum {
	SLIM_SEEK_SET,
	SLIM_SEEK_CUR,
	SLIM_SEEK_END
};

/* direction */

enum {
	SLIM_UP,
	SLIM_DOWN,
	SLIM_LEFT,
	SLIM_RIGHT,
	SLIM_DIRECTIONS
};

/* value type */
enum {
	SLIM_VALUETYPE_VOID,
	SLIM_VALUETYPE_INTEGER,
	SLIM_VALUETYPE_BOOL,
	SLIM_VALUETYPE_STRING,
	SLIM_VALUETYPE_POINTER,
	SLIM_VALUETYPES
};
	

/*               */
/* memory handle */
/*               */

struct slim_handle_ {
	slim_byte *fData;
};
typedef struct slim_handle_ *slim_handle;

struct slim_vhandle_ {
	slim_byte *fData;
};
typedef struct slim_vhandle_ *slim_vhandle;

/*	   */
/* pix */
/*	   */

struct slim_pix_ {
    slim_iaddr_word dummy;
};

typedef struct slim_pix_ *slim_pix;

#define slim_pix_nil ((slim_pix)0)

/*                      */
/* offset - length pair */
/*                      */

struct slim_offlen_ {
	slim_int off;
	slim_int len;
};
typedef struct slim_offlen_ slim_offlen;

/*                    */
/* object identifiers */
/*                    */

typedef struct iTString_ **TString;
#ifndef SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING
typedef struct iTFixedString_ **TFixedString;
#else
typedef TString TFixedString;
#endif
typedef struct iTRegion_ **TRegion;

/*                   */
/* system heart beat */
/*                   */

#define slimGetTickCount() slimGetTickCountPeer()


/*
 * progress yielding
 */

#ifdef SLIM_CONFIG_USE_IS_YIELDING_PEER
#define slimIsYielding() slimIsYieldingPeer()
#else
#define slimIsYielding() (slim_false)
#endif


/*                            */
/* standard newline character */
/*                            */

#define SLIM_INTERNAL_NEWLINE	10

/*            					*/
/* IP address 					*/
/* (compliant with AVE-TCP Ver6)*/

struct slim_ip_addr_ {
	slim_int fType;
	slim_byte fAddr[16];
};
typedef struct slim_ip_addr_ slim_ip_addr;

#define SLIM_IP_ADDR_TYPE_ANY 0
#define SLIM_IP_ADDR_TYPE_V4 4
#define SLIM_IP_ADDR_TYPE_V6 6
#define SLIM_IP_ADDR_LEN_V4 4
#define SLIM_IP_ADDR_LEN_V6 16

#define slim_ip_addr_get_size(addr)	\
	(((addr).fType == SLIM_IP_ADDR_TYPE_V4) ? (sizeof(slim_int) + SLIM_IP_ADDR_LEN_V4) : \
	 (((addr).fType == SLIM_IP_ADDR_TYPE_V6) ? (sizeof(slim_int) + SLIM_IP_ADDR_LEN_V6) : 0))
#define slim_ip_addr_eq(addr1, addr2) \
	(((addr1).fType == (addr2).fType) && (slim_memcmp(&(addr1), &(addr2), slim_ip_addr_get_size(addr1)) == 0))


/*
 * Log
 */
#ifdef SLIM_CONFIG_DEBUG_LOG
enum {
	SLIM_LOG_SIGNAL_DOCSTART = 0,
	SLIM_LOG_SIGNAL_DOCDONE,
	SLIM_LOG_SIGNAL_REPAGEMAKE_BY_REPLACESTYLE,
	SLIM_LOG_SIGNAL_REFORMAT_BY_REPLACESTYLE,
	SLIM_LOG_SIGNAL_REPOSITION_BY_REPLACESTYLE,
	SLIM_LOG_SIGNAL_REDRAW_BY_REPLACESTYLE,

	SLIM_LOG_SIGNALs
};
#endif


/*
 * IOBuffer
 */
typedef struct TIOBuffer_ TIOBuffer;
struct TIOBuffer_ {
	slim_byte *fBuffer;
	slim_int fLength;
	slim_int fReadOff;
	slim_int fWriteOff;
	/* 0 <= fReadOff <= fWriteOff <= fLength */
};

/*
 * RingBuffer
 */
typedef struct TRingBuffer_ TRingBuffer;
struct TRingBuffer_ {
	TIOBuffer fBase;
};

/*
 * ElasticBuf
 */
typedef struct TElasticBuf_ TElasticBuf;
typedef void *(*ElasticBuf_LockUnlockProc)(slim_opaque in_userdata, slim_bool in_lock);
typedef slim_bool (*ElasticBuf_ReallocProc)(slim_opaque in_userdata, slim_int in_len);
struct TElasticBuf_ {
	slim_opaque fUserData;
	ElasticBuf_LockUnlockProc fLockUnlock;
	ElasticBuf_ReallocProc fRealloc;
	slim_int fLength;
	slim_int fBlockSize;
};

SLIM_END_C_LINKAGE
#endif /* SLIM_BASE_H */
