/*
	coll.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/basis/coll.h 154   05/12/28 12:08 Someya $ */

#ifndef SLIM_COLL_H_PRIVATE
#define SLIM_COLL_H_PRIVATE

#ifdef SLIM_CONFIG_MEMORY_ALTERNATIVE
#include <slim/private/basis/coll_a.h>
#else
#include <slim/private/basis/coll_s.h>
#endif

SLIM_BEGIN_C_LINKAGE

/*
 * ObjectIterator
 */
#ifndef SLIM_CONFIG_DEBUG
#define TObjectIterator_Initialize(self) ((void)0)
#endif

/* hash table (generic) */

/* list collection */

/* spec list */
#define TSpecList_Finalize(self) (TList_Finalize(&(self)->fBase))
#define TSpecList_MakeEmpty(self) {TList_MakeEmpty(&(self)->fBase);}
#define TSpecList_IsEmpty(self) (TList_IsEmpty(&(self)->fBase))
#define TSpecList_Length(self) (TList_Length(&(self)->fBase))
#define TSpecList_Items(self) (TList_Items(&(self)->fBase))
#define TSpecList_First(self) (TList_First(&(self)->fBase))
#define TSpecList_Last(self) (TList_Last(&(self)->fBase))
#define TSpecList_Next(self,pix) (TList_Next(&(self)->fBase,(pix)))
#define TSpecList_Prev(self,pix) (TList_Prev(&(self)->fBase,(pix)))
#define TSpecList_Nth(self,n) (TList_Nth(&(self)->fBase,(n)))
#define TSpecList_Order(self,pix) (TList_Order(&(self)->fBase,(pix)))
#define TSpecList_GetItem(self,pix,p) (TBag_GetSpec(&(self)->fBase.fBase,(pix),(p)))
#define TSpecList_SetItem(self,pix,p) (TBag_SetSpec(&(self)->fBase.fBase,(pix),(p)))
#define TSpecList_LockItem(self,pix) (TBag_LockItem(&(self)->fBase.fBase,(pix)))
#define TSpecList_UnlockItem(self,pix) (TBag_UnlockItem(&(self)->fBase.fBase,(pix)))
#define TSpecList_LocateItem(self,pix) (TBag_LocateItem(&(self)->fBase.fBase,(pix)))
#define TSpecList_UnlocateItem(self,pix) (TBag_UnlocateItem(&(self)->fBase.fBase,(pix)))
#define TSpecList_Prepend(self,item) (TSpecList_InsertAfter((self),slim_pix_nil,(item)))
#define TSpecList_Append(self,item) (TSpecList_InsertBefore((self),slim_pix_nil,(item)))
#define TSpecList_ChainAfter(self,after,pix) (TList_ChainAfter(&(self)->fBase,(after),(pix)))
#define TSpecList_ChainFirst(self,pix) (TSpecList_ChainAfter((self),slim_pix_nil,(pix)))
#define TSpecList_ChainBefore(self,before,pix) (TList_ChainBefore(&(self)->fBase,(before),(pix)))
#define TSpecList_ChainLast(self,pix) (TSpecList_ChainBefore((self),slim_pix_nil,(pix)))
#define TSpecList_Unchain(self,pix) (TList_Unchain(&(self)->fBase,(pix)))
#define TSpecList_IsChained(self,pix) (TList_IsChained(&(self)->fBase,(pix)))
#define TSpecList_Remove(self,pix) (TList_Remove(&(self)->fBase,(pix)))

#define TSpecList_BeginVisit(self,pix,visit)	(TList_BeginVisit(&(self)->fBase,(pix),(visit)))
#define TSpecList_EndVisit(self,visit) (TList_EndVisit(&(self)->fBase,(visit)))
#define TSpecList_VisitAt(self,pix,visit) (TList_VisitAt(&(self)->fBase,(pix),(visit)))
#define TSpecList_VisitFirst(self,visit) (TList_VisitFirst(&(self)->fBase,(visit)))
#define TSpecList_VisitLast(self,visit) (TList_VisitLast(&(self)->fBase,(visit)))
#define TSpecList_VisitNext(self,visit) (TList_VisitNext(&(self)->fBase,(visit)))
#define TSpecList_VisitPrev(self,visit) (TList_VisitPrev(&(self)->fBase,(visit)))

