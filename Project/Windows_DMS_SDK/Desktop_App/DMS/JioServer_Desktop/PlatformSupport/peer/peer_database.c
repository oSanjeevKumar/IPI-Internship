/* peer_database.c
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD., whether the whole or part 
 * of the source code including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
 
#include <dlna_peer.h>
#include <dlna_memory.h>
#include <peer_database.h>

#ifdef DLNA_DB_MEMSYS5_ALLOCATOR
slim_byte *memsys5MemBuf;
#endif /* DLNA_DB_MEMSYS5_ALLOCATOR */
#ifdef DLNA_DB_SCRATCH_MEMORY_CONFIG
slim_byte *scratchMemBuf;
#endif /* DLNA_DB_SCRATCH_MEMORY_CONFIG */
#ifdef DLNA_DB_PAGE_CACHE_MEMORY_CONFIG
slim_byte *pageCacheMemBuf;
#endif /* DLNA_DB_PAGE_CACHE_MEMORY_CONFIG */

#ifdef DLNA_DB_ENABLE_ANALYZE
  #undef DLNA_DB_ENABLE_ANALYZE
#endif

#ifdef DLNA_DB_MEMSYS5_ALLOCATOR
slim_int
dlnaDatabaseConfigureMemsys5Allocator(slim_int mem_size, slim_int min_alloc_size) {
  slim_int rc = DLNA_DB_ERROR;

  memsys5MemBuf = dlna_memory_alloc(mem_size);
  if(memsys5MemBuf) {
    rc = sqlite3_config(SQLITE_CONFIG_HEAP, memsys5MemBuf, mem_size, min_alloc_size);
    if(SQLITE_OK != rc) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to set memsys5 memory!");
    }
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to allocate memsys5 memory buffer!");
  }

  return rc;
}
#endif /* DLNA_DB_MEMSYS5_ALLOCATOR */

#ifdef DLNA_DB_LOOKASIDE_ALLOCATOR_CONFIG
slim_int
dlnaDatabaseConfigureLookasideAllocator(slim_int slot_size, slim_int slot_count) {
  slim_int rc = DLNA_DB_ERROR;

  rc = sqlite3_config(SQLITE_CONFIG_LOOKASIDE, slot_size, slot_count);
  if(SQLITE_OK != rc) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to configure lookaside memory allocator!");
  }

  return rc;
}
#endif /* DLNA_DB_LOOKASIDE_ALLOCATOR_CONFIG */

#ifdef DLNA_DB_SCRATCH_MEMORY_CONFIG
slim_int
dlnaDatabaseConfigureScratchAllocator(slim_int single_allocation_size, slim_int simultaneous_alloc_count) {
  slim_int rc = DLNA_DB_ERROR;

  scratchMemBuf = dlna_memory_alloc(single_allocation_size * simultaneous_alloc_count);
  if(scratchMemBuf) {
    rc = sqlite3_config(SQLITE_CONFIG_SCRATCH, scratchMemBuf, single_allocation_size, simultaneous_alloc_count);
    if(SQLITE_OK != rc) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to set the scratch memory buffer!");
    }
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to allocate scratch memory buffer!");
  }

  return rc;
}
#endif /* DLNA_DB_SCRATCH_MEMORY_CONFIG */

#ifdef DLNA_DB_PAGE_CACHE_MEMORY_CONFIG
slim_int
dlnaDatabaseConfigurePageCacheAllocator(slim_int single_page_cache_size, slim_int page_cache_count) {
  slim_int rc = DLNA_DB_ERROR;

  pageCacheMemBuf = dlna_memory_alloc(single_page_cache_size * page_cache_count);
  if(pageCacheMemBuf) {
    rc = sqlite3_config(SQLITE_CONFIG_PAGECACHE, pageCacheMemBuf, single_page_cache_size, page_cache_count);
    if(SQLITE_OK != rc) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to set the page cache memory buffer!");
    }
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to allocate page cache memory buffer!");
  }

  return rc;
}
#endif /* DLNA_DB_PAGE_CACHE_MEMORY_CONFIG */

slim_int
dlnaDatabaseInitializePeer(void)
{
  slim_int rc = DLNA_DB_OK;
  rc = sqlite3_initialize();
  return rc;
}

void
dlnaDatabaseFinalizePeer(void)
{
#ifdef DLNA_DB_MEMSYS5_ALLOCATOR
  if(memsys5MemBuf) {
    dlna_memory_free(memsys5MemBuf);
  }
#endif /* DLNA_DB_MEMSYS5_ALLOCATOR */
#ifdef DLNA_DB_SCRATCH_MEMORY_CONFIG
  if(scratchMemBuf) {
    dlna_memory_free(scratchMemBuf);
  }
#endif /* DLNA_DB_SCRATCH_MEMORY_CONFIG */
#ifdef DLNA_DB_PAGE_CACHE_MEMORY_CONFIG
  if(pageCacheMemBuf) {
    dlna_memory_free(pageCacheMemBuf);
  }
#endif /* DLNA_DB_PAGE_CACHE_MEMORY_CONFIG */

  sqlite3_shutdown();
}

