/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_asn1.c */

#ifdef SLIM_CONFIG_USE_ASN1
TASN1OIDInfo * TASN1Object_ToOIDInfo(TASN1Object *self);
void TASN1Decoder_Initialize(TASN1Decoder *self);
void TASN1Decoder_Finalize(TASN1Decoder *self);
void TASN1Decoder_SetFlag(TASN1Decoder *self, slim_int in_flag, slim_bool in_set);
slim_int TASN1Decoder_Decode(TASN1Decoder *self, slim_int in_schema_id, slim_byte *in_buf, slim_int in_len, TASN1Object *out_object);
void TASN1Iterator_Initialize(TASN1Iterator *self, void *in_object);
slim_int TASN1Iterator_Next(TASN1Iterator *self, void *out_object);
void TASN1Iterator_Finalize(TASN1Iterator *self);
slim_int ASN1_DecodeObject(slim_int in_schema_id, slim_byte *in_buf, slim_int in_len, void *out_object);
void * ASN1_NewObject(slim_int in_schema_id, slim_byte *in_buf, slim_int in_len, slim_int *out_err);
void ASN1_DeleteObject(void *in_object);
#endif /* SLIM_CONFIG_USE_ASN1 */

/* slim_asn1_schema.c */

#ifdef SLIM_CONFIG_USE_ASN1
TASN1Schema * ASN1_GetSchemaByID(slim_int in_id);
slim_int ASN1_GetSchemaIDBySchema(TASN1Schema *in_schema);
#ifdef SLIM_CONFIG_ASN1_DEBUG
slim_char * ASN1_DebugName(slim_int in_offset);
#endif /* SLIM_CONFIG_ASN1_DEBUG */
#endif /* SLIM_CONFIG_USE_ASN1 */

/* slim_token_a1oid0.c */

#ifdef SLIM_CONFIG_USE_ASN1
TASN1OIDInfo * ASN1OIDInfo_CaseFindSS(slim_char *in_s, slim_int in_slen);
#endif /* SLIM_CONFIG_USE_ASN1 */

