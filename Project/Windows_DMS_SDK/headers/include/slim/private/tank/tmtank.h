/*
    (private) tmtank.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_MEMORY_TANK_H_PRIVATE_MODULE
#define SLIM_MEMORY_TANK_H_PRIVATE_MODULE

SLIM_BEGIN_C_LINKAGE

/* config */

/*
 * SLIM_CONFIG_MEMORY_DEBUG related macros.
 */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
	#define SLIM_MEMORY_DEBUGNOTIFY(symbol, b, c, d, e, f, g, h) \
		if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_MemoryAllocFreeDebugNotifyProc)) { \
			(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_MemoryAllocFreeDebugNotifyProc))( \
				(SLIM_MEMORY_DEBUGNOTIFY_ ## symbol), (b), (c), (d), (e), (f), (g), (h) \
			); \
		}
	#define SLIM_MEMORY_DEBUGNOTIFY_HANDLE(symbol, h, size, tank1, tank2) \
		if (h) { \
			SLIM_MEMORY_DEBUGNOTIFY(symbol, h, *(void**)h, size, slim_tank_memory_block_size(*(void**)h), slim_tank_memory_debug_from(*(void**)h), (tank1), (tank2)); \
		} else { \
			SLIM_MEMORY_DEBUGNOTIFY(symbol, h, slim_nil, size, 0, 0, slim_nil, slim_nil); \
		}
	#define SLIM_MEMORY_DEBUGNOTIFY_ALERT(string) \
		SLIM_MEMORY_DEBUGNOTIFY(ALERT, (string), __FILE__, __LINE__, 0, 0, 0, 0)
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
	#define SLIM_MEMORY_DEBUGNOTIFY(symbol, b, c, d, e, f, g, h)
	#define SLIM_MEMORY_DEBUGNOTIFY_HANDLE(symbol, h, size, tank1, tank2)
	#define SLIM_MEMORY_DEBUGNOTIFY_ALERT(string)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define TTank_BLOCK_SET_FROM(a, b, c) TTank_block_set_from((a), (b), (c))
#define TTank_BLOCK_FROM(a, b) TTank_block_from((a), (b))
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
#define TTank_BLOCK_SET_FROM(a, b, c) ((void)0)
#define TTank_BLOCK_FROM(a, b) ((slim_word)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

#ifdef SLIM_CONFIG_MEMORY_CHECKOW_DEBUG
	#define SLIM_MEMORY_CHECKOW         0xCD
	#define SLIM_MEMORY_CHECKOW_SIZE    4
	#define SLIM_MEMORY_CHECKOW_BYTES   (SLIM_ROUNDUP_P2(SLIM_MEMORY_CHECKOW_SIZE, SLIM_CONFIG_CC_STRUCTALIGN))
#else /* !defined(SLIM_CONFIG_MEMORY_CHECKOW_DEBUG) */
	#define SLIM_MEMORY_CHECKOW_BYTES   0
#endif /* !defined(SLIM_CONFIG_MEMORY_CHECKOW_DEBUG) */

#ifdef SLIM_CONFIG_MEMORY_PROTECT_DEBUG
#define TTank_LOCK_BLOCK_PROTECT_DEBUG(tank, a, b) TTank_lock_block((tank), (a), (b))
#else /* !defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG) */
#define TTank_LOCK_BLOCK_PROTECT_DEBUG(tank, a, b) ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG) */

/* Converts adress to block number. If address is of fragment, it returns block number of containing block */
#define TTank_A2B(tank, a)	(((slim_byte *)(a) - (slim_byte *)((tank)->fHeapBase)) >> SLIM_MEMORY_BLOG)
/* Converts block number to address */
#define TTank_B2A(tank, b)	((void *)(((slim_int)(b) << SLIM_MEMORY_BLOG) + (slim_byte *)((tank)->fHeapBase)))

