/*
	content.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/content.h 356   06/08/16 16:37 Siu $ */

#ifndef SLIM_CONTENT_H
#define SLIM_CONTENT_H

#include <slim/inet/dns.h>
#include <slim/inet/httpstrm.h>

SLIM_BEGIN_C_LINKAGE

/* declare */
typedef struct TContentClass_ TContentClass;

/* spec flag */
#define SLIM_CONTENT_DONE					0x00000001
#define SLIM_CONTENT_ERROR					0x00000002
#define SLIM_CONTENT_ABORT					0x00000004
#define SLIM_CONTENT_CONTENTAVAIL			0x00000008
#define SLIM_CONTENT_TYPEAVAIL				0x00000010
#define SLIM_CONTENT_ASIMAGE				0x00000020
#define SLIM_CONTENT_ASTEXT					0x00000040
#define SLIM_CONTENT_ASBINARY				0x00000060
#define SLIM_CONTENT_ASMASK					0x00000060
#define SLIM_CONTENT_WRITEOPEN				0x00000080

/* cache mode - enum */
#define SLIM_CONTENT_CACHE_USEDEFAULT		0x00000000	/* use TContentClass::fDefaultCacheMode */
#define SLIM_CONTENT_CACHE_INHERIT			0x00000100
#define SLIM_CONTENT_CACHE_NOCACHE			0x00000200
#define	SLIM_CONTENT_CACHE_NETFIRST			0x00000300
#define	SLIM_CONTENT_CACHE_NETFIRST_ONCE	0x00000400
#define	SLIM_CONTENT_CACHE_CACHEFIRST		0x00000500
#define	SLIM_CONTENT_CACHE_CACHEONLY		0x00000600
#define	SLIM_CONTENT_CACHE_NETONLY			0x00000700
#define	SLIM_CONTENT_CACHE_PAGESAVE			0x00000800
#define	SLIM_CONTENT_CACHE_REVALIDATE		0x00000900

#define SLIM_CONTENT_CACHEMASK				0x00000F00

/* bys */
#define	SLIM_CONTENT_BY_INCLUSION			0x00001000
#define	SLIM_CONTENT_BY_USER				0x00002000
#define	SLIM_CONTENT_BY_HISTORYBACK			0x00004000
#define	SLIM_CONTENT_BY_HISTORYFORW			0x00008000
#define	SLIM_CONTENT_BY_REFRESH				0x00010000
#define	SLIM_CONTENT_BY_RELOAD				0x00020000
#define	SLIM_CONTENT_BY_SCRIPT				0x00040000
#define	SLIM_CONTENT_BY_EMBED				0x00080000
#define	SLIM_CONTENT_BY_DOCWRITE			0x00100000
#define SLIM_CONTENT_BY_FRAME				0x00200000
#define SLIM_CONTENT_BY_ALTLINK				0x00400000

#define SLIM_CONTENT_BYMASK					0x00FFF000
#define SLIM_CONTENT_BY_HISTORY		(SLIM_CONTENT_BY_HISTORYBACK | SLIM_CONTENT_BY_HISTORYFORW)

/* header restriction */
#define SLIM_CONTENT_DISABLE_INFLATE		0x01000000
#define SLIM_CONTENT_DISABLE_REFERER		0x02000000
#define SLIM_CONTENT_DISABLE_COOKIE			0x04000000

/* history control */
#define SLIM_CONTENT_CUR_HISTORY_INHIBIT	0x08000000

/* cache control */
#define SLIM_CONTENT_INHIBIT_WRITE_CACHE	0x10000000

/* Content Request Type */
#define SLIM_CONTENT_REQUEST_FORM_SUBMIT	0x00000001
#define SLIM_CONTENT_REQUEST_FRAGMENT_JUMP	0x00000002
#define SLIM_CONTENT_REQUEST_INHIBIT_SHARE	0x00000004

#define SLIM_CONTENT_METHOD_GET		SLIM_HTTP_METHOD_GET
#define SLIM_CONTENT_METHOD_POST	SLIM_HTTP_METHOD_POST
	/* Ugh!: module dependency inversion (T_T) */

/* string encoding in post */
#define SLIM_CONTENT_POST_URLENCODED	0x00000001
#define SLIM_CONTENT_POST_PLAINTEXT		0x00000002
#define SLIM_CONTENT_POST_MULTIPART		0x00000004
#define SLIM_CONTENT_POST_RAW			0x00000008

