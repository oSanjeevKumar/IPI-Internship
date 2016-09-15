/*
	memory.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/memory.h 117   06/05/02 23:36 Kimura $ */

#ifndef SLIM_MEMORY_H_PRIVATE
#define SLIM_MEMORY_H_PRIVATE

#ifdef SLIM_CONFIG_MOD_MEMORY

#include <slim/basis/mmemory.h>

#else

/* include */
#include <slim/private/basis/memory_a.h>
#include <slim/private/basis/memory_s.h>

#ifdef SLIM_CONFIG_MEMORY_EXTERNAL
#include <slim/private/basis/memory_e.h>
#else
#include <slim/private/basis/mmapimap.h>
#endif

SLIM_BEGIN_C_LINKAGE

/* CAUTION:
 * DO NOT write any memory manager dependent code in this file.
 * This file must consist entirely of independent/common codes.
 */

/* common */
#define SLIM_MEMORY_BLOG_SHIFT_MASK	(((slim_int)1<<(32-SLIM_MEMORY_BLOG))-1)

#ifdef SLIM_CONFIG_MEMORY_DEBUG
typedef slim_bool (*Slim_MemoryRandomAllocFailureProc)(void);
#endif

/* aliases */
#define SLIM_MEMORY_MUTEX_LOCK()	slim_memory_mutex_lock()
#define SLIM_MEMORY_MUTEX_UNLOCK()	slim_memory_mutex_unlock()
#define SLIM_MEMNODE_INSAMEPAGE(p1,p2)	MemNode_IsPixInSamePage((p1),(p2))

#define SLIM_MEMNODE_DEBUG_VALID_PIX(memnode,pix) TMemNode_IsValidPix((memnode),(pix))
#define SLIM_MEMNODE_DEBUG_VALID_PIX_OR_NIL(memnode,pix) TMemNode_IsValidPixOrNil((memnode),(pix))

#define TMemNode_VerifyPixOrNil(memnode, pix) ((pix) ? TMemNode_VerifyPix((memnode), (pix)) : (void)0)

#ifdef SLIM_CONFIG_POINTER_MEMNODE
#define TPtrMemNode_VerifyPixOrNil(memnode, pix) ((pix) ? TPtrMemNode_VerifyPix((memnode), (pix)) : (void)0)
#endif

SLIM_END_C_LINKAGE

#endif

#endif