/* fragment header size */
#define SLIM_MEMORY_FRAGSPEC_SIZE	(SLIM_ROUNDUP_P2(sizeof(TMemFragSpec), SLIM_CONFIG_CC_STRUCTALIGN))

#define SLIM_MEMORY_MPTRBLK(h)		((TMasterPtrBlk *)((slim_uiaddr_word)(h) & ~(SLIM_MEMORY_BSIZE - 1)))
#define SLIM_MEMORY_MPTRS_PER_BLK	(((SLIM_MEMORY_BSIZE - SLIM_OFFSETOF(TMasterPtrBlk, fMasterPtrAndTank)) / sizeof(void *)) & ~1)
#define SLIM_MEMORY_DEF_MPTRBLKS	10

#define SLIM_MEMORY_HIGH				0x00000001
#define SLIM_MEMORY_DONOT_COMPACTION	0x00000002

#ifdef SLIM_CONFIG_MEMORY_DEBUG
#define SLIM_MEMORY_CHECKLOCATE SLIM_ASSERT(SLIM_RESOLVE_GLOBAL_VAR(gSlim_MemoryLocateCount) == 0)
#else
#define SLIM_MEMORY_CHECKLOCATE
#endif

#define SLIM_MEMORY_FROM_FREED		0xfefefefe
#define SLIM_MEMORY_PURGEBYTE		0xfd

#ifndef SLIM_TANK_MEMORY_MAX_NEW_HANDLERS
#define SLIM_TANK_MEMORY_MAX_NEW_HANDLERS	2
#endif /* SLIM_TANK_MEMORY_MAX_NEW_HANDLERS */

/*
	TMemBlock

	* Free block
	  .uFree.fType				always -1
	  .uFree.fSize				size of free block (in numbers of blocks)
	  .uFree.fNext				next free block number
	  .uFree.fPrev				previous free block number
	* Allocated block (normal block, not fragment)
	  .uAllocBlock.fType		always 0
	  .uAllocBlock.fSize		size of allocated block (in numbers of blocks) >= 1
	* Allocated block (fragment container)
	  .uAllocFrag.fType			log2 of size in bytes of fragment (same positon and size with uAllocBlock.fType)
	  .uAllocFrag.fFree			number of free fragments in block
	  .uAllocFrag.fToBeSplit	
	  .uAllocFrag.fFreeList		-1 or pointer to free fragment list in block (mod SLIM_MEMORY_BSIZE)
	  .uAllocFrag.fNext			next fragment block number
*/

struct TMemFragSpec_ {
	slim_int fLockCount;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_word fFrom;
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
};
typedef struct TMemFragSpec_ TMemFragSpec;

struct TMemBlock_AllocBlock_ {
	slim_short fType;	/* this field must be common with TMemBlock.uAllocFrag.fType */
	slim_short fSize;
	slim_int fLockCount;
	void **fMasterPtr;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_word fFrom;
#endif /* defined(SLIM_CONFIG_MEMORY_DEBUG) */
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
	slim_short fType; /* this field must be common with TMemBlock.uAllocBlock.fType, and must be -1 */
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

/* This struct is used only fragment is free, otherwise this struct is overwritten by memory user */
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
	/*
	 * fMasterPtrAndTank[2*k] is a master pointer.
	 * fMasterPtrAndTank[2*k + 1] is the corresponding TTank *.
	 */
	void *fMasterPtrAndTank[1];
};
typedef struct TMasterPtrBlk_ TMasterPtrBlk;