/* slim_cert.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int TCertDN_PeekName(TCertDN *self, TCertName *out_name);
slim_bool TCertDN_IsSameSS(TCertDN *self, slim_byte *in_str, slim_int in_len);
void TCert_BeginPeekSubjAltName(TCert *self, TCertPeekCookie *in_cookie, slim_int in_type);
slim_int TCert_PeekSubjAltName(TCert *self, TCertPeekCookie *in_cookie, slim_byte **out_str);
void TCert_EndPeekSubjAltName(TCert *self, TCertPeekCookie *in_cookie);
slim_int TCert_BeginPeekExtension(TCert *self, TCertPeekCookie *out_cookie, slim_int in_extn_id);
slim_int TCert_PeekExtension(TCert *self, TCertPeekCookie *inout_cookie, TX509Extension *out_extension);
void TCert_EndPeekExtension(TCert *self, TCertPeekCookie *inout_cookie);
slim_int TCert_Verify(TCert *self, TCert *in_issuer, slim_int in_flag);
slim_int TCert_Check(TCert *self, slim_int in_rec_flag, slim_int in_check_flags, slim_int in_depth, slim_char *in_name, slim_int in_match_len, slim_time *in_time, TCertDBManager *in_mgr);
slim_int TCertList_VerificationResults(TCertList self, slim_int in_index);
void TCertList_SetVerificationResults(TCertList self, slim_int in_index, slim_int in_results);
void TCertList_GetItem(TCertList self, slim_int in_index, TCertListItem *out_item);
void TCertList_SetItem(TCertList self, slim_int in_index, TCertListItem *in_item);
slim_int TCertList_Append(TCertList self, TCertListItem *in_item);
slim_int TCertList_AppendSS(TCertList self, slim_byte *in_der_cert, slim_int in_der_len, slim_int in_flag);
slim_int TCertList_Verify(TCertList self, slim_int in_check_flags, slim_char *in_server_name, slim_int in_match_len, slim_time *in_time, TCertDBManager *in_mgr);
slim_int TCertList_SerializeSize(TCertList self);
slim_handle TCertList_Serialize(TCertList self);
slim_bool TCertList_Deserialize(TCertList self, slim_handle in_handle);
slim_bool TCertList_ConstructChain(TCertList self, TRSAPrivateKey *in_prkey);
slim_bool TCertList_EqualServerCert(TCertList self, TCertList in_list);
TClientCertList ClientCertList_New(void);
slim_int TClientCertList_Append(TClientCertList self, TClientCertListItem *in_item);
void TClientCertList_VerifyAll(TClientCertList self, slim_int in_check_flags, slim_time *in_time, TCertDBManager *in_mgr);
void TClientCertList_SetCertPath(TClientCertList self, slim_int in_index, TCertList in_cert_path);
slim_int TClientCertList_SerializeSize(TClientCertList self);
slim_handle TClientCertList_Serialize(TClientCertList self);
slim_bool TClientCertList_Deserialize(TClientCertList self, slim_handle in_handle);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_cert_ber.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int TDER_EncodeLenOcts(slim_int in_len, slim_byte *out_der);
slim_int TDER_EncodeInt(slim_bool in_sign, slim_byte *in_data, slim_int in_len, slim_byte *out_der);
slim_int TDER_EncodeBitStr(slim_byte *in_data, slim_int in_bits, slim_byte *out_der);
slim_int TBER_DecodeRSAInt(slim_byte *in_ber, slim_int in_len, TRSAInt *out_rsa_int);
slim_int TBER_DecodeRSAPublicKey(slim_byte *in_ber, slim_int in_len, TRSAPublicKey *out_public);
slim_int TBER_DecodeNameAttrVal(slim_byte *in_ber, slim_int in_len, TCertName *out_name);
slim_int TBER_DecodeLength(slim_byte *in_octet, slim_int in_len, slim_int *out_len);
slim_int TBER_DecodeRSAPrivateKey(slim_byte *in_ber, slim_int in_len, TRSAPrivateKey *out_private);
slim_int TBER_DecodeCert(slim_byte *in_ber, slim_int in_len, TCert *out_cert);
slim_int TBER_DecodeRevokedCert(slim_byte *in_der, slim_int in_len, TCRL *in_crl, TCertSerNo *out_ser_no, slim_time *out_time);
slim_int TBER_DecodeCRL(slim_byte *in_der, slim_int in_len, TCRL *out_crl);
slim_int TBER_DecodeGN(slim_byte *in_ber, slim_int in_len, TCertGN *out_gn);
slim_int TBER_DecodeDigestInfo(slim_byte *in_ber, slim_int in_len, slim_int *out_algo, slim_byte **out_digest, slim_int *out_digest_len);
slim_int TDER_EncodeRSAPrivateKey(TRSAPrivateKey *in_private, slim_byte *out_der);
slim_int TDER_EncodeRSAPublicKey(TRSAPublicKey *in_public, slim_byte *out_der);
slim_int TDER_EncodeSignAlgo(slim_int in_algo, slim_byte *out_der);
slim_int TDER_EncodeRSAPublicKeyInfo(slim_int in_algo, TRSAPublicKey *in_public, slim_byte *out_der);
slim_int TDER_EncodeName(TCertName *in_names, slim_int in_num, slim_byte *out_der);
slim_int TDER_EncodeDigestInfo(slim_int in_algo, slim_byte *in_data, slim_int in_len, slim_byte *out_der);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_cert_db.c */