/* opaque list */

#define TOpaqueList_Finalize(self) (TList_Finalize(&(self)->fBase))
#define TOpaqueList_MakeEmpty(self) {TList_MakeEmpty(&(self)->fBase);}
#define TOpaqueList_IsEmpty(self) (TList_IsEmpty(&(self)->fBase))
#define TOpaqueList_Length(self) (TList_Length(&(self)->fBase))
#define TOpaqueList_Items(self) (TList_Items(&(self)->fBase))
#define TOpaqueList_First(self) (TList_First(&(self)->fBase))
#define TOpaqueList_Last(self) (TList_Last(&(self)->fBase))
#define TOpaqueList_Next(self,pix) (TList_Next(&(self)->fBase,(pix)))
#define TOpaqueList_Prev(self,pix) (TList_Prev(&(self)->fBase,(pix)))
#define TOpaqueList_Nth(self,n) (TList_Nth(&(self)->fBase,(n)))
#define TOpaqueList_Order(self,pix) (TList_Order(&(self)->fBase,(pix)))
#define TOpaqueList_GetItem(self,pix) (TBag_GetOpaque(&(self)->fBase.fBase,(pix)))
#define TOpaqueList_SetItem(self,pix,item) (TBag_SetOpaque(&(self)->fBase.fBase,(pix),(item)))
#define TOpaqueList_Prepend(self,item) (TOpaqueList_InsertBefore((self),slim_pix_nil,(item)))
#define TOpaqueList_Append(self,item) (TOpaqueList_InsertAfter((self),slim_pix_nil,(item)))
#define TOpaqueList_ChainAfter(self,after,pix) (TList_ChainAfter(&(self)->fBase,(after),(pix)))
#define TOpaqueList_ChainFirst(self,pix) (TOpaqueList_ChainAfter((self),slim_pix_nil,(pix)))
#define TOpaqueList_ChainBefore(self,before,pix) (TList_ChainBefore(&(self)->fBase,(before),(pix)))
#define TOpaqueList_ChainLast(self,pix) (TOpaqueList_ChainBefore((self),slim_pix_nil,(pix)))
#define TOpaqueList_Unchain(self,pix) (TList_Unchain(&(self)->fBase,(pix)))
#define TOpaqueList_IsChained(self,pix) (TList_IsChained(&(self)->fBase,(pix)))
#define TOpaqueList_Remove(self,pix) (TList_Remove(&(self)->fBase,(pix)))

#define TOpaqueList_BeginVisit(self,pix,visit) (TList_BeginVisit(&(self)->fBase,(pix),(visit)))
#define TOpaqueList_EndVisit(self,visit) (TList_EndVisit(&(self)->fBase,(visit)))
#define TOpaqueList_VisitAt(self,pix,visit) ((slim_opaque*)TList_VisitAt(&(self)->fBase,(pix),(visit)))
#define TOpaqueList_VisitFirst(self,visit) ((slim_opaque*)TList_VisitFirst(&(self)->fBase,(visit)))
#define TOpaqueList_VisitLast(self,visit) ((slim_opaque*)TList_VisitLast(&(self)->fBase,(visit)))
#define TOpaqueList_VisitNext(self,visit) ((slim_opaque*)TList_VisitNext(&(self)->fBase,(visit)))
#define TOpaqueList_VisitPrev(self,visit) ((slim_opaque*)TList_VisitPrev(&(self)->fBase,(visit)))

/* opaque list variants */