/* memory crisis callback entry */
struct TCallbackTable_ {
	slim_opaque fID;
	slim_bool (*fProc)(slim_opaque,slim_int);
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
#define slim_tank_memory_mutex_lock()	slimMemoryMutexLockPeer(SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemoryMutex))
#define slim_tank_memory_mutex_unlock()	slimMemoryMutexUnlockPeer(SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemoryMutex))
#else /* !defined(SLIM_CONFIG_MULTITHREAD) */
#define slim_tank_memory_mutex_lock()	((void)0)
#define slim_tank_memory_mutex_unlock()	((void)0)
#endif /* !defined(SLIM_CONFIG_MULTITHREAD) */

#define slim_tank_handle_addr(h, off)		((*(slim_byte **)(h))+SLIM_MEMORY_CHECKOW_BYTES+(off))
#define slim_tank_vhandle_addr(h, off)		((*(slim_byte **)(h))+SLIM_MEMORY_CHECKOW_BYTES+(off))

/* peekers... */
#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
#else
#define slim_tank_handle_peek_int(h, off)		(*(slim_int*)slim_tank_handle_addr((h),(off)))
#define slim_tank_handle_peek_short(h, off)		(*(slim_short*)slim_tank_handle_addr((h),(off)))
#define slim_tank_handle_peek_pix(h, off)		(*(slim_pix*)slim_tank_handle_addr((h),(off)))
#define slim_tank_handle_peek_handle(h, off)		(*(slim_handle*)slim_tank_handle_addr((h),(off)))
#define slim_tank_handle_peek_vhandle(h, off)	(*(slim_vhandle*)slim_tank_handle_addr((h),(off)))
#define slim_tank_handle_peek_ptr(h, off)		(*(void**)slim_tank_handle_addr((h),(off)))
#define slim_tank_handle_peek_opaque(h, off)		(*(slim_opaque*)slim_tank_handle_addr((h),(off)))
#define slim_tank_vhandle_peek_int(h, off)		slim_tank_handle_peek_int((h), (off))
#define slim_tank_vhandle_peek_short(h, off)		slim_tank_handle_peek_short((h), (off))
#define slim_tank_vhandle_peek_pix(h, off)		slim_tank_handle_peek_pix((h), (off))
#define slim_tank_vhandle_peek_handle(h, off)	slim_tank_handle_peek_handle((h), (off))
#define slim_tank_vhandle_peek_vhandle(h, off)	slim_tank_handle_peek_vhandle((h), (off))
#define slim_tank_vhandle_peek_ptr(h, off)		slim_tank_handle_peek_ptr((h), (off))
#define slim_tank_vhandle_peek_opaque(h, off)	slim_tank_handle_peek_opaque((h), (off))
#endif

#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_bool slim_tank_memory_debug_is_alloc_failure(void);
	void slim_tank_memory_debug_set_random_alloc_failure_proc(Slim_MemoryRandomAllocFailureProc in_proc);
#else /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */
	#define slim_tank_memory_debug_is_alloc_failure()	(slim_false)
	#define slim_tank_memory_debug_set_random_alloc_failure_proc(proc) ((void)0)
#endif /* !defined(SLIM_CONFIG_MEMORY_DEBUG) */

/* macros */
#define Tank_MainTank() (&SLIM_RESOLVE_GLOBAL_VAR(gSlim_MainTank))
/*
 * h[0] is the master pointer of the handle.
 * h[1] is the TTank * of the handle.
 * cf. fMasterPtrAndTank.
 */
#define Tank_HandleToTank(h) ((TTank *)*((void **)(h) + 1))

/*             */
/* memory node */
/*             */

#define TankMemNode_IsPixInSamePage(p1,p2)	(((((p1)^(p2)) >>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK) == 0)
#define TTankMemNode_GetPageHandleAndCheck(self, in_offset)	\
 (((self)->fHandleSize > (((in_offset)>>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK)) ? \
	TTankMemNode_GetPageHandle((self), (in_offset)) : slim_nil)
#define TTankMemNode_GetPageHandle(self, in_offset)	\
	((self)->fHandles[((in_offset)>>SLIM_MEMORY_BLOG) & SLIM_MEMORY_BLOG_SHIFT_MASK ])

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
#else
#define TTankMemNode_LocateX(self,off) (TTankMemNode_Locate((self),(off)))
#endif

#define TTankMemNode_PeekPix(self, off) \
	(slim_tank_handle_peek_pix(TTankMemNode_GetPageHandle((self),(off)),(off)&((1<<SLIM_MEMORY_BLOG)-1)))

#define TTankMemNode_UsedPages(self)		((self)->fUsedPages)
#define TTankMemNode_TotalPages(self)		((self)->fHandleSize)

#define TTankMemNode_IsValidPix(memnode, pix)			((pix) != slim_pix_nil)
#define TTankMemNode_IsValidPixOrNil(memnode, pix)	(slim_true)

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
#define TTankMemNode_VerifyPix(self, off) (\
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc) ? \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),0) : ((void)0)))
#define TTankMemNode_Unlock(self,off) (\
	slim_tank_handle_unlock(TTankMemNode_GetPageHandle((self),(off))), \
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc) ? \
		((*SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCK,(self),(off),-1),0) : 0))
