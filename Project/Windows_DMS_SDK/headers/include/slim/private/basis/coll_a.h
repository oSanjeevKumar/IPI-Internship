/*
	coll_a.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/coll_a.h 39    05/12/28 12:08 Someya $ */

#ifndef SLIM_COLL_A_H_PRIVATE
#define SLIM_COLL_A_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/* utility macro */

#define SLIM_COLL_ROUNDUP(s) SLIM_ROUNDUP_P2(s, SLIM_CONFIG_CC_STRUCTALIGN)

/*                */
/* bag collection */
/*                */
#ifdef SLIM_CONFIG_DEBUG
#else /* SLIM_CONFIG_DEBUG */
#define TBag_Locate(self,pix) ((TBagItemHolder *)TMemNode_Locate(&(self)->fBase, (slim_iaddr_word)(pix)))
#define TBag_Unlocate(self,pix) (TMemNode_Unlocate(&(self)->fBase, (slim_iaddr_word)(pix)))
#endif /* SLIM_CONFIG_DEBUG */
#define TBag_IsEmpty(self) ((self)->fItems == 0)
#define TBag_Items(self) ((self)->fItems)
#define TBag_Remove(self,pix) (TBag_FreeHolder((self),(pix)))
#ifdef SLIM_CONFIG_DEBUG
#else /* SLIM_CONFIG_DEBUG */
#define TBag_LockItem(self,pix)	\
		((void *)((slim_byte *)TMemNode_Lock(&(self)->fBase,(slim_uiaddr_word)(pix),slim_nil) + (self)->fHeaderSize))
#define TBag_UnlockItem(self,pix) (TMemNode_Unlock(&(self)->fBase, (slim_iaddr_word)(pix)))
#endif /* SLIM_CONFIG_DEBUG */
#define TBag_LocateItem(self,pix) ((void *)((slim_byte *)TBag_Locate((self),(pix)) + (self)->fHeaderSize))
#define TBag_UnlocateItem(self,pix) (TBag_Unlocate((self),(pix)))
#define TBag_PeekPix(self,pix,off) (TMemNode_PeekPix(&(self)->fBase,(slim_iaddr_word)(pix)+(off)))
#define TBag_PeekHandle(self,pix,off) (TMemNode_PeekHandle(&(self)->fBase,(slim_iaddr_word)(pix)+(off)))

/*                 */
/* list collection */
/*                 */

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
#define TListVisit_CurrentHolder(visit) ((TListItemHolder*)((visit)->fIndex))

#define TList_EndVisit(self,visit) ((void)0)
#define TList_VisitAt(self,pix,visit) (!(pix) ? slim_nil : (void*)((slim_byte*)((visit)->fIndex=(pix))+(self)->fBase.fHeaderSize))

/*                  */
/* array collection */
/*                  */

/* generic array */
#define TArray_MakeEmpty(self) {TMemNode_FreeAll(&(self)->fBase);(self)->fItems=0;}
#define TArray_IsEmpty(self) ((self)->fItems == 0)
#define TArray_Length(self) ((self)->fItems)
#define TArray_RemoveLast(self) (TArray_FreeItem((self)))
#define TArray_LockItem(self,index) (TArray_CalcAddr((self),(index)))
#define TArray_UnlockItem(self,index) (0)
#define TArray_LocateItem(self,index) (TArray_CalcAddr((self),(index)))
#define TArray_UnlocateItem(self,index) (void)(0)
#define TArray_EndVisit(self,visit) ((void)0)
#define TArray_VisitAt(self,index,visit) (TArray_CalcAddr((self),(visit)->fIndex=(index)))

/* generic fast array */
#define TFastArray_CalcOffset(self,index) ((slim_int)((index)<<(self)->fSizeLog))
#define TFastArray_MakeEmpty(self) {TMemNode_FreeAll(&(self)->fBase);(self)->fItems=0;}
#define TFastArray_IsEmpty(self) ((self)->fItems == 0)
#define TFastArray_Length(self) ((self)->fItems)
#define TFastArray_RemoveLast(self) (TFastArray_FreeItem((self)))
#define TFastArray_LockItem(self,index) (TFastArray_CalcAddr((self),(index)))
#define TFastArray_UnlockItem(self,index) ((void)0)
#define TFastArray_LocateItem(self,index) (TFastArray_CalcAddr((self),(index)))
#define TFastArray_UnlocateItem(self,index) ((void)0)
#define TFastArray_EndVisit(self,visit) ((void)0)
#define TFastArray_VisitAt(self,index,visit) (TFastArray_CalcAddr((self),(visit)->fIndex=(index)))

