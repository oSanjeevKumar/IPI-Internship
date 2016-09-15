/*
	memory_s.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/memory_s.h 15    05/12/28 12:07 Someya $ */

#ifndef SLIM_MEMORY_STANDARD_H
#define SLIM_MEMORY_STANDARD_H

SLIM_BEGIN_C_LINKAGE

/* mutex */

#ifdef SLIM_CONFIG_MULTITHREAD
#else
#define slim_std_memory_set_mutex(mux)		((void)0)
#endif

/*
 * memory management
 */

/* memory */

/* handle */


#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
#define slim_std_handle_locate(h) (slim_std_handle_lock((h)))
#define slim_std_handle_unlocate(h) (slim_std_handle_unlock((h)))
#else
#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define slim_std_handle_locate(h) (slim_std_handle_locate_d((h)))
#define slim_std_handle_unlocate(h) (slim_std_handle_unlocate_d((h)))
#else
#define slim_std_handle_locate(h) (*(void **)(h))
#define slim_std_handle_unlocate(h) ((void)0)
#endif
#endif

/* vhandle */


#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
#define slim_std_vhandle_locate(h) (slim_std_vhandle_lock((h)))
#define slim_std_vhandle_unlocate(h) (slim_std_vhandle_unlock((h)))
#else
#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define slim_std_vhandle_locate(h) (slim_std_vhandle_locate_d((h)))
#define slim_std_vhandle_unlocate(h) (slim_std_vhandle_unlocate_d((h)))
#else
#define slim_std_vhandle_locate(h) (*(void **)(h))
#define slim_std_vhandle_unlocate(h) ((void)0)
#endif
#endif

#ifdef SLIM_CONFIG_MEMORY_DEBUG
#else
#define slim_std_memory_debug_set_notify_proc(p) ((void)0)
#endif

/*
 * MemNode
 */

struct TStdMemNode_ {
	slim_handle *fHandles;
	slim_int fHandleSize;
	slim_int fUsedPages;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_int fFrom;
#endif
#ifdef SLIM_CONFIG_MEMNODE_DEBUG
	slim_int fID;
#endif
};
typedef struct TStdMemNode_ TStdMemNode;

#ifdef SLIM_CONFIG_POINTER_MEMNODE

struct TPtrMemNode_ {
	slim_handle *fHandles;
	slim_byte **fPtrs;
	slim_int fHandleSize;
	slim_int fUsedPages;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_int fFrom;
#endif
#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
	slim_int fID;
#endif
};
typedef struct TPtrMemNode_ TPtrMemNode;

#endif /* SLIM_CONFIG_POINTER_MEMNODE */

SLIM_END_C_LINKAGE
#endif
