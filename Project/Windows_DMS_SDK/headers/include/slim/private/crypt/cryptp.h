/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_crypt_aes.c */

#ifdef SLIM_CONFIG_CRYPT_USE_AES
void TAES_SetKey(TAES *self, slim_byte *in_key, slim_int in_len);
void TAES_Encrypt(TAES *self, slim_byte *in_blk, slim_byte *out_blk);
void TAES_Decrypt(TAES *self, slim_byte *in_blk, slim_byte *out_blk);
#endif /* SLIM_CONFIG_CRYPT_USE_AES */

/* slim_crypt_des.c */

#ifdef SLIM_CONFIG_CRYPT_USE_DES
void TDES_SetKey(TDES *self, slim_byte *in_key, slim_int in_len);
void TDES_Encrypt(TDES *self, slim_byte *in_blk, slim_byte *out_blk);
void TDES_Decrypt(TDES *self, slim_byte *in_blk, slim_byte *out_blk);
#endif /* SLIM_CONIFG_CRYPT_USE_DES */
#ifdef SLIM_CONFIG_CRYPT_USE_2KEYDES3
void T2KeyDES3_SetKey(T2KeyDES3 *self, slim_byte *in_key, slim_int in_len);
void T2KeyDES3_Encrypt(T2KeyDES3 *self, slim_byte *in_blk, slim_byte *out_blk);
void T2KeyDES3_Decrypt(T2KeyDES3 *self, slim_byte *in_blk, slim_byte *out_blk);
#endif /* SLIM_CONFIG_CRYPT_USE_2KEYDES3 */
#ifdef SLIM_CONFIG_CRYPT_USE_DES3
void TDES3_SetKey(TDES3 *self, slim_byte *in_key, slim_int in_len);
void TDES3_Encrypt(TDES3 *self, slim_byte *in_blk, slim_byte *out_blk);
void TDES3_Decrypt(TDES3 *self, slim_byte *in_blk, slim_byte *out_blk);
#endif /* SLIM_CONFIG_CRYPT_USE_DES3 */

/* slim_crypt_digest.c */

#ifdef SLIM_CONFIG_CRYPT_USE_MD
#ifdef SLIM_CONFIG_CRYPT_USE_HMAC
slim_bool TCryptHMAC_Initialize(TCryptHMAC *self, slim_int in_algo, slim_byte *in_key, slim_word in_len);
void TCryptHMAC_BeginCtx(TCryptHMAC *self);
void TCryptHMAC_UpdateCtx(TCryptHMAC *self, slim_byte *in_data, slim_word in_size);
void TCryptHMAC_EndCtx(TCryptHMAC *self, slim_byte *out_mac);
void TCryptHMAC_Generate(TCryptHMAC *self, slim_byte *in_data, slim_word in_size, slim_byte *out_mac);
void TCryptHMAC_Finalize(TCryptHMAC *self);
#endif /* SLIM_CONFIG_CRYPT_USE_HMAC */
#endif /* SLIM_CONFIG_CRYPT_USE_MD */

/* slim_crypt_ecc.c */

#ifdef SLIM_CONFIG_CRYPT_USE_ECC
void TECInt_Initialize(TECInt *self);
slim_bool TECInt_Set(TECInt *self, slim_byte *in_buf, slim_int in_len, slim_bool in_ref);
void TECInt_Finalize(TECInt *self);
void TECPoint_Initialize(TECPoint *self);
slim_bool TECPoint_SetXY(TECPoint *self, slim_byte *in_x, slim_int in_xlen, slim_byte *in_y, slim_int in_ylen, slim_bool in_ref);
void TECPoint_Finalize(TECPoint *self);
slim_int TEC_Initialize(TEC *self, TECInt *in_p, TECInt *in_a, TECInt *in_b, TECPoint *in_gen, TECInt *in_order);
void TEC_Finalize(TEC *self);
slim_int TECDH_Initialize(TECDH *self, TEC *in_ec);
slim_int TECDH_GeneratePublicValue(TECDH *self, TECInt *in_private, TECPoint *out_public);
slim_int TECDH_GenerateSharedPoint(TECDH *self, TECInt *in_private, TECPoint *in_public, TECPoint *out_shared_point);
void TECDH_Finalize(TECDH *self);
slim_int TECDSA_Initialize(TECDSA *self, TEC *in_ec);
slim_int TECDSA_GeneratePublicKey(TECDSA *self, TECInt *in_private_key, TECPoint *out_public_key);
slim_int TECDSA_MakeHash1(TECDSA *self, TECInt *in_msg, slim_byte *out_hash, slim_int in_hash_len);
slim_int TECDSA_Sign(TECDSA *self, TECInt *in_msg, TECInt *in_private_key, TECInt *in_random, TECInt *out_sign);
slim_int TECDSA_Verify(TECDSA *self, TECInt *in_msg, TECInt *in_sign, TECPoint *in_public_key);
void TECDSA_Finalize(TECDSA *self);
#else
#endif /* SLIM_CONFIG_CRYPT_USE_ECC */

