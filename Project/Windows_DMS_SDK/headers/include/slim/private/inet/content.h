/*
	content.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/content.h 340   06/08/16 16:38 Siu $ */

#ifndef SLIM_CONTENT_H_PRIVATE
#define SLIM_CONTENT_H_PRIVATE

#include <slim/private/inet/drm.h>

SLIM_BEGIN_C_LINKAGE

/*
 * Content Authentication Information
 */
#define TContentAuth_Lock(self)		((iTContentAuth *)slim_handle_lock((slim_handle)(self)))
#define TContentAuth_Unlock(self)	(slim_handle_unlock((slim_handle)(self)))
#define TContentAuth_Locate(self)	((iTContentAuth *)slim_handle_locate((slim_handle)(self)))
#define TContentAuth_Unlocate(self)	(slim_handle_unlocate((slim_handle)(self)))

#define TContentAuth_Flag(self)		(slim_handle_peek_int((slim_handle)(self), SLIM_OFFSETOF(iTContentAuth, fFlag)))

#define TContentAuth_IsAvail(self)	((TContentAuth_Flag(self) & SLIM_CNTAUTH_FLAG_AVAIL) == SLIM_CNTAUTH_FLAG_AVAIL)

/*
 * ContentRequest
 */

#define TContentRequest_Class(self) ((self)->fClass)
#define TContentRequest_Flag(self) ((self)->fFlag)
#define TContentRequest_CacheMode(self) ((self)->fFlag & SLIM_CONTENT_CACHEMASK)
#define TContentRequest_Method(self) ((self)->fMethod)
#define TContentRequest_Fragment(self) ((self)->fFragment)
#define TContentRequest_URLCharSet(self) ((self)->fURLCharSet)
#define TContentRequest_FragmentCharSet(self) ((self)->fFragmentCharSet)
#define TContentRequest_SchemeID(self) ((self)->fSchemeID)
#define TContentRequest_RefererX(self) ((self)->fReferer)
#define TContentRequest_PostEncoding(self) ((self)->fPostData ? TPostData_Encoding((self)->fPostData) : SLIM_CONTENT_POST_MULTIPART)
#define TContentRequest_PostData(self) ((self)->fPostData)
#define TContentRequest_PostDataLen(self) ((self)->fPostDataLen)
#define TContentRequest_IsFormSubmit(self) (((self)->fRequestTypeFlag) & SLIM_CONTENT_REQUEST_FORM_SUBMIT)
#define TContentRequest_IsFragmentJump(self) (((self)->fRequestTypeFlag) & SLIM_CONTENT_REQUEST_FRAGMENT_JUMP)
#define TContentRequest_IsShareInhibited(self) (((self)->fRequestTypeFlag) & SLIM_CONTENT_REQUEST_INHIBIT_SHARE)
#define TContentRequest_RefererContent(self) ((self)->fRefererContent)
#define TContentRequest_HTTPHeader(self) ((self)->fHTTPHeader)
#define TContentRequest_PageAuth(self) ((self)->fPageAuth)
#define TContentRequest_ProxyAuth(self) ((self)->fProxyAuth)

/* NOTE: these 4 macros are only for Content related-classes */
#define TContentRequest_ForgetPostData(self) ((self)->fPostData = slim_nil, (void)0)
#define TContentRequest_ForgetHTTPHeader(self) ((self)->fHTTPHeader = slim_nil, (void)0)
#define TContentRequest_ForgetPageAuth(self) ((void)((self)->fPageAuth = slim_nil))
#define TContentRequest_ForgetProxyAuth(self) ((void)((self)->fProxyAuth = slim_nil))

#define SLIM_CONTREQ_CMP_REFERER	0x00000001
#define SLIM_CONTREQ_CMP_HTTPHEADER	0x00000002
#define SLIM_CONTREQ_CMP_ISFORM	0x00000004

#define TContentRequest_AddHTTPHeaderByID(req, ID, val, vlen) TContentRequest_AddHTTPHeaderX((req), (slim_opaque)(ID), -1, (val), (vlen))

#define TContentRequest_SetFlag(self, flag) ((self)->fFlag = (flag))
#define TContentRequest_SetCacheMode(self, mode) {(self)->fFlag = (((self)->fFlag & ~SLIM_CONTENT_CACHEMASK) | (mode));}

#define TContentRequest_SetQuery(self, in_query) TContentRequest_SetQueryX((self), (in_query), slim_false)
#define TContentRequest_AddQuery(self, in_query) TContentRequest_SetQueryX((self), (in_query), slim_true)

/*
 * ContentChannel
 */

#define SLIM_RETRIEVER_FLAG_BY_HISTORY				0x00000001
#define SLIM_RETRIEVER_FLAG_RESOLVE_REDIRECT_URL	0x00000002
#define SLIM_RETRIEVER_FLAG_WITHOUT_CACHE			0x00000004

enum {
	SLIM_CONTENT_RETRIEVER_CHANNEL = 0,
	SLIM_CONTENT_RETRIEVER_VALIDATOR,
	SLIM_CONTENT_RETRIEVER_CACHE,
	SLIM_CONTENT_RETRIEVER_NONE,
	SLIM_CONTENT_RETRIEVERS
};

#define SLIM_CONTENT_SIGREOPEN	(1 << SLIM_POLL_SIGSHIFT)

/*
 * ContentCoreSpec
 */

#define SLIM_CORESPEC_FLAG_NONE						0x00000000
#define SLIM_CORESPEC_FLAG_VIA_PROXY				0x00000001
#define SLIM_CORESPEC_FLAG_HISTORY_ONLY				0x00000002
#define SLIM_CORESPEC_FLAG_MEMORY_ONLY				0x00000004
#define SLIM_CORESPEC_FLAG_DEFER_PERSISTENT			0x00000008
#define SLIM_CORESPEC_FLAG_PARTIAL					0x00000010
#define SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION	0x00000020
#define SLIM_CORESPEC_FLAG_DELETE_ASAP				0x00000040
#define SLIM_CORESPEC_FLAG_EXPIRED					0x00000080
#define SLIM_CORESPEC_FLAG_FORWARD_LOCK				0x00000100