dlna_db_handle 
dlnaDatabaseCreatePeer(slim_char* in_path, slim_int flags)
{
  slim_int ret = DLNA_DB_OK;
  sqlite3 *handle;

  if (!in_path) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] DB Destination is UNDEFINED!");
      return slim_nil;
  }

  ret = sqlite3_open_v2((char*)in_path, &handle, flags, NULL);
  if(ret) {
      dlnaDatabaseClosePeer((dlna_db_handle)handle);
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] DB Create Connection FAILED!");
      return slim_nil;
  }
  return (dlna_db_handle)handle;
}

dlna_db_handle
dlnaDatabaseOpenPeer(slim_char* in_path, slim_int flags)
{
  slim_int ret = DLNA_DB_OK;
  sqlite3 *handle = 0;
	
  if (!in_path) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] DB Destination is UNDEFINED!");
      return slim_nil;
  }

  ret = sqlite3_open_v2((char*)in_path, &handle, flags, NULL);
  if(ret) {
      sqlite3_close(handle);
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] DB Open Connection FAILED, Probably Database Not Created Yet!");
      return slim_nil;
  }
  return (dlna_db_handle)handle;
}

slim_int
dlnaDatabaseClosePeer(dlna_db_handle handle)
{
  return sqlite3_close((sqlite3*)handle);
}

void*
dlnaDatabaseMemoryMallocPeer(slim_int in_size)
{
  return sqlite3_malloc(in_size);
}

void*
dlnaDatabaseMemoryReallocPeer(void* in_mem, slim_int in_size)
{
  return sqlite3_realloc(in_mem, in_size);
}

void
dlnaDatabaseMemoryFreePeer(void *in_mem)
{
  sqlite3_free(in_mem);
}

slim_char*
dlnaDatabaseFormatQueryStringPeer(slim_char *in_query, va_list ap)
{
  return (slim_char *)sqlite3_vmprintf((const char*)in_query, ap);
}

slim_int 
dlnaDatabaseExecuteQueryPeer(dlna_db_handle handle, const slim_char* query, ...)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *err, *tmp;
  va_list ap;
  DLNA_FUNC_ENTER(dlnaDatabaseExecuteQueryPeer);
  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseExecuteQueryPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!query) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseExecuteQueryPeer] DB Query is NIL");
      return DLNA_DB_ERROR;
  }

  va_start(ap, query);
  tmp = (slim_char *)sqlite3_vmprintf((const char*)query, ap);
  va_end(ap);

  ret = sqlite3_exec((sqlite3*)handle, (const char *)tmp, NULL, NULL, (char **)&err);
  if(ret != SQLITE_OK) {
      if (err != NULL) {
              sqlite3_free(err);
      }
  }
  sqlite3_free(tmp);
  DLNA_FUNC_EXIT(dlnaDatabaseExecuteQueryPeer);
  return ret;
}

slim_int 
dlnaDatabasePrepareStatementPeer(dlna_db_handle handle, dlna_db_stmt *ppStmt, const slim_char* query, ...)
{
  slim_char *tmp;
  const slim_char* tail;
  va_list ap;
  slim_int ret = DLNA_DB_OK;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabasePrepareStatementPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }
  if (!query) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabasePrepareStatementPeer] DB Query is NIL");
      return DLNA_DB_ERROR;
  }

  va_start(ap, query);
  tmp = (slim_char *)sqlite3_vmprintf((const char *)query, ap);
  va_end(ap);

  ret = sqlite3_prepare_v2((sqlite3*)handle, (const char *)tmp, -1, (sqlite3_stmt**)ppStmt, (const char **)&tail);
  sqlite3_free(tmp);
#ifdef NFLC_ENABLE_DATABASE_QUERYPLAN
  if (ret == SQLITE_OK) {
      dlnaDatabaseExplainQueryPlanPeer(*ppStmt);
  }
#endif /*NFLC_ENABLE_DATABASE_QUERYPLAN*/
  return ret;
}

slim_int 
dlnaDatabaseAttachConnectionPeer(dlna_db_handle handle, slim_char* database_filepath, slim_char* database_name)
{
  slim_char *query = slim_nil;
  slim_int ret = DLNA_DB_OK;


  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseAttachConnectionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!database_filepath) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Database to be Attached destination is NIL");
      return DLNA_DB_ERROR;
  }

  if (!database_name) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Database to be Attached Alias is UNSPECIFIED");
      return DLNA_DB_ERROR;
  }

  query = SLIM_T("ATTACH '%q' AS '%q';");
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, database_filepath, database_name);
  return ret;
}

slim_int
dlnaDatabaseDetachConnectionPeer(dlna_db_handle handle, slim_char* database_name)
{
  slim_char *query = slim_nil;
  slim_int ret = DLNA_DB_OK;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseDetachConnectionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!database_name) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Database to be Detached Alias is UNSPECIFIED");
      return DLNA_DB_ERROR;
  }

  query = SLIM_T("DETACH '%q';");
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, database_name);
  return ret;
}

