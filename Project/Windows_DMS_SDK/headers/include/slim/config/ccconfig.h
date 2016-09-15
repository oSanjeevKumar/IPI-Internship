/*
	ccconfig.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

#ifndef SLIM_CC_CONFIG_H
#define SLIM_CC_CONFIG_H

#include <stddef.h>
#include <stdint.h>
#ifndef WIN32 
#include <unistd.h> /* intptr_t */
#endif
/*                 */
/* compiler config */
/*                 */

/*
 * Options for Dynamic Link Library
 */
#ifndef SLIM_DLLEXPORT
#define SLIM_DLLEXPORT
#endif

#ifndef SLIM_DLLIMPORT
#define SLIM_DLLIMPORT
#endif


#define SLIM_API /* DO NOT set this value here */

/*
	Configurations for architectures below are supported. 
	You can define one of them in config.h of your project or,
  
	SLIM_CONFIG_CC_X86
	SLIM_CONFIG_CC_SH_BE
	SLIM_CONFIG_CC_ARM_LE
	SLIM_CONFIG_CC_ARM_BE
	SLIM_CONFIG_CC_POWERPC_BE

	You can specify each features below one by one. 
	You don't have to define those if you define one of symbol above.

	SLIM_CONFIG_CC_BIGENDIAN
		Define SLIM_CONFIG_CC_BIGENDIAN if you have a big endian processor,
		undef the symbol if you have a little endian one.

	SLIM_CONFIG_CC_ALLOW_UNALIGNED
		Define this if your processor can write a 16 bit word or a 32 bit word 
		to the position which is not aligned. Enable if you have X86 processor.
*/

#ifdef SLIM_CONFIG_CC_X86
#undef  SLIM_CONFIG_CC_BIGENDIAN
#define SLIM_CONFIG_CC_ALLOW_UNALIGNED
#endif

#ifdef SLIM_CONFIG_CC_SH_BE
#define SLIM_CONFIG_CC_BIGENDIAN
#undef  SLIM_CONFIG_CC_ALLOW_UNALIGNED
#endif

#ifdef SLIM_CONFIG_CC_ARM_LE
#undef  SLIM_CONFIG_CC_BIGENDIAN
#undef  SLIM_CONFIG_CC_ALLOW_UNALIGNED
#endif

#ifdef SLIM_CONFIG_CC_ARM_BE
#define SLIM_CONFIG_CC_BIGENDIAN
#undef  SLIM_CONFIG_CC_ALLOW_UNALIGNED
#endif

#ifdef SLIM_CONFIG_CC_POWERPC_BE
#define SLIM_CONFIG_CC_BIGENDIAN
#undef  SLIM_CONFIG_CC_ALLOW_UNALIGNED
#endif

#ifdef __cplusplus
#define SLIM_CONFIG_CC_NIL (0)
#else
#define SLIM_CONFIG_CC_NIL ((void *)0)
#endif

#ifdef SLIM_CONFIG_CC_32BIT
#define SLIM_CONFIG_CC_UI8JUST         unsigned char
#define SLIM_CONFIG_CC_SI8             signed char
#define SLIM_CONFIG_CC_SI16            short
#define SLIM_CONFIG_CC_UI16            unsigned short
#define SLIM_CONFIG_CC_SI32            int
#define SLIM_CONFIG_CC_UI32            unsigned int
#define SLIM_CONFIG_CC_CONST           const
#define SLIM_CONFIG_CC_STRUCTALIGN     (4)
#define SLIM_CONFIG_CC_STRUCTALIGN_LOG (2) /* log2(SLIM_CONFIG_CC_STRUCTALIGN) */
#define SLIM_CONFIG_CC_DOUBLE          double
#define SLIM_CONFIG_CC_SI64            int64_t
#define SLIM_CONFIG_CC_UI64            uint64_t
#endif /* SLIM_CONFIG_CC_32BIT */

#ifdef ENABLE_64BIT_SUPPORT
#define SLIM_CONFIG_CC_UICPU_BITS    (64)
#else /* ENABLE_64BIT_SUPPORT */
#ifdef SLIM_CONFIG_CC_32BIT
#define SLIM_CONFIG_CC_UICPU_BITS    (32)
#endif /* SLIM_CONFIG_CC_32BIT */
#endif /* ENABLE_64BIT_SUPPORT */

