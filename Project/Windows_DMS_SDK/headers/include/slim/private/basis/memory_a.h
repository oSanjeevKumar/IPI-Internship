/*
	memory_a.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/memory_a.h 46    05/12/28 12:08 Someya $ */

#ifndef SLIM_MEMORY_ALTERNATIVE_H_PRIVATE
#define SLIM_MEMORY_ALTERNATIVE_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#ifndef SLIM_ALT_MEMORY_MAX_NEW_HANDLERS
#define SLIM_ALT_MEMORY_MAX_NEW_HANDLERS 1
#endif /* SLIM_ALT_MEMORY_MAX_NEW_HANDLERS */

/* multithread */
#ifdef SLIM_CONFIG_MULTITHREAD
#define slim_alt_memory_mutex_lock()	slimMemoryMutexLockPeer(SLIM_RESOLVE_GLOBAL_VAR(gSlim_AltMemoryMutex))
#define slim_alt_memory_mutex_unlock()	slimMemoryMutexUnlockPeer(SLIM_RESOLVE_GLOBAL_VAR(gSlim_AltMemoryMutex))
#else
#define slim_alt_memory_mutex_lock()	((void)0)
#define slim_alt_memory_mutex_unlock()	((void)0)
#endif

/* handle */
#define slim_alt_handle_addr(h, off)		((slim_byte *)(h)+(off))
#define slim_alt_handle_peek_int(h, off)		(*(slim_int*)slim_alt_handle_addr((h),(off)))
#define slim_alt_handle_peek_short(h, off)		(*(slim_short*)slim_alt_handle_addr((h),(off)))
#define slim_alt_handle_peek_pix(h, off)		(*(slim_pix*)slim_alt_handle_addr((h),(off)))
#define slim_alt_handle_peek_handle(h, off)		(*(slim_handle*)slim_alt_handle_addr((h),(off)))
#define slim_alt_handle_peek_vhandle(h, off)	(*(slim_vhandle*)slim_alt_handle_addr((h),(off)))
#define slim_alt_handle_peek_ptr(h, off)		(*(void**)slim_alt_handle_addr((h),(off)))
#define slim_alt_handle_peek_opaque(h, off)		(*(slim_opaque*)slim_alt_handle_addr((h),(off)))

/* vhandle */
#define slim_alt_vhandle_addr(h, off)		((*(slim_byte **)(h))+(off))

#define slim_alt_vhandle_peek_int(h, off)		(*(slim_int*)slim_alt_vhandle_addr((h),(off)))
#define slim_alt_vhandle_peek_short(h, off)		(*(slim_short*)slim_alt_vhandle_addr((h),(off)))
#define slim_alt_vhandle_peek_pix(h, off)		(*(slim_pix*)slim_alt_vhandle_addr((h),(off)))
#define slim_alt_vhandle_peek_handle(h, off)		(*(slim_handle*)slim_alt_vhandle_addr((h),(off)))
#define slim_alt_vhandle_peek_vhandle(h, off)	(*(slim_vhandle*)slim_alt_vhandle_addr((h),(off)))
#define slim_alt_vhandle_peek_ptr(h, off)		(*(void**)slim_alt_vhandle_addr((h),(off)))
#define slim_alt_vhandle_peek_opaque(h, off)		(*(slim_opaque*)slim_alt_vhandle_addr((h),(off)))


/*             */
/* memory node */
/*             */
#define AltMemNode_IsPixInSamePage(p1,p2)	((((slim_int)(p1)^(slim_int)(p2)) \
											>>SLIM_MEMORY_BLOG) == 0)

#define TAltMemNode_GetPageHandleAndCheck(self,off) TAltMemNode_GetPageHandle((self),(off))
#define TAltMemNode_OffsetToPageHandle(self,off) (((off) >> SLIM_MEMORY_BLOG < (self)->fHandleSize) ? \
		(self)->fHandles[(off) >> SLIM_MEMORY_BLOG] : slim_nil)
#define TAltMemNode_Lock(self, off, locked_handle) ((void*)(off))
#define TAltMemNode_Locate(self, off) ((void*)(off))

#define TAltMemNode_PeekPix(self, off) (*(slim_pix *)(off))

#define TAltMemNode_RefX(self, off) TAltMemNode_Locate((self),(off))
#define TAltMemNode_UsedPages(self)		((self)->fUsedPages)
#define TAltMemNode_TotalPages(self)		((self)->fHandleSize)

#define TAltMemNode_Unlock(self,off) ((void)0)
#define TAltMemNode_Unlocate(self,off) ((void)0)

/*
 * debug 
 */

#define slim_alt_memory_debug_is_alloc_failure()				(slim_false)
#define slim_alt_memory_debug_set_random_alloc_failure_proc(proc)	{}

#define slim_alt_memory_debug_from(addr) (0)
#define slim_alt_memory_block_from(addr) (0)
#define slim_alt_memory_block_set_from(addr, from) ((void)0)

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
#define TAltMemNode_IsValidPixOrNil(memnode, pix) (!(pix) || TAltMemNode_IsValidPix((memnode),(slim_int)(pix)))
#else
#define TAltMemNode_IsValidPix(self,pix) ((pix) != slim_nil)
#define TAltMemNode_IsValidPixOrNil(self,pix)	(slim_true)
#endif

#define TAltMemNode_DebugNotifyAlloc(self, off, size) ((void)0)
#define TAltMemNode_DebugNotifyFree(self, off) ((void)0)
#define TAltMemNode_DebugNotifyLocate(self, off, count) ((void)0)
#define TAltMemNode_VerifyPix(self, off) ((void)0)

SLIM_END_C_LINKAGE

#endif
