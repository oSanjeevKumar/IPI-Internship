/*
	ssl.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/ssl/ssl.h 218   06/01/25 2:48 Nagamati $ */

#ifndef SLIM_SSL_H_PRIVATE
#define SLIM_SSL_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

#ifdef SLIM_CONFIG_USE_SSL

/*************************************************************************************
	SSL Implementation Layer Structure

		Handshake Layer		SSLv2.0, SSLv3.0 and TLSv1.0 Protocol
							(ChangeCipherSpec, Alert, Handshake, ApplicationData)

		Message Layer		Send/Recv Handshake, Alert and ChengeCipherSpec Message

		Record Layer		Send/Recv SSL Record
							(Encryption, Decryption and MAC Verification)

		Packet Layer		Send/Recv TCP Packet (Byte Stream)
 *************************************************************************************/


/*===================================
	Endian Independent Pack/Unpack
 ===================================*/

#define slim_ssl_ptr_to_u8(num, p) \
	(num = (*((slim_byte *)(p))))

#define slim_ssl_ptr_to_u16(num, p) \
	(num = (slim_half)((((slim_half)(*(((slim_byte *)(p))+0))) << 8) + \
					   (((slim_half)(*(((slim_byte *)(p))+1))) << 0)))

#define slim_ssl_ptr_to_u24(num, p) \
	(num = (((slim_word)(*(((slim_byte *)(p))+0))) << 16) + \
		   (((slim_word)(*(((slim_byte *)(p))+1))) <<  8) + \
		   (((slim_word)(*(((slim_byte *)(p))+2))) <<  0))

#define slim_ssl_ptr_to_u32(num, p) \
	(num = (((slim_word)(*(((slim_byte *)(p))+0))) << 24) + \
		   (((slim_word)(*(((slim_byte *)(p))+1))) << 16) + \
		   (((slim_word)(*(((slim_byte *)(p))+2))) <<  8) + \
		   (((slim_word)(*(((slim_byte *)(p))+3))) <<  0))

#define slim_ssl_u8_to_ptr(p, num) \
	(*((slim_byte *)(p)) = (slim_byte)(num));

#define slim_ssl_u16_to_ptr(p, num) \
	((*(((slim_byte *)(p))+0) = ((slim_byte)((num) >> 8))) , \
	 (*(((slim_byte *)(p))+1) = ((slim_byte)((num) >> 0))))

#define slim_ssl_u24_to_ptr(p, num) \
	((*(((slim_byte *)(p))+0) = ((slim_byte)((num) >> 16))) , \
	 (*(((slim_byte *)(p))+1) = ((slim_byte)((num) >> 8 ))) , \
	 (*(((slim_byte *)(p))+2) = ((slim_byte)((num) >> 0 ))))

#define slim_ssl_u32_to_ptr(p, num) \
	((*(((slim_byte *)(p))+0) = ((slim_byte)((num) >> 24))) , \
	 (*(((slim_byte *)(p))+1) = ((slim_byte)((num) >> 16))) , \
	 (*(((slim_byte *)(p))+2) = ((slim_byte)((num) >> 8 ))) , \
     (*(((slim_byte *)(p))+3) = ((slim_byte)((num) >> 0 ))))


/*====================================
	CipherSuite (slim_ssl_cipher.c)
 ====================================*/

/*--------------------------
	Bulk Cipher Algorithm
 --------------------------*/

extern SLIM_ROM TSSLCipherAlgoInfo cSlim_SSLCipherAlgoInfo[SLIM_SSL_CIPHER_ALGOS];

