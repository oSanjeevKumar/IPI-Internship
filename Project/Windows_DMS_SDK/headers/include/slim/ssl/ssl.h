/*
	ssl.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/ssl/ssl.h 229   06/06/23 14:34 Siu $ */

#ifndef SLIM_SSL_H
#define SLIM_SSL_H

SLIM_BEGIN_C_LINKAGE

/* declare */
typedef struct iTSSL_ iTSSL;
typedef struct iTSSL_ **TSSL;
typedef struct TSSLClass_ TSSLClass;


/*==============
	Constants
 ==============*/

/* DO NOT CHANGE CONSTANTS */
#define SLIM_SSL3_REC_HEADER_SIZE				5
#define SLIM_SSL3_MSG_HEADER_SIZE				4
#define SLIM_SSL3_REC_HEAD_LEN_OFS				3
#define SLIM_SSL3_MAX_PLAIN_TXT_LEN				16384
#define SLIM_SSL3_MAX_COMPR_TXT_LEN				(SLIM_SSL3_MAX_PLAIN_TXT_LEN)
#define SLIM_SSL3_MAX_CIPHER_TXT_LEN			(SLIM_SSL3_MAX_COMPR_TXT_LEN + SLIM_CRYPT_SHS_DIGESTSIZE + 256)	/* 256 : padding */
#define SLIM_SSL3_MAX_MSG_LEN					(SLIM_SSL3_MAX_PLAIN_TXT_LEN - SLIM_SSL3_MSG_HEADER_SIZE)

#define SLIM_SSL2_MAC_SIZE						SLIM_CRYPT_MD5_DIGESTSIZE
#define SLIM_SSL2_MSG_OFS						(SLIM_SSL2_MAC_SIZE + 3)	/* 3 : 3-bytes header */
#define SLIM_SSL2_AT_MD5_WITH_RSA_ENCRYPTION	0x01
#define SLIM_SSL2_CT_X509_CERTIFICATE			0x01
#define SLIM_SSL2_2BH_MAX_CIPHER_TXT_LEN		32767
#define SLIM_SSL2_3BH_MAX_CIPHER_TXT_LEN		16383
#define SLIM_SSL2_2BH_MAX_STRM_PLAIN_TXT_LEN	(SLIM_SSL2_2BH_MAX_CIPHER_TXT_LEN - SLIM_SSL2_MAC_SIZE)

#define SLIM_SSL_MAX_KEY_MATERIAL	32
#define SLIM_SSL_MAX_HASH_LEN		20
#define SLIM_SSL_MAX_IV_LEN			16
#define SLIM_SSL3_MS_SIZE			48



/*==============================================================
	SSL Flag

	At least, one of CONN_V2, CONN_V3 CONN_TLS should be set.
	Mixed flags (for example, CONN_V2V3) mean auto selection.

	In "CONN_V2xxx", we send 16-bytes challenge to a server
	in order to work around the Netscape Commerce Server bug.
 ==============================================================*/

/* Version */
#define SLIM_SSL_FLAG_CONN_V2					0x00000001	/* connect by v2 protocol */
#define SLIM_SSL_FLAG_CONN_V3					0x00000002	/* connect by v3 protocol */
#define SLIM_SSL_FLAG_CONN_TLS					0x00000004	/* connect by TLS(v3.1) protocol */
#define SLIM_SSL_FLAG_CONN_V2V3					(SLIM_SSL_FLAG_CONN_V2 | SLIM_SSL_FLAG_CONN_V3)
#define SLIM_SSL_FLAG_CONN_V2TLS				(SLIM_SSL_FLAG_CONN_V2 | SLIM_SSL_FLAG_CONN_TLS)
#define SLIM_SSL_FLAG_CONN_V3TLS				(SLIM_SSL_FLAG_CONN_V3 | SLIM_SSL_FLAG_CONN_TLS)
#define SLIM_SSL_FLAG_CONN_V2V3TLS				(SLIM_SSL_FLAG_CONN_V2 | SLIM_SSL_FLAG_CONN_V3 | SLIM_SSL_FLAG_CONN_TLS)
#define SLIM_SSL_FLAG_CONN_MASK					SLIM_SSL_FLAG_CONN_V2V3TLS

/* Option */
#define SLIM_SSL_FLAG_OPT_TEMP_RSAKEY			0x00000010	/* allow to use temporary RSA key */
#define SLIM_SSL_FLAG_OPT_SERVER_AUTH			0x00000020	/* need to authenticate server */
#define SLIM_SSL_FLAG_OPT_V2_CLIENT_AUTH		0x00000040	/* allow to authenticate client with V2 */
#define SLIM_SSL_FLAG_OPT_V3_CLIENT_AUTH		0x00000080	/* allow to authenticate client with V3 */
#define SLIM_SSL_FLAG_OPT_TLS_CLIENT_AUTH		0x00000100	/* allow to authenticate client with TLS */
#define SLIM_SSL_FLAG_OPT_RENEGOTIATION			0x00000200	/* allow to re-negotiate */
#define SLIM_SSL_FLAG_OPT_REMEMBER_CERT_ERR		0x00000400	/* remember cert error */
#define SLIM_SSL_FLAG_OPT_AVOID_KNOWN_IV		0x00000800	/* for SSLv3 and TLSv1 */
#define SLIM_SSL_FLAG_OPT_MASK					( SLIM_SSL_FLAG_OPT_TEMP_RSAKEY       | \
												  SLIM_SSL_FLAG_OPT_SERVER_AUTH       | \
												  SLIM_SSL_FLAG_OPT_V2_CLIENT_AUTH    | \
												  SLIM_SSL_FLAG_OPT_V3_CLIENT_AUTH    | \
												  SLIM_SSL_FLAG_OPT_TLS_CLIENT_AUTH   | \
												  SLIM_SSL_FLAG_OPT_RENEGOTIATION     | \
												  SLIM_SSL_FLAG_OPT_REMEMBER_CERT_ERR | \
												  SLIM_SSL_FLAG_OPT_AVOID_KNOWN_IV      )

#define SLIM_SSL_FLAG_REUSE_SESSION				0x10000000	/* allow to reuse cached session */
#define SLIM_SSL_FLAG_FULL_DUPLEX				0x20000000	/* full duplex mode */

/* Operation */
#define SLIM_SSL_FLAG(flag, mask)			((flag) & (mask))
#define SLIM_SSL_SET_FLAG(flag, val, on)	((on) ? ((flag) |= (val)) : ((flag) &= ~(val)))
#define SLIM_SSL_CHECK_FLAG(flag, val)		(((flag) & (val)) != 0)



/*==================
	Configiration
 ==================*/

/*------------------------------------
	Use only exportable CipherSuite
 ------------------------------------*/

/* #define SLIM_CONFIG_SSL_EXPORT */


/*------------------
	Support SSLv2
 ------------------*/

#define SLIM_CONFIG_SSL_V2_SUPPORT

#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
#define SLIM_CONFIG_SSL_V2_COMPATIBLE
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */


/*-----------------------------------------------------------------------------------------------
	Version Roll-back Bug

	RFC2246 specifies that PreMasterSecret.ClientVersion must be latest (newest) version 
	supported by the client (i.e. ClientHello.ClientVersion) 
	because of detecting version roll-back attacks. 
	But some SSL server require PreMasterSecret.ClientVersion == ServerHello.ServerVersion. 

	If defined the following symbol, 
	setting PreMasterSecret.ClientVerison ServerHello.ServerVersin in order to avoid this bug.
 -----------------------------------------------------------------------------------------------*/

/* #define SLIM_CONFIG_SSL_AVOID_VERSION_ROLLBACK_BUG */



/*--------------------------------
	Default TCP Read/Write Peer
 --------------------------------*/

#define SLIM_SSL_DEFAULT_TCP_READ_PEER		slimTCPReadPeer
#define SLIM_SSL_DEFAULT_TCP_WRITE_PEER		slimTCPWritePeer


/*--------------------------------------------------------------------
	Buffer Size Configuration Constant

	We assume size of every handshake message is 
	smaller than SLIM_SSL_BUFFER_START_SIZE, 
	except for iTSSL3_ClientCertificate().

	In receiving message and sending iTSSL3_ClientCertificate(),
	we first check size of message,	
	then reallocate buffer if necessary.
	
	In sending application data, 
	application data is split into several message by buffer size.
 --------------------------------------------------------------------*/

#define SLIM_SSL_BUFFER_START_SIZE	(SLIM_SSL3_MAX_CIPHER_TXT_LEN + SLIM_SSL3_REC_HEADER_SIZE)


/*---------------------------------
	Limit Cached SSL Sessions
	Not cached if (limit) <= 0
 ---------------------------------*/

#ifndef SLIM_SSL_LIMIT_SESSIONS
#define SLIM_SSL_LIMIT_SESSIONS		8
#endif


/*---------------------------------------
	Limit Records of Certificate Sotre
 ---------------------------------------*/

#ifndef SLIM_SSL_ROMSTORE_LIMIT_RECORDS
#define SLIM_SSL_ROMSTORE_LIMIT_RECORDS		16
#endif
#ifndef SLIM_SSL_MEMSTORE_LIMIT_RECORDS
#define SLIM_SSL_MEMSTORE_LIMIT_RECORDS		32
#endif


/*-------------------------
	Default Version Flag
 -------------------------*/

#define SLIM_SSL_DEFAULT_CONN_MODE		SLIM_SSL_FLAG_CONN_V3TLS


/*------------------------
	Default Option Flag
 ------------------------*/

#define SLIM_SSL_DEFAULT_OPTION_FLAG	( SLIM_SSL_FLAG_OPT_TEMP_RSAKEY       | \
										  SLIM_SSL_FLAG_OPT_SERVER_AUTH       | \
										  SLIM_SSL_FLAG_OPT_V2_CLIENT_AUTH    | \
										  SLIM_SSL_FLAG_OPT_V3_CLIENT_AUTH    | \
										  SLIM_SSL_FLAG_OPT_TLS_CLIENT_AUTH   | \
										  SLIM_SSL_FLAG_OPT_RENEGOTIATION     | \
										  SLIM_SSL_FLAG_OPT_REMEMBER_CERT_ERR   )


/*-----------------------------------
	Default Certificate Check Flag
 -----------------------------------*/

#define SLIM_SSL_DEFAULT_CERT_CHECK_FLAG	( SLIM_SSL_CERT_CHECK_CN      | \
											  SLIM_SSL_CERT_CHECK_KU      | \
											  SLIM_SSL_CERT_CHECK_BC      | \
											  SLIM_SSL_CERT_CHECK_EKU       )


/*-------------------------------------------
	Defailt Matching Length of Server's CN
	No limit if (limit) < 0
 -------------------------------------------*/

#define SLIM_SSL_CERT_LIMIT_LEN			(-1)


/*-------------------------------------------
	Defailt Matching Length of Server's CN
	No limit if (limit) < 0
 -------------------------------------------*/

#define SLIM_SSL_CERT_CN_MATCH_LEN		(-1)


/*-------------------------------------------------------
	Defailt Limit Length of Server's Certificate Chain
	No limit if (limit) <= 0
 -------------------------------------------------------*/

#define SLIM_SSL_CERT_CHAIN_LIMIT_LEN	0


/*--------------------------------------------
	Default Time Limits of SSL Timer
	Timer is not started if negative value
 --------------------------------------------*/

#define SLIM_SSL_TIME_LIMIT_CLIENT_HELLO		(20 * 1000)
#define SLIM_SSL_TIME_LIMIT_V3_CLIENT_FINISHED	(20 * 1000)
#define SLIM_SSL_TIME_LIMIT_V2_CLIENT_FINISH	(20 * 1000)
#define SLIM_SSL_TIME_LIMIT_NO_CLIENT_CERT		(20 * 1000)
#define SLIM_SSL_TIME_LIMIT_CLIENT_CERT			(20 * 1000)



/*=================
	Content Type
 =================*/

/* DO NOT CHANGE CONSTANTS */
#define SLIM_SSL3_CT_CHANGE_CIPHER_SPEC	0x14
#define SLIM_SSL3_CT_ALERT				0x15
#define SLIM_SSL3_CT_HANDSHAKE			0x16
#define SLIM_SSL3_CT_APPLICATION_DATA	0x17



/*=======================
	Change Cipher Spec
 =======================*/

/* DO NOT CHANGE CONSTANTS */
#define SLIM_SSL3_CHANGE_CIPHER_SPEC 0x01



/*===========================
	Handshake Message Type
 ===========================*/

/* for SSLv2.0 -- DO NOT CHANGE CONSTANTS */
#define SLIM_SSL2_MT_ERROR					0x00
#define SLIM_SSL2_MT_CLIENT_HELLO			0x01
#define SLIM_SSL2_MT_CLIENT_MASTER_KEY		0x02
#define SLIM_SSL2_MT_CLIENT_FINISH			0x03
#define SLIM_SSL2_MT_SERVER_HELLO			0x04
#define SLIM_SSL2_MT_SERVER_VERIFY			0x05
#define SLIM_SSL2_MT_SERVER_FINISH			0x06
#define SLIM_SSL2_MT_REQUEST_CERTIFICATE	0x07
#define SLIM_SSL2_MT_CLIENT_CERTIFICATE		0x08

/* for SSLv3.x -- DO NOT CHANGE CONSTANTS */
#define SLIM_SSL3_MT_HELLO_REQUEST			0x00
#define SLIM_SSL3_MT_CLIENT_HELLO			0x01
#define SLIM_SSL3_MT_SERVER_HELLO			0x02
#define SLIM_SSL3_MT_CERTIFICATE			0x0b
#define SLIM_SSL3_MT_SERVER_KEY_EXCHANGE	0x0c
#define SLIM_SSL3_MT_CERTIFICATE_REQUEST	0x0d
#define SLIM_SSL3_MT_SERVER_HELLO_DONE		0x0e
#define SLIM_SSL3_MT_CERTIFICATE_VERIFY		0x0f
#define SLIM_SSL3_MT_CLIENT_KEY_EXCHANGE	0x10
#define SLIM_SSL3_MT_FINISHED				0x14



