/*
 * extension_register.h
 * Copyright (C) 2013 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef EXTENSION_REGISTER_H
#define EXTENSION_REGISTER_H

#ifdef __cplusplus
extern "C"
# endif
slim_int
extension_checker_lookup_registered_extensions(slim_char *in_suffix, slim_char *out_media_name);

slim_int
extension_checker_convert_media_name_to_contents_type(slim_char *in_media_name);

#endif /* EXTENSION_REGISTER_H */

