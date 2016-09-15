/*
	httpstrm.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/httpstrm.h 212   06/09/08 11:25 Iida $ */

#ifndef SLIM_HTTPSTRM_H
#define SLIM_HTTPSTRM_H

#ifndef SLIM_LIBSSL_H
#include <slim/libssl.h>
#endif
#ifndef SLIM_TOKEN_HPDHRID_H
#include <slim/token/hphdrid.h>
#endif
#include <slim/inet/postdata.h>

SLIM_BEGIN_C_LINKAGE

/*==================================================================*/
/* http stream pool 												*/
/*==================================================================*/
#ifndef SLIM_HTTP_STREAM_MAX_STREAMS
#define SLIM_HTTP_STREAM_MAX_STREAMS	4
#endif

#ifndef SLIM_HTTP_STREAM_MAX_ENTRIES
#define SLIM_HTTP_STREAM_MAX_ENTRIES	16
#endif

#ifndef SLIM_HTTP_STREAM_READ_CHUNK
#define SLIM_HTTP_STREAM_READ_CHUNK		2048
#endif

#ifndef SLIM_HTTP_STREAM_MAX_RETRY
#define SLIM_HTTP_STREAM_MAX_RETRY		2
#endif

#ifndef SLIM_HTTP_STREAM_COOKIE_MAX_ENTRIES
#define SLIM_HTTP_STREAM_COOKIE_MAX_ENTRIES				1000
#endif

#ifndef SLIM_HTTP_STREAM_COOKIE_MAX_ENTRIES_PER_DOMAIN
#define SLIM_HTTP_STREAM_COOKIE_MAX_ENTRIES_PER_DOMAIN	10
#endif

#ifndef SLIM_HTTP_STREAM_COOKIE_MAX_LEN
#define SLIM_HTTP_STREAM_COOKIE_MAX_LEN					4096
#endif

#ifndef SLIM_HTTP_STREAM_MAX_AUTH_ENTRIES
#define SLIM_HTTP_STREAM_MAX_AUTH_ENTRIES	(SLIM_HTTP_STREAM_MAX_STREAMS + 1)
#endif

#ifndef SLIM_HTTP_STREAM_MIN_CHUNK_CONTROLS
#define SLIM_HTTP_STREAM_MIN_CHUNK_CONTROLS	16
#endif

#ifndef SLIM_HTTP_STREAM_KEEP_ALIVE_LATENCY
#define SLIM_HTTP_STREAM_KEEP_ALIVE_LATENCY 500	/* ms */
#endif

#ifndef SLIM_HTTP_STREAM_MSS
#define SLIM_HTTP_STREAM_MSS 1460
#endif

#ifndef SLIM_HTTP_STREAM_MAX_REFCOUNT
#define SLIM_HTTP_STREAM_MAX_REFCOUNT	4
#endif

#define SLIM_HTTP_STREAM_DEFAULT_HTTP_PORT			80
#define SLIM_HTTP_STREAM_DEFAULT_HTTPS_PORT			443

/*----------------------------------------------------------*/
/* http tcp stream											*/
/*----------------------------------------------------------*/

typedef struct TSSLSocketInfo_ TSSLSocketInfo;

typedef slim_int (*TSocketOpenProc)(slim_opaque in_user_data, slim_int in_domain, slim_opaque *out_desc);
typedef void (*TSocketCloseProc)(slim_opaque in_user_data, slim_opaque in_desc);
typedef slim_int (*TSocketConnectProc)(slim_opaque in_user_data, slim_opaque in_desc, slim_ip_addr *in_addr, slim_int in_port);
typedef slim_int (*TSocketIsConnectedProc)(slim_opaque in_user_data, slim_opaque in_desc);
typedef slim_int (*TSocketReadProc)(slim_opaque in_user_data, slim_opaque in_desc,  slim_byte *out_buf, slim_int in_len);
typedef slim_int (*TSocketWriteProc)(slim_opaque in_user_data, slim_opaque in_desc, slim_byte *in_buf, slim_int in_len);
typedef slim_int (*TSocketCheckReadWriteProc)(slim_opaque in_user_data, slim_opaque in_desc, slim_int in_rw);
typedef slim_int (*TSocketCheckKeepAliveProc)(slim_opaque in_user_data, slim_opaque in_desc);
typedef void (*TSocketShutdownProc)(slim_opaque in_user_data, slim_opaque in_desc);

typedef slim_int (*TSocketSSLUpgradeProc)(slim_opaque in_user_data, slim_opaque in_desc, slim_int in_ssl_flag,
											slim_char *in_url_host,	slim_int in_url_len, slim_int in_url_port);
typedef slim_int (*TSocketDoSSLHandshakeProc)(slim_opaque in_user_data, slim_opaque in_desc);
typedef void (*TSocketGetSSLInfoProc)(slim_opaque in_user_data, slim_opaque in_desc, TSSLSocketInfo *inout_info);

struct TSocketClass_ {
	slim_opaque fUserData;
	TSocketOpenProc fOpenProc;
	TSocketCloseProc fCloseProc;
	TSocketConnectProc fConnectProc;
	TSocketIsConnectedProc fIsConnectedProc;
	TSocketReadProc fReadProc;
	TSocketWriteProc fWriteProc;
	TSocketCheckReadWriteProc fCheckReadWriteProc;
	TSocketCheckKeepAliveProc fCheckKeepAliveProc;
	TSocketShutdownProc fShutdownProc;
};
typedef struct TSocketClass_ TSocketClass;

struct TTCPSocketClass_ {
	TSocketClass fBase;
};
typedef struct TTCPSocketClass_ TTCPSocketClass;

struct TSSLSocketClass_ {
	TSocketClass fBase;
	TSocketSSLUpgradeProc fUpgradeProc;
	TSocketDoSSLHandshakeProc fDoHandshakeProc;
	TSocketGetSSLInfoProc	fGetInfoProc;
};
typedef struct TSSLSocketClass_ TSSLSocketClass;

struct TSSLSocketInfo_ {
	slim_int fFlag;
	TSSLVersion fVersion;
	TSSLCipherSuite fCipherSuite;
	slim_int fVerificationResults;
	TCertList fServerCertList;
};

#define SLIM_SSLSOCKETINFO_VERSION				0x00000001
#define SLIM_SSLSOCKETINFO_CIPHER_SUITE			0x00000002
#define SLIM_SSLSOCKETINFO_SERVER_CERT_LIST		0x00000004

struct THTTPTCPStream_ {
	TSocketClass *fClass;
	slim_opaque fTCPDesc;			/* Stream descriptor						*/
	slim_ip_addr fConnectAddr;		/* host or proxy ip address	for actual connect	*/
	slim_int fConnectPort;			/* host or proxy port for actual connect	*/
	TFixedString fURLHost;			/* host in URL								*/
	slim_int fURLPort;				/* port in URL								*/
	slim_int fKeepAliveBaseTick;	/* keep alive base tick 					*/
	slim_int fKeepAliveTimeout;		/* keep alive timeout						*/
	slim_int fKeepAliveMax;			/* keep alive max count						*/
	slim_char fBuf[SLIM_HTTP_STREAM_READ_CHUNK];
									/* buffer for receive response				*/
	slim_int fBufOfs;				/* uncopied received bytes offset in buffer	*/
	slim_int fBufLen;				/* uncopied received bytes in buffer		*/
	slim_short fFlag;				/* flag of stream (keep alive, pipeline)	*/
	slim_short fRefCount;			/* reference count 							*/
	/* SSL */
	slim_int fSSLState;				/* SSL state								*/
#ifdef SLIM_CONFIG_HTTP_STREAM_USE_PIPELINE
	slim_short fWriterNum;			/* number of writer pool entries			*/
	slim_short fReaderNum;			/* number of reader pool entries			*/
#endif /* SLIM_CONFIG_HTTP_STREAM_USE_PIPELINE */
	slim_short fServerVersion;		/* server's HTTP version 	-1 = unavailable */
};
typedef struct THTTPTCPStream_ THTTPTCPStream;