enum {
	SLIM_CONTENT_EXPIRE_NONE = 0,
	SLIM_CONTENT_EXPIRE_VALID,
	SLIM_CONTENT_EXPIRE_MUST_REVALIDATE,
	SLIM_CONTENT_EXPIRES
};


#define TContentCoreSpec_Lock(self)				((iTContentCoreSpec *)slim_handle_lock((slim_handle)self))
#define TContentCoreSpec_Unlock(self)			(slim_handle_unlock((slim_handle)self))
#define TContentCoreSpec_Locate(self)			((iTContentCoreSpec *)slim_handle_locate((slim_handle)self))
#define TContentCoreSpec_Unlocate(self)			(slim_handle_unlocate((slim_handle)self))

#define TContentCoreSpec_PeekPtr(self, field)	(slim_handle_peek_ptr((slim_handle)(self), SLIM_OFFSETOF(iTContentCoreSpec, field)))
#define TContentCoreSpec_PeekInt(self, field)	(slim_handle_peek_int((slim_handle)(self), SLIM_OFFSETOF(iTContentCoreSpec, field)))
#define TContentCoreSpec_PeekShort(self, field)	(slim_handle_peek_short((slim_handle)(self), SLIM_OFFSETOF(iTContentCoreSpec, field)))

#define TContentCoreSpec_Flag(self)				(TContentCoreSpec_PeekInt((self), fFlag))
#define TContentCoreSpec_CurrentLength(self)	(TContentCoreSpec_PeekInt((self), fCurrentLength))
#define TContentCoreSpec_ContentLength(self)	(TContentCoreSpec_PeekInt((self), fContentLength))
#define TContentCoreSpec_OriginLength(self)		(TContentCoreSpec_PeekInt((self), fOriginLength))
#define TContentCoreSpec_ContentType(self)		(TContentCoreSpec_PeekInt((self), fContentType))
#define TContentCoreSpec_Header(self)			((TString)TContentCoreSpec_PeekPtr((self), fHeader))
#define TContentCoreSpec_Content(self)			((slim_vhandle)TContentCoreSpec_PeekPtr((self), fContent))	/* Ugh!: encapsulation violation */
#define TContentCoreSpec_CertList(self)			((TCertList)TContentCoreSpec_PeekPtr((self), fCertList))
#define TContentCoreSpec_ValidatorETag(self)	((TString)TContentCoreSpec_PeekPtr((self), fValidatorETag))
#define TContentCoreSpec_ValidatorDate(self)	((TString)TContentCoreSpec_PeekPtr((self), fValidatorDate))

#define TContentCoreSpec_CheckFlag(self, flag)			((TContentCoreSpec_Flag((self)) & (flag)) == (flag))
#define TContentCoreSpec_IsViaProxy(self)				(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_VIA_PROXY))
#define TContentCoreSpec_IsHistoryOnly(self)			(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_HISTORY_ONLY))
#define TContentCoreSpec_IsMemoryOnly(self)				(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_MEMORY_ONLY))
#define TContentCoreSpec_IsDeferPersistent(self)		(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_DEFER_PERSISTENT))
#define TContentCoreSpec_IsPartial(self)				(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_PARTIAL))
#define TContentCoreSpec_IsValidatedPerSession(self)	(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION))
#define TContentCoreSpec_IsDeleteASAP(self)				(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_DELETE_ASAP))
#define TContentCoreSpec_IsExpired(self)				(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_EXPIRED))
#define TContentCoreSpec_IsForwardLock(self)			(TContentCoreSpec_CheckFlag((self), SLIM_CORESPEC_FLAG_FORWARD_LOCK))

#define TContentCoreSpec_SetViaProxy(self, set)				(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_VIA_PROXY, (set)))
#define TContentCoreSpec_SetHistoryOnly(self, set)			(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_HISTORY_ONLY, (set)))
#define TContentCoreSpec_SetMemoryOnly(self, set)			(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_MEMORY_ONLY, (set)))
#define TContentCoreSpec_SetDeferPersistent(self, set)		(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_DEFER_PERSISTENT, (set)))
#define TContentCoreSpec_SetPartial(self, set)				(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_PARTIAL, (set)))
#define TContentCoreSpec_SetValidatedPerSession(self, set)	(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION, (set)))
#define TContentCoreSpec_SetDeleteASAP(self, set)			(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_DELETE_ASAP, (set)))
#define TContentCoreSpec_SetExpired(self, set)				(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_EXPIRED, (set)))
#define TContentCoreSpec_SetForwardLock(self, set)			(TContentCoreSpec_SetFlag((self), SLIM_CORESPEC_FLAG_FORWARD_LOCK, (set)))

#define TContentCoreSpec_SetExpires(self, expires)	(TContentCoreSpec_SetExpiresX((self), SLIM_CONTENT_EXPIRE_VALID, (expires)))
#define TContentCoreSpec_SetRevalidate(self)		(TContentCoreSpec_SetExpiresX((self), SLIM_CONTENT_EXPIRE_MUST_REVALIDATE, slim_nil))

#define TContentCoreSpec_HeaderLength(iself) \
	(TContentCoreSpec_Header(iself) != slim_nil ? TString_Length(TContentCoreSpec_Header(iself)) : 0)
#define TContentCoreSpec_CertListSize(iself) \
	(TContentCoreSpec_CertList(iself) != slim_nil ? TCertList_SerializeSize(TContentCoreSpec_CertList(iself)) : 0)
#define TContentCoreSpec_ValidatorETagLength(iself) \
	(TContentCoreSpec_ValidatorETag(iself) != slim_nil ? TString_Length(TContentCoreSpec_ValidatorETag(iself)) : 0)
#define TContentCoreSpec_ValidatorDateLength(iself) \
	(TContentCoreSpec_ValidatorDate(iself) != slim_nil ? TString_Length(TContentCoreSpec_ValidatorDate(iself)) : 0)

/*
 * ContentCoreSpecInfo
 */

