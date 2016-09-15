/*
	config.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

#ifndef SLIM_CONFIG_H
#define SLIM_CONFIG_H

#ifdef WIN32
/*
	4127: conditional expression is constant
	4699: Note: pre-compiled header usage information message
	4705: statement has no effect
	4100: 'identifier' : unreferenced formal parameter
	4701: local variable 'name' may be used without having been initialized
	4206: nonstandard extension used : translation unit is empty
*/
#pragma warning(disable:4127 4699 4705 4100 4018 4701 4206 4786)
#endif

/* 
	SLIM_CONFIG_CC_32BIT
		Define if int is 32 bit long and short is 16 bit long on your compiler.
*/
#define SLIM_CONFIG_CC_32BIT

#define SLIM_CONFIG_CC_X86
/* #define SLIM_CONFIG_CC_SH_BE */
/* #define SLIM_CONFIG_CC_ARM_LE */
/* #define SLIM_CONFIG_CC_ARM_BE */
/* #define SLIM_CONFIG_CC_POWERPC_BE */

/* DLL setting sample */
#if 0 /* for Win32 */
#ifdef SLIM_BUILDING_LIBRARIES
#define SLIM_DLLEXPORT __declspec( dllexport )
#define SLIM_DLLIMPORT __declspec( dllexport )
#else
#define SLIM_DLLEXPORT __declspec( dllexport ) /* for Peer APIs */
#define SLIM_DLLIMPORT __declspec( dllimport )
#endif /* SLIM_BUILDING_LIBRARIES */
#endif

#include <slim/config/ccconfig.h>

/* NOTE: DO NOT use #undef for disabling any configuration macro. 
 * Because some configuration macros may be defined as a compiler option.
 */
 
/* color */
#define SLIM_CONFIG_COLOR_RGB
#define SLIM_CONFIG_COLOR_ALPHA_TRANSPARENT

/*
 * debug
 */

#ifdef _DEBUG
#define SLIM_CONFIG_DEBUG
#define SLIM_CONFIG_MEMORY_DEBUG
#define SLIM_CONFIG_MEMNODE_DEBUG
#endif

/*
 * memory debug
 */
/*
#define SLIM_CONFIG_MEMORY_DEBUG
#define SLIM_CONFIG_MEMNODE_DEBUG
*/
/* #define SLIM_CONFIG_MEMORY_CHECKOW_DEBUG */

/*
 * debug log
 */
/* #define SLIM_CONFIG_DEBUG_LOG */

/*
 * other config
 */
#define SLIM_CONFIG_MORESPEED
#define SLIM_CONFIG_NOMULTITHREAD
	/* Do not undefine this configuration. Multi-threading will be supported some time or other */

#if defined(__IOS__) || defined(ANDROID)
#if !defined(SLIM_CONFIG_MEMORY_ALTERNATIVE)
#define SLIM_CONFIG_MEMORY_ALTERNATIVE
#endif /* !defined(SLIM_CONFIG_MEMORY_ALTERNATIVE) */
#endif /* defined(__IOS__) || defined(ANDROID) */
/* #define SLIM_CONFIG_MEMORY_PROTECT_DEBUG */ /* add slim_memory_protect.c to makefile */

/* modules */
#define SLIM_CONFIG_MOD_MEMORY

/*
 * value limit
 */
#ifndef SLIM_CONFIG_WWW_VALUE_MAX
#define SLIM_CONFIG_WWW_VALUE_MAX SLIM_INT_MAX
#endif
#ifndef SLIM_CONFIG_WWW_VALUE_MIN
#define SLIM_CONFIG_WWW_VALUE_MIN SLIM_INT_MIN
#endif

/*
 * log output
 */

/*
#define SLIM_CONFIG_HTTP_STREAM_DEBUG
#define SLIM_CONFIG_SSL_DEBUG
#define SLIM_CONFIG_TICKCOUNT_DEBUG
*/

/* FixedString */
/* #define SLIM_CONFIG_FIXEDSTRING_REPLACE_STRING */

/*                 */
/* behavior config */
/*                 */

/* Peer */
/* #define SLIM_CONFIG_ENABLE_FILESYSTEM_PEER */
/* #define SLIM_CONFIG_USE_ALT_MEMORY_PEER */

/* I18N */
/* if you want to be disable specific languages, please comment out */
#define SLIM_CONFIG_USE_JAPANESE
#define SLIM_CONFIG_USE_KOREAN
#define SLIM_CONFIG_USE_SIMPLIFIED_CHINESE
#define SLIM_CONFIG_USE_TRADITIONAL_CHINESE
#define SLIM_CONFIG_USE_BALTIC
#define SLIM_CONFIG_USE_CENTRAL_EUROPEAN
#define SLIM_CONFIG_USE_CYRILLIC
#define SLIM_CONFIG_USE_GREEK
#define SLIM_CONFIG_USE_NORDIC
#define SLIM_CONFIG_USE_SOUTH_EUROPEAN
#define SLIM_CONFIG_USE_THAI
#define SLIM_CONFIG_USE_TURKISH
#define SLIM_CONFIG_USE_ARABIC
#define SLIM_CONFIG_USE_HEBREW

