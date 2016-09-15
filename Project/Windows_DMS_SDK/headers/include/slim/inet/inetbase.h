/*
	inetbase.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/inetbase.h 16    05/12/28 12:07 Someya $ */

#ifndef SLIM_INETBASE_H
#define SLIM_INETBASE_H

SLIM_BEGIN_C_LINKAGE

/*
 * Error Code
 */

#define SLIM_INET_ERROR_RESERVED	(-1000)

#define SLIM_HTTP_ERROR_START	(-200)
#define SLIM_FILEP_ERROR_START	(-300)
#define SLIM_PICTP_ERROR_START	(-400)
#define SLIM_DATAP_ERROR_START	(-500)
#define SLIM_CONTENT_ERROR_START	(-600)

/* declare */

typedef struct iTContent_ **TContent;
typedef struct iTContentSpec_ **TContentSpec;
typedef struct iTContentChannel_ **TContentChannel;
typedef struct iTStreamContent_ **TStreamContent;
typedef struct iTMultiContent_ **TMultiContent;
typedef struct iTFilepChannel_ **TFilepChannel;

SLIM_END_C_LINKAGE

#endif