/* flag operation */
#define SLIM_HTTP_TCP_STREAM_FLAG_OPENED				0x0001
#define SLIM_HTTP_TCP_STREAM_FLAG_KEEP_ALIVE			0x0002
#define SLIM_HTTP_TCP_STREAM_FLAG_PIPELINE				0x0004
#define SLIM_HTTP_TCP_STREAM_FLAG_PROXY					0x0008
#define SLIM_HTTP_TCP_STREAM_FLAG_SSL					0x0010
#define SLIM_HTTP_TCP_STREAM_FLAG_SSL_PROXY_AUTH_FAIL	0x0020
#define SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_TRY			0x0040
#define SLIM_HTTP_TCP_STREAM_FLAG_SSL_REUSE_SUCCESS		0x0080
#define SLIM_HTTP_TCP_STREAM_FLAG_SSL_CONFAIL_CONTENT	0x0100
#define SLIM_HTTP_TCP_STREAM_FLAG_CLOSED_BY_SERVER		0x0200

/*----------------------------------------------------------*/
/* http stream pool entry									*/
/*----------------------------------------------------------*/
struct THTTPStreamTimer_ {
	slim_short fSuspend;
	slim_short fEventType;
	slim_int fBaseTick;
	slim_int fSuspendTick;
};
typedef struct THTTPStreamTimer_ THTTPStreamTimer;

struct THTTPStreamPoolEntry_ {
	THTTPTCPStream *fPStream;		/* stream pool entry descriptor	(slim_nil = no stream)		*/
	slim_int fFlag;					/* flag (open, keep alive, pipeline stall)					*/
	THTTPStreamTimer fTimer;
#ifdef SLIM_CONFIG_HTTP_STREAM_USE_PIPELINE
	slim_short fOrderWrite;			/* order in wr_ite queue(>0 waiting, 0=writing, <0 written)	*/
	slim_short fOrderRead;			/* order in read queue	(>0 waiting, 0=reading, <0 read)	*/
#endif /* SLIM_CONFIG_HTTP_STREAM_USE_PIPELINE */
};
typedef struct THTTPStreamPoolEntry_ THTTPStreamPoolEntry;


/*----------------------------------------------------------*/
/* http stream pool											*/
/*----------------------------------------------------------*/
typedef struct THTTPStreamPool_ THTTPStreamPool;

#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
typedef void (*HTTPStreamPool_DebugPrintProc)(char *in_format, ...);
typedef void (*HTTPStreamPool_DebugNotifyProc)(slim_int in_desc, THTTPStreamPoolEntry *in_entry, slim_int in_ev);

enum {
	THTTP_STREAM_POOL_EV_OPEN = 0,
	THTTP_STREAM_POOL_EV_CLOSE,
	THTTP_STREAM_POOL_EV_CONNECT,
	THTTP_STREAM_POOL_EV_CONNECTED,
	THTTP_STREAM_POOL_EV_TCP_OPEN,
	THTTP_STREAM_POOL_EV_TCP_CLOSE,
	THTTP_STREAM_POOL_EV_TCP_CONNECT,
	THTTP_STREAM_POOL_EV_TCP_CONNECTED,
	THTTP_STREAM_POOL_EV_SET_KEEP_ALIVE,
	THTTP_STREAM_POOL_EV_SSL_START,
	THTTP_STREAM_POOL_EV_SSL_SEND_PROXY,
	THTTP_STREAM_POOL_EV_SSL_RECV_PROXY,
	THTTP_STREAM_POOL_EV_SSL_PROXY_AUTH,
	THTTP_STREAM_POOL_EV_SSL_HANDSHAKE,
	THTTP_STREAM_POOL_EV_SSL_DONE,
	THTTP_STREAM_POOL_EV_WRITE,
	THTTP_STREAM_POOL_EV_FINISH_WRITE,
	THTTP_STREAM_POOL_EV_READ,
	THTTP_STREAM_POOL_EV_FINISH_READ,
	THTTP_STREAM_POOL_EVS
};
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */

struct TSocketDesc_ {
	slim_int fTCPDesc;
	TSSL fSSL;
};
typedef struct TSocketDesc_ TSocketDesc;

struct TSocketDescContext_ {
	TSocketDesc fDesc[SLIM_HTTP_STREAM_MAX_STREAMS];
	TSSLClass *fSSLClass;
};
typedef struct TSocketDescContext_ TSocketDescContext;

struct THTTPStreamPool_ {
	/* classe for sockets */
	TTCPSocketClass fTCPSocketClass;
	TSSLSocketClass fSSLSocketClass;
	/* descriptors */
	TSocketDescContext fSocketDesc;	/* array of descriptors and pointer of SSLClass */
	/* attributes */
	slim_int fMaxStreams;											/* max streams 					*/
	slim_int fMaxKeepAliveTimeout;									/* max keepAlive streams		*/
	slim_int fMaxRefCount;											/* max refcount					*/
	THTTPTCPStream fStreams[SLIM_HTTP_STREAM_MAX_STREAMS];			/* array of streams 			*/
	THTTPStreamPoolEntry fEntries[SLIM_HTTP_STREAM_MAX_ENTRIES];	/* array of stream pool entries	*/
	slim_int fFlag;
#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
	HTTPStreamPool_DebugPrintProc fPrintfProc;	/* printf procedure				*/
	HTTPStreamPool_DebugNotifyProc fNotifyProc;/* callback procedure 			*/
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */
};


/*==================================================================*/
/* http: authentication 											*/
/*==================================================================*/
#ifdef SLIM_CONFIG_DEBUG
#ifdef SLIM_CONFIG_USE_HTTP
#define SLIM_CONFIG_HTTP_AUTH_DEBUG
#endif
#endif /* SLIM_CONFIG_DEBUG */

enum {
	SLIM_HTTP_AUTH_TYPE_NONE = -1,
	SLIM_HTTP_AUTH_TYPE_BASIC = 0,
	SLIM_HTTP_AUTH_TYPE_DIGEST,
	SLIM_HTTP_AUTH_TYPES
};

enum {
	SLIM_HTTP_AUTH_TARGET_NONE = -1,
	SLIM_HTTP_AUTH_TARGET_PAGE = 0,
	SLIM_HTTP_AUTH_TARGET_PROXY,
	SLIM_HTTP_AUTH_TARGETS
};

/*----------------------------------------------------------*/
/* http auth entry											*/
/*----------------------------------------------------------*/
struct THTTPAuthEntry_ {
	TFixedString fHost;
	slim_int fPort;
	slim_int fTarget;	/* page or proxy */
};
typedef struct THTTPAuthEntry_ THTTPAuthEntry;

/*----------------------------------------------------------*/
/* http auth info											*/
/*----------------------------------------------------------*/
struct THTTPAuthInfo_ {
	slim_int fFlag;		/* validation and serialization */
	TString fUser;		/* username	of realm			*/
	TString fPass;		/* password	of realm			*/
	TString fRealm;		/* realm of authentication		*/
	TString fChallenge;	/* challenge of authentication	*/
	TString fNextNonce;	/* nextnonce of auth-info header*/
	slim_word fNC;		/* nonce-count					*/
};
typedef struct THTTPAuthInfo_ THTTPAuthInfo;

