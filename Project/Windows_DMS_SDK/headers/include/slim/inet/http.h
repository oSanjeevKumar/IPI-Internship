/*
	http.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/http.h 238   06/07/13 21:15 Siu $ */

#ifndef SLIM_HTTP_H
#define SLIM_HTTP_H

#include <slim/inet/httpstrm.h>
#include <slim/inet/content.h>

SLIM_BEGIN_C_LINKAGE

/*=========================
	Forward Declarations
 =========================*/

typedef struct THTTPCache_ THTTPCache;
typedef struct THTTPL1Cache_ THTTPL1Cache;
typedef struct THTTPL2Cache_ THTTPL2Cache;
typedef struct THTTPContentCache_ THTTPContentCache;

typedef struct iTHTTPChannel_ iTHTTPChannel;
typedef iTHTTPChannel **THTTPChannel;
typedef struct THTTPChannelClass_ THTTPChannelClass;


/*===================
	Configurations
 ===================*/

/* for debug */
#ifdef SLIM_CONFIG_DEBUG
#ifdef SLIM_CONFIG_USE_HTTP
#define SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS
#define SLIM_CONFIG_HTTP_CHANNEL_DEBUG
#define SLIM_CONFIG_HTTP_CACHE_DEBUG
#endif
#endif

/* for cache */
#define SLIM_HTTP_CACHE_HASHSIZE						256
#define SLIM_HTTP_REDIRECTURLCACHE_LIMITS				200
#define SLIM_HTTP_L2CACHE_RWCHUNK						4096
#define SLIM_HTTP_CACHE_DEFAULT_STORE_HEADER			slim_true
#define SLIM_HTTP_CACHE_DEFAULT_L1_ENTRIES				0
#define SLIM_HTTP_CACHE_DEFAULT_L1_TOTAL_SIZE			0
#define SLIM_HTTP_CACHE_DEFAULT_L1_CONTENT_SIZE			0
#define SLIM_HTTP_CACHE_DEFAULT_L2_ENTRIES				0
#define SLIM_HTTP_CACHE_DEFAULT_L2_TOTAL_SIZE			0
#define SLIM_HTTP_CACHE_DEFAULT_L2_CONTENT_SIZE			0
#ifndef SLIM_HTTP_L2CACHE_DEFAULT_ROUND_UP_UNIT
#define SLIM_HTTP_L2CACHE_DEFAULT_ROUND_UP_UNIT			1024
#endif
#ifndef SLIM_HTTP_L2CACHE_DEFAULT_FAT_NAME
#define SLIM_HTTP_L2CACHE_DEFAULT_FAT_NAME				SLIM_T("cache.fat")
#endif
#ifndef SLIM_HTTP_L2CACHE_DEFAULT_DIR_NAME
#define SLIM_HTTP_L2CACHE_DEFAULT_DIR_NAME				SLIM_T("cache")
#endif
#ifndef SLIM_HTTP_L2CACHE_DEFAULT_DELIMITER
#define SLIM_HTTP_L2CACHE_DEFAULT_DELIMITER				SLIM_C('/')
#endif
#ifndef SLIM_HTTP_L2CACHE_DEFAULT_EXT_NAME
#define SLIM_HTTP_L2CACHE_DEFAULT_EXT_NAME				SLIM_T(".dcf")
#endif

/* for channel */
#define SLIM_HTTP_CHANNEL_DEFAULT_READ_CHUNK			SLIM_HTTP_STREAM_READ_CHUNK
#define SLIM_HTTP_CHANNEL_DEFAULT_TIME_OUT				20 * 1000						/* msec */
#define SLIM_HTTP_CHANNEL_DEFAULT_VERSION				SLIM_HTTP_VERSION_1_1
#define SLIM_HTTP_CHANNEL_DEFAULT_AUX_HEADER			SLIM_T("")
#define SLIM_HTTP_CHANNEL_DEFAULT_SSL_FLAG				SLIM_SSL_DEFAULT_CONN_MODE
#define SLIM_HTTP_CHANNEL_DEFAULT_PIPELINE				slim_true
#define SLIM_HTTP_CHANNEL_DEFAULT_LOOKUP_HTTPS_CACHE	slim_false
#define SLIM_HTTP_CHANNEL_DEFAULT_REDIRECT_CB			slim_false
#define SLIM_HTTP_CHANNEL_DEFAULT_AUTH_CB				slim_false


/*===============
	HTTP Cache
 ===============*/

/*------------------
	THTTPCacheKey
 ------------------*/

