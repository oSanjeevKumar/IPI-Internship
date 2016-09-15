/*
	mmapimap.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/mmapimap.h 12    06/07/04 13:18 Endoh $ */

#ifndef SLIM_MEMORY_API_MAPPING_H_PRIVATE
#define SLIM_MEMORY_API_MAPPING_H_PRIVATE

#ifndef SLIM_MEMORY_API_MAPPING_H
#include <slim/basis/mmapimap.h>
#endif

SLIM_BEGIN_C_LINKAGE

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
#define SLIM_MEMMANPREFIX_MEMNODE	AltMemNode
#define SLIM_MEMMANPREFIX_TMEMNODE	TAltMemNode

#else /* SLIM_CONFIG_MEMORY_ALTERNATIVE */
#ifdef SLIM_CONFIG_MEMORY_STANDARD
#define SLIM_MEMMANPREFIX_MEMNODE	StdMemNode
#define SLIM_MEMMANPREFIX_TMEMNODE	TStdMemNode

#else /* SLIM_CONFIG_MEMORY_STANDARD */
#error SLIM_CONFIG_MEMORY_EXTERNAL must be defined

#endif /* SLIM_CONFIG_MEMORY_STANDARD */
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

/* ATTENTION!
 * if you append any API below, you must also append them to memory_e.h
 */

/* handle */
#define slim_handle_peek_int(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_int((h),(off)))    
#define slim_handle_peek_short(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_short((h),(off)))  
#define slim_handle_peek_pix(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_pix((h),(off)))    
#define slim_handle_peek_handle(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_handle((h),(off))) 
#define slim_handle_peek_vhandle(h, off)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_vhandle((h),(off)))
#define slim_handle_peek_ptr(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_ptr((h),(off)))    
#define slim_handle_peek_opaque(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_handle_peek_opaque((h),(off))) 

/* vhandle */
#define slim_vhandle_peek_int(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_int((h),(off)))    
#define slim_vhandle_peek_short(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_short((h),(off)))  
#define slim_vhandle_peek_pix(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_pix((h),(off)))    
#define slim_vhandle_peek_handle(h, off)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_handle((h),(off))) 
#define slim_vhandle_peek_vhandle(h, off)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_vhandle((h),(off)))
#define slim_vhandle_peek_ptr(h, off)		SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_ptr((h),(off)))    
#define slim_vhandle_peek_opaque(h, off) 	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_vhandle_peek_opaque((h),(off))) 

/* MemNode */ 
#define MemNode_IsPixInSamePage(p1,p2)	SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEMNODE,_IsPixInSamePage((p1),(p2)))

#define TMemNode_Initialize(self) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Initialize((self))))
#define TMemNode_Finalize(self) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Finalize((self))))
#define TMemNode_GetPageHandle(self,off)	(SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_GetPageHandle((self),(off))))
#define TMemNode_GetPageHandleAndCheck(self, off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_GetPageHandleAndCheck((self), (off))))
#define TMemNode_ZeroAlloc(self,off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_ZeroAlloc((self),(off))))
#define TMemNode_Lock(self,off,locked) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Lock((self),(off),(locked))))
#define TMemNode_Locate(self,off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Locate((self),(off))))
#define TMemNode_Free(self,off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Free((self),(off))))
#define TMemNode_FreeAll(self) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_FreeAll(self)))
#define TMemNode_UsedPages(self) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_UsedPages(self)))
#define TMemNode_TotalPages(self) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_TotalPages(self)))
#define TMemNode_Unlock(self,off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Unlock((self),(off))))
#define TMemNode_Unlocate(self,off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_Unlocate((self),(off))))
#define TMemNode_PeekPix(self,off) (SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_PeekPix((self),(off))))


/*
 * Debug
 */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define slim_memory_debug_is_alloc_failure() SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_debug_is_alloc_failure())
#define slim_memory_debug_set_random_alloc_failure_proc(proc) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_debug_set_random_alloc_failure_proc((proc)))


#define slim_memory_block_from(addr) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_block_from((addr)))
#define slim_memory_block_set_from(addr, from) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_block_set_from((addr),(from)))
#define slim_memory_debug_from_equal(from, elem) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEM,_memory_debug_from_equal((from),(elem)))
#else /* SLIM_CONFIG_MEMORY_DEBUG */
#define slim_memory_debug_is_alloc_failure() (slim_false)
#define slim_memory_debug_set_random_alloc_failure_proc(proc) ((void)0)
#define slim_memory_debug_set_notify_proc(proc) ((void)0)

#define slim_memory_block_from(addr) (0)
#define slim_memory_block_set_from(addr, from) ((void)0)
#define slim_memory_debug_from_equal(from, elem) (slim_false)

#endif /* SLIM_CONFIG_MEMORY_DEBUG */

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
#define TMemNode_IsValidPix(self,pix)	(SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_IsValidPix((self),(pix))))
#define TMemNode_IsValidPixOrNil(self,pix)	(SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_IsValidPixOrNil((self),(pix))))

#define TMemNode_LocateX(self,off) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_LocateX((self),(off)))
#define TMemNode_UnlocateX(self,off) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_UnlocateX((self),(off)))

#define MemNode_DebugSetNotifyProc(proc) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_MEMNODE,_DebugSetNotifyProc((proc)))
#define TMemNode_DebugNotifyAlloc(self, off, size) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_DebugNotifyAlloc((self),(off),(size)))
#define TMemNode_DebugNotifyFree(self, off) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_DebugNotifyFree((self),(off)))
#define TMemNode_DebugNotifyLocate(self, off, count) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_DebugNotifyLocate((self),(off),(count)))
#define TMemNode_VerifyPix(self, off) SLIM_MEMMAN_FUNCGEN(SLIM_MEMMANPREFIX_TMEMNODE,_VerifyPix((self),(off)))

#else /* SLIM_CONFIG_MEMNODE_DEBUG */
#define TMemNode_IsValidPix(self,pix)	(slim_true)
#define TMemNode_IsValidPixOrNil(self,pix)	(slim_true)

#define TMemNode_LocateX(self,off) (TMemNode_Locate((self),(off)))
#define TMemNode_UnlocateX(self,off) (TMemNode_Unlocate((self),(off)))

#define MemNode_DebugSetNotifyProc(proc) ((void)0)
#define TMemNode_DebugNotifyAlloc(self, off, size) ((void)0)
#define TMemNode_DebugNotifyFree(self, off) ((void)0)
#define TMemNode_DebugNotifyLocate(self, off, count) ((void)0)
#define TMemNode_VerifyPix(self, off) ((void)0)

#endif /* SLIM_CONFIG_MEMNODE_DEBUG */

SLIM_END_C_LINKAGE
#endif