#define TTankMemNode_Unlocate(self,off) (\
	slim_handle_unlocate(TTankMemNode_GetPageHandle((self),(off))), \
	(SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc) ? \
		((*SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),-1),0) : 0))
#define TTankMemNode_UnlocateX(self,off) (\
	slim_handle_unlocate(TTankMemNode_GetPageHandle((self),(off))))

#define TTankMemNode_DebugNotifyAlloc(self, off, size)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_ALLOC, (self), (off), (size)); \
}
#define TTankMemNode_DebugNotifyFree(self, off)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_FREE, (self), (off), 0); \
}
#define TTankMemNode_DebugNotifyLocate(self, off, count)	{\
	if (SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc)) \
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_TankMemNodeAllocFreeDebugNotifyProc))(SLIM_MEMNODE_DEBUGNOTIFY_LOCATE, (self), (off), (count)); \
}
typedef void (*TankMemNode_AllocFreeDebugNotifyProc)(slim_int, TTankMemNode *, slim_int, slim_int);
#else
#define TTankMemNode_VerifyPix(self, off) ((void)0)
#define TTankMemNode_Unlock(self,off) (slim_handle_unlock(TTankMemNode_GetPageHandle((self),(off))))
#define TTankMemNode_Unlocate(self,off) (slim_handle_unlocate(TTankMemNode_GetPageHandle((self),(off))))
#define TTankMemNode_DebugNotifyAlloc(self, off, size)	{}
#define TTankMemNode_DebugNotifyFree(self, off)	{}
#define TTankMemNode_DebugNotifyLocate(self, off, count) {}
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
		(*SLIM_RESOLVE_GLOBAL_VAR(gSlim_PtrMemNodeAllocFreeDebugNotifyProc))(SLIM_PTRMEMNODE_DEBUGNOTIFY_LOCATE,(self),(off),0) : (void)0))
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

typedef void (*PtrMemNode_AllocFreeDebugNotifyProc)(slim_int, TPtrMemNode *, slim_int, slim_int);

#else
#define TPtrMemNode_VerifyPix(self, off) ((void)0)
#define TPtrMemNode_Unlock(self,off) ((void*)0)
#define TPtrMemNode_Unlocate(self,off) ((void*)0)
#define TPtrMemNode_DebugNotifyAlloc(self, off, size)	{}
#define TPtrMemNode_DebugNotifyFree(self, off)	{}
#define TPtrMemNode_DebugNotifyLocate(self, off, count) {}
#endif

#endif /* SLIM_CONFIG_POINTER_MEMNODE */


/* Tank itself. */

struct TTank_ {
	/*
	 * fPrev is a link to the previous tank of this tank.
	 * if fPrev == slim_nil, this tank is the main tank.
	 */
	struct TTank_ *fPrev;

	/*
	 * fNext is a link to the next tank of this tank.
	 * if fNext == slim_nil, this tank is the last tank
	 *  (the main tank or a sub tank).
	 */
	struct TTank_ *fNext;