/* Guaranteed to be 32/64 bit depending on the platform. */
#define SLIM_CONFIG_CC_IADDR         intptr_t
#define SLIM_CONFIG_CC_UIADDR        uintptr_t
#define SLIM_CONFIG_CC_UICPU         uintptr_t
#define SLIM_CONFIG_CC_SIZE          size_t

/*
	SLIM_CONFIG_CC_PEEK_nn_en(addr)
	SLIM_CONFIG_CC_POKE_nn_en(addr,value)

	nn ... 16 | 32
	en ... NE | RE | LE | BE

	NE: native endian
	RE: reverse endian
	LE: little endian
	BE: big endian
*/

#define SLIM_CONFIG_CC_PEEK_16_LE(a) \
    ( ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)) <<  8) \
	| ((*((SLIM_CONFIG_CC_UI8JUST *)(a)    ))      ))
#define SLIM_CONFIG_CC_PEEK_16_BE(a) \
    ( ((*((SLIM_CONFIG_CC_UI8JUST *)(a)    )) <<  8) \
	| ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1))      ))
#define SLIM_CONFIG_CC_PEEK_32_LE(a) \
	( ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 3)) << 24) \
    | ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 2)) << 16) \
	| ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)) <<  8) \
    | ((*((SLIM_CONFIG_CC_UI8JUST *)(a)    ))      ))
#define SLIM_CONFIG_CC_PEEK_32_BE(a) \
	( ((*((SLIM_CONFIG_CC_UI8JUST *)(a)    )) << 24) \
    | ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)) << 16) \
	| ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 2)) <<  8) \
    | ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 3))      ))
#define SLIM_CONFIG_CC_POKE_16_LE(a,v)                  \
    ((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)              \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >> 8) & 0x00FF)), \
     (*((SLIM_CONFIG_CC_UI8JUST *)(a)    )              \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v)     ) & 0x00FF)))
#define SLIM_CONFIG_CC_POKE_16_BE(a,v)                  \
    ((*((SLIM_CONFIG_CC_UI8JUST *)(a)    )              \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >> 8) & 0x00FF)), \
     (*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)              \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v)     ) & 0x00FF)))
#define SLIM_CONFIG_CC_POKE_32_LE(a,v)                       \
    ((*((SLIM_CONFIG_CC_UI8JUST *)(a)     )                  \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v)      ) & 0x000000FF)), \
	 (*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >>  8) & 0x000000FF)), \
	 (*((SLIM_CONFIG_CC_UI8JUST *)(a) + 2)                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >> 16) & 0x000000FF)), \
	 (*((SLIM_CONFIG_CC_UI8JUST *)(a) + 3)                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >> 24) & 0x000000FF)))
#define SLIM_CONFIG_CC_POKE_32_BE(a,v)                       \
	((*((SLIM_CONFIG_CC_UI8JUST *)(a) + 3)                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v)      ) & 0x000000FF)), \
	 (*((SLIM_CONFIG_CC_UI8JUST *)(a) + 2)                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >>  8) & 0x000000FF)), \
	 (*((SLIM_CONFIG_CC_UI8JUST *)(a) + 1)                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >> 16) & 0x000000FF)), \
	 (*((SLIM_CONFIG_CC_UI8JUST *)(a)    )                   \
	  = (SLIM_CONFIG_CC_UI8JUST)(((v) >> 24) & 0x000000FF)))

#define SLIM_CONFIG_CC_PEEK_16_NE(a) \
    (*(SLIM_CONFIG_CC_UI16 *)(a))
#define SLIM_CONFIG_CC_PEEK_32_NE(a) \
    (*(SLIM_CONFIG_CC_UI32 *)(a))

#define SLIM_CONFIG_CC_POKE_16_NE(a,v) \
    (*(SLIM_CONFIG_CC_UI16 *)(a)       \
    = (SLIM_CONFIG_CC_UI16)(v))
