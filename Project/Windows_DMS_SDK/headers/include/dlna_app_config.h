/*
 * dlna_app_config.h
 * Copyright (C) 2009-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DLNA_APP_CONFIG_H
#define DLNA_APP_CONFIG_H

#include <dlna_version.h>

#define DMS_VERSION_FILENAME	"version.txt"

/* SMM: Storage Manager message FIFO, Specify FIFO full path */
#define DEFAULT_STORAGE_MESSAGE_FIFO	"\\tmp\\dms_ipc"
#define INOTIFY_EVENT_LIST_SEPARATOR        "\x01"
#define INOTIFY_EVENT_LIST_SEPARATOR_CHAR   '\x01'

/* SMM: SQLITE configuration */
#if 0
#undef SQLITE_PERFORMANCE_EVAL
#undef SQLITE_QUERY_EXPLAIN
#define SQLITE_ENABLE_WAL
#undef SQLITE_ENABLE_JOURNAL_MODE_PERSIST
#ifdef SQLITE_ENABLE_WAL
#define SQLITE_ENABLE_WAL_CHECKPOINT
#define SQLITE_CHECKPOINTING_OFFSET					1000
#endif /* SQLITE_ENABLE_WAL */
#define DMS_ENABLE_SET_MEMORY_LIMIT_FOR_SQLITE
#ifdef DMS_ENABLE_SET_MEMORY_LIMIT_FOR_SQLITE
#define DMS_MEMORY_SIZE_LIMIT_FOR_SQLITE			(2*1024*1024)
#define DMS_USE_SOFT_HEAP_FOR_SQLITE
#endif /* DMS_ENABLE_SET_MEMORY_LIMIT_FOR_SQLITE */
#define SQLITE_DATABASE_DEFAULT_CACHE_SIZE			1000
#define SQLITE_ATTACH_DATABASE_DEFAULT_CACHE_SIZE	500
#define SQLITE_ENABLE_INDEXES
#define SQLITE_USE_ADDITIONAL_INDEXING_DB_CONNECTION
#define SQLITE_MAX_INDEXING_BUSY_RETRIES			50
#define SQLITE_MAX_BUSY_RETRIES						50
#endif

#ifdef HAVE_SIGMA
#define PAL_DMP_DIR			"\\mnt\\nfs\\dlna\\DMP"
#define PAL_DMP_DATA_DIR	"\\mnt\\nfs\\dlna\\data"
#define PAL_DMP_ROOT_DIR	"\\mnt\\nfs\\dlna\\media"
#else
#ifdef DMP_ENABLE_RELATIVE_PATH
#define PAL_DMP_DIR			".\\DMP"
#define PAL_DMP_DATA_DIR	".\\DMP\\data"
#define PAL_DMP_ROOT_DIR	".\\DMP\\media"
#else /* DMS_ENABLE_RELATIVE_PATH */
#define PAL_DMP_DIR			"\\usr\\local\\share\\dlna\\DMP"
#define PAL_DMP_DATA_DIR	"\\usr\\local\\share\\dlna\\DMP\\data"
#define PAL_DMP_ROOT_DIR	"\\usr\\local\\share\\dlna\\DMP\\media"
#endif /* DMP_ENABLE_RELATIVE_PATH */
#endif

/* DMPR configure macros. */

/* DMPr root directory of contents. */
#define DMPR_ROOT_DIR	"\\usr\\local\\share\\dlna"

/* DMS configuration directory (which will store XML files). */
#define DMPR_CONFIG_DIR	"\\usr\\local\\share\\dlna\\xml"

/* DMPr XML device description file name. */
#define DMPR_DESCRIPTION_FILE_NAME	"dmpr.xml"

/* DMPr UPnP port number. */
#define DMPR_UPNP_PORT	12387


#endif /* DLNA_APP_CONFIG_H */