#define TObjectList_Initialize(self) (TOpaqueList_Initialize((self)))
#define TObjectList_Finalize(self) (TOpaqueList_Finalize((self)))
#define TObjectList_MakeEmpty(self) {TOpaqueList_MakeEmpty((self));}
#define TObjectList_IsEmpty(self) (TOpaqueList_IsEmpty((self)))
#define TObjectList_Length(self) (TOpaqueList_Length((self)))
#define TObjectList_Items(self) (TOpaqueList_Items((self)))
#define TObjectList_First(self) (TOpaqueList_First((self)))
#define TObjectList_Last(self) (TOpaqueList_Last((self)))
#define TObjectList_Next(self,pix) (TOpaqueList_Next((self),(pix)))
#define TObjectList_Prev(self,pix) (TOpaqueList_Prev((self),(pix)))
#define TObjectList_Nth(self,n) (TOpaqueList_Nth((self),(n)))
#define TObjectList_Order(self,pix) (TOpaqueList_Order((self),(pix)))
#define TObjectList_GetItem(self,pix) ((slim_object)TOpaqueList_GetItem((self),(pix)))
#define TObjectList_SetItem(self,pix,item) (TOpaqueList_SetItem((self),(pix),(slim_opaque)(item))
#define TObjectList_InsertAfter(self,pix,item) (TOpaqueList_InsertAfter((self),(pix),(slim_opaque)(item)))
#define TObjectList_Prepend(self,item) (TOpaqueList_Prepend((self),(slim_opaque)(item)))
#define TObjectList_InsertBefore(self,pix,item) (TOpaqueList_InsertBefore((self),(pix),(slim_opaque)(item)))
#define TObjectList_Append(self,item) (TOpaqueList_Append((self),(slim_opaque)(item)))
#define TObjectList_ChainAfter(self,after,pix) (TOpaqueList_ChainAfter((self),(after),(pix)))
#define TObjectList_ChainFirst(self,pix) (TOpaqueList_ChainFirst((self),(pix)))
#define TObjectList_ChainBefore(self,before,pix) (TOpaqueList_ChainBefore((self),(before),(pix)))
#define TObjectList_ChainLast(self,pix) (TOpaqueList_ChainLast((self),(pix)))
#define TObjectList_Unchain(self,pix) (TOpaqueList_Unchain((self),(pix)))
#define TObjectList_IsChained(self,pix) (TOpaqueList_IsChained((self),(pix)))
#define TObjectList_Remove(self,pix) (TOpaqueList_Remove((self),(pix)))

#define TObjectList_BeginVisit(self,pix,visit) (TOpaqueList_BeginVisit((self),(pix),(visit)))
#define TObjectList_EndVisit(self,visit) (TOpaqueList_EndVisit((self),(visit)))
#define TObjectList_VisitAt(self,pix,visit)	((slim_object*)TOpaqueList_VisitAt((self),(pix),(visit)))
#define TObjectList_VisitFirst(self,visit) ((slim_object*)TOpaqueList_VisitFirst((self),(visit)))
#define TObjectList_VisitLast(self,visit) ((slim_object*)TOpaqueList_VisitLast((self),(visit)))
#define TObjectList_VisitNext(self,visit) ((slim_object*)TOpaqueList_VisitNext((self),(visit)))
#define TObjectList_VisitPrev(self,visit) ((slim_object*)TOpaqueList_VisitPrev((self),(visit)))

#define TIntList_Initialize(self) (TOpaqueList_Initialize((self)))
#define TIntList_Finalize(self) (TOpaqueList_Finalize((self)))
#define TIntList_MakeEmpty(self) {TOpaqueList_MakeEmpty((self));}
#define TIntList_IsEmpty(self) (TOpaqueList_IsEmpty((self)))
#define TIntList_Length(self) (TOpaqueList_Length((self)))
#define TIntList_Items(self) (TOpaqueList_Items((self)))
#define TIntList_First(self) (TOpaqueList_First((self)))
#define TIntList_Last(self) (TOpaqueList_Last((self)))
#define TIntList_Next(self,pix) (TOpaqueList_Next((self),(pix)))
#define TIntList_Prev(self,pix) (TOpaqueList_Prev((self),(pix)))
#define TIntList_Nth(self,n) (TOpaqueList_Nth((self),(n)))
#define TIntList_Order(self,pix) (TOpaqueList_Order((self),(pix)))
#define TIntList_GetItem(self,pix) ((slim_int)TOpaqueList_GetItem((self),(pix)))
#define TIntList_SetItem(self,pix,item) (TOpaqueList_SetItem((self),(pix),(slim_opaque)(item))
#define TIntList_InsertAfter(self,pix,item) (TOpaqueList_InsertAfter((self),(pix),(slim_opaque)(item)))
#define TIntList_Prepend(self,item) (TOpaqueList_Prepend((self),(slim_opaque)(item)))
#define TIntList_InsertBefore(self,pix,item) (TOpaqueList_InsertBefore((self),(pix),(slim_opaque)(item)))
#define TIntList_Append(self,item) (TOpaqueList_Append((self),(slim_opaque)(item)))
#define TIntList_ChainAfter(self,after,pix) (TOpaqueList_ChainAfter((self),(after),(pix)))
#define TIntList_ChainFirst(self,pix) (TOpaqueList_ChainFirst((self),(pix)))
#define TIntList_ChainBefore(self,before,pix) (TOpaqueList_ChainBefore((self),(before),(pix)))
#define TIntList_ChainLast(self,pix) (TOpaqueList_ChainLast((self),(pix)))
#define TIntList_Unchain(self,pix) (TOpaqueList_Unchain((self),(pix)))
#define TIntList_IsChained(self,pix) (TOpaqueList_IsChained((self),(pix)))
#define TIntList_Remove(self,pix) (TOpaqueList_Remove((self),(pix)))