struct THTTPCacheKey_ {
	TURLString fURL;
	slim_int fMethod;
	TPostData fPostData;
};
typedef struct THTTPCacheKey_ THTTPCacheKey;


/*-------------------
	THTTPCacheInfo
 -------------------*/

struct THTTPCacheInfo_ {
	TContentCoreSpecInfo fBase;
	slim_int fHeaderLength;
	slim_int fCertListSize;
	slim_int fContentType;
};
typedef struct THTTPCacheInfo_ THTTPCacheInfo;


/*--------------------
	THTTPCacheEntry
 --------------------*/

struct THTTPCacheEntry_ {
	slim_opaque fHashNext;
	slim_int fFlag;
	THTTPCacheKey fKey;
};
typedef struct THTTPCacheEntry_ THTTPCacheEntry;

#define SLIM_HTTP_CACHE_ENTRYFLAG_DONOTPURGE	0x00000001


/*----------------------
	THTTPLxCacheEntry
 ----------------------*/

struct THTTPLxCacheEntry_ {
	THTTPCacheEntry fBase;	/* inherited: must be the first field */
	slim_int fSticky;		/* sticky. 0 or 1 */
	slim_int fEntrySize;	/* entry size in cache media */
	slim_int fInfoSize;		/* content info size in cache media */
	slim_int fContentSize;	/* content size in cache media */
};
typedef struct THTTPLxCacheEntry_ THTTPLxCacheEntry;


/*---------------
	THTTPCache
 ---------------*/

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
typedef void (*THTTPCache_NotifyProc)(THTTPCache *self, slim_int in_op, slim_pix in_pix);
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */

struct THTTPCache_ {
	TSpecList fList;					/* LRU list of cache entry				*/
										/* this collection should not be global,*/
										/*   because each cache is cleared		*/
										/*   (made empty) by user at any timing */
	THash fHash;						/* hashtable of cache entry				*/
	slim_opaque fHashTable[SLIM_HTTP_CACHE_HASHSIZE];	/* hash table			*/
	slim_int fLimitEntries;				/* entry count in cache media			*/
	slim_int fLimitTotalSize;			/* cache limit total size				*/
	slim_int fLimitContentSize;			/* cache limit content size				*/
	slim_bool fStoreHeader;				/* store header or not					*/

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
	void (*fPrintfProc)(char *in_format, ...);	/* printf procedure				*/
	THTTPCache_NotifyProc fNotifyProc;	/* callback procedure	*/
	slim_char *fName;							/* name of cache				*/
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */	
};

/*-------------
	L1 Cache
 -------------*/

struct THTTPL1CacheEntry_ {
	THTTPLxCacheEntry fBase;	/* inherited: must be the first field */
	TContentCoreSpec fCoreSpec;
};
typedef struct THTTPL1CacheEntry_ THTTPL1CacheEntry;

struct THTTPL1Cache_ {
	THTTPCache fBase;	/* inherited: must be the first field */

	/* cache size info */
	slim_int fTotalSize;				/* a total of (fEntrySize + fInfoSize + fCContentSize) */
	slim_int fTotalContentSize;			/* a total of fCContentSize */
	slim_int fTotalStickedSize;			/* a total of sticked (fEntrySize + fInfoSize + fCContentSize) */
	slim_int fTotalStickedContentSize;	/* a total of sticked fCContentSize */
};


/*-------------
	L2 Cache
 -------------*/

struct THTTPL2CacheEntry_ {
	THTTPLxCacheEntry fBase;	/* inherited: must be the first field */
	THTTPCacheInfo fInfo;
	TString fFileName;			/* cache file name (encode cache entry number) */
	slim_int fCacheEntryNo;		/* unique cache entry number */
};
typedef struct THTTPL2CacheEntry_ THTTPL2CacheEntry;

/*
	if you want to add/del entry in l2Cache(entry), 
	change code in L2Start(), L2FlushFat(), L2GetEntrySize()
*/
struct THTTPL2Cache_ {
	THTTPCache fBase;	/* inherited: must be the first field */

	slim_int fRoundUpUnit;			/* round up unit of disk */
	slim_int fFileNameLength;		/* length of cache file name */
	TString fFatName;				/* fat file name */
	TString fDirName;				/* directory file name */
	TString fExtName;				/* extention name of cache file */
	slim_char fDelimiter;			/* directory delimiter char */
	slim_byte fStart;				/* start or not */
	slim_byte fNeedSyncCacheInfo;	/* need sync or not */
	slim_byte fPadding;

