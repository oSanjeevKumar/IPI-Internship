/*
 * info_qt.h
 * Copyright (C) 2008 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* QuickTime file support for NFLC. */

#ifndef NFLC_INFO_QT_H
#define NFLC_INFO_QT_H

#include <info_qt_def.h> /* Import defs */

slim_bool register_media_info_qt(media_manager_t *mim);

slim_bool register_media_info_mov(media_manager_t *mim);

#endif /* NFLC_INFO_QT_H */
