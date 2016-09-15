/*
 * dlna_link_protect_utils.h
 * Copyright (C) 2010-2011 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef _DLNA_LPTT_API_H
#define _DLNA_LPTT_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* function declaration */

/**
 * @brief Calculate the sent content pcp encryption length from cleartext length
 * @param[in] in_file_size Content clear text length
 * @return dlna_uint64 PCP encryption length
 * @details This function rely on the assumption that the sent content is DLNA_HTTP_LARGE_BUFFER_SIZE.
*/
dlna_uint64 dlna_link_protect_utils_get_pcp_len(dlna_uint64 in_file_size);

/**
 * @brief Retrieve the seek position into a cleartext file from pcp encrypted seek position
 * @param[in] in_seek PCP encrypted file seek position 
 * @return  dlna_uint64 Corresponding position corresponding into the cleartext file
 * @details This function rely on the assumption that the sent content is DLNA_HTTP_LARGE_BUFFER_SIZE.
*/
dlna_uint64 dlna_link_protect_utils_get_pcp_seek64(dlna_uint64 in_seek);

/**
 * @brief Retrieve the seek position into a cleartext file from pcp encrypted seek position
 * @param[in] in_seek PCP encrypted file seek position 
 * @return dlna_off_t Corresponding position corresponding into the cleartext file
 * @details This function rely on the assumption that the sent content is DLNA_HTTP_LARGE_BUFFER_SIZE.
*/
dlna_off_t dlna_link_protect_utils_get_pcp_seek(dlna_off_t in_seek);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DLNA_LPTT_API_H */

