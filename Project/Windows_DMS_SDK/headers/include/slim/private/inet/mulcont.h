/*
	mulcont.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/mulcont.h 21    05/12/28 12:08 Someya $ */

#ifndef SLIM_MULTI_CONTENT_H_PRIVATE
#define SLIM_MULTI_CONTENT_H_PRIVATE

#include <slim/private/inet/drm.h>

SLIM_BEGIN_C_LINKAGE

/*
 * TMultiContentReviver
 */

/* protected */
#define MultiContentReviver_New0(sz) ((TMultiContentReviver)slim_handle_zeroalloc((sz)))
#define TMultiContentReviver_Lock(self) (slim_handle_lock((slim_handle)(self)))
#define TMultiContentReviver_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define TMultiContentReviver_Locate(self) (slim_handle_locate((slim_handle)(self)))
#define TMultiContentReviver_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))


/* public */

/*
 * TMultiContentChannel
 */

#define MultiContentChannel_Finalize(cls)	(ContentChannel_Finalize(&(cls)->fBase))


/*
 * TMultiContent (Abstract)
 */

/* protected */
#define iTMultiContent_NewItem(self,sz)	TDataArena_ZeroNewItem((self)->fClass->fArena,(sz))

#define iTMultiContent_FirstChild(self,ppix)	TDataArena_FirstChild((self)->fClass->fArena, (ppix))

#define iTMultiContent_FirstItem(self)		TDataArena_FirstChild((self)->fClass->fArena, (self)->fItemListPix)
#define iTMultiContent_LastItem(self)		TDataArena_LastChild((self)->fClass->fArena, (self)->fItemListPix)
#define iTMultiContent_FirstPendingItem(self)		TDataArena_FirstChild((self)->fClass->fArena, (self)->fPendingItemListPix)
#define iTMultiContent_LastPendingItem(self)		TDataArena_LastChild((self)->fClass->fArena, (self)->fPendingItemListPix)
#define iTMultiContent_NextItem(self, pix)	TDataArena_NextItem((self)->fClass->fArena, (pix))
#define iTMultiContent_PrevItem(self, pix)	TDataArena_PrevItem((self)->fClass->fArena, (pix))
#define iTMultiContent_LockItem(self, pix)	TDataArena_LockItem((self)->fClass->fArena, (pix))
#define iTMultiContent_UnlockItem(self, pix)	TDataArena_UnlockItem((self)->fClass->fArena, (pix))
#define iTMultiContent_LocateItem(self, pix)	TDataArena_LocateItem((self)->fClass->fArena, (pix))
#define iTMultiContent_UnlocateItem(self, pix)	TDataArena_UnlocateItem((self)->fClass->fArena, (pix))
#define iTMultiContent_GetItem(self,pix,buf,sz)	TDataArena_GetItem((self)->fClass->fArena,(pix),(buf),(sz))
#define iTMultiContent_SetItem(self,pix,buf,sz)	TDataArena_SetItem((self)->fClass->fArena,(pix),(buf),(sz))

#define iTMultiContent_ListLength(self) ((self)->fItemListLength)
#define iTMultiContent_PendingListLength(self) ((self)->fPendingItemListLength)

#define iTMultiContent_AppendItem(self,item,sz) iTMultiContent_AppendItemX((self),(item),(sz),slim_false)
#define iTMultiContent_AppendPendingItem(self,item,sz) iTMultiContent_AppendItemX((self),(item),(sz),slim_true)
#define iTMultiContent_TidyItem(self,item) iTMultiContent_TidyItemX((self),(item),slim_false)
#define iTMultiContent_TidyPendingItem(self,item) iTMultiContent_TidyItemX((self),(item),slim_true)
#define iTMultiContent_ForeachItem(self,st,proc,arg) iTMultiContent_ForeachItemX((self),(st),(proc),(arg),slim_false)
#define iTMultiContent_ForeachPendingItem(self,st,proc,arg) iTMultiContent_ForeachItemX((self),(st),(proc),(arg),slim_true)
typedef slim_int (*MultiContent_ForeachItemProc)(slim_pix in_pix, TMultiContentItem *in_item, slim_opaque in_arg);
#define iTMultiContent_FindItemByURL(self,st,url) iTMultiContent_FindItemByURLX((self),(st),(url),slim_false)
#define iTMultiContent_FindPendingItemByURL(self,st,url) iTMultiContent_FindItemByURLX((self),(st),(url),slim_true)
#define iTMultiContent_FindItemBySpec(self,st,url) iTMultiContent_FindItemBySpecX((self),(st),(url),slim_false)
#define iTMultiContent_FindPendingItemBySpec(self,st,url) iTMultiContent_FindItemBySpecX((self),(st),(url),slim_true)



