/*
	httpstrm.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/httpstrm.h 174   06/06/20 14:56 Nosakatetsuro $ */

#ifndef SLIM_HTTPSTRM_H_PRIVATE
#define SLIM_HTTPSTRM_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#define SLIM_HTTP_STREAM_MAX_DNS_CACHE		 	10

#define SLIM_HTTP_STREAM_DEFAULT_SEND_REFERER		slim_true
#define SLIM_HTTP_STREAM_DEFAULT_SEND_PROXYKEEPALIVE	slim_true
#define SLIM_HTTP_STREAM_DEFAULT_SEND_COOKIE		slim_true
#define SLIM_HTTP_STREAM_DEFAULT_USE_PROXY			slim_false
#define SLIM_HTTP_STREAM_DEFAULT_HTTP11_OVER_PROXY	slim_false
#define SLIM_HTTP_STREAM_DEFAULT_PROXY_HOST			SLIM_T("")
#define SLIM_HTTP_STREAM_DEFAULT_PROXY_HTTP_PORT	8080
#define SLIM_HTTP_STREAM_DEFAULT_PROXY_HTTPS_PORT	8080
#define SLIM_HTTP_STREAM_DEFAULT_NO_PROXY_HOSTS		SLIM_T("")
#define SLIM_HTTP_STREAM_DEFAULT_USER_AGENT			SLIM_T("SLIM HTTP Stream Library")
#define SLIM_HTTP_STREAM_DEFAULT_HEADERS			SLIM_T("Accept: image/png, image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, */*\015\012")
#define SLIM_HTTP_STREAM_DEFAULT_CONNECT_HEADERS	SLIM_T("")
#define SLIM_HTTP_STREAM_DEFAULT_TIME_OUT		-1

#ifndef SLIM_CONFIG_USE_HTTP
/* dummy */

/*==================================================================*/
/* http stream pool 												*/
/*==================================================================*/
/*------------------------------*/
/* method						*/
/*------------------------------*/

/*----------------------------------------------------------*/
/* http auth info											*/
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
/* http auth cache											*/
/*----------------------------------------------------------*/
#define THTTPAuthCache_Serialize(iself, out_buf, in_len, in_key)	(0)
#define THTTPAuthCache_Deserialize(iself, in_buf, in_len, in_key)	(0)

/*==================================================================*/
/* http cookie 														*/
/*==================================================================*/
#define THTTPCookies_Initialize(self, in_max_total_cookies, in_max_cookies_per_domain, in_max_len_per_cookie) (slim_true)
#define THTTPCookies_Finalize(self) {}
#define THTTPCookies_SetMax(self, in_max_total_cookies, in_max_cookies_per_domain, in_max_len_per_cookie) {}
#define THTTPCookies_SetCookie(self, in_url, in_header, in_headerlen) (SLIM_E_OK)
#define THTTPCookies_SetCookieX(self, in_url, in_header, in_headerlen) (SLIM_E_OK)
#define THTTPCookies_MakeCookiesString(self, in_url, in_urllen, in_secure, out_len) (slim_nil)
#define THTTPCookies_SaveEntries(self, out_len) (slim_nil)
#define THTTPCookies_LoadEntries(self, in_s, in_slen) (slim_true)
#define THTTPCookies_MakeEmpty(self) {}
#define HTTPCookies_LimitSizeSavedEntries(in_limit, inout_s, inout_len) (slim_false)
#define THTTPCookies_SetHandleReceivedCookieProc(self, in_func, in_aux) ((void)0)

/*------------------------------*/
/* class method				 	*/
/*------------------------------*/
#define HTTPStream_SetHeaderRestrictions(in_class, in_req, in_rsp)	{}
#define HTTPStream_SetCookieMode(in_class, in_cookie_mode, in_cookie_callback, in_cookie_aux)	{}
#define HTTPStream_SetHandleReceivedCookieProc(self, in_func, in_aux) ((void)0)
#define HTTPStream_SetTunnelingCallback(in_class, in_tunneling_callback, in_tunneling_aux)	{}
#define HTTPStream_SetMakeCredProc(in_class, in_type, in_proc)	{}
#define HTTPStream_SetUserPassX(in_class, in_type, in_target,\
								 in_challenge_ss, in_realm_ss,\
								 in_user, in_pass, in_url, \
								 in_host, in_port,\
								 in_keep_user, in_keep_pass)	(slim_true)