/*====================================
	CipherSuite (slim_ssl_cipher.c)
 ====================================*/

/*-----------------------------
	Authentication Algorithm
 -----------------------------*/

typedef slim_int TSSLAuthAlgo;

enum {
	SLIM_SSL_AUTH_ALGO_NULL = 0,
	SLIM_SSL_AUTH_ALGO_RSA,
	SLIM_SSL_AUTH_ALGO_DSS,
	SLIM_SSL_AUTH_ALGOS
};


/*---------------------------
	Key Exchange Algorithm
 ---------------------------*/

typedef slim_int TSSLKyExAlgo;

enum {
	SLIM_SSL_KYEX_ALGO_NULL = 0,
	SLIM_SSL_KYEX_ALGO_RSA,
	SLIM_SSL_KYEX_ALGO_RSA_EXPORT,
	SLIM_SSL_KYEX_ALGO_DH,
	SLIM_SSL_KYEX_ALGO_DH_EXPORT,
	SLIM_SSL_KYEX_ALGO_DH_DSS_EXPORT,
	SLIM_SSL_KYEX_ALGOS
};


/*--------------------------
	Bulk Cipher Algorithm
 --------------------------*/

typedef slim_int TSSLCipherAlgo;

enum {
	SLIM_SSL_CIPHER_ALGO_NULL = 0,
	SLIM_SSL_CIPHER_ALGO_RC4_40,
	SLIM_SSL_CIPHER_ALGO_RC4_128,
	SLIM_SSL_CIPHER_ALGO_RC2_40,
	SLIM_SSL_CIPHER_ALGO_RC2_128,
	SLIM_SSL_CIPHER_ALGO_DES_40,
	SLIM_SSL_CIPHER_ALGO_DES_56,
	SLIM_SSL_CIPHER_ALGO_3DES_168,
	SLIM_SSL_CIPHER_ALGO_AES_128,
	SLIM_SSL_CIPHER_ALGO_AES_256,
	SLIM_SSL_CIPHER_ALGOS
};

struct TSSLCipherAlgoInfo_ {
	slim_int	fFlag;
	slim_int	fID;
	slim_int	fKeySize;
	slim_int	fExpKeySize;
	slim_int	fEffKeyBits;
	slim_int	fIVSize;
	slim_int	fBlkSize;
};
typedef struct TSSLCipherAlgoInfo_ TSSLCipherAlgoInfo;

#define SLIM_SSL_CIPHER_ALGO_FLAG_NONE		0x00
#define SLIM_SSL_CIPHER_ALGO_FLAG_STREAM	0x01
#define SLIM_SSL_CIPHER_ALGO_FLAG_EXPORT	0x02


/*---------------------
	Digest Algorithm
 ---------------------*/

typedef slim_int TSSLDigestAlgo;

enum {
	SLIM_SSL_DIGEST_ALGO_NULL = 0,
	SLIM_SSL_DIGEST_ALGO_MD5,
	SLIM_SSL_DIGEST_ALGO_SHA,
	SLIM_SSL_DIGEST_ALGOS
};

struct TSSLDigestAlgoInfo_ {
	slim_int	fID;
	slim_int	fDigestSize;
	slim_int	fPadSize;
};
typedef struct TSSLDigestAlgoInfo_ TSSLDigestAlgoInfo;


/*----------------
	CipherSuite
 ----------------*/

enum {
	SLIM_SSL_CS_UNKNOWN = -1,

	SLIM_SSL_CS_NULL_NULL_NULL = 0,

	/* SSLv2 */
	SLIM_SSL2_CS_start,
	SLIM_SSL2_CS_RSA_RC4_40_MD5 = SLIM_SSL2_CS_start,
	SLIM_SSL2_CS_RSA_RC2_40_MD5,
#ifndef SLIM_CONFIG_SSL_EXPORT
	SLIM_SSL2_CS_RSA_RC4_128_MD5,
	SLIM_SSL2_CS_RSA_RC2_128_MD5,
	SLIM_SSL2_CS_RSA_DES_56_MD5,
	SLIM_SSL2_CS_RSA_3DES_168_MD5,
#endif /* SLIM_CONFIG_SSL_EXPORT */
	SLIM_SSL2_CS_end,

	/* SSLv3/TLSv1 */
	SLIM_SSL3_CS_start = SLIM_SSL2_CS_end,
	SLIM_SSL3_CS_RSA_NULL_MD5 = SLIM_SSL3_CS_start,
	SLIM_SSL3_CS_RSA_NULL_SHA,
	SLIM_SSL3_CS_RSA_RC4_40_MD5,
	SLIM_SSL3_CS_RSA_RC2_40_MD5,
	SLIM_SSL3_CS_RSA_DES_40_SHA,
#ifndef SLIM_CONFIG_SSL_EXPORT
	SLIM_SSL3_CS_RSA_RC4_128_MD5,
	SLIM_SSL3_CS_RSA_RC4_128_SHA,
	SLIM_SSL3_CS_RSA_DES_56_SHA,
	SLIM_SSL3_CS_RSA_3DES_168_SHA,
	SLIM_TLS1_CS_RSA_AES_128_SHA,
	SLIM_TLS1_CS_RSA_AES_256_SHA,
#endif /* SLIM_CONFIG_SSL_EXPORT */
	SLIM_SSL3_CS_end,

	SLIM_SSL_CIPHER_SUITES = SLIM_SSL3_CS_end
};

#define SLIM_SSL2_CIPHER_SUITES		(SLIM_SSL2_CS_end - SLIM_SSL2_CS_start)
#define SLIM_SSL3_CIPHER_SUITES		(SLIM_SSL3_CS_end - SLIM_SSL3_CS_start)

typedef slim_int TSSLCipherSuite;

struct TSSLCipherSuiteInfo_ {
#ifdef SLIM_CONFIG_SSL_DEBUG
	slim_char	*fName;
#endif /* SLIM_CONFIG_SSL_DEBUG */
	TSSLAuthAlgo	fAuthAlgo;
	TSSLKyExAlgo	fKyExAlgo;
	TSSLCipherAlgo	fCipherAlgo;
	TSSLDigestAlgo	fDigestAlgo;
	slim_byte		fID[4];	/* fID[3] is not used */
};
typedef struct TSSLCipherSuiteInfo_ TSSLCipherSuiteInfo;



/*==============
	SSL Alert
 ==============*/

/*----------
	Level
 ----------*/

typedef slim_int TSSLAlertLevel;

/* DO NOT CHANGE CONSTANTS */
#define SLIM_SSL_AL_WARNING	1
#define SLIM_SSL_AL_FATAL	2


/*----------------
	Description
 ----------------*/

typedef slim_int TSSLAlertDescription;