#define iTMultiContent_UpdateContentSpec(self,spec) (!(self)->fClass->fUpdateContentSpec ? SLIM_E_OK : (*(self)->fClass->fUpdateContentSpec)((self),(spec)))



#define MultiContent_New0(sz)	((TMultiContent)slim_handle_zeroalloc((sz)))
#define TMultiContent_Delete0(self)	slim_handle_free((slim_handle)(self))

#define TMultiContent_PeekPtr(self,off) slim_handle_peek_ptr((slim_handle)(self),(off))
#define TMultiContent_PeekInt(self,off) slim_handle_peek_int((slim_handle)(self),(off))
#define TMultiContent_PeekShort(self,off) slim_handle_peek_short((slim_handle)(self),(off))
#define TMultiContent_Class(self)	((TMultiContentClass *)TMultiContent_PeekPtr((self),SLIM_OFFSETOF(iTMultiContent, fClass)))
/* public */
#define TMultiContent_ClassID(self)	(TMultiContent_Class((self))->fClassID)
#define TMultiContent_Lock(self)	(slim_handle_lock((slim_handle)(self)))
#define TMultiContent_Unlock(self)	(slim_handle_unlock((slim_handle)(self)))
#define TMultiContent_Locate(self)	(slim_handle_locate((slim_handle)(self)))
#define TMultiContent_Unlocate(self)	(slim_handle_unlocate((slim_handle)(self)))
#define TMultiContent_Length(self)	(TMultiContent_PeekInt((self), SLIM_OFFSETOF(iTMultiContent, fItemListLength)))


#define TMultiContent_OpenContent(self,req,cont) TMultiContent_OpenContentX((self),(req),slim_pix_nil,(cont))
#define TMultiContent_OpenRootContent(self,cont) TMultiContent_OpenContentX((self),slim_nil,slim_pix_nil,(cont))
#define TMultiContent_OpenContentByPix(self,pix,cont) TMultiContent_OpenContentX((self),slim_nil,(pix),(cont))


/*
 * MIMEMPContentReviver
 */

/* public */

#define MIMEMPContentReviver_Finalize(cls) ((void)0)


/*
 * MIMEMPContent
 */

/* class flags */
#define SLIM_MIMEMPCONT_FAVOR_INT_CONT	0x00000001
#define SLIM_MIMEMPCONT_ALLOW_EXT_CONT	0x00000002	/* retrieve content if not found in multipart content */

#define SLIM_MIMEMPCONTITEM_ENC_BINARY	0x00000000
#define SLIM_MIMEMPCONTITEM_ENC_7BIT	0x00000001
#define SLIM_MIMEMPCONTITEM_ENC_8BIT	0x00000002
#define SLIM_MIMEMPCONTITEM_ENC_BASE64	0x00000003
#define SLIM_MIMEMPCONTITEM_ENC_QP		0x00000004
#define SLIM_MIMEMPCONTITEM_ENC_UNKNOWN	0x00000005

#define SLIM_MIMEMPCONTITEM_ENCMASK		0x00000007

#define SLIM_MIMEMPCONTITEM_FLAG_HEADER_DONE	0x00000008
#define SLIM_MIMEMPCONTITEM_FLAG_BODY_AVAIL		0x00000010
#define SLIM_MIMEMPCONTITEM_FLAG_BODY_DONE		0x00000020

/* bits of SLIM_POLL_BITMASK are reserved */
#define SLIM_MIMEMPCONT_FLAG_HEADER_DONE	0x00000004
#define SLIM_MIMEMPCONT_FLAG_NOMSGHEADER	0x00000008

#define MIMEMPContent_SetFlag(in_class, flag, set)	((void)((in_class)->fFlag = ((set) ? (in_class)->fFlag | (flag) : (in_class)->fFlag & ~(flag))))

#define TMIMEMPContent_Class(self) ((TMIMEMPContentClass *)TMultiContent_Class((self)))
#define TMIMEMPContent_Flag(self) TMultiContent_PeekInt((self), SLIM_OFFSETOF(iTMIMEMPContent, fFlag))

#define TMIMEMPContent_OpenRootContentByURL(self,src,url,cont)  TMIMEMPContent_OpenRootContentByX((self),(src),-1,SLIM_MIME_UNKNOWN,(url),(cont))
#define TMIMEMPContent_OpenRootContentByMIMEType(self,src,type,cont) TMIMEMPContent_OpenRootContentByX((self),(src),-1,(type),slim_nil,(cont))
#define TMIMEMPContent_Open1stPartAsRootContent(self,src,cont) TMIMEMPContent_OpenRootContentByX((self),(src),0,SLIM_MIME_UNKNOWN,slim_nil,(cont))

/*
 * UserContent
 */
/* protected */
#define iTUserContent_Class(self) ((TUserContentClass *)(self)->fBase.fClass)

SLIM_END_C_LINKAGE
#endif
