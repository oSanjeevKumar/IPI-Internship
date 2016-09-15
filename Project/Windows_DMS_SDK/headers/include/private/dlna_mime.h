/*
 * dlna_mime.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2006 IP Infusion, Inc. All Rights Reserved.  */

#ifndef NFLC_DLNA_MIME_H
#define NFLC_DLNA_MIME_H

/* Contents types.  */
typedef enum mime_type
  {
    no_mime_type_found,       /* no mime type apropriate */
    video_mp4,	              /* all mp4 video and audio fit into this category */
    video_H264,	              /* H.264 specific. video/mp4 might still be appropriate */
    video_H263,	              /* H.263 specific. video/mp4 might still be appropriate */
    video_mpeg,	              /* mpeg 2 video */
    video_asf,	              /* ASF file type with video */
    video_vnd_dlna_mpeg_tts,  /* MPEG2 with timestamp */
    audio_asf,	              /* ASF file type with audio only */
    audio_mp4,	              /* Audio only mp4 (AAC). video/mp4 is also appropriate for audio only files. */
    audio_3gpp,
    audio_adts_aac,
    video_3gpp,
    audio_l16,	              /* lpcm */
    audio_mpeg,	              /* mp3 */
    image_jpeg,	              /* jpeg */
    image_png,	              /* png */
    image_pcx,                /* pcx */
    image_ppm,                /* ppm */
    image_bmp,	              /* bitmap pictures */
    image_gif,	              /* GIFs */
    playlist_m3u,             /* m3u */
    playlist_pls,             /* pls */
		video_quicktime,
	video_avi,					/* AVI */
	video_divx,					/* DivX */
	audio_wav,					/* WAV */
#ifdef DLNA_DMS_SUPPORT_AC3
	audio_ac3,
#endif /* DLNA_DMS_SUPPORT_AC3 */
	audio_ov,
	image_tiff,
	video_flv,
  audio_atrac,
  disc_image_iso,
  disc_image_img,
  video_dvrms,
	video_mj2,
  dlna_last_mime,
#ifdef DEVELOPMENT_DLNA_DMS_SUPPORT_AIFF
  audio_aiff					/* AIFF/AIF */
#endif
} mime_type_t;

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus  */

const slim_char *
dlna_getMimeString(mime_type_t enType);

#ifdef __cplusplus
	}
#endif	/* __cplusplus */

#endif /* NFLC_DLNA_MIME_H */
