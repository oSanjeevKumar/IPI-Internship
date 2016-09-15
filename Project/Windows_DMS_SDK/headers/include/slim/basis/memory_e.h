/*
	memory_e.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/memory_e.h 14    06/07/07 19:30 Siu $ */

#ifndef SLIM_MEMORY_EXTERNAL_H
#define SLIM_MEMORY_EXTERNAL_H

SLIM_BEGIN_C_LINKAGE

/*
 * memory manager API
 */

/* mutex */
SLIM_API void slim_memory_set_mutex(slim_opaque in_mux);

/* memory */
SLIM_API slim_bool slim_memory_initialize(void *in_start, slim_int in_len);
SLIM_API slim_bool slim_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API void slim_memory_finalize(void);
SLIM_API void slim_memory_compact(void);
SLIM_API void slim_memory_disable_compact(slim_bool in_disable);

SLIM_API void *slim_memory_alloc(slim_int in_size);
SLIM_API void *slim_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_memory_free(void *in_memory);
SLIM_API void *slim_memory_realloc(void *in_memory, slim_int in_size);

/* handle */
SLIM_API slim_handle slim_handle_alloc(slim_int in_size);
SLIM_API slim_handle slim_handle_zeroalloc(slim_int in_size);
SLIM_API slim_handle slim_handle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_handle_free(slim_handle in_handle);

SLIM_API void *slim_handle_lock(slim_handle in_handle);
SLIM_API void slim_handle_unlock(slim_handle in_handle);
SLIM_API void *slim_handle_locate(slim_handle in_handle);
SLIM_API void slim_handle_unlocate(slim_handle in_handle);
SLIM_API slim_int slim_handle_size(slim_handle in_handle);


/* vhandle */
SLIM_API slim_vhandle slim_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_vhandle_zeroalloc(slim_int in_size);
SLIM_API slim_vhandle slim_vhandle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_vhandle_free(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);

SLIM_API void *slim_vhandle_lock(slim_vhandle in_vhandle);
SLIM_API void slim_vhandle_unlock(slim_vhandle in_vhandle);
SLIM_API void *slim_vhandle_locate(slim_vhandle in_vhandle);
SLIM_API void slim_vhandle_unlocate(slim_vhandle in_vhandle);
SLIM_API slim_int slim_vhandle_size(slim_vhandle in_vhandle);

/*
 * MemNode
 */
struct TMemNode_ {
	slim_opaque fUserData;
};
typedef struct TMemNode_ TMemNode;

/*
 * Debug
 */
#define slim_memory_debug_set_notify_proc(proc) ((void)0)

SLIM_END_C_LINKAGE
#endif
