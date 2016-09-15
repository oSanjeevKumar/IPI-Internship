/*
	coll.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /Work/suzuki/tank/sw/slim/slim/private/basis/coll_s.h 12    06/09/08 20:26 Suzuki $ */

#ifndef SLIM_COLL_S_H_PRIVATE
#define SLIM_COLL_S_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* utility macro */

#define SLIM_COLL_ROUNDUP(s) SLIM_ROUNDUP_P2(s, SLIM_CONFIG_CC_STRUCTALIGN)


/*                */
/* bag collection */
/*                */

#ifdef SLIM_CONFIG_DEBUG
#else
#define TBag_Locate(self,pix) ((TBagItemHolder *)TMemNode_Locate(&(self)->fBase, (slim_int)(pix)))
#define TBag_Unlocate(self,pix) (TMemNode_Unlocate(&(self)->fBase, (slim_int)(pix)))
#endif
#define TBag_IsEmpty(self) ((self)->fItems == 0)
#define TBag_Items(self) ((self)->fItems)
#define TBag_Remove(self,pix) (TBag_FreeHolder((self),(pix)))
#ifdef SLIM_CONFIG_DEBUG
#else
#define TBag_LockItem(self,pix)	\
		((void *)((slim_byte *)TMemNode_Lock(&(self)->fBase,(slim_uiaddr_word)(pix),slim_nil) + (self)->fHeaderSize))
#define TBag_UnlockItem(self,pix) (TMemNode_Unlock(&(self)->fBase, (slim_int)(pix)))
#endif
#define TBag_LocateItem(self,pix) ((void *)((slim_byte *)TBag_Locate((self),(pix)) + (self)->fHeaderSize))
#define TBag_UnlocateItem(self,pix) (TBag_Unlocate((self),(pix)))

#define TBag_PeekPix(self,pix,off) (TMemNode_PeekPix(&(self)->fBase,(slim_int)(pix)+(off)))
#define TBag_PeekHandle(self,pix,off) (TMemNode_PeekHandle(&(self)->fBase,(slim_int)(pix)+(off)))

/* generic list */

#define TList_Finalize(self) (TBag_Finalize(&(self)->fBase))
#define TList_Locate(self,pix) ((TListItemHolder *)TBag_Locate(&(self)->fBase,(pix)))
#define TList_Unlocate(self,pix) (TBag_Unlocate(&(self)->fBase, (pix)))
#define TList_MakeEmpty(self) {TBag_MakeEmpty(&(self)->fBase);(self)->fFirst=slim_pix_nil;(self)->fLength=0;}
#define TList_IsEmpty(self) ((self)->fFirst == slim_pix_nil)
#define TList_Length(self) ((self)->fLength)
#define TList_Items(self) (TBag_Items(&(self)->fBase))
#define TList_First(self) ((self)->fFirst)


#define TListVisit_CurrentPix(self) ((self)->fIndex)
#define TListVisit_CurrentHolder(visit) ((visit)->fItemHolder)


/* generic array */
#define TArray_MakeEmpty(self) {TMemNode_FreeAll(&(self)->fBase);(self)->fItems=0;}
#define TArray_IsEmpty(self) ((self)->fItems == 0)
#define TArray_Length(self) ((self)->fItems)
#define TArray_RemoveLast(self) (TArray_FreeItem((self)))
#define TArray_LockItem(self,index) (TMemNode_Lock(&(self)->fBase,TArray_CalcOffset((self),(index)),slim_nil))
#define TArray_UnlockItem(self,index) (TMemNode_Unlock(&(self)->fBase,TArray_CalcOffset((self),(index))))
#define TArray_LocateItem(self,index) (TMemNode_Locate(&(self)->fBase, TArray_CalcOffset((self), (index))))
#define TArray_UnlocateItem(self,index) (TMemNode_Unlocate(&(self)->fBase, TArray_CalcOffset((self), (index))))

/* generic fast array */

#define TFastArray_CalcOffset(self,index) ((slim_int)((index)<<(self)->fSizeLog))
#define TFastArray_MakeEmpty(self) {TMemNode_FreeAll(&(self)->fBase);(self)->fItems=0;}
#define TFastArray_IsEmpty(self) ((self)->fItems == 0)
#define TFastArray_Length(self) ((self)->fItems)
#define TFastArray_RemoveLast(self) (TFastArray_FreeItem((self)))
#define TFastArray_LockItem(self,index) (TMemNode_Lock(&(self)->fBase,TFastArray_CalcOffset((self),(index)),slim_nil))
#define TFastArray_UnlockItem(self,index) (TMemNode_Unlock(&(self)->fBase,TFastArray_CalcOffset((self),(index))))
#define TFastArray_LocateItem(self,index) (TMemNode_Locate(&(self)->fBase, TFastArray_CalcOffset((self), (index))))
#define TFastArray_UnlocateItem(self,index) (TMemNode_Unlocate(&(self)->fBase, TFastArray_CalcOffset((self), (index))))

