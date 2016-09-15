#ifndef PEER_STRING_H
#define PEER_STRING_H

// multibyte to wide character (code page specific)
// returns the length of the converted string (or length required)
slim_int dlnaCS_CP_to_Wide(slim_word nCP, const slim_char *szSrc, wchar_t *szDst, slim_int nBufLen);
// wide character to multibyte (code page specific)
// returns the length of the converted string (or length required)
slim_int dlnaCS_Wide_to_CP(slim_word nCP, const wchar_t *szSrc, slim_char *szDst, slim_int nBufLen);
// convert a multi-byte string from one code page to another
slim_int dlnaCS_CP_to_CP(slim_word nCPsrc, slim_word nCPdest, const slim_char *szSrc, slim_char *szDst, slim_int nBufLen);
// convert from utf8 to any code page
slim_int dlnaCS_UTF8_to_CP(slim_word nCP, const slim_char *szSrc, slim_char *szDst, slim_int nBufLen);
// convert from utf8 to any code page
slim_int dlnaCS_CP_to_UTF8(slim_word nCP, const slim_char *szSrc, slim_char *szDst, slim_int nBufLen);
// utf8 to wide character
// returns the length of the converted string (or length required)
slim_int dlnaCS_UTF8_to_Wide(const slim_char *szSrc, wchar_t *szDst, slim_int nBufLen);
// wide character to utf8
// returns the length of the converted string (or length required)
slim_int dlnaCS_Wide_to_UTF8(const wchar_t *szSrc, slim_char *szDst, slim_int nBufLen);

#endif /* PEER_STRING_H */
