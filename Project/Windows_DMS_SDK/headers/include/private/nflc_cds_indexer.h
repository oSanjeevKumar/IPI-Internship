
/*
 * \file nflc_cds_indexer.h
 *
 * Copyright (C) 2012 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 *
 *    __
 *  /    \
 * | STOP |
 *  \ __ /
 *    ||
 *    ||
 *    ||
 *    ||
 *    ||
 *  ~~~~~~ Before you put something here, please keep in mind the file organization:
 *  - Headers
 *  - Macros
 *  - Type definitions
 *  - Declarations for global functions
 *
 *  Help us fight against global warming, put your comments in d'oxygen.
 */

#ifndef NFLC_CDS_INDEXER_H
#define NFLC_CDS_INDEXER_H

#include <dlna_peer.h>
#include <nflc_contents.h>
#include <nflc_cds_database.h>


/**
 * \brief CDS publisher error codes.
 *
 * Further information on an error is provided via standard error stream.
 */
enum cds_indexer_return {
	CDS_INDEXER_ERROR_OK,             /**< All went OK. */
	CDS_INDEXER_ERROR_STOPPED,        /**< Attempt to use stopped indexer. */
	CDS_INDEXER_ERROR_ITEM_EXISTS,    /**< Attempt to insert an item more then once. */
	CDS_INDEXER_ERROR_OUT_OF_MEMORY,  /**< Memory allocation failed. */
	CDS_INDEXER_ERROR_DATABASE,       /**< Database call returned an error. */
	CDS_INDEXER_ERROR_INVALID_PARAM,  /**< Invalid parameter was passed to a function. */
	CDS_INDEXER_ERROR_INSTANCE        /**< The indexer is Invalid parameter was passed to a function. */
};

typedef enum cds_indexer_return cds_indexer_return_t;


enum cds_indexer_priority {
	CDS_INDEXER_PRIO_REALTIME,
	CDS_INDEXER_PRIO_HIGH,
	CDS_INDEXER_PRIO_NORMAL,
	CDS_INDEXER_PRIO_LOW,
	CDS_INDEXER_PRIO_COUNT
};

typedef enum cds_indexer_priority cds_indexer_priority_t;

typedef void (*INDEXER_UPDATE_FUNC)(cds_database_info* database, slim_int db_id, slim_object user_data);

cds_indexer_return_t
cds_indexer_alloc(cm_t* cm);

cds_indexer_return_t
cds_indexer_start();

cds_indexer_return_t
cds_indexer_parse_item(cds_database_info* database, slim_int parent_id,
		slim_char* title, slim_char* url, slim_char* ext_id,
		INDEXER_UPDATE_FUNC func, slim_object user_data, cds_indexer_priority_t priority);

cds_indexer_return_t
cds_indexer_stop();

#endif