slim_int
dlnaDatabaseSetJournalModePeer(dlna_db_handle handle, slim_int journal_mode)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseDetachConnectionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if ((journal_mode == DLNA_DB_JOURNAL_MODE_ROLLBACK) || (journal_mode == DLNA_DB_JOURNAL_MODE_ROLLBACK_DELETE)) {
      query = (slim_char*)"PRAGMA journal_mode=DELETE;";
  } else if (journal_mode == DLNA_DB_JOURNAL_MODE_ROLLBACK_TRUNCATE) {
      query = (slim_char*)"PRAGMA journal_mode=TRUNCATE;";
  } else if (journal_mode == DLNA_DB_JOURNAL_MODE_ROLLBACK_PERSIST) {
      query = (slim_char*)"PRAGMA journal_mode=PERSIST;";
  } else if (journal_mode == DLNA_DB_JOURNAL_MODE_ROLLBACK_MEMORY) {
      query = (slim_char*)"PRAGMA journal_mode=MEMORY;";
#ifdef DLNA_DB_SUPPORT_JOURNAL_MODE_WAL
  } else if (journal_mode == DLNA_DB_JOURNAL_MODE_WAL) {
      query = (slim_char*)"PRAGMA journal_mode=WAL;";
#else /*DLNA_DB_SUPPORT_JOURNAL_MODE_WAL*/
  } else if (journal_mode == DLNA_DB_JOURNAL_MODE_WAL) {
      query = (slim_char*)"PRAGMA journal_mode=DELETE;";
#endif /*DLNA_DB_SUPPORT_JOURNAL_MODE_WAL*/
  } else if (journal_mode == DLNA_DB_JOURNAL_MODE_OFF) {
      query = (slim_char*)"PRAGMA journal_mode=OFF;";
  }

  ret = dlnaDatabaseExecuteQueryPeer(handle, query);
  return ret;
}

slim_int 
dlnaDatabaseCreateTablePeer(dlna_db_handle handle, slim_char* in_query) 
{
  slim_int ret = DLNA_DB_OK;
  char* err;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseCreateTablePeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!in_query) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseCreateTablePeer] DB Query is NIL");
      return DLNA_DB_ERROR;
  }

  ret = sqlite3_exec((sqlite3*)handle, (char*)in_query, NULL, NULL, &err);
  if(ret != DLNA_DB_OK) {
      if (err != NULL) {
          sqlite3_free(err);
      }
  }

  return ret;
}

slim_int
dlnaDatabaseCreateTriggerPeer(dlna_db_handle handle, slim_char* in_query)
{
  slim_int ret = DLNA_DB_OK;
  char* err;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseCreateTriggerPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!in_query) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseCreateTriggerPeer] DB Query is NIL");
      return DLNA_DB_ERROR;
  }

  ret = sqlite3_exec((sqlite3*)handle, (char*)in_query, NULL, NULL, &err);
  if(ret != DLNA_DB_OK) {
      if (err != NULL) {
          sqlite3_free(err);
      }
  }

  return ret;
}

slim_int 
dlnaDatabaseDropTablePeer(dlna_db_handle handle, slim_char* table)
{
  slim_char* query = slim_nil;
  slim_int ret = DLNA_DB_OK;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseDropTablePeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!table) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Table to be DROPPED is UNDEFINED");
      return DLNA_DB_ERROR;
  }

  query = SLIM_T("DROP TABLE IF EXISTS '%q';");
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, table);
  return ret;
}

slim_int
dlnaDatabaseCreateIndexPeer(dlna_db_handle handle, slim_char* table, slim_char* index, slim_char* in_column_to_be_indexed)
{
  slim_char* query = slim_nil;
  slim_int ret = DLNA_DB_OK;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseCreateIndexPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!table) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseCreateIndexPeer] Table Name is UNDEFINED");
      return DLNA_DB_ERROR;
  }

  if (!index) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Index to be CREATED is UNSPECIFIED");
      return DLNA_DB_ERROR;
  }

  if (!in_column_to_be_indexed) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] COLUMN For which Index is to be CREATED is UNSPECIFIED");
      return DLNA_DB_ERROR;
  }

  query = SLIM_T("CREATE INDEX IF NOT EXISTS '%q' ON '%q' ('%q');");
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, index, table, in_column_to_be_indexed);
  return ret;
}

slim_int 
dlnaDatabaseDropIndexPeer(dlna_db_handle handle, slim_char* table, slim_char* index)
{
  slim_char* query = slim_nil;
  slim_int ret = DLNA_DB_OK;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseDropIndexPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  if (!table) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseDropIndexPeer] Table Name is UNDEFINED");
      return DLNA_DB_ERROR;
  }

  if (!index) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Index to be DROPPED is UNSPECIFIED");
      return DLNA_DB_ERROR;
  }

  query = SLIM_T("DROP INDEX IF EXISTS '%q' ON '%q';");
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, index, table);
  return ret;
}

slim_int
dlnaDatabaseExecuteStepPeer(dlna_db_stmt in_stmt)
{
#ifdef DLNA_DB_ENABLE_SQLITE_LOCK_DELAY
  slim_int rc = SQLITE_OK;

  rc = sqlite3_step((sqlite3_stmt*)in_stmt);
  while(rc == SQLITE_LOCKED) {
      dlnaThreadSleepPeer(100);
      rc = sqlite3_step((sqlite3_stmt*)in_stmt);
  }
  return rc;
#else /*DLNA_DB_ENABLE_SQLITE_LOCK_DELAY*/
  return sqlite3_step((sqlite3_stmt*)in_stmt);
#endif /*DLNA_DB_ENABLE_SQLITE_LOCK_DELAY*/

}

slim_int
dlnaDatabaseGetIntegerTypeColumnValuePeer(dlna_db_stmt in_stmt, slim_int column)
{
  return sqlite3_column_int((sqlite3_stmt*)in_stmt, column);
}