#define HTTPStream_FindAuthCandidate(in_class, in_url, in_target,\
								  in_proxy_host, in_proxy_port,\
								  inout_realm, out_user, out_pass,\
								  out_keep_user, out_keep_pass)	{}
#define HTTPStream_IsAuthorized(in_class, in_url, in_target, in_proxy_host, \
								in_proxy_port, inout_realm) (slim_false)
#define HTTPStream_FindAuthInfoPix(in_class, in_target, in_url, \
									in_proxy_host, in_proxy_port, in_realm_ss, \
									out_pix)	(slim_pix_nil)
#define HTTPStream_FindAuthInfo(in_class, in_target, in_url, \
								  in_proxy_host, in_proxy_port, in_realm_ss, out_info)	(slim_false)
#define HTTPStream_KeepAliveTimeout(in_class) (SLIM_INT_MAX)
#define HTTPStream_SetMaxTotalCookiesLen(in_class, in_max_len) ((void)0)

/* multi application */
#define HTTPStream_SetSSLDeleteCallback(in_class, in_proc, in_aux)	(slim_true)
#define HTTPStream_SetSSLPrivateKeyEncryptProc(in_class, in_proc, in_aux)	(slim_true)

/*----------------------------------------------------------*/
/* http stream												*/
/*----------------------------------------------------------*/
/*------------------------------*/
/* method						*/
/*------------------------------*/
#define THTTPStream_SetTimeLimit(self, in_tmev, in_msec) {}
#define THTTPStream_SetMaxReqMsgHeader(self, in_size) ((void)0)
#define THTTPStream_SetNotifyStateProc(self, proc, aux)	((void)0)

#else /* SLIM_CONFIG_USE_HTTP */

/*----------------------------------------------------------*/
/* http tcp stream											*/
/*----------------------------------------------------------*/
#define THTTPTCPStream_SetOpened(self,val)		SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_OPENED,(val))
#define THTTPTCPStream_SetKeepAlive(self,val)	SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_KEEP_ALIVE,(val))
#define THTTPTCPStream_SetPipeline(self,val)	SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_PIPELINE,(val))
#define THTTPTCPStream_SetProxy(self,val)		SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_PROXY,(val))
#define THTTPTCPStream_SetSSL(self,val)			SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL,(val))
#define THTTPTCPStream_SetSSLProxyAuthFail(self,val) SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_PROXY_AUTH_FAIL,(val))
#define THTTPTCPStream_SetSSLReuseTry(self,val) SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_TRY,(val))
#define THTTPTCPStream_SetSSLReuseSuccess(self,val) SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_SUCCESS,(val))
#define THTTPTCPStream_SetSSLConFailContent(self,val) SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_CONFAIL_CONTENT,(val))
#define THTTPTCPStream_SetClosedByServer(self,val) SLIM_FLAG_OP((self),SLIM_HTTP_TCP_STREAM_FLAG_CLOSED_BY_SERVER,(val))

#define THTTPTCPStream_IsOpened(self)			 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_OPENED)
#define THTTPTCPStream_IsKeepAlive(self)		 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_KEEP_ALIVE)
#define THTTPTCPStream_IsPipeline(self)			 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_PIPELINE)
#define THTTPTCPStream_IsProxy(self)			 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_PROXY)
#define THTTPTCPStream_IsSSL(self)				 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL)
#define THTTPTCPStream_IsSSLProxyAuthFail(self)	 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_PROXY_AUTH_FAIL)
#define THTTPTCPStream_IsSSLReuseTry(self)		 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_TRY)
#define THTTPTCPStream_IsSSLReuseSuccess(self)	 SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_SUCCESS)
#define THTTPTCPStream_IsSSLConFailContent(self) SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_SSL_CONFAIL_CONTENT)
#define THTTPTCPStream_IsClosedByServer(self)    SLIM_FLAG_CK((self),SLIM_HTTP_TCP_STREAM_FLAG_CLOSED_BY_SERVER)

/* SSL state */
enum {
	SLIM_HTTP_STREAM_POOL_SSL_ST_START = 0,
	SLIM_HTTP_STREAM_POOL_SSL_ST_CONNECT,
	SLIM_HTTP_STREAM_POOL_SSL_ST_SEND_PROXY,
	SLIM_HTTP_STREAM_POOL_SSL_ST_RECV_PROXY,
	SLIM_HTTP_STREAM_POOL_SSL_ST_HANDSHAKE,
	SLIM_HTTP_STREAM_POOL_SSL_ST_DONE,
	SLIM_HTTP_STREAM_POOL_SSL_STS
};
/*----------------------------------------------------------*/
/* http stream pool entry									*/
/*----------------------------------------------------------*/