/* DO NOT CHANGE CONSTANTS */
#define SLIM_SSL_AD_NOTHING						-1
#define SLIM_SSL_AD_CLOSE_NOTIFY				0	/* warning	-----	SSLv3	TLSv2 */
#define SLIM_SSL_AD_V2_NO_CIPHER				1	/* fatal	SSLv2	-----	----- */
#define SLIM_SSL_AD_V2_NO_CERTIFICATE			2	/* warning	SSLv2	-----	----- */
#define SLIM_SSL_AD_V2_BAD_CERTIFICATE			4	/* fatal	SSLv2	-----	----- */
#define SLIM_SSL_AD_V2_UNSUPPORTED_CERT_TYPE	6	/* fatal	SSLv2	-----	----- */
#define SLIM_SSL_AD_UNEXPECTED_MESSAGE			10	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_BAD_RECORD_MAC				20	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_DECRYPTION_FAILED			21	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_RECORD_OVERFLOW				22	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_DECOMPRESSION_FAILURE		30	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_HANDSHAKE_FAILURE			40	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_NO_CERTIFICATE				41	/* warning	-----	SSLv3	----- */
#define SLIM_SSL_AD_BAD_CERTIFICATE				42	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_UNSUPPORTED_CERTIFICATE		43	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_CERTIFICATE_REVOKED			44	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_CERTIFICATE_EXPIRED			45	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_CERTIFICATE_UNKNOWN			46	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_ILLEGAL_PARAMETER			47	/* fatal	-----	SSLv3	TLSv1 */
#define SLIM_SSL_AD_UNKNOWN_CA					48	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_ACCESS_DENIED				49	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_DECODE_ERROR				50	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_DECRYPT_ERROR				51	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_EXPORT_RESTRICTION			60	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_PROTOCOL_VERSION			70	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_INSUFFICIENT_SECURITY		71	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_INTERNAL_ERROR				80	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_USER_CANCELED				90	/* fatal	-----	-----	TLSv1 */
#define SLIM_SSL_AD_NO_RENEGOTIATION			100	/* warning	-----	-----	TLSv1 */


/*----------
	Alert
 ----------*/

struct TSSLAlert_ {
	slim_bool fIsSent;
	TSSLAlertLevel fLevel;
	TSSLAlertDescription fDescription;
};
typedef struct TSSLAlert_ TSSLAlert;

/* Set Method */
typedef slim_int (*TSSLAlertSetProc)(iTSSL *self, TSSLAlertDescription in_alert_desc, slim_int in_alert_ecode);



/*===============
	Structures
 ===============*/

/*---------------------
	Protocol Version
 ---------------------*/

struct TSSLVersion_ {
	slim_half fMajor;
	slim_half fMinor;
};
typedef struct TSSLVersion_ TSSLVersion;


/*------------------------------------
	Signature

	Supported RSA-Signature, ONLY!!
	ServerKeyExchange, ClientVerify
 ------------------------------------*/

typedef slim_byte TSSLSignature[SLIM_CRYPT_MD5_DIGESTSIZE + SLIM_CRYPT_SHS_DIGESTSIZE];


/*-----------
	Random
 -----------*/

#define SLIM_SSL2_RANDOM_SIZE			0x10
#define SLIM_SSL3_RANDOM_SIZE			0x20
#define SLIM_SSL2_MAX_CONNECTION_ID_LEN	32
#define SLIM_SSL3_RANDOM_BYTES_OFS	4

struct TSSLRandom_ {
	slim_int  fSize;
	slim_byte fData[SLIM_SSL3_RANDOM_SIZE];
};
typedef struct TSSLRandom_ TSSLRandom;


/*---------------
	Session ID
 ---------------*/

#define SLIM_SSL_MAX_SESSION_ID_LEN		32	/* 0 .. 32 */
#define SLIM_SSL2_MAX_CHALLENGE_LEN		SLIM_SSL_MAX_SESSION_ID_LEN

struct TSSLSessionID_ {
	slim_int fLen;
	slim_byte fData[SLIM_SSL_MAX_SESSION_ID_LEN];
};
typedef struct TSSLSessionID_ TSSLSessionID;


/*-----------------------
	Compression Method
 -----------------------*/

typedef slim_int TSSLCompression;

/* Support NULL, ONLY */
enum {
	SLIM_SSL_COMPRESSION_NULL = 0,
	SLIM_SSL_COMPRESSIONS
};


/*-------------------
	 Master Secret
 -------------------*/

struct TSSLMasterSecret_ {
	slim_byte fData[SLIM_SSL3_MS_SIZE];
};
typedef struct TSSLMasterSecret_ TSSLMasterSecret;


/*----------------------
	Pre-Master Secret
 ----------------------*/

#define SLIM_SSL3_PMS_SIZE		48
#define SLIM_SSL3_PMS_RAND_OFS	2
#define SLIM_SSL3_PMS_RAND_SIZE	46

struct TSSLPreMasterSecret_ {
	slim_byte fData[SLIM_SSL3_PMS_SIZE];
};
typedef struct TSSLPreMasterSecret_ TSSLPreMasterSecret;


/*---------------
	MAC Secret
 ---------------*/

struct TSSLMACSecret_ {
	slim_int fLen;
	slim_byte fData[SLIM_SSL_MAX_HASH_LEN];
};
typedef struct TSSLMACSecret_ TSSLMACSecret;


/*----------------
	Init Vector
 ----------------*/

struct TSSLInitVector_ {
	slim_int fLen;
	slim_byte fData[SLIM_SSL_MAX_IV_LEN];
};
typedef struct TSSLInitVector_ TSSLInitVector;


/*---------------
	Cipher Key
 ---------------*/

struct TSSLCipherKey_ {
	slim_int fLen;
	slim_byte fData[SLIM_SSL_MAX_KEY_MATERIAL];
};
typedef struct TSSLCipherKey_ TSSLCipherKey;


/*--------------------
	Sequence Number
 --------------------*/

struct TSSLSeqNum_ {
	slim_word	fHi;
	slim_word	fLo;
};
typedef struct TSSLSeqNum_ TSSLSeqNum;


/*------------------------
	Security Parameters
 ------------------------*/

struct TSSLSecParams_ {
	TSSLCompression	fCompression;
	TSSLCipherSuite	fCipherSuite;
	TSSLMACSecret	fMACKey;
	TSSLInitVector	fIV;
	TSSLCipherKey	fCipherKey;
};
typedef struct TSSLSecParams_ TSSLSecParams;



/*=======================
	SSL Cipher Context
 =======================*/

/*-----------------------
	SSL Cipher Context
 -----------------------*/

typedef struct iTSSLCipherContext_ **TSSLCipherContext;



/*=====================
	SSL Debug Notify
 =====================*/
#ifdef SLIM_CONFIG_SSL_DEBUG

/*---------------
	Structures
 ---------------*/

struct TSSLDebugNotify_New_ {
	slim_char	*fServerName;
	slim_int	fServerPort;
};
typedef struct TSSLDebugNotify_New_ TSSLDebugNotify_New;

struct TSSLDebugNotify_Stat_ {
	slim_int	fRefCnt;
	slim_int	fHitCnt;
};
typedef struct TSSLDebugNotify_Stat_ TSSLDebugNotify_Stat;

struct TSSLDebugNotify_Rec_ {
	slim_byte	*fPtr;
	slim_int	fLen;
};
typedef struct TSSLDebugNotify_Rec_ TSSLDebugNotify_Rec;


/*----------------------
	SSL Socket Notify
 ----------------------*/

