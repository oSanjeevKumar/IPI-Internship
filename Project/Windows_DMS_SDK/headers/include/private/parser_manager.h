/*
 * parser_manager.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef PARSER_MANAGER_H
#define PARSER_MANAGER_H

/* Enums for return value */
enum {
  PARSER_MANAGER_OK = 0,
  PARSER_MANAGER_ALREADY_INITIALIZED,
  PARSER_MANAGER_INVAL_STATE,
  PARSER_MANAGER_INVAL_ARG,
  PARSER_MANAGER_NO_SUITABLE_PARSER,
  PARSER_MANAGER_PARSE_FAILED,
  PARSER_MANAGER_GENERIC_ERROR
};

struct _extension {
  struct _extension *next;
  struct _extension *prev;

  slim_char *value;
};

typedef struct _extension extension_t;

/* Structures */
struct _dlna_media_type {
  List(extension_t *) extension_list;
  slim_char media_type[16];
};

typedef struct _dlna_media_type dlna_media_type_t;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Functions */
slim_int
ParserManager_Initialize (slim_char *in_xml_dir_path, slim_char *in_xml_filename);

void
ParserManager_Finalize (void);

slim_int
ParserManager_GetSupportedMediaTypesCount (void);

slim_int
ParserManager_GetSupportedMediaTypes (dlna_media_type_t *out_supportlist);

slim_int
ParserManager_GetCtypeByFilePath (slim_char *in_filepath);

slim_int
ParserManager_GetMetadata (slim_char *in_filepath, minfo_t *out_metadata);

slim_int
ParserManager_ReleaseMetadata (minfo_t *in_metadata);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PARSER_MANAGER_H */
