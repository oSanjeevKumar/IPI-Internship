/*
 * http_code.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_HTTP_CODE_H
#define NFLC_HTTP_CODE_H

/* Minimum number placeholder.  */
#define  HTTP_STATUS_CODE_MIN               (100)

/* Informational.  */
#define  HTTP_100                           (100)
#define  HTTP_CONTINUE                      (100)
#define  HTTP_SWITCHING_PROTOCOLS           (101)

  /* Successful.  */
#define  HTTP_STATUS_CODE_200               (200)
#define  HTTP_OK                            (200)
#define  HTTP_CREATED                       (201)
#define  HTTP_ACCEPTED                      (202)
#define  HTTP_NO_AUTHORATATIVE_INFO         (203)
#define  HTTP_NO_CONTENT                    (204)
#define  HTTP_RESET_CONTENT                 (205)
#define  HTTP_PARTIAL_CONTENT               (206)

  /* Redirection.  */
#define  HTTP_STATUS_CODE_300               (300)
#define  HTTP_MULTIPLE_CHOICES              (300)
#define  HTTP_MOVED_PERMANENTLY             (301)
#define  HTTP_FOUND                         (302)
#define  HTTP_SEE_OTHER                     (303)

#define  HTTP_NOT_MODIFIED                  (304)
#define  HTTP_USE_PROXY                     (305)
#define  HTTP_TEMPORARY_REDIRECT            (307)

  /* Client error.  */
#define  HTTP_STATUS_CODE_400               (400)
#define  HTTP_BAD_REQUEST                   (400)
#define  HTTP_UNAUTHORIZED                  (401)
#define  HTTP_PAYMENT_REQUIRED              (402)
#define  HTTP_FORBIDDEN                     (403)
#define  HTTP_NOT_FOUND                     (404)
#define  HTTP_METHOD_NOT_ALLOWED            (405)
#define  HTTP_NOT_ACCEPTABLE                (406)
#define  HTTP_PROXY_AUTH_REQUIRED           (407)
#define  HTTP_REQUEST_TIMEOUT               (408)
#define  HTTP_CONFLICT                      (409)
#define  HTTP_GONE                          (410)
#define  HTTP_LENGTH_REQUIRED               (411)
#define  HTTP_PRECONDITION_FAILED           (412)
#define  HTTP_REQ_ENTITY_TOO_LARGE          (413)
#define  HTTP_REQUEST_URI_TOO_LONG          (414)
#define  HTTP_UNSUPPORTED_MEDIA_TYPE        (415)
#define  HTTP_REQUEST_RANGE_NOT_SATISFIABLE (416)
#define  HTTP_EXPECTATION_FAILED            (417)

  /* Server error. */
#define  HTTP_STATUS_CODE_500               (500)
#define  HTTP_INTERNAL_SERVER_ERROR         (500)
#define  HTTP_NOT_IMPLEMENTED               (501)
#define  HTTP_BAD_GATEWAY                   (502)
#define  HTTP_SERVICE_UNAVAILABLE           (503)
#define  HTTP_GATEWAY_TIMEOUT               (504)
#define  HTTP_VERSION_NOT_SUPPORTED         (505)

#define  HTTP_STATUS_CODE_MAX               (600)
#define  HTTP_STATUS_CODE_UNKNOWN           (-1)


#ifdef __cplusplus
extern "C" {
#endif

const slim_char *
http_code_str(slim_int in_code);

#ifdef __cplusplus
}
#endif

#endif /* NFLC_HTTP_CODE_H */