enum {
	SLIM_SSL_DEBUG_SOCKNTFY_NEW = 0,
	SLIM_SSL_DEBUG_SOCKNTFY_DELETE,
	SLIM_SSL_DEBUG_SOCKNTFY_STATE,
	SLIM_SSL_DEBUG_SOCKNTFY_VERSION,
	SLIM_SSL_DEBUG_SOCKNTFY_CH_READ_CIPHER,
	SLIM_SSL_DEBUG_SOCKNTFY_CH_WRITE_CIPHER,
	SLIM_SSL_DEBUG_SOCKNTFY_READ_SEQNUM,
	SLIM_SSL_DEBUG_SOCKNTFY_WRITE_SEQNUM,
	SLIM_SSL_DEBUG_SOCKNTFY_TIMER_START,
	SLIM_SSL_DEBUG_SOCKNTFY_TIMER_STOP,
	SLIM_SSL_DEBUG_SOCKNTFY_TIMER_TIMEDOUT,
	SLIM_SSL_DEBUG_SOCKNTFY_SEND_REC,
	SLIM_SSL_DEBUG_SOCKNTFY_RECV_REC,
	SLIM_SSL_DEBUG_SOCKNTFIES
};

struct TSSLDebugSockNotify_ {
	slim_int	fType;
	slim_int	fTCPDesc;
	union {
		TSSLDebugNotify_New		fNew;
		slim_int				fState;
		TSSLVersion				fVersion;
		TSSLCipherSuite			fCipherSuite;
		TSSLSeqNum				fSeqNum;
		slim_int				fTimerEvent;
		TSSLDebugNotify_Rec		fRec;
	} uArg;
};
typedef struct TSSLDebugSockNotify_ TSSLDebugSockNotify;


/*-----------------------
	SSL Session Notify
 -----------------------*/

enum {
	SLIM_SSL_DEBUG_SESSNTFY_NEW = 0,
	SLIM_SSL_DEBUG_SESSNTFY_DELETE,
	SLIM_SSL_DEBUG_SESSNTFY_VERSION,
	SLIM_SSL_DEBUG_SESSNTFY_CIPHERSUITE,
	SLIM_SSL_DEBUG_SESSNTFY_USE,
	SLIM_SSL_DEBUG_SESSNTFY_RESUMABLE,
	SLIM_SSL_DEBUG_SESSNTFY_STAT,
	SLIM_SSL_DEBUG_SESSNTFY_CERT_VERIF_RESULT,
	SLIM_SSL_DEBUG_SESSNTFIES
};

struct TSSLDebugSessNotify_ {
	slim_int	fType;
	slim_pix	fSessionPix;
	union {
		TSSLDebugNotify_New		fNew;
		TSSLVersion				fVersion;
		TSSLCipherSuite			fCipherSuite;
		slim_int				fUseCnt;
		slim_bool				fResumable;
		TSSLDebugNotify_Stat	fStat;
		slim_int				fCertVerifResult;
	} uArg;
};
typedef struct TSSLDebugSessNotify_ TSSLDebugSessNotify;


/*---------------------
	SSL Alert Notify
 ---------------------*/

struct TSSLDebugAlrtNotify_ {
	slim_int	fTCPDesc;
	slim_char	*fServerName;
	slim_int	fServerPort;
	TSSLVersion	fVersion;
	TSSLAlert	fAlert;
};
typedef struct TSSLDebugAlrtNotify_ TSSLDebugAlrtNotify;

#endif /* SLIM_CONFIG_SSL_DEBUG */



/*====================
	Handshake Layer
 ====================*/

/*--------------------
	Handshake State
 --------------------*/

enum {
	/* Common State */
	SLIM_SSL_ST_NOT_INITIALIZED = 0,
	SLIM_SSL_ST_INITIALIZED,
	
	/* SSL v3.x Handshake State */
	SLIM_SSL3_ST_CLIENT_HELLO_PACK,
	SLIM_SSL3_ST_CLIENT_HELLO_SEND,
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
	SLIM_SSL3_ST_V2CLIENT_HELLO_PACK,
	SLIM_SSL3_ST_V2CLIENT_HELLO_SEND,
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
	SLIM_SSL3_ST_SERVER_HELLO_RECV,
	SLIM_SSL3_ST_SERVER_HELLO_UNPACK,
	SLIM_SSL3_ST_SERVER_CERT_RECV,
	SLIM_SSL3_ST_SERVER_CERT_UNPACK,
	SLIM_SSL3_ST_SERVER_RSP_RECV_A,
	SLIM_SSL3_ST_SERVER_KEY_EXCH_UNPACK,
	SLIM_SSL3_ST_SERVER_RSP_RECV_B,
	SLIM_SSL3_ST_CERT_REQ_UNPACK,
	SLIM_SSL3_ST_SERVER_HELLO_DONE_RECV,
	SLIM_SSL3_ST_CLIENT_CERT_SELECT,
	SLIM_SSL3_ST_CLIENT_CERT_PACK,
	SLIM_SSL3_ST_CLIENT_CERT_SEND,
	SLIM_SSL3_ST_CLIENT_KEY_EXCH_PMS,
	SLIM_SSL3_ST_CLIENT_KEY_EXCH_PACK,
	SLIM_SSL3_ST_CLIENT_KEY_EXCH_SEND,
	SLIM_SSL3_ST_GENERATE_KEY,
	SLIM_SSL3_ST_CERT_VERIFY_PACK,
	SLIM_SSL3_ST_CERT_VERIFY_SEND,
	SLIM_SSL3_ST_CH_CIPHER_SPEC_SEND,
	SLIM_SSL3_ST_CLIENT_FINISHED_PACK,
	SLIM_SSL3_ST_CLIENT_FINISHED_SEND,
	SLIM_SSL3_ST_CH_CIPHER_SPEC_RECV,
	SLIM_SSL3_ST_SERVER_FINISHED_RECV,
	SLIM_SSL3_ST_SERVER_FINISHED_UNPACK,
	/* SSL v3.x Alert State */
	SLIM_SSL3_ST_ALERT_PACK,
	SLIM_SSL3_ST_ALERT_SEND,

#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
	/* SSLv2.0 Handshake State */
	SLIM_SSL2_ST_CLIENT_HELLO_PACK,
	SLIM_SSL2_ST_CLIENT_HELLO_SEND,
	SLIM_SSL2_ST_SERVER_HELLO_RECV,
	SLIM_SSL2_ST_SERVER_HELLO_UNPACK,
	SLIM_SSL2_ST_CLIENT_MKEY_PACK,
	SLIM_SSL2_ST_CLIENT_MKEY_SEND,
	SLIM_SSL2_ST_GENERATE_KEY,
	SLIM_SSL2_ST_CLIENT_FINISH_PACK,
	SLIM_SSL2_ST_CLIENT_FINISH_SEND,
	SLIM_SSL2_ST_SERVER_VERIFY_RECV,
	SLIM_SSL2_ST_SERVER_VERIFY_UNPACK,
	SLIM_SSL2_ST_SERVER_RSP_RECV_A,
	SLIM_SSL2_ST_REQ_CERT_UNPACK,
	SLIM_SSL2_ST_SERVER_RSP_RECV_B,
	SLIM_SSL2_ST_SERVER_FINISH_UNPACK,
	SLIM_SSL2_ST_CLIENT_CERT_SELECT,
	SLIM_SSL2_ST_CLIENT_CERT_PACK,
	SLIM_SSL2_ST_CLIENT_CERT_SEND,
	/* SSLv2.0 Alert State */
	SLIM_SSL2_ST_ALERT_PACK,
	SLIM_SSL2_ST_ALERT_SEND,
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */

	/* Common State */
	SLIM_SSL_ST_DONE,
	SLIM_SSL_ST_DORMANT,
	SLIM_SSL_STS
};



/*=======================
	SSL Session DB I/F
 =======================*/

struct TSSLSessionDBKey_ {
	TString fServerName;
	slim_int fServerPort;
};
typedef struct TSSLSessionDBKey_ TSSLSessionDBKey;

struct TSSLSessionDBRecord_ {
	slim_int fMajorVersion;
	slim_int fMinorVersion;
	slim_byte fSessionID[SLIM_SSL_MAX_SESSION_ID_LEN];
	slim_int fSessionIDLen;
	TSSLCipherSuite fCipherSuite;
	slim_handle fCertList;
	slim_int fCertListLen;
	slim_int fCertVerifyResult;
	union {
		struct {
			slim_byte fMasterKey[SLIM_SSL_MAX_KEY_MATERIAL];
			slim_int fMasterKeyLen;
			slim_byte fKeyArg[SLIM_SSL_MAX_IV_LEN];
			slim_int fKeyArgLen;
		} V2;
		struct {
			slim_byte fMasterSecret[SLIM_SSL3_MS_SIZE];
		} V3;
	} u;
};
typedef struct TSSLSessionDBRecord_ TSSLSessionDBRecord;

typedef slim_int (*TSSLSessionDBStoreProc)(slim_opaque in_user_data, TSSLSessionDBKey *in_key, TSSLSessionDBRecord *in_record);
typedef slim_int (*TSSLSessionDBFetchProc)(slim_opaque in_user_data, TSSLSessionDBKey *in_key, TSSLSessionDBRecord *out_record);
typedef void (*TSSLSessionDBDeleteProc)(slim_opaque in_user_data, TSSLSessionDBKey *in_key);
typedef void (*TSSLSessionDBClearProc)(slim_opaque in_user_data);
typedef void (*TSSLSessionDBUnregisterProc)(slim_opaque in_user_data);

struct TSSLSessionDB_ {
	slim_opaque fUserData;
	TSSLSessionDBStoreProc fStoreProc;
	TSSLSessionDBFetchProc fFetchProc;
	TSSLSessionDBDeleteProc fDeleteProc;
	TSSLSessionDBClearProc fClearProc;
	TSSLSessionDBUnregisterProc fUnregisterProc;
};
typedef struct TSSLSessionDB_ TSSLSessionDB;



/*==============
	SSL Class
 ==============*/

/*---------------------------
	CipherSuite Preference
 ---------------------------*/

struct TSSLCipherSuitePref_ {
	slim_int fV2Size;
	slim_int fV3Size;
	TSSLCipherSuite fV2List[SLIM_SSL2_CIPHER_SUITES];
	TSSLCipherSuite fV3List[SLIM_SSL3_CIPHER_SUITES];
};
typedef struct TSSLCipherSuitePref_ TSSLCipherSuitePref;


/*----------------------------
	Certificate Check Flags
 ----------------------------*/

#define SLIM_SSL_CERT_CHECK_CN			SLIM_CERT_CHECK_CN			/* SubjectCN check */
#define SLIM_SSL_CERT_CHECK_KU			SLIM_CERT_CHECK_KU			/* Key Usage check */
#define SLIM_SSL_CERT_CHECK_BC			SLIM_CERT_CHECK_BC			/* Basic Constraints check */
#define SLIM_SSL_CERT_CHECK_CRL			SLIM_CERT_CHECK_CRL			/* CRL Revocation check */
#define SLIM_SSL_CERT_CHECK_EKU			SLIM_CERT_CHECK_EKU			/* extended key usage check */
#define SLIM_SSL_CERT_CHECK_LOOP		SLIM_CERT_CHECK_LOOP		/* check Cert::fSubject != IssuerCert::fIssuer */
#define SLIM_SSL_CERT_NO_CHECK_ROOT_BC	SLIM_CERT_NO_CHECK_ROOT_BC	/* do not check basic constraints of root ca cert */


/*------------------
	Session Cache
 ------------------*/

struct TSSLSessionCache_ {
	TSpecList	fBase;
	TSSLClass	*fClass;
	slim_int	fLimitSessions;
	slim_bool	fInitialized;

#ifdef SLIM_CONFIG_MULTITHREAD
	slim_opaque	fMutex;
#endif /* SLIM_CONFIG_MULTITHREAD */
};
typedef struct TSSLSessionCache_ TSSLSessionCache;


/*--------------
	SSL Class
 --------------*/

enum {
	SLIM_SSL_TIMER_EVENT_NOTHING = -1,
	SLIM_SSL_TIMER_EVENT_CLIENT_HELLO,
	SLIM_SSL_TIMER_EVENT_V3_CLIENT_FINISHED,
	SLIM_SSL_TIMER_EVENT_V2_CLIENT_FINISH,
	SLIM_SSL_TIMER_EVENT_NO_CLIENT_CERT,
	SLIM_SSL_TIMER_EVENT_CLIENT_CERT,
	SLIM_SSL_TIMER_EVENTS
};

/* for in_index of TSSL_ClientCertSelect() */
/* in_index >= 0 index of selected client cert */
#define SLIM_SSL_CLIENT_CERT_SEL_CANCEL	(-1)	/* cancel. send no_certificate alert */
#define SLIM_SSL_CLIENT_CERT_SEL_REJECT	(-2)	/* reject. disconnect SSL */

typedef slim_bool (*TSSLServerCertConfirmProc)(TSSL in_ssl, slim_int in_verify_result, TCertList in_list, slim_opaque in_aux);
typedef slim_bool (*TSSLClientCertSelectProc)(TSSL in_ssl, TClientCertList in_list, slim_opaque in_aux);
typedef slim_int (*TSSLCertListVerifyProc)(TCertList in_list, slim_opaque in_aux);
typedef slim_bool (*TSSLPrivateKeyEncryptProc)(TSSL in_ssl, slim_byte *in_key, slim_int in_key_len, slim_byte *in_buf, slim_int in_len, slim_opaque in_aux);
typedef void (*TSSLDeleteCallback)(TSSL in_ssl, slim_opaque in_aux);
typedef void (*TSSLNotifyStateProc)(TSSL in_ssl, slim_int in_prev_state, slim_int in_state, slim_opaque in_aux);
typedef slim_bool (*TSSLCurrentTimeProc)(slim_time *out_time, slim_opaque in_aux);
typedef slim_int (*TSSLStateProc)(iTSSL *iself);

struct TSSLClass_ {
	TSSLSessionDB fSessionDB;
	TCertDBManager fCertDBManager;