#ifdef SLIM_CONFIG_USE_SSL
void TCertDB_Initialize(TCertDB *self);
void TCertDB_Finalize(TCertDB *self);
slim_int TCertDB_RegisterStore(TCertDB *self, slim_int in_type, TCertStore *in_store);
#ifdef SLIM_CONFIG_MULTITHREAD
void TCertDB_SetMutex(TCertDB *self, slim_opaque in_mutex);
#endif /* SLIM_CONFIG_MULTITHREAD */
void TCertDBManager_Initialize(TCertDBManager *self, TCertDB *in_db);
void TCertDBManager_Finalize(TCertDBManager *self);
slim_int TCertDBManager_OpenDB(TCertDBManager *self, slim_int in_mode);
void TCertDBManager_CloseDB(TCertDBManager *self);
slim_int TCertDBManager_VerifyCert(TCertDBManager *self, TCert *in_cert, slim_int in_rec_flag, slim_int in_check_flag, slim_time *in_time, slim_int *out_root_store_type, slim_opaque *out_root_id);
slim_int TCertDBManager_VerifyCertList(TCertDBManager *self, TCertList in_list, slim_int in_check_flags, slim_char *in_server_name, slim_int in_match_len, slim_time *in_time);
slim_int TCertDBManager_VerifyCRL(TCertDBManager *self, TCRL *in_crl, slim_time *in_time);
slim_int TCertDBManager_CheckRevocation(TCertDBManager *self, TCert *in_cert, slim_int in_rec_flag, slim_time *out_time);
slim_int TCertDBManager_EnumerateItem(TCertDBManager *self, TCertFindInfo *in_info, TCertStoreEnumerateItemProc in_proc, slim_opaque in_aux);
slim_int TCertDBManager_MakeCertList(TCertDBManager *self, slim_int in_from, slim_bool in_ref, TCertList *out_list);
slim_int TCertDBManager_MakeClientCertList(TCertDBManager *self, TClientCertList *out_list);
slim_int TCertDBManager_Rename(TCertDBManager *self, slim_int in_store_type, slim_opaque in_id, slim_byte *in_name, slim_int in_name_len);
slim_int TCertDBManager_SetRecFlag(TCertDBManager *self, slim_int in_store_type, slim_opaque in_id, slim_int in_flag, slim_bool in_set);
slim_int TCertDBManager_Import(TCertDBManager *self, TCertListImportInfo *in_info, slim_bool in_ow, slim_opaque *out_id, slim_int *out_old_store_type, slim_opaque *out_old_id);
slim_int TCertDBManager_Remove(TCertDBManager *self, slim_int in_store_type, slim_opaque in_id);
slim_int TCertDBManager_Find(TCertDBManager *self, TCertFindInfo *in_info, slim_int *out_store_type, slim_opaque *out_id);
slim_int TCertDBManager_OpenItem(TCertDBManager *self, slim_int in_store_type, slim_opaque in_id, TCertStoreItem *out_item);
void TCertDBManager_CloseItem(TCertDBManager *self, slim_int in_store_type, slim_opaque in_id, TCertStoreItem *in_item);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_cert_memdbs.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_bool TMemCertStore_Initialize(TMemCertStore *self, slim_int in_max_items);
void TMemCertStore_Finalize(TMemCertStore *self);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_cert_romdbs.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_bool TRomCertStore_Initialize(TRomCertStore *self, slim_int in_max_items);
void TRomCertStore_Finalize(TRomCertStore *self);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_crl.c */

#ifdef SLIM_CONFIG_USE_SSL
TCRL * CRL_New(void);
void TCRL_Delete(TCRL *self);
slim_int TCRL_PeekIssuerRDN(TCRL *self, slim_int in_attr, slim_int *inout_offset, slim_byte **out_str);
slim_int TCRL_Verify(TCRL *self, TCert *in_cert, slim_time *in_time);
slim_int TCRL_Decode(TCRL *self, slim_byte *in_der, slim_int in_len);
slim_bool TCRL_IsCertRevoked(TCRL *self, TCertSerNo *in_ser_no, slim_time *out_time);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_pkcs.c */

