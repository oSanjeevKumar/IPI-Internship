/*
	memory_s.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/memory_s.h 23    06/07/07 17:09 Siu $ */

#ifndef SLIM_MEMORY_STANDARD_H_PRIVATE
#define SLIM_MEMORY_STANDARD_H_PRIVATE

SLIM_BEGIN_C_LINKAGE


/* config */

#define SLIM_CONFIG_MEMORY_NOFRAGMOVE
	/* Ugh!: do not undefine SLIM_CONFIG_MEMORY_NOFRAGMOVE... */

#ifndef SLIM_CONFIG_MEMORY_NOFRAGMOVE
#define SLIM_CONFIG_MEMORY_FRAGMOVE
#endif

#ifdef SLIM_CONFIG_MEMORY_FRAGMOVE
#define SLIM_MEMORY_USEFRAGSPEC
#else
#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define SLIM_MEMORY_USEFRAGSPEC
#endif
#endif


#define SLIM_MEMORY_A2B(a)	(((slim_byte *)(a) - (slim_byte *)SLIM_RESOLVE_GLOBAL_VAR(gSlim_MemoryHeapBase)) >> SLIM_MEMORY_BLOG)
	/* Converts adress to block number. If address is of fragment, it returns block number of containing block */
#define SLIM_MEMORY_B2A(b)	((void *)(((slim_int)(b) << SLIM_MEMORY_BLOG) + (slim_byte *)SLIM_RESOLVE_GLOBAL_VAR(gSlim_MemoryHeapBase)))
	/* Converts block number to address */
#ifdef SLIM_MEMORY_USEFRAGSPEC
#define SLIM_MEMORY_FRAGSPEC_SIZE	(SLIM_ROUNDUP_P2(sizeof(TMemFragSpec), SLIM_CONFIG_CC_STRUCTALIGN))
	/* fragment header size */
#else
#define SLIM_MEMORY_FRAGSPEC_SIZE	0
#endif

#define SLIM_MEMORY_MPTRBLK(h)		((TMasterPtrBlk *)((slim_uiaddr_word)(h) & ~(SLIM_MEMORY_BSIZE - 1)))
#define SLIM_MEMORY_MPTRS_PER_BLK	((SLIM_MEMORY_BSIZE - SLIM_OFFSETOF(TMasterPtrBlk, fMasterPtr)) / sizeof(void *))
#define SLIM_MEMORY_DEF_MPTRBLKS	5

#define SLIM_MEMORY_HIGH				0x00000001
#define SLIM_MEMORY_DONOT_COMPACTION	0x00000002

#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define SLIM_MEMORY_CHECKLOCATE SLIM_ASSERT(SLIM_RESOLVE_GLOBAL_VAR(gSlim_MemoryLocateCount) == 0)
#else
#define SLIM_MEMORY_CHECKLOCATE
#endif

#define SLIM_MEMORY_FROM_FREED		0xfefefefe
#define SLIM_MEMORY_PURGEBYTE		0xfd

#ifndef SLIM_STD_MEMORY_MAX_NEW_HANDLERS
#define SLIM_STD_MEMORY_MAX_NEW_HANDLERS	2
#endif /* SLIM_STD_MEMORY_MAX_NEW_HANDLERS */

/*
	TMemBlock

	* Free block
	  .uFree.fSize				size of free block (in numbers of blocks)
	  .uFree.fNext				next free block number
	  .uFree.fPrev				previous free block number
	* Allocated block (not fragment)
	  .uAllocBlock.fType		always 0
	  .uAllocBlock.fSize		size of allocated block (in numbers of blocks)
	* Allocated block (fragment container)
	  .uAllocFrag.fType			log2 of size in bytes of fragment (same positon and size with uAllocBlock.fType)
	  .uAllocFrag.fFree			number of free fragments in block
	  .uAllocFrag.fFreeList		pointer to free fragment list in block
	  .uAllocFrag.fNext			next fragment block number
*/

#ifdef SLIM_MEMORY_USEFRAGSPEC
struct TMemFragSpec_ {
	slim_int fLockCount;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_word fFrom;
#endif
};
typedef struct TMemFragSpec_ TMemFragSpec;
#endif

struct TMemBlock_AllocBlock_ {
	slim_short fType;	/* this field must be common with TMemBlock.uAllocFrag.fType */
	slim_short fSize;
	slim_int fLockCount;
	void **fMasterPtr;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_word fFrom;
#endif
};
typedef struct TMemBlock_AllocBlock_ TMemBlock_AllocBlock;