#define TSSLCipherAlgo_IsStream(algo)			(cSlim_SSLCipherAlgoInfo[algo].fFlag & SLIM_SSL_CIPHER_ALGO_FLAG_STREAM)
#define TSSLCipherAlgo_IsExport(algo)			(cSlim_SSLCipherAlgoInfo[algo].fFlag & SLIM_SSL_CIPHER_ALGO_FLAG_EXPORT)
#define TSSLCipherAlgo_ID(algo)					(cSlim_SSLCipherAlgoInfo[algo].fID)
#define TSSLCipherAlgo_KeySize(algo)			(cSlim_SSLCipherAlgoInfo[algo].fKeySize)
#define TSSLCipherAlgo_ExpKeySize(algo)			(cSlim_SSLCipherAlgoInfo[algo].fExpKeySize)
#define TSSLCipherAlgo_EffKeyBits(algo)			(cSlim_SSLCipherAlgoInfo[algo].fEffKeyBits)
#define TSSLCipherAlgo_IVSize(algo)				(cSlim_SSLCipherAlgoInfo[algo].fIVSize)
#define TSSLCipherAlgo_BlkSize(algo)			(cSlim_SSLCipherAlgoInfo[algo].fBlkSize)



/*---------------------
	Digest Algorithm
 ---------------------*/

extern SLIM_ROM TSSLDigestAlgoInfo cSlim_SSLDigestAlgoInfo[SLIM_SSL_DIGEST_ALGOS];

#define TSSLDigestAlgo_ID(algo)			(cSlim_SSLDigestAlgoInfo[algo].fID)
#define TSSLDigestAlgo_DigestSize(algo)	(cSlim_SSLDigestAlgoInfo[algo].fDigestSize)
#define TSSLDigestAlgo_PadSize(algo)	(cSlim_SSLDigestAlgoInfo[algo].fPadSize)


/*----------------
	CipherSuite
 ----------------*/

extern SLIM_ROM TSSLCipherSuiteInfo cSlim_SSLCipherSuiteInfo[SLIM_SSL_CIPHER_SUITES];

#define TSSLCipherSuite_AuthAlgo(suite)		(cSlim_SSLCipherSuiteInfo[suite].fAuthAlgo)
#define TSSLCipherSuite_KyExAlgo(suite)		(cSlim_SSLCipherSuiteInfo[suite].fKyExAlgo)
#define TSSLCipherSuite_CipherAlgo(suite)	(cSlim_SSLCipherSuiteInfo[suite].fCipherAlgo)
#define TSSLCipherSuite_DigestAlgo(suite)	(cSlim_SSLCipherSuiteInfo[suite].fDigestAlgo)
#define TSSLCipherSuite_ID(suite, index)	(cSlim_SSLCipherSuiteInfo[suite].fID[index])

#ifdef SLIM_CONFIG_SSL_DEBUG
#define TSSLCipherSuite_Name(suite)			(cSlim_SSLCipherSuiteInfo[suite].fName)
#endif /* SLIM_CONFIG_SSL_DEBUG */


/*-----------------
	Padding Data
 -----------------*/

/* padding data array for hash in SSLv3.0 */
extern SLIM_ROM slim_byte cSlim_SSL3Padding0x36[];
extern SLIM_ROM slim_byte cSlim_SSL3Padding0x5c[];



/*===============
	Structures
 ===============*/

/*--------------------
	Sequence Number
 --------------------*/

#define TSSLSeqNum_Clear(self)			{(self)->fHi = (self)->fLo = 0;}
#define TSSLSeqNum_Inc(self)			{(self)->fLo++;	if ((self)->fLo == 0) (self)->fHi++;}
#define TSSLSeqNum_ToByteArray(self, p)	{slim_ssl_u32_to_ptr(p, (self)->fHi);	slim_ssl_u32_to_ptr(p+4, (self)->fLo);}



/*=======================
	SSL Cipher Context
 =======================*/

/*----------------
	MAC Context
 ----------------*/

/* SSLv3 */
struct TSSLv3MAC_ {
	TMD	fCtx;
	TMD	fInnerCtx;
	TMD	fOuterCtx;
};
typedef struct TSSLv3MAC_ TSSLv3MAC;


/* SSLv2 */
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
struct TSSLv2MAC_ {
	TMD			fCtx;
	slim_word	fKeySize;
	slim_byte	fKey[24];
};
typedef struct TSSLv2MAC_ TSSLv2MAC;

