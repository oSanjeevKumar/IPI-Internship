/*
	arena.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/arena.h 16    05/12/28 12:08 Someya $ */

#ifndef SLIM_ARENA_H_PRIVATE
#define SLIM_ARENA_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#define TDataArena_TreeInitialize(self) (TTree_Initialize(&(self)->fArenaTree))
#define TDataArena_TreeFinalize(self) (TTree_Finalize(&(self)->fArenaTree))
#define TDataArena_MakeEmpty(self) (TTree_MakeEmpty(&(self)->fArenaTree))
#define TDataArena_Root(self) (TTree_Root(&(self)->fArenaTree))
#define TDataArena_SetRoot(self,pix) (TTree_SetRoot(&(self)->fArenaTree,(pix)))
#define TDataArena_ParentItem(self,pix) (TTree_Parent(&(self)->fArenaTree,(pix)))
#define TDataArena_FirstChild(self,pix) (TTree_FirstChild(&(self)->fArenaTree,(pix)))
#define TDataArena_LastChild(self,pix) (TTree_LastChild(&(self)->fArenaTree,(pix)))
#define TDataArena_NextItem(self,pix) (TTree_Next(&(self)->fArenaTree,(pix)))
#define TDataArena_PrevItem(self,pix) (TTree_Prev(&(self)->fArenaTree,(pix)))
#define TDataArena_NewItem(self,size) (TTree_ZeroNewItem(&(self)->fArenaTree,(size)))
#define TDataArena_ZeroNewItem(self,size) (TTree_ZeroNewItem(&(self)->fArenaTree,(size)))
#define TDataArena_RemoveItem(self,pix) (TTree_Remove(&(self)->fArenaTree,(pix)))
#define TDataArena_LockItem(self,pix) (TTree_LockItem(&(self)->fArenaTree,(pix)))
#define TDataArena_UnlockItem(self,pix) (TTree_UnlockItem(&(self)->fArenaTree,(pix)))
#define TDataArena_LocateItem(self,pix) (TTree_LocateItem(&(self)->fArenaTree,(pix)))
#define TDataArena_UnlocateItem(self,pix) (TTree_UnlocateItem(&(self)->fArenaTree,(pix)))
#define TDataArena_ChainChildFirst(self,parent,pix) (TTree_ChainChildFirst(&(self)->fArenaTree,(parent),(pix)))
#define TDataArena_ChainChildLast(self,parent,pix) (TTree_ChainChildLast(&(self)->fArenaTree,(parent),(pix)))
#define TDataArena_ChainChildAfter(self,parent,after,pix) (TTree_ChainChildAfter(&(self)->fArenaTree,(parent),(after),(pix)))
#define TDataArena_ChainChildBefore(self,parent,before,pix) (TTree_ChainChildBefore(&(self)->fArenaTree,(parent),(before),(pix)))
#define TDataArena_UnchainItem(self,pix) (TTree_Unchain(&(self)->fArenaTree,(pix)))
#define TDataArena_GetItem(self,pix,buf,sz) (TTree_GetItem(&(self)->fArenaTree,(pix),(buf),(sz)))
#define TDataArena_SetItem(self,pix,buf,sz) (TTree_SetItem(&(self)->fArenaTree,(pix),(buf),(sz)))

#define TDataArena_Initialize(self) (TDataArena_TreeInitialize((self)))
#define TDataArena_Finalize(self) (TDataArena_TreeFinalize((self)))

#define TDataArena_BeginVisit(self, pix, visit) TTree_BeginVisit(&(self)->fArenaTree, (pix), (visit))
#define TDataArena_EndVisit(self, visit) TTree_EndVisit(&(self)->fArenaTree, (visit))
#define TDataArena_VisitFirstChild(self, visit) TTree_VisitFirstChild(&(self)->fArenaTree, (visit))
#define TDataArena_VisitLastChild(self, visit) TTree_VisitLastChild(&(self)->fArenaTree, (visit))
#define TDataArena_VisitAt(self, pix, visit) TTree_VisitAt(&(self)->fArenaTree, (pix), (visit))
#define TDataArena_VisitNext(self, visit) TTree_VisitNext(&(self)->fArenaTree, (visit))
#define TDataArena_VisitPrev(self, visit) TTree_VisitPrev(&(self)->fArenaTree, (visit))

SLIM_END_C_LINKAGE
#endif /* SLIM_ARENA_H_PRIVATE */