struct TMemBlock_AllocFrag_ {
	slim_short fType;	/* this field must be common with TMemBlock.uAllocBlock.fType */
	slim_short fFree;
	slim_short fToBeSplit;
	slim_short fFreeList;
	slim_int fNext;
};
typedef struct TMemBlock_AllocFrag_ TMemBlock_AllocFrag;

struct TMemBlock_Free_ {
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_short fType; /* this field must be common with TMemBlock.uAllocBlock.fType, and must be -1 */
#endif
	slim_short fSize;
	slim_short fCompactHint;
	slim_int fNext;
	slim_int fPrev;
};
typedef struct TMemBlock_Free_ TMemBlock_Free;

union TMemBlock_ {
	TMemBlock_AllocBlock uAllocBlock;
	TMemBlock_AllocFrag uAllocFrag;
	TMemBlock_Free uFree;
};
typedef union TMemBlock_ TMemBlock;

#define SLIM_MEMORY_FRAGTYPE_FREE 0xcdcd

/* This struct is used only flagment is free, otherwise this struct is overwritten by memory user */
struct TMemFragList_ {
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_half fFragType;
#endif
	slim_short fNext;	/* next free fragment offset in page */
};
typedef struct TMemFragList_ TMemFragList;

struct TMasterPtrBlk_ {
	slim_short fNext;
	slim_short fFree;
	void *fMasterPtr[1];
};
typedef struct TMasterPtrBlk_ TMasterPtrBlk;

/* memory crisis callback entry */
struct TCallbackTable_ {
	slim_opaque fID;
	slim_bool (*fProc)(slim_opaque in_arg, slim_int in_size);
	slim_opaque fArg;
};
typedef struct TCallbackTable_ TCallbackTable;

struct TMemoryHeapStaticInfo_ {
	slim_int fBlockSize;
};
typedef struct TMemoryHeapStaticInfo_ TMemoryHeapStaticInfo;
	/* the value -1 means infomation is not available */
struct TMemoryHeapDynamicInfo_ {
	slim_int fRemainingBlocks;
};
typedef struct TMemoryHeapDynamicInfo_ TMemoryHeapDynamicInfo;
	/* the value -1 means infomation is not available */


#ifdef SLIM_CONFIG_MULTITHREAD
#define slim_std_memory_mutex_lock()	slimMemoryMutexLockPeer(SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemoryMutex))
#define slim_std_memory_mutex_unlock()	slimMemoryMutexUnlockPeer(SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemoryMutex))
#else
#define slim_std_memory_mutex_lock()	((void)0)
#define slim_std_memory_mutex_unlock()	((void)0)
#endif

#define slim_std_handle_addr(h, off)		((*(slim_byte **)(h))+SLIM_MEMORY_CHECKOW_BYTES+(off))
#define slim_std_vhandle_addr(h, off)		((*(slim_byte **)(h))+SLIM_MEMORY_CHECKOW_BYTES+(off))

/* peekers... */
#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
#else
#define slim_std_handle_peek_int(h, off)		(*(slim_int*)slim_std_handle_addr((h),(off)))
#define slim_std_handle_peek_short(h, off)		(*(slim_short*)slim_std_handle_addr((h),(off)))
#define slim_std_handle_peek_pix(h, off)		(*(slim_pix*)slim_std_handle_addr((h),(off)))
#define slim_std_handle_peek_handle(h, off)		(*(slim_handle*)slim_std_handle_addr((h),(off)))
#define slim_std_handle_peek_vhandle(h, off)	(*(slim_vhandle*)slim_std_handle_addr((h),(off)))
#define slim_std_handle_peek_ptr(h, off)		(*(void**)slim_std_handle_addr((h),(off)))
#define slim_std_handle_peek_opaque(h, off)		(*(slim_opaque*)slim_std_handle_addr((h),(off)))
#define slim_std_vhandle_peek_int(h, off)		slim_std_handle_peek_int((h), (off))
#define slim_std_vhandle_peek_short(h, off)		slim_std_handle_peek_short((h), (off))
#define slim_std_vhandle_peek_pix(h, off)		slim_std_handle_peek_pix((h), (off))
#define slim_std_vhandle_peek_handle(h, off)	slim_std_handle_peek_handle((h), (off))
#define slim_std_vhandle_peek_vhandle(h, off)	slim_std_handle_peek_vhandle((h), (off))
#define slim_std_vhandle_peek_ptr(h, off)		slim_std_handle_peek_ptr((h), (off))
#define slim_std_vhandle_peek_opaque(h, off)	slim_std_handle_peek_opaque((h), (off))
#endif


