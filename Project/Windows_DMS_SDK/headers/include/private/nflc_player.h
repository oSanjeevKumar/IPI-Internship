/*
 * nflc_player.h
 * Copyright (C) 2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_PLAYER_H
#define NFLC_PLAYER_H

#ifdef DLNA_SUPPORT_RUIPL

#ifdef __cplusplus
extern "C" {
#endif

typedef void *nflc_player;
/* Allocate player.  */
nflc_player
nflc_player_alloc(dlna_client_t *in_dc);

/* Allocate player.  */
void
nflc_player_free(nflc_player in_player);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DLNA_SUPPORT_RUIPL */

#endif /* NFLC_PLAYER_H */