	/*
	 * fHeapNonAlignedAddress is the starting address of the heap.
	 * It is used to free heap if fFreeHeapOnDestory is slim_true.
	 */
	void *fHeapNonAlignedAddress;
	slim_bool fFreeHeapOnDestroy;
	 
	/*
	 * fHeapBase is NOT ALWAYS the starting address of the heap.
	 * fHeapBase is aligned to SLIM_MEMORY_BSIZE.
	 * fHeapBase != slim_nil.
	 * fHeapBase does not change after initialization.
	 */
	void *fHeapBase;

	/*
	 * fHeapBreak is the next to the last address of the tank.
	 * fHeapBreak is aligned to SLIM_MEMORY_BSIZE.
	 * fHeapBreak != slim_nil.
	 * fHeapBreak does not change after initialization.
	 */
	void *fHeapBreak;

	/*
	 * fTankAreaBytes is the original length of the area for the tank.
	 * fTankAreaBytes does NOT always equal to fHeapBreak - fHeapBase.
	 * This is for max total size check.
	 */
	slim_int fTankAreaBytes;

	/*
	 * fHeapMap is the pointer to the heap map (block usage info) of the tank.
	 * The heap map is allocated at the head of the tank itself.
	 * fHeapMap does not change after initialization.
	 */
	TMemBlock *fHeapMap;

	/*
	 * fFragBlk[k] is the starting block for the fragment of the tank.
	 * 2 ** k >= size-of-the-fragment != 0
	 */
	slim_int fFragBlk[SLIM_MEMORY_BLOG];

	/*
	 * fCurFragBlk[k] is the current block for the fragment of the tank.
	 * 2 ** k >= size-of-the-fragment != 0
	 */
	slim_int fCurFragBlk[SLIM_MEMORY_BLOG];

	/*
	 * fMPtrBlk is the start address of
	 * master pointer blocks of the tank.
	 * The master pointer blocks linked as a doubly linked list.
	 * A master pointer block is the area that is pointed
	 * with 'handle' and 'vhandle'.
	 * The master pointer block contains the real address of
	 * 'handle' or 'vhandle'.
	 * Most master pointer blocks are allocated at the tail of the tank itself.
	 * fMPtrBlk does not change after initialization.
	 */
	TMasterPtrBlk *fMPtrBlk;

	/*
	 * fCurMPtrBlk is the current master pointer block of the tank.
	 */
	TMasterPtrBlk *fCurMPtrBlk;
	slim_int fMPtrIndex;

	/*
	 * At the begining, SLIM_MEMORY_DEF_MPTRBLKS blocks are
	 * automatically allocated at highest memory area.
	 * And these blocks are not freed.
	 *
	 * fPersistMPtrBound is the lowest address of the
	 * initially allocated master pointer blocks.
	 * Higher blocks than fPersistMPtrBound are not freed.
	 * Note: This is true for the main tank only.
	 * All blocks are freed in sub tanks.
	 */
	slim_int fPersistMPtrBound;
	/*
	 * fRemainingBlocks is the number of remaining blocks.
	 */
	slim_int fRemainingBlocks;
	/*
	 * fBlocks is the total number of blocks.
	 * This equals to fRemainingBlocks at the beginning.
	 * fBlocks does not include blocks for fHeapMap.
	 */
	slim_int fBlocks;
};
typedef struct TTank_ TTank;

/*
 * Prototypes.
 * Do not include SLIM_API here.
 */

