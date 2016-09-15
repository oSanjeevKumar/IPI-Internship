/* peer_database.h
 * Copyright (C) 2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD., whether the whole or part 
 * of the source code including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
#ifndef _DATABASE_PEER_H
#define _DATABASE_PEER_H

#include <dlna_peer.h>
#include <sqlite3.h>

#undef DLNA_DB_MEMSYS5_ALLOCATOR
#undef DLNA_DB_SCRATCH_MEMORY_CONFIG
#undef DLNA_DB_PAGE_CACHE_MEMORY_CONFIG
#undef DLNA_DB_LOOKASIDE_ALLOCATOR_CONFIG
#define DLNA_DB_MEMORY_STATS_LOG
#define DLNA_DB_SUPPORT_SOFTHEAP
#define DLNA_DB_SUPPORT_JOURNAL_MODE_WAL
#define DLNA_DB_SUPPORT_FOREIGNKEY
#undef DLNA_DB_SUPPORT_SHARED_CACHE
#undef NFLC_ENABLE_DATABASE_QUERYPLAN
#undef DLNA_DB_ENABLE_SQLITE_LOCK_DELAY
#define DLNA_DB_ENABLE_ANALYZE

/*!
Database Error Codes

<table>
  <tr>
    <td><b> Error Code</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_OK</td>
    <td>Successful Result</td>
  </tr>
  <tr>
    <td>DLNA_DB_ERROR</td>
    <td>SQL error or missing database</td>
  </tr>
  <tr>
    <td>DLNA_DB_INTERNAL</td>
    <td>Internal logic error in SQLite</td>
  </tr>
  <tr>
    <td>DLNA_DB_PERM</td>
    <td>Access permission denied</td>
  </tr>
  <tr>
    <td>DLNA_DB_ABORT</td>
    <td>Callback routine requested an abort</td>
  </tr>
  <tr>
    <td>DLNA_DB_BUSY</td>
    <td>The database file is locked</td>
  </tr>
  <tr>
    <td>DLNA_DB_LOCKED</td>
    <td>A table in the database is locked</td>
  </tr>
  <tr>
    <td>DLNA_DB_NOMEM</td>
    <td>A malloc() failed</td>
  </tr>
  <tr>
    <td>DLNA_DB_READONLY</td>
    <td>Attempt to write a readonly database</td>
  </tr>
  <tr>
    <td>DLNA_DB_INTERRUPT</td>
    <td>Operation terminated</td>
  </tr>
  <tr>
    <td>DLNA_DB_IOERR</td>
    <td>Some kind of disk I/O error occurred</td>
  </tr>
  <tr>
    <td>DLNA_DB_CORRUPT</td>
    <td>The database disk image is malformed</td>
  </tr>
  <tr>
    <td>DLNA_DB_NOTFOUND</td>
    <td>NOT USED. Table or record not found</td>
  </tr>
  <tr>
    <td>DLNA_DB_FULL</td>
    <td>Insertion failed because database is full</td>
  </tr>
  <tr>
    <td>DLNA_DB_CANTOPEN</td>
    <td>Unable to open the database file</td>
  </tr>
  <tr>
    <td>DLNA_DB_PROTOCOL</td>
    <td>Database lock protocol error</td>
  </tr>
  <tr>
    <td>DLNA_DB_EMPTY</td>
    <td>Database is empty</td>
  </tr>
  <tr>
    <td>DLNA_DB_SCHEMA</td>
    <td>The database schema changed</td>
  </tr>
  <tr>
    <td>DLNA_DB_TOOBIG</td>
    <td>String or BLOB exceeds size limit</td>
  </tr>
  <tr>
    <td>DLNA_DB_CONSTRAINT</td>
    <td>Abort due to constraint violation</td>
  </tr>
  <tr>
    <td>DLNA_DB_MISMATCH</td>
    <td>Data type mismatch</td>
  </tr>
  <tr>
    <td>DLNA_DB_MISUSE</td>
    <td>Library used incorrectly</td>
  </tr>
  <tr>
    <td>DLNA_DB_NOLFS</td>
    <td>Uses OS features not supported on host</td>
  </tr>
  <tr>
    <td>DLNA_DB_AUTH</td>
    <td>Authorization denied</td>
  </tr>
  <tr>
    <td>DLNA_DB_FORMAT</td>
    <td>Auxiliary database format error</td>
  </tr>
  <tr>
    <td>DLNA_DB_RANGE</td>
    <td>2nd parameter to dlnaDatabaseBindTextPeer out of range</td>
  </tr>
  <tr>
    <td>DLNA_DB_NOTADB</td>
    <td>File opened that is not a database file</td>
  </tr>
  <tr>
    <td>DLNA_DB_ROW</td>
    <td>dlnaDatabaseExecuteStepPeer() has another row ready </td>
  </tr>
  <tr>
    <td>DLNA_DB_DONE</td>
    <td>dlnaDatabaseExecuteStepPeer() has finished executing</td>
  </tr>
</table>
*/
#define DLNA_DB_OK          SQLITE_OK         /* Successful result */
/* beginning-of-error-codes */
#define DLNA_DB_ERROR       SQLITE_ERROR      /* SQL error or missing database */
#define DLNA_DB_INTERNAL    SQLITE_INTERNAL   /* Internal logic error in SQLite */
#define DLNA_DB_PERM        SQLITE_PERM       /* Access permission denied */
#define DLNA_DB_ABORT       SQLITE_ABORT      /* Callback routine requested an abort */
#define DLNA_DB_BUSY        SQLITE_BUSY       /* The database file is locked */
#define DLNA_DB_LOCKED      SQLITE_LOCKED     /* A table in the database is locked */
#define DLNA_DB_NOMEM       SQLITE_NOMEM      /* A malloc() failed */
#define DLNA_DB_READONLY    SQLITE_READONLY   /* Attempt to write a readonly database */
#define DLNA_DB_INTERRUPT   SQLITE_INTERRUPT  /* Operation terminated by sqlite3_interrupt()*/
#define DLNA_DB_IOERR       SQLITE_IOERR      /* Some kind of disk I/O error occurred */
#define DLNA_DB_CORRUPT     SQLITE_CORRUPT    /* The database disk image is malformed */
#define DLNA_DB_NOTFOUND    SQLITE_NOTFOUND   /* NOT USED. Table or record not found */
#define DLNA_DB_FULL        SQLITE_FULL       /* Insertion failed because database is full */
#define DLNA_DB_CANTOPEN    SQLITE_CANTOPEN   /* Unable to open the database file */
#define DLNA_DB_PROTOCOL    SQLITE_PROTOCOL   /* Database lock protocol error */
#define DLNA_DB_EMPTY       SQLITE_EMPTY      /* Database is empty */
#define DLNA_DB_SCHEMA      SQLITE_SCHEMA     /* The database schema changed */
#define DLNA_DB_TOOBIG      SQLITE_TOOBIG     /* String or BLOB exceeds size limit */
#define DLNA_DB_CONSTRAINT  SQLITE_CONSTRAINT /* Abort due to constraint violation */
#define DLNA_DB_MISMATCH    SQLITE_MISMATCH   /* Data type mismatch */
#define DLNA_DB_MISUSE      SQLITE_MISUSE     /* Library used incorrectly */
#define DLNA_DB_NOLFS       SQLITE_NOLFS      /* Uses OS features not supported on host */
#define DLNA_DB_AUTH        SQLITE_AUTH       /* Authorization denied */
#define DLNA_DB_FORMAT      SQLITE_FORMAT     /* Auxiliary database format error */
#define DLNA_DB_RANGE       SQLITE_RANGE      /* 2nd parameter to sqlite3_bind out of range */
#define DLNA_DB_NOTADB      SQLITE_NOTADB     /* File opened that is not a database file */
#define DLNA_DB_ROW         SQLITE_ROW        /* sqlite3_step() has another row ready */
#define DLNA_DB_DONE        SQLITE_DONE       /* sqlite3_step() has finished executing */

