/*
	memory.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/memory.h 119   06/07/13 21:15 Siu $ */

#ifndef SLIM_MEMORY_H
#define SLIM_MEMORY_H

SLIM_BEGIN_C_LINKAGE

typedef slim_bool (*SLIM_MemoryNewHandlerProc)(slim_opaque in_arg, slim_int in_size);

SLIM_END_C_LINKAGE

#ifdef SLIM_CONFIG_MOD_MEMORY

#include <slim/basis/mmemory.h>

#else

#ifndef SLIM_BASE_H
#include <slim/basis/base.h>
#endif

SLIM_BEGIN_C_LINKAGE

/* CAUTION:
 * DO NOT write any memory manager dependent code in this file.
 * This file must consist entirely of independent/common codes.
 */

/* config */
#ifndef SLIM_MEMORY_BSIZE
#define SLIM_MEMORY_BSIZE			4096	/* Block size. It must be power of 2 */
#endif
#ifndef SLIM_MEMORY_BLOG
#define SLIM_MEMORY_BLOG			12		/* log2(SLIM_MEMORY_BSIZE) */
#endif

#define SLIM_MEMNODE_DEFAULT_HANDLES	2

#ifdef SLIM_CONFIG_MEMORY_CHECKOW_DEBUG
#define SLIM_MEMORY_CHECKOW			0xCD
#define SLIM_MEMORY_CHECKOW_SIZE	4
#define SLIM_MEMORY_CHECKOW_BYTES	(SLIM_ROUNDUP_P2(SLIM_MEMORY_CHECKOW_SIZE, SLIM_CONFIG_CC_STRUCTALIGN))
#else
#define SLIM_MEMORY_CHECKOW_BYTES	0
#endif

#if defined SLIM_CONFIG_MEMORY_DEBUG || defined SLIM_CONFIG_MEMORY_DEBUG_ALTERNATIVE
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
	SLIM_MEMORY_DEBUGNOTIFICATIONS
};
typedef void (*SLIM_MemoryAllocFreeDebugNotifyProc)(slim_int code, void *addr1, void *addr2, slim_int sz1, slim_int sz2, slim_word from);
#endif

SLIM_END_C_LINKAGE

/* include */
#include <slim/basis/memory_a.h>
#include <slim/basis/memory_s.h>

#ifdef SLIM_CONFIG_MEMORY_EXTERNAL
#include <slim/basis/memory_e.h>
#else
#include <slim/basis/mmapimap.h>
#endif

#endif

#endif