	TCryptRandom fRandomGenerator;	/* Random Bytes Generator */
	TRomCertStore fRomCertStore;	/* ROM Certificate Store  */
	TMemCertStore fMemCertStore;	/* MEM Certificate Store  */
	TCertDB fCertDB;				/* Certificate Database   */
	TSSLSessionCache fSessionCache;	/* SSL Session Cache      */

	/* Instance list */
	TSSL fFirstInstance, fLastInstance;

	/* Preference */
	slim_int fFlag;
	slim_int fCertCheckFlag;
	slim_int fCertLimitLen;
	slim_int fCertCNMatchLen;
	slim_int fCertChainLimitLen;
	slim_int fTimeLimit[SLIM_SSL_TIMER_EVENTS];
	TSSLCipherSuitePref fCipherSuitePref;

	TSSLCertListVerifyProc fCertListVerifyProc;
	TSSLServerCertConfirmProc fServerCertConfirmProc;
	TSSLClientCertSelectProc fClientCertSelectProc;
	TSSLPrivateKeyEncryptProc fPrivateKeyEncryptProc;
	TSSLCurrentTimeProc fCurrentTimeProc;
	TSSLDeleteCallback fDeleteCallback;
	TSSLNotifyStateProc fNotifyStateProc;
	slim_opaque fCertListVerifyAux;
	slim_opaque fServerCertConfirmAux;
	slim_opaque fClientCertSelectAux;
	slim_opaque fPrivateKeyEncryptAux;
	slim_opaque fCurrentTimeAux;
	slim_opaque fDeleteCallbackAux;
	slim_opaque fNotifyStateAux;

	slim_int (*fTCPReadPeer)(slim_int in_desc, slim_byte *out_buf, slim_int in_len);
	slim_int (*fTCPWritePeer)(slim_int in_desc, slim_byte *in_buf, slim_int in_len);

	TSSLStateProc fHandleStateProc;

#ifdef SLIM_CONFIG_MULTITHREAD
	slim_opaque fMutex;
#endif /* SLIM_CONFIG_MULTITHREAD */

#ifdef SLIM_CONFIG_SSL_DEBUG
	void (*fDebugPrintfProc)(char *in_format, ...);
	void (*fDebugSockNotifyProc)(TSSLDebugSockNotify *in_notify);
	void (*fDebugSessNotifyProc)(TSSLDebugSessNotify *in_notify);
	void (*fDebugAlrtNotifyProc)(TSSLDebugAlrtNotify *in_notify);
#endif /* SLIM_CONFIG_SSL_DEBUG */
};

/* API */
#ifdef SLIM_CONFIG_USE_SSL


#define SSL_SetOptionFlag(ssl_class, option, on)	SSL_SetFlag(ssl_class, option, on)


#ifdef SLIM_CONFIG_SSL_DEBUG
#endif
#else
#define SSL_Initialize(in_class, in_random_seed)						(slim_true)
#define SSL_Finalize(in_class)											((void)0)
#define SSL_New(in_class, in_ssl_flag, in_sever_name, in_server_port)	(slim_nil)
#define SSL_ClearSessionCache(ssl_class)								((void)0)
#define SSL_OpenCertDB(in_class, out_list)								(SLIM_E_OK)
#define SSL_CloseCertDB(in_class, list)									((void)0)
#define SSL_SetOptionFlag(ssl_class, option, on)						((void)0)
#define SSL_SetCertChainLimitLen(in_class, in_len)						((void)0)
#define SSL_SetCertLimitLen(in_class, in_limit)							((void)0)
#define SSL_SetTimeLimit(in_class, in_event, in_limit)					((void)0)
#define SSL_Timeout(in_class)											(SLIM_INT_MAX)
#define SSL_SetServerCertConfirmProc(in_class, in_proc, in_aux)			((void)0)
#define SSL_SetClientCertSelectProc(in_class, in_proc, in_aux)			((void)0)
#define SSL_SetPrivateKeyEncryptProc(in_class, in_proc, in_aux)			((void)0)
#define SSL_SetNotifyStateProc(in_class, in_proc, in_aux)				((void)0)
#define SSL_SetCipherSuitePref(in_class, in_pref)						((void)0)
#define SSL_RegisterSessionDB(in_class, in_db, out_old)					(SLIM_E_INVAL)
#define SSL_RegisterCertStore(in_class, in_store)						(SLIM_E_GENERIC)
#ifdef SLIM_CONFIG_SSL_DEBUG
#define SSL_SetDebugProc(in_class, in_printf_proc, in_sock_notify_proc, in_sess_notify_proc, in_alrt_notify_proc)	((void)0)
#endif
#endif /* SLIM_CONFIG_USE_SSL */



/*==================
	SSL Instatnce
 ==================*/

/*---------------
	SSL Buffer
 ---------------*/

struct TSSLBuf_ {
	slim_int fState;
	slim_vhandle fHdl;
	slim_byte *fPtr;
	slim_int fCurLen;
	slim_int fOfs;
	slim_int fLen;
};
typedef struct TSSLBuf_ TSSLBuf;

enum {
	SLIM_SSL_RWST_NOTHING = 0,
	SLIM_SSL_RWST_READ_START,
	SLIM_SSL_RWST_READ_HEADER,
	SLIM_SSL_RWST_READ_CONTENT,
	SLIM_SSL_RWST_READ_PROGRESS,
	SLIM_SSL_RWST_READ_DONE,
	SLIM_SSL_RWST_WRITE_START,
	SLIM_SSL_RWST_WRITE_WAIT,
	SLIM_SSL_RWST_WRITE_PROGRESS,
	SLIM_SSL_RWST_WRITE_DONE
};


/*------------------
	SSL Instatnce
 ------------------*/

struct iTSSL_ {
	TSSLClass *fClass;

	TSSLStateProc fHandleStateProc;

	TSSL fSelf;			/* Reverse handle to itself */
	TSSL fNextInstance;

	slim_int fFlag;

	slim_int fState;
	slim_int fStateFlag;

	TCertDBManager fCertDBManager;

	/* TCP Descriptor */
	slim_int fFd;

	/* timer */
	slim_int fTimerEvent;
	slim_int fStartTick;

	/* server name and port */
	TString fServerName;
	slim_int fServerPort;

	/*
		If SLIM_SSL_CHECK_FLAG(fFlag, SLIM_SSL_FLAG_FULL_DUPLEX), use two buffers.
		Else, use one buffer for sending and receiving.
	*/
	TSSLBuf fReadBuf, fWriteBuf;

	/* sequence number -- protection against replay attack */
	TSSLSeqNum fReadSeqNum, fWriteSeqNum;

	/*
		pending write sequence number
		-- which is updated when finishing to send the pending SSL message
	*/
	TSSLSeqNum fPendingWriteSeqNum;

	/* digest of handshake messages */
	TMD fHandshakeMessagesMD5, fHandshakeMessagesSHA;

	/* version */
	TSSLVersion fVersion;

	/* session id */
	TSSLSessionID fSessionId;

	/* client and server random */
	TSSLRandom fClientRandom, fServerRandom;

	/* master secret */
	TSSLMasterSecret fMasterSecret;

	/* Security Parameters */
	TSSLSecParams fCurrentSWParams, fCurrentCWParams;
	TSSLSecParams fPendingSWParams, fPendingCWParams;

