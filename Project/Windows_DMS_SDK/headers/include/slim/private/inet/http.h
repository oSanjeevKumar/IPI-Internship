/*
	http.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/http.h 233   06/05/09 21:22 Nagamati $ */

#ifndef SLIM_HTTP_H_PRIVATE
#define SLIM_HTTP_H_PRIVATE

#include <slim/private/token/hphdr.h>

SLIM_BEGIN_C_LINKAGE

/*---------------
	THTTPCache
 ---------------*/

#ifndef SLIM_CONFIG_USE_HTTP
/* dummy */

/*===============
	HTTP Cache
 ===============*/

/*------------------
	THTTPCacheKey
 ------------------*/

#define THTTPCacheKey_Tidy(iself, in_new)		((void)0)
#define THTTPCacheKey_DeepCopy(iself, in_src)	(slim_false)
#define THTTPCacheKey_Equal(iself, in_key)		(slim_false)

/*--------------------
	THTTPCacheEntry
 --------------------*/

#define THTTPCacheEntry_Tidy(iself, in_new)	((void)0)


/*----------------------
	THTTPContentCache
 ----------------------*/

#define THTTPContentCache_Restart(iself) ((void)0)
#define THTTPContentCache_Find(iself, in_key, in_resolve_redirect_url, out_cache_type) (slim_pix_nil)
#define THTTPContentCache_GetCoreSpecInfo(iself, in_cache_type, in_pix, out_info) (slim_true)
#define THTTPContentCache_Realize(iself, in_key, out_pix, out_spec, in_resolve_redirect_url)	(*(out_pix) = slim_pix_nil, SLIM_E_GENERIC)
#define THTTPContentCache_Use(iself, in_pix, in_use)	(0)
#define THTTPContentCache_SetLimitSize(iself, inout_l1_entries,	inout_l1_total_size, inout_l1_content_size,\
									inout_l2_entries, inout_l2_total_size, inout_l2_content_size) ((void)0)
#define THTTPContentCache_ClearL1LRUEntry(iself)	(slim_true)
#define THTTPContentCache_Clear(iself, in_no_memory_allocate)	(slim_true)
#define THTTPContentCache_ClearL1(iself, in_all)			(slim_true)
#define THTTPContentCache_ClearL2(iself, in_all)			(slim_true)
#define THTTPContentCache_ChangeL2CacheDir(iself, dir_name, dir_len) (SLIM_E_GENERIC)
#define THTTPContentCache_KeepCacheEntry(self, key) (slim_pix_nil)


/*=================
	HTTP Channel
 =================*/

/*---------------------
	THTTPChanneClass
 ---------------------*/

#define HTTPChannel_Initialize(in_class, in_mime_class, in_scheme_class)	(slim_true)
#define HTTPChannel_Finalize(in_class)										((void)0)
#define HTTPChannel_SetContentClass(in_class, in_cont_class)				((void)0)
#define HTTPChannel_SetConnectCallback(in_class, in_cb, in_aux)				((void)0)
#define HTTPChannel_SetRedirectCallback(in_class, in_cb, in_aux)			((void)0)
#define HTTPChannel_SetAuthCallback(in_class, in_cb, in_aux)				((void)0)
#define HTTPChannel_SetHeaderReceivedCallback(in_class, in_cb, in_aux)		((void)0)
#define HTTPChannel_SetOnDeleteCallback(cls, cb, arg)						((void)0)
#define HTTPChannel_SetPipeline(self,val)									((void)0)
#define HTTPChannel_SetEnableRedirectCallback(self,val)						((void)0)
#define HTTPChannel_SetEnableAuthCallback(self,val)							((void)0)


/*-----------------
	THTTPChannel
 -----------------*/

#define THTTPChannel_ConfirmConnectDialog(self)								((void)0)
#define THTTPChannel_AbortConnectDialog(self)								((void)0)
#define THTTPChannel_ConfirmRedirectDialog(self, in_method, in_new_url)		((void)0)
#define THTTPChannel_AbortRedirectDialog(self)								((void)0)
#define THTTPChannel_IsReposting(self)										(slim_false)
#define THTTPChannel_ConfirmAuthDialogX( \
			self, in_type, in_target, in_challenge_ss, in_realm_ss, \
			in_user, in_pass, in_proxy_host, in_proxy_port,	in_keep_user, in_keep_pass) ((void)0)
#define THTTPChannel_AbortAuthDialog(self)									((void)0)

#else /* defined(SLIM_CONFIG_USE_HTTP) */


/*===============
	HTTP Cache
 ===============*/

