/*
    (private) tmapimap.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_PRIVATE_MEMORY_APIMAP_H_MODULE
#define SLIM_PRIVATE_MEMORY_APIMAP_H_MODULE

#ifndef SLIM_PUBLIC_MEMORY_APIMAP_H_MODULE
#include <slim/tank/tmapimap.h>
#endif /* !defined(SLIM_PUBLIC_MEMORY_APIMAP_H_MODULE) */

SLIM_BEGIN_C_LINKAGE

/* handle */
#define slim_handle_peek_int(h, off)        slim_tank_handle_peek_int((h),(off))
#define slim_handle_peek_short(h, off)      slim_tank_handle_peek_short((h),(off))
#define slim_handle_peek_pix(h, off)        slim_tank_handle_peek_pix((h),(off))
#define slim_handle_peek_handle(h, off)     slim_tank_handle_peek_handle((h),(off))
#define slim_handle_peek_vhandle(h, off)    slim_tank_handle_peek_vhandle((h),(off))
#define slim_handle_peek_ptr(h, off)        slim_tank_handle_peek_ptr((h),(off))
#define slim_handle_peek_opaque(h, off)     slim_tank_handle_peek_opaque((h),(off))

/* vhandle */
#define slim_vhandle_peek_int(h, off)       slim_tank_vhandle_peek_int((h),(off))
#define slim_vhandle_peek_short(h, off)     slim_tank_vhandle_peek_short((h),(off))
#define slim_vhandle_peek_pix(h, off)       slim_tank_vhandle_peek_pix((h),(off))
#define slim_vhandle_peek_handle(h, off)    slim_tank_vhandle_peek_handle((h),(off))
#define slim_vhandle_peek_vhandle(h, off)   slim_tank_vhandle_peek_vhandle((h),(off))
#define slim_vhandle_peek_ptr(h, off)       slim_tank_vhandle_peek_ptr((h),(off))
#define slim_vhandle_peek_opaque(h, off)    slim_tank_vhandle_peek_opaque((h),(off))

/* MemNode */ 
#define MemNode_IsPixInSamePage(p1,p2)  TankMemNode_IsPixInSamePage((p1),(p2))

#define TMemNode_Initialize(self) 			TTankMemNode_Initialize((self))
#define TMemNode_Finalize(self)				TTankMemNode_Finalize((self))
#define TMemNode_GetPageHandle(self,off)    TTankMemNode_GetPageHandle((self),(off))
#define TMemNode_GetPageHandleAndCheck(self, off) TTankMemNode_GetPageHandleAndCheck((self), (off))
#define TMemNode_ZeroAlloc(self,off) 		TTankMemNode_ZeroAlloc((self),(off))
#define TMemNode_Lock(self,off,locked) 		TTankMemNode_Lock((self),(off),(locked))
#define TMemNode_Locate(self,off) 			TTankMemNode_Locate((self),(off))
#define TMemNode_Free(self,off) 			TTankMemNode_Free((self),(off))
#define TMemNode_FreeAll(self) 				TTankMemNode_FreeAll(self)
#define TMemNode_UsedPages(self) 			TTankMemNode_UsedPages(self)
#define TMemNode_TotalPages(self) 			TTankMemNode_TotalPages(self)
#define TMemNode_Unlock(self,off) 			TTankMemNode_Unlock((self),(off))
#define TMemNode_Unlocate(self,off) 		TTankMemNode_Unlocate((self),(off))
#define TMemNode_PeekPix(self,off) 			TTankMemNode_PeekPix((self),(off))

/*
 * Debug
 */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
	#define slim_memory_debug_is_alloc_failure() \
	   slim_tank_memory_debug_is_alloc_failure()
	#define slim_memory_debug_set_random_alloc_failure_proc(proc) \
	   slim_tank_memory_debug_set_random_alloc_failure_proc(proc)
	#define slim_memory_get_free_size(a, b) \
	   slim_tank_memory_get_free_size((a), (b))
	#define slim_memory_debug_from(addr) \
	   slim_tank_memory_debug_from(addr)
	#define slim_memory_debug_from_name(from, outlen) \
	   slim_tank_memory_debug_from_name(from, outlen)
	#define slim_memory_debug_from_name_array(from) \
	   slim_tank_memory_debug_from_name_array(from)
	#define slim_memory_debug_from_equal(a, b) \
	   slim_tank_memory_debug_from_equal((a), (b))
	#define slim_memory_block_from(addr) \
       slim_tank_memory_block_from(addr)
	#define slim_memory_block_set_from(addr, from) \
	   slim_tank_memory_block_set_from((addr), (from))
	#define slim_memory_debugout_statistics() \
       slim_tank_memory_debugout_statistics()
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
	#define slim_memory_debug_is_alloc_failure() (slim_false)
	#define slim_memory_debug_set_random_alloc_failure_proc(proc) ((void)0)
	#define slim_memory_get_free_size(a, b) ((void)0)
	#define slim_memory_debug_from(addr) (0)
	#define slim_memory_debug_from_name(from, outlen) (0)
	#define slim_memory_debug_from_name_array(addr) (0)
	#define slim_memory_debug_from_equal(a, b) (slim_false)
	#define slim_memory_block_from(addr) (0)
	#define slim_memory_block_set_from(addr, from) ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
#define TMemNode_IsValidPix(self,pix)   (TTankMemNode_IsValidPix((self),(pix)))
#define TMemNode_IsValidPixOrNil(self,pix)  (TTankMemNode_IsValidPixOrNil((self),(pix)))
#define TMemNode_LocateX(self,off) TTankMemNode_LocateX((self),(off))
#define TMemNode_UnlocateX(self,off) TTankMemNode_UnlocateX((self),(off))
#define MemNode_DebugSetNotifyProc(proc) TankMemNode_DebugSetNotifyProc((proc))
#define TMemNode_DebugNotifyAlloc(self, off, size) TTankMemNode_DebugNotifyAlloc((self),(off),(size))
#define TMemNode_DebugNotifyFree(self, off) TTankMemNode_DebugNotifyFree((self),(off))
#define TMemNode_DebugNotifyLocate(self, off, count) TTankMemNode_DebugNotifyLocate((self),(off),(count))
#define TMemNode_VerifyPix(self, off) TTankMemNode_VerifyPix((self),(off))
#else /* !defined(SLIM_CONFIG_MEMNODE_DEBUG) */
#define TMemNode_IsValidPix(self,pix)   (slim_true)
#define TMemNode_IsValidPixOrNil(self,pix)  (slim_true)
#define TMemNode_LocateX(self,off) (TMemNode_Locate((self),(off)))
#define TMemNode_UnlocateX(self,off) (TMemNode_Unlocate((self),(off)))
#define MemNode_DebugSetNotifyProc(proc) ((void)0)
#define TMemNode_DebugNotifyAlloc(self, off, size) ((void)0)
#define TMemNode_DebugNotifyFree(self, off) ((void)0)
#define TMemNode_DebugNotifyLocate(self, off, count) ((void)0)
#define TMemNode_VerifyPix(self, off) ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMNODE_DEBUG) */

SLIM_END_C_LINKAGE
#endif /* !defined(SLIM_PRIVATE_MEMORY_APIMAP_H_MODULE) */