	/* file manipulation function */
	slim_int (*fFileOpenProc)(slim_char *in_fname, slim_int in_flag);
	void (*fFileCloseProc)(slim_int in_desc);
	slim_int (*fFileReadProc)(slim_int in_desc, void *out_buf, slim_int in_len);
	slim_int (*fFileWriteProc)(slim_int in_desc, void *in_buf, slim_int in_len);
	slim_int (*fFileDeleteProc)(slim_char *in_fname);
	slim_int (*fFileDeleteAllProc)(THTTPL2Cache *self);

	/* cache size info */
	slim_int fTotalEntrySize;			/* a total of fEntrySize which is NOT rounded up */
	slim_int fTotalFileSize;			/* a total of (fInfoSize + fCContentSize) which is rounded up */
	slim_int fTotalContentSize;			/* a total of fCContentSize which is NOT rounded up */
	slim_int fTotalStickedFileSize;		/* a total of sticked (fInfoSize + fCContentSize) which is rounded up */
	slim_int fTotalStickedContentSize;	/* a total of sticked fCContentSize which is NOT rounded up */
};


/*----------------------------
	HTTP Redirect URL Cache
 ----------------------------*/

struct THTTPRedirectURLCacheEntry_ {
	slim_opaque fHashNext;
	TURLString fURL;
	TURLString fOriginalURL;
};
typedef struct THTTPRedirectURLCacheEntry_ THTTPRedirectURLCacheEntry;

struct THTTPRedirectURLCache_ {
	TSpecList fList;
	slim_int fLimits;
	THash fHash;
	slim_opaque fHashTable[SLIM_HTTP_CACHE_HASHSIZE];
};
typedef struct THTTPRedirectURLCache_ THTTPRedirectURLCache;


/*-----------------------
	HTTP Content Cache
 -----------------------*/

struct THTTPContentCacheEntry_ {
	THTTPCacheEntry fBase;		/* inherited: must be the first field */
	slim_int fUseCount;
	TContentCoreSpec fCoreSpec;
};
typedef struct THTTPContentCacheEntry_ THTTPContentCacheEntry;

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
/* for fNotifyProc */
enum {
	CACHE_NTFY_ADD,
	CACHE_NTFY_DEL,
	CACHE_NTFY_MOD,
	CACHE_NTFY_UPDATE_LRU,
	CACHE_NTFIES
};
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
typedef void (*THTTPContentCache_NotifyProc)(THTTPContentCache *self, slim_int in_op, slim_pix in_pix);
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */

struct THTTPContentCache_ {
	THTTPL1Cache fL1CacheInfo;	/* HTTP L1 cache			*/
	THTTPL2Cache fL2CacheInfo;	/* HTTP L2 cache			*/
	TBag fBag;					/* bag of content			*/
	THash fHash;				/* hash of content 			*/
	slim_opaque fHashTable[SLIM_HTTP_CACHE_HASHSIZE];	/* hash table			*/
	THTTPRedirectURLCache fRedirectURLCache;

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
	void (*fPrintfProc)(char *in_format, ...);			/* printf procedure		*/
	THTTPContentCache_NotifyProc fNotifyProc;	/* callback procedure	*/
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */
};


/*=================
	HTTP Channel
 =================*/

/*----------------------------
	HTTP Channel Statistics
 ----------------------------*/
#ifdef SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS

#define SLIM_HTTP_ERROR_MAX 7

struct THTTPChannelStatistic_ {
	slim_int fChannels;								/* channel count							*/
	slim_int fCacheHits;							/* cache hit count							*/
	slim_int fRedirects;							/* redirect count							*/
	slim_int fAuthRetries;							/* authentication retry count				*/
	slim_int fStreamErrors[SLIM_HTTP_ERROR_MAX];	/* stream error count						*/
	slim_int fTimeoutSendings;						/* timeout count in sending					*/
	slim_int fTimeoutReceivingHeaders;				/* timeout count in receiving header		*/
	slim_int fTimeoutReceivingEntities;				/* timeout count in receiving entity		*/
	slim_int fPartialContents;						/* partial contents count					*/
};
typedef struct THTTPChannelStatistic_ THTTPChannelStatistic;

#endif /* SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS */


/*----------------------
	THTTPChannelClass
 ----------------------*/

typedef slim_int (*THTTPChannel_ConnectCallback)(THTTPChannel self, TURLString in_url, slim_int in_method,
												 TPostData in_post_data, slim_opaque in_aux);
typedef slim_int (*THTTPChannel_RedirectCallback)(THTTPChannel self, slim_int in_status_code, slim_int in_content_by,
												  slim_int in_methor, TURLString in_url, TURLString in_new_url, slim_opaque in_aux);
