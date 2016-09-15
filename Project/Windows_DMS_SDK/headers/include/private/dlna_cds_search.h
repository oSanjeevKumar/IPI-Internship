/*
 * dlna_cds_search.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DLNA_CDS_SEARCH_H
#define NFLC_DLNA_CDS_SEARCH_H

/* Search keywords.  */
enum search_token_type
{
  SEARCH_TOKEN_NOT_EQUAL,
  SEARCH_TOKEN_LESS_THAN,
  SEARCH_TOKEN_LESS_THAN_EQUAL,
  SEARCH_TOKEN_EQUAL,
  SEARCH_TOKEN_GREATER_THAN,
  SEARCH_TOKEN_GREATER_THAN_EQUAL,
  SEARCH_TOKEN_CONTAINS,
  SEARCH_TOKEN_DOES_NOT_CONTAIN,
  SEARCH_TOKEN_DERIVED_FROM,
  SEARCH_TOKEN_EXISTS,

  SEARCH_TOKEN_TRUE,
  SEARCH_TOKEN_FALSE,
  SEARCH_TOKEN_AND,
  SEARCH_TOKEN_OR,
  SEARCH_TOKEN_PAREN_OPEN,
  SEARCH_TOKEN_PAREN_CLOSE,

  SEARCH_TOKEN_STRING_VALUE
};

/* Search match result.  */
enum search_match_result
{
  SEARCH_NOT_MATCH,
  SEARCH_MATCH
};

/* Search expression structure.  */
struct search_exp
{
  /* If set, this is virtual s_exp.  */
  slim_int virtual_link;

  /* If the s_exp is virtual s_exp, this is a pointer to the child
     node.  */
  struct search_exp *child;

  /* Operation of the s_exp.  This must be one of "AND" or "OR".  */
  enum search_token_type op;

  /* Subject of the s_exp match.  */
  dlna_split_ss match_subject;

  /*
   * Match operation of the s_exp.  This must be one of "contains",
   * "doesNotContain", "derivedfrom" or "exists".
   */
  enum search_token_type match_op;

  /*
   * Match object of the s_exp.  This can be string value or
   * boolean value "true" or "false".
   */
  enum search_token_type match_type;
  dlna_split_ss match_val;

  /* Next expression pointer.  */
  struct search_exp *next;
};

typedef struct search_exp cds_search_exp_t;


#endif /* NFLC_DLNA_CDS_SEARCH_H */