/* MEMORY OPERATIONS */
#define DLNA_DB_STATUS_MEMORY_USED          SQLITE_STATUS_MEMORY_USED
#define DLNA_DB_STATUS_PAGECACHE_USED       SQLITE_STATUS_PAGECACHE_USED
#define DLNA_DB_STATUS_PAGECACHE_OVERFLOW   SQLITE_STATUS_PAGECACHE_OVERFLOW
#define DLNA_DB_STATUS_SCRATCH_USED         SQLITE_STATUS_SCRATCH_USED
#define DLNA_DB_STATUS_SCRATCH_OVERFLOW     SQLITE_STATUS_SCRATCH_OVERFLOW
#define DLNA_DB_STATUS_MALLOC_SIZE          SQLITE_STATUS_MALLOC_SIZE
#define DLNA_DB_STATUS_PARSER_STACK         SQLITE_STATUS_PARSER_STACK
#define DLNA_DB_STATUS_PAGECACHE_SIZE       SQLITE_STATUS_PAGECACHE_SIZE
#define DLNA_DB_STATUS_SCRATCH_SIZE         SQLITE_STATUS_SCRATCH_SIZE
#define DLNA_DB_STATUS_MALLOC_COUNT         SQLITE_STATUS_MALLOC_COUNT

/* STATEMENT OPERATIONS*/
#define DLNA_DB_STMTSTATUS_FULLSCAN_STEP    SQLITE_STMTSTATUS_FULLSCAN_STEP
#define DLNA_DB_STMTSTATUS_SORT             SQLITE_STMTSTATUS_SORT
#define DLNA_DB_STMTSTATUS_AUTOINDEX        SQLITE_STMTSTATUS_AUTOINDEX

/*!
Database File Operations

<table>
  <tr>
    <td><b> File Opeartion</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_READONLY</td>
    <td>Database is opened in ReadOnly Mode</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_READWRITE</td>
    <td>Database is opened in ReadWrite Mode</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_CREATE</td>
    <td>Database is created if it does not already exist</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_URI</td>
    <td>URI Filename interpretations</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_NOMUTEX</td>
    <td>Database file is opened in multi-thread threading mode</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_FULLMUTEX</td>
    <td>Database is opened in serialized threading mode</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_SHAREDCACHE</td>
    <td>Database connection to be eligible to use shared cache</td>
  </tr>
  <tr>
    <td>DLNA_DB_FILE_OPERATION_OPEN_PRIVATECACHE</td>
    <td>Database connection to be eligible to use private cache</td>
  </tr>
</table>
*/
#define DLNA_DB_FILE_OPERATION_OPEN_READONLY    SQLITE_OPEN_READONLY
#define DLNA_DB_FILE_OPERATION_OPEN_READWRITE   SQLITE_OPEN_READWRITE
#define DLNA_DB_FILE_OPERATION_OPEN_CREATE    SQLITE_OPEN_CREATE
#define DLNA_DB_FILE_OPERATION_OPEN_URI     SQLITE_OPEN_URI
#define DLNA_DB_FILE_OPERATION_OPEN_NOMUTEX   SQLITE_OPEN_NOMUTEX
#define DLNA_DB_FILE_OPERATION_OPEN_FULLMUTEX   SQLITE_OPEN_FULLMUTEX
#define DLNA_DB_FILE_OPERATION_OPEN_SHAREDCACHE   SQLITE_OPEN_SHAREDCACHE
#define DLNA_DB_FILE_OPERATION_OPEN_PRIVATECACHE  SQLITE_OPEN_PRIVATECACHE

#define DLNA_DB_COL_TYPE_INTEGER  "INTEGER"
#define DLNA_DB_COL_TYPE_FLOAT    "FLOAT"
#define DLNA_DB_COL_TYPE_TEXT   "TEXT"
#define DLNA_DB_COL_TYPE_BLOB   "BLOB"
#define DLNA_DB_COL_TYPE_NULL   "NULL"

#define DLNA_DB_COL_CONSTRAINT_PRIMARYKEY  "PRIMARY KEY"
#define DLNA_DB_COL_CONSTRAINT_FOREIGNKEY  "FOREIGN KEY"
#define DLNA_DB_COL_CONSTRAINT_NOTNULL     "NOT NULL"
#define DLNA_DB_COL_CONSTRAINT_UNIQUE    "UNIQUE"
#define DLNA_DB_COL_CONSTRAINT_DEFAULT     "DEFAULT"
#define DLNA_DB_COL_CONSTRAINT_CHECK     "CHECK"

/*!
Database Column Data Types

<table>
  <tr>
    <td><b> Data Type</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_DATATYPE_INTEGER</td>
    <td>Integer Type</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_DATATYPE_FLOAT</td>
    <td>Float Type</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_DATATYPE_TEXT</td>
    <td>Text/String Type</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_DATATYPE_BLOB</td>
    <td>Blob Type</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_DATATYPE_NULL</td>
    <td>NULL Type</td>
  </tr>
</table>
*/
enum {
  DLNA_DB_COLUMN_DATATYPE_INTEGER = 0,
  DLNA_DB_COLUMN_DATATYPE_TEXT,
  DLNA_DB_COLUMN_DATATYPE_FLOAT,
  DLNA_DB_COLUMN_DATATYPE_BLOB,
  DLNA_DB_COLUMN_DATATYPE_NULL
};