slim_char*
dlnaDatabaseGetTextTypeColumnValuePeer(dlna_db_stmt in_stmt, slim_int column)
{
  slim_char* col_value = slim_nil;

  col_value = (slim_char*)sqlite3_column_text((sqlite3_stmt*)in_stmt, column);
  if (col_value) {
      if (dlna_strcmp(col_value, (slim_char*)"(NULL)")) {
          return col_value;
      } else {
          return slim_nil;
      }
  }
  return col_value;
}

slim_int 
dlnaDatabaseFinalizeStatementPeer(dlna_db_stmt in_stmt)
{
  return sqlite3_finalize((sqlite3_stmt*)in_stmt);
}

slim_int 
dlnaDatabaseGetLastInsertedRowIDPeer(dlna_db_handle handle)
{
  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetLastInsertedRowIDPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  return sqlite3_last_insert_rowid((sqlite3*)handle);
}

#ifdef DLNA_DB_SUPPORT_JOURNAL_MODE_WAL
slim_int
dlnaDatabaseEnableCheckpointPeer(dlna_db_handle handle)
{
  slim_int ret = DLNA_DB_OK;
  slim_int pnLog = 0;
  slim_int pnCkpt = 0;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseEnableCheckpointPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

//  ret = sqlite3_wal_checkpoint((sqlite3*)handle, "");
  ret = sqlite3_wal_checkpoint_v2(handle, NULL, SQLITE_CHECKPOINT_PASSIVE, &pnLog, &pnCkpt);
  if (ret != DLNA_DB_OK) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Checkpointing Failed, %s", dlnaDatabaseGetErrorMsgPeer(handle));
      return ret;
  }
  return ret;
}
#endif /*DLNA_DB_SUPPORT_JOURNAL_MODE_WAL*/

slim_int
dlnaDatabaseGetTableRowCountPeer(dlna_db_handle handle, slim_char* table, slim_int *count)
{
  *count = 0;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetTableRowCount] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }
  if (!table) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetTableRowCount] Table is UNSPECIFIED");
      return DLNA_DB_ERROR;
  }

  /*TODO:AS+ TBD*/

  return DLNA_DB_OK;
}

/* New Column Limitations:
    * The column may not have a PRIMARY KEY or UNIQUE constraint.
    * The column may not have a default value of CURRENT_TIME, CURRENT_DATE, CURRENT_TIMESTAMP, or an expression in parentheses.
    * If a NOT NULL constraint is specified, then the column must have a default value other than NULL.
    * If foreign key constraints are enabled and a column with a REFERENCES clause is added, the column must have a default value of NULL. 
    
    *NOTE: Protect the Addition of a Column with a Transaction Begin and Commit or ThreadLock and Unlock to avoid unexpected modifications to the database when a new column is created
*/
slim_int
dlnaDatabaseAddColumnPeer(dlna_db_handle handle, slim_char* table_name, slim_char* col_name, slim_int col_type, slim_int col_constraint, slim_char* default_value, slim_char* check_expr)
{
	slim_char* query = slim_nil;
	slim_int ret = DLNA_DB_OK;
	slim_char* datatype_string;
	slim_char* col_constraint_string;

	switch(col_type)
	{
		case DLNA_DB_COLUMN_DATATYPE_INTEGER:
			datatype_string = (slim_char*)"INTEGER";
			break;
		case DLNA_DB_COLUMN_DATATYPE_TEXT:
			datatype_string = (slim_char*)"TEXT";
			break;
		case DLNA_DB_COLUMN_DATATYPE_FLOAT:
			datatype_string = (slim_char*)"FLOAT";
			break;
		case DLNA_DB_COLUMN_DATATYPE_BLOB:
			datatype_string = (slim_char*)"BLOB";
			break;
		default:
			ret = DLNA_DB_ERROR;
			DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] ADD COLUMN DataType UNKNOWN");
			return ret;
			break;
	}
	
	switch(col_constraint)
	{
		case DLNA_DB_COLUMN_CONSTRAINT_PRIMARYKEY:
			DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] ADD COLUMN AS PRIMARY KEY NOT ALLOWED!");
			ret = DLNA_DB_ERROR;
			return ret;
			break;
		case DLNA_DB_COLUMN_CONSTRAINT_FOREIGNKEY:
			col_constraint_string = (slim_char*)"FOREIGN KEY";
			break;
		case DLNA_DB_COLUMN_CONSTRAINT_NOTNULL:
			col_constraint_string = (slim_char*)"NOT NULL";
			break;
		case DLNA_DB_COLUMN_CONSTRAINT_UNIQUE:
			DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] ADD COLUMN AS UNIQUE NOT ALLOWED!");
			ret = DLNA_DB_ERROR;
			return ret;
			break;
		case DLNA_DB_COLUMN_CONSTRAINT_DEFAULT:
			col_constraint_string = (slim_char*)"DEFAULT";
			break;
		case DLNA_DB_COLUMN_CONSTRAINT_CHECK:
			col_constraint_string = (slim_char*)"CHECK";
			break;
		default:
			col_constraint_string = slim_nil;
			break;
	}
		
	if( col_constraint == DLNA_DB_COLUMN_CONSTRAINT_DEFAULT) {
		query = SLIM_T("ALTER TABLE '%q' ADD COLUMN '%q' '%q' '%q' '%q';");
		ret = dlnaDatabaseExecuteQueryPeer(handle, query, table_name, datatype_string, col_constraint_string, default_value);
	} else if (col_constraint == DLNA_DB_COLUMN_CONSTRAINT_CHECK) {
		query = SLIM_T("ALTER TABLE '%q' ADD COLUMN '%q' '%q' '%q' '%q';");
		ret = dlnaDatabaseExecuteQueryPeer(handle, query, table_name, datatype_string, col_constraint_string, check_expr);
	} else {
		if(col_constraint_string) {
			query = SLIM_T("ALTER TABLE '%q' ADD COLUMN '%q' '%q' '%q';");
			ret = dlnaDatabaseExecuteQueryPeer(handle, query, table_name, datatype_string, col_constraint_string);
		} else {
			query = SLIM_T("ALTER TABLE '%q' ADD COLUMN '%q' '%q';");
			ret = dlnaDatabaseExecuteQueryPeer(handle, query, table_name, datatype_string);
		}
	}
	return ret;
}

