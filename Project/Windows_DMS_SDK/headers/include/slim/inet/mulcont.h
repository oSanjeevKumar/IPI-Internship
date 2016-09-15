/*
	mulcont.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/mulcont.h 21    06/04/13 12:36 Nagamati $ */

#ifndef SLIM_MULTI_CONTENT_H
#define SLIM_MULTI_CONTENT_H

SLIM_BEGIN_C_LINKAGE

/* declare */
typedef struct iTMultiContent_ iTMultiContent;
typedef struct TMultiContentClass_ TMultiContentClass;

/*
 * TMultiContentReviver
 */
typedef struct iTMultiContentReviver_ iTMultiContentReviver;
typedef struct iTMultiContentReviver_ **TMultiContentReviver;
typedef struct TMultiContentReviverClass_ TMultiContentReviverClass;
typedef slim_int (*MultiContentReviver_NewProc)(TMultiContentReviverClass *in_class, iTMultiContent *in_content, TMultiContentReviver *out_reviver);
typedef slim_bool (*MultiContentReviver_EqualProc)(iTMultiContentReviver *self, iTMultiContentReviver *in_another);
typedef slim_int (*MultiContentReviver_ReviveProc)(iTMultiContentReviver *self, TMultiContent *out_content);
typedef void (*MultiContentReviver_TidyProc)(iTMultiContentReviver *self);
struct TMultiContentReviverClass_ {
	TMultiContentClass *fMultiContentClass;
	MultiContentReviver_NewProc fNew;
	MultiContentReviver_EqualProc fEqual;
	MultiContentReviver_ReviveProc fRevive;
	MultiContentReviver_TidyProc fTidy;
};

struct iTMultiContentReviver_ {
	TMultiContentReviverClass *fClass;
	slim_int fRefCount;
};

/*
 * TMultiContentChannel
 */
typedef struct TMultiContentChannelClass_ TMultiContentChannelClass;
typedef struct iTMultiContentChannel_ iTMultiContentChannel;
typedef struct iTMultiContentChannel_ **TMultiContentChannel;

struct TMultiContentChannelClass_ {
	TContentChannelClass fBase;
};

struct iTMultiContentChannel_ {
	iTContentChannel fBase;
	TMultiContent fContent;
};

/*
 * TMultiContent (Abstract)
 */

enum {
	SLIM_MULTICONT_CLSID_UNKNOWN = -1,
	SLIM_MULTICONT_CLSID_PAGESAVE = 0,
	SLIM_MULTICONT_CLSID_MIMEMP,
	SLIM_MULTICONT_CLSID_VIEWER,
	SLIM_MULTICONT_CLSID_USER,
	SLIM_MULTICONT_CLSID_EXT_START = 1000
};

typedef struct TMultiContentItem_ TMultiContentItem;
struct TMultiContentItem_ {
	TContentSpec fContentSpec;
};

struct TMultiContentInfo_ {
	TURLString fURL;
	TCertList fCertList;
};
typedef struct TMultiContentInfo_ TMultiContentInfo;

typedef slim_int (*MultiContent_NewContentSpecProc)(iTMultiContent *self, TContentRequest *in_req, TContentSpec *out_spec);
typedef void (*MultiContent_TidyProc)(iTMultiContent *self);
typedef void (*MultiContent_TidyItemProc)(iTMultiContent *self, TMultiContentItem *in_item, slim_bool in_pending);
typedef slim_int (*MultiContent_UpdateContentSpecProc)(iTMultiContent *self, TContentSpec in_spec);
typedef void (*MultiContent_AbortProc)(iTMultiContent *self);
typedef slim_int (*MultiContent_GetInfoProc)(iTMultiContent *self, TMultiContentInfo *out_info);

struct TMultiContentClass_ {
	TContentClass *fContentClass;
	TDataArena *fArena;
	slim_int fClassID;
	TMultiContentChannelClass *fMultiContentChannelClass;
	TMultiContentReviverClass *fReviverClass;
	MultiContent_NewContentSpecProc fNewContentSpec;
	MultiContent_TidyProc fTidy;
	MultiContent_TidyItemProc fTidyItem;
	MultiContent_UpdateContentSpecProc fUpdateContentSpec;
	MultiContent_AbortProc fAbort;
	MultiContent_GetInfoProc fGetInfo;
};

