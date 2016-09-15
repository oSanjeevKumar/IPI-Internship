/*
    (public) tmapimap.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_PUBLIC_MEMORY_APIMAP_H_MODULE
#define SLIM_PUBLIC_MEMORY_APIMAP_H_MODULE

SLIM_BEGIN_C_LINKAGE

typedef TTankMemNode TMemNode;

#ifdef SLIM_TANK_REPLAY
	#define TANK_PREFIX slim_replay
#else /* !defined(SLIM_TANK_REPLAY) */
	#define TANK_PREFIX slim_tank
#endif /* !defined(SLIM_TANK_REPLAY) */

#define SLIM_MEMMAN_FUNCGEN(prefix,body) SLIM_PASTE(prefix,body)

/* mutex */
#define slim_memory_mutex_lock()    			slim_tank_memory_mutex_lock()
#define slim_memory_mutex_unlock()  			slim_tank_memory_mutex_unlock()

/* management */
#define slim_memory_initialize(start, len)     	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_initialize((start),(len)))
#define slim_memory_set_new_handler(cb, arg)   	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_set_new_handler((cb),(arg)))
#define slim_memory_clear_new_handler(cb, arg) 	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_clear_new_handler((cb),(arg)))
#define slim_memory_finalize()                 	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_finalize())
#define slim_memory_compact()                  	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_compact())
#define slim_memory_disable_compact(b)         	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_disable_compact((b)))

/* memory */
#define slim_memory_alloc(sz)               	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_alloc((sz)))
#define slim_memory_zeroalloc(sz)           	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_zeroalloc((sz)))
#define slim_memory_free(m)                 	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_free((m)))
#define slim_memory_realloc(m, sz)          	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_realloc((m),(sz)))

/* handle */
#define slim_handle_alloc(sz)               	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_alloc((sz)))
#define slim_handle_zeroalloc(sz)           	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_zeroalloc((sz)))
#define slim_handle_calloc(elem, elem_sz)   	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_calloc((elem), (elem_sz)))
#define slim_handle_free(h)                 	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_free((h)))
#define slim_handle_lock(h)                 	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_lock((h)))
#define slim_handle_unlock(h)               	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_unlock((h)))
#define slim_handle_size(h)                 	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_size((h)))

/* vhandle */
#define slim_vhandle_alloc(sz)              	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_alloc((sz)))
#define slim_vhandle_zeroalloc(sz)          	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_zeroalloc((sz)))
#define slim_vhandle_calloc(elem, elem_sz)  	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_calloc((elem), (elem_sz)))
#define slim_vhandle_free(v)                	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_free((v)))
#define slim_vhandle_realloc(v, sz)         	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_realloc((v),(sz)))
#define slim_vhandle_lock(h)                	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_lock((h)))
#define slim_vhandle_unlock(h)              	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_unlock((h)))
#define slim_vhandle_size(v)                	SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_size((v)))

/* debug */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define slim_memory_debug_set_notify_proc(proc) slim_tank_memory_debug_set_notify_proc((proc))
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
#define slim_memory_debug_set_notify_proc(proc) ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

/* multithread */
#ifdef SLIM_CONFIG_MULTITHREAD
#define slim_memory_set_mutex(mux)				slim_tank_memory_set_mutex((mux))
#else /* !defined(SLIM_CONFIG_MULTITHREAD) */
#define slim_memory_set_mutex(mux)				((void)0)
#endif /* !defined(SLIM_CONFIG_MULTITHREAD) */

/* debug + multithread */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	#ifdef SLIM_CONFIG_MULTITHREAD
		/* (1) debug && multithread -> do not use locate/unlocate, but use lock/unlock. */
		#define slim_handle_locate(h)                   slim_tank_handle_lock((h))
		#define slim_handle_unlocate(h)                 slim_tank_handle_unlock((h))
		#define slim_vhandle_locate(h)                  slim_tank_vhandle_lock((h))
		#define slim_vhandle_unlocate(h)                slim_tank_vhandle_unlock((h))
	#else /* !defined(SLIM_CONFIG_MULTITHREAD) */
		/* (2) debug && !multithread -> use locate_d/unlocate_d. */
		#define slim_handle_locate(h)                   slim_tank_handle_locate_d((h))
		#define slim_handle_unlocate(h)                 slim_tank_handle_unlocate_d((h))
		#define slim_vhandle_locate(h)                  slim_tank_vhandle_locate_d((h))
		#define slim_vhandle_unlocate(h)                slim_tank_vhandle_unlocate_d((h))
	#endif /* !defined(SLIM_CONFIG_MULTITHREAD) */
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
	/* (3) !debug -> access directly. */
	#define slim_handle_locate(h)                   (*(void **)(h))
	#define slim_handle_unlocate(h)                 ((void)0)
	#define slim_vhandle_locate(h)                  (*(void **)(h))
	#define slim_vhandle_unlocate(h)                ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

/* debug (one line statement replace) */
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	#define SLIM_TANK_ON_MEMORY_DEBUG(statement) statement
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
	#define SLIM_TANK_ON_MEMORY_DEBUG(statement) ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

/* not SLIM_API */
#define slim_handle_sparealloc(sz, blks) SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_handle_sparealloc((sz),(blks)))
#define slim_memory_sparealloc(sz, blks) SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_memory_sparealloc((sz),(blks)))
#define slim_vhandle_sparealloc(sz, blks) SLIM_MEMMAN_FUNCGEN(TANK_PREFIX,_vhandle_sparealloc((sz),(blks)))

SLIM_END_C_LINKAGE
#endif /* !defined(SLIM_PUBLIC_MEMORY_APIMAP_H_MODULE) */