#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */

/* Context */
union TSSLMAC_ {
	TCryptHMAC	uTLSv1;
	TSSLv3MAC	uSSLv3;
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
	TSSLv2MAC	uSSLv2;
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
};
typedef union TSSLMAC_ TSSLMAC;


/*-----------------------
	SSL Cipher Context
 -----------------------*/

struct iTSSLCipherContext_ {
	TSymCipher	fBulkCipher;
	TSSLMAC		fMAC;
};
typedef struct iTSSLCipherContext_ iTSSLCipherContext;

#define SSLCipherContext_New()				((TSSLCipherContext)slim_handle_alloc(sizeof(iTSSLCipherContext)))
#define TSSLCipherContext_Delete(self)		slim_handle_free((slim_handle)(self))
#define TSSLCipherContext_Lock(self)		(iTSSLCipherContext *)slim_handle_lock((slim_handle)(self))
#define TSSLCipherContext_Unlock(self)		slim_handle_unlock((slim_handle)(self))
#define TSSLCipherContext_Locate(self)		(iTSSLCipherContext *)slim_handle_locate((slim_handle)(self))
#define TSSLCipherContext_Unlocate(self)	slim_handle_unlocate((slim_handle)(self))



/*======================
	SSL Session Cache
 ======================*/

/*----------------
	SSL Session
 ----------------*/

struct TSSLSession_ {
	TSSLSessionDBKey fKey;
	TSSLSessionDBRecord fRecord;

#ifdef SLIM_CONFIG_SSL_DEBUG
	slim_int fStatRefCnt;
	slim_int fStatHitCnt;
#endif /* SLIM_CONFIG_SSL_DEBUG */
};
typedef struct TSSLSession_ TSSLSession;


/*----------------------
	SSL Session Cache
 ----------------------*/


/* Methods */

#define TSSLSessionCache_LockItem(self, pix)			TSpecList_LockItem(&(self)->fBase, pix)
#define TSSLSessionCache_UnlockItem(self, pix)			TSpecList_UnlockItem(&(self)->fBase, pix)
#define TSSLSessionCache_LocateItem(self, pix)			TSpecList_LocateItem(&(self)->fBase, pix)
#define TSSLSessionCache_UnlocateItem(self, pix)		TSpecList_UnlocateItem(&(self)->fBase, pix)

/* for debug */
#ifdef SLIM_CONFIG_SSL_DEBUG
#else
#define TSSLSessionCache_IncStatRefCnt(self, name, port)	
#define TSSLSessionCache_IncStatHitCnt(self, name, port)	
#endif /* SLIM_CONFIG_SSL_DEBUG */



/*====================
	Handshake Layer
 ====================*/

/*-------------------------
	Handshake State Proc
 -------------------------*/

/* Common State (slim_ssl_client.c) */

/* SSLv3.x State (slim_ssl_client3.c) */
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */

/* SSLv2 State (slim_ssl_client2.c) */
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */



/*==================
	Message Layer
 ==================*/

/*-----------------------
	Read / Write State
 -----------------------*/

/* TLSv1 (slim_ssl_tls.c) */
#define slim_tls1_verify_digest(md5, sha, ms, digest)		slim_tls1_digest(md5, sha, slim_nil, ms, digest)
#define slim_tls1_fin_digest(md5, sha, label, ms, digest)	slim_tls1_digest(md5, sha, label, ms, digest)

/* SSLv3.x (slim_ssl_message3.c) */

/* SSLv2 (slim_ssl_message2.c) */
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */



/*=================
	Record Layer
 =================*/

/* Common */
#define iTSSL_EncryptBulkCipher(s,buf,len)	TSSLCipherContext_EncryptDecrypt((s)->fCWCipherCtx,buf,len)
#define iTSSL_DecryptBulkCipher(s,buf,len)	TSSLCipherContext_EncryptDecrypt((s)->fSWCipherCtx,buf,len)