/* for compatibility and convenience */
/* #define SLIM_CONFIG_DISABLE_CJK */

/* if you want to use UTF-8 as architecture charset of all languages */
/* #define SLIM_CONFIG_ARCHCHARSET_UTF_8 */

/* R to L */
/* #define SLIM_CONFIG_USE_RTL */
/* #define SLIM_CONFIG_USE_BIDI */
/* #define SLIM_CONFIG_BIDI_PEER_CHARSET	SLIM_CHARSET_XXX */

/* font */
/* #define SLIM_CONFIG_FONTFAMILY_IGNORECASE */

/* DNS */
/*
#define SLIM_CONFIG_USE_DNS
*/

/* Server Peer */
/*
#define SLIM_CONFIG_USE_TCP_SERVER
*/
/* HTTP */

#define SLIM_CONFIG_USE_HTTP
#define SLIM_CONFIG_HTTP_STREAM_USE_PIPELINE
/*
#define SLIM_CONFIG_USE_L2CACHE
*/

/* SSL */
/*
#define SLIM_CONFIG_USE_SSL
*/

/* datap */
/*
#define SLIM_CONFIG_USE_DATAP
*/

/* CSS */
/*
#define SLIM_CONFIG_CSS_LEVEL_1_POSITIONING
#define SLIM_CONFIG_CSS_LEVEL_2
#define SLIM_CONFIG_CSS_NOSUPPORT_FONT_FACE
*/
/* #define SLIM_CONFIG_CSS_LEVEL_3 */

/* NSPlug-in */
/*
#define SLIM_CONFIG_USE_NSPLUGIN
*/

/* DOM */
/*
#define SLIM_CONFIG_DOM
*/
#ifdef SLIM_CONFIG_DOM
#define SLIM_CONFIG_DOM0_NAVIGATOR_APPCODENAME		SLIM_T("Mozilla")
#define SLIM_CONFIG_DOM0_NAVIGATOR_APPNAME			SLIM_T("ACCESS NetFront")
#define SLIM_CONFIG_DOM0_NAVIGATOR_APPVERSION		SLIM_T("3.4")
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_APPMINORVERSION	SLIM_T("") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_OSCPU			SLIM_T("Windows NT 5.1") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_CPUCLASS			SLIM_T("x86") */
#define SLIM_CONFIG_DOM0_NAVIGATOR_PLATFORM			SLIM_T("Win32")
#define SLIM_CONFIG_DOM0_NAVIGATOR_LANGUAGE			SLIM_T("ja")
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_BROWSERLANGUAGE	SLIM_T("ja") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_SYSTEMLANGUAGE	SLIM_T("ja") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_USERLANGUAGE		SLIM_T("ja") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_VENDOR			SLIM_T("ACCESS") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_VENDORSUB		SLIM_T("") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_PRODUCT			SLIM_T("NetFront") */
/* #define SLIM_CONFIG_DOM0_NAVIGATOR_PRODUCTSUB		SLIM_T("") */
#endif

/* Crypto Object */
/* #define SLIM_CONFIG_USE_DOM_CRYPTO */

/* JavaScript */
/*
#define SLIM_CONFIG_JS_DEBUG
*/
/* for reduce memory consumption */
/* #define SLIM_CONFIG_JS_DISABLE_SOURCE_TEXT */
/* for external dtoi() implementation */
/* #define SLIM_CONFIG_JS_USE_EXTERNAL_DTOI */

/* Markup language */
/*
#define SLIM_CONFIG_USE_RSS
#define SLIM_CONFIG_USE_ATOM
#define SLIM_CONFIG_USE_WML 
#define SLIM_CONFIG_USE_SMIL
#define SLIM_CONFIG_USE_XML_WRITER
#define SLIM_CONFIG_USE_TINYHTML
#undef SLIM_CONFIG_USE_WMLSCRIPT
*/

/* SVG configs  */
/*
#define SLIM_SVG_CONFIG_DEBUG_OVERFLOW
#define SLIM_CONFIG_SVG_USE_DOM
#define SLIM_CONFIG_SVG_USE_CSS
#define SLIM_CONFIG_SVG_USE_RGB32
#define SLIM_CONFIG_SVG_USE_RGB12
#define SLIM_CONFIG_SVG_USE_RGB16
#define SLIM_CONFIG_SVG_USE_ARGB16
#define SLIM_CONFIG_SVG_USE_SPECIAL16
*/

/* PictP */
/*
#define SLIM_CONFIG_USE_PICTP
*/

/* Media Scheme */
/*
#define SLIM_CONFIG_USE_MEDIA_SCHEME
*/