/*!
Database Column Constraint Types

<table>
  <tr>
    <td><b> Constraint Type</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_CONSTRAINT_PRIMARYKEY</td>
    <td>Primary Key Constraint</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_CONSTRAINT_FOREIGNKEY</td>
    <td>Foreign Key Constraint</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_CONSTRAINT_NOTNULL</td>
    <td>NOT NULL Constraint</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_CONSTRAINT_UNIQUE</td>
    <td>Unique Constraint</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_CONSTRAINT_DEFAULT</td>
    <td>Default Constraint</td>
  </tr>
  <tr>
    <td>DLNA_DB_COLUMN_CONSTRAINT_CHECK</td>
    <td>Check Constraint</td>
  </tr>
</table>
*/
enum {
  DLNA_DB_COLUMN_CONSTRAINT_PRIMARYKEY = 0,
  DLNA_DB_COLUMN_CONSTRAINT_FOREIGNKEY,
  DLNA_DB_COLUMN_CONSTRAINT_NOTNULL,
  DLNA_DB_COLUMN_CONSTRAINT_UNIQUE,
  DLNA_DB_COLUMN_CONSTRAINT_DEFAULT,
  DLNA_DB_COLUMN_CONSTRAINT_CHECK
};

/*!
Database Connection Journal Mode

<table>
  <tr>
    <td><b> Connection Journal Mode</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_ROLLBACK</td>
    <td>Default Journal Mode where Journal file is deleted after the completion of each transaction </td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_ROLLBACK_DELETE</td>
    <td>Same as Rollback Journal Mode</td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_ROLLBACK_TRUNCATE</td>
    <td>Truncate Journal Mode commits transactions by truncating the rollback journal to zero-length instead of deleting it</td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_ROLLBACK_PERSIST</td>
    <td>PERSIST journaling mode prevents the rollback journal from being deleted at the end of each transaction</td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_ROLLBACK_MEMORY</td>
    <td>MEMORY journaling mode stores the rollback journal in volatile RAM</td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_WAL</td>
    <td>WAL journaling mode uses a write-ahead log instead of a rollback journal to implement transactions</td>
  </tr>
  <tr>
    <td>DLNA_DB_JOURNAL_MODE_OFF</td>
    <td>OFF journaling mode disables the rollback journal completely</td>
  </tr>
</table>
*/
enum {
  DLNA_DB_JOURNAL_MODE_ROLLBACK = 0,
  DLNA_DB_JOURNAL_MODE_ROLLBACK_DELETE,
  DLNA_DB_JOURNAL_MODE_ROLLBACK_TRUNCATE,
  DLNA_DB_JOURNAL_MODE_ROLLBACK_PERSIST,
  DLNA_DB_JOURNAL_MODE_ROLLBACK_MEMORY,
  DLNA_DB_JOURNAL_MODE_WAL,
  DLNA_DB_JOURNAL_MODE_OFF
};

/*!
Database Auto Vacuum Status in the database

<table>
  <tr>
    <td><b> Connection Journal Mode</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_AUTOVACUUM_NONE</td>
    <td>Default Auto Vacuum setting which means Auto Vacuum is disabled </td>
  </tr>
  <tr>
    <td>DLNA_DB_AUTOVACUUM_FULL</td>
    <td>Full Auto vacuum mode means the freelist pages are moved to the end of the database file and the database file is truncated to remove the freelist pages at every transaction commit</td>
  </tr>
  <tr>
    <td>DLNA_DB_AUTOVACUUM_INCREMENTAL</td>
    <td>For Incremental, the additional information needed to do auto-vacuuming is stored in the database file but auto-vacuuming does not occur automatically at each commit</td>
  </tr>
</table>
*/
enum {
  DLNA_DB_AUTOVACUUM_NONE = 0,
  DLNA_DB_AUTOVACUUM_FULL,
  DLNA_DB_AUTOVACUUM_INCREMENTAL
};

/*!
Database Bind Parameter Destructor Type

<table>
  <tr>
    <td><b> Bind Destructor Type</b></td>
    <td><b> Details</b></td>
  </tr>
  <tr>
    <td>DLNA_DB_BIND_DESTRUCTOR_TYPE_STATIC</td>
    <td>SQLite assumes that the information is in static, unmanaged space and does not need to be freed </td>
  </tr>
  <tr>
    <td>DLNA_DB_BIND_DESTRUCTOR_TYPE_TRANSIENT</td>
    <td>SQLite makes its own private copy of the data immediately</td>
  </tr>
</table>
*/
enum {
  DLNA_DB_BIND_DESTRUCTOR_TYPE_STATIC = 0,
  DLNA_DB_BIND_DESTRUCTOR_TYPE_TRANSIENT
};

/*!
Database Connection Handle
*/
typedef void *dlna_db_handle;

/*!
Database Prepared Statement Pointer
*/
typedef void *dlna_db_stmt;
/*!
Database Tables List Pointer
*/
typedef void *dlna_db_tables;
/*!
Database Indices List Pointer
*/
typedef void *dlna_db_indices;

/*!
Database busy handler callback
*/
typedef slim_int (*dlna_db_busy_handler_callback)(void* arg, slim_int call_count);

typedef struct dlna_database_peer_table_list_item_
{
  struct dlna_database_peer_table_list_item_ *prev;
  struct dlna_database_peer_table_list_item_ *next;
  slim_char* table_name;
} dlna_database_peer_table_list_item;

typedef struct dlna_database_peer_tables_
{
  List(dlna_database_peer_table_list_item*) table_list;
} dlna_database_peer_tables;

typedef struct dlna_database_peer_index_list_item_
{
  struct dlna_database_peer_index_list_item_ *prev;
  struct dlna_database_peer_index_list_item_ *next;
  slim_char* index_name;
} dlna_database_peer_index_list_item;

typedef struct dlna_database_peer_indices_
{
  List(dlna_database_peer_index_list_item*) index_list;
} dlna_database_peer_indices;

/*!
\par Function:
Initializes Database Peer
\par Parameters:

\return DLNA_DB_OK if database peer initialization succeeded
\return DLNA_DB_ERROR if database peer initialization failed
\par Description:
This function initializes the database peer.
*/
slim_int 
dlnaDatabaseInitializePeer(void);

/*!
\par Function:
Finalized Database Peer
\par Parameters:

\par Description:
This function finalizes the database peer.
*/
void
dlnaDatabaseFinalizePeer(void);

