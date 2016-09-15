/*
	mime.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/inet/mime.h 48    06/06/13 16:19 Nosakatetsuro $ */

#ifndef SLIM_MIME_H
#define SLIM_MIME_H

#include <slim/token/mimeid.h>

SLIM_BEGIN_C_LINKAGE

#define SLIM_MIME_UNKNOWN							(-1)
#define SLIM_MIME_UNCERTAIN							(-2)	/* used for the return value of MIME_Guess() */

#define SLIM_MIME_DEFAULT_DEFAULT					SLIM_TKID_MIME____
#define SLIM_MIME_TEXT_DEFAULT						SLIM_TKID_MIME_text__
#define SLIM_MIME_APPLICATION_DEFAULT				SLIM_TKID_MIME_application__
#define SLIM_MIME_IMAGE_DEFAULT						SLIM_TKID_MIME_image__
#define SLIM_MIME_AUDIO_DEFAULT						SLIM_TKID_MIME_audio__
#define SLIM_MIME_VIDEO_DEFAULT						SLIM_TKID_MIME_video__
#define SLIM_MIME_MODEL_DEFAULT						SLIM_TKID_MIME_model__
#define SLIM_MIME_MESSAGE_DEFAULT					SLIM_TKID_MIME_message__
#define SLIM_MIME_MULTIPART_DEFAULT					SLIM_TKID_MIME_multipart__

#define SLIM_MIME_TEXT_HTML							SLIM_TKID_MIME_text_html
#define SLIM_MIME_APPLICATION_XHTML					SLIM_TKID_MIME_application_xhtml_xml
#define SLIM_MIME_APPLICATION_XHTMLMP				SLIM_TKID_MIME_application_vnd_wap_xhtml_xml
#define SLIM_MIME_TEXT_PLAIN						SLIM_TKID_MIME_text_plain
#define SLIM_MIME_TEXT_XML							SLIM_TKID_MIME_text_xml
#define SLIM_MIME_APPLICATION_XML					SLIM_TKID_MIME_application_xml
#define SLIM_MIME_IMAGE_GIF							SLIM_TKID_MIME_image_gif
#define SLIM_MIME_IMAGE_JPEG						SLIM_TKID_MIME_image_jpeg
#define SLIM_MIME_IMAGE_PJPEG						SLIM_TKID_MIME_image_pjpeg
#define SLIM_MIME_IMAGE_PNG							SLIM_TKID_MIME_image_png
#define SLIM_MIME_IMAGE_BMP							SLIM_TKID_MIME_image_bmp
#define SLIM_MIME_VIDEO_X_MNG						SLIM_TKID_MIME_video_x_mng
#define SLIM_MIME_TEXT_CSS							SLIM_TKID_MIME_text_css
#define SLIM_MIME_TEXT_JAVASCRIPT					SLIM_TKID_MIME_text_javascript
#define SLIM_MIME_APPLICATION_X_JAVASCRIPT			SLIM_TKID_MIME_application_x_javascript
#define SLIM_MIME_APPLICATION_SMIL					SLIM_TKID_MIME_application_smil
#define SLIM_MIME_MESSAGE_RFC822					SLIM_TKID_MIME_message_rfc822
#define SLIM_MIME_APPLICATION_OCTET_STREAM			SLIM_TKID_MIME_application_octet_stream
#define SLIM_MIME_APPLICATION_X_GZIP				SLIM_TKID_MIME_application_x_gzip

#define SLIM_MIME_MULTIPART_MIXED					SLIM_TKID_MIME_multipart_mixed
#define SLIM_MIME_MULTIPART_RELATED					SLIM_TKID_MIME_multipart_related
#define SLIM_MIME_MULTIPART_ALTERNATIVE				SLIM_TKID_MIME_multipart_alternative
#define SLIM_MIME_MULTIPART_BYTERANGES				SLIM_TKID_MIME_multipart_byteranges

