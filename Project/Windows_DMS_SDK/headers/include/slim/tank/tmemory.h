/*
    tmemory.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_PUBLIC_MEMORY_H_MODULE
#define SLIM_PUBLIC_MEMORY_H_MODULE

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif /* !defined(SLIM_BASE_H) */

SLIM_BEGIN_C_LINKAGE

/*
 * Define default block size if not defined.
 */

#ifndef SLIM_MEMORY_BSIZE
	#define SLIM_MEMORY_BSIZE       4096    /* Block size. It must be power of 2 */
#endif /* !defined(SLIM_MEMORY_BSIZE) */

#ifndef SLIM_MEMORY_BLOG
	#define SLIM_MEMORY_BLOG        12      /* log2(SLIM_MEMORY_BSIZE) */
#endif /* !defined(SLIM_MEMORY_BLOG) */

/* #define SLIM_TANK_REPLAY *//* Uncomment if you use 'replay' feature. */
#ifndef SLIM_CONFIG_MEMORY_DEBUG
	#undef SLIM_TANK_REPLAY
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

#define SLIM_MEMNODE_DEFAULT_HANDLES    2

#ifdef SLIM_CONFIG_MEMORY_DEBUG
enum {
    SLIM_MEMORY_DEBUGNOTIFY_INITHEAP,
    SLIM_MEMORY_DEBUGNOTIFY_ALLOCMPTRBLK,
    SLIM_MEMORY_DEBUGNOTIFY_FREEMPTRBLK,
    SLIM_MEMORY_DEBUGNOTIFY_ALLOCMEMORY,
    SLIM_MEMORY_DEBUGNOTIFY_FREEMEMORY,
    SLIM_MEMORY_DEBUGNOTIFY_REALLOCMEMORY,
    SLIM_MEMORY_DEBUGNOTIFY_ALLOCHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_FREEHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_LOCKHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_LOCATEHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_ALLOCVHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_FREEVHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_LOCKVHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_LOCATEVHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_REALLOCVHANDLE,
    SLIM_MEMORY_DEBUGNOTIFY_MOVEBLOCK,
    SLIM_MEMORY_DEBUGNOTIFY_FINALIZE,
    SLIM_MEMORY_DEBUGNOTIFY_CREATETANK,
    SLIM_MEMORY_DEBUGNOTIFY_DESTROYTANK,
    SLIM_MEMORY_DEBUGNOTIFY_ATTACHTANK,
    SLIM_MEMORY_DEBUGNOTIFY_DETACHTANK,
    SLIM_MEMORY_DEBUGNOTIFY_ALERT,
    SLIM_MEMORY_DEBUGNOTIFICATIONS
};
typedef void (*SLIM_MemoryAllocFreeDebugNotifyProc)(slim_int code, void *addr1, void *addr2, slim_int sz1, slim_int sz2, slim_word from, void *in_tank1, void *in_tank2);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */

SLIM_END_C_LINKAGE

#include <slim/tank/tmtank.h>
#include <slim/tank/tmapimap.h>

#ifdef SLIM_TANK_REPLAY
#include <slim/private/tank/tmreplay.h>
#endif /* defined(SLIM_TANK_REPLAY) */

#endif /* !defined(SLIM_PUBLIC_MEMORY_H_MODULE) */