#define TIntList_BeginVisit(self,pix,visit) (TOpaqueList_BeginVisit((self),(pix),(visit)))
#define TIntList_EndVisit(self,visit) (TOpaqueList_EndVisit((self),(visit)))
#define TIntList_VisitAt(self,pix,visit)	((slim_int*)TOpaqueList_VisitAt((self),(pix),(visit)))
#define TIntList_VisitFirst(self,visit) ((slim_int*)TOpaqueList_VisitFirst((self),(visit)))
#define TIntList_VisitLast(self,visit) ((slim_int*)TOpaqueList_VisitLast((self),(visit)))
#define TIntList_VisitNext(self,visit) ((slim_int*)TOpaqueList_VisitNext((self),(visit)))
#define TIntList_VisitPrev(self,visit) ((slim_int*)TOpaqueList_VisitPrev((self),(visit)))

#define TPtrList_Initialize(self) (TOpaqueList_Initialize((self)))
#define TPtrList_Finalize(self) (TOpaqueList_Finalize((self)))
#define TPtrList_MakeEmpty(self) {TOpaqueList_MakeEmpty((self));}
#define TPtrList_IsEmpty(self) (TOpaqueList_IsEmpty((self)))
#define TPtrList_Length(self) (TOpaqueList_Length((self)))
#define TPtrList_Items(self) (TOpaqueList_Items((self)))
#define TPtrList_First(self) (TOpaqueList_First((self)))
#define TPtrList_Last(self) (TOpaqueList_Last((self)))
#define TPtrList_Next(self,pix) (TOpaqueList_Next((self),(pix)))
#define TPtrList_Prev(self,pix) (TOpaqueList_Prev((self),(pix)))
#define TPtrList_Nth(self,n) (TOpaqueList_Nth((self),(n)))
#define TPtrList_Order(self,pix) (TOpaqueList_Order((self),(pix)))
#define TPtrList_GetItem(self,pix) ((void *)TOpaqueList_GetItem((self),(pix)))
#define TPtrList_SetItem(self,pix,item) (TOpaqueList_SetItem((self),(pix),(slim_opaque)(item))
#define TPtrList_InsertAfter(self,pix,item) (TOpaqueList_InsertAfter((self),(pix),(slim_opaque)(item)))
#define TPtrList_Prepend(self,item) (TOpaqueList_Prepend((self),(slim_opaque)(item)))
#define TPtrList_InsertBefore(self,pix,item) (TOpaqueList_InsertBefore((self),(pix),(slim_opaque)(item)))
#define TPtrList_Append(self,item) (TOpaqueList_Append((self),(slim_opaque)(item)))
#define TPtrList_ChainAfter(self,after,pix) (TOpaqueList_ChainAfter((self),(after),(pix)))
#define TPtrList_ChainFirst(self,pix) (TOpaqueList_ChainFirst((self),(pix)))
#define TPtrList_ChainBefore(self,before,pix) (TOpaqueList_ChainBefore((self),(before),(pix)))
#define TPtrList_ChainLast(self,pix) (TOpaqueList_ChainLast((self),(pix)))
#define TPtrList_Unchain(self,pix) (TOpaqueList_Unchain((self),(pix)))
#define TPtrList_IsChained(self,pix) (TOpaqueList_IsChained((self),(pix)))
#define TPtrList_Remove(self,pix) (TOpaqueList_Remove((self),(pix)))