#define SLIM_CONFIG_CC_POKE_32_NE(a,v) \
    (*(SLIM_CONFIG_CC_UI32 *)(a)       \
	= (SLIM_CONFIG_CC_UI32)(v))

#ifdef SLIM_CONFIG_CC_BIGENDIAN
#define SLIM_CONFIG_CC_PEEK_16_RE(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#else
#define SLIM_CONFIG_CC_PEEK_16_RE(a) SLIM_CONFIG_CC_PEEK_16_BE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE(a) SLIM_CONFIG_CC_PEEK_32_BE((a))
#endif /* SLIM_CONFIG_CC_BIGENDIAN */


#define SLIM_CONFIG_CC_POKE_16_RE(a,v)           \
    (*(SLIM_CONFIG_CC_UI16 *)(a)                  \
    = (SLIM_CONFIG_CC_UI16)((((v) >> 8) & 0x00FF) \
						  | (((v) << 8) & 0xFF00)))
#define SLIM_CONFIG_CC_POKE_32_RE(a,v)                \
	(*(SLIM_CONFIG_CC_UI32 *)(a)                       \
	= (SLIM_CONFIG_CC_UI32)((((v) >> 24) & 0x000000FF) \
	                      | (((v) >>  8) & 0x0000FF00) \
	                      | (((v) <<  8) & 0x00FF0000) \
	                      | (((v) << 24) & 0xFF000000)))

/*
	SLIM_CONFIG_CC_PEEK_nn_en_al(addr)
	SLIM_CONFIG_CC_POKE_nn_en_al(addr,value)
  
	nn ... 16 | 32
	en ... NE | RE | LE | BE
	al ... AL | UA

	NE: native endian
	RE: reverse endian
	LE: little endian
	BE: big endian

	AL: address is assumed to be aligned at (nn / 8).
	UA: address is not assumed to be aligned at (nn / 8).
*/

#ifdef SLIM_CONFIG_CC_BIGENDIAN
#ifdef SLIM_CONFIG_CC_ALLOW_UNALIGNED

#define SLIM_CONFIG_CC_PEEK_16_NE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_NE_UA(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_AL(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_UA(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_AL(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_UA(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_UA(a) SLIM_CONFIG_CC_PEEK_16_NE((a))

#define SLIM_CONFIG_CC_PEEK_32_NE_AL(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_NE_UA(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_AL(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_UA(a)	SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_AL(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_UA(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_AL(a)	SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_UA(a)	SLIM_CONFIG_CC_PEEK_32_NE((a))

#define SLIM_CONFIG_CC_POKE_16_NE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_NE_UA(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_AL(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_AL(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_UA(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))

#define SLIM_CONFIG_CC_POKE_32_NE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_NE_UA(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_AL(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_AL(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_UA(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))

#else /* !defined(SLIM_CONFIG_CC_ALLOW_UNALIGNED) */

#define SLIM_CONFIG_CC_PEEK_16_NE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_NE_UA(a) SLIM_CONFIG_CC_PEEK_16_BE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_AL(a) SLIM_CONFIG_CC_PEEK_16_RE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_UA(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_AL(a) SLIM_CONFIG_CC_PEEK_16_RE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_UA(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_UA(a) SLIM_CONFIG_CC_PEEK_16_BE((a))

#define SLIM_CONFIG_CC_PEEK_32_NE_AL(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_NE_UA(a) SLIM_CONFIG_CC_PEEK_32_BE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_AL(a) SLIM_CONFIG_CC_PEEK_32_RE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_UA(a)	SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_AL(a) SLIM_CONFIG_CC_PEEK_32_RE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_UA(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_AL(a)	SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_UA(a) SLIM_CONFIG_CC_PEEK_32_BE((a))

#define SLIM_CONFIG_CC_POKE_16_NE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_NE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_AL(a,v) SLIM_CONFIG_CC_POKE_16_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_AL(a,v) SLIM_CONFIG_CC_POKE_16_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))

#define SLIM_CONFIG_CC_POKE_32_NE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_NE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_AL(a,v) SLIM_CONFIG_CC_POKE_32_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_AL(a,v) SLIM_CONFIG_CC_POKE_32_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))

