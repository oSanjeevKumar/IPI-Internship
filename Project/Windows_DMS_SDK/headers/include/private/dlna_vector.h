/*
 * dlna_vector.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_VECTOR_H
#define NFLC_VECTOR_H

/* Vector structure. */
struct _vector 
{
  /* Max number of used slot.  */
  slim_int max;

  /* Number of allocated slot.  */
  slim_int alloced;

  /* Index to data.  */
  void **index;
};

/* Typedef it.  */
typedef struct _vector *vector;

#define VECTOR_MIN_SIZE 8

/* Macros.  */
#define VectorSlot(V,I)         ((V)->index[(I)])
#define VectorMax(V)            ((V)->max)
#define VectorReset(V)          ((V)->max = 0)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Prototypes. */
vector vector_init (slim_int size);
slim_bool vector_ensure (vector v, slim_int num);
slim_int vector_empty_slot (vector v);
slim_int vector_set (vector v, void *val);
slim_int vector_set_index (vector v, slim_int i, void *val);
void *vector_lookup_index (vector v, slim_int i);
void vector_unset (vector v, slim_int i);
slim_int vector_count (vector v);
void vector_free (vector v);
vector vector_copy (vector v);
void vector_add (vector dest, vector src);
void vector_dup (vector dest, vector src);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_VECTOR_H */
