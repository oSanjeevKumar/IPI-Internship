/*
 * dlna_peer_list.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005, 2006 IP Infusion, Inc. All Rights Reserved.  */

/* Generic linked list macros.  */

#ifndef NFLC_PEER_LIST_H
#define NFLC_PEER_LIST_H

/* Declaration of linked list.  */
#define List(T)                                                               \
  struct {                                                                    \
    T head;                                                                   \
    T tail;                                                                   \
    slim_int count;                                                           \
  }

/* Declaration of linked list.  */
#define ListNamed(T, N)                                                       \
  struct N {                                                                  \
    T head;                                                                   \
    T tail;                                                                   \
    slim_int count;                                                           \
  }

/* List initialization macro.  */
#define ListInit(L)                                                           \
  do {                                                                        \
    (L)->head = slim_nil;                                                     \
    (L)->tail = slim_nil;                                                     \
    (L)->count = 0;                                                           \
  } while (0)

/* List add macro.  */
#define ListAdd(L,N)                                                          \
  do {                                                                        \
    if((N)->next || (N)->prev){                                              \
      DLNA_DEBUG_MSG(IS_DEBUG_DLNA_ERROR, ("ERROR: ListAdd->pointer_not_null.\n"));  \
      break;                                                                  \
    }                                                                         \
    (N)->next = slim_nil;                                                     \
    (N)->prev = (L)->tail;                                                    \
    if (! (L)->head) {                                                        \
      (L)->head = (N);                                                        \
    } else {                                                                  \
      (L)->tail->next = (N);                                                  \
    }                                                                         \
    (L)->tail = (N);                                                          \
    (L)->count++;                                                             \
  } while (0)

/* List add head macro.  */
#define ListAddHead(L,N)                                                      \
  do {                                                                        \
    if((N)->next || (N)->prev){                                              \
      DLNA_DEBUG_MSG(IS_DEBUG_DLNA_ERROR, ("ERROR: ListAddHead->pointer_not_null.\n"));  \
      break;                                                                  \
    }                                                                         \
    (N)->prev = slim_nil;                                                     \
    (N)->next = (L)->head;                                                    \
    if (! (L)->tail)                                                          \
      (L)->tail = (N);                                                        \
    else                                                                      \
      (L)->head->prev = (N);                                                  \
    (L)->head = (N);                                                          \
    (L)->count++;                                                             \
} while (0)

/* List insert macro.  */
#define ListInsert(L,P,N)                                                     \
  do {                                                                        \
    if((N)->next || (N)->prev){                                               \
      DLNA_DEBUG_MSG(IS_DEBUG_DLNA_ERROR, ("ERROR: ListInsert->pointer_not_null.\n"));  \
      break;                                                                  \
    }                                                                         \
    (N)->prev = (P);                                                          \
    if (P) {                                                                  \
      if ((P)->next) {                                                        \
        (P)->next->prev = (N);                                                \
      } else {                                                                \
        (L)->tail = (N);                                                      \
      }                                                                       \
      (N)->next = (P)->next;                                                  \
      (P)->next = (N);                                                        \
    } else {                                                                  \
      if ((L)->head) {                                                        \
        (L)->head->prev = (N);                                                \
      } else {                                                                \
        (L)->tail = (N);                                                      \
      }                                                                       \
      (N)->next = (L)->head;                                                  \
      (L)->head = (N);                                                        \
    }                                                                         \
    (L)->count++;                                                             \
  } while (0)

/* List delete macro.  */
#define ListDelete(L,N)                                                       \
  do {                                                                        \
    if ((N)->prev || (N)->next || (N) == (L)->head) {                         \
      if ((N)->prev) {                                                        \
        (N)->prev->next = (N)->next;                                          \
      } else {                                                                \
        (L)->head = (N)->next;                                                \
      }                                                                       \
      if ((N)->next) {                                                        \
        (N)->next->prev = (N)->prev;                                          \
      } else {                                                                \
        (L)->tail = (N)->prev;                                                \
      }                                                                       \
      (N)->next = slim_nil;                                                   \
      (N)->prev = slim_nil;                                                   \
      (L)->count--;                                                           \
    }                                                                         \
  } while (0)

#define ListLoop(L,N)                                                         \
  for ((N) = (L)->head; (N); (N) = (N)->next)

#define ListLoopForDel(L, N, M)                                               \
  for ((N) = (L)->head, ((N) ? ((M) = (N)->next): (M = N)); (N);              \
       (N) = (M), ((M) ? ((M) = (M)->next) : (M)))

#define ListLoopForDelBackward(L, N, M)                                       \
  for ((N) = (L)->tail, ((N) ? ((M) = (N)->prev): (M = N)); (N);              \
       (N) = (M), ((M) ? ((M) = (M)->prev) : (M)))

#define ListEmpty(L)                                                          \
  (! (L)->head)

#define ListHead(L)                                                           \
  ((L)->head)

#define ListTail(L)                                                           \
  ((L)->tail)

#define ListCount(L)                                                          \
  ((L)->count)

#endif /* NFLC_PEER_LIST_H */
