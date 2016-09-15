/*
	url.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/inet/url.h 75    06/06/20 23:40 Yamabuti $ */

#ifndef SLIM_URL_H_PRIVATE
#define SLIM_URL_H_PRIVATE

#include <slim/private/token/scheme.h>

SLIM_BEGIN_C_LINKAGE

/*						*/
/* absolute URL string	*/
/*						*/

#define TURLString_Use(self, count) (TFixedString_Use((self), (count)))
#define TURLString_Locate(self) (TFixedString_Locate(self))
#define TURLString_Unlocate(self) (TFixedString_Unlocate(self))
#define TURLString_Hash(self) (TFixedString_Hash(self))
#define TURLString_EqualUS(self,fs) (TFixedString_EqualFS((self),(fs)))
#define TURLString_IsWhite(self) (TFixedString_IsWhite(self))

/* TURLSchemeInfoClass */

/*
	URI conversion flags

	SLIM_URI_CONV_PCTENC_CTRL:			percent-encode control characters
	SLIM_URI_CONV_PCTENC_SPACE:			percent-encode spaces
	SLIM_URI_CONV_PCTENC_SYMBOL:		percent-encode ASCII symbol characters (not RFC 2396/3986 unreserved nor reserved)
	SLIM_URI_CONV_PCTENC_NONASCII:		percent-encode Non-ASCII characters
	SLIM_URI_CONV_PCTDEC_UNRESERVED:	percent-decode RFC 2396/3986 unreserved characters
	SLIM_URI_CONV_PCTDEC_RESERVED:		percent-decode RFC 2396/3986 reserved characters
	SLIM_URI_CONV_PCTDEC_SPACE:			percent-decode spaces
	SLIM_URI_CONV_PCTDEC_SYMBOL:		percent-decode ASCII symbol characters (not RFC 2396/3986 unreserved nor reserved)
	SLIM_URI_CONV_PCTDEC_NONASCII:		percent-decode Non-ASCII characters
	SLIM_URI_CONV_PCTCASE:				transform characters of percent-encoding to uppercase
	SLIM_URI_CONV_USE_RFC2396:			use the definition not of RFC 3986 but of RFC 2396 as reserved/unreserved characters
	SLIM_URI_CONV_LOWERCASE:			transform ALPHA to lowercase (for scheme or host part)
	SLIM_URI_CONV_BACKSLASH:			convert '\' to '/' (for path part)
	SLIM_URI_CONV_IDN_TO_ASCII:			convert IDN to ASCII (punycode)
	SLIM_URI_CONV_IDN_TO_UNICODE:		convert IDN to Unicode
	SLIM_URI_CONV_ZAP_PART:				zap the whole of this part
*/
#define SLIM_URI_CONV_PCTENC_CTRL			0x00000001
#define SLIM_URI_CONV_PCTENC_SPACE			0x00000002
#define SLIM_URI_CONV_PCTENC_SYMBOL			0x00000004
#define SLIM_URI_CONV_PCTENC_NONASCII		0x00000008
#define SLIM_URI_CONV_PCTDEC_UNRESERVED		0x00000010
#define SLIM_URI_CONV_PCTDEC_RESERVED		0x00000020
#define SLIM_URI_CONV_PCTDEC_SPACE			0x00000040
#define SLIM_URI_CONV_PCTDEC_SYMBOL			0x00000080
#define SLIM_URI_CONV_PCTDEC_NONASCII		0x00000100
#define SLIM_URI_CONV_PCTCASE				0x00000200
#define SLIM_URI_CONV_USE_RFC2396			0x00000400
#define SLIM_URI_CONV_LOWERCASE				0x00000800
#define SLIM_URI_CONV_IDN_TO_ASCII			0x00001000
#define SLIM_URI_CONV_IDN_TO_UNICODE		0x00002000
#define SLIM_URI_CONV_ZAP_PART				0x00004000

#define SLIM_URI_CONV_PCTENC_MASK	(SLIM_URI_CONV_PCTENC_CTRL			| \
									 SLIM_URI_CONV_PCTENC_SPACE			| \
									 SLIM_URI_CONV_PCTENC_SYMBOL		| \
									 SLIM_URI_CONV_PCTENC_NONASCII)
#define SLIM_URI_CONV_PCTDEC_MASK	(SLIM_URI_CONV_PCTDEC_UNRESERVED	| \
									 SLIM_URI_CONV_PCTDEC_RESERVED		| \
									 SLIM_URI_CONV_PCTDEC_SPACE			| \
									 SLIM_URI_CONV_PCTDEC_SYMBOL		| \
									 SLIM_URI_CONV_PCTDEC_NONASCII)

/* URI resolving/normalization flag */
#define SLIM_URIRSLV_FLAG_FORCE_CONV_CHARSET	0x00000001
#define SLIM_URIRSLV_FLAG_SKIP_EOL_CHECK		0x00000002
#define SLIM_URIRSLV_FLAG_SKIP_HOSTPORT_CHECK	0x00000004
#define SLIM_URIRSLV_FLAG_SKIP_TOLOWER			0x00000008
#define SLIM_URIRSLV_FLAG_USE_IDN				0x00000010
#define SLIM_URIRSLV_FLAG_ALLOW_NOSCHEME		0x00000020


#define URLSchemeInfo_SplitURL(cls, spec, len, ss)	(URLSchemeInfo_SplitURLX((cls),(spec),(len),(ss),slim_nil,slim_nil,slim_nil,slim_nil))

SLIM_END_C_LINKAGE

#endif
