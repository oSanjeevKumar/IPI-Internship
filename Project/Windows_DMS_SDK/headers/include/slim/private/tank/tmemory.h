/*
    (private) tmemory.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_PRIVATE_MEMORY_H_MODULE
#define SLIM_PRIVATE_MEMORY_H_MODULE

/*
 * DO NOT write memory manager dependent code in this file.
 * DO NOT write public structure in this file.
 */

SLIM_BEGIN_C_LINKAGE

/* common */
#define SLIM_MEMORY_BLOG_SHIFT_MASK (((slim_int)1<<(32-SLIM_MEMORY_BLOG))-1)

#ifdef SLIM_CONFIG_MEMORY_DEBUG
typedef slim_bool (*Slim_MemoryRandomAllocFailureProc)(void);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */

/* aliases */
#define SLIM_MEMORY_MUTEX_LOCK()    slim_memory_mutex_lock()
#define SLIM_MEMORY_MUTEX_UNLOCK()  slim_memory_mutex_unlock()
#define SLIM_MEMNODE_INSAMEPAGE(p1,p2)  MemNode_IsPixInSamePage((p1),(p2))

#define SLIM_MEMNODE_DEBUG_VALID_PIX(memnode,pix) TMemNode_IsValidPix((memnode),(pix))
#define SLIM_MEMNODE_DEBUG_VALID_PIX_OR_NIL(memnode,pix) TMemNode_IsValidPixOrNil((memnode),(pix))

#define TMemNode_VerifyPixOrNil(memnode, pix) ((pix) ? TMemNode_VerifyPix((memnode), (pix)) : (void)0)

#ifdef SLIM_CONFIG_POINTER_MEMNODE
#define TPtrMemNode_VerifyPixOrNil(memnode, pix) ((pix) ? TPtrMemNode_VerifyPix((memnode), (pix)) : (void)0)
#endif /* defined(SLIM_CONFIG_POINTER_MEMNODE) */

SLIM_END_C_LINKAGE

#include <slim/private/tank/tmtank.h>
#include <slim/private/tank/tmreplay.h>
#include <slim/private/tank/tmapimap.h>
#include <slim/private/tank/tmverify.h>
#include <slim/private/tank/mem_rslv.h>

#endif /* !defined(SLIM_PRIVATE_MEMORY_H_MODULE) */