/* image decoder */
/*
#define SLIM_CONFIG_USE_GIF
#define SLIM_CONFIG_USE_JPEG
#define SLIM_CONFIG_USE_PNG
#define SLIM_CONFIG_USE_MNG
#define SLIM_CONFIG_USE_WBMP
#define SLIM_CONFIG_USE_BMP
#define SLIM_CONFIG_USE_ZLIB
*/
/* PNG requires Zlib, HTTP Deflate/Gzip requires Zlib */
/* #define SLIM_CONFIG_GIF_NOINLINING */
/* #define SLIM_CONFIG_BMP_NOINLINING */

/* page save */
/*
#define SLIM_CONFIG_USE_PAGESAVE_SLIM
#define SLIM_CONFIG_USE_PAGESAVE_MHT
#define SLIM_CONFIG_USE_PAGESAVE_CACHE
*/

/* Netscape Plug-in */
/* #define SLIM_CONFIG_NSPLUGIN_UNIX */

/* pixmap */
/* #define SLIM_CONFIG_USE_RGB16_PIXELMAP_CLASS */
/* #define SLIM_CONFIG_USE_RGB8_PIXELMAP_CLASS */
/* #define SLIM_CONFIG_PIXMAP_USE_SPECIAL */

/* Cryptography */
/* #define SLIM_CONFIG_CRYPT_EXPORT_RESTRICTION */	/* undef SLIM_CONFIG_CRYPT_USE_XXX except message digests */
#define SLIM_CONFIG_CRYPT_USE_PRBG					/* pseudo-random byte generator */
#if 0
#define SLIM_CONFIG_CRYPT_USE_MD2					/* message digest */
#define SLIM_CONFIG_CRYPT_USE_MD5					/* message digest */
#endif
#define SLIM_CONFIG_CRYPT_USE_SHA1					/* message digest */
/* #define SLIM_CONFIG_CRYPT_USE_SHA256 */			/* message digest */
#define SLIM_CONFIG_CRYPT_USE_MD					/* abstract message digest class */
#if 0
#define SLIM_CONFIG_CRYPT_USE_HMAC					/* HMAC - depend on USE_MD */
#define SLIM_CONFIG_CRYPT_USE_RC4					/* stream cipher */
#define SLIM_CONFIG_CRYPT_USE_RC2					/* block cipher */
#define SLIM_CONFIG_CRYPT_USE_DES					/* block cipher */
#define SLIM_CONFIG_CRYPT_USE_2KEYDES3				/* block cipher */
#define SLIM_CONFIG_CRYPT_USE_DES3					/* block cipher */
#endif
#define SLIM_CONFIG_CRYPT_USE_AES					/* block cipher */
#define SLIM_CONFIG_CRYPT_USE_ECB_MODE				/* block cipher mode - ecb */
#define SLIM_CONFIG_CRYPT_USE_CBC_MODE				/* block cipher mode - cbc */
#if 0
#define SLIM_CONFIG_CRYPT_USE_STRM					/* abstract stream cipher class */
#endif
#define SLIM_CONFIG_CRYPT_USE_BLK					/* abstract block cipher class */
#define SLIM_CONFIG_CRYPT_USE_SYM					/* abstract symmetic cipher class - depend on USE_STRM and USE_BLK */
/* #define SLIM_CONFIG_CRYPT_USE_CUSTOM */
#if 0
#define SLIM_CONFIG_CRYPT_USE_RSA
#endif
#define SLIM_CONFIG_CRYPT_USE_ECC				/* elliptic curve cryptography */

/* PKCS */
#if 0
#define SLIM_CONFIG_USE_PKCS7
#define SLIM_CONFIG_USE_PKCS10
#define SLIM_CONFIG_USE_PKCS12
#endif

/* Rapid Rendering */
/*
#define SLIM_CONFIG_USE_RAPID_RENDERING
*/

/* PostData */
/*
#define SLIM_CONFIG_POSTDATA_DEBUG
*/

/* VirusChecker */
/* #define SLIM_CONFIG_USE_VIRUSCHECKER */

/* WebDataManager */
/*
#define SLIM_CONFIG_USE_WEBDATA_MANAGER
*/

/* QueryFormatter */
/*
#define SLIM_CONFIG_USE_QUERY_FORMATTER
*/

/* Favicon */
/*
#define SLIM_CONFIG_USE_FAVICON
*/

/* WAP Push */
/* #define SLIM_CONFIG_USE_WAPPUSH */

/* plate */
/* #define SLIM_CONFIG_USE_PLATE */
/* #define SLIM_CONFIG_USE_PWSPATCH */

/* offscreen */
/* #define SLIM_CONFIG_USE_OFFSCREEN */

/* draw optimization (experimental) */
/* #define SLIM_CONFIG_OPTIMIZE_DRAW_EXPERIMENTAL */

#include <slim/config/config0.h>

#endif
