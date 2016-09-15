#ifndef NFLC_INFO_APIC_H
#define NFLC_INFO_APIC_H

#include <info_media.h>

#define EMBEDDED_ALBUM_ART_URI_PREFIX_ID3 "/embeddedID3"DEFAULT_DMSCONFIG_ID_DELIM

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

slim_char*
getEmbeddedAlbumArtUrifromID3(slim_char* full_path, albumArtImage **embedded_image);

albumArtImage*
getEmbeddedAlbumArtUriImagefromID3(slim_char* full_path);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_INFO_ID3_H */