slim_char*
dlnaDatabaseGetDBLibraryVersionPeer(void)
{
  const char* version;
  version = sqlite3_libversion();
  return (slim_char*)version;
}

slim_int
dlnaDatabaseGetMemoryOperationStatusPeer(slim_int op, slim_int *pCurrent, slim_int *pHighWater, slim_int resetFlag)
{
  return sqlite3_status(op, pCurrent, pHighWater, resetFlag);
}

slim_int
dlnaDatabaseGetStatementStatusPeer(dlna_db_stmt stmt, slim_int op, slim_int resetFlag)
{
  return sqlite3_stmt_status((sqlite3_stmt*)stmt, op, resetFlag);
}

slim_int
dlnaDatabaseAutoVacuumPeer(dlna_db_handle handle, slim_int mode)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] DB Connection Handle is NULL");
    return DLNA_DB_ERROR;
  }

  if (mode == DLNA_DB_AUTOVACUUM_NONE) {
      query = (slim_char*)"PRAGMA auto_vacuum = NONE;";
  } else if (mode == DLNA_DB_AUTOVACUUM_FULL) {
      query = (slim_char*)"PRAGMA auto_vacuum = FULL;";
  } else if (mode == DLNA_DB_AUTOVACUUM_INCREMENTAL) {
      query = (slim_char*)"PRAGMA auto_vacuum = INCREMENTAL;";
  }

  ret = dlnaDatabaseExecuteQueryPeer(handle, query);
  return ret;
}

slim_int 
dlnaDatabaseIncrementalVacuumPeer(dlna_db_handle handle, slim_int pages)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] DB Connection Handle is NULL");
    return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA incremental_vacuum(%i);";
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, pages);
  return ret;
}

slim_int
dlnaDatabaseIntegrityCheckPeer(dlna_db_handle handle)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;
  dlna_db_stmt stmt = slim_nil;
  slim_int col = 0;

  if (!handle) {
          DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseIntegrityCheckPeer] DB Connection Handle is NULL");
          return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA quick_check;";
  ret = dlnaDatabasePrepareStatementPeer((sqlite3*)handle, &stmt, query);
  if(ret != DLNA_DB_OK) {
          if (stmt) {
                  dlnaDatabaseFinalizeStatementPeer(stmt);
          }
          return ret;
  }
  ret = dlnaDatabaseExecuteStepPeer(stmt);
  DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[MSG] Performing Database Check");
  while(ret == DLNA_DB_ROW)
  {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[MSG] Database STATUS: %s",
                                                                   dlnaDatabaseGetTextTypeColumnValuePeer(stmt, col));
          if (col == 0) {
                  if (!dlna_strcmp((slim_char*)"ok",
                                   (slim_char*)dlnaDatabaseGetTextTypeColumnValuePeer(stmt, col))) {
                          if (stmt) {
                                  dlnaDatabaseFinalizeStatementPeer(stmt);
                          }
                          return DLNA_DB_OK;
                  }
          }
          col++;
          ret = dlnaDatabaseExecuteStepPeer(stmt);
  }
  if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
  }
  return DLNA_DB_ERROR;
}

slim_int
dlnaDatabaseSetUserVersionPeer(dlna_db_handle handle, slim_int version)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseSetUserVersionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA user_version = %i;";
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, version);
  return ret;
}

slim_int
dlnaDatabaseGetUserVersionPeer(dlna_db_handle handle, slim_int *version)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;
  dlna_db_stmt stmt = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetUserVersionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA user_version;";
  ret = dlnaDatabasePrepareStatementPeer((sqlite3*)handle, &stmt, query);
  if(ret != DLNA_DB_OK) {
      if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
      }
      return ret;
  }
  ret = dlnaDatabaseExecuteStepPeer(stmt);
  if (ret == DLNA_DB_ROW) {
      *version = dlnaDatabaseGetIntegerTypeColumnValuePeer(stmt, 0);
  }
  if (stmt) {
      dlnaDatabaseFinalizeStatementPeer(stmt);
  }
  return DLNA_DB_OK;
}

