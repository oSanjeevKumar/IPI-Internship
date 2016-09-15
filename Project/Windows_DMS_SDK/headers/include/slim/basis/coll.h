/*
	coll.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/coll.h 156   06/07/10 14:58 Siu $ */

#ifndef SLIM_COLL_H
#define SLIM_COLL_H

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
#include <slim/basis/coll_a.h>
#else /* SLIM_CONFIG_MEMORY_ALTERNATIVE */
#include <slim/basis/coll_s.h>
#endif /* SLIM_CONFIG_MEMORY_ALTERNATIVE */

SLIM_BEGIN_C_LINKAGE
/*
 * common
 */
enum {
	SLIM_FOREACH_E_CONTINUE = 0,
	SLIM_FOREACH_E_BREAK,
	SLIM_FOREACH_E_SKIP,
	SLIM_FOREACH_EXCEPTIONS
};

/*
 * Iterator (Interface)
 */

typedef struct TObjectIterator_ TObjectIterator;

typedef slim_bool (*ObjectIterator_IsDoneProc)(TObjectIterator *self);
typedef slim_bool (*ObjectIterator_FirstProc)(TObjectIterator *self);
typedef slim_bool (*ObjectIterator_NextProc)(TObjectIterator *self);
typedef slim_opaque (*ObjectIterator_LockProc)(TObjectIterator *self);
typedef void (*ObjectIterator_UnlockProc)(TObjectIterator *self);
typedef void (*ObjectIterator_TidyProc)(TObjectIterator *self);

struct TObjectIterator_ {
	slim_opaque fUserData;
	slim_opaque fUserData2;
	slim_opaque fCurPos;
	ObjectIterator_IsDoneProc fIsDone;
	ObjectIterator_FirstProc fFirst;
	ObjectIterator_NextProc fNext;
	ObjectIterator_LockProc fLock;
	ObjectIterator_UnlockProc fUnlock;
	ObjectIterator_TidyProc fTidy;
#ifdef SLIM_CONFIG_DEBUG
	slim_int fLockCount;
#endif
};

/* API */
#define TObjectIterator_IsDone(self) ((*(self)->fIsDone)((self)))
#define TObjectIterator_First(self) ((*(self)->fFirst)((self)))
#ifndef SLIM_CONFIG_DEBUG
#define TObjectIterator_Next(self) ((*(self)->fNext)((self)))
#define TObjectIterator_Lock(self) ((*(self)->fLock)((self)))
#define TObjectIterator_Unlock(self) ((self)->fUnlock ? (*(self)->fUnlock)((self)) : (void)0)
#define TObjectIterator_Finalize(self) ((self)->fTidy ? (*(self)->fTidy)((self)) : (void)0)
#endif

/* 
 * Hash
 */
#define SLIM_HASH_FLAG_OVERWRITE	0x00000001

typedef slim_opaque (*THashGetKeyProc)(void *in_located_item);
typedef slim_int (*THashItemHashProc)(slim_opaque in_key_coll, slim_opaque in_item_key);
typedef slim_int (*THashExtHashProc)(slim_opaque in_ext_key);
typedef slim_bool (*THashEqualProc)(slim_opaque in_key_coll, slim_opaque in_item_key, slim_opaque in_ext_key, slim_int in_full_hash);
typedef void *(*THashLockItemProc)(slim_opaque in_item_coll, slim_opaque in_item);
typedef void (*THashUnlockItemProc)(slim_opaque in_item_coll, slim_opaque in_item);

struct THash_ {
	slim_short fTableOffset;
	slim_short fTableSize;
	slim_short fTableSizeMask;
	slim_short fNextOffset;
	slim_opaque fItemColl;
	slim_opaque fKeyColl;
	THashGetKeyProc fGetKeyProc;
	THashItemHashProc fItemHashProc;
	THashExtHashProc fExtHashProc;
	THashEqualProc fEqualProc1;
	THashLockItemProc fLockItemProc;
	THashUnlockItemProc fUnlockItemProc;
#ifdef SLIM_CONFIG_DEBUG_HASH_DISTRIBUTION
	slim_int fFinds;
	slim_int fSkips;
	slim_short fDebugItems;
	slim_short fDebugMaxItems;
	slim_short *fDistribution;
#endif	
};
typedef struct THash_ THash;

/* list */
struct TSpecList_ {
	TList fBase;
};
typedef struct TSpecList_ TSpecList;

struct TOpaqueList_ {
	TList fBase;
};
typedef struct TOpaqueList_ TOpaqueList;
typedef TListItemHolder TOpaqueListItemHolder;


typedef TOpaqueList TObjectList;
typedef TOpaqueList TIntList;
typedef TOpaqueList TPtrList;

/* array */
struct TSpecArray_ {
	TArray fBase;
};
typedef struct TSpecArray_ TSpecArray;

struct TOpaqueArray_ {
	TArray fBase;
};
typedef struct TOpaqueArray_ TOpaqueArray;

typedef TOpaqueArray TObjectArray;
typedef TOpaqueArray TIntArray;
typedef TOpaqueArray TPtrArray;

struct TSpecFastArray_ {
	TFastArray fBase;
};
typedef struct TSpecFastArray_ TSpecFastArray;

struct TOpaqueFastArray_ {
	TFastArray fBase;
};
typedef struct TOpaqueFastArray_ TOpaqueFastArray;

typedef TOpaqueFastArray TObjectFastArray;
typedef TOpaqueFastArray TIntFastArray;
typedef TOpaqueFastArray TPtrFastArray;

/*
 * linear array is array implementation with vhandle, not memnode.
 */

#define SLIM_COLL_LINEARARRAY_DEFINED /* for compatibility */

struct TLinearArray_ {
	slim_int     fItemSize;
	slim_int     fLength;
	slim_int fMaxLength;
	slim_int fRoundup;
	slim_vhandle fHandle;
};
typedef struct TLinearArray_  TLinearArray;

struct TLinearArrayVisit_ {
	slim_byte* fLockedBuffer;
};
typedef struct TLinearArrayVisit_ TLinearArrayVisit;

/*
 * Tree
 */

enum {
	SLIM_TREE_FOREACH_TYPE_NOLOCK, /* without locking item */
	SLIM_TREE_FOREACH_TYPE_CHILDREN1, /* one way */
	SLIM_TREE_FOREACH_TYPE_CHILDREN2, /* both way */
	SLIM_TREE_FOREACH_TYPE_ANCESTOR
};

#define SLIM_TREE_FOREACH_CONTINUE SLIM_FOREACH_E_CONTINUE
#define SLIM_TREE_FOREACH_BREAK SLIM_FOREACH_E_BREAK
#define SLIM_TREE_FOREACH_SKIP SLIM_FOREACH_E_SKIP

typedef slim_int (*Tree_ForeachProc)(slim_pix in_pix, slim_int in_dir, void *in_item, slim_opaque in_arg);
typedef void (*TTreeTidyProc)(TTree *self, slim_pix in_pix, slim_opaque in_arg);

enum {
	SLIM_NODE_CMP_PRECEDING,
	SLIM_NODE_CMP_FOLLOWING,
	SLIM_NODE_CMP_EQUAL,
	SLIM_NODE_CMP_DIFFERENT_TREE
};

SLIM_END_C_LINKAGE
#endif
