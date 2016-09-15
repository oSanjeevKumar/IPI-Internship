/*
	version.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/version.h 31    06/08/31 18:19 Someya $ */

#ifndef SLIM_VERSION_H_PRIVATE
#define SLIM_VERSION_H_PRIVATE

SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_VERSION_ID_CORE = 0,
	SLIM_VERSION_ID_CODEC,
	SLIM_VERSION_ID_INET,
	SLIM_VERSION_ID_WWW,
#ifdef SLIM_CONFIG_USE_XML
	SLIM_VERSION_ID_XML,
#endif
	SLIM_VERSION_IDs
};

#define SLIM_LIB_VERSIONS	SLIM_VERSION_IDs

#define SLIM_VERSION_MAJOR		(3)
#define SLIM_VERSION_MINOR		(4)
#define SLIM_VERSION_PATCH		(5)
#define SLIM_VERSION_EXTENSION	(SLIM_CONFIG_VERSION_EXTENSION)

#define slim_get_version(ver)	{ \
	(ver)->fModule    = SLIM_T(SLIM_CONFIG_BROWSER_NAME);\
	(ver)->fMajor     = SLIM_VERSION_MAJOR;\
	(ver)->fMinor     = SLIM_VERSION_MINOR;\
	(ver)->fPatch	  = SLIM_VERSION_PATCH;\
	(ver)->fExtension = SLIM_T(SLIM_VERSION_EXTENSION);\
}

#define SLIM_CORE_VERSION_MODULE	"libcore"
#define SLIM_CORE_VERSION_MAJOR	(1)
#define SLIM_CORE_VERSION_MINOR	(1)
#define SLIM_CORE_VERSION_PATCH	(999)
#define SLIM_CORE_VERSION_EXTENSION	(SLIM_CONFIG_VERSION_EXTENSION)

#define slim_core_get_version(ver) { \
	(ver)->fModule = SLIM_T(SLIM_CORE_VERSION_MODULE); \
	(ver)->fMajor = SLIM_CORE_VERSION_MAJOR;\
	(ver)->fMinor = SLIM_CORE_VERSION_MINOR;\
	(ver)->fPatch = SLIM_CORE_VERSION_PATCH;\
	(ver)->fExtension = SLIM_T(SLIM_CORE_VERSION_EXTENSION);\
}


#define SLIM_CODEC_VERSION_MODULE	"libcodec"
#define SLIM_CODEC_VERSION_MAJOR	(1)
#define SLIM_CODEC_VERSION_MINOR	(1)
#define SLIM_CODEC_VERSION_PATCH	(999)
#define SLIM_CODEC_VERSION_EXTENSION	(SLIM_CONFIG_VERSION_EXTENSION)

#define slim_codec_get_version(ver)	{ \
	(ver)->fModule = SLIM_T(SLIM_CODEC_VERSION_MODULE);\
	(ver)->fMajor = SLIM_CODEC_VERSION_MAJOR;\
	(ver)->fMinor = SLIM_CODEC_VERSION_MINOR;\
	(ver)->fPatch = SLIM_CODEC_VERSION_PATCH;\
	(ver)->fExtension = SLIM_T(SLIM_CODEC_VERSION_EXTENSION);\
}

#define SLIM_INET_VERSION_MODULE	"libinet"
#define SLIM_INET_VERSION_MAJOR	(1)
#define SLIM_INET_VERSION_MINOR	(1)
#define SLIM_INET_VERSION_PATCH	(999)
#define SLIM_INET_VERSION_EXTENSION	(SLIM_CONFIG_VERSION_EXTENSION)

#define slim_inet_get_version(ver)	{ \
	(ver)->fModule = SLIM_T(SLIM_INET_VERSION_MODULE);\
	(ver)->fMajor = SLIM_INET_VERSION_MAJOR;\
	(ver)->fMinor = SLIM_INET_VERSION_MINOR;\
	(ver)->fPatch = SLIM_INET_VERSION_PATCH;\
	(ver)->fExtension = SLIM_T(SLIM_INET_VERSION_EXTENSION);\
}

#define SLIM_WWW_VERSION_MODULE	"libwww"
#define SLIM_WWW_VERSION_MAJOR	(1)
#define SLIM_WWW_VERSION_MINOR	(1)
#define SLIM_WWW_VERSION_PATCH	(999)
#define SLIM_WWW_VERSION_EXTENSION	(SLIM_CONFIG_VERSION_EXTENSION)

#define slim_www_get_version(ver)	{ \
	(ver)->fModule = SLIM_T(SLIM_WWW_VERSION_MODULE);\
	(ver)->fMajor = SLIM_WWW_VERSION_MAJOR;\
	(ver)->fMinor = SLIM_WWW_VERSION_MINOR;\
	(ver)->fPatch = SLIM_WWW_VERSION_PATCH;\
	(ver)->fExtension = SLIM_T(SLIM_WWW_VERSION_EXTENSION);\
}

#define SLIM_XML_VERSION_MODULE	"libxml"
#define SLIM_XML_VERSION_MAJOR	(1)
#define SLIM_XML_VERSION_MINOR	(1)
#define SLIM_XML_VERSION_PATCH	(999)
#define SLIM_XML_VERSION_EXTENSION	(SLIM_CONFIG_VERSION_EXTENSION)

#define slim_xml_get_version(ver)	{ \
	(ver)->fModule = SLIM_T(SLIM_XML_VERSION_MODULE);\
	(ver)->fMajor = SLIM_XML_VERSION_MAJOR;\
	(ver)->fMinor = SLIM_XML_VERSION_MINOR;\
	(ver)->fPatch = SLIM_XML_VERSION_PATCH;\
	(ver)->fExtension = SLIM_T(SLIM_XML_VERSION_EXTENSION);\
}

void slim_get_lib_versions(TVersionInfo *out_vers);

SLIM_END_C_LINKAGE
#endif
