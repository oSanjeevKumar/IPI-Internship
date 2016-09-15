/*
 * transcoding_utils.h
 * Copyright (C) 2007 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005 IP Infusion, Inc. All Rights Reserved.  */

#ifndef TRANSCODING_UTILS_H_
#define TRANSCODING_UTILS_H_

#include <dlna_peer.h>
#include <nflc_contents.h>
#include "http_parser.h"
#include "http_session.h"

#define SCALE		"scale"
#define NORM		"norm"
#define SCALE_EXP	"?" SCALE "="
#define NORM_EXP	"?" NORM "="

struct file_session
{
  struct file_session *next;
  struct file_session *prev;
  slim_int session_id;
  slim_char *file_name;
};// files_t;

List(struct file_session *) files_list;

slim_char *
handle_transcoded_image_request(contents_t *c, http_message_t *http, http_session_t *session, http_parser_t *parser, http_receiver_t *receiver, slim_char *keyword);

slim_char *
handle_transcoded_audio_video_request(contents_t *c, slim_char *url, slim_int session_id, slim_char *keyword);

void *
transcoding_thread_main(void *args);

void *
transcoding_image_thread_main(void *args);

slim_int
perform_image_transcoding(slim_char *path, slim_char *output, slim_char *scale);

slim_int
perform_av_transcoding(slim_char *path, slim_char *output, slim_char *norm, slim_char *type);

struct file_session *
add_new_file_session(slim_int session_id, slim_char *path);

void
clean_transcoded_files(slim_word session_id);

slim_char *
create_transcoded_file_name(slim_char *url, slim_char *ext, slim_char *keyword);

slim_char *
create_transcoded_dir_path(slim_char *usb_path);

slim_char *
create_transcoded_file_path(slim_char *usb_path, slim_char *file_name);

void
parse_scale(slim_char *scale, slim_int *width, slim_int *height);

slim_char *
remove_prohibited_chars(slim_char *str);


#endif /* TRANSCODING_UTILS_H_ */

#ifndef TRANSCODING_UTILS_H_
#define TRANSCODING_UTILS_H_


#endif /* TRANSCODING_UTILS_H_ */