typedef slim_int (*THTTPChannel_AuthCallback)(THTTPChannel self, slim_int in_target, slim_int in_type,
											  slim_split_ss *in_challenge_ss, slim_split_ss *in_realm_ss,
											  TURLString in_url, TFixedString in_host, slim_int in_port,
											  slim_opaque in_aux);
typedef slim_int (*THTTPChannel_HeaderReceivedCallback)(iTHTTPChannel *iself, slim_int in_err, slim_opaque in_aux);
typedef void (*THTTPChannel_OnDeleteCallback)(THTTPChannel self, slim_opaque in_arg);

typedef slim_bool (*HTTPChannel_FindCacheProc)(THTTPChannelClass *in_class, THTTPCacheKey *in_key,
											   slim_bool in_resolve_redirect_url, slim_int *inout_cache_type,
											   slim_opaque *out_cache_item_id);
typedef slim_bool (*HTTPChannel_GetCoreSpecInfoProc)(THTTPChannelClass *in_class, slim_int in_cache_type,
													 slim_opaque in_cache_item_id, TContentCoreSpecInfo *out_info);
typedef void (*HTTPChannel_TidyCoreSpecInfoProc)(THTTPChannelClass *in_class, slim_int in_cache_type,
												 slim_opaque in_cache_item_id, TContentCoreSpecInfo *in_info);
typedef slim_bool (*THTTPChannel_UseOrStickCacheProc)(iTHTTPChannel *iself, slim_int in_delta, slim_bool *out_stick);
typedef slim_int (*THTTPChannel_ReadCacheProc)(iTHTTPChannel *iself, slim_bool in_resolve_redirect_url, slim_bool in_validated);
typedef slim_int (*THTTPChannel_DeleteCacheProc)(iTHTTPChannel *iself);
typedef void (*THTTPChannel_CacheMaintenanceProc)(iTHTTPChannel *iself);
typedef slim_int (*HTTPChannel_CacheProgressProc)(THTTPChannelClass *in_class);

typedef slim_int (*HTTPChannel_FetchAuthInfoProc)(TURLString in_url, slim_int *out_type, THTTPAuthInfo *out_info, slim_opaque in_user_data);

struct THTTPChannelClass_ {
	TContentChannelClass fBase;							/* base class 					*/
	TContentClass *fContentClass;						/* Content class				*/
	THTTPStreamClass fStreamClass;						/* HTTP stream class			*/
	THTTPContentCache fCache;							/* HTTP content cache			*/
	slim_int fReadChunk;								/* HTTP read chunk				*/
	slim_int fVersion;									/* HTTP Version 				*/
	TString fAuxHeader;									/* aux request header			*/
	THTTPChannel_ConnectCallback fConnectCallback;		/* pointer to callback function	*/
	slim_opaque fConnectCallbackAux;					/* aux data for callback		*/
	THTTPChannel_RedirectCallback fRedirectCallback;	/* pointer to callback function	*/
	slim_opaque fRedirectCallbackAux;					/* aux data for callback		*/
	THTTPChannel_AuthCallback fAuthCallback;			/* pointer to callback function	*/
	slim_opaque fAuthCallbackAux;						/* aux data for callback		*/
	THTTPChannel_HeaderReceivedCallback fHeaderReceivedCallback;	/* pointer to callback function	*/
	slim_opaque fHeaderReceivedCallbackAux;				/* aux data for callback		*/
	THTTPChannel_OnDeleteCallback fOnDeleteCallback;
	slim_opaque fOnDeleteCallbackArg;
	slim_int fSSLFlag;									/* flag for SSL					*/ 
	slim_int fFlag;
	slim_int fDefaultCacheExpirePeriod;					/* default cache expired period */
	slim_int fHTTPMaxStreams;							/* max number of active HTTP stream */
	slim_int fHTTPStreams;								/* current number of active HTTP stream */

	HTTPChannel_FindCacheProc fFindCacheProc;
	HTTPChannel_GetCoreSpecInfoProc fGetCoreSpecInfoProc;
	HTTPChannel_TidyCoreSpecInfoProc fTidyCoreSpecInfoProc;
	THTTPChannel_UseOrStickCacheProc fUseOrStickCacheProc;
	THTTPChannel_ReadCacheProc fReadCacheProc;
	THTTPChannel_DeleteCacheProc fDeleteCacheProc;
	THTTPChannel_CacheMaintenanceProc fCacheMaintenanceProc;
	HTTPChannel_CacheProgressProc fCacheProgressProc;

