/*
	coll_a.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/coll_a.h 33    05/12/28 12:07 Someya $ */

#ifndef SLIM_COLL_A_H
#define SLIM_COLL_A_H

SLIM_BEGIN_C_LINKAGE

/* bag */
struct TBag_ {
	TMemNode fBase;
	slim_short fHeaderSize;		/* ROUNDUPed size of xxxItemHolder 	*/
	slim_short fItemSize;		/* actual size of item (not ROUNDUPed for acutal memcpy) */
	slim_short fHolderSize;		/* fHeaderSize + ROUNDUPed(fItemSize) */
	slim_short fHoldersPerPage;	/* holder number per page (SLIM_MEMORY_BSIZE / fHolderSize) */
	slim_int fItems;			/* total number of items in bag */
	slim_int fAllocHint;		/* on next allocation, search free item from here. 0 means there is no hint for alloc */
};
typedef struct TBag_ TBag;

typedef struct TBagItemHolder_ TBagItemHolder;
struct TBagItemHolder_ {
	TBagItemHolder *fNext;	/* next free holder offset in page */
							/* this field is used only this item holder is free,
							   otherwize this field is overwritten by item holder of bag user */
};

struct TBagPage_ {
	slim_int fFree;			/* number of free holder */
	TBagItemHolder *fToBeSplit;	/* the place offset to be split into new holder */
	TBagItemHolder *fFirstFree;	/* the first free holder offset in page */
};
typedef struct TBagPage_ TBagPage;

/* list */
struct TList_ {
	TBag fBase;
	slim_pix fFirst;
	slim_int fLength;
};
typedef struct TList_ TList;

struct TListItemHolder_ {
	slim_pix fPrev, fNext;
};
typedef struct TListItemHolder_ TListItemHolder;

struct TListVisit_ {
	slim_pix fIndex;	/* this member refers to the item last visited by TXXXList_VisitYYY() */
};
typedef struct TListVisit_ TListVisit;

/* array */

struct TArray_ {
	TMemNode fBase;
	slim_short fItemSize;
	slim_short fHolderSize;	/* = SLIM_COLL_ROUNDUP(fItemSize) */
	slim_short fHoldersPerPage;
	slim_short fPagePadding;
	slim_int fItems;
};
typedef struct TArray_ TArray;

struct TArrayVisit_ {
	slim_int fIndex;	/* this member refers to the item last visited by TXXXArray_VisitYYY() */
};
typedef struct TArrayVisit_ TArrayVisit;


struct TFastArray_ {
	TMemNode fBase;
	slim_short fItemSize;
	slim_short fSizeLog;
	slim_int fItems;
};
typedef struct TFastArray_ TFastArray;

/* var bag */


struct TVarBag_ {
	TMemNode fBase;
	slim_int fItems;
	slim_short fHeaderSize;
	slim_short fAllocHint; /* On the next allocation, search from this designated page. */
	slim_int fLastPage; /* The offset of the last page */
#ifdef SLIM_CONFIG_DEBUG
	slim_int fAllocatedBytes;
#endif
};
typedef struct TVarBag_ TVarBag;

struct TVarBagItemHolder_ {
	slim_int fHolderSize;
};
typedef struct TVarBagItemHolder_ TVarBagItemHolder;

/* A TVarBagFreeHolder is stored in a holder only if a holder is free,
   otherwise the area occupied by a TVarBagFreeHolder is overwritten by holder's item. */
typedef struct TVarBagFreeHolder_ TVarBagFreeHolder;
struct TVarBagFreeHolder_ {
	slim_int fHolderSize; /* If a holder is a used-holder, its holder-size is stored in its pseudo-index */
	TVarBagFreeHolder *fNextFree;  /* the pointer of the next free holder in the free holder list */
};

struct TVarBagPage_ {
	slim_int fFree; /* the number of free holders */
	TVarBagFreeHolder *fFirstFree; /* the pointer of the first free holder */
	/* fFirstFree == slim_nil means that there is no free holder in the free holder list */
};
typedef struct TVarBagPage_ TVarBagPage;

/* tree */
struct TTree_ {
	TVarBag fBase;
	slim_pix fRoot;
};
typedef struct TTree_ TTree;

struct TTreeItemHolder_ {
	TVarBagItemHolder fBase;
	slim_pix fPrev, fNext;
	slim_pix fParent, fFirstChild;
};
typedef struct TTreeItemHolder_ TTreeItemHolder;

struct TTreeVisit_ {
	slim_pix fIndex;	/* this member refers to the item last visited by TXXXTree_VisitYYY() */
};
typedef struct TTreeVisit_ TTreeVisit;

struct TTreeTraverse_ {
	slim_pix fPix;
	slim_short fDirection;
	slim_short fVisited;
};
typedef struct TTreeTraverse_ TTreeTraverse;

struct TTreeTraverseVisit_ {
	TTree *fTree;
	TTreeTraverse fTrav;
	TTreeVisit fVisit;
};
typedef struct TTreeTraverseVisit_ TTreeTraverseVisit;

SLIM_END_C_LINKAGE
#endif