/* flag operation */
#define SLIM_HTTP_STREAM_POOL_FLAG_OPEN			0x0001
#define SLIM_HTTP_STREAM_POOL_FLAG_STALL		0x0002
#define SLIM_HTTP_STREAM_POOL_FLAG_PIPE_CHECK	0x0004

#define THTTPStreamPoolEntry_SetOpen(self,val)		SLIM_FLAG_OP((self),SLIM_HTTP_STREAM_POOL_FLAG_OPEN,(val))
#define THTTPStreamPoolEntry_SetStall(self,val)		SLIM_FLAG_OP((self),SLIM_HTTP_STREAM_POOL_FLAG_STALL,(val))
#define THTTPStreamPoolEntry_SetPipeCheck(self,val)	SLIM_FLAG_OP((self),SLIM_HTTP_STREAM_POOL_FLAG_PIPE_CHECK,(val))

#define THTTPStreamPoolEntry_IsOpen(self)		SLIM_FLAG_CK((self),SLIM_HTTP_STREAM_POOL_FLAG_OPEN)
#define THTTPStreamPoolEntry_IsStall(self)		SLIM_FLAG_CK((self),SLIM_HTTP_STREAM_POOL_FLAG_STALL)
#define THTTPStreamPoolEntry_IsPipeCheck(self)	SLIM_FLAG_CK((self),SLIM_HTTP_STREAM_POOL_FLAG_PIPE_CHECK)

/* read option */
#define SLIM_HTTP_STREAM_POOL_READ_DIRECT		1	/* do not use local buffer but specified buffer */
#define SLIM_HTTP_STREAM_POOL_READ_FORCE		2	/* read data from TCP/SSL forcely				*/

/*==================================================================*/
/* http stream pool 												*/
/*==================================================================*/

/* flag */
#define SLIM_HTTP_STRMPOOL_FLAG_NONE				0x00000000
#define SLIM_HTTP_STRMPOOL_FLAG_OMIT_CLOSENOTIFY	0x00000001
#define SLIM_HTTP_STRMPOOL_FLAG_TIMER_RESUMABLE		0x00000002

#define THTTPStreamPool_SetOmitCloseNotify(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STRMPOOL_FLAG_OMIT_CLOSENOTIFY,(val))
#define THTTPStreamPool_SetTimerResumable(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STRMPOOL_FLAG_TIMER_RESUMABLE,(val))
#define THTTPStreamPool_IsOmitCloseNotify(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STRMPOOL_FLAG_OMIT_CLOSENOTIFY)
#define THTTPStreamPool_IsTimerResumable(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_STRMPOOL_FLAG_TIMER_RESUMABLE)

#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG

#define THTTP_STREAM_POOL_DP(iself,arg) 	{if ((iself)->fPrintfProc) {(*(iself)->fPrintfProc) arg ;}}
#define HSP_NTFY(iself,desc,ev)	\
	{if ((iself)->fNotifyProc) {(*(iself)->fNotifyProc)((desc), &((iself)->fEntries[desc]),(ev));}}
#define HSP_TCP_NTFY(iself,desc,ev)	\
	{if ((iself)->fNotifyProc) {(*(iself)->fNotifyProc)((slim_int)(desc), slim_nil, (ev));}}
#else
/* dummy */
#define THTTPStreamPool_DebugDump(iself)	{}
#define THTTP_STREAM_POOL_DP(iself,arg) 	{}
#define HSP_NTFY(iself,desc,ev)				{}
#define HSP_TCP_NTFY(iself,desc,ev)			{}
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */

#define THTTP_STREAM_POOL_NTFY_OPEN(iself,desc)			  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_OPEN)
#define THTTP_STREAM_POOL_NTFY_CLOSE(iself,desc)		  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_CLOSE)
#define THTTP_STREAM_POOL_NTFY_CONNECT(iself,desc)		  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_CONNECT)
#define THTTP_STREAM_POOL_NTFY_CONNECTED(iself,desc)	  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_CONNECTED)
#define THTTP_STREAM_POOL_NTFY_TCP_OPEN(iself,desc)		  HSP_TCP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_TCP_OPEN)
#define THTTP_STREAM_POOL_NTFY_TCP_CLOSE(iself,desc)	  HSP_TCP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_TCP_CLOSE)
#define THTTP_STREAM_POOL_NTFY_TCP_CONNECT(iself,desc)	  HSP_TCP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_TCP_CONNECT)
#define THTTP_STREAM_POOL_NTFY_TCP_CONNECTED(iself,desc)  HSP_TCP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_TCP_CONNECTED)
#define THTTP_STREAM_POOL_NTFY_SET_KEEP_ALIVE(iself,desc) HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SET_KEEP_ALIVE)
#define THTTP_STREAM_POOL_NTFY_SSL_START(iself,desc)	  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SSL_START)
#define THTTP_STREAM_POOL_NTFY_SSL_SEND_PROXY(iself,desc) HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SSL_SEND_PROXY)
#define THTTP_STREAM_POOL_NTFY_SSL_RECV_PROXY(iself,desc) HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SSL_RECV_PROXY)
#define THTTP_STREAM_POOL_NTFY_SSL_PROXY_AUTH(iself,desc) HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SSL_PROXY_AUTH)
#define THTTP_STREAM_POOL_NTFY_SSL_HANDSHAKE(iself,desc)  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SSL_HANDSHAKE)
#define THTTP_STREAM_POOL_NTFY_SSL_DONE(iself,desc)		  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_SSL_DONE)
#define THTTP_STREAM_POOL_NTFY_WRITE(iself,desc)		  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_WRITE)
#define THTTP_STREAM_POOL_NTFY_FINISH_WRITE(iself,desc)	  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_FINISH_WRITE)
#define THTTP_STREAM_POOL_NTFY_READ(iself,desc)			  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_READ)
#define THTTP_STREAM_POOL_NTFY_FINISH_READ(iself,desc)	  HSP_NTFY((iself),(desc),THTTP_STREAM_POOL_EV_FINISH_READ)

#define THTTPStreamPool_IsKeepAlive(iself, in_desc)			\
	THTTPStreamPool_CheckFlag(iself, in_desc, SLIM_HTTP_TCP_STREAM_FLAG_KEEP_ALIVE)
#define THTTPStreamPool_IsSSLProxyAuthFail(iself, in_desc)	\
	THTTPStreamPool_CheckFlag(iself, in_desc, SLIM_HTTP_TCP_STREAM_FLAG_SSL_PROXY_AUTH_FAIL)
#define THTTPStreamPool_IsSSLReuseTry(iself, in_desc)		\
	THTTPStreamPool_CheckFlag(iself, in_desc, SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_TRY)
#define THTTPStreamPool_IsSSLReuseSuccess(iself, in_desc)	\
	THTTPStreamPool_CheckFlag(iself, in_desc, SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_SUCCESS)
#define THTTPStreamPool_IsSSLConFailContent(iself, in_desc)	\
	THTTPStreamPool_CheckFlag(iself, in_desc, SLIM_HTTP_TCP_STREAM_FLAG_SSL_CONFAIL_CONTENT)
#define THTTPStreamPool_IsClosedByServer(iself, in_desc)	\
	THTTPStreamPool_CheckFlag(iself, in_desc, SLIM_HTTP_TCP_STREAM_FLAG_CLOSED_BY_SERVER)


/*==================================================================*/
/* http: authentication 											*/
/*==================================================================*/

#define SLIM_HTTP_AUTH_PATH_SAME		SLIM_INET_PATH_SAME
#define SLIM_HTTP_AUTH_PATH_ANCESTOR	SLIM_INET_PATH_ANCESTOR
#define SLIM_HTTP_AUTH_PATH_DESCENDANT	SLIM_INET_PATH_DESCENDANT
#define SLIM_HTTP_AUTH_PATH_COUSIN		SLIM_INET_PATH_COUSIN

#define SLIM_HTTP_AUTH_TARGET_TO_BIT(type)	(1 << (type))
#define SLIM_HTTP_AUTH_TARGET_BIT_PAGE		SLIM_HTTP_AUTH_TARGET_TO_BIT(SLIM_HTTP_AUTH_TARGET_PAGE)
#define SLIM_HTTP_AUTH_TARGET_BIT_PROXY		SLIM_HTTP_AUTH_TARGET_TO_BIT(SLIM_HTTP_AUTH_TARGET_PROXY)
#define SLIM_HTTP_AUTH_TARGET_BIT_ALL		(SLIM_HTTP_AUTH_TARGET_BIT_PAGE | SLIM_HTTP_AUTH_TARGET_BIT_PROXY)