	HTTPChannel_FetchAuthInfoProc fFetchAuthInfoProc;
	slim_opaque fExternalAuthDB;

#ifdef SLIM_CONFIG_HTTP_CHANNEL_DEBUG
	void (*fPrintfProc)(char *in_format, ...);			/* printf procedure		*/
#endif /* SLIM_CONFIG_HTTP_CHANNEL_DEBUG */

#ifdef SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS
	THTTPChannelStatistic fStats;						/* statistic					*/
#endif /* SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS */
};

#define SLIM_HTTP_FLAG_PIPELINE						0x00000001
#define SLIM_HTTP_FLAG_READ_GREEDY					0x00000002
#define SLIM_HTTP_FLAG_LOOKUP_HTTPS_CACHE			0x00000004
#define SLIM_HTTP_FLAG_ENABLE_REDIRECT_CALLBACK		0x00000008
#define SLIM_HTTP_FLAG_ENABLE_AUTH_CALLBACK			0x00000010
#define SLIM_HTTP_FLAG_REMOVE_QUERY_FROM_REFERER	0x00000020
#define SLIM_HTTP_FLAG_PASS_SESSION_AUTH_TO_NEXT	0x00000040

	/* temporal fix */
#define SLIM_HTTP_FLAG_ALLOW_CACHE_PARTIAL_ENCODED	0x00000040


/*-----------------
	THTTPChannel
 -----------------*/

enum {
	SLIM_HTTP_VALIDATOR_STR_If_Range = 0,
	SLIM_HTTP_VALIDATOR_STR_Range,
	SLIM_HTTP_VALIDATOR_STR_If_None_Match,
	SLIM_HTTP_VALIDATOR_STR_If_Modified_Since,

	SLIM_HTTP_VALIDATOR_STRS
};

struct iTHTTPChannel_ {
	iTContentChannel fBase;		/* inherited: must be the first field		*/
	THTTPChannel fSelf;			/* handle to itself							*/
	TURLString fURL;			/* URL	(key of hash)						*/
	slim_int fMethod;			/* method	(key of hash)					*/
	slim_int fPostDataLen;		/* length of post data						*/
	THTTPStream fStream;		/* HTTP stream 								*/
	slim_int fResult;			/* result of progress DONE, CONT, ERR		*/
	slim_short fFlag;			/* flag (skip content, redirect, do not cache, inquiring, accept rangas bytes) */
	slim_short fStatusCode;		/* status code of http response				*/
	slim_int fLastSentState;	/* for NotifyStream							*/
	/* content */
	TContentSpec fContentSpec;	/* handle to content spec					*/
	slim_int fCacheFlag;		/* cache control flag						*/
	slim_int fCacheType;		/* type of referred cache					*/
	slim_opaque fCacheItemID;	/* for HTTPCache, pix of content in memory	*/
	TString fValidatorStr[SLIM_HTTP_VALIDATOR_STRS];	/* header values for validation */
	TString fCookieStr;
	slim_int fBytesRecv;
	slim_int fResponseLen;

	slim_opaque fUserData;
};

#define SLIM_HTTP_CHANNEL_FLAG_CHECK_HEADER			0x0001
#define SLIM_HTTP_CHANNEL_FLAG_SKIP_CONTENT			0x0002
#define SLIM_HTTP_CHANNEL_FLAG_REDIRECT				0x0004
#define SLIM_HTTP_CHANNEL_FLAG_AUTH_RETRY			0x0008
#define SLIM_HTTP_CHANNEL_FLAG_WAITFOR_CONNECT_DIALOG	0x0010
#define SLIM_HTTP_CHANNEL_FLAG_WAITFOR_REDIRECT_DIALOG	0x0020
#define SLIM_HTTP_CHANNEL_FLAG_WAITFOR_AUTH_DIALOG	0x0040
#define SLIM_HTTP_CHANNEL_FLAG_VALIDATING			0x0080
#define SLIM_HTTP_CHANNEL_FLAG_ACCEPT_RANGES_BYTES	0x0100
#define SLIM_HTTP_CHANNEL_FLAG_PERSISTENT_CONTENT	0x0200
#define SLIM_HTTP_CHANNEL_FLAG_SSL_V3				0x0400
#define SLIM_HTTP_CHANNEL_FLAG_SSL_V2				0x0800
#define SLIM_HTTP_CHANNEL_FLAG_DELETEASAP			0x1000
#define SLIM_HTTP_CHANNEL_FLAG_SKIP_CACHE_MAINTENANCE	0x2000
#define SLIM_HTTP_CHANNEL_FLAG_CONTENT_ENCODED		0x4000

SLIM_END_C_LINKAGE

#endif /* SLIM_HTTP_H */