struct iTMultiContent_ {
	TMultiContentClass *fClass;
	slim_int fRefCount;
	TMultiContent fHandle;
	slim_pix fItemListPix;
	slim_int fItemListLength;
	slim_pix fPendingItemListPix;
	slim_int fPendingItemListLength;
};


/* declare */
typedef struct iTMIMEMPContent_ iTMIMEMPContent;
typedef struct iTMIMEMPContent_ **TMIMEMPContent;

/*
 * MIMEMPContentReviver
 */
typedef struct iTMIMEMPContentReviver_ iTMIMEMPContentReviver;
typedef struct iTMIMEMPContentReviver_ **TMIMEMPContentReviver;

struct iTMIMEMPContentReviver_ {
	iTMultiContentReviver fBase;
	TContentRequest fReq;
};

typedef struct TMIMEMPContentReviverClass_ TMIMEMPContentReviverClass;
struct TMIMEMPContentReviverClass_ {
	TMultiContentReviverClass fBase;
};

/*
 * MIMEMPContent
 */

typedef struct TMIMEMPContentItem_ TMIMEMPContentItem;
struct TMIMEMPContentItem_ {
	TMultiContentItem fBase;
	TURLString fLocation;
	TURLString fCID;
	slim_int fDepth;
	slim_int fMIMEType; /* of Content-Type: field */
	slim_offlen fHeader;
	slim_offlen fBody;
	slim_int fFlag;
	slim_int fNextOff;
};

typedef struct TMIMEMPContentPendItem_ TMIMEMPContentPendItem;
struct TMIMEMPContentPendItem_ {
	TMultiContentItem fBase;
	slim_int fIndex;
	slim_int fMIMEType;
	TURLString fURL;
	slim_pix fStartPix; /* for FindItemByMIMEType */
};

typedef struct TMIMEMPTokenHandler_ TMIMEMPTokenHandler;
struct TMIMEMPTokenHandler_ {
	TTokenHandler fBase;
	iTMIMEMPContent *fContent;
};

typedef struct TMIMEMPContentClass_ TMIMEMPContentClass;
struct TMIMEMPContentClass_ {
	TMultiContentClass fBase;
	slim_int fFlag;
	slim_int fMaxStayTime;
	TInetMsgTokenizerClass fTokenizerClass;
	TTokenHandlerClass fHandlerClass;
	TMIMEMPContentReviverClass fReviverClass;
};

struct iTMIMEMPContent_ {
	iTMultiContent fBase;
	slim_int fFlag;
	slim_int fState;
	slim_pix fContainerPix;
	TContent fSrcContent;
	TReaderInput fInput;
	TInetMsgTokenizer fTokenizer;
	TMIMEMPTokenHandler fHandler;
	TReader fReader;
};

/*
 * UserContent
 */

typedef struct TUserContentItem_ TUserContentItem;
struct TUserContentItem_ {
	TMultiContentItem fBase;
};

typedef struct iTUserContent_ iTUserContent;
typedef iTUserContent **TUserContent;

typedef slim_bool (*UserContent_InitItemProc)(iTUserContent *self, TUserContentItem *out_item);
typedef struct TUserContentClass_ TUserContentClass;
struct TUserContentClass_ {
	TMultiContentClass fBase;
	slim_int fItemSize;
	UserContent_InitItemProc fInitItem;
};

struct iTUserContent_ {
	iTMultiContent fBase;
	slim_pix fRootItem;
};

/* API */
#define TUserContent_AddData(self,url,ulen,mime,data,dlen) TUserContent_AddDataX((self),(url),(ulen),(mime),(data),(dlen), slim_pix_nil)


#define TUserContent_ContentType(self,idx) TUserContent_GetSetContentType((self),(idx),SLIM_MIME_UNKNOWN, slim_false)
#define TUserContent_SetContentType(self,idx,mime) TUserContent_GetSetContentType((self),(idx),(mime),slim_true)

#define TUserContent_OpenContentByURL(self, url, len, out) (TUserContent_OpenContentX((self),(url),(len),slim_pix_nil,(out)))
#define TUserContent_OpenContentByIndex(self,i,out) (TUserContent_OpenContentX((self),slim_nil,0,(i),(out)))



SLIM_END_C_LINKAGE
#endif