/* API */
#ifndef SLIM_CONFIG_USE_HTTP
/* dummy */
#define THTTPAuthInfo_Tidy(iself, in_new)	{}
#else /* SLIM_CONFIG_USE_HTTP */
#define THTTPAuthInfo_User(iself)			((iself)->fUser)
#define THTTPAuthInfo_Pass(iself)			((iself)->fPass)
#define THTTPAuthInfo_Realm(iself)			((iself)->fRealm)
#endif /* SLIM_CONFIG_USE_HTTP */

/*----------------------------------------------------------*/
/* http auth node											*/
/*----------------------------------------------------------*/
struct THTTPAuthNode_ {
	slim_int fType;	/* basic or digest */
	TString fPath;	/* path */
};
typedef struct THTTPAuthNode_ THTTPAuthNode;

/*----------------------------------------------------------*/
/* http auth cache											*/
/*----------------------------------------------------------*/
typedef struct THTTPAuthCache_ THTTPAuthCache;

#ifdef SLIM_CONFIG_HTTP_AUTH_DEBUG
typedef void (*HTTPAuthCache_DebugPrintProc)(char *in_format, ...);
typedef void (*HTTPAuthCache_DebugNotifyProc)(THTTPAuthCache *in_auth);
#endif /* SLIM_CONFIG_HTTP_AUTH_DEBUG */

typedef TString (*THTTPAuthMakeCredProc)(slim_int in_target, THTTPAuthInfo *in_info, slim_char *in_method, 
										 TURLString in_url, slim_byte *in_entity_hash);
/* for serialization */
typedef slim_int (*THTTPAuthHashKeyProc)(slim_byte *in_key, slim_byte *out_buf);
typedef slim_int (*THTTPAuthEncodeStringProc)(slim_byte *in_str, slim_byte *in_key, slim_byte *out_buf);
typedef TString (*THTTPAuthDecodeStringProc)(slim_byte *in_str, slim_int in_len, slim_byte *in_key);

struct THTTPAuthCache_ {
	TTree fBase;
	slim_int fMaxEntries;
	slim_int fCurEntries;
	slim_pix fEntryHead;
	THTTPAuthMakeCredProc fMakeCredProc[SLIM_HTTP_AUTH_TYPES];
	THTTPAuthHashKeyProc fHashKeyProc;
	THTTPAuthEncodeStringProc fEncodeStringProc;
	THTTPAuthDecodeStringProc fDecodeStringProc;

#ifdef SLIM_CONFIG_HTTP_AUTH_DEBUG
	HTTPAuthCache_DebugPrintProc fDebugPrintfProc;
	HTTPAuthCache_DebugNotifyProc fDebugNotifyProc;
#endif /* SLIM_CONFIG_HTTP_AUTH_DEBUG */
};

/*==================================================================*/
/* http cookie 														*/
/*==================================================================*/
#ifdef SLIM_CONFIG_DEBUG
#ifdef SLIM_CONFIG_USE_HTTP
#define SLIM_CONFIG_HTTP_COOKIE_DEBUG
#endif
#endif /* SLIM_CONFIG_DEBUG */

typedef struct THTTPCookies_ THTTPCookies;
typedef struct iTHTTPCookieEntry_ iTHTTPCookieEntry;
typedef struct iTHTTPCookieEntry_ **THTTPCookieEntry;
typedef struct THTTPCookie_ THTTPCookie;

typedef slim_bool (*THTTPCookiesCookieCallback)(THTTPCookies *in_cookies, TURLString in_url, 
												slim_char *in_cookie_str, slim_int in_cookie_len, 
												slim_opaque in_aux);
typedef slim_int (*THTTPCookies_HandleReceivedCookieProc)(THTTPCookies *in_cookies, THTTPCookie *inout_cookie, slim_time *in_cur_time, slim_opaque in_aux);
typedef slim_bool (*THTTPCookiesRemoveCandidateCallback)(THTTPCookies *self, THTTPCookieEntry in_cur_entry, THTTPCookieEntry *inout_same_entry, THTTPCookieEntry *inout_total_least_entry, THTTPCookieEntry *inout_domain_least_entry);
#ifdef SLIM_CONFIG_HTTP_COOKIE_DEBUG
enum {
	SLIM_HTTPCOOKIE_DBGNOTIFY_ADD,
	SLIM_HTTPCOOKIE_DBGNOTIFY_DELETE
};

typedef void (*THTTPCookiesDebugNotifyProc)(THTTPCookieEntry in_entry, slim_int in_notify, slim_opaque in_aux);
#endif

struct iTHTTPCookieEntry_ {
	THTTPCookieEntry fPrev;
	THTTPCookieEntry fNext;
	TString fName;
	TString fValue;
	TString fDomain;
	TString fPath;
#ifdef SLIM_CONFIG_MORESPEED
	slim_short fNameLen;
	slim_short fValueLen;
	slim_short fDomainLen;
	slim_short fPathLen;
#endif
	slim_time fExpires;
	slim_int fFlag;
};

struct THTTPCookie_ {
	slim_int fFlag;
	slim_split_ss fURLHost;
	slim_split_ss fURLPath;
	slim_split_ss fName;
	slim_split_ss fValue;
	slim_split_ss fComment;
	slim_split_ss fDomain;
	slim_time fExpires;
	slim_split_ss fPath;
};

#define SLIM_HTTPCOOKIE_VALID_EXPIRES		0x00000001
#define SLIM_HTTPCOOKIE_IS_SECURE			0x00000002
#define SLIM_HTTPCOOKIE_DOMAIN_SPECIFIED	0x00000004
#define SLIM_HTTPCOOKIE_PATH_SPECIFIED		0x00000008
#define SLIM_HTTPCOOKIE_RFC2109_COOKIE		0x00000010

#define SLIM_HTTPCOOKIE_VERSION_MASK		(SLIM_HTTPCOOKIE_RFC2109_COOKIE)

struct THTTPCookies_ {
	slim_int fFlag;
	slim_int fCookieMode;		/* cookie set mode					*/
	slim_opaque fCookieAux;		/* cookie callback aux				*/
	THTTPCookiesCookieCallback fCookieCallback;						/* cookie dialog callback */
	THTTPCookiesRemoveCandidateCallback fRemoveCandidateCallback;	/* cookie dialog callback */
	THTTPCookies_HandleReceivedCookieProc fHandleReceivedCookieProc;			/* new cookie dialog callback */
	slim_opaque fHandleReceivedCookieAux;
	THTTPCookieEntry fHead;
	THTTPCookieEntry fTail;
	slim_int fMaxTotalCookies;
	slim_int fMaxCookiesPerDomain;
	slim_int fMaxLenPerCookie;
#ifdef SLIM_CONFIG_HTTP_COOKIE_DEBUG
	THTTPCookiesDebugNotifyProc fDebugNotifyProc;
	slim_opaque fDebugNotifyAux;
#endif
	slim_int fTotalCookiesLen;
	slim_int fMaxTotalCookiesLen;
};