#define TContentCoreSpecInfo_Flag(self)							((self)->fFlag)
#define TContentCoreSpecInfo_Time(self, time)					(*(time) = (self)->fTime)
#define TContentCoreSpecInfo_ContentLength(self)				((self)->fContentLength)
#define TContentCoreSpecInfo_OriginLength(self)					((self)->fOriginLength)
#define TContentCoreSpecInfo_ValidatorETag(self)				((self)->fValidatorETag)
#define TContentCoreSpecInfo_ValidatorDate(self)				((self)->fValidatorDate)
#define TContentCoreSpecInfo_Expires(self, time)				(*(time) = (self)->fExpires)
#define TContentCoreSpecInfo_ExpireType(self)					((self)->fExpireType)

#define TContentCoreSpecInfo_SetTime(self, time)				((self)->fTime = *(time))
#define TContentCoreSpecInfo_SetContentLength(self, len)		((self)->fContentLength = (len))
#define TContentCoreSpecInfo_SetOriginLength(self, len)			((self)->fOriginLength = (len))
#define TContentCoreSpecInfo_SetValidatorETag(self, etag)		((self)->fValidatorETag = (etag))
#define TContentCoreSpecInfo_SetValidatorDate(self, date)		((self)->fValidatorDate = (date))
#define TContentCoreSpecInfo_SetExpires(self, time)				((self)->fExpires = *(time))
#define TContentCoreSpecInfo_SetExpireType(self, type)			((self)->fExpireType = (type))

#define TContentCoreSpecInfo_CheckFlag(self, flag)				(((self)->fFlag & (flag)) == (flag))
#define TContentCoreSpecInfo_IsViaProxy(self)					(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_VIA_PROXY))
#define TContentCoreSpecInfo_IsHistoryOnly(self)				(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_HISTORY_ONLY))
#define TContentCoreSpecInfo_IsMemoryOnly(self)					(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_MEMORY_ONLY))
#define TContentCoreSpecInfo_IsDeferPersistent(self)			(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_DEFER_PERSISTENT))
#define TContentCoreSpecInfo_IsPartial(self)					(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_PARTIAL))
#define TContentCoreSpecInfo_IsValidatedPerSession(self)		(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION))
#define TContentCoreSpecInfo_IsDeleteASAP(self)					(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_DELETE_ASAP))
#define TContentCoreSpecInfo_IsExpired(self)					(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_EXPIRED))
#define TContentCoreSpecInfo_IsForwardLock(self)				(TContentCoreSpecInfo_CheckFlag((self), SLIM_CORESPEC_FLAG_FORWARD_LOCK))

#define TContentCoreSpecInfo_SetFlag(self, flag, set)			((self)->fFlag = (set) ? ((self)->fFlag | (flag)) : ((self)->fFlag & ~(flag)))
#define TContentCoreSpecInfo_SetViaProxy(self, set)				(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_VIA_PROXY, (set)))
#define TContentCoreSpecInfo_SetHistoryOnly(self, set)			(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_HISTORY_ONLY, (set)))
#define TContentCoreSpecInfo_SetMemoryOnly(self, set)			(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_MEMORY_ONLY, (set)))
#define TContentCoreSpecInfo_SetDeferPersistent(self, set)		(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_DEFER_PERSISTENT, (set)))
#define TContentCoreSpecInfo_SetPartial(self, set)				(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_PARTIAL, (set)))
#define TContentCoreSpecInfo_SetValidatedPerSession(self, set)	(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_VALIDATED_PER_SESSION, (set)))
#define TContentCoreSpecInfo_SetDeleteASAP(self, set)			(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_DELETE_ASAP, (set)))
#define TContentCoreSpecInfo_SetExpired(self, set)				(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_EXPIRED, (set)))
#define TContentCoreSpecInfo_SetForwardLock(self, set)			(TContentCoreSpecInfo_SetFlag((self), SLIM_CORESPEC_FLAG_FORWARD_LOCK, (set)))

/*
 * ContentSpecList
 */
#define SLIM_CONTSPCLIST_FLAG_INACTIVE				0x00000001
#define SLIM_CONTSPCLIST_FLAG_INHIBIT_SHARE			0x00000002

#define TContentSpecList_GetItem(self,pix,spec) TTree_GetItem(&(self)->fList,(pix),(spec),sizeof(TContentSpec))
#define TContentSpecList_DoneSpecPix(self) ((self)->fDoneSpecPix)
#define TContentSpecList_Deactivate(self,spec) TContentSpecList_ChangeState((self),(spec),slim_true)
#define TContentSpecList_Activate(self,spec) TContentSpecList_ChangeState((self),(spec),slim_false)

/*
 * ContentSpec
 */

#define SLIM_CONTENT_CACHE_TYPE_NONE			0x00000000
#define SLIM_CONTENT_CACHE_TYPE_ANON			0x00000001
#define SLIM_CONTENT_CACHE_TYPE_HTTPCACHE		0x00000002
#define SLIM_CONTENT_CACHE_TYPE_PAGESAVECACHE	0x00000004
#define SLIM_CONTENT_CACHE_TYPE_EXTERNAL		0x00000008

#define SLIM_CONTENT_CACHE_TYPE_MASK			0x0000FFFF
#define SLIM_CONTENT_CACHE_SUBTYPE_MASK			0xFFFF0000

#define ContentSpec_New0() ((TContentSpec)slim_handle_zeroalloc(sizeof(iTContentSpec)))
#define TContentSpec_Delete0(self) (slim_handle_free((slim_handle)(self)))

/* ContentSpec Method */

#define TContentSpec_Lock(self)		((iTContentSpec *)slim_handle_lock((slim_handle)(self)))
#define TContentSpec_Unlock(self)	(slim_handle_unlock((slim_handle)(self)))
#define TContentSpec_Locate(self)	((iTContentSpec *)slim_handle_locate((slim_handle)(self)))
#define TContentSpec_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))
#define TContentSpec_GetPtr(self, off) (slim_handle_peek_ptr((slim_handle)(self), (off)))
#define TContentSpec_GetInt(self, off) (slim_handle_peek_int((slim_handle)(self), (off)))
#define TContentSpec_GetShort(self, off) (slim_handle_peek_short((slim_handle)(self), (off)))