#ifdef SLIM_CONFIG_MEMORY_DEBUG
slim_word slim_tank_memory_debug_from(void *in_addr);
slim_bool slim_tank_memory_debug_from_equal(slim_word in_from, slim_int in_from_element);
slim_char * slim_tank_memory_debug_from_name(slim_word in_from, slim_int *out_len);
slim_char * slim_tank_memory_debug_from_name_array(slim_word in_from);
slim_word slim_tank_memory_block_from(void *in_addr);
void slim_tank_memory_block_set_from(void *in_addr, slim_word in_from);
void slim_tank_memory_debug_set_random_alloc_failure_proc(Slim_MemoryRandomAllocFailureProc in_proc);
slim_bool slim_tank_memory_debug_is_alloc_failure(void);
void slim_tank_memory_debugout_statistics(void);
#endif /* defined( SLIM_CONFIG_MEMORY_DEBUG) */

void * slim_tank_memory_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_handle slim_tank_handle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
slim_vhandle slim_tank_vhandle_sparealloc(slim_int in_size, slim_int in_spare_blocks);
void slim_tank_memory_get_free_size(slim_int *out_total, slim_int *out_longest_blocks);

#ifdef SLIM_CONFIG_DEBUG
void slim_tank_memory_debug_dump(slim_bool in_showfrag);
void slim_tank_memory_debug_dump_string(slim_bool in_showfrag);
#endif /* defined(SLIM_CONFIG_DEBUG) */

#if defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG)
slim_int slim_tank_handle_peek_int(slim_handle in_handle, slim_int in_offset);
slim_short slim_tank_handle_peek_short(slim_handle in_handle, slim_int in_offset);
slim_pix slim_tank_handle_peek_pix(slim_handle in_handle, slim_int in_offset);
slim_handle slim_tank_handle_peek_handle(slim_handle in_handle, slim_int in_offset);
slim_vhandle slim_tank_handle_peek_vhandle(slim_handle in_handle, slim_int in_offset);
void * slim_tank_handle_peek_ptr(slim_handle in_handle, slim_int in_offset);
slim_opaque slim_tank_handle_peek_opaque(slim_handle in_handle, slim_int in_offset);
slim_int slim_tank_vhandle_peek_int(slim_vhandle in_vhandle, slim_int in_offset);
slim_short slim_tank_vhandle_peek_short(slim_vhandle in_vhandle, slim_int in_offset);
slim_pix slim_tank_vhandle_peek_pix(slim_vhandle in_vhandle, slim_int in_offset);
slim_handle slim_tank_vhandle_peek_handle(slim_vhandle in_vhandle, slim_int in_offset);
slim_vhandle slim_tank_vhandle_peek_vhandle(slim_vhandle in_vhandle, slim_int in_offset);
void * slim_tank_vhandle_peek_ptr(slim_vhandle in_vhandle, slim_int in_offset);
slim_opaque slim_tank_vhandle_peek_opaque(slim_vhandle in_vhandle, slim_int in_offset);
#endif /* defined(SLIM_CONFIG_MULTITHREAD) || defined(SLIM_CONFIG_MEMORY_PROTECT_DEBUG) */

#ifdef SLIM_CONFIG_MEMNODE_DEBUG
void TankMemNode_DebugSetNotifyProc(TankMemNode_AllocFreeDebugNotifyProc in_proc);
void * TTankMemNode_LocateX(TTankMemNode *self, slim_int in_offset);
#endif /* defined(SLIM_CONFIG_MEMNODE_DEBUG) */

slim_bool TTankMemNode_Initialize(TTankMemNode *self);
void TTankMemNode_Finalize(TTankMemNode *self);
void * TTankMemNode_Lock(TTankMemNode *self, slim_int in_offset, slim_handle *out_locked_handle);
void * TTankMemNode_Locate(TTankMemNode *self, slim_int in_offset);

slim_handle TTankMemNode_ZeroAlloc(TTankMemNode *self, slim_int in_offset);
void TTankMemNode_Free(TTankMemNode *self, slim_int in_offset);
void TTankMemNode_FreeAll(TTankMemNode *self);

SLIM_END_C_LINKAGE

#endif /* !defined(SLIM_MEMORY_TANK_H_PRIVATE_MODULE) */
