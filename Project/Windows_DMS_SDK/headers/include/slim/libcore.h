/*
	libcore.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/libcore.h 40    06/01/17 17:58 Nagamati $ */

#ifndef SLIM_LIBCORE_H
#define SLIM_LIBCORE_H

#include <slim/config/config.h>
#include <slim/copy.h>

#undef SLIM_API
#define SLIM_API SLIM_DLLIMPORT

#include <slim/basis/base.h>
#include <slim/basis/peer.h>
#include <slim/basis/custom.h>
#include <slim/basis/token.h>
#include <slim/basis/clib.h>
#include <slim/basis/memory.h>
#include <slim/basis/coll.h>
#include <slim/basis/chsetinf.h>
#include <slim/basis/i18n.h>
#include <slim/basis/string.h>
#include <slim/basis/arena.h>
#include <slim/basis/guibase.h>

#include <slim/basis/cdatafmt.h>
#include <slim/basis/reader.h>
#include <slim/basis/xxmltknz.h>
#include <slim/basis/ptxttknz.h>
#include <slim/basis/imsgtknz.h>
#include <slim/basis/xmlerr.h>

#include <slim/basis/bignum.h>
#include <slim/basis/regexp.h>
#include <slim/basis/util.h>

#ifdef SLIM_CONFIG_USE_BIDI
#include <slim/basis/bidi.h>
#endif

SLIM_BEGIN_C_LINKAGE
#include <slim/basis/basisp.h>
SLIM_END_C_LINKAGE

#ifdef SLIM_BUILDING_LIBRARIES
#include <slim/private/libcore.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLEXPORT

#endif