/*!
\par Function:
Creates and opens the database file at the input path specified with input flags for file operations
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_path</td>
    <td>path where the database file should be created including database filename</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_flags</td>
    <td>File Operations Flags </td>
  </tr>
</table>

\return dlna_db_handle Pointer to handle of database file/connection
\par Description:
This function creates and opens the database with the input file operations specified. The input file operations can be chosen from the File Operations Table
This function returns the handle for database file connection.
*/
dlna_db_handle 
dlnaDatabaseCreatePeer(slim_char* in_path, slim_int in_flags);

/*!
\par Function:
Opens the database file which has already been created before at the input path specified with input flags for file operations
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_path</td>
    <td>path where the database file should be created including database filename</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_flags</td>
    <td>File Operations Flags </td>
  </tr>
</table>

\return dlna_db_handle Pointer to handle of database file/connection
\par Description:
This function opens the database with the input file operations specified. The input file operations can be chosen from the File Operations Table
This function returns the handle for database file connection.
*/
dlna_db_handle
dlnaDatabaseOpenPeer(slim_char* in_path, slim_int flags);

/*!
\par Function:
Closes the database Connection
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>pointer to database handle dlna_db_handle</td>
  </tr>

</table>

\return
\par Description:
This function closes the database connection specified by its handle
*/
slim_int
dlnaDatabaseClosePeer(dlna_db_handle handle);

/*!
\par Function:
Allocates the memory block of the input size
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_size</td>
    <td>size of the memory to be allocated</td>
  </tr>


</table>

\returns pointer to the allocated memory
\par Description:
This function allocates a memory of the input size and returns the pointer to the allocated memory by the database
*/
void*
dlnaDatabaseMemoryMallocPeer(slim_int in_size);

/*!
\par Function:
Reallocates the memory block previously allocated
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_mem</td>
    <td>Pointer to the memory location previously allocated</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_size</td>
    <td>size/new size of the memory to be reallocated</td>
  </tr>


</table>

\returns pointer to the allocated memory
\par Description:
This function resizes the prior memory allocation by the database to a new size and returns the pointer to be the reallocated memory
*/
void*
dlnaDatabaseMemoryReallocPeer(void* in_mem, slim_int in_size);

/*!
\par Function:
Frees the allocated memory by the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_mem</td>
    <td>pointer to the memory allocated</td>
  </tr>

</table>

\return
\par Description:
This function frees the memory allocated by the database
*/
void
dlnaDatabaseMemoryFreePeer(void *in_mem);

/*!
\par Function:
Formats the string database query with the input variable arguments list
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_query</td>
    <td>string database query</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>argument_list</td>
    <td>Variable Argument list</td>
  </tr>
   <tr>
    <td>[out]</td>
    <td>out_query</td>
    <td>Output database query resulting from formating of the input database query with arguments list</td>
  </tr>

</table>

\returns the formatted string with input params else NULL pointer if it cannot allocate the required memory to store the formatted string
\par Description:
This function formats the input database query string with the input variable arguments and returns the formatted database query string.
NOTE: It is required that the allocated memory to prepare a formatted string should be freed after the use. Refer to dlnaDatabaseMemoryFreePeer().
*/
slim_char*
dlnaDatabaseFormatQueryStringPeer(slim_char *in_query, va_list argument_list);

/*!
\par Function:
Executes the database query on the database corresponding to the input database connection handle
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>query</td>
    <td>database query string</td>
  </tr>

</table>

\return DLNA_DB_OK if the query is executed successfully else the corresponding error code. Please see the error codes table

\par Description:
This function executes the database query. If the database query requires additional input arguments that needs to be formatted, this function requires additional input arguments.
Thus this function formats the query with the input arguments and executes it.
*/
slim_int 
dlnaDatabaseExecuteQueryPeer(dlna_db_handle handle, const slim_char* query, ...);

slim_int
dlnaDatabaseCreateStatementPeer(dlna_db_handle handle, dlna_db_stmt* ppStmt, const slim_char* query);

#ifdef DEVELOPMENT_DATABASE_STATEMENTS_PRECOMPILATION

slim_int
dlnaDatabaseCleanStatementPeer(dlna_db_stmt pStmt);

slim_int
dlnaDatabaseResetStatementPeer(dlna_db_stmt pStmt);

#endif /* DEVELOPMENT_DATABASE_STATEMENTS_PRECOMPILATION */

slim_int
dlnaDatabaseBindBLOBPeer(dlna_db_stmt in_stmt, slim_int index, slim_char* blob, slim_int blob_size);

slim_int
dlnaDatabaseGetBLOBTypeColumnValuePeer(dlna_db_stmt in_stmt, slim_int column, slim_char** dest);

/*!
\par Function:
Prepares the database statement for the database corresponding to the database connection handle
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>query</td>
    <td>database query string</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>ppStmt</td>
    <td>Output prepared statement</td>
  </tr>

</table>

\return DLNA_DB_OK if the prepare statement is executed successfully else the corresponding error code. Please see the error codes table

\par Description:
This function prepares the database statement which shall hold the results of the queried database. Usually statements are prepared for "SELECT" queries
If the database query requires additional input arguments that needs to be formatted, this function requires additional input arguments.
Thus this function formats the query with the input arguments and prepares the database statement on the query.
*/
slim_int 
dlnaDatabasePrepareStatementPeer(dlna_db_handle handle, dlna_db_stmt* ppStmt, const slim_char* query, ...);

/*!
\par Function:
Attaches a database to a main database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle of the main database</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>database_filepath</td>
    <td>database fullpath which is to be attached</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>database_name</td>
    <td>Database Alias for the database to be attached</td>
  </tr>

</table>

\return DLNA_DB_OK if the database is attached successfully else the corresponding error code. Please see the error codes table

\par Description:
This function attaches a database file to the existing main database.Alias of the attached database can be used to identify the attached database.
*/
slim_int 
dlnaDatabaseAttachConnectionPeer(dlna_db_handle handle, slim_char* database_filepath, slim_char* database_name);

/*!
\par Function:
Detaches a database from a main database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle of the main database</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>database_name</td>
    <td>Database Alias for the database attached</td>
  </tr>

</table>

\return DLNA_DB_OK if the database is detached successfully else the corresponding error code. Please see the error codes table

\par Description:
This function detaches the database connection from the main database.
*/
slim_int
dlnaDatabaseDetachConnectionPeer(dlna_db_handle handle, slim_char* database_name);