/*                     */
/* variable length bag */
/*                     */

#define SLIM_VARBAG_VALID_PIX_SIZE(in_holder_size)     ((in_holder_size) >= 0)
#define SLIM_VARBAG_VALID_PIX_OFFS(in_position_offset) ((in_position_offset) >= 0)
#define SLIM_VARBAG_PIX_OFFS(in_pix)                   ((slim_int)(in_pix))

#ifdef SLIM_CONFIG_DEBUG
	/* Function is defined in slim_coll_vbag.c */
#else /* !defined(SLIM_CONFIG_DEBUG) */
	#define TVarBag_Locate(self, pix) 	(TMemNode_Locate(  &(self)->fBase, SLIM_VARBAG_PIX_OFFS(pix)))
	#define TVarBag_Unlocate(self, pix)	(TMemNode_Unlocate(&(self)->fBase, SLIM_VARBAG_PIX_OFFS(pix)))
#endif /* !defined(SLIM_CONFIG_DEBUG) */
#define TVarBag_GetItem(self,pix,buf,sz) (TVarBag_CopyOut((self), (pix), 0, (sz), (buf)))
#define TVarBag_SetItem(self,pix,buf,sz) (TVarBag_CopyIn( (self), (pix), 0, (sz), (buf)))
#define TVarBag_Items(self) ((self)->fItems)
#ifdef SLIM_CONFIG_DEBUG
	/* Function is defined in slim_coll_vbag.c */
#else /* !defined(SLIM_CONFIG_DEBUG) */
	#define TVarBag_LockItem(self,pix) \
		((void *)((slim_byte *)TMemNode_Lock(&(self)->fBase, SLIM_VARBAG_PIX_OFFS(pix), slim_nil) + (self)->fHeaderSize))
	#define TVarBag_UnlockItem(self,pix) (TMemNode_Unlock(&(self)->fBase, (slim_int)(pix)))
#endif /* !defined(SLIM_CONFIG_DEBUG) */
#define TVarBag_LocateItem(self,pix) ((void *)((slim_byte *)TVarBag_Locate((self),(pix)) + (self)->fHeaderSize))
#define TVarBag_UnlocateItem(self,pix) (TVarBag_Unlocate((self),(pix)))

#define TVarBag_PeekPix(self,pix,off)    (TMemNode_PeekPix(   &(self)->fBase,(slim_int)(SLIM_VARBAG_PIX_OFFS(pix)+(off))))
#define TVarBag_PeekHandle(self,pix,off) (TMemNode_PeekHandle(&(self)->fBase,(slim_int)(SLIM_VARBAG_PIX_OFFS(pix)+(off))))

#ifdef SLIM_CONFIG_DEBUG
	#define TVarBag_DebugOutStatistics(self,newline) (TVarBag_DebugOutStatisticsX((self),(newline),0))
#endif /* defined(SLIM_CONFIG_DEBUG) */

#define TVarBag_VerifyPix(self, pix)      (TMemNode_VerifyPix(     &(self)->fBase, SLIM_VARBAG_PIX_OFFS((pix))))
#define TVarBag_VerifyPixOrNil(self, pix) (TMemNode_VerifyPixOrNil(&(self)->fBase, SLIM_VARBAG_PIX_OFFS((pix))))

/*
 * At the tail of header, we reserve an area for a size of holder (slim_short).
 * 
 * holder             pix of the item (offset used in TMemNode)
 * |                  |
 * v                  v
 *  <--(1)-> <--(2)--> <---------(3)----------->
 * +--------+---------+-------------------------+
 * |        |   (X)   |                         |
 * +--------+---------+-------------------------+
 *  <-------------------(X)--------------------->
 *  <------(Y)------->
 *
 * (1) in_header_sz (header used by subclass of TVarBag)
 * (2) sizeof(slim_short)
 * (3) item itself
 *
 * (X) = holder size (may differ for holder by holder)
 * (Y) = fHeaderSize
 */
#define SLIM_VARBAG_SIZE_OF_HOLDERSIZE	sizeof(slim_short)

/*                 */
/* tree collection */
/*                 */