#define SLIM_CNTSPEC_EXT_USENET					0x00000001
#define SLIM_CNTSPEC_EXT_AUTH_AUTO_RETRIED		0x00000002
#define SLIM_CNTSPEC_EXT_META_MAXAGE_SPECIFIED	0x00000004
#define SLIM_CNTSPEC_EXT_META_EXPIRES_SPECIFIED	0x00000008
#define SLIM_CNTSPEC_EXT_HIGH_PRIORITY			0x00000010
#define SLIM_CNTSPEC_EXT_VISITED				0x00000020
#define SLIM_CNTSPEC_EXT_SHARABLE				0x00000040
#define SLIM_CNTSPEC_EXT_REOPEN					0x00000080
#define SLIM_CNTSPEC_EXT_ALLOW_EMPTY			0x00000100

/*
 * Content Authentication Information
 */
struct iTContentAuth_ {
	slim_int fFlag;
	slim_int fType;
	slim_int fTarget;
	TString fChallenge;
	TString fRealm;
	TString fUser;
	TString fPass;
	TFixedString fProxyHost;
	slim_int fProxyPort;
};
typedef struct iTContentAuth_ iTContentAuth;
typedef struct iTContentAuth_ **TContentAuth;

enum {
	SLIM_CNTAUTH_FLAG_AVAIL       = 0x00000001,
	SLIM_CNTAUTH_FLAG_KEEP_USERID = 0x00000002,
	SLIM_CNTAUTH_FLAG_KEEP_PASSWD = 0x00000004
};

/*
 * ContentRequest
 */
typedef struct TContentRequest_ TContentRequest;
struct TContentRequest_ {
	TContentClass *fClass;
	slim_int fMethod;
	slim_int fFlag;
	TURLString fURL;
	TString fFragment;
	slim_int fURLCharSet;
	slim_int fFragmentCharSet;
	slim_int fSchemeID;
	slim_offlen fSplit[SLIM_SPLITURL_SPLITS];
	TURLString fReferer;
	TPostData fPostData;
	TString fHTTPHeader;
	slim_int fRequestTypeFlag;
	TContent fRefererContent;
	TContentAuth fPageAuth;
	TContentAuth fProxyAuth;
};

/* API */
#define TContentRequest_By(self) ((self)->fFlag & SLIM_CONTENT_BYMASK)
#define TContentRequest_URL(self) ((self)->fURL)
#ifndef SLIM_CONFIG_USE_HTTP
#define TContentRequest_AddHTTPHeaderX(self, in_name, in_name_len, in_val, in_val_len) (slim_true)
#endif
#define TContentRequest_AddHTTPHeader(req, name, nlen, val, vlen) TContentRequest_AddHTTPHeaderX((req), (slim_opaque)(name), (nlen), (val), (vlen))

/*
 * ContentChannel
 */
struct TContentChannelClass_ {
	TContentChannel (*fNewProc)(struct TContentChannelClass_ *in_class, TContentSpec in_spec, slim_int in_flag);
	void (*fDeleteProc)(TContentChannel self, TContentSpec in_spec);
	slim_int (*fProgressProc)(TContentChannel self, TContentSpec in_spec, slim_int *out_sleep);
	void (*fAbortProc)(TContentChannel self, TContentSpec in_spec);
	void (*fMakePersistentProc)(TContentChannel self, slim_bool in_persistent);
	void (*fSetCachePinProc)(TContentChannel self, slim_bool in_pin);
	slim_int (*fDetermineRetrieverProc)(struct TContentChannelClass_ *in_class, TURLString in_url, slim_int in_method, TPostData in_post_data, slim_int in_cache_mode, slim_int in_flag, slim_int *out_cache_type);
	void (*fSyncPersistentInfoProc)(struct TContentChannelClass_ *in_class);
	TMIMEInfoClass *fMIMEInfoClass;
	TURLSchemeInfoClass *fURLSchemeInfoClass;
	slim_opaque fUserData;
};
typedef struct TContentChannelClass_ TContentChannelClass;

struct iTContentChannel_ {
	TContentChannelClass *fClass;
	slim_int fState;
};
typedef struct iTContentChannel_ iTContentChannel;

struct TContentChannelRecord_ {
	slim_int fSchemeID;	/* SLIM_URL_SCHEME_UNKNOWN means empty */
	TContentChannelClass *fContentChannelClass;
};
typedef struct TContentChannelRecord_ TContentChannelRecord;

/*
 * ContentCoreSpec
 */
struct iTContentCoreSpec_ {
	slim_int fFlag;	/* via-proxy, defer-persistent, history-only, memory-only, expired */
	slim_int fRefCount;
	slim_time fTime;
	slim_vhandle fContent;
	TString fHeader;
	slim_int fCurrentLength;
	slim_int fContentLength;
	slim_int fOriginLength;
	slim_int fContentType;
	TString fValidatorETag;
	TString fValidatorDate;
	slim_time fExpires;
	slim_int fExpireType;
	TCertList fCertList;
	slim_int fCertListSize;		/* serialized cert list length for L2 cache */
};
typedef struct iTContentCoreSpec_ iTContentCoreSpec;
typedef struct iTContentCoreSpec_ **TContentCoreSpec;