/* slim_crypt_md2.c */

#ifdef SLIM_CONFIG_CRYPT_USE_MD2
void TMD2_Initialize(TMD2 *self);
void TMD2_Update(TMD2 *self, slim_byte *in_buf, slim_word in_len);
void TMD2_Finalize(TMD2 *self, slim_byte *out_digest);
#endif /* SLIM_CONFIG_CRYPT_USE_MD2 */

/* slim_crypt_md5.c */

#ifdef SLIM_CONFIG_CRYPT_USE_MD5
void TMD5_Initialize(TMD5 *self);
void TMD5_Update(TMD5 *self, slim_byte *in_buf, slim_word in_len);
void TMD5_Finalize(TMD5 *self, slim_byte *out_digest);
#endif /* SLIM_CONFIG_CRYPT_USE_MD5 */

/* slim_crypt_random.c */

#ifdef SLIM_CONFIG_CRYPT_USE_PRBG
#ifdef SLIM_CONFIG_CRYPT_USE_X962
slim_bool TCryptRandom_Initialize(TCryptRandom *self, slim_int in_seed);
void TCryptRandom_Finalize(TCryptRandom *self);
slim_bool TCryptRandom_GenerateBytes(TCryptRandom *self, slim_byte *out_random, slim_word in_req_bytes);
#else /* !defined(SLIM_CONFIG_CRYPT_USE_X962) */
slim_bool TCryptRandom_Initialize(TCryptRandom *self, slim_int in_seed);
void TCryptRandom_Finalize(TCryptRandom *self);
slim_bool TCryptRandom_GenerateBytes(TCryptRandom *self, slim_byte *out_random, slim_word in_len);
#endif /* SLIM_CONFIG_CRYPT_USE_X962 */
#endif /* SLIM_CONFIG_CRYPT_USE_PRBG */

/* slim_crypt_rc2.c */

#ifdef SLIM_CONFIG_CRYPT_USE_RC2
void TRC2_SetKey(TRC2 *self, slim_byte *in_key, slim_int in_len);
void TRC2_Encrypt(TRC2 *self, slim_byte *in_blk, slim_byte *out_blk);
void TRC2_Decrypt(TRC2 *self, slim_byte *in_blk, slim_byte *out_blk);
#endif /* SLIM_CONFIG_CRYPT_USE_RC2 */

/* slim_crypt_rc4.c */