/*
 * If this flag is set, quote(") in attr leads to format error.
 * This behavior is compliant with RFC2109/2965. But IE/Mozilla
 * which support only NS cookie treat quote as just character.
 *
 * You can use this flag in order to keep the compatibility
 * with these browser's behavior.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_STRICT_ATTR_FORMAT		0x00000001

/*
 * If this flag is set, browser ignores quote in attr and
 * treats it as normal character. not special delimiter.
 *
 * You can use this flag if you want to support only NS cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_IGNORE_AQUOTE			0x00000002

/*
 * If this flag is set, browser ignores quote in value and
 * treats it as normal character. not special delimiter.
 *
 * You can use this flag if you want to support only NS cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_IGNORE_VQUOTE			0x00000004

/*
 * Expires is ignored if this flag is set.
 *
 * You can use this flag if you want to support only RFC cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_IGNORE_EXPIRES			0x00000008

/*
 * Max-Age is ignored if this flag is set.
 *
 * You can use this flag if you want to support only NS cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_IGNORE_MAXAGE			0x00000010

/*
 * Version is ignored if this flag is set.
 *
 * You can use this flag if you want to support only NS cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_IGNORE_VERSION			0x00000040

/*
 * If this flag is set, Request-URI "foobar.com" is not
 * matched with Domain=".foobar.com".
 *
 * You can use this flag if you want to support only RFC cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_STRICT_DOMAIN			0x00000080

/*
 * If this flag is set, a cookie is accepted
 * which has the value for the Domain attribute doesn't start with a dot.
 *
 * this flag is valid only if a cookie is RFC cookie.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_ALLOW_NONLEADDOT_DOMAIN	0x00000100

/*
 * If this flag is set, 'document.cookie = "foo";' is
 * evaluated as (name, value) = ("foo", ). :Opera's behavior.
 * Otherwise, as (name, value) = ( ,"foo"). : IE/Mozilla's behavior.
 *
 * You can use this flag in order to keep the compatibility
 * with old version (-v3.3) of NetFront's behavior.
 *
 * Default: OFF
 */
#define SLIM_HTTPCOOKIES_TREAT_NONPAIRDATA_AS_NAME	0x00000200

/*
 * For comvenience, we define the following symbols.
 *
 * NS Cookie      : IGNORE_AQUOTE | IGNORE_VQUOTE | IGNORE_MAXAGE | IGNORE_VERSION
 * RFC2109 Cookie : STRICT_ATTR_FORMAT | IGNORE_EXPIRES | STRICT_DOMAIN
 */
#define SLIM_HTTPCOOKIES_STRICT_NS_COOKIE		(SLIM_HTTPCOOKIES_IGNORE_AQUOTE  | \
												 SLIM_HTTPCOOKIES_IGNORE_VQUOTE  | \
												 SLIM_HTTPCOOKIES_IGNORE_MAXAGE  | \
												 SLIM_HTTPCOOKIES_IGNORE_VERSION)

#define SLIM_HTTPCOOKIES_STRICT_RFC2109_COOKIE	(SLIM_HTTPCOOKIES_STRICT_ATTR_FORMAT | \
												 SLIM_HTTPCOOKIES_IGNORE_EXPIRES     | \
												 SLIM_HTTPCOOKIES_STRICT_DOMAIN)

#ifndef SLIM_HTTPCOOKIES_DEFAULT_FLAG
#define SLIM_HTTPCOOKIES_DEFAULT_FLAG	SLIM_HTTPCOOKIES_STRICT_NS_COOKIE
#endif

/*==================================================================*/
/* http: stream 													*/
/*==================================================================*/

/* errors */
enum {
	SLIM_HTTP_E_DNS_INVAL = SLIM_HTTP_ERROR_START,
	SLIM_HTTP_E_DNS_NOSERVER,
	SLIM_HTTP_E_DNS_TIMEDOUT,
	SLIM_HTTP_E_DNS_NOTFOUND,
	SLIM_HTTP_E_TCP_OPEN,
	SLIM_HTTP_E_TCP_CONNECT,
	SLIM_HTTP_E_TCP_READ,
	SLIM_HTTP_E_TCP_WRITE,
	SLIM_HTTP_E_SSL_CONNECT,
	SLIM_HTTP_E_SSL_HANDSHAKE,
	SLIM_HTTP_E_SSL_READ,
	SLIM_HTTP_E_SSL_WRITE,
	SLIM_HTTP_E_REQTIMEDOUT,
	SLIM_HTTP_E_RSPTIMEDOUT,
	SLIM_HTTP_E_CACHE_NONE,
	SLIM_HTTP_E_CACHE_EXPIRE,
	SLIM_HTTP_E_AUTH_UNKNOWN,
	SLIM_HTTP_E_AUTH_NOHEADER,
	SLIM_HTTP_E_AUTH_FORMAT,
	SLIM_HTTP_E_AUTH_IGNORED,		/* means authentication is canceled by THTTPChannelClass::fAuthCallback */
	SLIM_HTTP_E_REDIRECT_FORMAT,
	SLIM_HTTP_E_REDIRECT_CANCELED,
	SLIM_HTTP_E_REDIRECT_IGNORED,	/* means redirection is canceled by THTTPChannelClass::fRedirectCallback */
	SLIM_HTTP_E_REQ_HEADER_SIZEOVER,	/* method GET */
	SLIM_HTTP_E_REQ_BODY_SIZEOVER, /* method POST */
	SLIM_HTTP_E_RSP_HEADER_SIZEOVER,
	SLIM_HTTP_E_REQ_TOOMANYCONTINUE ,
	SLIM_HTTP_E_TLS_INTOLERANT,
	SLIM_HTTP_E_REQ_MSGHDR_SIZEOVER,
	SLIM_HTTP_E_CONTENT_ENCODING,
	SLIM_HTTP_ERROR_END
};

/* header type */
enum {
	SLIM_HTTP_HEADER_TYPE_GENERAL = 0,
	SLIM_HTTP_HEADER_TYPE_REQUEST,
	SLIM_HTTP_HEADER_TYPE_RESPONSE,
	SLIM_HTTP_HEADER_TYPE_ENTITY,
	SLIM_HTTP_HEADER_TYPE_OTHER,
	SLIM_HTTP_HEADER_TYPES
};

