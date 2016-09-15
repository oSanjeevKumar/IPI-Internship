/*
 * icp_curl.h
 *
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef HTTP_CURL_H_
#define HTTP_CURL_H_



struct http_data_buffer
{
  slim_char * data;
  slim_word offset;
  slim_word size;
};


void*
http_curl_init_url(const slim_char * in_url);

slim_int
http_curl_fetch_data(void* in_arg, void* in_data, slim_int to_be_read);

void
http_curl_cleanup(void *in_arg);

void*
http_send_receive_init(slim_char* url);

slim_int
http_send_receive_buf(void* in_arg, void* buf, slim_int size);


#endif /* HTTP_CURL_H_ */