/*
 * ContentCoreSpecInfo
 */
struct TContentCoreSpecInfo_ {
	slim_int fFlag;
	slim_time fTime;
	slim_int fContentLength;
	slim_int fOriginLength;
	TString fValidatorETag;
	TString fValidatorDate;
	slim_time fExpires;
	slim_int fExpireType;
};
typedef struct TContentCoreSpecInfo_ TContentCoreSpecInfo;

/*
 * ContentSpecList
 */
struct TContentSpecKey_ {
	TURLString fURL;
	slim_int fMethod;
	TPostData fPostData;
};
typedef struct TContentSpecKey_ TContentSpecKey;

#define SLIM_CONTSPECLIST_HASHSIZE 256
typedef struct TContentSpecList_ TContentSpecList;
struct TContentSpecList_ {
	TTree fList;
	slim_pix fRootPix;
	slim_pix fDoneSpecPix;
	slim_int fHighPriorityItems;
	THash fHash;
	slim_opaque fTable[SLIM_CONTSPECLIST_HASHSIZE];
};

/*
 * ContentSpec
 */
struct iTContentSpec_ {
	/* is-a */
	TContentClass *fClass;
	/* general */
	slim_pix fPix;
	slim_int fFlag;	/* status, as-flag, by-flag, cache-mode, history-inhibit, <meta> info */
	slim_opaque fHashNext;
	slim_short fRefCount;
	slim_short fAbortCount;
	slim_short fRedirectCount;
	slim_tiny fPageAuthCount;
	slim_tiny fProxyAuthCount;
	/* request */
	slim_int fMethod;
	TURLString fURL;			/* key of hash, do not modify */
	TURLString fReferer;
	TPostData fPostData;
	TURLString fRedirectURL;
	TURLString fOriginalURL;	/* if redirection, set the first URL */
	TString fHTTPHeader;  /* additional header from TContentRequest */
	
	/* comm */
	TContentChannelClass *fContentChannelClass;
	TContentChannel fContentChannel;
	slim_int fCacheType;
	slim_int fExtFlag;
	slim_int fRequestLen;
	slim_int fRequestSent;
	slim_int fChannelState;
	slim_int fStatusCode;
	slim_int fErrorCode;
	
	/* core spec */
	TContentCoreSpec fCoreSpec;

	/* for streaming */
	slim_int fWindowSize;
	slim_int fConsumedLength;

	/* authentication */
	TContentAuth fPageAuth;
	TContentAuth fProxyAuth;
};
typedef struct iTContentSpec_ iTContentSpec;

/*
 * ContentSpecFactory
 */

typedef struct TContentSpecFactory_ TContentSpecFactory;
typedef slim_int (*ContentSpecFactory_PrepareProc)(TContentSpecFactory *self, TContentRequest *in_req, TContentSpec *out_spec);
struct TContentSpecFactory_ {
	TContentClass *fContentClass;
	ContentSpecFactory_PrepareProc fPrepare;
	slim_opaque fUserData;
};

/*
 * Content
 */

/* NetScape full compatible content state notify*/
enum {
	SLIM_CONTENTSTATE_OPEN,
	SLIM_CONTENTSTATE_CONNECTING,
	SLIM_CONTENTSTATE_SSLHANDSHAKING,
	SLIM_CONTENTSTATE_REQUESTING,
	SLIM_CONTENTSTATE_TRANSFERSTART,
	SLIM_CONTENTSTATE_TRANSFERRING,
	SLIM_CONTENTSTATE_TRANSFERRED,
	SLIM_CONTENTSTATE_READINGCACHE,
	SLIM_CONTENTSTATE_READINGFILE
};

enum {
	SLIM_CONTENT_E_SIZEOVER = SLIM_CONTENT_ERROR_START,
	SLIM_CONTENT_E_NO_CONTENT,
	SLIM_CONTENT_E_TOOMANYREDIRECT,
	SLIM_CONTENT_E_TOOMANYAUTH,
	SLIM_CONTENT_E_BADMIMETYPE,
	SLIM_CONTENT_ERROR_END
};

#define SLIM_CONTENT_MAX_CHANNELS 8

typedef void (*Content_NotifyProc)(TContentSpec in_content, slim_int in_notify, slim_opaque in_aux);
typedef TURLString (*Content_RestrictRefererProc)(struct TContentClass_ *in_class, TURLString in_url, TURLString in_referer, slim_int in_by);