slim_int
dlnaDatabaseGetSchemaVersionPeer(dlna_db_handle handle, slim_int *version)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;
  dlna_db_stmt stmt = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetSchemaVersionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA schema_version;";
  ret = dlnaDatabasePrepareStatementPeer((sqlite3*)handle, &stmt, query);
  if(ret != DLNA_DB_OK) {
      if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
      }
      return ret;
  }
  ret = dlnaDatabaseExecuteStepPeer(stmt);
  if (ret == DLNA_DB_ROW) {
      *version = dlnaDatabaseGetIntegerTypeColumnValuePeer(stmt, 0);
  }
  if (stmt) {
      dlnaDatabaseFinalizeStatementPeer(stmt);
  }
  return DLNA_DB_OK;
}

slim_int 
dlnaDatabaseBindTextPeer(dlna_db_stmt stmt, slim_int index, slim_char* value, slim_int nbytes, slim_int destructor_type)
{
  slim_int ret = DLNA_DB_OK;
  if (destructor_type == DLNA_DB_BIND_DESTRUCTOR_TYPE_STATIC) {
      ret = sqlite3_bind_text(stmt, index, (const char*)value, nbytes, SQLITE_STATIC);
  } else if (destructor_type == DLNA_DB_BIND_DESTRUCTOR_TYPE_TRANSIENT) {
      ret = sqlite3_bind_text(stmt, index, (const char*)value, nbytes, SQLITE_TRANSIENT);
  }
  return ret;
}

#ifdef DLNA_DB_SUPPORT_FOREIGNKEY
slim_int
dlnaDatabaseEnableForeignKeyPeer(dlna_db_handle handle)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseEnableForeignKey] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA foreign_keys = ON;";
  ret = dlnaDatabaseExecuteQueryPeer(handle, query);
  return ret;
}
#endif /*DLNA_DB_SUPPORT_FOREIGNKEY*/

#ifdef DLNA_DB_SUPPORT_SOFTHEAP
void
dlnaDatabaseSetSoftHeapPeer(slim_int nbytes)
{
  sqlite3_soft_heap_limit64(nbytes);
}
#endif /*DLNA_DB_SUPPORT_SOFTHEAP*/

#ifdef DLNA_DB_SUPPORT_SHARED_CACHE
slim_int
dlnaDatabaseSetSharedCacheModePeer(slim_bool mode)
{
  return sqlite3_enable_shared_cache(mode);
}
#endif /*DLNA_DB_SUPPORT_SHARED_CACHE*/

slim_int
dlnaDatabaseReleaseMemoryPeer(slim_int nbytes)
{
  return sqlite3_release_memory(nbytes);
}

slim_int
dlnaDatabaseConnectionCacheSizeChangePeer(dlna_db_handle handle, slim_int pages)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseIncrementalVaccumPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA cache_size = %i;";
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, pages);
  return ret;
}

slim_char*
dlnaDatabaseGetErrorMsgPeer(dlna_db_handle handle)
{
  const char * err;
  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseIncrementalVaccumPeer] DB Connection Handle is NULL");
      return slim_nil;
  }
  sqlite3_mutex_enter(sqlite3_db_mutex((sqlite3*)handle));
  err = sqlite3_errmsg((sqlite3*)handle);
  sqlite3_mutex_leave(sqlite3_db_mutex((sqlite3*)handle));

  return (slim_char*)err;
}

dlna_db_tables
dlnaDatabaseGetTablesListPeer(dlna_db_handle handle)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;
  dlna_database_peer_tables *peer_tables;
  dlna_database_peer_table_list_item *table_list_item;
  dlna_db_stmt stmt = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetTablesListPeer] DB Connection Handle is NULL");
      return 0;
  }
	
  query = (slim_char*)"SELECT name FROM sqlite_master WHERE type='table' ORDER BY name;";
  ret = dlnaDatabasePrepareStatementPeer((sqlite3*)handle, &stmt, query);
  if(ret != DLNA_DB_OK) {
      if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
      }
      return 0;
  }

  ret = dlnaDatabaseExecuteStepPeer(stmt);
  if(ret == DLNA_DB_ROW) {
      peer_tables = (dlna_database_peer_tables*)XCALLOC(MTYPE_TMP, sizeof(dlna_database_peer_tables));
      if(!peer_tables){
          if (stmt) {
              dlnaDatabaseFinalizeStatementPeer(stmt);
          }
          return 0;
      }
      ListInit(&peer_tables->table_list);
  } else {
      if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
      }
      return 0;
  }

  while(ret == DLNA_DB_ROW) {
      if(dlnaDatabaseGetTextTypeColumnValuePeer(stmt, 0)) {
          table_list_item = (dlna_database_peer_table_list_item*)XCALLOC(MTYPE_TMP, sizeof(dlna_database_peer_table_list_item));
          if(!table_list_item){
        	  continue;
          }
          table_list_item->table_name = XSTRDUP(MTYPE_TMP, dlnaDatabaseGetTextTypeColumnValuePeer(stmt, 0));
          if(!table_list_item->table_name){
        	  XFREE(MTYPE_TMP,table_list_item);
        	  continue;
          }
          ListAdd(&peer_tables->table_list, table_list_item);
      }
      ret = dlnaDatabaseExecuteStepPeer(stmt);
  }

  if (stmt) {
      dlnaDatabaseFinalizeStatementPeer(stmt);
  }
  return (dlna_db_tables)peer_tables;
} 