/* SSLv3.x ( slim_ssl_record3.c) */

/* SSLv2 (slim_ssl_record2.c) */
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */



/*=================
	Packet Layer
 =================*/




/*==============
	SSL Class
 ==============*/

/*---------------------------
	CipherSuite Preference
 ---------------------------*/



/*---------------------
	SSL Class Method
 ---------------------*/

#define SSL_VersionFlag(ssl_class)					(SSL_Flag(ssl_class, SLIM_SSL_FLAG_CONN_MASK))
#define SSL_OptionFlag(ssl_class)					(SSL_Flag(ssl_class, SLIM_SSL_FLAG_OPT_MASK))

#define SSL_SetVersionFlag(ssl_class, version, on)	SSL_SetFlag(ssl_class, version, on)



#ifdef SLIM_CONFIG_MULTITHREAD
#endif /* SLIM_CONFIG_MULTITHREAD */

#ifdef SLIM_CONFIG_MULTITHREAD
#define SLIM_SSL_MUTEX_INIT(ssl_class)		{(ssl_class)->fMutex = slim_nil;}
#define SLIM_SSL_MUTEX_FIN(ssl_class)		{(ssl_class)->fMutex = slim_nil;}
#define SLIM_SSL_MUTEX_LOCK(ssl_class)		{if ((ssl_class)->fMutex) slimMutexLockPeer((ssl_class)->fMutex);}
#define SLIM_SSL_MUTEX_UNLOCK(ssl_class)	{if ((ssl_class)->fMutex) slimMutexUnlockPeer((ssl_class)->fMutex);}
#else
#define SLIM_SSL_MUTEX_INIT(ssl_class)		
#define SLIM_SSL_MUTEX_FIN(ssl_class)		
#define SLIM_SSL_MUTEX_LOCK(ssl_class)		
#define SLIM_SSL_MUTEX_UNLOCK(ssl_class)	
#endif /* SLIM_CONFIG_MULTITHREAD */



/*==================
	SSL Instatnce
 ==================*/

/*-------------------------
	SSL Instatnce Method
 -------------------------*/



#define TSSL_IsRecvCloseNotify(self)		((TSSL_StateFlag(self) & SLIM_SSL_ST_FLAG_RECV_CLOSE_NOTIFY) != 0)
#define TSSL_IsSendCloseNotify(self)		((TSSL_StateFlag(self) & SLIM_SSL_ST_FLAG_SEND_CLOSE_NOTIFY) != 0)

#define iTSSL_ConnFlag(isefl)		SLIM_SSL_FLAG((iself)->fFlag, SLIM_SSL_FLAG_CONN_MASK)
#define iTSSL_IsConnV2(iself) 		SLIM_SSL_CHECK_FLAG((iself)->fFlag, SLIM_SSL_FLAG_CONN_V2)
#define iTSSL_IsConnV3(iself) 		SLIM_SSL_CHECK_FLAG((iself)->fFlag, SLIM_SSL_FLAG_CONN_V3)
#define iTSSL_IsConnTLS(iself)		SLIM_SSL_CHECK_FLAG((iself)->fFlag, SLIM_SSL_FLAG_CONN_TLS)
#define iTSSL_IsConnV3TLS(iself)	(iTSSL_IsConnV3(iself) || iTSSL_IsConnTLS(iself))
#define iTSSL_IsConnV2V3TLS(iself)	(iTSSL_IsConnV2(iself) || iTSSL_IsConnV3(iself) || iTSSL_IsConnTLS(iself))
#define iTSSL_IsConnOnlyV2(iself)	(iTSSL_ConnFlag(iself) == SLIM_SSL_FLAG_CONN_V2)
#define iTSSL_IsConnOnlyV3(iself)	(iTSSL_ConnFlag(iself) == SLIM_SSL_FLAG_CONN_V3)
#define iTSSL_IsConnOnlyTLS(iself)	(iTSSL_ConnFlag(iself) == SLIM_SSL_FLAG_CONN_TLS)