#define TContentSpec_Class(self)			((TContentClass *)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fClass))))
#define TContentSpec_Flag(self)				(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fFlag)))
#define TContentSpec_CacheMode(self)		(TContentSpec_Flag((self)) & SLIM_CONTENT_CACHEMASK)
#define TContentSpec_By(self)				(TContentSpec_Flag((self)) & SLIM_CONTENT_BYMASK)
#define TContentSpec_Method(self)			(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fMethod)))
#define TContentSpec_URL(self)				((TURLString)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fURL))))
#define TContentSpec_RefererX(self)			((TURLString)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fReferer))))
#define TContentSpec_PostEncoding(self)		(TPostData_Encoding(TContentSpec_PostData((self))))
#define TContentSpec_PostData(self)			((TPostData)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fPostData))))
#define TContentSpec_RequestLen(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fRequestLen)))
#define TContentSpec_RequestSent(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fRequestSent)))
#define TContentSpec_OriginalURL(self)		((TURLString)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fOriginalURL))))
#define TContentSpec_RequestHeader(self)	((TString)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fHTTPHeader))))
#define TContentSpec_CacheType(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fCacheType)))
#define TContentSpec_IsReadFromCache(self)	(TContentSpec_CacheType(self) != SLIM_CONTENT_CACHE_TYPE_NONE ? slim_true : slim_false)
#define TContentSpec_ExtFlag(self)			(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fExtFlag)))
#define TContentSpec_ChannelState(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fChannelState)))
#define TContentSpec_StatusCode(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fStatusCode)))
#define TContentSpec_ErrorCode(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fErrorCode)))
#define TContentSpec_CoreSpec(self)			((TContentCoreSpec)TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fCoreSpec)))
#define TContentSpec_ContentChannel(self)	((TContentChannel)(TContentSpec_GetPtr((self), SLIM_OFFSETOF(iTContentSpec, fContentChannel))))

#define TContentSpec_WindowSize(self)		(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fWindowSize)))
#define TContentSpec_ConsumedLength(self)	(TContentSpec_GetInt((self), SLIM_OFFSETOF(iTContentSpec, fConsumedLength)))

#define TContentSpec_CoreSpecFlag(self)		(TContentCoreSpec_Flag(TContentSpec_CoreSpec((self))))
#define TContentSpec_Time(self, time)		(TContentCoreSpec_Time(TContentSpec_CoreSpec((self)), (time)))
#define TContentSpec_CurrentLength(self)	(TContentCoreSpec_CurrentLength(TContentSpec_CoreSpec((self))))
#define TContentSpec_ContentLength(self)	(TContentCoreSpec_ContentLength(TContentSpec_CoreSpec((self))))
#define TContentSpec_OriginLength(self)		(TContentCoreSpec_OriginLength(TContentSpec_CoreSpec((self))))
#define TContentSpec_ContentType(self)		(TContentCoreSpec_ContentType(TContentSpec_CoreSpec((self))))
#define TContentSpec_Header(self)			(TContentCoreSpec_Header(TContentSpec_CoreSpec((self))))
#define TContentSpec_Content(self)			(TContentCoreSpec_Content(TContentSpec_CoreSpec((self))))
#define TContentSpec_CertList(self)			(TContentCoreSpec_CertList(TContentSpec_CoreSpec((self))))
#define TContentSpec_ValidatorETag(self)	(TContentCoreSpec_ValidatorETag(TContentSpec_CoreSpec((self))))
#define TContentSpec_ValidatorDate(self)	(TContentCoreSpec_ValidatorDate(TContentSpec_CoreSpec((self))))
#define TContentSpec_Expires(self, t, e)	(TContentCoreSpec_Expires(TContentSpec_CoreSpec((self)), (t), (e)))
#define TContentSpec_HTTPHeader(self) 		TContentSpec_Header(self)	/* Ugh!: backward compatibility */

#define TContentSpec_IsDone(self)					((TContentSpec_Flag((self)) & SLIM_CONTENT_DONE) == SLIM_CONTENT_DONE)
#define TContentSpec_IsError(self)					((TContentSpec_Flag((self)) & SLIM_CONTENT_ERROR) == SLIM_CONTENT_ERROR)
#define TContentSpec_IsAborted(self)				((TContentSpec_Flag((self)) & SLIM_CONTENT_ABORT) == SLIM_CONTENT_ABORT)
#define TContentSpec_IsContentAvail(self)			((TContentSpec_Flag((self)) & SLIM_CONTENT_CONTENTAVAIL) == SLIM_CONTENT_CONTENTAVAIL)
#define TContentSpec_IsTypeAvail(self)				((TContentSpec_Flag((self)) & SLIM_CONTENT_TYPEAVAIL) == SLIM_CONTENT_TYPEAVAIL)
#define TContentSpec_IsWriteOpen(self)				((TContentSpec_Flag((self)) & SLIM_CONTENT_WRITEOPEN) == SLIM_CONTENT_WRITEOPEN)
#define TContentSpec_IsAvail(self)					((TContentSpec_Flag((self)) & (SLIM_CONTENT_CONTENTAVAIL|SLIM_CONTENT_TYPEAVAIL)) == (SLIM_CONTENT_CONTENTAVAIL|SLIM_CONTENT_TYPEAVAIL))
#define TContentSpec_IsComplete(self)				((TContentSpec_Flag((self)) & (SLIM_CONTENT_DONE|SLIM_CONTENT_ABORT|SLIM_CONTENT_ERROR)) == SLIM_CONTENT_DONE)