#ifdef SLIM_CONFIG_MEMORY_DEBUG
#else
#define slim_std_memory_debug_from(addr) (0)
#define slim_std_memory_block_from(addr) (0)
#define slim_std_memory_block_set_from(addr, from) ((void)0)
#endif

#ifdef SLIM_CONFIG_DEBUG
#endif
#ifdef SLIM_CONFIG_MEMORY_DEBUG
#else
#define slim_std_memory_debug_is_alloc_failure()	(slim_false)
#define slim_std_memory_debug_set_random_alloc_failure_proc(proc) ((void)0)
#endif

/*             */
/* memory node */
/*             */

#define StdMemNode_IsPixInSamePage(p1,p2)	(((((p1)^(p2)) >>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK) == 0)
#define TStdMemNode_GetPageHandleAndCheck(self, in_offset)	\
 (((self)->fHandleSize > (((in_offset)>>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK)) ? \
	TStdMemNode_GetPageHandle((self), (in_offset)) : slim_nil)
#define TStdMemNode_GetPageHandle(self, in_offset)	\
	((self)->fHandles[((in_offset)>>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK ])

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
#else
#define TStdMemNode_LocateX(self,off) (TStdMemNode_Locate((self),(off)))
#endif

#define TStdMemNode_PeekPix(self, off) \
	(slim_std_handle_peek_pix(TStdMemNode_GetPageHandle((self),(off)),(off)&((1<<SLIM_MEMORY_BLOG)-1)))

#define TStdMemNode_UsedPages(self)		((self)->fUsedPages)
#define TStdMemNode_TotalPages(self)		((self)->fHandleSize)

#define TStdMemNode_IsValidPix(memnode, pix)			((pix) != slim_pix_nil)
#define TStdMemNode_IsValidPixOrNil(memnode, pix)	(slim_true)

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
enum {
	SLIM_MEMNODE_DEBUGNOTIFY_INIT,
	SLIM_MEMNODE_DEBUGNOTIFY_ALLOC,
	SLIM_MEMNODE_DEBUGNOTIFY_FREE,
	SLIM_MEMNODE_DEBUGNOTIFY_FREEALL,
	SLIM_MEMNODE_DEBUGNOTIFY_LOCK,
	SLIM_MEMNODE_DEBUGNOTIFY_LOCATE,
	SLIM_MEMNODE_DEBUGNOTIFY_FINALIZE,
	SLIM_MEMNODE_DEBUGNOTIFIES
};
#define TStdMemNode_VerifyPix(self, off) (\
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc) ? \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),0) : ((void)0)))
#define TStdMemNode_Unlock(self,off) (\
	slim_std_handle_unlock(TStdMemNode_GetPageHandle((self),(off))), \
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc) ? \
		((*SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCK,(self),(off),-1),0) : 0))
#define TStdMemNode_Unlocate(self,off) (\
	slim_std_handle_unlocate(TStdMemNode_GetPageHandle((self),(off))), \
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc) ? \
		((*SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),-1),0) : 0))
#define TStdMemNode_UnlocateX(self,off) (\
	slim_std_handle_unlocate(TStdMemNode_GetPageHandle((self),(off))))

#define TStdMemNode_DebugNotifyAlloc(self, off, size)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_ALLOC, (self), (off), (size)); \
}
#define TStdMemNode_DebugNotifyFree(self, off)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_FREE, (self), (off), 0); \
}
#define TStdMemNode_DebugNotifyLocate(self, off, count)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_StdMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCATE, (self), (off), (count)); \
}
typedef void (*StdMemNode_AllocFreeDebugNotifyProc)(slim_int in_code, TStdMemNode *in_memnode, slim_int in_arg1, slim_int in_arg2);
#else
#define TStdMemNode_VerifyPix(self, off) ((void)0)
#define TStdMemNode_Unlock(self,off) (slim_std_handle_unlock(TStdMemNode_GetPageHandle((self),(off))))
#define TStdMemNode_Unlocate(self,off) (slim_std_handle_unlocate(TStdMemNode_GetPageHandle((self),(off))))
#define TStdMemNode_DebugNotifyAlloc(self, off, size)	{}
#define TStdMemNode_DebugNotifyFree(self, off)	{}
#define TStdMemNode_DebugNotifyLocate(self, off, count) {}
#endif


