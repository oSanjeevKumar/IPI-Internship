/*
* ahl.h
* Copyright (C) 2015 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef AHL_H
#define AHL_H

#include <dlna_peer.h>
#ifdef ENABLE_WEBSOCKETINTERFACE
#include <nflc_webinterface.h>
#endif /* ENABLE_WEBSOCKETINTERFACE */
/* AHL return value.  */
/*!
\par Return Values:
The return values for the AHL API are shown below.

<table>
	<tr>
		<td> \b Definition</td>
		<td> \b Meaning</td>
	</tr>
	<tr>
		<td>NFLC_E_OK</td>
		<td>Succeeded (=0)</td>
	</tr>
	<tr>
		<td>NFLC_E_ERROR</td>
		<td>Failed</td>
	</tr>
	<tr>
		<td>NFLC_E_INVALID_PARAM</td>
		<td>Invalid parameter</td>
	</tr>
	<tr>
		<td>NFLC_E_DEVICE_NOT_FOUND</td>
		<td>Device not found</td>
	</tr>
	<tr>
		<td>NFLC_E_DEVICE_SERVICE_NOT_FOUND</td>
		<td>Service not found</td>
	</tr>
</table>
*/

typedef enum returnValue_ {
  NFLC_E_OK = 0,
  NFLC_E_ERROR = -1,
  NFLC_E_INVALID_PARAM = -2,
  NFLC_E_DEVICE_NOT_FOUND = -3,
  NFLC_E_DEVICE_SERVICE_NOT_FOUND = -4,
  NFLC_E_INVALID_WEBSOCKET_REQUEST = -5,
  NFLC_E_UNKNOWN_WEBSOCKET_REQUEST = -6,
  NFLC_E_OK_WARNING = -7,
  NFLC_E_INVALID_INSTANCE = -8,
  NFLC_E_FILESYSTEM_PATH_NOT_EXIST = -9,
  NFLC_E_FILESYSTEM_PATH_NOT_A_FOLDER = -10,
  NFLC_E_FILESYSTEM_PATH_NOT_A_FILE = -11,
  NFLC_E_FILESYSTEM_PATH_NOT_WRITABLE = -12,
  NFLC_E_NOT_STARTED = -13,
  NFLC_E_FILESYSTEM_FILE_NOT_EXIST = -14,
  NFLC_E_FILE_UPLOAD_IN_PROGRESS = -15,
  NFLC_E_UPLOAD_NOT_SUPPORTED = -16,
  NFLC_E_UPLOAD_OBJECT_RESTRICTED = -17,
  NFLC_E_UPLOAD_MIME_NOT_SUPPORTED = -18,
  NFLC_E_NOT_SUPPORT = -19,
  NFLC_E_STORAGE_LIMIT_REACHED = -20,
  NFLC_E_BUFFER_SIZE_TOO_LOW = -21
} returnValue;

typedef enum notifyEvent_ {
   NOTIFY_EVENT_NETWORK_DOWN = 0,
   NOTIFY_EVENT_NETWORK_UP,
   NOTIFY_EVENT_END
 } notifyEvent;

/* XMLBuffer is a pointer to memory that contains the data in xml format */

typedef slim_char *XMLBuffer;


#endif /* AHL_H */