#define SLIM_HTTP_AUTH_INFO_VALID			0x00000001	/* need auth dialog or not */
#define SLIM_HTTP_AUTH_INFO_KEEP_USER		0x00000002	/* for serialization */
#define SLIM_HTTP_AUTH_INFO_KEEP_PASS		0x00000004	/* for serialization */
#define SLIM_HTTP_AUTH_INFO_AUTHORIZED		0x00000008	/* available for auto crawl or not */

/*----------------------------------------------------------*/
/* http auth entry											*/
/*----------------------------------------------------------*/

#define THTTPAuthEntry_Host(iself)			((iself)->fHost)
#define THTTPAuthEntry_Port(iself)			((iself)->fPort)
#define THTTPAuthEntry_Target(iself)		((iself)->fTarget)


/*----------------------------------------------------------*/
/* http auth info											*/
/*----------------------------------------------------------*/


#define THTTPAuthInfo_Challenge(iself)		((iself)->fChallenge)
#define THTTPAuthInfo_Flag(iself)			((iself)->fFlag)
#define THTTPAuthInfo_Valid(iself)			(((iself)->fFlag & SLIM_HTTP_AUTH_INFO_VALID) ? slim_true : slim_false)
#define THTTPAuthInfo_KeepUser(iself)		(((iself)->fFlag & SLIM_HTTP_AUTH_INFO_KEEP_USER) ? slim_true : slim_false)
#define THTTPAuthInfo_KeepPass(iself)		(((iself)->fFlag & SLIM_HTTP_AUTH_INFO_KEEP_PASS) ? slim_true : slim_false)
#define THTTPAuthInfo_Authorized(iself)		(((iself)->fFlag & SLIM_HTTP_AUTH_INFO_AUTHORIZED) ? slim_true : slim_false)
#define THTTPAuthInfo_TransferUser(iself, user)		{*(user) = (iself)->fUser; (iself)->fUser = slim_nil;}
#define THTTPAuthInfo_TransferPass(iself, pass)		{*(pass) = (iself)->fPass; (iself)->fPass = slim_nil;}
#define THTTPAuthInfo_TransferRealm(iself, realm)	{*(realm) = (iself)->fRealm; (iself)->fRealm = slim_nil;}

/*----------------------------------------------------------*/
/* http auth node											*/
/*----------------------------------------------------------*/

#define THTTPAuthNode_Type(iself)			((iself)->fType)
#define THTTPAuthNode_Path(iself)			((iself)->fPath)

/*----------------------------------------------------------*/
/* http auth cache											*/
/*----------------------------------------------------------*/
#ifdef SLIM_CONFIG_HTTP_AUTH_DEBUG

#define SLIM_HTTP_AUTH_DPW(iself, args)			\
{												\
	if ((iself)->fDebugPrintfProc) {			\
		(*(iself)->fDebugPrintfProc) args ;		\
	}											\
}
#define SLIM_HTTP_AUTH_DP(iself, args)			\
{												\
	if ((iself)->fDebugPrintfProc) {			\
		(*(iself)->fDebugPrintfProc) args ;		\
		(*(iself)->fDebugPrintfProc) ("\r\n");	\
	}											\
}
#define SLIM_HTTP_AUTH_NTFY(iself)				\
{												\
	if ((iself)->fDebugNotifyProc) {			\
		(*(iself)->fDebugNotifyProc)(iself);	\
	}											\
}
#else
#define SLIM_HTTP_AUTH_DPW(iself, args)			{}
#define SLIM_HTTP_AUTH_DP(iself, args)			{}
#define SLIM_HTTP_AUTH_NTFY(iself)				{}
#endif /* SLIM_CONFIG_HTTP_AUTH_DEBUG */

#define THTTPAuthCache_SetUserPass(iself,target,type,in_host,in_port,in_user,in_pass,in_path,in_realm,in_challenge) \
  THTTPAuthCache_SetUserPassX((iself),(target),(type),(in_host),(in_port),(in_user),(in_pass),(in_path),(in_realm),(in_challenge),slim_false,slim_false)