/*--------------------
	Flag Operations
 --------------------*/

#define SLIM_HTCACHE_CHK_FLAG(flag, val)		(((flag) & (val)) == (val))
#define SLIM_HTCACHE_SET_FLAG(flag, val, set)	((flag) = ((set) ? ((flag) | (val)) : ((flag) & ~(val))))


/*------------------
	THTTPCacheKey
 ------------------*/


#define THTTPCacheKey_URL(iself)			((iself)->fURL)
#define THTTPCacheKey_Method(iself)			((iself)->fMethod)
#define THTTPCacheKey_PostData(iself)		((iself)->fPostData)
#define THTTPCacheKey_URLLen(iself)			((iself)->fURL != slim_nil ? TURLString_Length((iself)->fURL) : 0)
#define THTTPCacheKey_PostDataLen(iself)	((iself)->fPostData ? 4 * 3 + TPostData_DataSize((iself)->fPostData) : 0)

/*-------------------
	THTTPCacheInfo
 -------------------*/


#define THTTPCacheInfo_HeaderLength(iself)	((iself)->fHeaderLength)
#define THTTPCacheInfo_ContentLength(iself)	((iself)->fBase.fContentLength)
#define THTTPCacheInfo_OriginLength(iself)	((iself)->fBase.fOriginLength)
#define THTTPCacheInfo_CertListSize(iself)	((iself)->fCertListSize)

#define THTTPCacheInfo_ValidatorETagLength(iself) \
	((iself)->fBase.fValidatorETag != slim_nil ? TString_Length((iself)->fBase.fValidatorETag) : 0)

#define THTTPCacheInfo_ValidatorDateLength(iself) \
	((iself)->fBase.fValidatorDate != slim_nil ? TString_Length((iself)->fBase.fValidatorDate) : 0)

#define THTTPCacheInfo_IsPartial(iself)						SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_PARTIAL)
#define THTTPCacheInfo_IsValidatedPerSession(iself)			SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION)
#define THTTPCacheInfo_IsHistoryOnly(iself)					SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_HISTORY_ONLY)
#define THTTPCacheInfo_IsMemoryOnly(iself)					SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_MEMORY_ONLY)
#define THTTPCacheInfo_IsViaProxy(iself)					SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_VIA_PROXY)
#define THTTPCacheInfo_IsDeleteASAP(iself)					SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_DELETE_ASAP)
#define THTTPCacheInfo_IsExpired(iself)						SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_EXPIRED)
#define THTTPCacheInfo_IsForwardLock(iself)					SLIM_HTCACHE_CHK_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_FORWARD_LOCK)
#define THTTPCacheInfo_SetPartial(iself, set)				SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_PARTIAL, set)
#define THTTPCacheInfo_SetValidatedPerSession(iself, set)	SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION, set)
#define THTTPCacheInfo_SetHistoryOnly(iself, set)			SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_HISTORY_ONLY, set)
#define THTTPCacheInfo_SetMemoryOnly(iself, set)			SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_MEMORY_ONLY, set)
#define THTTPCacheInfo_SetViaProxy(iself, set)				SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_VIA_PROXY, set)
#define THTTPCacheInfo_SetDeleteASAP(iself, set)			SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_DELETE_ASAP, set)
#define THTTPCacheInfo_SetExpired(iself, set)				SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_EXPIRED, set)
#define THTTPCacheInfo_SetForwardLock(iself, set)			SLIM_HTCACHE_SET_FLAG((iself)->fBase.fFlag, SLIM_CORESPEC_FLAG_FORWARD_LOCK, set)

#define THTTPCacheInfo_SetContentLength(iself, len)	((iself)->fBase.fContentLength = (len))
#define THTTPCacheInfo_SetOriginLength(iself, len)	((iself)->fBase.fOriginLength = (len))
#define THTTPCacheInfo_SetExpires(iself, expires)	((iself)->fBase.fExpires = *(expires))
#define THTTPCacheInfo_SetExpireType(iself, type)	((iself)->fBase.fExpireType = (type))
#define THTTPCacheInfo_SetContentType(iself, type)	((iself)->fContentType = (type))


/*--------------------
	THTTPCacheEntry
 --------------------*/


#define THTTPCacheEntry_Flag(iself)			((iself)->fFlag)
#define THTTPCacheEntry_Key(iself)			(&(iself)->fKey)

