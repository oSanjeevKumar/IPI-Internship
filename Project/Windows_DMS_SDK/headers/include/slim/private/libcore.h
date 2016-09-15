/*
	libcore.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/libcore.h 41    06/05/22 20:34 Yamabuti $ */

#ifndef SLIM_LIBCORE_H_PRIVATE
#define SLIM_LIBCORE_H_PRIVATE

#include <slim/private/basis/base.h>
#include <slim/private/basis/isctype.h>
#include <slim/private/basis/clib.h>
#include <slim/private/basis/split.h>
#include <slim/private/basis/memory.h>
#include <slim/private/basis/from.h>
#include <slim/private/basis/bignum.h>
#include <slim/private/basis/chstproc.h>
#include <slim/private/basis/i18n.h>
#include <slim/private/basis/i18ncjk.h>
#include <slim/private/basis/string.h>
#include <slim/private/basis/coll.h>
#include <slim/private/basis/arena.h>
#include <slim/private/basis/token.h>
#include <slim/private/basis/regexp.h>
#include <slim/private/basis/util.h>
#include <slim/private/basis/prefutil.h>
#include <slim/private/basis/reader.h>
#include <slim/private/basis/xxmltknz.h>
#include <slim/private/basis/imsgtknz.h>
#include <slim/private/basis/ptxttknz.h>
#include <slim/private/basis/cdatafmt.h>
#include <slim/private/basis/slimrslv.h>
#include <slim/private/basis/glblrslv.h>

#ifdef SLIM_CONFIG_USE_BIDI
#include <slim/private/basis/bidi.h>
#endif

SLIM_BEGIN_C_LINKAGE
#include <slim/private/basis/basisp.h>
SLIM_END_C_LINKAGE

#endif /* SLIM_LIBCORE_H_PRIVATE */
