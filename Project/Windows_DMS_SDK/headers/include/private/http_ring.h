/*
 * http_ring.h
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

#ifndef NFLC_HTTP_RING_H
#define NFLC_HTTP_RING_H

/*
 * Ring buffer chunk size.  This should be same as HTTP session's read
 * buffer size for efficiency.
 */
#define HTTP_RING_BUFFER_SIZE           (1024 * 1024)

/* Ring buffer for HTTP.  */
struct http_ring_buffer
{
  /* Linked list.  */
  struct http_ring_buffer *prev;
  struct http_ring_buffer *next;

  /* Buffer size.  */
  slim_char buf[HTTP_RING_BUFFER_SIZE];

  /* Current read pointer.  */
  slim_word rcp;

  /* Current write pointer.  */
  slim_word wcp;

  /* if this buffer is used. */
  slim_bool used;
};

/* Ring read macro.  */
#define RING_READ_LENGTH(R)              (((R)->wcp) - ((R)->rcp))
#define RING_READ_BUFFER(R)              (((R)->buf) + ((R)->rcp))
#define RING_READ_FORWARD(R,L)           ((R)->rcp += (L))

/* Ring write macro.  */
#define RING_WRITE_LENGTH(R)             (HTTP_RING_BUFFER_SIZE - (R)->wcp)
#define RING_WRITE_BUFFER(R)             (((R)->buf) + ((R)->wcp))
#define RING_WRITE_FORWARD(R,L)          ((R)->wcp += (L))

/* Ring buffer master.  */
struct http_ring_buffer_master
{
  /* Ring buffer list.  */
  List (struct http_ring_buffer *) ring;

  /* Number of ring buffer.  */
  slim_word num_ring;

  /* Total buffer size.  */
  slim_int total_size;

  /* Ring buffer threshold size.  */
  slim_int threshold_size;
  
  /* Number of all buffers */
  slim_int buffer_count;
  
  /* Stock of buffers */
  struct http_ring_buffer **buffer_list;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct http_ring_buffer_master *
http_ring_buffer_master_alloc (void);

void
http_ring_buffer_master_free (struct http_ring_buffer_master *self);

slim_int
http_ring_buffer_read (struct http_ring_buffer_master *master,
                       slim_byte *out_buf, slim_int in_len, 
                       slim_bool is_check_delayed_close, slim_bool *out_delayed_close);

slim_int
http_ring_buffer_write (struct http_ring_buffer_master *master, slim_byte *in_buf,
                        slim_int in_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_HTTP_RING_H */