slim_int
dlnaDatabaseGetTablesCountPeer(dlna_db_tables tables)
{
  dlna_database_peer_tables *peer_tables = (dlna_database_peer_tables*)tables;

  if(!peer_tables) {
      return 0;
  }
  return ListCount(&peer_tables->table_list);
}

slim_char*
dlnaDatabaseGetTablePeer(dlna_db_handle handle, dlna_db_tables tables, slim_int item_no)
{
  dlna_database_peer_tables *peer_tables = (dlna_database_peer_tables*)tables;
  dlna_database_peer_table_list_item *table_list_item;
  slim_int i = 0;

  if(!peer_tables) {
      return slim_nil;
  }

  ListLoop(&peer_tables->table_list, table_list_item) {
    if (i == item_no) {
        return table_list_item->table_name;
    }
    i++;
  }

  return slim_nil;
}

void
dlnaDatabaseFreeTablesListPeer(dlna_db_tables tables)
{
  dlna_database_peer_tables *peer_tables = (dlna_database_peer_tables*)tables;
  dlna_database_peer_table_list_item *table_list_item;

  if(!peer_tables) {
    return;
  }

  while ((table_list_item = ListHead(&peer_tables->table_list)))
  {
      ListDelete(&peer_tables->table_list, table_list_item);
      if(table_list_item->table_name) {
          XFREE(MTYPE_TMP, table_list_item->table_name);
      }
      XFREE(MTYPE_TMP, table_list_item);
  }

  XFREE(MTYPE_TMP, peer_tables);
}

dlna_db_indices
dlnaDatabaseGetIndicesListPeer(dlna_db_handle handle)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;
  dlna_database_peer_indices *peer_indices;
  dlna_database_peer_index_list_item *index_list_item;
  dlna_db_stmt stmt = slim_nil;
	
  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseGetIndicesListPeer] DB Connection Handle is NULL");
      return 0;
  }

  query = (slim_char*)"SELECT name FROM sqlite_master WHERE type='index' ORDER BY name;";
  ret = dlnaDatabasePrepareStatementPeer((sqlite3*)handle, &stmt, query);
  if(ret != DLNA_DB_OK) {
      if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
      }
      return 0;
  }

  ret = dlnaDatabaseExecuteStepPeer(stmt);
  if(ret == DLNA_DB_ROW) {
      peer_indices = (dlna_database_peer_indices*)XCALLOC(MTYPE_TMP, sizeof(dlna_database_peer_indices));
      if(!peer_indices){
          if (stmt) {
              dlnaDatabaseFinalizeStatementPeer(stmt);
          }
          return 0;
      }
      ListInit(&peer_indices->index_list);
  } else {
      if (stmt) {
          dlnaDatabaseFinalizeStatementPeer(stmt);
      }
      return 0;
  }

  while(ret == DLNA_DB_ROW) {
      if(dlnaDatabaseGetTextTypeColumnValuePeer(stmt, 0)) {
          index_list_item = (dlna_database_peer_index_list_item*)XCALLOC(MTYPE_TMP, sizeof(dlna_database_peer_index_list_item));
          if(!index_list_item){
        	  continue;
          }
          if(!(index_list_item->index_name = XSTRDUP(MTYPE_TMP, dlnaDatabaseGetTextTypeColumnValuePeer(stmt, 0)))){
        	  XFREE(MTYPE_TMP,index_list_item);
        	  continue;
          }
          ListAdd(&peer_indices->index_list, index_list_item);
      }
      ret = dlnaDatabaseExecuteStepPeer(stmt);
  }

  if (stmt) {
      dlnaDatabaseFinalizeStatementPeer(stmt);
  }
  return (dlna_db_indices)peer_indices;
} 

slim_int
dlnaDatabaseGetIndicesCountPeer(dlna_db_indices indices)
{
  dlna_database_peer_indices *peer_indices = (dlna_database_peer_indices*)indices;

  if(!peer_indices) {
      return 0;
  }
  return ListCount(&peer_indices->index_list);
}

slim_char*
dlnaDatabaseGetIndexPeer(dlna_db_handle handle, dlna_db_indices indices, slim_int item_no)
{
  dlna_database_peer_indices *peer_indices = (dlna_database_peer_indices*)indices;
  dlna_database_peer_index_list_item *index_list_item;
  slim_int i = 0;

  if(!peer_indices) {
      return slim_nil;
  }

  ListLoop(&peer_indices->index_list, index_list_item) {
    if (i == item_no) {
        return index_list_item->index_name;
    }
    i++;
  }
  return slim_nil;
	
}

void
dlnaDatabaseFreeIndicesListPeer(dlna_db_indices indices)
{
  dlna_database_peer_indices *peer_indices = (dlna_database_peer_indices*)indices;
  dlna_database_peer_index_list_item *index_list_item;

  if(!peer_indices) {
    return;
  }

  while ((index_list_item = ListHead(&peer_indices->index_list)))
  {
      ListDelete(&peer_indices->index_list, index_list_item);
      if(index_list_item->index_name) {
          XFREE(MTYPE_TMP, index_list_item->index_name);
      }
      XFREE(MTYPE_TMP, index_list_item);
  }

  XFREE(MTYPE_TMP, peer_indices);
}

