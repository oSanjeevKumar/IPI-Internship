/*
 * peer_random.c
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#include <dlna_peer.h>
#include <stdlib.h>

/* Start new sequence of pseudo-random.  */
void
dlna_set_random_seed (slim_int in_seed)
{
	srand ((unsigned int) in_seed);
}

/* Get pseudo-random between 0 and (in_n - 1).  */
slim_word
dlna_random (slim_word in_n)
{
	return rand () % in_n;
}