#define TContentSpec_IsUseNet(self)					((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_USENET) == SLIM_CNTSPEC_EXT_USENET)
#define TContentSpec_IsAuthAutoRetried(self)		((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_AUTH_AUTO_RETRIED) == SLIM_CNTSPEC_EXT_AUTH_AUTO_RETRIED)
#define TContentSpec_IsMETAMaxAgeSpecified(self)	((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_META_MAXAGE_SPECIFIED) == SLIM_CNTSPEC_EXT_META_MAXAGE_SPECIFIED)
#define TContentSpec_IsMETAExpiresSpecified(self)	((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_META_EXPIRES_SPECIFIED) == SLIM_CNTSPEC_EXT_META_EXPIRES_SPECIFIED)
#define TContentSpec_HasHighPriority(self)			((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_HIGH_PRIORITY) == SLIM_CNTSPEC_EXT_HIGH_PRIORITY)
#define TContentSpec_IsVisited(self)				((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_VISITED) == SLIM_CNTSPEC_EXT_VISITED)
#define TContentSpec_IsSharable(self)				((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_SHARABLE) == SLIM_CNTSPEC_EXT_SHARABLE)
#define TContentSpec_IsReopen(self)					((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_REOPEN) == SLIM_CNTSPEC_EXT_REOPEN)
#define TContentSpec_IsAllowEmpty(self)				((TContentSpec_ExtFlag((self)) & SLIM_CNTSPEC_EXT_ALLOW_EMPTY) == SLIM_CNTSPEC_EXT_ALLOW_EMPTY)

#define TContentSpec_IsViaProxy(self)				(TContentCoreSpec_IsViaProxy(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsHistoryOnly(self)			(TContentCoreSpec_IsHistoryOnly(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsMemoryOnly(self)				(TContentCoreSpec_IsMemoryOnly(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsDeferPersistent(self)		(TContentCoreSpec_IsDeferPersistent(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsPartial(self)				(TContentCoreSpec_IsPartial(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsValidatedPerSession(self)	(TContentCoreSpec_IsValidatedPerSession(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsDeleteASAP(self)				(TContentCoreSpec_IsDeleteASAP(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsExpired(self)				(TContentCoreSpec_IsExpired(TContentSpec_CoreSpec((self))))
#define TContentSpec_IsForwardLock(self)			(TContentCoreSpec_IsForwardLock(TContentSpec_CoreSpec((self))))

#define TContentSpec_CacheMode(self)		(TContentSpec_Flag((self)) & SLIM_CONTENT_CACHEMASK)
#define TContentSpec_IsSecure(self)			(TContentSpec_CertList((self)) != slim_nil)
#define TContentSpec_IsHTTPS(self)			(TURLString_IsHTTPS(TContentSpec_URL((self))))


#define TContentSpec_FindHTTPHeaderByID(self, id, o) TContentSpec_FindHTTPHeaderByX((self), slim_nil, (id), (o))
#define TContentSpec_FindHTTPHeaderByCS(self, cs, o) (!(cs) ? slim_false : TContentSpec_FindHTTPHeaderByX((self), (cs), slim_strlen(cs), (o)) )
#define TContentSpec_FindHTTPHeaderBySS(self, s, l, o) (!(s) ? slim_false : TContentSpec_FindHTTPHeaderByX((self), (s), (l), (o)) )


#define SLIM_CONTSPC_MKFNAME_URL			0x00000001
#define SLIM_CONTSPC_MKFNAME_ORIG_URL		0x00000002
#define SLIM_CONTSPC_MKFNAME_DISPOSITION	0x00000004
#define SLIM_CONTSPC_MKFNAME_SUFFIXMIMETYPE	0x00000008
#define TContentSpec_MakeDispositionFileName(self,fname) TContentSpec_SuffixMIMETypeOrMakeFileNameX((self),(fname),slim_nil,SLIM_CONTSPC_MKFNAME_DISPOSITION)
#define TContentSpec_MakeFileName(self,fname) TContentSpec_SuffixMIMETypeOrMakeFileNameX((self),(fname),slim_nil,SLIM_CONTSPC_MKFNAME_DISPOSITION|SLIM_CONTSPC_MKFNAME_URL)


#define TContentSpec_SetContentAvail(self, set)			(TContentSpec_SetFlag((self), SLIM_CONTENT_CONTENTAVAIL, (set)))
#define TContentSpec_SetTypeAvail(self, set)			(TContentSpec_SetFlag((self), SLIM_CONTENT_TYPEAVAIL, (set)))

#define TContentSpec_SetUseNet(self, set)				(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_USENET, (set)))
#define TContentSpec_SetAuthAutoRetried(self, set)		(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_AUTH_AUTO_RETRIED, (set)))
#define TContentSpec_SetMETAMaxAgeSpecified(self, set)	(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_META_MAXAGE_SPECIFIED, (set)))
#define TContentSpec_SetMETAExpiresSpecified(self, set)	(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_META_EXPIRES_SPECIFIED, (set)))
#define TContentSpec_SetVisited(self, set)				(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_VISITED, (set)))
#define TContentSpec_SetSharable(self, set)				(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_SHARABLE, (set)))
#define TContentSpec_SetReopen(self, set)				(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_REOPEN, (set)))
#define TContentSpec_SetAllowEmpty(self, set)			(TContentSpec_SetExtFlag((self), SLIM_CNTSPEC_EXT_ALLOW_EMPTY, (set)))

#define TContentSpec_SetCoreSpecFlag(self, flag, set)	(TContentCoreSpec_SetFlag(TContentSpec_CoreSpec((self)), (flag), (set)))
#define TContentSpec_SetCurrentLength(self, length)		(TContentCoreSpec_SetCurrentLength(TContentSpec_CoreSpec((self)), (length)))
#define TContentSpec_SetContentLength(self, length)		(TContentCoreSpec_SetContentLength(TContentSpec_CoreSpec((self)), (length)))
#define TContentSpec_SetOriginLength(self, length)		(TContentCoreSpec_SetOriginLength(TContentSpec_CoreSpec((self)), (length)))
#define TContentSpec_SetContentType(self, type)			(TContentCoreSpec_SetContentType(TContentSpec_CoreSpec((self)), (type)))
#define TContentSpec_SetHeader(self, header)			(TContentCoreSpec_SetHeader(TContentSpec_CoreSpec((self)), (header)))
#define TContentSpec_SetContent(self, content)			(TContentCoreSpec_SetContent(TContentSpec_CoreSpec((self)), (content)))
#define TContentSpec_SetCertList(self, cert_list)		(TContentCoreSpec_SetCertList(TContentSpec_CoreSpec((self)), (cert_list)))
#define TContentSpec_SetValidatorETag(self, etag)		(TContentCoreSpec_SetValidatorETag(TContentSpec_CoreSpec((self)), (etag)))
#define TContentSpec_SetValidatorDate(self, date)		(TContentCoreSpec_SetValidatorDate(TContentSpec_CoreSpec((self)), (date)))
#define TContentSpec_SetExpires(self, expires)			(TContentCoreSpec_SetExpires(TContentSpec_CoreSpec((self)), (expires)))
#define TContentSpec_SetRevalidate(self)				(TContentCoreSpec_SetRevalidate(TContentSpec_CoreSpec((self))))
#define TContentSpec_SetTime(self, time)				(TContentCoreSpec_SetTime(TContentSpec_CoreSpec((self)), (time)))
#define TContentSpec_SetExpiresX(self, type, expires)	(TContentCoreSpec_SetExpiresX(TContentSpec_CoreSpec((self)), (type), (expires)))