#define THTTPCacheEntry_URL(iself)			(THTTPCacheKey_URL(THTTPCacheEntry_Key(iself)))
#define THTTPCacheEntry_Method(iself)		(THTTPCacheKey_Method(THTTPCacheEntry_Key(iself)))
#define THTTPCacheEntry_PostData(iself)		(THTTPCacheKey_URL(THTTPCacheEntry_Key(iself)))
#define THTTPCacheEntry_URLLen(iself)		(THTTPCacheKey_URLLen(THTTPCacheEntry_Key(iself)))
#define THTTPCacheEntry_PostDataLen(iself)	(THTTPCacheKey_PostDataLen(THTTPCacheEntry_Key(iself)))

#define THTTPCacheEntry_IsDoNotPurge(iself)			SLIM_HTCACHE_CHK_FLAG((iself)->fFlag, SLIM_HTTP_CACHE_ENTRYFLAG_DONOTPURGE)
#define THTTPCacheEntry_SetDoNotPurge(iself, set)	SLIM_HTCACHE_SET_FLAG((iself)->fFlag, SLIM_HTTP_CACHE_ENTRYFLAG_DONOTPURGE, set)


/*---------------
	THTTPCache
 ---------------*/

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
#define THTTP_CACHE_DP(iself, arg)			{if ((iself)->fPrintfProc) {(*(iself)->fPrintfProc) arg ;}}
#define	THTTP_CACHE_NTFY(iself, op, pix)	{if ((iself)->fNotifyProc) {(*(iself)->fNotifyProc)(iself, op, pix);}}
#else
#define THTTPCache_DebugDump(iself)			((void)0)
#define THTTP_CACHE_DP(iself, arg) 			((void)0)
#define	THTTP_CACHE_NTFY(iself, op, pix)	((void)0)
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */


/*----------------------
	THTTPContentCache
 ----------------------*/

#ifdef SLIM_CONFIG_HTTP_CACHE_DEBUG
#define THTTP_CONTENT_CACHE_DP(iself, arg)			{if ((iself)->fPrintfProc) {(*(iself)->fPrintfProc) arg ;}}
#define	THTTP_CONTENT_CACHE_NTFY(iself, op, pix)	{if ((iself)->fNotifyProc) {(*(iself)->fNotifyProc)(iself, op, pix);}}
#else
#define THTTP_CONTENT_CACHE_DP(iself, arg)			((void)0)
#define	THTTP_CONTENT_CACHE_NTFY(iself, op, pix)	((void)0)
#endif /* SLIM_CONFIG_HTTP_CACHE_DEBUG */


/*=================
	HTTP Channel
 =================*/

/*----------------------
	THTTPChannelClass
 ----------------------*/

#define HTTPChannel_SetContentClass(cls, cntcls) ((cls)->fContentClass = (cntcls))
#define HTTPChannel_SetOnDeleteCallback(cls, cb, arg) ((cls)->fOnDeleteCallback = (cb), (cls)->fOnDeleteCallbackArg = (arg))

/* flag operation */
#define HTTPChannel_SetPipeline(cls,val)					SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_PIPELINE,(val))
#define HTTPChannel_SetReadGreedy(cls,val)					SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_READ_GREEDY,(val))
#define HTTPChannel_SetLookupHTTPSCache(cls,val)			SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_LOOKUP_HTTPS_CACHE,(val))
#define HTTPChannel_SetEnableRedirectCallback(cls,val)		SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_ENABLE_REDIRECT_CALLBACK,(val))
#define HTTPChannel_SetEnableAuthCallback(cls,val)			SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_ENABLE_AUTH_CALLBACK,(val))
#define HTTPChannel_SetRemoveQueryFromReferer(cls,val)		SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_REMOVE_QUERY_FROM_REFERER,(val))
#define HTTPChannel_SetAllowCachePartialEncoded(cls,val)	SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_ALLOW_CACHE_PARTIAL_ENCODED,(val))
#define HTTPChannel_SetPassSessionAuthToNext(cls,val)		SLIM_FLAG_OP((cls),SLIM_HTTP_FLAG_PASS_SESSION_AUTH_TO_NEXT,(val))

#define HTTPChannel_IsPipeline(cls)							SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_PIPELINE)
#define HTTPChannel_IsReadGreedy(cls)						SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_READ_GREEDY)
#define HTTPChannel_IsLookupHTTPSCache(cls)					SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_LOOKUP_HTTPS_CACHE)
#define HTTPChannel_IsEnableRedirectCallback(cls)			SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_ENABLE_REDIRECT_CALLBACK)
#define HTTPChannel_IsEnableAuthCallback(cls)				SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_ENABLE_AUTH_CALLBACK)
#define HTTPChannel_IsRemoveQueryFromReferer(cls)			SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_REMOVE_QUERY_FROM_REFERER)
#define HTTPChannel_IsAllowCachePartialEncoded(cls)			SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_ALLOW_CACHE_PARTIAL_ENCODED)
#define HTTPChannel_IsPassSessionAuthToNext(cls)			SLIM_FLAG_CK((cls),SLIM_HTTP_FLAG_PASS_SESSION_AUTH_TO_NEXT)