#define SLIM_MIME_APPLICATION_RDF					SLIM_TKID_MIME_application_rdf_xml
#define SLIM_MIME_APPLICATION_RSS					SLIM_TKID_MIME_application_rss_xml
#define SLIM_MIME_APPLICATION_ATOM					SLIM_TKID_MIME_application_atom_xml
#define SLIM_MIME_APPLICATION_OPML					SLIM_TKID_MIME_application_opml_xml
#define SLIM_MIME_APPLICATION_X_NETCDF				SLIM_TKID_MIME_application_x_netcdf
#define SLIM_MIME_APPLICATION_X_XBEL				SLIM_TKID_MIME_application_x_xbel
#define SLIM_MIME_APPLICATION_X_URL					SLIM_TKID_MIME_application_x_url

#define SLIM_MIME_TEXT_WML							SLIM_TKID_MIME_text_vnd_wap_wml
#define SLIM_MIME_IMAGE_WBMP						SLIM_TKID_MIME_image_vnd_wap_wbmp
#define SLIM_MIME_TEXT_WMLSCRIPT					SLIM_TKID_MIME_text_vnd_wap_wmlscript
#define SLIM_MIME_APPLICATION_WBXML					SLIM_TKID_MIME_application_vnd_wap_wbxml
#define SLIM_MIME_APPLICATION_WMLC					SLIM_TKID_MIME_application_vnd_wap_wmlc
#define SLIM_MIME_APPLICATION_WMLSC					SLIM_TKID_MIME_application_vnd_wap_wmlsc
#define SLIM_MIME_APPLICATION_WMLSCRIPTC			SLIM_TKID_MIME_application_vnd_wap_wmlscriptc

#define SLIM_MIME_IMAGE_SVG							SLIM_TKID_MIME_image_svg_xml
#define SLIM_MIME_APPLICATION_PDF					SLIM_TKID_MIME_application_pdf
#define SLIM_MIME_APPLICATION_X_SHOCKWAVE_FLASH		SLIM_TKID_MIME_application_x_shockwave_flash
#define SLIM_MIME_APPLICATION_FUTURESPLASH			SLIM_TKID_MIME_application_futuresplash
#define SLIM_MIME_APPLICATION_X_DIRECTOR			SLIM_TKID_MIME_application_x_director
#define SLIM_MIME_AUDIO_X_PN_REALAUDIO				SLIM_TKID_MIME_audio_x_pn_realaudio
#define SLIM_MIME_APPLICATION_X_JAVA				SLIM_TKID_MIME_application_x_java

#define SLIM_MIME_AUDIO_MIDI						SLIM_TKID_MIME_audio_midi
#define SLIM_MIME_AUDIO_X_WAV						SLIM_TKID_MIME_audio_x_wav
#define SLIM_MIME_AUDIO_X_AIFF						SLIM_TKID_MIME_audio_x_aiff
#define SLIM_MIME_AUDIO_BASIC						SLIM_TKID_MIME_audio_basic
#define SLIM_MIME_VIDEO_MPEG						SLIM_TKID_MIME_video_mpeg
#define SLIM_MIME_AUDIO_MPEG						SLIM_TKID_MIME_audio_mpeg

#define SLIM_MIME_APPLICATION_X_WWW_FORM_URLENCODED	SLIM_TKID_MIME_application_x_www_form_urlencoded
#define SLIM_MIME_MULTIPART_FORM_DATA				SLIM_TKID_MIME_multipart_form_data

