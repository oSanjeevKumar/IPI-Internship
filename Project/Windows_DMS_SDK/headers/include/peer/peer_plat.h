/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef _PEER_PLAT_H_
#define _PEER_PLAT_H_

/* Includes.  */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <tchar.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <dlna_peer.h>
#include <winapifamily.h>

#define HAVE_TIME_H
#define HAVE_STDIO_H
#define HAVE_SYS_STAT_H
#define HAVE_SETJMP_H
#define HAVE_WINSOCK2_H
#define HAVE_WINDOWS_H

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
#define HAVE_IPHLPAPI_H
#pragma comment(lib, "IPHlpApi.lib")
#pragma comment(lib, "winmm.lib")
#endif //WINAPI_PARTITION_PHONE_APP


/* NFLC-3.1 Compliant dependency >>>>>> START */
#pragma comment(lib, "Ws2_32.lib")

#undef DLNA_S_ISLNK
#define DLNA_S_ISLNK(MODE)   (MODE & 0x0000)

/* SMM: Used to customize separator in filename paths */
#define PATH_REDIRECTOR      "..\\"
/* NFLC-3.1 Compliant dependency >>>>>> END */

/* For _stat  */
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0603	// Change this to the appropriate value to target other versions of Windows.
#endif /* ! _WIN32_WINNT */
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0601	// Change this to the appropriate value to target other versions of Windows.
#endif /* ! _WIN32_WINNT */
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif /* ! _WIN32_WINNT */
#endif


# include <sys/types.h>
# include <errno.h>
# include <sys/stat.h>

#ifdef HAVE_WINSOCK2_H
# include <winsock2.h>
#endif /* HAVE_WINSOCK2_H */

#ifdef HAVE_IPHLPAPI_H
# include <Iphlpapi.h>
#endif /* HAVE_IPHLPAPI_H */

#ifdef HAVE_WINDOWS_H
# include <windows.h>
#endif /* HAVE_WINDOWS_H */

#ifndef __cplusplus
# include <winsock2.h>
# include <ws2tcpip.h>
# include <windows.h>
#endif

#ifndef BUFSIZ
# define BUFSIZ 512
#endif /* ! BUFSIZ */

/* Debug function.  */
#ifdef UNDER_CE
# define dlnaDebugPrintfPeer plat_debugprintf
#endif /* UNDER_CE */

#ifndef _DEBUG
# undef dlnaDebugPrintfPeer
# define dlnaDebugPrintfPeer
#endif /* ! _DEBUG */

/* Memory API mapper.  */
#undef dlna_memory_alloc
#define dlna_memory_alloc malloc

#undef dlna_memory_free
#define dlna_memory_free free

#undef dlna_memory_realloc
#define dlna_memory_realloc realloc

/* Memory utility API mapper.  */
#undef dlna_memset
#define dlna_memset memset

#undef dlna_memcpy
#define dlna_memcpy memcpy

#undef dlna_memcmp
#define dlna_memcmp memcmp

#undef dlna_memmove
#define dlna_memmove memmove

/* Endian conversion macros */
#undef dlna_ntohl
#define dlna_ntohl ntohl

#undef dlna_ntohs
#define dlna_ntohs ntohs

#undef dlna_htonl
#define dlna_htonl htonl

#undef dlna_htons
#define dlna_htons htons

#if defined(WIN32) || defined(WIN64)

# define inline __inline

# undef strcasecmp
# define strcasecmp _stricmp

# undef strncasecmp
# define strncasecmp _strnicmp

# undef snprintf
# define snprintf _snprintf

#endif /* WIN32 || WIN64 */

/* sscanf */
#undef dlna_sscanf
#define HAVE_SSCANF
#define dlna_sscanf sscanf

/* Define what string functions we support */
#define HAVE_STRLEN
#define HAVE_STRCMP
#define HAVE_STRNCMP
#define HAVE_STRICMP
#define HAVE_STRNICMP
#define HAVE_STRCPY
#define HAVE_STRNCPY
#define HAVE_STRTOUL
#define HAVE_STRDUP
#define HAVE_STRSTR
#define HAVE_STRCHR
#define HAVE_STRRCHR
#define HAVE_STRCAT
#define HAVE_STRNCAT
#define HAVE_STRSPN
#define HAVE_ATOI
#define HAVE_ISSPACE
#define HAVE_ISALPHA
#define HAVE_ISALNUM
#define HAVE_ISDIGIT
#define HAVE_ISXDIGIT
#define HAVE_TOLOWER
#define HAVE_TOUPPER
#define HAVE_STRRSTR
#define HAVE_ISPRINT

#undef DLNA_ASSERT
#define DLNA_ASSERT(x) assert(x)

/* File system stat macro.  */
#undef DLNA_S_ISDIR
#define DLNA_S_ISDIR(MODE)			(MODE & _S_IFDIR)

#undef DLNA_S_ISREG
#define DLNA_S_ISREG(MODE)			(MODE & _S_IFREG)

#undef DLNA_S_ISPERMISSION
#define DLNA_S_ISPERMISSION(MODE)	(MODE & FILE_ATTRIBUTE_READONLY)

#undef DLNA_S_ISREADABLE
#define DLNA_S_ISREADABLE(MODE)   (MODE & _S_IREAD)

#undef DLNA_S_ISWRITABLE
#define DLNA_S_ISWRITABLE(MODE)   (MODE & _S_IWRITE)

#define DLNA_ACCESS_F              0 /*Test for existence*/
#define DLNA_ACCESS_X              1 /*Test for execute permission*/
#define DLNA_ACCESS_W              2 /*Test for write permission*/
#define DLNA_ACCESS_R              4 /*Test for read permission*/

/* SMM: Used to customize separator in filename paths */
#define PATH_SEPARATOR				"\\"
#define PATH_SEPARATOR_CHAR			'\\'
#define PATH_DOT					"."
#define PATH_DOT_CHAR				'.'
#define PATH_DOUBLEDOT				".."
#define PATH_DOUBLEDOT_CHAR			'..'

/* For peer string conversion routines (multibyte to wide, etc.)  */
#include "peer_string.h"

/*
* DLNA wrapper for setjmp and long jump functionality. Evey platform can
* specific implementations for these routines, this method works for
* standard c library versions. Refer to peer_jump.c also.
*/

#define dlnaJumpSetPeer setjmp
#define dlnaJumpLongPeer longjmp

typedef jmp_buf dlna_jmp_buf;

/* Temprary definition of debug function register.  */
#ifdef __cplusplus
extern "C" {
#endif

	int plat_debugprintf(const char *format, ...);
	dlna_jmp_buf *dlnaSetJmpGetBufferPeer(void);
	dlna_jmp_buf *dlnaLongJmpGetBufferPeer(void);
	time_t winConvertSys2Timet(SYSTEMTIME* rSysTime);

#ifdef __cplusplus
}
#endif

#endif /* _PEER_PLAT_H_ */