/*!
\par Function:
Sets the Journaling Mode that can be used for a database connection
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>journal_mode</td>
    <td>Input Journal Mode to be set. See Jorunal Mode Table for different modes</td>
  </tr>
</table>

\return DLNA_DB_OK if the desired Journal mode is set successfully else the corresponding error code. Please see the error codes table

\par Description:
This function sets the Journal mode for the database connection. If the Journal mode is not for the database connection, the default Journal mode is set
*/
slim_int
dlnaDatabaseSetJournalModePeer(dlna_db_handle handle, slim_int journal_mode);

/*!
\par Function:
Creates the database table for the input database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_query</td>
    <td>Input database query string to create table</td>
  </tr>

</table>

\return DLNA_DB_OK if the desired database table is created successfully else the corresponding error code. Please see the error codes table

\par Description:
This function creates the database table for the input database. The input query should specify the table name, columns of the tables and their data types and column constraints if any.
Thus this function creates the database table with all the columns specified in the database query
*/
slim_int 
dlnaDatabaseCreateTablePeer(dlna_db_handle handle, slim_char* in_query);

/*!
\par Function:
Creates the trigger on table for the input database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_query</td>
    <td>Input database query string to create trigger</td>
  </tr>

</table>

\return DLNA_DB_OK if the desired table's trigger is created successfully else the corresponding error code. Please see the error codes table

\par Description:
This function executes the query holding trigger creation against the input database. The input query should containt the statement for creating a trigger on an existing database table.
*/
slim_int
dlnaDatabaseCreateTriggerPeer(dlna_db_handle handle, slim_char* in_query);

/*!
\par Function:
Drops the table for the input database connection
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>table_name</td>
    <td>Table to be dropped</td>
  </tr>

</table>

\return DLNA_DB_OK if the desired database table is dropped successfully else the corresponding error code. Please see the error codes table

\par Description:
This function drops the table for input database.
*/
slim_int 
dlnaDatabaseDropTablePeer(dlna_db_handle handle, slim_char* table_name);

/*!
\par Function:
Adds a table column to the input database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>table_name</td>
    <td>Table for which the column is to be created</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>col_name</td>
    <td>column name of the column to be created</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>col_type</td>
    <td>Data type of the column to be created. See Data Type table for supported Column Data Types</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>col_constraint</td>
    <td>Constraint if required any for the column to be created. See Column Constraints table for supported Column Constraints</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>default_value</td>
    <td>default value if any for the column if the Constraint is set DLNA_DB_COLUMN_CONSTRAINT_DEFAULT</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>check_expr</td>
    <td>Check expression if any for the column if the constraint is DLNA_DB_COLUMN_CONSTRAINT_CHECK</td>
  </tr>
</table>

\return DLNA_DB_OK if the desired database column is added successfully else the corresponding error code. Please see the error codes table

\par Description:
This function adds a column to the existing database table.
*/
slim_int
dlnaDatabaseAddColumnPeer(dlna_db_handle handle, slim_char* table_name, slim_char* col_name, slim_int col_type, slim_int col_constraint, slim_char* default_value, slim_char* check_expr);

/*!
\par Function:
Creates and Index for the database table
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>table_name</td>
    <td>Table for which the index is to be created</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>index_name</td>
    <td>Name of the index to be created</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_column_to_be_indexed</td>
    <td>Database Table Column on which Indexed to be created</td>
  </tr>

</table>

\return DLNA_DB_OK if the desired index table is created successfully else the corresponding error code. Please see the error codes table

\par Description:
This function creates an index on a single column specified for the given table of the input database connection. Indexes are created to improve the performance of Select on databases.
*/
slim_int
dlnaDatabaseCreateIndexPeer(dlna_db_handle handle, slim_char* table_name, slim_char* index_name, slim_char* in_column_to_be_indexed);

/*!
\par Function:
Drops the Index of a database table created before
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>table_name</td>
    <td>Table for which the index to be dropped</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>index_name</td>
    <td>index to be dropped</td>
  </tr>
</table>

\return DLNA_DB_OK if the desired index table is dropped successfully else the corresponding error code. Please see the error codes table

\par Description:
This function drops the index previously created for a table of the input database.
*/
slim_int 
dlnaDatabaseDropIndexPeer(dlna_db_handle handle, slim_char* table_name, slim_char* index_name);

/*!
\par Function:
Executes the Step on the database statement prepared to retrieve the row
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_stmt</td>
    <td>Pointer to database statement</td>
  </tr>
</table>

\return DLNA_DB_ROW if there are any rows in the prepared statements else DLNA_DB_DONE indicating no more rows to be read

\par Description:
This function steps through the database prepared statement to retrieve a single row.
*/
slim_int
dlnaDatabaseExecuteStepPeer(dlna_db_stmt in_stmt);

/*!
\par Function:
Returns the value of a integer type column of the database from the prepared statement
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_stmt</td>
    <td>Pointer to database statement</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>column</td>
    <td>column id whose value needs to be retrieved</td>
  </tr>
</table>

\return value of the integer type column
\par Description:
This function returns the value of the integer type column by column id from the prepared statement
*/
slim_int
dlnaDatabaseGetIntegerTypeColumnValuePeer(dlna_db_stmt in_stmt, slim_int column);

/*!
\par Function:
Returns the value of a text type column of the database from the prepared statement
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_stmt</td>
    <td>Pointer to database statement</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>column</td>
    <td>column id whose value needs to be retrieved</td>
  </tr>
</table>

\return value of the integer type column
\par Description:
This function returns the value of the text type column by column id from the prepared statement
*/
slim_char*
dlnaDatabaseGetTextTypeColumnValuePeer(dlna_db_stmt in_stmt, slim_int column);

/*!
\par Function:
Finalizes the prepared statement
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_stmt</td>
    <td>Pointer to database statement to be freed</td>
  </tr>
</table>

\return DLNA_DB_OK if finalized successfully else returns error. Please see Error Code Table

\par Description:
This function frees the prepared statement for the database. It is recommended to finalize the prepared statement to reduce the number of database locks before another statement is prepared
*/
slim_int 
dlnaDatabaseFinalizeStatementPeer(dlna_db_stmt in_stmt);

/*!
\par Function:
Gets the last inserted row id in the database table
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>handle to the database connection</td>
  </tr>
</table>

\return the id of the last inserted row in the database table

\par Description:
This function gets the last inserted row id in the database table of the input database
*/
slim_int 
dlnaDatabaseGetLastInsertedRowIDPeer(dlna_db_handle handle);