#define THTTPAuthCache_GetInfo(iself, pix, info)	(TTree_GetItem(&(iself)->fBase, pix, info, sizeof(THTTPAuthInfo)))
#define THTTPAuthCache_Unserialize(iself,buf,len,key) THTTPAuthCache_Deserialize((iself),(buf),(len),(key))

#define THTTPAuthCache_RemovePageEntries(iself)											\
{																						\
	THTTPAuthCache_RemoveEntries(iself, slim_nil, -1, SLIM_HTTP_AUTH_TARGET_BIT_PAGE);	\
}
#define THTTPAuthCache_RemoveProxyEntries(iself)										\
{																						\
	THTTPAuthCache_RemoveEntries(iself, slim_nil, -1, SLIM_HTTP_AUTH_TARGET_BIT_PROXY);	\
}
#define THTTPAuthCache_MakeEmpty(iself)													\
{																						\
	THTTPAuthCache_RemoveEntries(iself, slim_nil, -1, SLIM_HTTP_AUTH_TARGET_BIT_ALL);	\
	SLIM_ASSERT((iself)->fCurEntries == 0);												\
}

/*==================================================================*/
/* http cookie 														*/
/*==================================================================*/

#define HTTPCookieEntry_New0() ((THTTPCookieEntry)slim_handle_zeroalloc(sizeof(iTHTTPCookieEntry)))
#define THTTPCookieEntry_Delete0(self) (slim_handle_free((slim_handle)(self)))
#define THTTPCookieEntry_Lock(self) ((iTHTTPCookieEntry *)slim_handle_lock((slim_handle)(self)))
#define THTTPCookieEntry_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define THTTPCookieEntry_Locate(self) ((iTHTTPCookieEntry *)slim_handle_locate((slim_handle)(self)))
#define THTTPCookieEntry_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))
#define THTTPCookies_SetHandleReceivedCookieProc(self, in_func, in_aux) ((self)->fHandleReceivedCookieProc = (in_func), (self)->fHandleReceivedCookieAux = in_aux)

/*----------------------------------------------------------*/
/* HTTP Header Restriction	 								*/
/*----------------------------------------------------------*/
#define SLIM_HPHDR_RESTRICT_BIT_OP(w,i,b)	((b) ? ((w) |= (1 << i)) : ((w) &= ~(1 << i)))
#define SLIM_HPHDR_RESTRICT_BIT_CK(w,i)		(((w) & (1 << i)) != 0)

/* multi application */

/*==================================================================*/
/* http: stream 													*/
/*==================================================================*/

#define SLIM_HTTP_STREAM_TEXT_CRLF		SLIM_T("\015\012")
#define SLIM_HTTP_STREAM_TEXT_CRLFCRLF 	SLIM_T("\015\012\015\012")
#define SLIM_HTTP_STREAM_TEXT_CRCR 		SLIM_T("\015\015")
#define SLIM_HTTP_STREAM_TEXT_LFLF 		SLIM_T("\012\012")

#define HTTPStream_SetMaxReqMsgHeader(in_class, size)	{(in_class)->fMaxReqMsgHeader = (size);}
#define HTTPStream_SetCustomizeHeaderProc(cls, proc, aux) ((void)((cls)->fCustomizeHeaderProc = (proc), (cls)->fCustomizeHeaderAux = (slim_opaque)(aux)))


#define HTTPStream_SetProxyResolved(in_class,val)	SLIM_FLAG_OP((in_class),SLIM_HTTP_STREAM_FLAG_PROXY_RESOLVED,(val))
#define HTTPStream_SetSendReferer(in_class,val)		SLIM_FLAG_OP((in_class),SLIM_HTTP_STREAM_FLAG_SEND_REFERER,(val))
#define HTTPStream_SetSendProxyKeepAlive(in_class,val)	SLIM_FLAG_OP((in_class),SLIM_HTTP_STREAM_FLAG_SEND_PROXYKEEPALIVE,(val))
#define HTTPStream_SetSendCookie(in_class,val)	SLIM_FLAG_OP((in_class),SLIM_HTTP_STREAM_FLAG_SEND_COOKIE,(val))
#define HTTPStream_SetHandleReceivedCookieProc(self, in_func, in_aux) THTTPCookies_SetHandleReceivedCookieProc(&(self)->fCookie, (in_func), (in_aux))