#define SLIM_HTTPHDR_CACHE_CONTROL				SLIM_TKID_HPHDR_Cache_Control_
#define SLIM_HTTPHDR_CONNECTION					SLIM_TKID_HPHDR_Connection_
#define SLIM_HTTPHDR_DATE						SLIM_TKID_HPHDR_Date_
#define SLIM_HTTPHDR_PRAGMA						SLIM_TKID_HPHDR_Pragma_
#define SLIM_HTTPHDR_TRAILER					SLIM_TKID_HPHDR_Trailer_
#define SLIM_HTTPHDR_TRANSFER_ENCODING			SLIM_TKID_HPHDR_Transfer_Encoding_
#define SLIM_HTTPHDR_UPGRADE					SLIM_TKID_HPHDR_Upgrade_
#define SLIM_HTTPHDR_VIA						SLIM_TKID_HPHDR_Via_
#define SLIM_HTTPHDR_WARNING					SLIM_TKID_HPHDR_Warning_
#define SLIM_HTTPHDR_KEEP_ALIVE					SLIM_TKID_HPHDR_Keep_Alive_
#define SLIM_HTTPHDR_PROXY_CONNECTION			SLIM_TKID_HPHDR_Proxy_Connection_
#define SLIM_HTTPHDR_ACCEPT						SLIM_TKID_HPHDR_Accept_
#define SLIM_HTTPHDR_ACCEPT_CHARSET				SLIM_TKID_HPHDR_Accept_Charset_
#define SLIM_HTTPHDR_ACCEPT_ENCODING			SLIM_TKID_HPHDR_Accept_Encoding_
#define SLIM_HTTPHDR_ACCEPT_LANGUAGE			SLIM_TKID_HPHDR_Accept_Language_
#define SLIM_HTTPHDR_AUTHORIZATION				SLIM_TKID_HPHDR_Authorization_
#define SLIM_HTTPHDR_EXPECT						SLIM_TKID_HPHDR_Expect_
#define SLIM_HTTPHDR_FROM						SLIM_TKID_HPHDR_From_
#define SLIM_HTTPHDR_HOST						SLIM_TKID_HPHDR_Host_
#define SLIM_HTTPHDR_IF_MATCH					SLIM_TKID_HPHDR_If_Match_
#define SLIM_HTTPHDR_IF_MODIFIED_SINCE			SLIM_TKID_HPHDR_If_Modified_Since_
#define SLIM_HTTPHDR_IF_NONE_MATCH				SLIM_TKID_HPHDR_If_None_Match_
#define SLIM_HTTPHDR_IF_RANGE					SLIM_TKID_HPHDR_If_Range_
#define SLIM_HTTPHDR_IF_UNMODIFIED_SINCE		SLIM_TKID_HPHDR_If_Unmodified_Since_
#define SLIM_HTTPHDR_MAX_FORWARDS				SLIM_TKID_HPHDR_Max_Forwards_
#define SLIM_HTTPHDR_PROXY_AUTHORIZATION		SLIM_TKID_HPHDR_Proxy_Authorization_
#define SLIM_HTTPHDR_RANGE						SLIM_TKID_HPHDR_Range_
#define SLIM_HTTPHDR_REFERER					SLIM_TKID_HPHDR_Referer_
#define SLIM_HTTPHDR_TE							SLIM_TKID_HPHDR_TE_
#define SLIM_HTTPHDR_USER_AGENT					SLIM_TKID_HPHDR_User_Agent_
#define SLIM_HTTPHDR_COOKIE						SLIM_TKID_HPHDR_Cookie_
#define SLIM_HTTPHDR_ACCEPT_RANGES				SLIM_TKID_HPHDR_Accept_Ranges_
#define SLIM_HTTPHDR_AGE						SLIM_TKID_HPHDR_Age_
#define SLIM_HTTPHDR_ETAG						SLIM_TKID_HPHDR_ETag_
#define SLIM_HTTPHDR_LOCATION					SLIM_TKID_HPHDR_Location_
#define SLIM_HTTPHDR_PROXY_AUTHENTICATE			SLIM_TKID_HPHDR_Proxy_Authenticate_
#define SLIM_HTTPHDR_RETRY_AFTER				SLIM_TKID_HPHDR_Retry_After_
#define SLIM_HTTPHDR_SERVER						SLIM_TKID_HPHDR_Server_
#define SLIM_HTTPHDR_VARY						SLIM_TKID_HPHDR_Vary_
#define SLIM_HTTPHDR_WWW_AUTHENTICATE			SLIM_TKID_HPHDR_WWW_Authenticate_
#define SLIM_HTTPHDR_SET_COOKIE					SLIM_TKID_HPHDR_Set_Cookie_
#define SLIM_HTTPHDR_AUTHENTICATION_INFO		SLIM_TKID_HPHDR_Authentication_Info_
#define SLIM_HTTPHDR_PROXY_AUTHENTICATION_INFO	SLIM_TKID_HPHDR_Proxy_Authentication_Info_
#define SLIM_HTTPHDR_ALLOW						SLIM_TKID_HPHDR_Allow_
#define SLIM_HTTPHDR_CONTENT_ENCODING			SLIM_TKID_HPHDR_Content_Encoding_
#define SLIM_HTTPHDR_CONTENT_DISPOSITION		SLIM_TKID_HPHDR_Content_Disposition_
#define SLIM_HTTPHDR_CONTENT_LANGUAGE			SLIM_TKID_HPHDR_Content_Language_
#define SLIM_HTTPHDR_CONTENT_LENGTH				SLIM_TKID_HPHDR_Content_Length_
#define SLIM_HTTPHDR_CONTENT_LOCATION			SLIM_TKID_HPHDR_Content_Location_
#define SLIM_HTTPHDR_CONTENT_MD5				SLIM_TKID_HPHDR_Content_MD5_
#define SLIM_HTTPHDR_CONTENT_RANGE				SLIM_TKID_HPHDR_Content_Range_
#define SLIM_HTTPHDR_CONTENT_TYPE				SLIM_TKID_HPHDR_Content_Type_
#define SLIM_HTTPHDR_EXPIRES					SLIM_TKID_HPHDR_Expires_
#define SLIM_HTTPHDR_LAST_MODIFIED				SLIM_TKID_HPHDR_Last_Modified_

/* constant for http stream state */
enum {
	SLIM_HTTP_STREAM_ST_NEW = 0,
	SLIM_HTTP_STREAM_ST_DORMANT,
	SLIM_HTTP_STREAM_ST_REQ_CREATED,
	SLIM_HTTP_STREAM_ST_REQ_RESOLVE,
	SLIM_HTTP_STREAM_ST_REQ_RESOLVING,
	SLIM_HTTP_STREAM_ST_REQ_OPEN,
	SLIM_HTTP_STREAM_ST_REQ_CONNECT,
	SLIM_HTTP_STREAM_ST_REQ_CONNECTING,
	SLIM_HTTP_STREAM_ST_REQ_PROXY_CONNECT,
	SLIM_HTTP_STREAM_ST_REQ_PROXY_CONNECTING,
	SLIM_HTTP_STREAM_ST_REQ_SSL_HANDSHAKING,
	SLIM_HTTP_STREAM_ST_REQ_SSL_HANDSHAKED,
	SLIM_HTTP_STREAM_ST_REQ_SENDING,
	SLIM_HTTP_STREAM_ST_REQ_SENT,
	SLIM_HTTP_STREAM_ST_RSP_HEADER_WAITING,
	SLIM_HTTP_STREAM_ST_RSP_CONTINUE,
	SLIM_HTTP_STREAM_ST_RSP_HEADER_RECEIVING,
	SLIM_HTTP_STREAM_ST_RSP_HEADER_RECEIVED,
	SLIM_HTTP_STREAM_ST_RSP_ENTITY_RECEIVING,
	SLIM_HTTP_STREAM_ST_RSP_ENTITY_RECEIVED,
	SLIM_HTTP_STREAM_ST_OBSOLETE,
	SLIM_HTTP_STREAM_ST_DELETE,
	SLIM_HTTP_STREAM_STS
};

/* constant for http stream protocol scheme */
enum {
	SLIM_HTTP_SCHEME_HTTP = 0,
	SLIM_HTTP_SCHEME_HTTPS,
	SLIM_HTTP_SCHEMES
};

/* constant for http method */
enum {
	SLIM_HTTP_METHOD_OPTIONS = 0,
	SLIM_HTTP_METHOD_GET,
	SLIM_HTTP_METHOD_HEAD,
	SLIM_HTTP_METHOD_POST,
	SLIM_HTTP_METHOD_PUT,
	SLIM_HTTP_METHOD_DELETE,
	SLIM_HTTP_METHOD_TRACE,
	SLIM_HTTP_METHOD_CONNECT,
	SLIM_HTTP_METHODS
};

/* constant for http version */
enum {
	SLIM_HTTP_VERSION_0_9 = 0,
	SLIM_HTTP_VERSION_1_0,
	SLIM_HTTP_VERSION_1_1,
	SLIM_HTTP_VERSIONS
};