/*!
\par Function:
Gets the table row count for the input database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>handle to the database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_table</td>
    <td>table of which the row count needs to be obtained</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>out_count</td>
    <td>total rows of the table</td>
  </tr>
</table>

\return DLNA_DB_OK if table row count is obtained successfully else returns error. Please see Error Code Table

\par Description:
This function gets the total count of rows in the database table for the input database
*/
slim_int
dlnaDatabaseGetTableRowCountPeer(dlna_db_handle handle, slim_char* in_table, slim_int *out_count);

/*!
\par Function:
Checkpointing for the WAL Database Journal file
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>handle to the database connection</td>
  </tr>
</table>

\return DLNA_DB_OK if checkpointing is successful else returns error. Please see Error Code Table

\par Description:
This function enables manual checkpointing of the database if the WAL Journaling mode if used.
*/
slim_int
dlnaDatabaseEnableCheckpointPeer(dlna_db_handle handle);

/*!
\par Function:
Gets the Database Library Version
\par Parameters:

\return the database version as a string

\par Description:
This function gets the database library version
*/
slim_char*
dlnaDatabaseGetDBLibraryVersionPeer(void);

/*!
\par Function:
Get Database Library Memory Operation Status
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_operation</td>
    <td>Integer Code for the memory parameter to be measured</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>pCurrent</td>
    <td>Current value of the parameter</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>pHighWater</td>
    <td>Highest value recorded</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>resetFlag</td>
    <td>If the reset flag is true, the highest value is recorded is reset after pHighWater is writted</td>
  </tr>
</table>

\return DLNA_DB_OK if operation status is retrieved successfully else returns error. Please see Error Code Table

\par Description:
This function is used to get the status of any memory operations of the database library. It returns the current value, highest value recorded and indication if the highest recorded
value is reset or not after recording for the input parameter to be measured.
*/
slim_int
dlnaDatabaseGetMemoryOperationStatusPeer(slim_int in_operation, slim_int *pCurrent, slim_int *pHighWater, slim_int resetFlag);

slim_int
dlnaDatabaseGetStatementStatusPeer(dlna_db_stmt in_stmt, slim_int in_operation, slim_int resetFlag);

/*!
\par Function:
Auto vacuums the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>mode</td>
    <td>Auto vacuum mode See Autovacuum mode table</td>
  </tr>
</table>

\return DLNA_DB_OK if auto vacuum is executed successfully else returns error. Please see Error Code Table

\par Description:
This function vacuums the database depending upon the type of mode set.
*/
slim_int
dlnaDatabaseAutoVacuumPeer(dlna_db_handle handle, slim_int mode);

/*!
\par Function:
Executes the Incremental vacuum on database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>pages</td>
    <td>Number of database pages for which the incremental vacuum to be executed</td>
  </tr>
</table>

\return DLNA_DB_OK if freed successfully else returns error. Please see Error Code Table

\par Description:
This function executes the incremental vacuum to free the number of pages specified for the input database.
*/
slim_int 
dlnaDatabaseIncrementalVacuumPeer(dlna_db_handle handle, slim_int pages);

/*!
\par Function:
Changes the cache size of the database to a desired value
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>pages</td>
    <td>Number of database pages to which the database connection size to be changed</td>
  </tr>
</table>

\return DLNA_DB_OK if cache size changed successfully else returns error. Please see Error Code Table

\par Description:
This function changes the cache size to the number of pages specified for the input database connection.
*/
slim_int
dlnaDatabaseConnectionCacheSizeChangePeer(dlna_db_handle handle, slim_int pages);

/*!
\par Function:
Checks the Database Integrity
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
</table>

\return DLNA_DB_OK if database integrity check is performed successfully else returns error. Please see Error Code Table

\par Description:
Checks if the database is corrupted or not, if so then deletes the database and creates a new database connection. This integrity check is performed only if previously created
database is opened for the first time.
*/
slim_int
dlnaDatabaseIntegrityCheckPeer(dlna_db_handle handle);

/*!
\par Function:
Sets the recursive triggers pragma for the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>enabled</td>
    <td>Value to be set for the pragma (enabled/disabled)</td>
  </tr>
</table>

\return DLNA_DB_OK if database user version is set successfully else returns error. Please see Error Code Table

\par Description:
Sets the user version specified for the input database. This allows the user to set his own versions for the database schemas whenever he makes any changes to database.
*/
slim_int
dlnaDatabaseSetRecursiveTriggersPeer(dlna_db_handle handle, slim_bool enabled);

/*!
\par Function:
Sets the User Version for the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>version</td>
    <td>Desired User Version for the database</td>
  </tr>
</table>

\return DLNA_DB_OK if database user version is set successfully else returns error. Please see Error Code Table

\par Description:
Sets the user version specified for the input database. This allows the user to set his own versions for the database schemas whenever he makes any changes to database.
*/
slim_int
dlnaDatabaseSetUserVersionPeer(dlna_db_handle handle, slim_int version);

/*!
\par Function:
Gets the User Version for the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>version</td>
    <td>User Version of the database</td>
  </tr>
</table>

\return DLNA_DB_OK if database user version is retrieved successfully else returns error. Please see Error Code Table

\par Description:
Gets the user version specified for the input database.
*/
slim_int
dlnaDatabaseGetUserVersionPeer(dlna_db_handle handle, slim_int *version);

/*!
\par Function:
Gets the Schema Version for the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[out]</td>
    <td>version</td>
    <td>Schema Version of the database</td>
  </tr>
</table>

\return DLNA_DB_OK if database schema version is retrieved successfully else returns error. Please see Error Code Table

\par Description:
Gets the schema version specified for the input database. Schema versions are set by the database library
*/
slim_int
dlnaDatabaseGetSchemaVersionPeer(dlna_db_handle handle, slim_int *version);

/*!
\par Function:
Sets the Shared Cache Mode for the database library
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>mode</td>
    <td>Boolean mode</td>
  </tr>
</table>

\return DLNA_DB_OK if database library shared cache mode is set successfully else returns error. Please see Error Code Table

\par Description:
This function sets the shared cache mode for the database library if the input mode is true.
*/
slim_int
dlnaDatabaseSetSharedCacheModePeer(slim_bool mode);

/*!
\par Function:
Releases the memory used by database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>nbytes</td>
    <td>Number of bytes to be released</td>
  </tr>
</table>

\return DLNA_DB_OK if memory is released successfully else returns error. Please see Error Code Table

\par Description:
This function releases the database memory specified in input number of bytes.
*/
slim_int
dlnaDatabaseReleaseMemoryPeer(slim_int nbytes);


#ifdef DEVELOPMENT_DATABASE_STATEMENTS_PRECOMPILATION