#define TContentSpec_SetViaProxy(self, set)				(TContentCoreSpec_SetViaProxy(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetHistoryOnly(self, set)			(TContentCoreSpec_SetHistoryOnly(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetMemoryOnly(self, set)			(TContentCoreSpec_SetMemoryOnly(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetDeferPersistent(self, set)		(TContentCoreSpec_SetDeferPersistent(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetPartial(self, set)				(TContentCoreSpec_SetPartial(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetValidatedPerSession(self, set)	(TContentCoreSpec_SetValidatedPerSession(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetDeleteASAP(self, set)			(TContentCoreSpec_SetDeleteASAP(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetExpired(self, set)				(TContentCoreSpec_SetExpired(TContentSpec_CoreSpec((self)), (set)))
#define TContentSpec_SetForwardLock(self, set)			(TContentCoreSpec_SetForwardLock(TContentSpec_CoreSpec((self)), (set)))

#define TContentSpec_Disuse(self) TContentSpec_DisuseX((self),slim_false)

/*
 * ContentSpecFactory
 */

#define TContentSpecFactory_Prepare(self,req,spec) ((*(self)->fPrepare)((self),(req),(spec)))
#define TContentSpecFactory_Finalize(self) ((void)0)

/*
 * Content
 */

#define SLIM_CONTENT_PRESERVE_MAX (4096 * 50) /* max first allocation by contents length */

enum {
	SLIM_CONTENT_L2CACHE_TIMING_ON_CONTENT_CLOSE = 0,
	SLIM_CONTENT_L2CACHE_TIMING_ON_CONTENT_DONE,
	SLIM_CONTENT_L2CACHE_TIMING_ON_IDLE,
	SLIM_CONTENT_L2CACHE_TIMINGS
};

#define SLIM_CONFIG_CONTENT_MAXREDIRECT				30
#define SLIM_CONFIG_CONTENT_MAXPAGEAUTH				-1
#define SLIM_CONFIG_CONTENT_MAXPROXYAUTH			-1
#define SLIM_CONFIG_CONTENT_DEFAULT_CACHE_MODE		SLIM_CONTENT_CACHE_NETFIRST_ONCE
#define SLIM_CONFIG_CONTENT_DEFAULT_L2CACHE_TIMING	SLIM_CONTENT_L2CACHE_TIMING_ON_IDLE

#define SLIM_CONTENTINSTANCE_FLAG_READFROMNET	0x00000001
#define SLIM_CONTENTINSTANCE_FLAG_ABORTED	0x00000002

#define Content_New0() ((TContent)slim_handle_zeroalloc(sizeof(iTContent)))
#define TContent_Delete0(self) (slim_handle_free((slim_handle)(self)))

#define Content_SetDeterminerClass(cls, dtmncls) ((cls)->fDeterminerClass = (dtmncls))
#define Content_SetContentSpecFactory(cls, factory) ((cls)->fContentSpecFactory = (factory))

#define Content_SetDefaultCacheMode(self,val)	{(self)->fDefaultCacheMode = (val);}
#define Content_DefaultCacheMode(self)			((self)->fDefaultCacheMode)
#define Content_SetMaxRedirect(self,val)		{(self)->fMaxRedirect = (val);}
#define Content_MaxRedirect(self)				((self)->fMaxRedirect)
#define Content_SetMaxPageAuth(self,val)		{(self)->fMaxPageAuth = (val);}
#define Content_MaxPageAuth(self)				((self)->fMaxPageAuth)
#define Content_SetMaxProxyAuth(self,val)		{(self)->fMaxProxyAuth = (val);}
#define Content_MaxProxyAuth(self)				((self)->fMaxProxyAuth)


#ifdef SLIM_CONFIG_DEBUG
#else
#define TContent_Check(self) ((slim_handle)(self))
#endif

#define TContent_Lock(self)		((iTContent *)slim_handle_lock(TContent_Check(self)))
#define TContent_Unlock(self)	(slim_handle_unlock(TContent_Check(self)))
#define TContent_Locate(self)	((iTContent *)slim_handle_locate(TContent_Check(self)))
#define TContent_Unlocate(self) (slim_handle_unlocate(TContent_Check(self)))
#define TContent_GetShort(self, off) (slim_handle_peek_short(TContent_Check((self)),(off)))
#define TContent_GetInt(self, off) (slim_handle_peek_int(TContent_Check((self)),(off)))
#define TContent_GetPtr(self, off) (slim_handle_peek_ptr(TContent_Check((self)),(off)))

#define TContent_ContentSpec(self)	((TContentSpec)TContent_GetPtr((self), SLIM_OFFSETOF(iTContent, fContentSpec)))
#define TContent_RequestFlag(self)	(TContent_GetInt((self), SLIM_OFFSETOF(iTContent, fRequestFlag)))

#define TContent_OriginalContentType(self) (TContentSpec_ContentType(TContent_ContentSpec((self))))
#define TContent_RequestedMIMEType(self) TContent_GetInt((self), SLIM_OFFSETOF(iTContent,fRequestedMIMEType))
#define TContent_HeaderMIMEType(self) TContentSpec_HeaderMIMEType(TContent_ContentSpec((self)))
#define TContent_SuffixMIMEType(self) TContentSpec_SuffixMIMEType(TContent_ContentSpec((self)))