#define TPtrList_BeginVisit(self,pix,visit) (TOpaqueList_BeginVisit((self),(pix),(visit)))
#define TPtrList_EndVisit(self,visit) (TOpaqueList_EndVisit((self),(visit)))
#define TPtrList_VisitAt(self,pix,visit)	((void **)TOpaqueList_VisitAt((self),(pix),(visit)))
#define TPtrList_VisitFirst(self,visit) ((void **)TOpaqueList_VisitFirst((self),(visit)))
#define TPtrList_VisitLast(self,visit) ((void **)TOpaqueList_VisitLast((self),(visit)))
#define TPtrList_VisitNext(self,visit) ((void **)TOpaqueList_VisitNext((self),(visit)))
#define TPtrList_VisitPrev(self,visit) ((void **)TOpaqueList_VisitPrev((self),(visit)))

/* array collection */

/* spec array */

#define TSpecArray_Initialize(self,itemsz) (TArray_Initialize(&(self)->fBase,(itemsz)))
#define TSpecArray_Finalize(self) (TArray_Finalize(&(self)->fBase))
#define TSpecArray_MakeEmpty(self) {TArray_MakeEmpty(&(self)->fBase);}
#define TSpecArray_IsEmpty(self) (TArray_IsEmpty(&(self)->fBase))
#define TSpecArray_Length(self) (TArray_Length(&(self)->fBase))
#define TSpecArray_Append(self,item) (TArray_AppendSpec(&(self)->fBase,(item)))
#define TSpecArray_RemoveLast(self) (TArray_RemoveLast(&(self)->fBase))
#define TSpecArray_GetItem(self,index,item) (TArray_GetSpec(&(self)->fBase,(index),(item)))
#define TSpecArray_SetItem(self,index,item) (TArray_SetSpec(&(self)->fBase,(index),(item)))
#define TSpecArray_GetLastItem(self,item) (TArray_Length(&(self)->fBase) > 0 ? TArray_GetSpec(&(self)->fBase, TArray_Length(&(self)->fBase) - 1,(item)) : 0)
#define TSpecArray_SetLastItem(self,item) (TArray_Length(&(self)->fBase) > 0 ? TArray_SetSpec(&(self)->fBase, TArray_Length(&(self)->fBase) - 1,(item)) : 0)
#define TSpecArray_LockItem(self,index) (TArray_LockItem(&(self)->fBase,(index)))
#define TSpecArray_UnlockItem(self,index) (TArray_UnlockItem(&(self)->fBase,(index)))
#define TSpecArray_LockLastItem(self) (TArray_Length(&(self)->fBase) > 0 ? TArray_LockItem(&(self)->fBase, TArray_Length(&(self)->fBase) - 1) : slim_nil)
#define TSpecArray_UnlockLastItem(self) (TArray_Length(&(self)->fBase) > 0 ? (void)TArray_UnlockItem(&(self)->fBase, TArray_Length(&(self)->fBase) - 1 ) : (void)0)
#define TSpecArray_LocateItem(self,index) (TArray_LocateItem(&(self)->fBase,(index)))
#define TSpecArray_UnlocateItem(self,index) (TArray_UnlocateItem(&(self)->fBase,(index)))
#define TSpecArray_LocateLastItem(self) (TArray_Length(&(self)->fBase) > 0 ? TArray_LocateItem(&(self)->fBase, TArray_Length(&(self)->fBase) - 1) : slim_nil)
#define TSpecArray_UnlocateLastItem(self) (TArray_Length(&(self)->fBase) > 0 ? (void)TArray_UnlocateItem(&(self)->fBase, TArray_Length(&(self)->fBase) - 1 ) : (void)0)
#define TSpecArray_BeginVisit(self,index,visit) (TArray_BeginVisit(&(self)->fBase,(index),(visit)))
#define TSpecArray_EndVisit(self,visit) (TArray_EndVisit(&(self)->fBase,(visit)))
#define TSpecArray_VisitAt(self,index,visit) (TArray_VisitAt(&(self)->fBase,(index),(visit)))