slim_int
dlnaDatabaseBindIntPeer(dlna_db_stmt in_stmt, slim_int index, slim_int value);

#endif /* DEVELOPMENT_DATABASE_STATEMENTS_PRECOMPILATION */


/*!
\par Function:
Binds the values to the Prepared Database Statements
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>in_stmt</td>
    <td>Pointer to database Prepared Statement</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>index</td>
    <td>Position where the value needs to be binded</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>value</td>
    <td>value to be binded to the prepared statement</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>nbytes</td>
    <td>Number of bytes in the parameter</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>destructor_type</td>
    <td>Bind destructor type. See Bind Destructor Type Table for different types</td>
  </tr>
</table>

\return DLNA_DB_OK if memory is released successfully else returns error. Please see Error Code Table

\par Description:
This function releases the database memory specified in input number of bytes.
*/
slim_int 
dlnaDatabaseBindTextPeer(dlna_db_stmt in_stmt, slim_int index, slim_char* value, slim_int nbytes, slim_int destructor_type);

/*!
\par Function:
Enables Foreign Key for database connections
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
</table>

\return DLNA_DB_OK if Foreign Key is enabled successfully else returns error. Please see Error Code Table

\par Description:
This function enables the foreign keys for the input database connections. By default Foreign Keys are not enabled for Database connections.
*/
slim_int
dlnaDatabaseEnableForeignKeyPeer(dlna_db_handle handle);

/*!
\par Function:
Sets soft heap size for the database
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>nbytes</td>
    <td>Number of bytes of Heap to be set</td>
  </tr>
</table>

\return DLNA_DB_OK if heap memory is set successfully else returns error. Please see Error Code Table

\par Description:
This function Sets the heap size in input number of bytes for the database. If the heap sizes increases beyond the input number of bytes, the extra used memory is freed.
If not permitted to free, it is not freed.
*/
void
dlnaDatabaseSetSoftHeapPeer(slim_int nbytes);

/*!
\par Function:
Gets teh Error Message for the last failure on the database connection
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
</table>

\return the string error message

\par Description:
This function returns the string error message for the last failure on the database connection.
*/
slim_char*
dlnaDatabaseGetErrorMsgPeer(dlna_db_handle handle);

/*!
\par Function:
Gets the tables list of the database connection
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
</table>

\return dlna_db_tables pointer to the database tables list

\par Description:
This function returns the list of database tables for the given database connection
*/
dlna_db_tables
dlnaDatabaseGetTablesListPeer(dlna_db_handle handle);

/*!
\par Function:
Gets the table count from the database table list
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>tables</td>
    <td>Input table list</td>
  </tr>
</table>

\return the database table count for the connection

\par Description:
This function returns the number of tables from the table list for the given database connection.
*/
slim_int
dlnaDatabaseGetTablesCountPeer(dlna_db_tables tables);

/*!
\par Function:
Gets the table name from the list of tables
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
   <tr>
    <td>[in]</td>
    <td>tables</td>
    <td>Input table list</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>table_index</td>
    <td>Index of the table in the table list</td>
  </tr>
</table>

\return the database table name from the list of tables

\par Description:
This function returns the name of the database table from the list of tables with the index of the table
*/
slim_char*
dlnaDatabaseGetTablePeer(dlna_db_handle handle, dlna_db_tables tables, slim_int table_index);

/*!
\par Function:
Frees the tables list
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>tables</td>
    <td>Input table list</td>
  </tr>
</table>

\return

\par Description:
This function frees the tables list
*/
void
dlnaDatabaseFreeTablesListPeer(dlna_db_tables tables);

/*!
\par Function:
Gets the Indices list of the database connection
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
</table>

\return dlna_db_indices pointer to the database tables list

\par Description:
This function returns the list of database indices for the given database connection
*/
dlna_db_indices
dlnaDatabaseGetIndicesListPeer(dlna_db_handle handle);

/*!
\par Function:
Gets the indices count from the database indices list
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>indices</td>
    <td>Input table list</td>
  </tr>
</table>

\return the database indices count from the indices list

\par Description:
This function returns the number of indices from the table list for the given database connection.
*/
slim_int
dlnaDatabaseGetIndicesCountPeer(dlna_db_indices indices);

/*!
\par Function:
Gets the table name from the list of tables
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
   <tr>
    <td>[in]</td>
    <td>indices</td>
    <td>Input table list</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>index</td>
    <td>Index of database index from the indices table</td>
  </tr>
</table>

\return the database index name from the list of indices

\par Description:
This function returns the name of the database index from the list of indices with the number of the index from the list
*/
slim_char*
dlnaDatabaseGetIndexPeer(dlna_db_handle handle, dlna_db_indices indices, slim_int index);

/*!
\par Function:
Frees the indices list
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>indices</td>
    <td>Input table list</td>
  </tr>
</table>

\return

\par Description:
This function frees the indices list
*/
void
dlnaDatabaseFreeIndicesListPeer(dlna_db_indices indices);

/*!
\par Function:
Sets the callback for busy handler
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the Database connection</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>in_callback_func</td>
    <td>Callback function pointer</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>callback_arg</td>
    <td>callback function argument</td>
  </tr>
</table>

\return DLNA_DB_OK if busy handler callback is set successfully else returns error. Please see Error Code Table

\par Description:
This function sets the busy handler callback and the callback function is triggered if the database busy is notified.
*/
void
dlnaDatabaseSetBusyHandlerPeer(dlna_db_handle in_handle, dlna_db_busy_handler_callback in_callback_func, void* callback_arg);

/*!
\par Function:
Explains the database Query Plan to optimize the queries
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>pStmt</td>
    <td>Handle to the database Prepared Statement</td>
  </tr>
</table>

\return DLNA_DB_OK if Query Plan has been printed out correctly is set successfully else returns error. Please see Error Code Table

\par Description:
This function is just a helper peer function to optimize the database queries. The implementation shall vary depending upon the database integarated.
It takes the prepared statement of a query and explains the following:
    - name of the table read from
    - if an index or automatic index is used
    - if any covering index optimization applies or not
    - which terms of the "WHERE" clause are used for indexing
    - the estimated number of rows the database will visit
This function just prints the output for the developer to optimize the queries and improve the Performance of the database interfaces
*/
slim_int
dlnaDatabaseExplainQueryPlanPeer(dlna_db_stmt pStmt);