struct TContentSizeLimit_ {
	slim_int fMIMEType;
	slim_int fLimit;
};
typedef struct TContentSizeLimit_ TContentSizeLimit;

#define SLIM_CNTCLS_DISABLE_SEND_COOKIE			0x00000001
#define SLIM_CNTCLS_DISABLE_SEND_REFERER		0x00000002
#define SLIM_CNTCLS_USE_DATE_AS_VALIDATOR		0x00000004
#define SLIM_CNTCLS_USE_CURDATE_AS_VALIDATOR	0x00000008
#define SLIM_CNTCLS_USE_HEURISTIC_EXPIRATION	0x00000010

struct TContentClass_ {
	TContentChannelRecord fChannelTable[SLIM_CONTENT_MAX_CHANNELS];
	TContentSpecList fContentSpecList;
	slim_int fFlag;
	slim_int fDefaultCacheMode;
	slim_int fL2CacheTiming;
	slim_int fDeferredCount;
	Content_NotifyProc fNotifyProc;
	slim_opaque fAux;
	TMIMEInfoClass *fMIMEInfoClass;
	TURLSchemeInfoClass *fURLSchemeInfoClass;
	TSpecList fSizeLimit;		/* size limitation according to the content type */
	slim_int fMaxRedirect;		/* default : SLIM_CONFIG_CONTENT_MAXREDIRECT */
	slim_int fMaxPageAuth;		/* default : SLIM_CONFIG_CONTENT_MAXPAGEAUTH */
	slim_int fMaxProxyAuth;		/* default : SLIM_CONFIG_CONTENT_MAXPROXYAUTH */
	TContentDeterminerClass *fDeterminerClass;
	TContent fDummy;
	TDRMManager *fDRMManager;
	TContentSpecFactory *fContentSpecFactory;
	Content_RestrictRefererProc fRestrictRefererProc;
};

struct iTContent_ {
	TContentSpec fContentSpec;
	slim_int fRequestFlag;
	TURLString fReferer;	/* original referer in requesting */
	slim_int fURLCharSet;
	slim_int fRequestedMIMEType;
	TString fFragment;
	slim_int fFragmentCharSet;
	slim_int fForcedCharSet;
	slim_int fInstanceFlag;
	TMultiContent fMultiContent;
	slim_int fSafeDataLen; /* length of virus-free data */
	slim_bool fSafeDataDone;

	/* DRM extention */
	TDRMMediaObject *fMediaObject;
	TDRMUsageContext *fUsageContext;
};
typedef struct iTContent_ iTContent;

/*
 * TStreamContent
 */
struct iTStreamContent_ {
	TContentSpec fContentSpec;
	slim_int fRequestFlag;
	TURLString fReferer;	/* original referer in requesting */
	slim_int fURLCharSet;
	slim_int fRequestedMIMEType;
	TMultiContent fMultiContent;
};
typedef struct iTStreamContent_ iTStreamContent;

/*
 * ContentReader
 */
typedef struct TContentReader_ TContentReader;
typedef slim_int (*ContentReader_ProgressProc)(TContentReader *self);
typedef void (*ContentReader_TidyProc)(TContentReader *self);
typedef slim_int (*ContentReader_ReadProc)(TContent in_cont, void *in_data, slim_int *inout_len, slim_int in_offset, slim_int in_charset, slim_bool in_eof, slim_opaque in_arg);
typedef slim_bool (*ContentReader_WriteProc)(TContentReader *self, void *in_data, slim_int in_len);

struct TContentReader_ {
	slim_int fFlag;
	TContent fContent;
	slim_int fOffset;
	ContentReader_ProgressProc fProgress;
	ContentReader_TidyProc fTidy;
	ContentReader_ReadProc fRead;
	ContentReader_WriteProc fWrite;
	slim_opaque fUserData;
};

/*
 * BinaryContentReader
 */

typedef struct TBinaryContentReader_ TBinaryContentReader;
struct TBinaryContentReader_ {
	TContentReader fBase;
};

/*
 * TextContentReader
 */

typedef struct TTextContentReader_ TTextContentReader;
struct TTextContentReader_ {
	TContentReader fBase;
	TI18NConverter *fI18NConverter;
	TContentDeterminer *fDeterminer;
	slim_vhandle fTextBuffer;
	slim_int fTextBufLength;
	slim_int fConvSrcLength;
	slim_int fWrittenLength;
	/* 0 <= fWrittenLength <= fTextBufLength */
};

SLIM_END_C_LINKAGE
#endif