#define SLIM_MIME_APPLICATION_X_TAR					SLIM_TKID_MIME_application_x_tar
#define SLIM_MIME_APPLICATION_ZIP					SLIM_TKID_MIME_application_zip
#define SLIM_MIME_VIDEO_X_MSVIDEO					SLIM_TKID_MIME_video_x_msvideo
#define SLIM_MIME_VIDEO_QUICKTIME					SLIM_TKID_MIME_video_quicktime
#define SLIM_MIME_VIDEO_3GPP						SLIM_TKID_MIME_video_3gpp
#define SLIM_MIME_VIDEO_3GPP2						SLIM_TKID_MIME_video_3gpp2
#define SLIM_MIME_AUDIO_3GPP						SLIM_TKID_MIME_audio_3gpp
#define SLIM_MIME_AUDIO_3GPP2						SLIM_TKID_MIME_audio_3gpp2
#define SLIM_MIME_VIDEO_X_MS_WMV					SLIM_TKID_MIME_video_x_ms_wmv
#define SLIM_MIME_VIDEO_X_MS_ASF					SLIM_TKID_MIME_video_x_ms_asf
#define SLIM_MIME_VIDEO_X_MS_ASX					SLIM_TKID_MIME_video_x_ms_asx
#define SLIM_MIME_VIDEO_X_MS_WVX					SLIM_TKID_MIME_video_x_ms_wvx
#define SLIM_MIME_VIDEO_X_MS_WM						SLIM_TKID_MIME_video_x_ms_wm
#define SLIM_MIME_AUDIO_X_MS_WMA					SLIM_TKID_MIME_audio_x_ms_wma
#define SLIM_MIME_AUDIO_X_MS_WAX					SLIM_TKID_MIME_audio_x_ms_wax
#define SLIM_MIME_AUDIO_X_GSM						SLIM_TKID_MIME_audio_x_gsm
#define SLIM_MIME_TEXT_XSL							SLIM_TKID_MIME_text_xsl
#define SLIM_MIME_IMAGE_TIFF						SLIM_TKID_MIME_image_tiff
#define SLIM_MIME_IMAGE_X_ICON						SLIM_TKID_MIME_image_x_icon
#define SLIM_MIME_IMAGE_X_XPIXMAP					SLIM_TKID_MIME_image_x_xpixmap
#define SLIM_MIME_IMAGE_X_XBITMAP					SLIM_TKID_MIME_image_x_xbitmap
#define SLIM_MIME_MODEL_VRML						SLIM_TKID_MIME_model_vrml
#define SLIM_MIME_X_WORLD_X_VRML					SLIM_TKID_MIME_x_world_x_vrml
#define SLIM_MIME_APPLICATION_X_BINARY_JAVASCRIPT	SLIM_TKID_MIME_application_x_binary_javascript

#define SLIM_MIME_APPLICATION_WORD					SLIM_TKID_MIME_application_word
#define SLIM_MIME_APPLICATION_X_WORD				SLIM_TKID_MIME_application_x_word
#define SLIM_MIME_APPLICATION_MSWORD				SLIM_TKID_MIME_application_msword
#define SLIM_MIME_APPLICATION_X_MSWORD				SLIM_TKID_MIME_application_x_msword
#define SLIM_MIME_APPLICATION_VND_MS_WORD			SLIM_TKID_MIME_application_vnd_ms_word
#define SLIM_MIME_APPLICATION_EXCEL					SLIM_TKID_MIME_application_excel
#define SLIM_MIME_APPLICATION_X_EXCEL				SLIM_TKID_MIME_application_x_excel
#define SLIM_MIME_APPLICATION_MSEXCEL				SLIM_TKID_MIME_application_msexcel
#define SLIM_MIME_APPLICATION_X_MSEXCEL				SLIM_TKID_MIME_application_x_msexcel
#define SLIM_MIME_APPLICATION_VND_MS_EXCEL			SLIM_TKID_MIME_application_vnd_ms_excel
#define SLIM_MIME_TEXT_CSV							SLIM_TKID_MIME_text_csv
#define SLIM_MIME_TEXT_COMMA_SEPARATED_VALUES		SLIM_TKID_MIME_text_comma_separated_values
#define SLIM_MIME_APPLICATION_POWERPOINT			SLIM_TKID_MIME_application_powerpoint
#define SLIM_MIME_APPLICATION_X_POWERPOINT			SLIM_TKID_MIME_application_x_powerpoint
#define SLIM_MIME_APPLICATION_MSPOWERPOINT			SLIM_TKID_MIME_application_mspowerpoint
#define SLIM_MIME_APPLICATION_X_MSPOWERPOINT		SLIM_TKID_MIME_application_x_mspowerpoint
#define SLIM_MIME_APPLICATION_VND_MS_POWERPOINT		SLIM_TKID_MIME_application_vnd_ms_powerpoint

