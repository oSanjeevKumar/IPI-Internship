/*
 * peer_debug_msg.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef PEER_DEBUG_MSG_H_
#define PEER_DEBUG_MSG_H_
#ifdef DLNA_DEBUG_MSG
#undef DLNA_DEBUG_MSG
#endif
#define DLNA_DEBUG_MSG(x, arg)          \
           do {                         \
             if (x) {                   \
               dlnaDebugPrintfPeer arg; \
             }                          \
           } while (0)



#endif /* PEER_DEBUG_MSG_H_ */
