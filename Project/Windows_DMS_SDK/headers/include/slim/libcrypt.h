/*
	libcrypt.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/libcrypt.h 5     05/12/28 12:07 Someya $ */

#ifndef SLIM_LIBCRYPT_H
#define SLIM_LIBCRYPT_H

#ifndef SLIM_LIBCORE_H
#include <slim/libcore.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLIMPORT

#include <slim/crypt/crypt.h>

SLIM_BEGIN_C_LINKAGE
#include <slim/crypt/cryptp.h>
SLIM_END_C_LINKAGE

#ifdef SLIM_BUILDING_LIBRARIES
#include <slim/private/libcrypt.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLEXPORT

#endif
