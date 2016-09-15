/*
 * nflc_uuid.h
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

/* UUID - Universally Unique Identifier generator.  */

#ifndef NFLC_UUID_H
#define NFLC_UUID_H

/* UUID node identifier size.  */
#define UUID_NODE_ID_SIZE          6

/* UUID string size.  */
#define UUID_STRING_SIZE           36

/* UUID time hi and version string size.  */
#define UUID_VERSION_STRING_SIZE   4

/* UUID Clock sequence and reserved string size.  */
#define UUID_RESERVED_STRING_SIZE  4

/* UUID node identifier string size.  */
#define UUID_NODE_ID_STRING_SIZE   12

/* Version string offset.  */
#define UUID_VERSION_STRING_OFFSET 14

/* Node ID string offset.  */
#define UUID_NODE_ID_STRING_OFFSET 24

/* UDN "uuid:" prefix size.  */
#define UDN_PREFIX_SIZE            5

/* UDN string size. (Additional "uuid:" prefix to UUID)  */
#define UDN_STRING_SIZE           (UUID_STRING_SIZE + UDN_PREFIX_SIZE)

/* UDN version string offset. (Additional "uuid:" prefix to UUID)  */
#define UDN_VERSION_STRING_OFFSET (UUID_VERSION_STRING_OFFSET + UDN_PREFIX_SIZE)

/* UDN node ID string offset. (Additional "uuid:" prefix to UUID)  */
#define UDN_NODE_ID_STRING_OFFSET (UUID_NODE_ID_STRING_OFFSET + UDN_PREFIX_SIZE)

/* UUID structure.  */
struct uuid
{
  /* Current time.  */
  dlna_timeval timeval;

  /* Privious time.  */
  dlna_timeval last_timeval;

  /* For clock adjustment.  */
  slim_word ticks;

  /* Clock sequence.  */
  slim_int clock_seq;

  /* Node identifier.  */
  slim_byte node_id[UUID_NODE_ID_SIZE];

  /* Formatted values.  */
  slim_word time_low;
  slim_half time_mid;
  slim_half time_hi_and_version;
  slim_byte clock_seq_low;
  slim_byte clock_seq_hi_and_reserved;
};

#ifdef __cplusplus
extern "C" {
#endif

struct uuid *
uuid_alloc(void);

#if defined DEVELOPMENT_DLNA_SUPPORT_HNSO | defined __IOS__
void
nflc_uuid_generate(struct uuid *in_uuid, struct uuid *out_uuid);
#else
void
uuid_generate(struct uuid *in_uuid, struct uuid *out_uuid);
#endif

slim_int
uuid_generate_by_string(slim_char *in_udn, struct uuid *out_uuid);

void
uuid_free(struct uuid *in_uuid);

void
uuid_unpack(struct uuid *in_uuid, slim_char *out_str);

/* Utility function to check uuid in string */
slim_bool 
uuid_is_valid(slim_char* in_str);

/* Utility function to check if input string is uuid in format
   "uuid:xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx" */
slim_bool
uuid_is_valid_uuid_str(slim_char* in_str);

void 
uuid_string_to_int(slim_char* uuid_str, slim_byte *uuid_out, slim_word uuid_out_size);

void 
uuid_int_to_string(slim_byte* uuid_int, slim_byte bsize, slim_char* out_str, slim_int out_str_size);

#ifdef __cplusplus
}
#endif

#endif /* NFLC_UUID_H */