/*==============
	SSL Debug
 ==============*/
#ifdef SLIM_CONFIG_SSL_DEBUG

/*--------------------------
	Set Debug Proc Method
 --------------------------*/

/*----------------------
	Debug Dump/Notify
 ----------------------*/


#define SLIM_SSL_DPW(ssl_class, args) \
{ \
	if ((ssl_class)->fDebugPrintfProc) { \
		(*(ssl_class)->fDebugPrintfProc) args ; \
	} \
}
#define SLIM_SSL_DP(ssl_class, args) \
{ \
	if ((ssl_class)->fDebugPrintfProc) { \
		(*(ssl_class)->fDebugPrintfProc) args ; \
		(*(ssl_class)->fDebugPrintfProc) ("\r\n"); \
	} \
}
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_NEW(ssl)							(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_NEW))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_DELETE(ssl)						(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_DELETE))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_STATE(ssl)						(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_STATE))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_VERSION(ssl)						(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_VERSION))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_CH_READ_CIPHER(ssl)				(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_CH_READ_CIPHER))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_CH_WRITE_CIPHER(ssl)				(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_CH_WRITE_CIPHER))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_READ_SEQNUM(ssl)					(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_READ_SEQNUM))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_WRITE_SEQNUM(ssl)				(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_WRITE_SEQNUM))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_TIMER_START(ssl)					(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_TIMER_START))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_TIMER_STOP(ssl)					(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_TIMER_STOP))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_TIMER_TIMEDOUT(ssl)				(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_TIMER_TIMEDOUT))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_SEND_REC(ssl)					(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_SEND_REC))
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_RECV_REC(ssl)					(iTSSL_Debug_Notify(ssl, SLIM_SSL_DEBUG_SOCKNTFY_RECV_REC))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_NEW(cache, pix)					(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_NEW))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_DELETE(cache, pix)				(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_DELETE))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_VERSION(cache, pix)				(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_VERSION))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_CIPHERSUITE(cache, pix)			(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_CIPHERSUITE))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_USE(cache, pix)					(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_USE))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_RESUMABLE(cache, pix)			(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_RESUMABLE))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_STAT(cache, pix)					(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_STAT))
#define SLIM_SSL_DEBUG_SESS_NOTIFY_CERT_VERIF_RESULT(cache, pix)	(TSSLSessionCache_Debug_Notify(cache, pix, SLIM_SSL_DEBUG_SESSNTFY_CERT_VERIF_RESULT))
#define SLIM_SSL_DEBUG_ALRT_NOTIFY_SEND(ssl)						(iTSSL_Debug_NotifyAlert(ssl))
#define SLIM_SSL_DEBUG_ALRT_NOTIFY_RECV(ssl)						(iTSSL_Debug_NotifyAlert(ssl))


#else /* !defined(SLIM_CONFIG_SSL_DEBUG) */
#define SLIM_SSL_DPW(ssl_class, args)								
#define SLIM_SSL_DP(ssl_class, args)								
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_NEW(ssl)							
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_DELETE(ssl)						
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_STATE(ssl)						
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_VERSION(ssl)						
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_CH_READ_CIPHER(ssl)				
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_CH_WRITE_CIPHER(ssl)				
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_READ_SEQNUM(ssl)					
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_WRITE_SEQNUM(ssl)				
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_TIMER_START(ssl)					
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_TIMER_STOP(ssl)					
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_TIMER_TIMEDOUT(ssl)				
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_SEND_REC(ssl)					
#define SLIM_SSL_DEBUG_SOCK_NOTIFY_RECV_REC(ssl)					
#define SLIM_SSL_DEBUG_SESS_NOTIFY_NEW(cache, pix)					
#define SLIM_SSL_DEBUG_SESS_NOTIFY_DELETE(cache, pix)				
#define SLIM_SSL_DEBUG_SESS_NOTIFY_VERSION(cache, pix)				
#define SLIM_SSL_DEBUG_SESS_NOTIFY_CIPHERSUITE(cache, pix)			
#define SLIM_SSL_DEBUG_SESS_NOTIFY_USE(cache, pix)					
#define SLIM_SSL_DEBUG_SESS_NOTIFY_RESUMABLE(cache, pix)			
#define SLIM_SSL_DEBUG_SESS_NOTIFY_STAT(cache, pix)					
#define SLIM_SSL_DEBUG_SESS_NOTIFY_CERT_VERIF_RESULT(cache, pix)	
#define SLIM_SSL_DEBUG_ALRT_NOTIFY_SEND(ssl)						
#define SLIM_SSL_DEBUG_ALRT_NOTIFY_RECV(ssl)						

