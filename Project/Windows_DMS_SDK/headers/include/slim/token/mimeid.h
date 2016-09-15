/*
	mimeid.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_MIMEID_H
#define SLIM_TOKEN_MIMEID_H


SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_TKID_MIME____ = 0,
	SLIM_TKID_MIME_text__,
	SLIM_TKID_MIME_application__,
	SLIM_TKID_MIME_image__,
	SLIM_TKID_MIME_audio__,
	SLIM_TKID_MIME_video__,
	SLIM_TKID_MIME_model__,
	SLIM_TKID_MIME_message__,
	SLIM_TKID_MIME_multipart__,
	SLIM_TKID_MIME_x_world__,
	SLIM_TKID_MIME_text_html,
	SLIM_TKID_MIME_application_xhtml_xml,
	SLIM_TKID_MIME_text_plain,
	SLIM_TKID_MIME_text_xml,
	SLIM_TKID_MIME_application_xml,
	SLIM_TKID_MIME_image_gif,
	SLIM_TKID_MIME_image_jpeg,
	SLIM_TKID_MIME_image_pjpeg,
	SLIM_TKID_MIME_image_png,
	SLIM_TKID_MIME_image_bmp,
	SLIM_TKID_MIME_video_x_mng,
	SLIM_TKID_MIME_text_css,
	SLIM_TKID_MIME_text_javascript,
	SLIM_TKID_MIME_application_x_javascript,
	SLIM_TKID_MIME_application_smil,
	SLIM_TKID_MIME_message_rfc822,
	SLIM_TKID_MIME_multipart_mixed,
	SLIM_TKID_MIME_multipart_related,
	SLIM_TKID_MIME_multipart_alternative,
	SLIM_TKID_MIME_multipart_byteranges,
	SLIM_TKID_MIME_application_rdf_xml,
	SLIM_TKID_MIME_application_rss_xml,
	SLIM_TKID_MIME_application_atom_xml,
	SLIM_TKID_MIME_application_opml_xml,
	SLIM_TKID_MIME_application_x_netcdf,
	SLIM_TKID_MIME_application_x_xbel,
	SLIM_TKID_MIME_application_x_url,
	SLIM_TKID_MIME_text_vnd_wap_wml,
	SLIM_TKID_MIME_image_vnd_wap_wbmp,
	SLIM_TKID_MIME_text_vnd_wap_wmlscript,
	SLIM_TKID_MIME_application_vnd_wap_xhtml_xml,
	SLIM_TKID_MIME_application_vnd_wap_wbxml,
	SLIM_TKID_MIME_application_vnd_wap_wmlc,
	SLIM_TKID_MIME_application_vnd_wap_wmlsc,
	SLIM_TKID_MIME_application_vnd_wap_wmlscriptc,
	SLIM_TKID_MIME_image_svg_xml,
	SLIM_TKID_MIME_application_pdf,
	SLIM_TKID_MIME_application_x_shockwave_flash,
	SLIM_TKID_MIME_application_futuresplash,
	SLIM_TKID_MIME_application_x_director,
	SLIM_TKID_MIME_audio_x_pn_realaudio,
	SLIM_TKID_MIME_application_x_java,
	SLIM_TKID_MIME_audio_midi,
	SLIM_TKID_MIME_audio_x_wav,
	SLIM_TKID_MIME_audio_x_aiff,
	SLIM_TKID_MIME_audio_basic,
	SLIM_TKID_MIME_video_mpeg,
	SLIM_TKID_MIME_audio_mpeg,
	SLIM_TKID_MIME_application_vnd_oma_drm_message,
	SLIM_TKID_MIME_application_vnd_oma_drm_rights_xml,
	SLIM_TKID_MIME_application_vnd_oma_drm_rights_wbxml,
	SLIM_TKID_MIME_application_vnd_oma_drm_content,
	SLIM_TKID_MIME_application_x_www_form_urlencoded,
	SLIM_TKID_MIME_multipart_form_data,
	SLIM_TKID_MIME_application_octet_stream,
	SLIM_TKID_MIME_application_x_gzip,
	SLIM_TKID_MIME_application_x_tar,
	SLIM_TKID_MIME_application_zip,
	SLIM_TKID_MIME_video_x_msvideo,
	SLIM_TKID_MIME_video_quicktime,
	SLIM_TKID_MIME_video_3gpp,
	SLIM_TKID_MIME_video_3gpp2,
	SLIM_TKID_MIME_audio_3gpp,
	SLIM_TKID_MIME_audio_3gpp2,
	SLIM_TKID_MIME_video_x_ms_wmv,
	SLIM_TKID_MIME_video_x_ms_asf,
	SLIM_TKID_MIME_video_x_ms_asx,
	SLIM_TKID_MIME_video_x_ms_wvx,
	SLIM_TKID_MIME_video_x_ms_wm,
	SLIM_TKID_MIME_audio_x_ms_wma,
	SLIM_TKID_MIME_audio_x_ms_wax,
	SLIM_TKID_MIME_audio_x_gsm,
	SLIM_TKID_MIME_text_xsl,
	SLIM_TKID_MIME_image_tiff,
	SLIM_TKID_MIME_image_x_icon,
	SLIM_TKID_MIME_image_x_xpixmap,
	SLIM_TKID_MIME_image_x_xbitmap,
	SLIM_TKID_MIME_model_vrml,
	SLIM_TKID_MIME_x_world_x_vrml,
	SLIM_TKID_MIME_application_x_binary_javascript,
	SLIM_TKID_MIME_application_word,
	SLIM_TKID_MIME_application_x_word,
	SLIM_TKID_MIME_application_msword,
	SLIM_TKID_MIME_application_x_msword,
	SLIM_TKID_MIME_application_vnd_ms_word,
	SLIM_TKID_MIME_application_excel,
	SLIM_TKID_MIME_application_x_excel,
	SLIM_TKID_MIME_application_msexcel,
	SLIM_TKID_MIME_application_x_msexcel,
	SLIM_TKID_MIME_application_vnd_ms_excel,
	SLIM_TKID_MIME_text_csv,
	SLIM_TKID_MIME_text_comma_separated_values,
	SLIM_TKID_MIME_application_powerpoint,
	SLIM_TKID_MIME_application_x_powerpoint,
	SLIM_TKID_MIME_application_mspowerpoint,
	SLIM_TKID_MIME_application_x_mspowerpoint,
	SLIM_TKID_MIME_application_vnd_ms_powerpoint,
	SLIM_TKID_MIME_ENUMS
};

#define SLIM_TOKEN_MIME_TOKENS SLIM_TKID_MIME_ENUMS
#define SLIM_TOKEN_MIME_ENUMS SLIM_TKID_MIME_ENUMS


SLIM_END_C_LINKAGE
#endif
