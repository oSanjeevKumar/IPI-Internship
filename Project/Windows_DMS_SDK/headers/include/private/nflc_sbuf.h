/*
 * nflc_sbuf.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005, 2006 IP Infusion, Inc. All Rights Reserved.  */

/* String buffer.  */

#ifndef NFLC_SBUF_H
#define NFLC_SBUF_H

#include <dlna_int64.h>

struct sbuf
{
  /* Buffer.  */
  slim_char *buf;
  
  /* Current length.  */
  slim_word size;

  /* Allocated length.  */
  slim_word alloc;
};

/* Default allocation size.  */
#define SBUF_ALLOC_SIZE        (512)

/* Buffer size for number.  */
#define SBUF_NUM_BUFFER_SIZE   (20)

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct sbuf *
sbuf_alloc (void);

void
sbuf_free (struct sbuf *sbuf);

void
sbuf_free_buffer (struct sbuf *sbuf);

void
sbuf_init (struct sbuf *sbuf);

void
sbuf_reset (struct sbuf *sbuf);

slim_int
sbuf_resize(struct sbuf * buf, slim_word new_size);

slim_int
sbuf_ensure (struct sbuf *sbuf, slim_word new_size);

slim_int
sbuf_add (struct sbuf *sbuf, const slim_char *buf, slim_word len);

slim_int
sbuf_add_char (struct sbuf *sbuf, slim_char c);

slim_int
sbuf_add_str (struct sbuf *sbuf, const slim_char *str);

slim_int
sbuf_add_num (struct sbuf *sbuf, slim_word num);

slim_int
sbuf_add_num64 (struct sbuf *sbuf, dlna_uint64 *in_src);

slim_char *
sbuf_detach (struct sbuf *sbuf);

void
sbuf_attach (struct sbuf *sbuf, slim_char *buf, slim_word size);

slim_int
sbuf_assign (struct sbuf *sbuf, slim_char *buf,  slim_word len);

slim_int
sbuf_assign_str (struct sbuf *sbuf, slim_char *str);

void
sbuf_delete (struct sbuf *sbuf, slim_word index, slim_word len);

slim_int
sbuf_insert (struct sbuf *sbuf, slim_char *buf, slim_word len, slim_word index);

slim_int
sbuf_add_escape (struct sbuf *sbuf, slim_char *buf);

slim_word
sbuf_get_begin (struct sbuf *sbuf, slim_char *buf, slim_word len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SBUF_H */