void
dlnaDatabaseSetBusyHandlerPeer(dlna_db_handle in_handle, dlna_db_busy_handler_callback in_callback_func, void* callback_arg)
{
  sqlite3_busy_handler((sqlite3*)in_handle, (void*)in_callback_func, callback_arg);  
}

slim_int
dlnaDatabaseExplainQueryPlanPeer(dlna_db_stmt pStmt)
{
  slim_char *inSql = slim_nil;
  slim_char *explainSql = slim_nil;
  sqlite3_stmt *pExplain = 0;
  slim_int rc;

  inSql = (slim_char*)sqlite3_sql((sqlite3_stmt*)pStmt);
  if( inSql==0 ) {
      return SQLITE_ERROR;
  }

  explainSql = (slim_char*)sqlite3_mprintf("EXPLAIN QUERY PLAN %s", inSql);
  if( !explainSql) {
      return SQLITE_NOMEM;
  }

  rc = sqlite3_prepare_v2(sqlite3_db_handle((sqlite3_stmt*)pStmt), (char*)explainSql, -1, &pExplain, 0);
  sqlite3_free(explainSql);
  if( rc!=SQLITE_OK ) {
      return rc;
  }
  DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_TRACE, "[PEER_DB][QPEXLAIN] QUERY: %s", inSql);
  while( SQLITE_ROW==sqlite3_step(pExplain) ){
    slim_int iSelectid = sqlite3_column_int(pExplain, 0);
    slim_int iOrder = sqlite3_column_int(pExplain, 1);
    slim_int iFrom = sqlite3_column_int(pExplain, 2);
    const slim_char *zDetail = (const slim_char *)sqlite3_column_text(pExplain, 3);
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_TRACE, "[PEER_DB][QPEXPLAIN] %d %d %d %s", iSelectid, iOrder, iFrom, zDetail);
  }
  return sqlite3_finalize(pExplain);
}

slim_int
dlnaDatabaseAnalyzePeer(dlna_db_handle handle)
{
  slim_int rc = SQLITE_OK;
#ifdef DLNA_DB_ENABLE_ANALYZE
  slim_char *sql = slim_nil;

  sql = SLIM_T("ANALYZE;");
  rc = dlnaDatabaseExecuteQueryPeer(handle, sql);
  if(rc != SQLITE_OK) {
    return -1;
  }
#endif /*DLNA_DB_ENABLE_ANALYZE*/
  return rc;
}

void
dlnaDatabaseMemoryStatusLog(void)
{
#ifdef DLNA_DB_MEMORY_STATS_LOG
  slim_int ret;
  slim_int current = 0;
  slim_int highwater = 0;
  slim_int reset_flag = 0;

  DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "==============================================================");
  DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_MEMORY_STATUS] LOG START");

  ret = sqlite3_status(SQLITE_STATUS_MEMORY_USED, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_MEMORY_USED!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_MEMORY_USED current = %d, highwater = %d", current, highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_MALLOC_SIZE, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_MALLOC_SIZE!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_MALLOC_SIZE highwater = %d", highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_MALLOC_COUNT, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_MALLOC_COUNT!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_MALLOC_COUNT current = %d, highwater = %d", current, highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_PAGECACHE_USED, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_PAGECACHE_USED!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_PAGECACHE_USED current = %d, highwater = %d (pages)", current, highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_PAGECACHE_OVERFLOW, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_PAGECACHE_OVERFLOW!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_PAGECACHE_OVERFLOW current = %d, highwater = %d!", current, highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_PAGECACHE_SIZE, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_PAGECACHE_SIZE!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_PAGECACHE_SIZE highwater = %d!", highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_SCRATCH_USED, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_SCRATCH_USED!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_SCRATCH_USED current = %d, highwater = %d!", current, highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_SCRATCH_OVERFLOW, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_SCRATCH_OVERFLOW!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_SCRATCH_OVERFLOW current = %d, highwater = %d!", current, highwater);
  }

  current = 0;
  highwater = 0;
  ret = sqlite3_status(SQLITE_STATUS_SCRATCH_SIZE, &current, &highwater, reset_flag);
  if(SQLITE_OK != ret) {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER] Failed to get sqlite status SQLITE_STATUS_SCRATCH_SIZE!");
  }
  else {
    DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_STATUS] SQLITE_STATUS_SCRATCH_SIZE highwater = %d!", highwater);
  }

  DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "[SQLITE_MEMORY_STATUS] LOG END");
  DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_DEBUG, "==============================================================");
  return;
#else
  return;
#endif
}

slim_int
dlnaDatabaseSetRecursiveTriggersPeer(dlna_db_handle handle, slim_bool enabled)
{
  slim_int ret = DLNA_DB_OK;
  slim_char *query = slim_nil;

  if (!handle) {
      DLNA_LOG(DLNA_LOG_PEER_DB, DLNA_LOG_LEVEL_ERROR, "[DB_PEER][dlnaDatabaseSetUserVersionPeer] DB Connection Handle is NULL");
      return DLNA_DB_ERROR;
  }

  query = (slim_char*)"PRAGMA recursive_triggers = %i;";
  ret = dlnaDatabaseExecuteQueryPeer(handle, query, enabled);

  return ret;
}

slim_int
dlnaDatabaseRowsModifiedNumber(dlna_db_handle handle)
{
  return sqlite3_changes((sqlite3*)handle);
}
