/*
	mmemory.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

#ifndef SLIM_MMEMORY_H
#define SLIM_MMEMORY_H

/*
 * 'mmemory.h' is the interface file between "slim core" and "memory module".
 * This file depends on "memory module".
 */

#include <slim/tank/tmemory.h>

#ifdef SLIM_BUILDING_LIBRARIES
#include <slim/private/tank/tmemory.h>
#endif /* defined(SLIM_BUILDING_LIBRARIES) */

#ifdef SYSTEM_FREE
/* TODO: This section is a very dirty workaround to fix nf3_npp_dsound.c compilation error. */
#include <slim/private/tank/tmemory.h>
#endif /* SYSTEM_FREE */

/* mem_resolve.c */
SLIM_BEGIN_C_LINKAGE
slim_bool slim_memory_init_global_variables(void);
void slim_memory_tidy_global_variables(void);
SLIM_END_C_LINKAGE

#endif /* !defined(SLIM_MMEMORY_H) */