#endif /* SLIM_CONFIG_SSL_DEBUG */


/* dummy functions */
#else /* !defined(SLIM_CONFIG_USE_SSL) */
#define SSL_SetCertListVerifyProc(in_class, in_proc, in_aux)			((void)0)
#define SSL_SetCurrentTimeProc(in_class, in_proc, in_aux)				((void)0)
#define SSL_SetDeleteCallback(in_class, in_proc, in_aux)				((void)0)
#define SSL_VersionFlag(ssl_class)										(0)
#define SSL_OptionFlag(ssl_class)										(0)
#define SSL_CertCheckFlag(in_class)										(0)
#define SSL_CertLimitLen(in_class)										(0)
#define SSL_CertCNMatchLen(in_class)									(0)
#define SSL_CertChainLimitLen(in_class)									(0)
#define SSL_TimeLimit(in_class, in_event)								(0)
#define SSL_CipherSuitePref(in_class, out_pref)							{slim_memset((out_pref), 0, sizeof(TSSLCipherSuitePref));}
#define SSL_LimitSessions(in_class)										(0)
#define SSL_SetVersionFlag(ssl_class, version, on)						((void)0)
#define SSL_SetCertCheckFlag(in_class, in_flag, in_on)					((void)0)
#define SSL_SetCertCNMatchLen(in_class, in_match_len)					((void)0)
#define SSL_SetLimitSessions(in_class, in_limit)						((void)0)
#define SSL_SetHandleStateProc(in_class, in_proc)						((void)0)
#ifdef SLIM_CONFIG_MULTITHREAD
#define SSL_SetMutex(in_class, in_mutex, in_sess_mutex, in_certdb_mutex)	((void)0)
#endif /* SLIM_CONFIG_MULTITHREAD */
#define TSSL_SetFlag(self, in_flag, in_on)							((void)0)
#define TSSL_GetFlag(self)											(0)
#define TSSL_StateFlag(self)										(0)
#define TSSL_MakeClientCertList(self)								(slim_nil)
#define TSSL_Lock(self)												(slim_nil)
#define TSSL_Unlock(self)											((void)0)
#define TSSL_Locate(self)											(slim_nil)
#define TSSL_Unlocate(self)											((void)0)
#define TSSL_IsRecvCloseNotify(self)								(slim_false)
#define TSSL_CheckKeepAlive(self)									(SLIM_E_GENERIC)
#define TSSLCipherSuite_AuthAlgo(suite)								((void)0)
#define TSSLCipherSuite_KyExAlgo(suite)								((void)0)
#define TSSLCipherSuite_CipherAlgo(suite)							((void)0)
#define TSSLCipherSuite_DigestAlgo(suite)							((void)0)
#define TSSLCipherSuite_ID(suite, index)							((void)0)
#ifdef SLIM_CONFIG_SSL_DEBUG
#define TSSLCipherSuite_Name(suite)									(SLIM_T(""))
#endif /* SLIM_CONFIG_SSL_DEBUG */

#endif /* SLIM_CONFIG_USE_SSL */

SLIM_END_C_LINKAGE

#endif /* SLIM_SSL_H_PRIVATE */