#define HTTPStream_IsProxyResolved(in_class) 		SLIM_FLAG_CK((in_class),SLIM_HTTP_STREAM_FLAG_PROXY_RESOLVED)
#define HTTPStream_IsSendReferer(in_class)			SLIM_FLAG_CK((in_class),SLIM_HTTP_STREAM_FLAG_SEND_REFERER)
#define HTTPStream_IsSendProxyKeepAlive(in_class)	SLIM_FLAG_CK((in_class),SLIM_HTTP_STREAM_FLAG_SEND_PROXYKEEPALIVE)
#define HTTPStream_IsSendCookie(in_class)			SLIM_FLAG_CK((in_class),SLIM_HTTP_STREAM_FLAG_SEND_COOKIE)


/*------------------------------*/
/* method						*/
/*------------------------------*/

#define THTTPStream_Lock(self) ((iTHTTPStream *)slim_handle_lock((slim_handle)(self)))
#define THTTPStream_Unlock(self) (slim_handle_unlock((slim_handle)(self)))
#define THTTPStream_Locate(self) ((iTHTTPStream *)slim_handle_locate((slim_handle)(self)))
#define THTTPStream_Unlocate(self) (slim_handle_unlocate((slim_handle)(self)))


#define iTHTTPStream_IsSSL(iself)	((iself)->fScheme == SLIM_HTTP_SCHEME_HTTPS)

/* flag operation */
#define SLIM_HTTP_STREAM_FLAG_PIPELINE				0x00000001
#define SLIM_HTTP_STREAM_FLAG_POST_AS_STRING		0x00000002
#define SLIM_HTTP_STREAM_FLAG_CONNECT_VIA_PROXY		0x00000004
#define SLIM_HTTP_STREAM_FLAG_HEADER_CREATED		0x00000008
#define SLIM_HTTP_STREAM_FLAG_HEADER_RECEIVED		0x00000010
#define SLIM_HTTP_STREAM_FLAG_CHUNKED				0x00000020
#define SLIM_HTTP_STREAM_FLAG_LAST_CHUNK			0x00000040
#define SLIM_HTTP_STREAM_FLAG_TRAILER				0x00000080
#define SLIM_HTTP_STREAM_FLAG_KEEP_ALIVE			0x00000100
#define SLIM_HTTP_STREAM_FLAG_CONNECTION_CLOSE		0x00000200
#define SLIM_HTTP_STREAM_FLAG_SSL_REUSE_TRY			0x00000400
#define SLIM_HTTP_STREAM_FLAG_SSL_REUSE_SUCCESS		0x00000800
#define SLIM_HTTP_STREAM_FLAG_PORT_SPECIFIED 		0x00001000
#define SLIM_HTTP_STREAM_FLAG_POST_AS_PLAINTEXT		0x00002000
#define SLIM_HTTP_STREAM_FLAG_ENCODED_DEFLATE		0x00004000
#define SLIM_HTTP_STREAM_FLAG_ENCODED_GZIP			0x00008000
#define SLIM_HTTP_STREAM_FLAG_ENDENDSSL				0x00010000
#define SLIM_HTTP_STREAM_FLAG_WAIT_PROXYRSP_CONFIRM	0x00020000
#define SLIM_HTTP_STREAM_FLAG_DISABLE_INFLATE		0x00040000
#define SLIM_HTTP_STREAM_FLAG_CONTENT_ENCODED		0x00080000

