/*
 * dlna_int64.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */


#ifndef NFLC_DLNA_INT64_H
#define NFLC_DLNA_INT64_H

/*** Type definitions ***/

#define DLNA_SINT64_LOW_MAX (0xffffffff)
#define DLNA_SINT64_LOW_MIN (0)
#define DLNA_SINT64_HIGH_MAX (0x7fffffff)
#define DLNA_SINT64_HIGH_MIN (0x80000000)
#define DLNA_SINT64_HIGH_SGN (0xffffffff)

#define DLNA_UINT64_LOW_MAX (0xffffffff)
#define DLNA_UINT64_LOW_MIN (0)
#define DLNA_UINT64_HIGH_MAX (0xffffffff)
#define DLNA_UINT64_HIGH_MIN (0)

#define DLNA_SINT32_MAX (0x7fffffff)
#define DLNA_SINT32_MIN (0x80000000)


#define DLNA_SINT32HL_TO_64(p_si64_out, si32_high_in, si32_low_in) { \
  (p_si64_out)->high= (si32_high_in); \
  (p_si64_out)->low= (si32_low_in); \
}

#define DLNA_UINT32HL_TO_64(p_ui64_out, ui32_high_in, ui32_low_in) { \
  (p_ui64_out)->high= (ui32_high_in); \
  (p_ui64_out)->low= (ui32_low_in); \
}

#define DLNA_SINT64_ISZERO(p_si64_in) ((p_si64_in)->high == 0 && (p_si64_in)->low == 0)

#define DLNA_UINT64_ISZERO(p_ui64_in) ((p_ui64_in)->high == 0 && (p_ui64_in)->low == 0)


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* dlna_sint32 */
void
dlna_sint64_neg(dlna_sint64 *p_si64_out, const dlna_sint64 *p_si64_in);

void
dlna_sint32_to_64(dlna_sint64 *p_si64_out, slim_int si32_in);

void
dlna_sint64_to_32(slim_int *p_si32_out, const dlna_sint64 *p_si64_in);

void
dlna_sint64_add(dlna_sint64 *p_dst_out, const dlna_sint64 *p_src_1_in, const dlna_sint64 *p_src_2_in);

void
dlna_sint64_add_32(dlna_sint64 *p_dst_out, const dlna_sint64 *p_src_1_in, const slim_int src_2_in);

void
dlna_sint64_sub(dlna_sint64 *p_dst_out, const dlna_sint64 *p_src_1_in, const dlna_sint64 *p_src_2_in);

slim_int
dlna_sint64_cmp(const dlna_sint64 *p_src_1_in, const dlna_sint64 *p_src_2_in);



/* dlna_uint32 */
void
dlna_uint32_to_64(dlna_uint64 *p_ui64_out, slim_word ui32_in);

void
dlna_uint64_to_32(slim_word *p_ui32_out, const dlna_uint64 *p_ui64_in);

slim_int
dlna_uint64_cmp(const dlna_uint64 *p_src_1_in, const dlna_uint64 *p_src_2_in);

void
dlna_uint64_add(dlna_uint64 *out_dst, const dlna_uint64 *in_src1, const dlna_uint64 *in_src2);

void
dlna_uint64_add_32(dlna_uint64 *out_dst, const dlna_uint64 *in_src1, const slim_word in_src2);

void
dlna_uint64_sub(dlna_uint64 *p_dst_out, const dlna_uint64 *p_src_1_in, const dlna_uint64 *p_src_2_in);

void
dlna_uint64_sub_32(dlna_uint64 *p_dst_out, const dlna_uint64 *p_src_1_in, const slim_word src_2_in);

void
dlna_uint64_mul(dlna_uint64 *p_dst_out, const dlna_uint64 *p_src_1_in, const slim_word in_src_2);

void 
dlna_uint64_div(dlna_uint64 *p_dst_out, const dlna_uint64 *p_src_1_in, const slim_word in_src_2);

slim_word 
dlna_uint64_mod(const dlna_uint64 *p_src_1_in, const slim_word in_src_2);

slim_int
dlna_uint64_to_str(slim_char *out_buf, slim_int in_buf_len, const dlna_uint64 *in_src);

slim_int 
dlna_str_to_uint64(dlna_uint64 *out_dst, slim_char *in_buf, slim_int in_buf_size);

#ifdef __cplusplus
}
#endif    /* __cplusplus */


#endif /* NFLC_DLNA_INT64_H */
