/*
	libssl.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/libssl.h 9     05/12/28 12:07 Someya $ */

#ifndef SLIM_LIBSSL_H
#define SLIM_LIBSSL_H

#ifndef SLIM_LIBCORE_H
#include <slim/libcore.h>
#endif

#ifndef SLIM_LIBCRYPT_H
#include <slim/libcrypt.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLIMPORT

#include <slim/ssl/asn1.h>
#include <slim/ssl/asn1schm.h>
#include <slim/ssl/a1oidid.h>
#include <slim/ssl/cert.h>
#include <slim/ssl/ssl.h>

#ifdef SLIM_CONFIG_USE_PKCS5 
#include <slim/ssl/pkcs.h>
#include <slim/ssl/pkcs5.h>
#endif

#ifdef SLIM_CONFIG_USE_PKCS7
#include <slim/ssl/pkcs.h>
#include <slim/ssl/pkcs7.h>
#endif

#ifdef SLIM_CONFIG_USE_PKCS12
#include <slim/ssl/pkcs.h>
#include <slim/ssl/pkcs12.h>
#endif

SLIM_BEGIN_C_LINKAGE
#include <slim/ssl/sslp.h>
SLIM_END_C_LINKAGE

#ifdef SLIM_BUILDING_LIBRARIES
#include <slim/private/libssl.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLEXPORT

#endif