/* opaque array */

#define TOpaqueArray_Initialize(self) (TArray_Initialize(&(self)->fBase,sizeof(slim_opaque)))
#define TOpaqueArray_Finalize(self) (TArray_Finalize(&(self)->fBase))
#define TOpaqueArray_MakeEmpty(self) {TArray_MakeEmpty(&(self)->fBase);}
#define TOpaqueArray_IsEmpty(self) (TArray_IsEmpty(&(self)->fBase))
#define TOpaqueArray_Length(self) (TArray_Length(&(self)->fBase))
#define TOpaqueArray_Append(self,item) (TArray_AppendOpaque(&(self)->fBase,(item)))
#define TOpaqueArray_RemoveLast(self) (TArray_RemoveLast(&(self)->fBase))
#define TOpaqueArray_GetItem(self,index) (TArray_GetOpaque(&(self)->fBase,(index)))
#define TOpaqueArray_SetItem(self,index,item) (TArray_SetOpaque(&(self)->fBase,(index),(item)))
#define TOpaqueArray_GetLastItem(self) (TOpaqueArray_Length(self) > 0 ? TOpaqueArray_GetItem((self), TOpaqueArray_Length(self) - 1 ) : slim_nil)
#define TOpaqueArray_BeginVisit(self,index,visit) (TArray_BeginVisit(&(self)->fBase,(index),(visit)))
#define TOpaqueArray_EndVisit(self,visit) (TArray_EndVisit(&(self)->fBase,(visit)))
#define TOpaqueArray_VisitAt(self,index,visit) ((slim_opaque*)TArray_VisitAt(&(self)->fBase,(index),(visit)))

/* opaque array variants */

#define TObjectArray_Initialize(self) (TOpaqueArray_Initialize((self)))
#define TObjectArray_Finalize(self) (TOpaqueArray_Finalize((self)))
#define TObjectArray_MakeEmpty(self) {TOpaqueArray_MakeEmpty((self));}
#define TObjectArray_IsEmpty(self) (TOpaqueArray_IsEmpty((self)))
#define TObjectArray_Length(self) (TOpaqueArray_Length((self)))
#define TObjectArray_Append(self,item) (TOpaqueArray_Append((self),(slim_opaque)(item)))
#define TObjectArray_RemoveLast(self) (TOpaqueArray_RemoveLast((self)))
#define TObjectArray_GetItem(self,index) ((slim_object)TOpaqueArray_GetItem((self),(index)))
#define TObjectArray_SetItem(self,index,item) (TOpaqueArray_SetItem((self),(index),(slim_opaque)(item)))

#define TObjectArray_BeginVisit(self,index,visit) (TOpaqueArray_BeginVisit((self),(index),(visit)))
#define TObjectArray_EndVisit(self,visit) (TOpaqueArray_EndVisit((self),(visit)))
#define TObjectArray_VisitAt(self,index,visit) ((slim_object*)TOpaqueArray_VisitAt((self),(index),(visit)))


#define TIntArray_Initialize(self) (TOpaqueArray_Initialize((self)))
#define TIntArray_Finalize(self) (TOpaqueArray_Finalize((self)))
#define TIntArray_MakeEmpty(self) {TOpaqueArray_MakeEmpty((self));}
#define TIntArray_IsEmpty(self) (TOpaqueArray_IsEmpty((self)))
#define TIntArray_Length(self) (TOpaqueArray_Length((self)))
#define TIntArray_Append(self,item) (TOpaqueArray_Append((self),(slim_opaque)(item)))
#define TIntArray_RemoveLast(self) (TOpaqueArray_RemoveLast((self)))
#define TIntArray_GetItem(self,index) ((slim_int)TOpaqueArray_GetItem((self),(index)))
#define TIntArray_GetLastItem(self) ((slim_int)TOpaqueArray_GetLastItem(self))
#define TIntArray_SetItem(self,index,item) (TOpaqueArray_SetItem((self),(index),(slim_opaque)(item)))

