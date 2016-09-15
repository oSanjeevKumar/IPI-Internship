/*
	(public) tmtank.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/module/memory/tank/basis/tmtank.h 6     06/07/27 19:56 Suzuki $ */

#ifndef SLIM_PUBLIC_MEMORY_TANK_H_MODULE
#define SLIM_PUBLIC_MEMORY_TANK_H_MODULE
SLIM_BEGIN_C_LINKAGE

/*
 * This file defines tank memory specific APIs and types.
 */

/* Tank Peer Procs (platform dependent memory allocator) */

typedef void *(*TankPeerAllocProc)(slim_int in_size);
typedef void *(*TankPeerReallocProc)(void *in_mem, slim_int in_size);
typedef void (*TankPeerFreeProc)(void *in_mem);

struct TTankPeerProcs_ {
    TankPeerAllocProc fTankPeerAllocProc;
    TankPeerReallocProc fTankPeerRellocProc;
    TankPeerFreeProc fTankPeerFreeProc;
};
typedef struct TTankPeerProcs_ TTankPeerProcs;

/* Tank Information */

struct TTankInfo_ {
    slim_int fMaxTotalBytes;
    slim_int fMinSubTankBytes;
	slim_bool fAutoExtend;
};
typedef struct TTankInfo_ TTankInfo;

/* Attach tanks */

typedef slim_opaque TAttachTank;

/*
 * MemNode
 */

struct TTankMemNode_ {
	slim_handle *fHandles;
	slim_int fHandleSize;
	slim_int fUsedPages;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_int fFrom;
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
#ifdef SLIM_CONFIG_MEMNODE_DEBUG
	slim_int fID;
#endif /* defined(SLIM_CONFIG_MEMNODE_DEBUG) */
};
typedef struct TTankMemNode_ TTankMemNode;

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

/* Prototypes */
/* Tank specific API. */
SLIM_API void slim_tank_set_peer_procs(TTankPeerProcs *in_peer);
SLIM_API void slim_tank_get_tank_info(TTankInfo *out_tank_info);
SLIM_API void slim_tank_set_tank_info(TTankInfo *in_tank_info);
SLIM_API TAttachTank slim_tank_attach(void *in_start, slim_int in_len);
SLIM_API slim_bool slim_tank_detach(TAttachTank in_tank);

/* Common API. */
SLIM_API slim_bool slim_tank_memory_initialize(void *in_start, slim_int in_len);
SLIM_API slim_bool slim_tank_memory_set_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API slim_bool slim_tank_memory_clear_new_handler(SLIM_MemoryNewHandlerProc in_callback, slim_opaque in_arg);
SLIM_API void slim_tank_memory_finalize(void);
SLIM_API void * slim_tank_memory_alloc(slim_int in_size);
SLIM_API void * slim_tank_memory_zeroalloc(slim_int in_size);
SLIM_API void slim_tank_memory_free(void *in_memory);
SLIM_API void * slim_tank_memory_realloc(void *in_memory, slim_int in_size);
SLIM_API slim_handle slim_tank_handle_alloc(slim_int in_size);
SLIM_API slim_handle slim_tank_handle_zeroalloc(slim_int in_size);
SLIM_API slim_handle slim_tank_handle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_tank_handle_free(slim_handle in_handle);
SLIM_API slim_int slim_tank_handle_size(slim_handle in_handle);
SLIM_API void * slim_tank_handle_lock(slim_handle in_handle);
SLIM_API void slim_tank_handle_unlock(slim_handle in_handle);
SLIM_API slim_vhandle slim_tank_vhandle_alloc(slim_int in_size);
SLIM_API slim_vhandle slim_tank_vhandle_zeroalloc(slim_int in_size);
SLIM_API slim_vhandle slim_tank_vhandle_calloc(slim_int in_elements, slim_int in_element_size);
SLIM_API void slim_tank_vhandle_free(slim_vhandle in_vhandle);
SLIM_API slim_int slim_tank_vhandle_size(slim_vhandle in_vhandle);
SLIM_API void * slim_tank_vhandle_lock(slim_vhandle in_vhandle);
SLIM_API void slim_tank_vhandle_unlock(slim_vhandle in_vhandle);
SLIM_API slim_bool slim_tank_vhandle_realloc(slim_vhandle in_vhandle, slim_int in_size);
SLIM_API void slim_tank_memory_disable_compact(slim_bool in_disable);
SLIM_API void slim_tank_memory_compact(void);

#ifdef SLIM_CONFIG_MULTITHREAD
SLIM_API void slim_tank_memory_set_mutex(slim_opaque in_mutex);
#endif /* defined(SLIM_CONFIG_MULTITHREAD) */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
SLIM_API void * slim_tank_vhandle_locate_d(slim_vhandle in_vhandle);
SLIM_API void slim_tank_vhandle_unlocate_d(slim_vhandle in_vhandle);
SLIM_API void * slim_tank_handle_locate_d(slim_handle in_handle);
SLIM_API void slim_tank_handle_unlocate_d(slim_handle in_handle);
SLIM_API void slim_tank_memory_debug_set_notify_proc(SLIM_MemoryAllocFreeDebugNotifyProc in_proc);
/* not SLIM_API */ void *slim_tank_memory_debug_memory_to_tank(void *in_address);
/* not SLIM_API */ void *slim_tank_memory_debug_next_tank(void *in_tank);
/* not SLIM_API */ slim_bool slim_tank_memory_debug_get_tanknum(void *in_tank, slim_int *out_tanknum, slim_int *out_alltanknum);
/* not SLIM_API */ slim_int slim_tank_memory_test(slim_int in_count);
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */

SLIM_END_C_LINKAGE
#endif /* !defined(SLIM_PUBLIC_MEMORY_TANK_H_MODULE) */
