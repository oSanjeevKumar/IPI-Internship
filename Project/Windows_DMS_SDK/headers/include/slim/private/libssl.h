/*
	libssl.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/libssl.h 8     05/12/28 12:08 Someya $ */

#ifndef SLIM_LIBSSL_H_PRIVATE
#define SLIM_LIBSSL_H_PRIVATE

#include <slim/private/ssl/a1oid.h>
#include <slim/private/ssl/cert.h>
#include <slim/private/ssl/ssl.h>

#ifdef SLIM_CONFIG_USE_PKCS10
#include <slim/private/ssl/pkcs10.h>
#endif

SLIM_BEGIN_C_LINKAGE
#include <slim/private/ssl/sslp.h>
SLIM_END_C_LINKAGE

#endif
