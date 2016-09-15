/*
	pkcs10.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/ssl/pkcs10.h 8     05/12/28 12:08 Someya $ */

#ifndef SLIM_PKCS10_H_PRIVATE
#define SLIM_PKCS10_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

/*=============
	PKCS#10
 =============*/

typedef slim_int (*TP10EncodeAttributesProc)(void *in_arg, slim_byte *out_der);

SLIM_END_C_LINKAGE

#endif /* SLIM_PKCS10_H */