#endif /* SLIM_CONFIG_CC_ALLOW_UNALIGNED */
#else /* !defined(SLIM_CONFIG_CC_BIGENDIAN) */
#ifdef SLIM_CONFIG_CC_ALLOW_UNALIGNED

#define SLIM_CONFIG_CC_PEEK_16_NE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_NE_UA(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_AL(a) SLIM_CONFIG_CC_PEEK_16_BE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_UA(a) SLIM_CONFIG_CC_PEEK_16_BE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_UA(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_AL(a) SLIM_CONFIG_CC_PEEK_16_BE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_UA(a) SLIM_CONFIG_CC_PEEK_16_BE((a))

#define SLIM_CONFIG_CC_PEEK_32_NE_AL(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_NE_UA(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_AL(a) SLIM_CONFIG_CC_PEEK_32_BE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_UA(a)	SLIM_CONFIG_CC_PEEK_32_BE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_AL(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_UA(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_AL(a)	SLIM_CONFIG_CC_PEEK_32_BE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_UA(a)	SLIM_CONFIG_CC_PEEK_32_BE((a))

#define SLIM_CONFIG_CC_POKE_16_NE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_NE_UA(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_AL(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_UA(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_AL(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))

#define SLIM_CONFIG_CC_POKE_32_NE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_NE_UA(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_AL(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_UA(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_AL(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))

#else /* !defined(SLIM_CONFIG_CC_ALLOW_UNALIGNED) */

#define SLIM_CONFIG_CC_PEEK_16_NE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_NE_UA(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_AL(a) SLIM_CONFIG_CC_PEEK_16_RE((a))
#define SLIM_CONFIG_CC_PEEK_16_RE_UA(a) SLIM_CONFIG_CC_PEEK_16_BE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_AL(a) SLIM_CONFIG_CC_PEEK_16_NE((a))
#define SLIM_CONFIG_CC_PEEK_16_LE_UA(a) SLIM_CONFIG_CC_PEEK_16_LE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_AL(a) SLIM_CONFIG_CC_PEEK_16_RE((a))
#define SLIM_CONFIG_CC_PEEK_16_BE_UA(a) SLIM_CONFIG_CC_PEEK_16_BE((a))

#define SLIM_CONFIG_CC_PEEK_32_NE_AL(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_NE_UA(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_AL(a) SLIM_CONFIG_CC_PEEK_32_RE((a))
#define SLIM_CONFIG_CC_PEEK_32_RE_UA(a)	SLIM_CONFIG_CC_PEEK_32_BE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_AL(a) SLIM_CONFIG_CC_PEEK_32_NE((a))
#define SLIM_CONFIG_CC_PEEK_32_LE_UA(a) SLIM_CONFIG_CC_PEEK_32_LE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_AL(a) SLIM_CONFIG_CC_PEEK_32_RE((a))
#define SLIM_CONFIG_CC_PEEK_32_BE_UA(a) SLIM_CONFIG_CC_PEEK_32_BE((a))

#define SLIM_CONFIG_CC_POKE_16_NE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_NE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_AL(a,v) SLIM_CONFIG_CC_POKE_16_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_RE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_AL(a,v) SLIM_CONFIG_CC_POKE_16_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_LE_UA(a,v) SLIM_CONFIG_CC_POKE_16_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_AL(a,v) SLIM_CONFIG_CC_POKE_16_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_16_BE_UA(a,v) SLIM_CONFIG_CC_POKE_16_BE((a),(v))

#define SLIM_CONFIG_CC_POKE_32_NE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_NE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_AL(a,v) SLIM_CONFIG_CC_POKE_32_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_RE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_AL(a,v) SLIM_CONFIG_CC_POKE_32_NE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_LE_UA(a,v) SLIM_CONFIG_CC_POKE_32_LE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_AL(a,v) SLIM_CONFIG_CC_POKE_32_RE((a),(v))
#define SLIM_CONFIG_CC_POKE_32_BE_UA(a,v) SLIM_CONFIG_CC_POKE_32_BE((a),(v))

#endif /* SLIM_CONFIG_CC_ALLOW_ALIGN */
#endif /* SLIM_CONFIG_CC_LITTLEENDIAN */

#endif /* SLIM_CC_CONFIG_H */