/*                     */
/* variable length bag */
/*                     */

/* A pseudo-index of a TVarBag consists of two bit fields.
 * The lower bit field (10 bits = max 1024 bytes) indicates holder-size.
 * The higher bit field (22 bits = max 4MB) indicates position-offset which is used for the offset of a TMemNode.
 */
/* Constants for storing holder-size and position-offset into pseudo-index */
enum {
	SLIM_VARBAG_SIZE_BITS = SLIM_MEMORY_BLOG - SLIM_CONFIG_CC_STRUCTALIGN_LOG,
	SLIM_VARBAG_OFFS_BITS = 32 - SLIM_VARBAG_SIZE_BITS
};
enum {
	SLIM_VARBAG_SIZE_MASK = (1 << SLIM_VARBAG_SIZE_BITS) - 1,
	SLIM_VARBAG_OFFS_MASK = (1 << SLIM_VARBAG_OFFS_BITS) - 1
};

#define SLIM_VARBAG_PIX_SIZE(pix) (((TVarBagItemHolder*)(pix))->fHolderSize)
#define SLIM_VARBAG_PIX_OFFS(pix) ((slim_iaddr_word)(pix))

#ifdef SLIM_CONFIG_DEBUG
#else
#define TVarBag_Locate(self,pix) (TMemNode_Locate(&(self)->fBase,SLIM_VARBAG_PIX_OFFS((pix))))
#define TVarBag_Unlocate(self,pix) (TMemNode_Unlocate(&(self)->fBase,SLIM_VARBAG_PIX_OFFS((pix))))
#endif
#define TVarBag_GetItem(self,pix,buf,sz) (TVarBag_CopyOut((self),(pix),0,(sz),(buf)))
#define TVarBag_SetItem(self,pix,buf,sz) (TVarBag_CopyIn((self),(pix),0,(sz),(buf)))
#define TVarBag_Items(self) ((self)->fItems)
#ifdef SLIM_CONFIG_DEBUG
#else
#define TVarBag_LockItem(self,pix)	\
		((void *)((slim_byte *)TMemNode_Lock(&(self)->fBase,SLIM_VARBAG_PIX_OFFS((pix)),slim_nil) + (self)->fHeaderSize))
#define TVarBag_UnlockItem(self,pix) (TMemNode_Unlock(&(self)->fBase,SLIM_VARBAG_PIX_OFFS((pix))))
#endif
#define TVarBag_LocateItem(self,pix) ((void *)((slim_byte *)TVarBag_Locate((self),(pix)) + (self)->fHeaderSize))
#define TVarBag_UnlocateItem(self,pix) (TVarBag_Unlocate((self),(pix)))

#ifdef SLIM_CONFIG_DEBUG
#define TVarBag_DebugOutStatistics(self,newline)	\
	(TVarBag_DebugOutStatisticsX((self),(newline),sizeof(TVarBagItemHolder)))
#endif

#define TVarBag_VerifyPix(self, pix) (TMemNode_VerifyPix(&(self)->fBase,SLIM_VARBAG_PIX_OFFS((pix))))
#define TVarBag_VerifyPixOrNil(self, pix) (TMemNode_VerifyPixOrNil(&(self)->fBase,SLIM_VARBAG_PIX_OFFS((pix))))

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

#define TTreeItem_ItemHolder(self) ((TTreeItemHolder*)(((slim_byte*)self)-SLIM_COLL_ROUNDUP(sizeof(TTreeItemHolder))))
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

#define TTree_VerifyPix(self, pix) (TVarBag_VerifyPix(&(self)->fBase,(pix)))
#define TTree_VerifyPixOrNil(self, pix) (TVarBag_VerifyPixOrNil(&(self)->fBase,(pix)))

#define TTree_EndVisit(self,visit) ((void)0)
#define TTree_VisitAt(self,pix,visit) ((void*)((slim_byte *)((visit)->fIndex = (pix))+(self)->fBase.fHeaderSize))



SLIM_END_C_LINKAGE

#endif