#ifdef SLIM_CONFIG_POINTER_MEMNODE
/*----------begin temporary -------------*/
/*#define SLIM_MEMORY_FROM_TPTRMEMNODE SLIM_MEMORY_FROM_TMEMNODE */
#define SLIM_PTRMEMNODE_INSAMEPAGE(p1,p2) SLIM_MEMNODE_INSAMEPAGE((p1),(p2))

/*----------end temporary -------------*/


#define SLIM_PTRMEMNODE_DEFAULT_HANDLES SLIM_MEMNODE_DEFAULT_HANDLES


#define TPtrMemNode_GetPageHandleAndCheck(self, in_offset)	\
 (((self)->fHandleSize > (((in_offset)>>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK)) ? \
	TPtrMemNode_GetPagePtr((self), (in_offset)) : slim_nil)

#define TPtrMemNode_GetPagePtr(self,in_offset) \
	((self)->fPtrs[((in_offset)>>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK ])



#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
#else
#define TPtrMemNode_LocateX(self,off) (TPtrMemNode_Locate((self),(off)))
#endif

#define TPtrMemNode_PeekPix(self, off) \
	(*(slim_pix*)((slim_byte*)TPtrMemNode_GetPagePtr((self),(off)) + ((off)&((1<<SLIM_MEMORY_BLOG)-1))))
#define TPtrMemNode_PeekHandle(self, off) \
	(*(slim_handle*)((slim_byte*)TPtrMemNode_GetPagePtr((self),(off)) + ((off)&((1<<SLIM_MEMORY_BLOG)-1))))

#define TPtrMemNode_UsedPages(self) TMemNode_UsedPages(self)
#define TPtrMemNode_TotalPages(self) TMemNode_TotalPages(self)

#define SLIM_PTRMEMNODE_DEBUG_VALID_PIX(memnode,pix) SLIM_MEMNODE_DEBUG_VALID_PIX(memnode,pix)
#define SLIM_PTRMEMNODE_DEBUG_VALID_PIX_OR_NIL(memnode,pix) SLIM_MEMNODE_DEBUG_VALID_PIX_OR_NIL(memnode,pix)

#ifdef SLIM_CONFIG_PTRMEMNODE_DEBUG
enum {
	SLIM_PTRMEMNODE_DEBUGNOTIFY_INIT,
	SLIM_PTRMEMNODE_DEBUGNOTIFY_ALLOC,
	SLIM_PTRMEMNODE_DEBUGNOTIFY_FREE,
	SLIM_PTRMEMNODE_DEBUGNOTIFY_FREEALL,
	SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCK,
	SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCATE,
	SLIM_PTRMEMNODE_DEBUGNOTIFY_FINALIZE,
	SLIM_PTRMEMNODE_DEBUGNOTIFIES
};

#define TPtrMemNode_VerifyPix(self, off) (\
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc) ? \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),0) : 0))
#define TPtrMemNode_Unlock(self,off) (\
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc) ? \
		((*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCK,(self),(off),-1),0) : 0))
#define TPtrMemNode_Unlocate(self,off) (\
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc) ? \
		((*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),-1),0) : 0))
#define TPtrMemNode_UnlocateX(self,off) (\
	TPtrMemNode_GetPageHandle((self),(off)))
#define TPtrMemNode_DebugNotifyAlloc(self, off, size)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_ALLOC, (self), (off), (size)); \
}
#define TPtrMemNode_DebugNotifyFree(self, off)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_FREE, (self), (off), 0); \
}
#define TPtrMemNode_DebugNotifyLocate(self, off, count)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCATE, (self), (off), (count)); \
}

typedef void (*PtrMemNode_AllocFreeDebugNotifyProc)(slim_int in_code, TPtrMemNode *in_memnode, slim_int in_arg1, slim_int in_arg2);

#else
#define TPtrMemNode_VerifyPix(self, off) ((void)0)
#define TPtrMemNode_Unlock(self,off) ((void*)0)
#define TPtrMemNode_Unlocate(self,off) ((void*)0)
#define TPtrMemNode_DebugNotifyAlloc(self, off, size)	{}
#define TPtrMemNode_DebugNotifyFree(self, off)	{}
#define TPtrMemNode_DebugNotifyLocate(self, off, count) {}
#endif


#endif /* SLIM_CONFIG_POINTER_MEMNODE */


SLIM_END_C_LINKAGE

#endif