#define TContent_ForcedCharSet(self) TContent_GetInt((self),SLIM_OFFSETOF(iTContent, fForcedCharSet))
#define TContent_SetContentType(self,mime) TContent_SetContentTypeX((self),(mime),slim_false) 
#define TContent_SetRequestedMIMEType(self,mime) TContent_SetContentTypeX((self),(mime),slim_true) 

#define TContent_IsWriteOpen(self)	(TContentSpec_IsWriteOpen(TContent_ContentSpec((self))))

#define TContent_SpecFlag(self)			(TContentSpec_Flag(TContent_ContentSpec((self))))
#define TContent_CoreSpecFlag(self)		(TContentSpec_CoreSpecFlag(TContent_ContentSpec((self))))
#define TContent_CacheMode(self)		(TContent_RequestFlag((self)) & SLIM_CONTENT_CACHEMASK)
#define TContent_By(self)				(TContent_RequestFlag((self)) & SLIM_CONTENT_BYMASK)
#define TContent_IsContentAvail(self)	TContentSpec_IsContentAvail(TContent_ContentSpec((self)))
#define TContent_IsTypeAvail(self)		TContentSpec_IsTypeAvail(TContent_ContentSpec((self)))

#define TContent_OriginLength(self) TContent_OriginalLength((self))
#define TContent_OriginalOriginalLength(self) (TContentSpec_OriginLength(TContent_ContentSpec((self))))
#define TContent_OriginalContentLength(self) (TContentSpec_ContentLength(TContent_ContentSpec((self))))
#define TContent_OriginalCurrentLength(self) (TContentSpec_CurrentLength(TContent_ContentSpec((self))))

#define TContent_ContentViaProxy(self)	TContentSpec_ContentViaProxy(TContent_ContentSpec((self)))
#define TContent_Method(self)	TContentSpec_Method(TContent_ContentSpec((self)))
#define TContent_RefererX(self)	((TURLString)(TContent_GetPtr((self), SLIM_OFFSETOF(iTContent,fReferer))))
#define TContent_PostEncoding(self)	TContentSpec_PostEncoding(TContent_ContentSpec((self)))
#define TContent_PostData(self)	TContentSpec_PostData(TContent_ContentSpec((self)))
#define TContent_PostDataLen(self)	TContentSpec_PostDataLen(TContent_ContentSpec((self)))
#define TContent_RequestLen(self)	TContentSpec_RequestLen(TContent_ContentSpec((self)))
#define TContent_RequestSent(self)	TContentSpec_RequestSent(TContent_ContentSpec((self)))
#define TContent_OriginalURL(self)	TContentSpec_OriginalURL(TContent_ContentSpec((self)))
#define TContent_Expires(self, t, e)	TContentSpec_Expires(TContent_ContentSpec((self)), (t), (e))

#define TContent_OriginalContent(self)	TContentSpec_Content(TContent_ContentSpec((self)))
#define TContent_Class(self)	TContentSpec_Class(TContent_ContentSpec((self)))

#define TContent_FindHTTPHeaderByID(self, id, o) TContentSpec_FindHTTPHeaderByID(TContent_ContentSpec((self)),(id),(o))
#define TContent_FindHTTPHeaderByCS(self, cs, o) TContentSpec_FindHTTPHeaderByCS(TContent_ContentSpec((self)),(cs),(o))
#define TContent_FindHTTPHeaderBySS(self, s, l, o) TContentSpec_FindHTTPHeaderBySS(TContent_ContentSpec((self)),(s),(l),(o))

#define TContent_MIMEInfoClass(self) (TContent_Class(self)->fMIMEInfoClass)
#define TContent_CacheType(self)	TContentSpec_CacheType(TContent_ContentSpec((self)))
#define TContent_IsReadFromCache(self)	TContentSpec_IsReadFromCache(TContent_ContentSpec((self)))
#define TContent_IsUseNet(self)	TContentSpec_IsUseNet(TContent_ContentSpec((self)))
#define TContent_MultiContent(self) ((TMultiContent)TContent_GetPtr((self), SLIM_OFFSETOF(iTContent, fMultiContent)))

#define TContent_InstanceFlag(self) TContent_GetInt((self), SLIM_OFFSETOF(iTContent, fInstanceFlag))
#define TContent_SetInstanceFlag(self,flag) TContent_SetClearInstanceFlag((self),(flag),slim_false)
#define TContent_ClearInstanceFlag(self,flag) TContent_SetClearInstanceFlag((self),(flag),slim_true)

#define TContent_DeleteFragment(self) TContent_SetFragmentSS((self),slim_nil,0,SLIM_CHARSET_UNKNOWN)
#define TContent_ChannelState(self) TContentSpec_ChannelState(TContent_ContentSpec((self)))

#define TContent_MakeDispositionFileName(self,fname) TContentSpec_MakeDispositionFileName(TContent_ContentSpec((self)),(fname))

#define TContent_DoNotCache(self)	TContentSpec_DoNotCache(TContent_ContentSpec((self)))
#define TContent_ErrorCode(self)	TContentSpec_ErrorCode(TContent_ContentSpec((self)))
#define TContent_HeaderCharSet(self) TContentSpec_HeaderCharSet(TContent_ContentSpec((self)))
#define TContent_HTTPHeader(self)	TContentSpec_HTTPHeader(TContent_ContentSpec((self)))
#define TContent_IsAbort(self)		TContentSpec_IsAborted(TContent_ContentSpec((self)))
#define TContent_IsError(self)		TContentSpec_IsError(TContent_ContentSpec((self)))
#define TContent_IsComplete(self)	TContentSpec_IsComplete(TContent_ContentSpec((self)))
#define TContent_IsHTTPS(self)		TContentSpec_IsHTTPS(TContent_ContentSpec((self)))
#define TContent_MakeFileName(self,fname) TContentSpec_MakeFileName(TContent_ContentSpec((self)),(fname))
#define TContent_StatusCode(self)	TContentSpec_StatusCode(TContent_ContentSpec((self)))
#define TContent_Time(self,otime)	TContentSpec_Time(TContent_ContentSpec((self)),(otime))
#define TContent_URL(self)	TContentSpec_URL(TContent_ContentSpec((self)))
#define TContent_ContentChannel(self)	TContentSpec_ContentChannel(TContent_ContentSpec((self)))

