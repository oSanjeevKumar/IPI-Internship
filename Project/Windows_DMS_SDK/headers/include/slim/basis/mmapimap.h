/*
	mmapimap.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/mmapimap.h 8     05/12/28 12:07 Someya $ */

#ifndef SLIM_MEMORY_API_MAPPING_H
#define SLIM_MEMORY_API_MAPPING_H

SLIM_BEGIN_C_LINKAGE

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
typedef TAltMemNode TMemNode;
#define SLIM_MEMMANPREFIX_MEM	slim_alt

#else /* SLIM_CONFIG_MEMORY_ALTERNATIVE */
#ifdef SLIM_CONFIG_MEMORY_STANDARD
typedef TStdMemNode TMemNode;
#define SLIM_MEMMANPREFIX_MEM	slim_std

#else /* SLIM_CONFIG_MEMORY_STANDARD */
#error SLIM_CONFIG_MEMORY_EXTERNAL must be defined

#endif /* SLIM_CONFIG_MEMORY_STANDARD */
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

#define SLIM_MEMMAN_FUNCGEN(prefix, body) SLIM_PASTE(prefix,body)

/* ATTENTION!
 * if you append any API below, you must also append them to memory_e.h
 */

/*
 * memory manager API
 */

/* mutex */
#define slim_memory_set_mutex(mux)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_set_mutex((mux)))  
#define slim_memory_mutex_lock()	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_mutex_lock())    
#define slim_memory_mutex_unlock()	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_mutex_unlock())  

/* memory */
#define slim_memory_initialize(start, len)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_initialize((start),(len)))
#define slim_memory_set_new_handler(cb, arg) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_set_new_handler((cb),(arg)))
#define slim_memory_clear_new_handler(cb, arg) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_clear_new_handler((cb),(arg)))
#define slim_memory_finalize()				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_finalize())
#define slim_memory_compact()				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_compact())
#define slim_memory_disable_compact(b)			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_disable_compact((b)))

#define slim_memory_alloc(sz)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_alloc((sz)))
#define slim_memory_zeroalloc(sz)			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_zeroalloc((sz)))
#define slim_memory_free(m)					SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_free((m)))
#define slim_memory_realloc(m, sz)			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_realloc((m),(sz)))

/* handle */
#define slim_handle_alloc(sz) 				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_alloc((sz)))
#define slim_handle_zeroalloc(sz) 			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_zeroalloc((sz)))
#define slim_handle_calloc(elem, elem_sz)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_calloc(elem, elem_sz))
#define slim_handle_free(h) 				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_free((h)))

#define slim_handle_lock(h) 				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_lock((h)))
#define slim_handle_unlock(h)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_unlock((h)))
#define slim_handle_locate(h) 				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_locate((h)))
#define slim_handle_unlocate(h)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_unlocate((h)))
#define slim_handle_size(h)					SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_size((h)))


/* vhandle */
#define slim_vhandle_alloc(sz)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_alloc((sz)))
#define slim_vhandle_zeroalloc(sz)			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_zeroalloc((sz)))
#define slim_vhandle_calloc(elem, elem_sz)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_calloc(elem, elem_sz))
#define slim_vhandle_free(v)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_free((v)))
#define slim_vhandle_realloc(v, sz)			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_realloc((v),(sz)))

#define slim_vhandle_lock(h) 				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_lock((h)))
#define slim_vhandle_unlock(h)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_unlock((h)))
#define slim_vhandle_locate(h)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_locate((h)))
#define slim_vhandle_unlocate(h)			SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_unlocate((h)))
#define slim_vhandle_size(v)				SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_size((v)))

/* debug */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define slim_memory_debug_set_notify_proc(proc) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_debug_set_notify_proc((proc)))
#else
#define slim_memory_debug_set_notify_proc(proc) ((void)0)
#endif

SLIM_END_C_LINKAGE
#endif
