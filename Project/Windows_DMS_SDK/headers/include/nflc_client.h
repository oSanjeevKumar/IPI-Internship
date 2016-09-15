/*
 * nflc_client.h
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef _NFLC_CLIENT_H
#define _NFLC_CLIENT_H
#include <dlna_peer.h>
#include <dlna_client.h>

/* Prototypes.  */
#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

/* Get dlna Object type*/
DLNA_API slim_word
dlnaGetNFLCObjectType(dlna_object_t *self);

/* Check DLNA Object type*/
DLNA_API slim_bool
dlnaNFLCObjectTypeIs(dlna_object_t *self, slim_word type);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _NFLC_CLIENT_H */