/* DRM */
#define Content_SetDRMManager(cls,man) ((cls)->fDRMManager = (man))

/* for customization */

#ifdef SLIM_CONFIG_DEBUG
#else
#define TContent_DebugDump(self, in_precise)	{}
#endif /* SLIM_CONFIG_DEBUG */

/* TStreamContent */


#define TStreamContent_Lock(self)		((iTStreamContent *)slim_handle_lock((slim_handle)self))
#define TStreamContent_Unlock(self)	(slim_handle_unlock((slim_handle)self))
#define TStreamContent_Locate(self)	((iTStreamContent *)slim_handle_locate((slim_handle)self))
#define TStreamContent_Unlocate(self) (slim_handle_unlocate((slim_handle)self))
#define TStreamContent_GetPtr(self, off) (slim_handle_peek_ptr((slim_handle)(self), (off)))
#define TStreamContent_GetInt(self, off) (slim_handle_peek_int((slim_handle)(self), (off)))
#define TStreamContent_GetShort(self, off) (slim_handle_peek_short((slim_handle)(self), (off)))
#define TStreamContent_MakeDispositionFileName(self,fname) TContentSpec_MakeDispositionFileName(TStreamContent_ContentSpec((self)),(fname))

#define TStreamContent_ContentSpec(self)	((TContentSpec)TStreamContent_GetPtr((self),SLIM_OFFSETOF(iTStreamContent, fContentSpec)))
#define TStreamContent_RequestFlag(self)	(TStreamContent_GetInt((self), SLIM_OFFSETOF(iTStreamContent, fRequestFlag)))

#define TStreamContent_CoreSpecFlag(self)	TContentSpec_CoreSpecFlag(TStreamContent_ContentSpec((self)))

#define TStreamContent_IsContentAvail(self)	TContentSpec_IsContentAvail(TStreamContent_ContentSpec((self)))
#define TStreamContent_CacheMode(self)		(TStreamContent_RequestFlag((self)) & SLIM_CONTENT_CACHEMASK)
#define TStreamContent_By(self)				(TStreamContent_RequestFlag((self)) & SLIM_CONTENT_BYMASK)

#define TStreamContent_OriginLength(self)	TContentSpec_OriginLength(TStreamContent_ContentSpec((self)))
#define TStreamContent_ContentViaProxy(self)	TContentSpec_ContentViaProxy(TStreamContent_ContentSpec((self)))
#define TStreamContent_Method(self)	TContentSpec_Method(TStreamContent_ContentSpec((self)))
#define TStreamContent_RefererX(self)	((TURLString)(TStreamContent_GetPtr((self),SLIM_OFFSETOF(iTStreamContent,fReferer))))
#define TStreamContent_PostEncoding(self)	TContentSpec_PostEncoding(TStreamContent_ContentSpec((self)))
#define TStreamContent_PostData(self)	TContentSpec_PostData(TStreamContent_ContentSpec((self)))
#define TStreamContent_PostDataLen(self)	TContentSpec_PostDataLen(TStreamContent_ContentSpec((self)))

#define TStreamContent_OriginalURL(self)	TContentSpec_OriginalURL(TStreamContent_ContentSpec((self)))
#define TStreamContent_CertList(self)	TContentSpec_CertList(TStreamContent_ContentSpec((self)))
#define TStreamContent_Class(self)	TContentSpec_Class(TStreamContent_ContentSpec((self)))

#define TStreamContent_CheckDone(self) TContentSpec_IsDone(TStreamContent_ContentSpec((self)))
#define TStreamContent_Content(self)	TContentSpec_Content(TStreamContent_ContentSpec((self)))
#define TStreamContent_ContentLength(self)	TContentSpec_ContentLength(TStreamContent_ContentSpec((self)))
#define TStreamContent_CurrentLength(self)	TContentSpec_CurrentLength(TStreamContent_ContentSpec((self)))
#define TStreamContent_DoNotCache(self) TContentSpec_DoNotCache(TStreamContent_ContentSpec((self)))
#define TStreamContent_ErrorCode(self)	TContentSpec_ErrorCode(TStreamContent_ContentSpec((self)))
#define TStreamContent_HTTPHeader(self)	TContentSpec_HTTPHeader(TStreamContent_ContentSpec((self)))
#define TStreamContent_HeaderCharSet(self) TContentSpec_HeaderCharSet(TStreamContent_ContentSpec((self)))
#define TStreamContent_IsAbort(self) TContentSpec_IsAborted(TStreamContent_ContentSpec((self)))
#define TStreamContent_IsError(self) TContentSpec_IsError(TStreamContent_ContentSpec((self)))
#define TStreamContent_IsComplete(self) TContentSpec_IsComplete(TStreamContent_ContentSpec((self)))
#define TStreamContent_IsHTTPS(self) TContentSpec_IsHTTPS(TStreamContent_ContentSpec((self)))
#define TStreamContent_IsSecure(self) TContentSpec_IsSecure(TStreamContent_ContentSpec((self)))
#define TStreamContent_MakeFileName(self,fname) TContentSpec_MakeFileName(TStreamContent_ContentSpec((self)),(fname))
#define TStreamContent_StatusCode(self)	TContentSpec_StatusCode(TStreamContent_ContentSpec((self)))
#define TStreamContent_Time(self, otime) TContentSpec_Time(TStreamContent_ContentSpec((self)),(otime))
#define TStreamContent_URL(self)	TContentSpec_URL(TStreamContent_ContentSpec((self)))


/*
 * ContentReader
 */

/* bits of SLIM_POLL_BITMASK are reserved */
#define SLIM_CONTREADER_NOTIFYRESTART		0x00000004

#define TContentReader_SetUserData(self,arg) ((self)->fUserData = (arg))

/*
 * BinaryContentReader
 */

/*
 * TextContentReader
 */

SLIM_END_C_LINKAGE

#endif