/*!
\par Function:
Explains the database Query Plan to optimize the queries
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>Handle to the database connection</td>
  </tr>
</table>

\return DLNA_DB_OK if Query Plan has been printed out correctly is set successfully else returns error. Please see Error Code Table

\par Description:
This function gathers statistics about tables and indices and stores the collected information in a special table in the database
where the query optimizer can use it to help make better query planning choices.
*/
slim_int
dlnaDatabaseAnalyzePeer(dlna_db_handle handle);

/*!
\par Function:
Prints log of memory usage stats

\return void

\par Description:
This function gathers statistics about tables and indices and stores the collected information in a special table in the database
where the query optimizer can use it to help make better query planning choices.
*/
void
dlnaDatabaseMemoryStatusLog(void);

#ifdef DLNA_DB_MEMSYS5_ALLOCATOR
/*!
\par Function:
Enables SQLite MEMSYS5 memory allocator
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>mem_size</td>
    <td>Size of memory buffer to be provided for MEMSYS5</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>min_alloc_size</td>
    <td>Minimum size of a single allocation</td>
  </tr>
</table>

\return DLNA_DB_OK if MEMSYS5 configured successfully else returns error. Please see Error Code Table

\par Description:
Function enables MEMSYS5 memory allocator of SQLite. SQLITE_ENABLE_MEMSYS5 must first be enabled when
building the SQLite library. When MEMSYS5 is enabled the application will allocate a big memory buffer
of "mem_size" bytes which will be used by SQLite MEMSYS5 allocator. No calls to system malloc function
will be done, the allocator will use only the memory provided in the buffer.
Second param is the minimum allocation size. Setting this value properly together with buffer size will
result in less fragmentation and can assure no memory breaks (Robson proof).
The size of a maximum memory used on a system can be checked experimentally with function
dlnaDatabaseMemoryStatusLog() (DLNA_DB_MEMORY_STATS_LOG compilation flag must be enabled)
More information about the allocator and Robson proof can be found on http://www.sqlite.org/malloc.html
website.
*/
slim_int
dlnaDatabaseConfigureMemsys5Allocator(slim_int mem_size, slim_int min_alloc_size);
#endif /* DLNA_DB_MEMSYS5_ALLOCATOR */

#ifdef DLNA_DB_LOOKASIDE_ALLOCATOR_CONFIG
/*!
\par Function:
Configures SQLite lookaside memory allocator
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>slot_size</td>
    <td>Size of a single memory slot</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>slot_count</td>
    <td>Count of the slots</td>
  </tr>
</table>

\return DLNA_DB_OK if MEMSYS5 configured successfully else returns error. Please see Error Code Table

\par Description:
Lookaside memory allocator prealocates a single large chunk of memory for each database conection.
It is used for many small allocation done by the SQLite. It is enabled by default and is about
50KB per connection. With this function the lookaside memory allocator can be configured to use less
or more memory or even turned off by setting both params to 0. The buffer for lookaside memory allocator
consists of several slots of the same size. This is why it is fast and easy to manage them. When slot size
is to small or all slots are taken then general purpose memory allocator is used (e.g. MEMSYS5).
More information about the allocator can be found on http://www.sqlite.org/malloc.html website.
*/
slim_int
dlnaDatabaseConfigureLookasideAllocator(slim_int slot_size, slim_int slot_count);
#endif /* DLNA_DB_LOOKASIDE_ALLOCATOR_CONFIG */

#ifdef DLNA_DB_SCRATCH_MEMORY_CONFIG
/*!
\par Function:
Configures SQLite scratch memory allocator
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>single_allocation_size</td>
    <td>Size of a single scratch allocation</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>simultaneous_alloc_count</td>
    <td>Count of maximum simultaneous scratch allocations</td>
  </tr>
</table>

\return DLNA_DB_OK if MEMSYS5 configured successfully else returns error. Please see Error Code Table

\par Description:
"SQLite occasionally needs a large chunk of "scratch" memory to perform some transient calculation."
(www.sqlite.org). This is why SQLite allocates some large chunk of memory (about 10KB). On embedded
systems this may lead to heap fragmentation. This function provides an interface to set a separate
buffer preallocated by the application to use as scratch memory. The first param is the size of a
single scratch allocation and this should be about 10KB. The second param is the number of maximum
simultaneous scratch allocations. As a single thread will never use more than two scratch allocations
at one time safe value is twice the number of threads that use SQLite. The buffer size will be
(single_allocation_size * simultaneous_alloc_count)
Scratch memory is disables by default which is the same as setting both params to 0.
The size of a maximum scratch allocation on a system can be checked experimentally with function
dlnaDatabaseMemoryStatusLog() (DLNA_DB_MEMORY_STATS_LOG compilation flag must be enabled)
More information about the allocator can be found on http://www.sqlite.org/malloc.html website.
*/
slim_int
dlnaDatabaseConfigureScratchAllocator(slim_int single_allocation_size, slim_int simultaneous_alloc_count);
#endif /* DLNA_DB_SCRATCH_MEMORY_CONFIG */

#ifdef DLNA_DB_PAGE_CACHE_MEMORY_CONFIG
/*!
\par Function:
Configures page cache memory allocator for SQLite
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>single_page_cache_size</td>
    <td>Size of a single page cache</td>
  </tr>
  <tr>
    <td>[in]</td>
    <td>page_cache_count</td>
    <td>Maximum number of pages to be stored in the buffer</td>
  </tr>
</table>

\return DLNA_DB_OK if MEMSYS5 configured successfully else returns error. Please see Error Code Table

\par Description:
This function can enable a separate allocator for storing page cache information. A preallocated buffer
of size (single_page_cache_size * page_cache_count) will be used for this purpose.
The size of a single page cache on a system can be checked experimentally with function
dlnaDatabaseMemoryStatusLog() (DLNA_DB_MEMORY_STATS_LOG compilation flag must be enabled)
More information about the allocator can be found on http://www.sqlite.org/malloc.html website.
*/
slim_int
dlnaDatabaseConfigurePageCacheAllocator(slim_int single_page_cache_size, slim_int page_cache_count);
#endif /* DLNA_DB_PAGE_CACHE_MEMORY_CONFIG */

/*!
\par Function:
Returns number of rows modified, inserted or deleted by the most recent call
\par Parameters:

<table>
  <tr>
    <td>[in]</td>
    <td>handle</td>
    <td>database connection handle of the main database</td>
  </tr>
</table>

\return Number of rows modified, inserted or deleted by the most recent call

\par Description:
This function returns number of rows modified, inserted or deleted by the most recent
call to UPDATE, INSERT or DELETE
*/
slim_int
dlnaDatabaseRowsModifiedNumber(dlna_db_handle handle);

#endif /*_DATABASE_PEER_H*/
