/*
 * upnp_search.h
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

/* UPnP AV search function.  */

#ifndef NFLC_UPNP_SEARCH_H
#define NFLC_UPNP_SEARCH_H

/*
 * Maximum nest depth of search expression.  Default max expression is
 * like "((((((((((S))))))))))".
 */
#define SEARCH_NEST_DEPTH_MAX  (10)

#define SEARCH_PARSE_STACK_MAX (20)

/* Search evaluation callback function.  */
typedef enum search_match_result (*search_callback_t) (cds_search_exp_t *s_exp,
                                                       void *arg);
/* Parse search string.  */
cds_search_exp_t*
upnp_cds_search_parse (slim_char *str);

/* Evaluate search expression against argument arg.  */
enum search_match_result
upnp_cds_search_eval (cds_search_exp_t *s_exp, void *arg, search_callback_t func);

/* Free search expression.  */
void
upnp_cds_search_free (cds_search_exp_t *s_exp);

#endif /* NFLC_UPNP_SEARCH_H */
