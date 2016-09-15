/*
 * peer_memory.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

/* SLIM peer FILE APIs.  */

#include <dlna_peer.h>
#include <stdlib.h>

void *
dlna_memory_zeroalloc(slim_int in_size)
{
  return calloc (1, in_size);
}