#ifdef SLIM_CONFIG_CRYPT_USE_RC4
void TRC4_Initialize(TRC4 *self, slim_byte *in_source, slim_int in_len);
void TRC4_Update(TRC4 *self, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
void TRC4_Finalize(TRC4 *self);
#endif /* SLIM_CONFIG_CRYPT_USE_RC4 */

/* slim_crypt_rsa.c */

#ifdef SLIM_CONFIG_CRYPT_USE_RSA
void TRSAKey_Initialize(TRSAKey *self, slim_int in_flag);
void TRSAKey_Finalize(TRSAKey *self);
slim_byte * TRSAKey_MallocBuf(TRSAKey *self, slim_int in_size);
void TRSAKey_FreeBuf(TRSAKey *self);
slim_bool TRSAPublicKey_MallocBuf(TRSAPublicKey *self, slim_int in_mod_len, slim_int in_exp_len);
slim_int TRSAPublicKey_Encrypt(TRSAPublicKey *self, TCryptRandom *inout_random, slim_byte *in_buf, slim_word in_len, slim_byte *out_buf, slim_word *out_len);
slim_int TRSAPublicKey_Decrypt(TRSAPublicKey *self, slim_byte *in_buf, slim_word in_len, slim_byte *out_buf, slim_word *out_len);
slim_int TRSAPublicKey_Verify(TRSAPublicKey *self, slim_int in_algo, slim_byte *in_tbs, slim_int in_tbs_len, slim_byte *in_sign, slim_int in_sign_len);
slim_bool TRSAPrivateKey_MallocBuf(TRSAPrivateKey *self, slim_int in_mod_len, slim_int in_exp_len, slim_int in_pubexp_len, slim_int in_p1_len, slim_int in_p2_len, slim_int in_pexp1_len, slim_int in_pexp2_len, slim_int in_coeff_len);
slim_bool TRSAPrivateKey_Decode(TRSAPrivateKey *self, slim_byte *in_der, slim_int in_len);
slim_int TRSAPrivateKey_Encrypt(TRSAPrivateKey *self, slim_byte *in_buf, slim_word in_len, slim_byte *out_buf, slim_word *out_len);
slim_int TRSAPrivateKey_Decrypt(TRSAPrivateKey *self, slim_byte *in_buf, slim_word in_len, slim_byte *out_buf, slim_word *out_len);
slim_int TRSAPrivateKey_Sign(TRSAPrivateKey *self, slim_int in_algo, slim_byte *in_tbs, slim_int in_tbs_len, slim_byte *out_sign);
slim_bool TRSAPrivateKey_ExtractPublicKey(TRSAPrivateKey *self, slim_bool in_ref, TRSAPublicKey *out_public);
#ifdef SLIM_CONFIG_CRYPT_USE_RSA_KEYGEN
slim_bool TRSAPrivateKey_Generate(TRSAPrivateKey *self, slim_word in_exponent, slim_word in_bits);
#endif /* SLIM_CONFIG_CRYPT_USE_RSA_KEYGEN */
#endif /* SLIM_CONFIG_CRYPT_USE_RSA */

/* slim_crypt_sha256.c */

#ifdef SLIM_CONFIG_CRYPT_USE_SHA256
void TSHA256_Initialize(TSHA256 *self);
void TSHA256_Update(TSHA256 *self, slim_byte *in_buf, slim_word in_len);
void TSHA256_Finalize(TSHA256 *self, slim_byte *out_digest);
#endif /* SLIM_CONFIG_CRYPT_USE_SHA256 */

/* slim_crypt_shs1.c */

#ifdef SLIM_CONFIG_CRYPT_USE_SHA1
void TSHS_Initialize(TSHS *self);
void TSHS_Update(TSHS *self, slim_byte *in_buf, slim_word in_len);
void TSHS_Finalize(TSHS *self, slim_byte *out_digest);
#endif /* SLIM_CONFIG_CRYPT_USE_SHA1 */

/* slim_crypt_sym.c */

#ifdef SLIM_CONFIG_CRYPT_USE_STRM
slim_bool TStrmCipher_Initialize(TStrmCipher *self, TSymCipherInfo *in_info);
slim_int TStrmCipher_Update(TStrmCipher *self, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
void TStrmCipher_Finalize(TStrmCipher *self);
#endif /* SLIM_CONFIG_CRYPT_USE_STRM */
#ifdef SLIM_CONFIG_CRYPT_USE_ECB_MODE
slim_bool TBlkCipherECB_Initialize(TBlkCipherECB *self, TSymCipherInfo *in_info);
void TBlkCipherECB_Encrypt(TBlkCipherECB *self, slim_byte *in_plain, slim_int in_len, slim_byte *out_cipher);
void TBlkCipherECB_Decrypt(TBlkCipherECB *self, slim_byte *in_cipher, slim_int in_len, slim_byte *out_plain);
void TBlkCipherECB_Finalize(TBlkCipherECB *self);
#endif /* SLIM_CONFIG_CRYPT_USE_ECB_MODE */
#ifdef SLIM_CONFIG_CRYPT_USE_CBC_MODE
slim_bool TBlkCipherCBC_Initialize(TBlkCipherCBC *self, TSymCipherInfo *in_info);
void TBlkCipherCBC_Encrypt(TBlkCipherCBC *self, slim_byte *in_plain, slim_int in_len, slim_byte *out_cipher);
void TBlkCipherCBC_Decrypt(TBlkCipherCBC *self, slim_byte *in_cipher, slim_int in_len, slim_byte *out_plain);
void TBlkCipherCBC_Finalize(TBlkCipherCBC *self);
#endif /* SLIM_CONFIG_CRYPT_USE_CBC_MODE */
#ifdef SLIM_CONFIG_CRYPT_USE_BLK
slim_bool TBlkCipher_Initialize(TBlkCipher *self, TSymCipherInfo *in_info);
slim_int TBlkCipher_Update(TBlkCipher *self, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
void TBlkCipher_Finalize(TBlkCipher *self);
#endif /* SLIM_CONFIG_CRYPT_USE_BLK */
#ifdef SLIM_CONFIG_CRYPT_USE_SYM
slim_bool TSymCipher_Initialize(TSymCipher *self, TSymCipherInfo *in_info);
slim_int TSymCipher_Update(TSymCipher *self, slim_byte *in_buf, slim_int in_len, slim_byte *out_buf);
void TSymCipher_Finalize(TSymCipher *self);
#endif /* SLIM_CONFIG_CRYPT_USE_SYM */
