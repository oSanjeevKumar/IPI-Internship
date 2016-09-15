/*
	arena.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/arena.h 15    05/12/28 12:07 Someya $ */

#ifndef SLIM_ARENA_H
#define SLIM_ARENA_H

SLIM_BEGIN_C_LINKAGE

struct TDataArena_ {
	TTree fArenaTree;
};
typedef struct TDataArena_ TDataArena;
typedef TTreeVisit TDataArenaVisit;

SLIM_END_C_LINKAGE
#endif /* SLIM_ARENA_H */
