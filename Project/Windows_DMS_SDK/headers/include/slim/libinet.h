/*
	libinet.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/libinet.h 42    06/07/31 19:04 Someya $ */

#ifndef SLIM_LIBINET_H
#define SLIM_LIBINET_H

#ifndef SLIM_LIBCORE_H
#include <slim/libcore.h>
#endif

#include <slim/libssl.h>

#undef SLIM_API
#define SLIM_API SLIM_DLLIMPORT

#include <slim/inet/inetbase.h>
#include <slim/inet/url.h>
#include <slim/inet/media.h>
#include <slim/inet/mime.h>
#include <slim/inet/drm.h>
#include <slim/inet/contdtmn.h>
#include <slim/inet/content.h>
#include <slim/inet/mulcont.h>
#include <slim/inet/viruschk.h>

#include <slim/inet/filep.h>
#include <slim/inet/aboutch.h>
#include <slim/inet/pictp.h>
#include <slim/inet/datap.h>

#include <slim/inet/dns.h>
#include <slim/inet/httpstrm.h>
#include <slim/inet/http.h>

#include <slim/inet/inetutil.h>
#include <slim/inet/postdata.h>

SLIM_BEGIN_C_LINKAGE
#include <slim/inet/inetp.h>
SLIM_END_C_LINKAGE

#ifdef SLIM_BUILDING_LIBRARIES
#include <slim/private/libinet.h>
#endif

#undef SLIM_API
#define SLIM_API SLIM_DLLEXPORT

#endif