/* constants for HTTP cache controlling */
enum {
	SLIM_HTTP_CACHECONTROL_NORMAL,
	SLIM_HTTP_CACHECONTROL_REVALIDATE,
	SLIM_HTTP_CACHECONTROL_NOCACHE,
	SLIM_HTTP_CACHECONTROLS
};

/* constant for http status code */
enum {
	SLIM_HTTP_CODE_Continue							= 100,
	SLIM_HTTP_CODE_Switching_Protocols				= 101,
	SLIM_HTTP_CODE_OK								= 200,
	SLIM_HTTP_CODE_Created							= 201,
	SLIM_HTTP_CODE_Accepted							= 202,
	SLIM_HTTP_CODE_Non_Authoritative_Information	= 203,
	SLIM_HTTP_CODE_No_Content						= 204,
	SLIM_HTTP_CODE_Reset_Content					= 205,
	SLIM_HTTP_CODE_Partial_Content					= 206,
	SLIM_HTTP_CODE_Multiple_Choices					= 300,
	SLIM_HTTP_CODE_Moved_Permanently				= 301,
	SLIM_HTTP_CODE_Found							= 302,
	SLIM_HTTP_CODE_See_Other						= 303,
	SLIM_HTTP_CODE_Not_Modified						= 304,
	SLIM_HTTP_CODE_Use_Proxy						= 305,
	SLIM_HTTP_CODE_Temporary_Redirect				= 307,
	SLIM_HTTP_CODE_Bad_Request						= 400,
	SLIM_HTTP_CODE_Unauthorized						= 401,
	SLIM_HTTP_CODE_Payment_Required					= 402,
	SLIM_HTTP_CODE_Forbidden						= 403,
	SLIM_HTTP_CODE_Not_Found						= 404,
	SLIM_HTTP_CODE_Method_Not_Allowed				= 405,
	SLIM_HTTP_CODE_Not_Acceptable					= 406,
	SLIM_HTTP_CODE_Proxy_Authentication_Required	= 407,
	SLIM_HTTP_CODE_Request_Time_out					= 408,
	SLIM_HTTP_CODE_Conflict							= 409,
	SLIM_HTTP_CODE_Gone								= 410,
	SLIM_HTTP_CODE_Length_Required					= 411,
	SLIM_HTTP_CODE_Precondition_Failed				= 412,
	SLIM_HTTP_CODE_Request_Entity_Too_Large			= 413,
	SLIM_HTTP_CODE_Request_URI_Too_Large			= 414,
	SLIM_HTTP_CODE_Unsupported_Media_Type			= 415,
	SLIM_HTTP_CODE_Requested_range_not_satisfiable	= 416,
	SLIM_HTTP_CODE_Expectation_Failed				= 417,
	SLIM_HTTP_CODE_Internal_Server_Error			= 500,
	SLIM_HTTP_CODE_Not_Implemented					= 501,
	SLIM_HTTP_CODE_Bad_Gateway						= 502,
	SLIM_HTTP_CODE_Service_Unavailable				= 503,
	SLIM_HTTP_CODE_Gateway_Time_out					= 504,
	SLIM_HTTP_CODE_HTTP_Version_not_supported		= 505
};

/* constant for cookie mode */
enum {
	SLIM_HTTP_COOKIE_NOTIFY_BEFORE_SET = 0,
	SLIM_HTTP_COOKIE_ALWAYS_SET,
	SLIM_HTTP_COOKIE_NEVER_SET
};

/* timer events */
enum {
	SLIM_HTTP_STREAM_TMEV_NONE = -1,
	SLIM_HTTP_STREAM_TMEV_CONNECT,
	SLIM_HTTP_STREAM_TMEV_READ,
	SLIM_HTTP_STREAM_TMEV_WRITE,
	SLIM_HTTP_STREAM_TMEVS
};

/*----------------------------------------------------------*/
/* HTTP Header Restriction	 								*/
/*----------------------------------------------------------*/
#define SLIM_HPHDR_RESTRICT_BITS_PER_BYTE	8
#define SLIM_HPHDR_RESTRICT_BYTES_PER_WORD	sizeof(slim_word)
#define SLIM_HPHDR_RESTRICT_BITS_PER_WORD	(SLIM_HPHDR_RESTRICT_BYTES_PER_WORD * SLIM_HPHDR_RESTRICT_BITS_PER_BYTE)
#define SLIM_HPHDR_RESTRICT_WORDS			SLIM_HOWMANY(SLIM_TOKEN_HPHDR_ENUMS, SLIM_HPHDR_RESTRICT_BITS_PER_WORD)
#define SLIM_HPHDR_RESTRICT_BYTES			(SLIM_HPHDR_RESTRICT_WORDS * SLIM_HPHDR_RESTRICT_BYTES_PER_WORD)

struct THTTPHdrRestriction_ {
	slim_word fWords[SLIM_HPHDR_RESTRICT_WORDS];
};
typedef struct THTTPHdrRestriction_ THTTPHdrRestriction;


/*----------------------------------------------------------*/
/* DNS cache entry information 								*/
/*----------------------------------------------------------*/
#define SLIM_DNSCACHE_ENTRY_FLAG_NONE				0x00000000
#define SLIM_DNSCACHE_ENTRY_FLAG_IGNORE_EXPIRATION	0x00000001

struct TDNSCacheEntry_ {
	TFixedString name;		/* host name	*/
	slim_ip_addr addr;		/* IP address	*/
	slim_int flag;			/* for expiration */
	slim_time expire_time;	/* for expiration */
};
typedef struct TDNSCacheEntry_ TDNSCacheEntry;
typedef TSpecList TDNSCache;

/*----------------------------------------------------------*/
/* http stream class										*/
/*----------------------------------------------------------*/

/* flag operation */
#define SLIM_HTTP_STREAM_FLAG_USE_PROXY		 		0x00000001
#define SLIM_HTTP_STREAM_FLAG_PROXY_RESOLVED 		0x00000002
#define SLIM_HTTP_STREAM_FLAG_HTTP11_OVER_PROXY		0x00000004
#define SLIM_HTTP_STREAM_FLAG_SEND_REFERER			0x00000008
#define SLIM_HTTP_STREAM_FLAG_SEND_PROXYKEEPALIVE	0x00000010
#define SLIM_HTTP_STREAM_FLAG_SEND_COOKIE			0x00000020

typedef struct THTTPStreamClass_ THTTPStreamClass;
typedef struct iTHTTPStream_ iTHTTPStream;
typedef iTHTTPStream **THTTPStream;

typedef slim_int (*THTTPStream_ReqStateProc)(iTHTTPStream *iself, slim_int in_state);
typedef slim_int (*THTTPStream_RspStateProc)(iTHTTPStream *iself, slim_int in_state, slim_char *out_buf, slim_int in_len, slim_int *out_len);

typedef slim_int (*THTTPStreamCustomizeHeaderProc)(THTTPStream self, slim_opaque in_aux);

typedef void (*HTTPStreamWakeUpCallbackProc)(slim_opaque in_aux);
typedef slim_bool (*THTTPStreamNotifyStateProc)(THTTPStream self, TURLString in_url, slim_int in_state, slim_opaque in_aux);

#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
typedef void (*HTTPStream_DebugPrintProc)(char *in_format, ...);
typedef void (*HTTPStream_DebugNotifyProc)(iTHTTPStream *stream);
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */

struct THTTPStreamClass_ {
	/* class variables */
	TDNS fDNS;					/* DNS								*/
	THTTPStreamPool fStreamPool;/* stream pool						*/
	THTTPAuthCache fAuthCache;	/* authentication info cache		*/
	slim_int fFlag;				/* flag (send referer, use proxy)	*/
	slim_int fHTTPPort;			/* port number for HTTP				*/
	slim_int fHTTPSPort;		/* port number for HTTPS			*/
	slim_int fMaxRequestHeader;	/* Ugh!: max request "line" size	*/
	slim_int fMaxReqMsgHeader;	/* max request message header size	*/
	slim_int fMaxRequestBody;	/* max request body size (POST)		*/
	TFixedString fProxyHost;	/* proxy host name					*/
	slim_ip_addr fProxyAddr;	/* proxy ip address					*/
	slim_int fProxyHTTPPort;	/* proxy host port number (HTTP)	*/
	slim_int fProxyHTTPSPort;	/* proxy host port number (HTTPS)	*/
	TString fNoProxyHosts;		/* no proxy host name lists			*/
	TFixedString fUserAgent;	/* user agent name					*/
	TString fDefaultHeaders;	/* default headers for all request	*/
	TString fDefaultConnectHeaders;	/* default headers for CONNECT request	*/
	THTTPCookies fCookie;		/* cookie							*/
	TDNSCache fDNSCache;		/* cache for dns entry				*/
	slim_int fDNSMaxCacheEntries;/* max entries of dns cache		*/
	slim_int fMaxResponseHeader;/* max response header size			*/
	slim_int fMax100Continue;	/* max 100 continue 				*/
	THTTPStream_ReqStateProc fReqStateProc;
	THTTPStream_RspStateProc fRspStateProc;
	slim_int fTimeLimit[SLIM_HTTP_STREAM_TMEVS];
	THTTPStreamCustomizeHeaderProc fCustomizeHeaderProc;
	slim_opaque fCustomizeHeaderAux;
	slim_int (*fTunnelingCallback)(iTHTTPStream *iself, slim_char *in_buf, slim_int in_len, slim_opaque in_aux);
	slim_opaque fTunnelingAux;
	THTTPHdrRestriction fReqHdrRestriction;	/* restrictions for request header	*/
	THTTPHdrRestriction fRspHdrRestriction;	/* restrictions for response header	*/
	/* multi application */
	TObjectList fList;
	HTTPStreamWakeUpCallbackProc fCallbackProc;
	slim_opaque fCallbackAux;
	TSSLServerCertConfirmProc fSSLConfirmProc;
	slim_opaque fSSLConfirmAux;
	TSSLClientCertSelectProc fSSLSelectProc;
	slim_opaque fSSLSelectAux;
	TSSLDeleteCallback fSSLDeleteProc;
	slim_opaque fSSLDeleteAux;
	TSSLPrivateKeyEncryptProc fSSLEncryptProc;
	slim_opaque fSSLEncryptAux;
	THTTPStreamNotifyStateProc fNotifyStateProc;
	slim_opaque fNotifyStateAux;
#ifdef SLIM_CONFIG_HTTP_STREAM_DEBUG
	HTTPStream_DebugPrintProc fPrintfProc;	/* printf procedure				*/
	HTTPStream_DebugNotifyProc fNotifyProc;		/* callback procedure 			*/
#endif /* SLIM_CONFIG_HTTP_STREAM_DEBUG */
};

/* API */
#ifndef SLIM_CONFIG_USE_HTTP
/* dummy */
#define HTTPStream_ClearAuthCache(in_class)			((void)0)
#define HTTPStream_ClearDNSCache(in_class)	{}
#define HTTPStream_ClearSSLSessionCache(in_class)	((void)0)
#define HTTPStream_CloseAllKeepAlive(in_class)	{}
#define HTTPStream_Finalize(in_class)	{}
#define HTTPStream_Initialize(in_class)	(slim_true)
#define HTTPStream_MakeAuthInfo(in_class, in_target, in_url, \
								  in_proxy_host, in_proxy_port, in_realm_ss, out_info)	(slim_false)
#define HTTPStream_MakeProxy(in_class, out_proxy_host, out_proxy_http_port, out_proxy_https_port, out_no_proxy_hosts)	{}
#define HTTPStream_New(in_class)	(slim_nil)
#define HTTPStream_SetDefaultHeaders(in_class, in_default_headers)	(slim_true)
#define HTTPStream_SetDefaultConnectHeaders(in_class, in_default_headers)	(slim_true)
#define HTTPStream_SetProxy(in_class, in_proxy_host, in_proxy_http_port, in_proxy_https_port, in_no_proxy_hosts)	(slim_true)
#define HTTPStream_SetSSLClientCertSelectProc(in_class, in_proc, in_aux)	(slim_true)
#define HTTPStream_SetSSLServerCertConfirmProc(in_class, in_proc, in_aux)	(slim_true)
#define HTTPStream_RegisterSSLSessionDB(in_class, in_db, out_old) (SLIM_E_INVAL)
#define HTTPStream_SetUserAgent(in_class, in_user_agent)	(slim_true)
#define HTTPStream_SetWakeUpCallback(in_class, in_proc, in_aux)	(slim_true)
#define HTTPStream_SetNotifyStateProc(in_class, proc, aux)	((void)0)
#define HTTPStream_WakeUpByTCP(in_class, in_desc)	{}
#define HTTPStream_WakeUpByDNS(in_class, in_ticket_id)	{}
#define HTTPStream_AddCookie(in_class, in_url, in_str, in_len) (SLIM_E_OK)
#define THTTPStream_AddHeaderCS(self, in_type, in_str) (slim_true)

#else /* SLIM_CONFIG_USE_HTTP */

#define HTTPStream_IsHTTP11OverProxy(in_class) 		SLIM_FLAG_CK((in_class),SLIM_HTTP_STREAM_FLAG_HTTP11_OVER_PROXY)
#define HTTPStream_IsUseProxy(in_class) 			SLIM_FLAG_CK((in_class),SLIM_HTTP_STREAM_FLAG_USE_PROXY)
#define HTTPStream_ClearSSLSessionCache(in_class)	SSL_ClearSessionCache((in_class)->fStreamPool.fSocketDesc.fSSLClass)
#define HTTPStream_RegisterTCPInterface(in_class, tcp_class)	THTTPStreamPool_RegisterTCPInterface(&(in_class)->fStreamPool, (tcp_class))
#define HTTPStream_RegisterSSLInterface(in_class, ssl_class)	THTTPStreamPool_RegisterSSLInterface(&(in_class)->fStreamPool, (ssl_class))
#define HTTPStream_RegisterSSLClass(in_class, ssl_class)	{(in_class)->fStreamPool.fSocketDesc.fSSLClass = (ssl_class);}
#define HTTPStream_SSLClass(in_class)	((in_class)->fStreamPool.fSocketDesc.fSSLClass)
#define HTTPStream_SetHTTP11OverProxy(in_class,val)	SLIM_FLAG_OP((in_class),SLIM_HTTP_STREAM_FLAG_HTTP11_OVER_PROXY,(val))
#define HTTPStream_SetHTTPPort(in_class, port)	{(in_class)->fHTTPPort = (port);}
#define HTTPStream_SetHTTPSPort(in_class, port)	{(in_class)->fHTTPSPort = (port);}
#define HTTPStream_SetMaxRequestBody(in_class, size)	{(in_class)->fMaxRequestBody = (size);}
#define HTTPStream_SetMaxRequestHeader(in_class, size)	{(in_class)->fMaxRequestHeader = (size);}
#define HTTPStream_SetUseProxy(in_class,val)		SLIM_FLAG_OP((in_class),SLIM_HTTP_STREAM_FLAG_USE_PROXY,(val))

