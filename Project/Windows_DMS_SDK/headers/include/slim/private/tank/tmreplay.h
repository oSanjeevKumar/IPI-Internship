/*
    (private) tmreplay.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_MEMORY_REPLAY_H_PRIVATE_MODULE
#define SLIM_MEMORY_REPLAY_H_PRIVATE_MODULE

SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_TANK_REPLAY_CODE_COMMENT,
	SLIM_TANK_REPLAY_CODE_ALLOC_MEMORY_BEGIN,
	SLIM_TANK_REPLAY_CODE_ALLOC_MEMORY_END,
	SLIM_TANK_REPLAY_CODE_FREE_MEMORY,
	SLIM_TANK_REPLAY_CODE_REALLOC_MEMORY_BEGIN,
	SLIM_TANK_REPLAY_CODE_REALLOC_MEMORY_END,
	SLIM_TANK_REPLAY_CODE_ALLOC_HANDLE_BEGIN,
	SLIM_TANK_REPLAY_CODE_ALLOC_HANDLE_END,
	SLIM_TANK_REPLAY_CODE_FREE_HANDLE,
	SLIM_TANK_REPLAY_CODE_ALLOC_VHANDLE_BEGIN,
	SLIM_TANK_REPLAY_CODE_ALLOC_VHANDLE_END,
	SLIM_TANK_REPLAY_CODE_FREE_VHANDLE,
	SLIM_TANK_REPLAY_CODE_REALLOC_VHANDLE_BEGIN,
	SLIM_TANK_REPLAY_CODE_REALLOC_VHANDLE_END,
	SLIM_TANK_REPLAY_CODE_LOCK_HANDLE,
	SLIM_TANK_REPLAY_CODE_LOCK_VHANDLE,
	SLIM_TANK_REPLAY_CODE_COMPACT,
	SLIM_TANK_REPLAY_CODE_DISABLE_COMPACT,
	/* non SLIM_API */
	SLIM_TANK_REPLAY_CODE_SPAREALLOC_MEMORY_BEGIN,
	SLIM_TANK_REPLAY_CODE_SPAREALLOC_MEMORY_END,
	SLIM_TANK_REPLAY_CODE_SPAREALLOC_HANDLE_BEGIN,
	SLIM_TANK_REPLAY_CODE_SPAREALLOC_HANDLE_END,
	SLIM_TANK_REPLAY_CODE_SPAREALLOC_VHANDLE_BEGIN,
	SLIM_TANK_REPLAY_CODE_SPAREALLOC_VHANDLE_END,
	SLIM_TANK_REPLAY_CODE_MAX
};

#ifdef SLIM_TANK_REPLAY
	slim_bool slim_replay_record_open(slim_char *in_recording_filename);
	void slim_replay_record_close(void);
	void slim_replay_record_write(slim_int in_replay_code, void *in_addr, slim_int in_size, slim_int in_incdec, void *in_reallocated_addr);
	slim_bool slim_replay_play_line(slim_char *in_play_line);
	#define SLIM_REPLAY_OPEN(fn) slim_replay_record_open(fn)
	#define SLIM_REPLAY_CLOSE() slim_replay_record_close()
	#define SLIM_REPLAY_REPLAY(line) slim_replay_play_line(line)
	#define SLIM_REPLAY_LOG(a, b, c, d, e) slim_replay_record_write((a),(b),(c),(d),(e))
#else /* !defined(SLIM_TANK_REPLAY) */
	#define SLIM_REPLAY_OPEN(fn)			(slim_true)
	#define SLIM_REPLAY_CLOSE()				((void)0)
	#define SLIM_REPLAY_REPLAY(line)		((void)0)
	#define SLIM_REPLAY_LOG(a, b, c, d, e)	((void)0)
#endif /* !defined(SLIM_TANK_REPLAY) */

#ifdef SLIM_TANK_REPLAY
SLIM_API slim_bool slim_replay_memory_initialize(void *in_start, slim_int in_len);
SLIM_API void slim_replay_memory_finalize(void);
SLIM_API void slim_replay_memory_compact(void);
SLIM_API void slim_replay_memory_disable_compact(slim_bool in_disable);
SLIM_API void *slim_replay_memory_alloc(slim_int in_size);
/* not SLIM_API */ void *slim_replay_memory_sparealloc(slim_int in_size, slim_int in_spare_blocks);
SLIM_API void *slim_replay_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_replay_memory_free(void *in_memory);
SLIM_API void *slim_replay_memory_realloc(void *in_memory, slim_int in_size);
SLIM_API slim_handle slim_replay_handle_alloc(slim_int in_size);
SLIM_API slim_handle slim_replay_handle_zeroalloc(slim_int in_size);
SLIM_API slim_handle slim_replay_handle_calloc(slim_int in_elements, slim_int in_element_size);
/* not SLIM_API */ slim_handle slim_replay_handle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
SLIM_API void slim_replay_handle_free(slim_handle in_handle);
SLIM_API slim_int slim_replay_handle_size(slim_handle in_handle);
SLIM_API void *slim_replay_handle_lock(slim_handle in_handle);
SLIM_API void slim_replay_handle_unlock(slim_handle in_handle);
SLIM_API slim_vhandle slim_replay_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_replay_vhandle_zeroalloc(slim_int in_size);
SLIM_API slim_vhandle slim_replay_vhandle_calloc(slim_int in_elements, slim_int in_element_size);
/* not SLIM_API */ slim_vhandle slim_replay_vhandle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
SLIM_API void slim_replay_vhandle_free(slim_vhandle in_vhandle);
SLIM_API void *slim_replay_vhandle_lock(slim_vhandle in_vhandle);
SLIM_API void slim_replay_vhandle_unlock(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_replay_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);
SLIM_API slim_int slim_replay_vhandle_size(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_replay_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_replay_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
#endif /* defined(SLIM_TANK_REPLAY) */

SLIM_END_C_LINKAGE

#endif /* !defined(SLIM_MEMORY_REPLAY_H_PRIVATE_MODULE) */