/* treetpl.txt */
slim_bool TTree_Foreach (TTree *self, slim_int in_type, slim_pix in_start_pix, Tree_ForeachProc in_proc, slim_opaque in_arg, slim_pix *out_pix);
slim_int TTree_NodeCmp (TTree *self, slim_pix in_pix1, slim_int in_pix1_dir, slim_pix in_pix2, slim_int in_pix2_dir);

#define TTreeVisit_CurrentPix(visit) ((visit)->fIndex)

#define TTree_Finalize(self) (TVarBag_Finalize(&(self)->fBase))
#define TTree_IsEmpty(self) ((self)->fRoot == slim_pix_nil)
#define TTree_Root(self) ((self)->fRoot)
#define TTree_Items(self) (TVarBag_Items(&(self)->fBase))
#ifdef SLIM_CONFIG_DEBUG
#else
#define TTree_Parent(self, pix)	(TVarBag_PeekPix(&(self)->fBase,(pix),SLIM_OFFSETOF(TTreeItemHolder, fParent)))
#define TTree_FirstChild(self, pix)	(TVarBag_PeekPix(&(self)->fBase,(pix),SLIM_OFFSETOF(TTreeItemHolder, fFirstChild)))
#define TTree_Next(self, pix)	(TVarBag_PeekPix(&(self)->fBase,(pix),SLIM_OFFSETOF(TTreeItemHolder, fNext)))
#endif
#define TTree_LockItem(self,pix) (TVarBag_LockItem(&(self)->fBase,(pix)))
#define TTree_UnlockItem(self,pix) (TVarBag_UnlockItem(&(self)->fBase,(pix)))
#define TTree_LocateItem(self,pix) (TVarBag_LocateItem(&(self)->fBase,(pix)))
#define TTree_UnlocateItem(self,pix) (TVarBag_UnlocateItem(&(self)->fBase,(pix)))
#define TTree_ChainChildFirst(self,parent,pix) (TTree_ChainChildAfter((self),(parent),slim_pix_nil,(pix)))
#define TTree_ChainChildLast(self,parent,pix) (TTree_ChainChildBefore((self),(parent),slim_pix_nil,(pix)))
#define TTree_IsChild(self,pix1,pix2) (TTree_Parent((self),(pix1))==(pix2))
#define TTree_IsParent(self,pix1,pix2) (TTree_Parent((self),(pix2))==(pix1))
#define TTree_IsAncestor(self,pix1,pix2) (TTree_IsDescendant((self),(pix2),(pix1)))
#define TTree_GetItem(self,pix,buf,sz) (TVarBag_GetItem(&(self)->fBase,(pix),(buf),(sz)))
#define TTree_SetItem(self,pix,buf,sz) (TVarBag_SetItem(&(self)->fBase,(pix),(buf),(sz)))


/* -sizeof(slim_short) is for holder size of TVarBag */
#define TTreeItem_ItemHolder(self) ((TTreeItemHolder*)(((slim_byte*)self)-SLIM_COLL_ROUNDUP(SLIM_COLL_ROUNDUP(sizeof(TTreeItemHolder))+SLIM_VARBAG_SIZE_OF_HOLDERSIZE)))
#define TTreeItem_Parent(self) (TTreeItem_ItemHolder(self)->fParent)
#define TTreeItem_FirstChild(self) (TTreeItem_ItemHolder(self)->fFirstChild)
#define TTreeItem_Next(self) (TTreeItem_ItemHolder(self)->fNext)
/* fast TTreeItem_Prev(self) is not easy to implement */

#define TTree_ForeachN(s, p, c, a, o) TTree_Foreach((s), SLIM_TREE_FOREACH_TYPE_NOLOCK, (p), (c), (a), (o))
#define TTree_Foreach1(s, p, c, a, o) TTree_Foreach((s), SLIM_TREE_FOREACH_TYPE_CHILDREN1, (p), (c), (a), (o))
#define TTree_Foreach2(s, p, c, a, o) TTree_Foreach((s), SLIM_TREE_FOREACH_TYPE_CHILDREN2, (p), (c), (a), (o))
#define TTree_ForeachA(s, p, c, a, o) TTree_Foreach((s), SLIM_TREE_FOREACH_TYPE_ANCESTOR, (p), (c), (a), (o))


#ifdef SLIM_CONFIG_DEBUG
#define TTree_DebugOutStatistics(self,newline)	\
	(TVarBag_DebugOutStatisticsX(&(self)->fBase,(newline),sizeof(TTreeItemHolder)))
#endif

#define TTree_VerifyPix(self,pix) (TVarBag_VerifyPix(&(self)->fBase,(pix)))
#define TTree_VerifyPixOrNil(self,pix) (TVarBag_VerifyPixOrNil(&(self)->fBase,(pix)))