#define HTTPStream_SetUserPass(in_class,in_type,in_target,in_challenge_ss,in_realm_ss,\
							   in_user,in_pass,in_url,in_host,in_port) \
	 HTTPStream_SetUserPassX((in_class),(in_type),(in_target),(in_challenge_ss),(in_realm_ss),\
							(in_user),(in_pass),(in_url),(in_host),(in_port),slim_false,slim_false)

#define HTTPStream_SetMaxTCPStreams(in_class, max) ((in_class)->fStreamPool.fMaxStreams = (max))
#define HTTPStream_SetMaxPipelineRequests(in_class, max) ((in_class)->fStreamPool.fMaxRefCount = (max))
#define HTTPStream_SetMaxKeepAliveTimeout(in_class, max) ((in_class)->fStreamPool.fMaxKeepAliveTimeout = (max))
#define HTTPStream_SetMax100Continue(in_class, max) ((in_class)->fMax100Continue = (max))
#define HTTPStream_SetDNSMaxCacheEntries(in_class, max) ((in_class)->fDNSMaxCacheEntries = (max))

#define HTTPStream_SetTimeLimit(in_class, i, ms) ((in_class)->fTimeLimit[(i)] = (ms))	/* private */
#define HTTPStream_SetConnectTimeOut(in_class, in_msec) HTTPStream_SetTimeLimit((in_class), SLIM_HTTP_STREAM_TMEV_CONNECT, (in_msec))
#define HTTPStream_SetReqTimeOut(in_class, in_msec) HTTPStream_SetTimeLimit((in_class), SLIM_HTTP_STREAM_TMEV_WRITE,(in_msec))
#define HTTPStream_SetRspTimeOut(in_class, in_msec) HTTPStream_SetTimeLimit((in_class), SLIM_HTTP_STREAM_TMEV_READ,(in_msec))

#endif /* SLIM_CONFIG_USE_HTTP */

/*----------------------------------------------------------*/
/* http stream												*/
/*----------------------------------------------------------*/
enum {
	SLIM_INFLATE_TYPE_IDENTITY = 0,
	SLIM_INFLATE_TYPE_DEFLATE,
	SLIM_INFLATE_TYPE_GZIP,
	SLIM_INFLATE_TYPES
};

struct THTTPStreamInflate_ {
	slim_int fType;
	slim_bool (*fInitializeProc)(struct THTTPStreamInflate_ *iself);
	slim_int (*fSkipHeaderProc)(struct THTTPStreamInflate_ *iself, iTHTTPStream *in_stream);
	slim_int (*fReadProc)(struct THTTPStreamInflate_ *iself, iTHTTPStream *in_stream, slim_char *out_buf, slim_int in_len, slim_int *out_len);
	void (*fFinalizeProc)(struct THTTPStreamInflate_ *iself);
};
typedef struct THTTPStreamInflate_ THTTPStreamInflate;

/*----------------------------------------------------------*/
/* http stream												*/
/*----------------------------------------------------------*/
struct iTHTTPStream_ {
	/* general attributes */
	THTTPStreamClass *fClass;		/* pointer to class							*/
	slim_short fState;				/* state of stream							*/
	slim_short fRetryCount;			/* retry count								*/
	slim_int fFlag;					/* flag of stream
									   (pipeline, post as string, finish create header,
									   connect via proxy, finish receive header, last chunk,
									   trailer, chunked, keep alive, connection close) */
	/* attributes for create request */
	TURLString fURL;				/* absolute URL string						*/
	slim_int fMethod;				/* method 									*/
	slim_short fVersion;			/* http version								*/
	slim_short fScheme;				/* protocol scheme (http/https)				*/
	TFixedString fURLHost;			/* host string in URL						*/
	slim_int fPostDataLen;			/* data length of post data					*/
	slim_handle fPostData;			/* post data 								*/
	slim_byte *fProgressivePostData;/* progressive post data 					*/
	slim_int fProgressivePostDataLen;/* progressive post data len				*/
	slim_int fProgressivePostDataWritten;/* progressive post data written len	*/
	TPostData fPostOnDemand;
	TPostDataCursor* fPostDataCursor;
	TString fRequest;				/* request string 							*/
	slim_int fRequestLen;			/* length of request message				*/
	/* SSL */
	slim_int fSSLFlag;				/* ssl management flag						*/
	TString fSSLConnectRequest;		/* connect request string for SSL			*/
	/* attributes for send request */
	TFixedString fConnectHost;		/* host name (proxy or server) to connect	*/
	slim_int fFileOfs;				/* offset of file string in URL				*/
	slim_int fFileLen;				/* length of file string in URL				*/
	slim_int fURLPort;				/* url host port to connect					*/
	slim_int fConnectPort;			/* host port (proxy or server) to connect	*/
	slim_int fDnsTicket;			/* dns ticket for resolve ip address		*/
	slim_ip_addr fConnectAddr;		/* host ip address							*/
	slim_int fStreamDesc;			/* stream descriptor						*/
	slim_int fBytesSent;			/* bytes sent	 							*/
	slim_int fBytesRecv;			/* bytes received (not decompressed length)	*/
	/* attributes for receive response */
	slim_int fChunkRemain;			/* remains of chunk bytes in fBuffer		*/
	/* public attributes to provide response header information (availavle fFinishReceiveHeader = true) */
	slim_vhandle fHeader;			/* status/header line of response header	*/
	slim_int fHeaderBufLen;			/* stored characters of response header		*/
	slim_short fServerVersion;		/* server version 							-1 = unavailable */
	slim_short fStatusCode;			/* status code of response					-1 = unavailable */
	slim_int fStatusLen;			/* status string length in received stream	-1 = unavailable */
	slim_int fReasonOfs;			/* reason string offset in received stream	-1 = unavailable */
	slim_int fReasonLen;			/* reason string length in received stream	-1 = unavailable */
	slim_int fHeaderOfs;			/* header string offset in received stream	-1 = unavailable */
	slim_int fHeaderLen;			/* header string length in received stream	-1 = unavailable */
	slim_int fEntityOfs;			/* entity string offset in received stream	-1 = unavailable */
	slim_int fEntityLen;			/* entity string length in received stream	-1 = unavailable */
	/* public header value (availavle fFinishReceiveHeader = true) */
	slim_int fResponseLen;			/* Content-Length. "-1" means no Content-Length header or Trunsfar-Encoding: chunked. */
	slim_int fContentLength;		/* Content-Length (-1 = not specified in header)	*/

	slim_pix fPageAuthInfoPix;
	slim_pix fProxyAuthInfoPix;
	slim_int f100Continue;			/* 100 continue count */
	slim_int fTimeLimit[SLIM_HTTP_STREAM_TMEVS];
	THTTPStreamInflate *fInflate;
	/* multi application */
	slim_pix fPix;
	slim_int fMaxReqMsgHeader;		/* max request message header size (Telnet EOLs are included) */

	THTTPStreamNotifyStateProc fNotifyStateProc;
	slim_opaque fNotifyStateAux;
};

/* API */
#define THTTPStream_GetHeaderSS(self, in_type, out_ofs, out_len)	THTTPStream_GetHeaderSSWithOffset(self, in_type, 0, out_ofs, out_len)	

SLIM_END_C_LINKAGE
#endif
