/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_asn1.c */

#ifdef SLIM_CONFIG_USE_ASN1
SLIM_API slim_int TASN1Object_EntityLen(void *self);
SLIM_API slim_byte * TASN1Object_EntityEnd(void *self);
SLIM_API slim_bool TASN1Object_ToBool(TASN1Object *self);
SLIM_API slim_int TASN1Object_ToInt(TASN1Object *self);
SLIM_API slim_int TASN1Object_ToOIDInfoID(TASN1Object *self);
SLIM_API slim_bool TASN1Object_ToTime(TASN1Object *self, slim_time *out_time);
SLIM_API slim_bool TASN1Object_CheckBit(TASN1Object *self, slim_int in_bit);
#endif /* SLIM_CONFIG_USE_ASN1 */

/* slim_asn1_schema.c */


/* slim_token_a1oid0.c */


/* slim_cert.c */

#ifdef SLIM_CONFIG_USE_SSL
SLIM_API slim_bool TCertDN_BeginPeekRDN(TCertDN *self, slim_int in_attr);
SLIM_API slim_int TCertDN_PeekRDN(TCertDN *self, slim_char **out_str);
SLIM_API void TCertDN_EndPeekRDN(TCertDN *self);
SLIM_API TCert * Cert_NewX(slim_bool in_alloc_store_item);
SLIM_API void TCert_Delete(TCert *self);
SLIM_API slim_int TCert_Decode(TCert *self, slim_byte *in_der, slim_int in_len);
SLIM_API slim_int TCert_PeekSerialNumber(TCert *self, slim_char **out_str);
SLIM_API TCertList CertList_New(slim_int in_type);
SLIM_API TCertList TCertList_Clone(TCertList self);
SLIM_API void TCertList_Delete(TCertList self);
SLIM_API slim_int TCertList_Length(TCertList self);
SLIM_API slim_int TCertList_Type(TCertList self);
SLIM_API slim_int TCertList_Flag(TCertList self, slim_int in_index);
SLIM_API slim_int TCertList_RecFlag(TCertList self, slim_int in_index);
SLIM_API void TCertList_SetRecFlag(TCertList self, slim_int in_index, slim_int in_flag, slim_bool in_on);
SLIM_API slim_int TCertList_BeginDecode(TCertList self, slim_int in_index, TCert **out_cert);
SLIM_API void TCertList_EndDecode(TCertList self, TCert *in_cert);
SLIM_API slim_int TCertList_Find(TCertList self, TCertListFindInfo *in_info);
SLIM_API slim_int TCertList_ImportCert(TCertList self, TCertListImportInfo *in_info, slim_bool in_over_write);
SLIM_API slim_int TCertList_ImportCRL(TCertList self, TCertListImportInfo *in_info, slim_bool in_over_write);
SLIM_API slim_bool TCertList_Remove(TCertList self, slim_int in_index);
SLIM_API slim_int TCertList_MakeCertName(TCertList self, slim_int in_index, TString *out_name);
SLIM_API TClientCertList TClientCertList_Clone(TClientCertList self);
SLIM_API void TClientCertList_Delete(TClientCertList self);
SLIM_API slim_int TClientCertList_Length(TClientCertList self);
SLIM_API slim_int TClientCertList_VerificationResults(TClientCertList self, slim_int in_index);
SLIM_API TCertList TClientCertList_CertPath(TClientCertList self, slim_int in_index);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_cert_ber.c */


/* slim_cert_db.c */

#ifdef SLIM_CONFIG_USE_SSL
SLIM_API slim_bool TCertFindInfo_MatchByItem(TCertFindInfo *self, TCertStoreItem *in_item);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_cert_memdbs.c */


/* slim_cert_romdbs.c */


/* slim_crl.c */


/* slim_pkcs.c */


/* slim_pkcs10.c */


/* slim_pkcs12.c */