#define SLIM_MIME_APP_OMA_DRM_MESSAGE				SLIM_TKID_MIME_application_vnd_oma_drm_message
#define SLIM_MIME_APP_OMA_DRM_CONTENT				SLIM_TKID_MIME_application_vnd_oma_drm_content

#define SLIM_MIMES									SLIM_TOKEN_MIME_ENUMS

/* Ugh!: */
#define SLIM_MIME_TEXT_SMIL							SLIM_MIME_APPLICATION_SMIL
#define SLIM_MIME_APPLICATION_VND_WAP_XHTML_XML		SLIM_MIME_APPLICATION_XHTMLMP


#define SLIM_MIME_USER_EXTEND_ID_START			(10000)
#define SLIM_MIME_USER_EXTEND_ID_END			(20000)

typedef struct TMIMEInfoClass_ TMIMEInfoClass;
struct TMIMEInfoClass_ {
	TDataArena *fDataArena;
	slim_pix fMIMETypeTree;
	slim_pix fSuffixTree;
	slim_pix fDefaultMIMETypePix;
	slim_pix fAnonPrimaryTypePix;
	slim_int fNextAllocID;
};

struct TSuffixInfo_ {
	slim_char *fSuffix;
	slim_int fLength;
};
typedef struct TSuffixInfo_ TSuffixInfo;

struct TSuffixBind_ {
	slim_int fBindType;
	slim_int fMIMETypeID;
};
typedef struct TSuffixBind_ TSuffixBind;

struct TMIMEPrimaryTypeInfo_ {
	slim_char *fPrimaryType;
	slim_int fLength;
	slim_pix fDefaultMIMETypePix;
};
typedef struct TMIMEPrimaryTypeInfo_ TMIMEPrimaryTypeInfo;

struct TMIMETypeInfo_ {
	slim_int fFlag;
	slim_int fMIMETypeID;
	slim_char *fMIMEType;
};
typedef struct TMIMETypeInfo_ TMIMETypeInfo;

#define SLIM_MIMEINFO_FINDFLAG_BY_SS		0x00000001
#define SLIM_MIMEINFO_FINDFLAG_BY_SUFFIX	0x00000002
#define SLIM_MIMEINFO_FINDFLAG_BY_ID		0x00000004
#define SLIM_MIMEINFO_FINDFLAG_BYMASK		0x0000000f

#define SLIM_MIMEINFO_FINDFLAG_WILDCARD		0x00000010

#define SLIM_MIMEINFO_BINDTYPE_DEFAULT		0x00000000
#define SLIM_MIMEINFO_BINDTYPE_PLUGIN		0x00010000
#define SLIM_MIMEINFO_BINDMASK				0x00ff0000

#define SLIM_MIMEINFO_FINDBY_SS				(SLIM_MIMEINFO_FINDFLAG_BY_SS|SLIM_MIMEINFO_BINDTYPE_DEFAULT)
#define SLIM_MIMEINFO_FINDBY_SUFFIX_DEFAULT	(SLIM_MIMEINFO_FINDFLAG_BY_SUFFIX|SLIM_MIMEINFO_BINDTYPE_DEFAULT)

/* API */

#define MIMEInfo_IDFindSS(cls, s, len) (MIMEInfo_IDFindByX((cls), (s), (len), SLIM_MIMEINFO_FINDBY_SS))
#define MIMEInfo_IDFindBySuffix(cls, s, len) (MIMEInfo_IDFindByX((cls), (s), (len), SLIM_MIMEINFO_FINDBY_SUFFIX_DEFAULT))
#define MIMEInfo_Register(cls, type, suf, id) (MIMEInfo_RegisterX((cls), (type), (suf), (id), SLIM_FLAG_NONE, slim_true))

SLIM_END_C_LINKAGE
#endif