#if (defined(SLIM_CONFIG_USE_PKCS7) || defined(SLIM_CONFIG_USE_PKCS12))
TPxImportMgr * PxImportMgr_New(slim_int in_type);
void TPxImportMgr_Delete(TPxImportMgr *self);
void TPxImportMgr_SetCertList(TPxImportMgr *self, TCertList in_list);
void TPxImportMgr_SetPrivateKey(TPxImportMgr *self, slim_byte *in_prkey, slim_int in_prkey_len);
void TPxImportMgr_Confirm(TPxImportMgr *self, slim_bool in_confirm);
slim_bool TPxImportMgr_SetPassword(TPxImportMgr *self, slim_char *in_pass, slim_int in_len);
slim_bool TPxImportMgr_Start(TPxImportMgr *self, slim_byte *in_content, slim_int in_content_len);
void TPxImportMgr_End(TPxImportMgr *self);
slim_int TPxImportMgr_Progress(TPxImportMgr *self);
#endif /* defined(SLIM_CONFIG_USE_PKCS7) || defined(SLIM_CONFIG_USE_PKCS12) */

/* slim_pkcs10.c */

#ifdef SLIM_PKCS10_H_PRIVATE
slim_int slim_p10_encode_cert_req_info(TCertName *in_names, slim_int in_num, slim_int in_algo, TRSAPublicKey *in_public, TP10EncodeAttributesProc in_proc, void *in_arg, slim_byte *out_der);
slim_int slim_p10_encode_cert_req(slim_byte *in_info, slim_int in_info_len, slim_int in_algo, slim_byte *in_sign, slim_int in_sign_len, slim_byte *out_der);
slim_int slim_p10_make_cert_req(TCertName *in_names, slim_int in_num, slim_int in_algo, TRSAPrivateKey *in_private, TP10EncodeAttributesProc in_proc, void *in_arg, slim_byte **out_cert_req);
#endif /* SLIM_PKCS10_H */

/* slim_pkcs12.c */


/* slim_pkcs5.c */