#ifdef SLIM_CONFIG_USE_PKCS12
SLIM_API void TP12PFX_Initialize(TP12PFX *self);
SLIM_API void TP12PFX_Finalize(TP12PFX *self);
SLIM_API slim_int TP12PFX_Decode(TP12PFX *self, slim_byte *in_buf, slim_int in_len);
SLIM_API slim_int TP12PFX_IntegrityMode(TP12PFX *self);
SLIM_API slim_int TP12PFX_Authenticate(TP12PFX *self, TP12AuthSafe *in_auth_safe, slim_byte *in_password, slim_int in_password_len);
SLIM_API slim_int TP12PFX_DecodeAuthSafe(TP12PFX *self, TP12AuthSafe *out_auth_safe);
SLIM_API void TP12AuthSafe_Initialize(TP12AuthSafe *self);
SLIM_API void TP12AuthSafe_Finalize(TP12AuthSafe *self);
SLIM_API void TP12AuthSafeIterator_Initialize(TP12AuthSafeIterator *self, TP12AuthSafe *in_auth_safe);
SLIM_API void TP12AuthSafeIterator_Finalize(TP12AuthSafeIterator *self);
SLIM_API slim_int TP12AuthSafeIterator_OpenSafeContents(TP12AuthSafeIterator *self, TP7KeyInfo *in_key_info, TP12SafeContents *out_safe_contents);
SLIM_API void TP12AuthSafeIterator_CloseSafeContents(TP12AuthSafeIterator *self);
SLIM_API slim_int TP12SafeBag_BagId(TP12SafeBag *self);
SLIM_API slim_int TP12SafeBag_OpenBagValue(TP12SafeBag *self, TPKCSKeyInfo *in_key_info, slim_byte **out_value, slim_int *out_value_len, slim_int *out_value_type);
SLIM_API void TP12SafeBag_CloseBagValue(TP12SafeBag *self, slim_byte *in_value, slim_int in_value_len);
#endif /* SLIM_CONFIG_USE_PKCS12 */

/* slim_pkcs5.c */


/* slim_pkcs7.c */

#ifdef SLIM_CONFIG_USE_PKCS7
SLIM_API void TP7ContentInfo_Initialize(TP7ContentInfo *self);
SLIM_API void TP7ContentInfo_Finalize(TP7ContentInfo *self);
SLIM_API slim_int TP7ContentInfo_Decode(TP7ContentInfo *self, slim_byte *in_buf, slim_int in_len);
SLIM_API slim_int TP7ContentInfo_ContentType(TP7ContentInfo *self);
SLIM_API slim_int TP7ContentInfo_DecodeContent(TP7ContentInfo *self, void *out_object);
#endif /* SLIM_CONFIG_USE_PKCS7 */

/* slim_ssl.c */