#define iTHTTPStream_SetPipeline(iself,val) 		SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_PIPELINE,(val))
#define iTHTTPStream_SetPostAsString(iself,val) 	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_POST_AS_STRING,(val))
#define iTHTTPStream_SetConnectViaProxy(iself,val) 	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_CONNECT_VIA_PROXY,(val))
#define iTHTTPStream_SetHeaderCreated(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_HEADER_CREATED,(val))
#define iTHTTPStream_SetHeaderReceived(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_HEADER_RECEIVED,(val))
#define iTHTTPStream_SetChunked(iself,val)			SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_CHUNKED,(val))
#define iTHTTPStream_SetLastChunk(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_LAST_CHUNK,(val))
#define iTHTTPStream_SetTrailer(iself,val)			SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_TRAILER,(val))
#define iTHTTPStream_SetKeepAlive(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_KEEP_ALIVE,(val))
#define iTHTTPStream_SetConnectionClose(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_CONNECTION_CLOSE,(val))
#define iTHTTPStream_SetSSLReuseTry(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_SSL_REUSE_TRY,(val))
#define iTHTTPStream_SetSSLReuseSuccess(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_SSL_REUSE_SUCCESS,(val))
#define iTHTTPStream_SetPortSpecified(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_PORT_SPECIFIED,(val))
#define iTHTTPStream_SetPostAsPlainText(iself,val) 	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_POST_AS_PLAINTEXT,(val))
#define iTHTTPStream_SetEncodedDeflate(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_ENCODED_DEFLATE,(val))
#define iTHTTPStream_SetEncodedGzip(iself,val)		SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_ENCODED_GZIP,(val))
#define iTHTTPStream_SetWaitProxyRspConfirm(iself,val) SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_WAIT_PROXYRSP_CONFIRM,(val))
#define iTHTTPStream_SetDisableInflate(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_DISABLE_INFLATE,(val))
#define iTHTTPStream_SetContentEncoded(iself,val)	SLIM_FLAG_OP((iself),SLIM_HTTP_STREAM_FLAG_CONTENT_ENCODED,(val))

#define iTHTTPStream_IsPipeline(iself)				SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_PIPELINE)
#define iTHTTPStream_IsPostAsString(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_POST_AS_STRING)
#define iTHTTPStream_IsConnectViaProxy(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_CONNECT_VIA_PROXY)
#define iTHTTPStream_IsHeaderCreated(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_HEADER_CREATED)
#define iTHTTPStream_IsHeaderReceived(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_HEADER_RECEIVED)
#define iTHTTPStream_IsChunked(iself)				SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_CHUNKED)
#define iTHTTPStream_IsLastChunk(iself)				SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_LAST_CHUNK)
#define iTHTTPStream_IsTrailer(iself)				SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_TRAILER)
#define iTHTTPStream_IsKeepAlive(iself)				SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_KEEP_ALIVE)
#define iTHTTPStream_IsConnectionClose(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_CONNECTION_CLOSE)
#define iTHTTPStream_IsSSLReuseTry(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_SSL_REUSE_TRY)
#define iTHTTPStream_IsSSLReuseSuccess(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_SSL_REUSE_SUCCESS)
#define iTHTTPStream_IsPortSpecified(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_PORT_SPECIFIED)
#define iTHTTPStream_IsPostAsPlainText(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_POST_AS_PLAINTEXT)
#define iTHTTPStream_IsEncodedDeflate(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_ENCODED_DEFLATE)
#define iTHTTPStream_IsEncodedGzip(iself)			SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_ENCODED_GZIP)
#define iTHTTPStream_IsEncoded(iself)				(iTHTTPStream_IsEncodedDeflate(iself) || iTHTTPStream_IsEncodedGzip(iself))
#define iTHTTPStream_IsWaitProxyRspConfirm(iself)	SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_WAIT_PROXYRSP_CONFIRM)
#define iTHTTPStream_IsDisableInflate(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_DISABLE_INFLATE)
#define iTHTTPStream_IsContentEncoded(iself)		SLIM_FLAG_CK((iself),SLIM_HTTP_STREAM_FLAG_CONTENT_ENCODED)


/*------------------------------*/
/* http stream debug			*/
/*------------------------------*/
#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG

#define HTTP_STREAM_DP(iself,arg) 		{if ((iself)->fPrintfProc) {(*(iself)->fPrintfProc) arg ;}}
#define THTTP_STREAM_DP(iself,arg) 		{if ((iself)->fClass->fPrintfProc) {(*(iself)->fClass->fPrintfProc) arg ;}}
#define THTTP_STREAM_NTFY_STATE(iself)	{if ((iself)->fClass->fNotifyProc) {(*(iself)->fClass->fNotifyProc)(iself);}}
#define DUMP_IPADDR(addr)	(addr)[0],(addr)[1],(addr)[2],(addr)[3]
#else
#define THTTPStream_DebugDump(self, in_precise)	{}
#define HTTPStream_DebugDump_CacheDNSEntry(in_class, in_entry) {}
#define HTTPStream_DebugDump(in_class)			{}
#define HTTP_STREAM_DP(iself,arg) 				{}
#define THTTP_STREAM_DP(iself,arg) 				{}
#define THTTP_STREAM_NTFY_STATE(iself)			{}
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */

#endif /* SLIM_CONFIG_USE_HTTP */

SLIM_END_C_LINKAGE
#endif