#ifdef SLIM_CONFIG_USE_PKCS5
slim_int slim_p5_pbes1(TPBESParams *in_params, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
slim_int slim_p5_pbes2(void);
TPBESInfo * slim_pbes_lookup_info(slim_int in_algo);
slim_int slim_pbes_set_params(TPBESInfo *in_info, slim_bool in_encryption, slim_byte *in_passwd, slim_int in_passwd_len, slim_byte *in_salt, slim_int in_salt_len, slim_int in_iter, TPBESParams *out_params);
slim_int slim_pbes_update(TPBESParams *in_params, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
slim_int slim_p5_pbmac1(void);
#ifdef SLIM_CONFIG_USE_PKCS12
slim_int slim_pbmac_p12_generate(slim_int in_algo, slim_byte *in_password, slim_int in_password_len, slim_byte *in_salt, slim_int in_salt_len, slim_int in_iter, slim_byte *in_msg, slim_int in_len, slim_byte *out_mac);
#endif
#endif /* SLIM_CONFIG_USE_PKCS5 */

/* slim_pkcs7.c */

#ifdef SLIM_CONFIG_USE_PKCS7
slim_int TP7ContentInfo_OpenContent(TP7ContentInfo *self, TP7KeyInfo *in_key_info, slim_byte **out_content, slim_int *out_content_len);
void TP7ContentInfo_CloseContent(TP7ContentInfo *self, slim_byte *in_content, slim_int in_content_len);
#endif /* SLIM_CONFIG_USE_PKCS7 */

/* slim_ssl.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int iTSSL_HandleState(iTSSL *iself);
slim_int TSSLSessionCache_LimitSessions(TSSLSessionCache *self);
void TSSLSessionCache_SetLimitSessions(TSSLSessionCache *self, slim_int in_limit);
#ifdef SLIM_CONFIG_SSL_DEBUG
void TSSLSessionCache_IncStatRefCnt(TSSLSessionCache *self, TString in_name, slim_int in_port);
void TSSLSessionCache_IncStatHitCnt(TSSLSessionCache *self, TString in_name, slim_int in_port);
#endif /* SLIM_CONFIG_SSL_DEBUG */
void SSL_SetCertListVerifyProc(TSSLClass *in_class, TSSLCertListVerifyProc in_proc, slim_opaque in_aux);
void SSL_SetCurrentTimeProc(TSSLClass *in_class, TSSLCurrentTimeProc in_time_proc, slim_opaque in_aux);
void SSL_SetDeleteCallback(TSSLClass *in_class, TSSLDeleteCallback in_callback, slim_opaque in_aux);
slim_int SSL_Flag(TSSLClass *in_class, slim_int in_mask);
slim_int SSL_CertCheckFlag(TSSLClass *in_class);
void SSL_SetCertCheckFlag(TSSLClass *in_class, slim_int in_flag, slim_bool in_on);
slim_int SSL_CertCNMatchLen(TSSLClass *in_class);
void SSL_SetCertCNMatchLen(TSSLClass *in_class, slim_int in_match_len);
slim_int SSL_CertChainLimitLen(TSSLClass *in_class);
slim_int SSL_TimeLimit(TSSLClass *in_class, slim_int in_event);
void SSL_CipherSuitePref(TSSLClass *in_class, TSSLCipherSuitePref *out_pref);
slim_int SSL_CertLimitLen(TSSLClass *in_class);
slim_int SSL_LimitSessions(TSSLClass *in_class);
void SSL_SetLimitSessions(TSSLClass *in_class, slim_int in_limit);
void SSL_SetHandleStateProc(TSSLClass *in_class, TSSLStateProc in_proc);
iTSSL * TSSL_Lock(TSSL self);
void TSSL_Unlock(TSSL self);
iTSSL * TSSL_Locate(TSSL self);
void TSSL_Unlocate(TSSL self);
void TSSL_SetFlag(TSSL self, slim_int in_flag, slim_bool in_on);
slim_int TSSL_GetFlag(TSSL self);
slim_int TSSL_StateFlag(TSSL self);
void iTSSL_ClearSession(iTSSL *iself);
slim_int iTSSL_LoadSession(iTSSL *iself);
slim_int iTSSL_SaveSession(iTSSL *iself);
void iTSSL_DeleteSession(iTSSL *iself);
slim_int iTSSL_VerifyCertList(iTSSL *iself, TCertList in_list);
slim_int iTSSL_EncryptByPrivateKey(iTSSL *iself, TCertList in_list, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf, slim_word *out_len);
void iTSSL_InitializeCipherContext(iTSSL *iself, TSSLCipherContext in_ctx, TSSLSecParams *in_params, slim_bool in_write);
void iTSSL_FinalizeCipherContext(iTSSL *iself, TSSLCipherContext in_ctx, TSSLSecParams *in_params);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_cipher.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int TSSLCipherAlgo_CalcPadLen(TSSLCipherAlgo self, slim_int in_len);
slim_int TSSLCipherSuitePref_PackV2(TSSLCipherSuitePref *self, slim_byte *out_buf);
slim_int TSSLCipherSuitePref_PackV3(TSSLCipherSuitePref *self, slim_bool in_v3, slim_byte *out_buf);
TSSLCipherSuite TSSLCipherSuitePref_FindV2(TSSLCipherSuitePref *self, slim_byte *in_id);
TSSLCipherSuite TSSLCipherSuitePref_FindV3(TSSLCipherSuitePref *self, slim_byte *in_id);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_client.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int iTSSL_SelectVersion(iTSSL *iself);
slim_int iTSSL_SelectHelloFormat(iTSSL *iself);
slim_int iTSSL_Done(iTSSL *iself);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_client2.c */

#ifdef SLIM_CONFIG_USE_SSL
#ifndef SLIM_CONFIG_SSL_V2_SUPPORT
#else /* SLIM_CONFIG_SSL_V2_SUPPORT */
slim_int iTSSL2_ClientHello_Pack(iTSSL *iself);
slim_int iTSSL2_ClientHello_Send(iTSSL *iself);
slim_int iTSSL2_ServerHello_Receive(iTSSL *iself);
slim_int iTSSL2_ServerHello_Unpack(iTSSL *iself);
slim_int iTSSL2_ClientMasterKey_Pack(iTSSL *iself);
slim_int iTSSL2_ClientMasterKey_Send(iTSSL *iself);
slim_int iTSSL2_GenerateKey(iTSSL *iself);
slim_int iTSSL2_ClientFinish_Pack(iTSSL *iself);
slim_int iTSSL2_ClientFinish_Send(iTSSL *iself);
slim_int iTSSL2_ServerVerify_Receive(iTSSL *iself);
slim_int iTSSL2_ServerVerify_Unpack(iTSSL *iself);
slim_int iTSSL2_ServerResponse_Receive(iTSSL *iself);
slim_int iTSSL2_RequestCertificate_Unpack(iTSSL *iself);
slim_int iTSSL2_ServerFinish_Unpack(iTSSL *iself);
slim_int iTSSL2_ClientCertificate_Select(iTSSL *iself);
slim_int iTSSL2_ClientCertificate_Pack(iTSSL* iself);
slim_int iTSSL2_ClientCertificate_Send(iTSSL* iself);
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_client3.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int iTSSL3_ClientHello_Pack(iTSSL *iself);
slim_int iTSSL3_ClientHello_Send(iTSSL *iself);
#ifdef SLIM_CONFIG_SSL_V2_SUPPORT
slim_int iTSSL3_V2ClientHello_Pack(iTSSL *iself);
slim_int iTSSL3_V2ClientHello_Send(iTSSL *iself);
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
slim_int iTSSL3_ServerHello_Receive(iTSSL *iself);
slim_int iTSSL3_ServerHello_Unpack(iTSSL *iself);
slim_int iTSSL3_ServerCertificate_Receive(iTSSL *iself);
slim_int iTSSL3_ServerCertificate_Unpack(iTSSL *iself);
slim_int iTSSL3_ServerResponse_Receive(iTSSL *iself);
slim_int iTSSL3_ServerKeyExchange_Unpack(iTSSL *iself);
slim_int iTSSL3_CertificateRequest_Unpack(iTSSL *iself);
slim_int iTSSL3_ClientCertificate_Select(iTSSL *iself);
slim_int iTSSL3_ClientCertificate_Pack(iTSSL *iself);
slim_int iTSSL3_ClientCertificate_Send(iTSSL *iself);
slim_int iTSSL3_ClientKeyExchange_PMS(iTSSL *iself);
slim_int iTSSL3_ClientKeyExchange_Pack(iTSSL *iself);
slim_int iTSSL3_ClientKeyExchange_Send(iTSSL *iself);
slim_int iTSSL3_GenerateKey(iTSSL *iself);
slim_int iTSSL3_CertificateVerify_Pack(iTSSL *iself);
slim_int iTSSL3_CertificateVerify_Send(iTSSL *iself);
slim_int iTSSL3_ChCipherSpec_Send(iTSSL *iself);
slim_int iTSSL3_ClientFinished_Pack(iTSSL *iself);
slim_int iTSSL3_ClientFinished_Send(iTSSL *iself);
slim_int iTSSL3_ChCipherSpec_Receive(iTSSL *iself);
slim_int iTSSL3_ServerFinished_Receive(iTSSL *iself);
slim_int iTSSL3_ServerFinished_Unpack(iTSSL *iself);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_debug.c */

#ifdef SLIM_CONFIG_USE_SSL
#ifndef SLIM_CONFIG_SSL_DEBUG
#else /* defined(SLIM_CONFIG_SSL_DEBUG) */
void iTSSL_Debug_Notify(iTSSL *iself, slim_int in_type);
void TSSLSessionCache_Debug_Notify(TSSLSessionCache *self, slim_pix in_pix, slim_int in_type);
void iTSSL_Debug_NotifyAlert(iTSSL *iself);
#endif /* SLIM_CONFIG_SSL_DEBUG */
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_message2.c */

#ifdef SLIM_CONFIG_USE_SSL
#ifndef SLIM_CONFIG_SSL_V2_SUPPORT
#else /* SLIM_CONFIG_SSL_V2_SUPPORT */
slim_int iTSSL2_RecvHandshake(iTSSL *iself);
slim_int iTSSL2_SendHandshake(iTSSL *iself);
slim_int iTSSL2_Alert_Set(iTSSL *iself, TSSLAlertDescription in_error_no, slim_int in_alert_ecode);
slim_int iTSSL2_Alert_Pack(iTSSL *iself);
slim_int iTSSL2_Alert_Send(iTSSL *iself);
void iTSSL2_ChangeCipherSpec(iTSSL *iself);
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_message3.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int iTSSL3_RecvHandshake(iTSSL *self);
slim_int iTSSL3_SendHandshake(iTSSL *self, slim_bool in_pending);
slim_int iTSSL3_Alert_Set(iTSSL *self, TSSLAlertDescription in_alert_description, slim_int in_alert_ecode);
slim_int iTSSL3_Alert_Pack(iTSSL *self);
slim_int iTSSL3_Alert_Send(iTSSL *self);
slim_int iTSSL3_SendChangeCipherSpec(iTSSL *self);
void iTSSL3_ChangeReadCipherSpec(iTSSL *self);
void iTSSL3_ChangeWriteCipherSpec(iTSSL *self);
void iTSSL3_HashHandshakeMessage(iTSSL *self, slim_byte *in_msg, slim_int in_len);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_packet.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int iTSSL_SendPacket(iTSSL *self, slim_byte *in_data, slim_int in_size);
slim_int iTSSL_RecvPacket(iTSSL *self, slim_byte *out_data, slim_int in_size);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_record2.c */

#ifdef SLIM_CONFIG_USE_SSL
#ifndef SLIM_CONFIG_SSL_V2_SUPPORT
#else /* SLIM_CONFIG_SSL_V2_SUPPORT */
void TSSLv2MAC_Initialize(TSSLv2MAC *self, slim_int in_algo, slim_byte *in_key, slim_word in_len);
void TSSLv2MAC_Finalize(TSSLv2MAC *self);
slim_int iTSSL2_Send(iTSSL *iself);
slim_int iTSSL2_Recv(iTSSL *iself);
#endif /* SLIM_CONFIG_SSL_V2_SUPPORT */
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_record3.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int iTSSL3_Send(iTSSL *iself, slim_bool in_pending);
slim_int iTSSL3_Recv(iTSSL *iself);
void TSSLv3MAC_Initialize(TSSLv3MAC *self, slim_int in_algo, slim_byte *in_key, slim_word in_len);
void TSSLv3MAC_Finalize(TSSLv3MAC *self);
void TSSLCipherContext_EncryptDecrypt(TSSLCipherContext self, slim_byte *inout_buf, slim_int in_len);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_rw.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_int TSSL_CheckKeepAlive(TSSL self);
#endif /* SLIM_CONFIG_USE_SSL */

/* slim_ssl_tls.c */

#ifdef SLIM_CONFIG_USE_SSL
slim_bool slim_tls1_prf(slim_byte *in_key, slim_int in_klen, slim_byte *in_label, slim_int in_llen, slim_byte *in_seed, slim_int in_slen, slim_int in_req_len, slim_byte *out_result);
slim_bool slim_tls1_digest(TMD *in_md5, TMD *in_sha, slim_char *in_label, slim_byte *in_ms, slim_byte *out_digest);
slim_bool iTTLS_GenerateKeys(iTSSL *self);
slim_int iTTLS_Alert_Set(iTSSL *self, TSSLAlertDescription in_alert_description, slim_int in_alert_ecode);
#endif /* SLIM_CONFIG_USE_SSL */