#ifdef SLIM_CONFIG_POINTER_MEMNODE
/*---------temporary-------- */
#define SLIM_COLL_FROM_PTRTREE SLIM_COLL_FROM_TREE

/*---------end temporary---- */

/*                     */
/* variable length bag */
/*                     */

#define SLIM_PTRVARBAG_VALID_PIX_SIZE(holderSize) ((holderSize) >= 0)
#define SLIM_PTRVARBAG_VALID_PIX_OFFS(positionOff) ((positionOff) >= 0)

#define TPtrVarBag_Locate(self,pix) 		((void *)((slim_byte *)(pix) - (self)->fHeaderSize))
#define TPtrVarBag_Unlocate(self,pix)		((void)0)
#define TPtrVarBag_LockItem(self,pix)		((void *)(pix))
#define TPtrVarBag_UnlockItem(self,pix) 	((void)0)
#define TPtrVarBag_LocateItem(self,pix) 	((void *)(pix))
#define TPtrVarBag_UnlocateItem(self,pix) 	((void)0)
#define TPtrVarBag_PeekPix(self,pix,off) 	(*((slim_pix    *)((slim_byte *)(pix) - (self)->fHeaderSize + (off))))
#define TPtrVarBag_PeekHandle(self,pix,off) (*((slim_handle *)((slim_byte *)(pix) - (self)->fHeaderSize + (off))))

#define TPtrVarBag_GetItem(self,pix,buf,sz) (TPtrVarBag_CopyOut((self),(pix),0,(sz),(buf)))
#define TPtrVarBag_SetItem(self,pix,buf,sz) (TPtrVarBag_CopyIn((self),(pix),0,(sz),(buf)))
#define TPtrVarBag_Items(self) ((self)->fItems)

#ifdef SLIM_CONFIG_DEBUG
#define TPtrVarBag_DebugOutStatistics(self,newline)	\
	(TPtrVarBag_DebugOutStatisticsX((self),(newline),0))
#endif

void TPtrVarBag_VerifyPix(TPtrVarBag *self, slim_pix in_pix);
void TPtrVarBag_VerifyPixOrNil(TPtrVarBag *self, slim_pix in_pix);

/*
 * At the tail of header, we reserve an area for a size of holder (slim_short).
 * 
 * holder             pix of the item  (real pointer)
 * |                  |
 * v                  v
 *  <--(1)-> <--(2)--> <---------(3)----------->
 * +--------+---------+-------------------------+
 * |        |   (X)   |                         |
 * +--------+---------+-------------------------+
 *  <-------------------(X)--------------------->
 *  <------(Y)------->
 *
 * (1) in_header_sz (header used by subclass of TPtrVarBag)
 * (2) sizeof(slim_short)
 * (3) item itself
 *
 * (X) = holder size (may differ for holder by holder)
 * (Y) = fHeaderSize
 */
#define SLIM_PTRVARBAG_SIZE_OF_HOLDERSIZE SLIM_VARBAG_SIZE_OF_HOLDERSIZE
#define TPtrVarBag_HolderSizeByPix(self, in_pix) (*(((slim_short *)(in_pix)) - 1))
#define TPtrVarBag_SetHolderSizeByPix(self, in_pix, in_holder_size) (*(((slim_short *)(in_pix)) - 1) = (in_holder_size))
#define TPtrVarBag_PixByHolder(self, in_holder) ((slim_pix)((slim_byte *)(in_holder) + (self)->fHeaderSize))

/*                 */
/* tree collection */
/*                 */

/* treetpl.txt */
slim_bool TPtrTree_Foreach (TPtrTree *self, slim_int in_type, slim_pix in_start_pix, Tree_ForeachProc in_proc, slim_opaque in_arg, slim_pix *out_pix);
slim_int TPtrTree_NodeCmp (TPtrTree *self, slim_pix in_pix1, slim_int in_pix1_dir, slim_pix in_pix2, slim_int in_pix2_dir);

#define TPtrTreeVisit_CurrentPix(visit) ((visit)->fIndex)