#ifdef SLIM_CONFIG_USE_SSL
SLIM_API slim_bool SSL_Initialize(TSSLClass *in_class, slim_int in_random_seed);
SLIM_API void SSL_Finalize(TSSLClass* in_class);
SLIM_API slim_int SSL_OpenCertDB(TSSLClass *in_class, TCertList *out_list);
SLIM_API void SSL_CloseCertDB(TSSLClass *in_class, TCertList in_list);
SLIM_API void SSL_SetServerCertConfirmProc(TSSLClass *in_class, TSSLServerCertConfirmProc in_confirm_proc, slim_opaque in_aux);
SLIM_API void SSL_SetClientCertSelectProc(TSSLClass *in_class, TSSLClientCertSelectProc in_select_proc, slim_opaque in_aux);
SLIM_API void SSL_SetPrivateKeyEncryptProc(TSSLClass *in_class, TSSLPrivateKeyEncryptProc in_proc, slim_opaque in_aux);
SLIM_API void SSL_SetNotifyStateProc(TSSLClass *in_class, TSSLNotifyStateProc in_proc, slim_opaque in_aux);
SLIM_API slim_int SSL_Timeout(TSSLClass *in_class);
SLIM_API void SSL_SetFlag(TSSLClass *in_class, slim_int in_flag, slim_bool in_on);
SLIM_API void SSL_SetCertChainLimitLen(TSSLClass *in_class, slim_int in_len);
SLIM_API void SSL_SetTimeLimit(TSSLClass *in_class, slim_int in_event, slim_int in_limit);
SLIM_API void SSL_SetCipherSuitePref(TSSLClass *in_class, TSSLCipherSuitePref *in_pref);
SLIM_API void SSL_SetCertLimitLen(TSSLClass *in_class, slim_int in_limit);
SLIM_API void SSL_ClearSessionCache(TSSLClass *in_class);
SLIM_API slim_int SSL_RegisterSessionDB(TSSLClass *in_class, TSSLSessionDB *in_db, TSSLSessionDB *out_old);
SLIM_API slim_int SSL_RegisterCertStore(TSSLClass *in_class, TCertStore *in_store);
SLIM_API TSSL SSL_New(TSSLClass *in_class, slim_int in_ssl_flag, slim_char *in_server_name, slim_int in_server_port);
#ifdef SLIM_CONFIG_MULTITHREAD
SLIM_API void SSL_SetMutex(TSSLClass *in_class, slim_opaque in_mutex, slim_opaque in_cache_mutex, slim_opaque in_certdb_mutex);
#endif /* SLIM_CONFIG_MULTITHREAD */
#ifdef SLIM_CONFIG_SSL_DEBUG
SLIM_API void SSL_SetDebugProc(TSSLClass *in_class, void (*in_printf_proc)(char *in_format, ...), void (*in_sock_notify_proc)(TSSLDebugSockNotify *in_notify), void (*in_sess_notify_proc)(TSSLDebugSessNotify *in_notify), void (*in_alrt_notify_proc)(TSSLDebugAlrtNotify *in_notify));
#endif /* SLIM_CONFIG_SSL_DEBUG */
SLIM_API void TSSL_Delete(TSSL self);
SLIM_API void TSSL_SetFd(TSSL self, slim_int in_fd);
SLIM_API slim_int TSSL_State(TSSL self);
SLIM_API slim_bool TSSL_Alert(TSSL self, TSSLAlert *out_alert);
SLIM_API void TSSL_Version(TSSL self, TSSLVersion *out_version);
SLIM_API void TSSL_CipherSuite(TSSL self, TSSLCipherSuite *out_suite);
SLIM_API void TSSL_SetServerCertConfirmProc(TSSL self, TSSLServerCertConfirmProc in_proc, slim_opaque in_aux);
SLIM_API void TSSL_SetClientCertSelectProc(TSSL self, TSSLClientCertSelectProc in_proc, slim_opaque in_aux);
SLIM_API void TSSL_SetPrivateKeyEncryptProc(TSSL self, TSSLPrivateKeyEncryptProc in_proc, slim_opaque in_aux);
SLIM_API void TSSL_SetCurrentTimeProc(TSSL self, TSSLCurrentTimeProc in_proc, slim_opaque in_aux);
SLIM_API slim_int TSSL_Connect(TSSL self);
SLIM_API slim_int TSSL_ConnectProgress(TSSL self);
SLIM_API void TSSL_ServerCertConfirm(TSSL self, slim_int in_verify_result, slim_bool in_confirm);
SLIM_API void TSSL_ClientCertSelect(TSSL self, slim_int in_index);
SLIM_API void TSSL_PrivateKeyEncrypt(TSSL self, slim_byte *in_buf, slim_int in_len, slim_int in_result);
SLIM_API TCertList TSSL_MakeServerCertList(TSSL self);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_cipher.c */


/* slim_ssl_client.c */


/* slim_ssl_client2.c */


/* slim_ssl_client3.c */


/* slim_ssl_debug.c */


/* slim_ssl_message2.c */


/* slim_ssl_message3.c */


/* slim_ssl_packet.c */


/* slim_ssl_record2.c */


/* slim_ssl_record3.c */


/* slim_ssl_rw.c */

#ifdef SLIM_CONFIG_USE_SSL
SLIM_API slim_int TSSL_Write(TSSL self, slim_byte *in_buf, slim_int in_len);
SLIM_API slim_int TSSL_Read(TSSL self, slim_byte *out_buf, slim_int in_len);
SLIM_API slim_bool TSSL_IsAlive(TSSL self);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_tls.c */