#define TIntArray_BeginVisit(self,index,visit) (TOpaqueArray_BeginVisit((self),(index),(visit)))
#define TIntArray_EndVisit(self,visit) (TOpaqueArray_EndVisit((self),(visit)))
#define TIntArray_VisitAt(self,index,visit) ((slim_int*)TOpaqueArray_VisitAt((self),(index),(visit)))

#define TPtrArray_Initialize(self) (TOpaqueArray_Initialize((self)))
#define TPtrArray_Finalize(self) (TOpaqueArray_Finalize((self)))
#define TPtrArray_MakeEmpty(self) {TOpaqueArray_MakeEmpty((self));}
#define TPtrArray_IsEmpty(self) (TOpaqueArray_IsEmpty((self)))
#define TPtrArray_Length(self) (TOpaqueArray_Length((self)))
#define TPtrArray_Append(self,item) (TOpaqueArray_Append((self),(slim_opaque)(item)))
#define TPtrArray_RemoveLast(self) (TOpaqueArray_RemoveLast((self)))
#define TPtrArray_GetItem(self,index) ((void *)TOpaqueArray_GetItem((self),(index)))
#define TPtrArray_SetItem(self,index,item) (TOpaqueArray_SetItem((self),(index),(slim_opaque)(item)))

#define TPtrArray_GetLastItem(self) ((void *)TOpaqueArray_GetLastItem(self))

#define TPtrArray_BeginVisit(self,index,visit) (TOpaqueArray_BeginVisit((self),(index),(visit)))
#define TPtrArray_EndVisit(self,visit) (TOpaqueArray_EndVisit((self),(visit)))
#define TPtrArray_VisitAt(self,index,visit) ((void **)TOpaqueArray_VisitAt((self),(index),(visit)))

/* spec fast array */

#define TSpecFastArray_Initialize(self,itemsz) (TFastArray_Initialize(&(self)->fBase,(itemsz)))
#define TSpecFastArray_Finalize(self) (TFastArray_Finalize(&(self)->fBase))
#define TSpecFastArray_MakeEmpty(self) {TFastArray_MakeEmpty(&(self)->fBase);}
#define TSpecFastArray_IsEmpty(self) (TFastArray_IsEmpty(&(self)->fBase))
#define TSpecFastArray_Length(self) (TFastArray_Length(&(self)->fBase))
#define TSpecFastArray_Append(self,item) (TFastArray_AppendSpec(&(self)->fBase,(item)))
#define TSpecFastArray_RemoveLast(self) (TFastArray_RemoveLast(&(self)->fBase))
#define TSpecFastArray_GetItem(self,index,item) (TFastArray_GetSpec(&(self)->fBase,(index),(item)))
#define TSpecFastArray_SetItem(self,index,item) (TFastArray_SetSpec(&(self)->fBase,(index),(item)))
#define TSpecFastArray_GetLastItem(self,item) (TFastArray_Length(&(self)->fBase) > 0 ? TFastArray_GetSpec(&(self)->fBase, TFastArray_Length(&(self)->fBase) - 1,(item)) : 0)
#define TSpecFastArray_SetLastItem(self,item) (TFastArray_Length(&(self)->fBase) > 0 ? TFastArray_SetSpec(&(self)->fBase, TFastArray_Length(&(self)->fBase) - 1,(item)) : 0)
#define TSpecFastArray_LockItem(self,index) (TFastArray_LockItem(&(self)->fBase,(index)))
#define TSpecFastArray_UnlockItem(self,index) (TFastArray_UnlockItem(&(self)->fBase,(index)))
#define TSpecFastArray_LockLastItem(self) (TFastArray_Length(&(self)->fBase) > 0 ? TFastArray_LockItem(&(self)->fBase, TFastArray_Length(&(self)->fBase) - 1) : slim_nil)
#define TSpecFastArray_UnlockLastItem(self) (TFastArray_Length(&(self)->fBase) > 0 ? (TFastArray_UnlockItem(&(self)->fBase, TFastArray_Length(&(self)->fBase) - 1 ),0) : 0)
#define TSpecFastArray_LocateItem(self,index) (TFastArray_LocateItem(&(self)->fBase,(index)))
#define TSpecFastArray_UnlocateItem(self,index) (TFastArray_UnlocateItem(&(self)->fBase,(index)))
#define TSpecFastArray_LocateLastItem(self) (TFastArray_Length(&(self)->fBase) > 0 ? TFastArray_LocateItem(&(self)->fBase, TFastArray_Length(&(self)->fBase) - 1) : slim_nil)
#define TSpecFastArray_UnlocateLastItem(self) (TFastArray_Length(&(self)->fBase) > 0 ? TFastArray_UnlocateItem(&(self)->fBase, TFastArray_Length(&(self)->fBase) - 1 ) : 0)
#define TSpecFastArray_BeginVisit(self,index,visit) (TFastArray_BeginVisit(&(self)->fBase,(index),(visit)))
#define TSpecFastArray_EndVisit(self,visit) (TFastArray_EndVisit(&(self)->fBase,(visit)))
#define TSpecFastArray_VisitAt(self,index,visit) (TFastArray_VisitAt(&(self)->fBase,(index),(visit)))