#define TPtrTree_Finalize(self) (TPtrVarBag_Finalize(&(self)->fBase))
#define TPtrTree_IsEmpty(self) ((self)->fRoot == slim_pix_nil)
#define TPtrTree_Root(self) ((self)->fRoot)
#define TPtrTree_Items(self) (TPtrVarBag_Items(&(self)->fBase))
#ifdef SLIM_CONFIG_DEBUG
#else
#define TPtrTree_Parent(self, pix)	(TPtrVarBag_PeekPix(&(self)->fBase,(pix),SLIM_OFFSETOF(TPtrTreeItemHolder, fParent)))
#define TPtrTree_FirstChild(self, pix)	(TPtrVarBag_PeekPix(&(self)->fBase,(pix),SLIM_OFFSETOF(TPtrTreeItemHolder, fFirstChild)))
#define TPtrTree_Next(self, pix)	(TPtrVarBag_PeekPix(&(self)->fBase,(pix),SLIM_OFFSETOF(TPtrTreeItemHolder, fNext)))
#endif
#define TPtrTree_LockItem(self,pix) (TPtrVarBag_LockItem(&(self)->fBase,(pix)))
#define TPtrTree_UnlockItem(self,pix) (TPtrVarBag_UnlockItem(&(self)->fBase,(pix)))
#define TPtrTree_LocateItem(self,pix) (TPtrVarBag_LocateItem(&(self)->fBase,(pix)))
#define TPtrTree_UnlocateItem(self,pix) (TPtrVarBag_UnlocateItem(&(self)->fBase,(pix)))
#define TPtrTree_ChainChildFirst(self,parent,pix) (TPtrTree_ChainChildAfter((self),(parent),slim_pix_nil,(pix)))
#define TPtrTree_ChainChildLast(self,parent,pix) (TPtrTree_ChainChildBefore((self),(parent),slim_pix_nil,(pix)))
#define TPtrTree_IsChild(self,pix1,pix2) (TPtrTree_Parent((self),(pix1))==(pix2))
#define TPtrTree_IsParent(self,pix1,pix2) (TPtrTree_Parent((self),(pix2))==(pix1))
#define TPtrTree_IsAncestor(self,pix1,pix2) (TPtrTree_IsDescendant((self),(pix2),(pix1)))
#define TPtrTree_GetItem(self,pix,buf,sz) (TPtrVarBag_GetItem(&(self)->fBase,(pix),(buf),(sz)))
#define TPtrTree_SetItem(self,pix,buf,sz) (TPtrVarBag_SetItem(&(self)->fBase,(pix),(buf),(sz)))

#define SLIM_PTRTREE_FOREACH_TYPE_NOLOCK SLIM_TREE_FOREACH_TYPE_NOLOCK
#define SLIM_PTRTREE_FOREACH_TYPE_CHILDREN1 SLIM_TREE_FOREACH_TYPE_CHILDREN1
#define SLIM_PTRTREE_FOREACH_TYPE_CHILDREN2 SLIM_TREE_FOREACH_TYPE_CHILDREN2
#define SLIM_PTRTREE_FOREACH_TYPE_ANCESTOR SLIM_TREE_FOREACH_TYPE_ANCESTOR
#define SLIM_PTRTREE_FOREACH_CONTINUE SLIM_TREE_FOREACH_CONTINUE
#define SLIM_PTRTREE_FOREACH_BREAK SLIM_TREE_FOREACH_BREAK
#define SLIM_PTRTREE_FOREACH_SKIP SLIM_TREE_FOREACH_SKIP

typedef slim_int (*PtrTree_ForeachProc)(slim_pix in_pix, slim_int in_dir, void *in_item, slim_opaque in_arg);

#define TPtrTree_ForeachN(s, p, c, a, o) TPtrTree_Foreach((s), SLIM_PTRTREE_FOREACH_TYPE_NOLOCK, (p), (c), (a), (o))
#define TPtrTree_Foreach1(s, p, c, a, o) TPtrTree_Foreach((s), SLIM_PTRTREE_FOREACH_TYPE_CHILDREN1, (p), (c), (a), (o))
#define TPtrTree_Foreach2(s, p, c, a, o) TPtrTree_Foreach((s), SLIM_PTRTREE_FOREACH_TYPE_CHILDREN2, (p), (c), (a), (o))
#define TPtrTree_ForeachA(s, p, c, a, o) TPtrTree_Foreach((s), SLIM_PTRTREE_FOREACH_TYPE_ANCESTOR, (p), (c), (a), (o))


#ifdef SLIM_CONFIG_DEBUG
#define TPtrTree_DebugOutStatistics(self,newline)	\
	(TPtrVarBag_DebugOutStatisticsX(&(self)->fBase,(newline),sizeof(TPtrTreeItemHolder)))
#endif

#define TPtrTree_VerifyPix(self,pix) (TPtrVarBag_VerifyPix(&(self)->fBase,(pix)))
#define TPtrTree_VerifyPixOrNil(self,pix) (TPtrVarBag_VerifyPixOrNil(&(self)->fBase,(pix)))



#endif /* SLIM_CONFIG_POINTER_MEMNODE */

SLIM_END_C_LINKAGE
#endif