	/* Cipher Context */
	TSSLCipherContext fCWCipherCtx, fSWCipherCtx;

	/* Server's Temporary RSA Public Key */
	TRSAPublicKey fServerPublicKey;

	/* Server's Trust CA List */
	slim_handle fCAList;

	/* Server Certificate List */
	TCertList fServerCertList;

	/* Client Certificate List */
	TCertList fClientCertList;
	TClientCertList fClientCertSelectList;

	/* Pre-Master Secret */
	TSSLPreMasterSecret fPreMasterSecret;

	/* Accepted certificate verification errors */
	slim_int fCertVerifResult;
	slim_int fCurCertVerifResult;

	/* alert */
	TSSLAlertSetProc fAlertSet;
	TSSLAlert fAlert;
	slim_int fAlertEcode;
	slim_int fAlertState;

	TSSLCertListVerifyProc fCertListVerifyProc;
	slim_opaque fCertListVerifyAux;

	/* Certificate Callback Proc */
	TSSLServerCertConfirmProc fServerCertConfirmProc;
	TSSLClientCertSelectProc fClientCertSelectProc;
	TSSLPrivateKeyEncryptProc fPrivateKeyEncryptProc;
	slim_opaque fServerCertConfirmAux;
	slim_opaque fClientCertSelectAux;
	slim_opaque fPrivateKeyEncryptAux;

	/* Current Time Proc */
	TSSLCurrentTimeProc fCurrentTimeProc;
	slim_opaque fCurrentTimeAux;

#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
	TSSLCipherKey fMasterKey;
	TSSLSessionID fCertificateChallenge;
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
};


/* State Flags */
#define SLIM_SSL_ST_FLAG_NONE						0x00000000
#define SLIM_SSL_ST_FLAG_AUTHENTICATED_SERVER		0x00001000	/* A connecting server have been authenticated */
#define SLIM_SSL_ST_FLAG_USE_TEMP_RSAKEY			0x00002000	/* use temporary RSA keys */
#define SLIM_SSL_ST_FLAG_NEED_CLIENT_CERTIFICATE	0x00004000	/* need client certificate */
#define SLIM_SSL_ST_FLAG_TIMER						0x00008000	/* Stert timer */
#define SLIM_SSL_ST_FLAG_RECV_CLOSE_NOTIFY			0x00010000	/* Receive CloseNotify */
#define SLIM_SSL_ST_FLAG_SEND_CLOSE_NOTIFY			0x00020000	/* Send CloseNotify */
#define SLIM_SSL_ST_FLAG_WAIT_FOR_DIALOG			0x00040000	/* Wait for dialog */
#define SLIM_SSL_ST_FLAG_OPEN_CERTDB				0x00080000	/* CertDB is opened */
#define SLIM_SSL_ST_FLAG_SEND_ZERO_APP_DATA			0x00100000	/* write 0 byte app-data */
#define SLIM_SSL_ST_FLAG_PANIC						0x00200000	/* fatal error */
#define SLIM_SSL_ST_FLAG_NEED_CLIENT_SIGNATURE		0x00400000	/* need client signature */
#define SLIM_SSL_ST_FLAG_RECV_HELLO_REQUEST			0x00800000	/* receive HelloRequest message */
#define SLIM_SSL_ST_FLAG_CWCIPHERCTX_INITIALIZED	0x01000000
#define SLIM_SSL_ST_FLAG_SWCIPHERCTX_INITIALIZED	0x02000000


/*-------------------
	SSL Error Code
 -------------------*/

/* for SSL */
#define SLIM_SSL_E_TCP_READ				-101	/* TCP read error */
#define SLIM_SSL_E_TCP_WRITE			-102	/* TCP write error */
#define SLIM_SSL_E_MAC					-103	/* different MAC(HASH) */
#define SLIM_SSL_E_RECORD_LEN			-104	/* too large record */
#define SLIM_SSL_E_BAD_MESSAGE			-105	/* unexpected handshake message */
#define SLIM_SSL_E_NOT_IMPLEMENTED		-106	/* function is not implemented */
#define SLIM_SSL_E_RSA					-107	/* failure in RSA */
#define SLIM_SSL_E_CIPHER_SUITE			-108	/* cipher suite is not supported */
#define SLIM_SSL_E_GOT_ALERT			-109	/* got alert from server */
#define SLIM_SSL_E_EOF					-110	/* find EOF */
#define SLIM_SSL_E_BAD_FLAG				-111	/* invalid SSL connection mode flag */
#define SLIM_SSL_E_TLS_INTOLERANT		-112	/* tls intolerant server */

/* for Cert */
#define SLIM_SSL_E_CERT_LEN				-201
#define SLIM_SSL_E_CERT_DB				-202	/* CertDB error */
#define SLIM_SSL_E_CERT_VERIFY			-203	/* verify error */
#define SLIM_SSL_E_CERT_NOISSUER		-204	/* issuer's certification is not found */
#define SLIM_SSL_E_CERT_DECODE			-205	/* decode / encode failure */
#define SLIM_SSL_E_CERT_NOT_IMPLEMENTED	-206	/* function is not implemented */
#define SLIM_SSL_E_CERT_NO_CERTIFICATE	-207	/* client's certificatino is not found */
#define SLIM_SSL_E_CERT_EXPIRED			-208	/* certification is expired */
#define SLIM_SSL_E_CERT_NOCRL			-209	/* no CRL */
#define SLIM_SSL_E_CERT_REVOKED			-210	/* certificate had been revoked */
#define SLIM_SSL_E_CERT_EXTENSION		-211	/* X.509 extesion error */

#ifdef SLIM_CONFIG_USE_SSL
#else
#define TSSL_Alert(self, out_alert)									(slim_false)
#define TSSL_CipherSuite(self, out_suite)							((void)0)
#define TSSL_ClientCertSelect(self, in_index)						((void)0)
#define TSSL_Connect(self)											(SLIM_E_GENERIC)
#define TSSL_ConnectProgress(self)									(SLIM_E_GENERIC)
#define TSSL_Delete(self)											((void)0)
#define TSSL_IsAlive(self)											(slim_false)
#define TSSL_MakeServerCertList(self)								(slim_nil)
#define TSSL_PrivateKeyEncrypt										(slim_nil)	/* pointer to function */
#define TSSL_Read(self, buf, len)									(SLIM_E_GENERIC)
#define TSSL_ServerCertConfirm(self, in_verify_result, in_confirm)	((void)0)
#define TSSL_SetClientCertSelectProc(self, in_proc, in_aux)			((void)0)
#define TSSL_SetCurrentTimeProc(self, in_proc, in_aux)				((void)0)
#define TSSL_SetFd(self, in_fd)										((void)0)
#define TSSL_SetPrivateKeyEncryptProc(self, in_proc, in_aux)		((void)0)
#define TSSL_SetServerCertConfirmProc(self, in_proc, in_aux)		((void)0)
#define TSSL_State(self)											(0)
#define TSSL_Version(self, out_version)								((void)0)
#define TSSL_Write(self, buf, len)									(SLIM_E_GENERIC)
#endif

SLIM_END_C_LINKAGE

#endif /* SLIM_SSL_H */