/* linear array */

#define TLinearArray_VisitAtX_Direct(self, i, visit) ((void*)((visit)->fLockedBuffer + ((i)*((self)->fItemSize))))
#define TLinearArray_ItemSize(self) ((self)->fItemSize)
#define TLinearArray_Length(self)   ((self)->fLength)
#define TLinearArray_Initialize(self, item_size) TLinearArray_InitializeX(self, item_size, 0)
#define TLinearArray_InitWithMargin(self, item_size, cap) TLinearArray_InitializeX(self, item_size, cap)
#define TLinearArray_IsEmpty(self) (0 == TLinearArray_Length(self))
#define TLinearArray_Append(self, item) (TLinearArray_Append3((self), (item)) >= 0)
#define TLinearArray_Append3(self, item) (TLinearArray_AppendN3((self), (item), 1))
#define TLinearArray_RemoveLast(self) (SLIM_ASSERT(TLinearArray_Length(self) > 0), (self)->fLength--)
#define TLinearArray_RemoveLastN(self, n) (SLIM_ASSERT(TLinearArray_Length(self) >= n), (self)->fLength -= n)
#define	TLinearArray_GetItem(self,i,item) (TLinearArray_GetAt((self),(i),(item)))
#define TLinearArray_LockItem(self,i) ((void*)(((slim_byte*)slim_vhandle_lock((self)->fHandle)) + (self)->fItemSize*(i)))
#define TLinearArray_UnlockItem(self,i) slim_vhandle_unlock((self)->fHandle)
#define TLinearArray_LocateItem(self,i) ((void*)(((slim_byte*)slim_vhandle_locate((self)->fHandle)) + (self)->fItemSize*(i)))
#define TLinearArray_UnlocateItem(self,i) slim_vhandle_unlocate((self)->fHandle)
/* lock gives you direct access to buffer, to get fast, rather than portable */
#define TLinearArray_LockBuffer(self) slim_vhandle_lock((self)->fHandle)
#define TLinearArray_UnlockBuffer(self) slim_vhandle_unlock((self)->fHandle)
#define TLinearArray_LocateBuffer(self) slim_vhandle_locate((self)->fHandle)
#define TLinearArray_UnlocateBuffer(self) slim_vhandle_unlocate((self)->fHandle)
#define TLinearArray_EndVisit(self, visit) ((void)(TLinearArray_UnlockBuffer(self), (visit)->fLockedBuffer = slim_nil))
#ifdef SLIM_CONFIG_DEBUG
#define TLinearArray_VisitAt(self, i, visit) TLinearArray_VisitAtX_Checked((self), (i), (visit))
#else
#define TLinearArray_VisitAt(self, i, visit) TLinearArray_VisitAtX_Direct((self), (i), (visit))
#endif

SLIM_END_C_LINKAGE

#endif