#ifdef SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS
#define HTTP_CHANNEL_STATS_INC_CHANNELS(in_class)					 {(in_class)->fStats.fChannels++;}
#define HTTP_CHANNEL_STATS_INC_CACHE_HITS(in_class)				 	 {(in_class)->fStats.fCacheHits++;}
#define HTTP_CHANNEL_STATS_INC_REDIRECTS(in_class)					 {(in_class)->fStats.fRedirects++;}
#define HTTP_CHANNEL_STATS_INC_AUTH_RETRIES(in_class)				 {(in_class)->fStats.fAuthRetries++;}
#define HTTP_CHANNEL_STATS_INC_STREAM_ERRORS(in_class, i)		  	 {(in_class)->fStats.fStreamErrors[((0<=i) && (i<SLIM_HTTP_ERROR_MAX))?i:0]++;}
#define HTTP_CHANNEL_STATS_INC_TIMEOUT_SENDINGS(in_class)			 {(in_class)->fStats.fTimeoutSendings++;}
#define HTTP_CHANNEL_STATS_INC_TIMEOUT_RECEIVING_HEADERS(in_class)	 {(in_class)->fStats.fTimeoutReceivingHeaders++;}
#define HTTP_CHANNEL_STATS_INC_TIMEOUT_RECEIVING_ENTITIES(in_class)  {(in_class)->fStats.fTimeoutReceivingEntities++;}
#define HTTP_CHANNEL_STATS_INC_PARTIAL_CONTENTS(in_class)			 {(in_class)->fStats.fPartialContents++;}
#else
#define HTTPChannel_ShowStatistic(in_class)							 ((void)0)
#define HTTP_CHANNEL_STATS_INC_CHANNELS(in_class)					 ((void)0)
#define HTTP_CHANNEL_STATS_INC_CACHE_HITS(in_class)					 ((void)0)
#define HTTP_CHANNEL_STATS_INC_REDIRECTS(in_class)					 ((void)0)
#define HTTP_CHANNEL_STATS_INC_AUTH_RETRIES(in_class)				 ((void)0)
#define HTTP_CHANNEL_STATS_INC_STREAM_ERRORS(in_class, i)			 ((void)0)
#define HTTP_CHANNEL_STATS_INC_TIMEOUT_SENDINGS(in_class)			 ((void)0)
#define HTTP_CHANNEL_STATS_INC_TIMEOUT_RECEIVING_HEADERS(in_class)	 ((void)0)
#define HTTP_CHANNEL_STATS_INC_TIMEOUT_RECEIVING_ENTITIES(in_class)  ((void)0)
#define HTTP_CHANNEL_STATS_INC_PARTIAL_CONTENTS(in_class)			 ((void)0)
#endif /* SLIM_CONFIG_HTTP_CHANNEL_RECORD_STATS */


/*-----------------
	THTTPChannel
 -----------------*/

#define SLIM_HTTP_CACHE_SUBTYPE_L0	0x00010000
#define SLIM_HTTP_CACHE_SUBTYPE_L1	0x00020000
#define SLIM_HTTP_CACHE_SUBTYPE_L2	0x00040000
#define SLIM_HTTP_CACHE_TYPE_MEMORY	(SLIM_CONTENT_CACHE_TYPE_HTTPCACHE|SLIM_HTTP_CACHE_SUBTYPE_L0)
#define SLIM_HTTP_CACHE_TYPE_L1		(SLIM_CONTENT_CACHE_TYPE_HTTPCACHE|SLIM_HTTP_CACHE_SUBTYPE_L1)
#define SLIM_HTTP_CACHE_TYPE_L2		(SLIM_CONTENT_CACHE_TYPE_HTTPCACHE|SLIM_HTTP_CACHE_SUBTYPE_L2)

#define THTTPChannel_Lock(self) ((iTHTTPChannel *)slim_handle_lock((slim_handle)(self)))
#define THTTPChannel_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define THTTPChannel_Locate(self) ((iTHTTPChannel *)slim_handle_locate((slim_handle)(self)))
#define THTTPChannel_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))

