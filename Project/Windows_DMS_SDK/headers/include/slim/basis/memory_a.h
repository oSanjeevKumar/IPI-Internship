/*
	memory_a.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/memory_a.h 48    06/03/15 17:21 Iida $ */

#ifndef SLIM_MEMORY_ALTERNATIVE_H
#define SLIM_MEMORY_ALTERNATIVE_H

SLIM_BEGIN_C_LINKAGE

/*
 * mutex
 */
#ifdef SLIM_CONFIG_MULTITHREAD
#else
#define slim_alt_memory_set_mutex(mux)		((void)0)
#endif

/*
 * memory management
 */
#define slim_alt_memory_compact()				{}
#define slim_alt_memory_disable_compact(b)				{}


/* memory */

#ifdef SLIM_CONFIG_MEMORY_DEBUG_ALTERNATIVE

typedef struct TDebugCell_ TDebugCell;
struct TDebugCell_{
	void* fPointer;
	slim_int fSize;
	TDebugCell *fNext;
};

#endif

/* handle */
#define slim_alt_handle_alloc(sz) 				((slim_handle)slim_alt_memory_alloc(sz))
#define slim_alt_handle_zeroalloc(sz) 			((slim_handle)slim_alt_memory_zeroalloc(sz))
#define slim_alt_handle_calloc(elem, elem_sz) 	((slim_handle)slim_alt_memory_zeroalloc((elem) * (elem_sz)))
#define slim_alt_handle_free(in_handle) 		(slim_alt_memory_free(in_handle))

#define slim_alt_handle_lock(h) 	((void *)(h))
#define slim_alt_handle_unlock(h)	((void)0)
#define slim_alt_handle_locate(h)	((void *)(h))
#define slim_alt_handle_unlocate(h)	((void)0)


/* vhandle */
#define slim_alt_vhandle_calloc(n,size) slim_alt_vhandle_zeroalloc((n)*(size))

#define slim_alt_vhandle_lock(h) 		(*(void **)(h))
#define slim_alt_vhandle_unlock(h)		((void)0)
#define slim_alt_vhandle_locate(h)		(*(void **)(h))
#define slim_alt_vhandle_unlocate(h)	((void)0)

#ifdef SLIM_CONFIG_MEMORY_DEBUG_ALTERNATIVE
#else
#define slim_alt_memory_debug_set_notify_proc(p) ((void)0)
#endif

/*
 * MemNode
 */

struct TAltMemNode_ {
	slim_handle *fHandles;
	slim_int fHandleSize;
	slim_int fUsedPages;
};
typedef struct TAltMemNode_ TAltMemNode;

SLIM_END_C_LINKAGE
#endif
