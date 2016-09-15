/*
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* WARNING: DO NOT EDIT! This file is generated automatically. */



/* slim_crypt_aes.c */


/* slim_crypt_des.c */


/* slim_crypt_digest.c */

#ifdef SLIM_CONFIG_CRYPT_USE_MD
SLIM_API slim_int MD_DigestSize(slim_int in_algo);
SLIM_API slim_bool TMD_Initialize(TMD *self, slim_int in_algo);
SLIM_API void TMD_BeginCtx(TMD *self);
SLIM_API void TMD_UpdateCtx(TMD *self, slim_byte *in_msg, slim_word in_len);
SLIM_API void TMD_EndCtx(TMD *self, slim_byte *out_digest);
SLIM_API void TMD_Generate(TMD *self, slim_byte *in_msg, slim_word in_len, slim_byte *out_digest);
SLIM_API void TMD_Finalize(TMD *self);
SLIM_API slim_int TMD_Algorithm(TMD *self);
#endif /* SLIM_CONFIG_CRYPT_USE_MD */

/* slim_crypt_ecc.c */


/* slim_crypt_md2.c */


/* slim_crypt_md5.c */


/* slim_crypt_random.c */


/* slim_crypt_rc2.c */


/* slim_crypt_rc4.c */


/* slim_crypt_rsa.c */


/* slim_crypt_sha256.c */


/* slim_crypt_shs1.c */


/* slim_crypt_sym.c */