#define THTTPChannel_ConfirmAuthDialog(self,in_type,in_target,in_challenge_ss,in_realm_ss,\
									   in_user,in_pass,in_proxy_host,in_proxy_port)  \
        THTTPChannel_ConfirmAuthDialogX((self),(in_type),(in_target),(in_challenge_ss),(in_realm_ss),\
								(in_user),(in_pass),(in_proxy_host),(in_proxy_port), slim_false, slim_false)

#define iTHTTPChannel_CacheMode(iself) ((iself)->fCacheFlag & SLIM_CONTENT_CACHEMASK)
#define iTHTTPChannel_By(iself) ((iself)->fCacheFlag & SLIM_CONTENT_BYMASK)
#define iTHTTPChannel_IsDoingHistory(iself) (iTHTTPChannel_By(iself) & SLIM_CONTENT_BY_HISTORY)
#define iTHTTPChannel_IsDoingReload(iself) \
 (iTHTTPChannel_By(iself) & (SLIM_CONTENT_BY_RELOAD|SLIM_CONTENT_BY_REFRESH))
#define iTHTTPChannel_WritingCacheIsInhibited(iself) ((iself)->fCacheFlag & SLIM_CONTENT_INHIBIT_WRITE_CACHE)

#define iTHTTPChannel_SetCheckHeader(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_CHECK_HEADER,(val))
#define iTHTTPChannel_SetSkipContent(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_SKIP_CONTENT,(val))
#define iTHTTPChannel_SetRedirect(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_REDIRECT,(val))
#define iTHTTPChannel_SetAuthRetry(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_AUTH_RETRY,(val))
#define iTHTTPChannel_SetWaitforConnectDialog(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_WAITFOR_CONNECT_DIALOG,(val))
#define iTHTTPChannel_SetWaitforRedirectDialog(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_WAITFOR_REDIRECT_DIALOG,(val))
#define iTHTTPChannel_SetWaitforAuthDialog(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_WAITFOR_AUTH_DIALOG,(val))
#define iTHTTPChannel_SetValidating(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_VALIDATING,(val))
#define iTHTTPChannel_SetAcceptRangesBytes(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_ACCEPT_RANGES_BYTES,(val))
#define iTHTTPChannel_SetPersistentContent(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_PERSISTENT_CONTENT,(val))
#define iTHTTPChannel_SetSSLV3(iself,val) 			SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_SSL_V3,(val))
#define iTHTTPChannel_SetSSLV2(iself,val) 			SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_SSL_V2,(val))
#define iTHTTPChannel_SetDeleteASAP(iself,val) 		SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_DELETEASAP,(val))
#define iTHTTPChannel_SetSkipCacheMaintenance(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_SKIP_CACHE_MAINTENANCE,(val))
#define iTHTTPChannel_SetContentEncoded(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_CHANNEL_FLAG_CONTENT_ENCODED,(val))

#define iTHTTPChannel_IsCheckHeader(iself) 			SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_CHECK_HEADER)
#define iTHTTPChannel_IsSkipContent(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_SKIP_CONTENT)
#define iTHTTPChannel_IsRedirect(iself)				SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_REDIRECT)
#define iTHTTPChannel_IsAuthRetry(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_AUTH_RETRY)
#define iTHTTPChannel_IsWaitforConnectDialog(iself)	SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_WAITFOR_CONNECT_DIALOG)
#define iTHTTPChannel_IsWaitforRedirectDialog(iself)	SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_WAITFOR_REDIRECT_DIALOG)
#define iTHTTPChannel_IsWaitforAuthDialog(iself)	SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_WAITFOR_AUTH_DIALOG)
#define iTHTTPChannel_IsValidating(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_VALIDATING)
#define iTHTTPChannel_IsAcceptRangesBytes(iself)	SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_ACCEPT_RANGES_BYTES)
#define iTHTTPChannel_IsPersistentContent(iself) 	SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_PERSISTENT_CONTENT)
#define iTHTTPChannel_IsSSLV3(iself) 				SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_SSLV3)
#define iTHTTPChannel_IsSSLV2(iself) 				SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_SSLV2)
#define iTHTTPChannel_IsDeleteASAP(iself) 			SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_DELETEASAP)
#define iTHTTPChannel_IsSkipCacheMaintenance(iself) 	SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_SKIP_CACHE_MAINTENANCE)
#define iTHTTPChannel_IsContentEncoded(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_CHANNEL_FLAG_CONTENT_ENCODED)

#endif /* SLIM_CONFIG_USE_HTTP */

SLIM_END_C_LINKAGE

#endif /* SLIM_HTTP_H */
