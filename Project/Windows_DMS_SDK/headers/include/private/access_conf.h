/*
* access_conf.h
* Copyright (C) 2008 ACCESS CO.,LTD.
* All rights are reserved by ACCESS CO.,LTD.,
* whether the whole or part of the source code
* including any modifications is concerned.
*
* This is an unpublished source code of ACCESS CO.,LTD., and must be
* treated as confidential material.  The above copyright notice does
* not evidence any actual or intended publication of this source code.
*/

#ifndef _ACCESS_CONF_H
#define _ACCESS_CONF_H

#include <dlna_peer.h>
#include <dms_api.h>
#include <nflc_cds_database.h>
#ifdef ENABLE_PARENTAL_GUIDANCE
#include "parental_guidance.h"
#endif
#include <dlna_app_config.h>

/*! \def DMS_INDEX_MODE_AUTO
 *  \hideinitializer
 *  \brief when index mode is auto then full indexing process is triggered automatically when new device is plugged to dms
 */
/*! \def DMS_INDEX_MODE_MANUAL
 *  \hideinitializer
 *  \brief when index mode is auto then user needs to explicitly trigger indexing using WebUI for newly plugged devices
 */
#define DMS_INDEX_MODE_AUTO     0
#define DMS_INDEX_MODE_MANUAL   1

#define DMS_CONTENTS_FILE_BIG_ENDIAN    0
#define DMS_CONTENTS_FILE_LITTLE_ENDIAN 1

#define USB_STORAGE_OUT_OF_MEMORY -3
#define USB_STORAGE_REBUILD_CANCEL -2
#define USB_STORAGE_REBUILD_ERR -1
#define USB_STORAGE_REBUILD_UNKNW  0
#define USB_STORAGE_REBUILDING 1 /* ZZZ 1~99 means progress and 0 means what ever */
#define USB_STORAGE_REBUILD_OK 100

#define DEFAULT_WEBUI_PORT (8080)
#define DEFAULT_PAL_DMS_UPNP_PORT_MIN (2869)
#define DEFAULT_MPE_SERVER_PORT (9978)

typedef struct net_if_config {
  struct net_if_config* next;
  struct net_if_config* prev;

  slim_char *net_dev_name;
  slim_int  *ifindex;
} net_if_config_t;


/**
 * \par Structure
 * services_ports is the structure that stores ports numbers of available services and features
 *
 * \code
typedef struct services_ports
{
  //Lowest possible DMS UPnP port number
  slim_int pal_dms_upnp_port_min;
  //WEBUI TCP port
  slim_int webui_port_number;
  //Media Processing Extension server communication TCP port
  slim_int mpe_server_port;
}services_ports_t;
 * \endcode
 *
 * \par Member:
 *
<table>
  <tr>
    <td>pal_dms_upnp_port_min</td>
    <td>Lowest possible DMS UPnP port number.</td>
  </tr>
  <tr>
    <td>webui_port_number</td>
    <td>WEB User Interface server TCP port number</td>
  </tr>
  <tr>
    <td>mpe_server_port</td>
    <td>Media Processing Extension server communication TCP port</td>
  </tr>
</table>
 */
typedef struct services_ports
{
  /*Lowest possible DMS UPnP port number*/
  slim_int pal_dms_upnp_port_min;
  /*WEBUI TCP port*/
  slim_int webui_port_number;
  /*Media Processing Extension server communication TCP port*/
  slim_int mpe_server_port;
}services_ports_t;


typedef slim_int (*fn_access_config_callback)(void*);

#ifdef ENABLE_PARENTAL_GUIDANCE
struct parental_control;
#endif

struct storage_config;

typedef struct access_config {
  slim_byte serverState;
  slim_half refreshFreq;

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
  slim_char *premiumContentDBLocation;
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

  struct dms* dms;
  List(struct storage_config *) storage;
  slim_int rebuild_all_state;
  slim_int rebuild_all_new_state;
  slim_int all_idx_file_ID;
  slim_char *defaultMusicThumbnailPath;
  slim_char *defaultVideoThumbnailPath;
  slim_char *defaultImageThumbnailPath;
  slim_char *defaultMusicMedThumbnailPath;
  slim_char *defaultVideoMedThumbnailPath;
  slim_char *defaultImageMedThumbnailPath;
  slim_char *titlePhoto;
  slim_char *titlePhototAll;
  slim_char *titlePhotoAlbum;
  slim_char *titlePhotoDate;
  slim_char *titlePhotoYear;
  slim_char *titlePhotoFolder;
#ifdef DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
  slim_char *titlePhotoSlideshow;
  slim_char *titlePhotoLastPlayed;
  slim_char *titlePhotoMostPlayed;
  slim_char *titlePhotoRecentlyAdded;
#endif /* DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS */
#ifdef ENABLE_GPS_SUPPORT
  slim_char *titlePhotoGeoTagged;
  slim_char *titlePhotoGeoArea;
#endif /*ENABLE_GPS_SUPPORT*/
  slim_char *titleMusic;
  slim_char *titleMusicAll;
  slim_char *titleMusicGenre;
  slim_char *titleMusicAlbum;
  slim_char *titleMusicArtist;
  slim_char *titleMusicFolder;
  slim_char *titleMusicRating;
  slim_char *titleMusicDate;
  slim_char *titleMusicYear;
  slim_char *titleMusicArtistAlbum;
  slim_char *titleMusicArtistIndex;
  slim_char *titleMusicGenreAlbum;
  slim_char *titleMusicGenreArtist;
  slim_char *titleMusicPlaylist;
#ifdef DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
  slim_char *titleMusicLastPlayed;
  slim_char *titleMusicMostPlayed;
  slim_char *titleMusicRecentlyAdded;
#endif /* DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS */
  slim_char *titleVideo;
  slim_char *titleVideoAll;
  slim_char *titleVideoGenre;
  slim_char *titleVideoAlbum;
  slim_char *titleVideoActor;
  slim_char *titleVideoRating;
  slim_char *titleVideoYear;
  slim_char *titleVideoDate;
  slim_char *titleVideoFolder;
#ifdef DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS
  slim_char *titleVideoPlaylist;
  slim_char *titleVideoLastPlayed;
  slim_char *titleVideoMostPlayed;
  slim_char *titleVideoRecentlyAdded;
#endif /* DEVELOPMENT_ENABLE_VIRTUAL_PLAYLISTS */
  slim_char *selected_language;
  slim_char **available_languages;
  slim_int languages_count;
#ifdef ENABLE_MOVIEDB_MOVIECOVER
	slim_char *titleVideoCoverArt;
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/
	slim_char *titleStorage;
  slim_char *titleUnknown;
  slim_char *titleOther;
  slim_char *titleDocument;
  slim_char *titleDocumentAll;

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
  slim_char *titlePremium;
  slim_char *titlePremiumOnlineContent;
  slim_char *titlePremiumLiveContent;
  slim_char *titlePremiumRecordedContent;
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

  fn_access_config_callback callback;
#ifdef ENABLE_ACCESS_CFG_UDN
  slim_char *udn;
#endif /* ENABLE_ACCESS_CFG_UDN */
  slim_char *presentationURL;
  List(net_if_config_t*) net_if_config_list;
  slim_char *lan_device;
  slim_word ssdp_notify_interval;
  slim_word ssdp_cachecontrol_maxage;
  slim_word ssdp_notify_msg_delay;
  slim_word ssdp_notify_msg_copy_count;
  /*Some services and features port numbers*/
  services_ports_t s_ports;

  slim_word storage_memcheck_memory_limit;
  slim_word storage_memcheck_repeat_counter;


  slim_int mpeServerResponseTimeout;

  slim_word localDBJournalWAL;
  slim_bool emptyContainerDisabled;
#ifdef DEVELOPMENT_DATABASE_CHECKPOINT_TRIGGER_VIA_ACCESS_CONF
  slim_word databaseCheckpoint;
#endif /* DEVELOPMENT_DATABASE_CHECKPOINT_TRIGGER_VIA_ACCESS_CONF */
#ifdef DEVELOPMENT_DISABLE_THUMBNAILS_FOR_PARTIAL_INDEXING
  slim_word partial_indexing_thumbnail;
  slim_word thumbnails_rebuild_interval;
#endif /*DEVELOPMENT_DISABLE_THUMBNAILS_FOR_PARTIAL_INDEXING*/
  slim_int  ipc_content_list_max_value;
  slim_int  ipc_content_list_max_changed;
  slim_int  ipc_content_per_page_value;
  slim_bool ipc_content_per_page_changed;

	slim_word minimum_thumbnail_time;
	slim_word minimum_thumbnail_percentage;

#ifdef ENABLE_PARENTAL_GUIDANCE
  struct parental_control *pc;
#endif
	slim_char *storageMessageFifo;

#ifdef DEVELOPEMENT_EXTRACTION_EMBEDDED_ALBUM_ARTS
	slim_bool extract_embedded_album_arts_to_storage;
#endif /*DEVELOPEMENT_EXTRACTION_EMBEDDED_ALBUM_ARTS*/
	slim_int streaming_sessions_limit;
#ifdef DEVELOPMENT_CONTENT_AGGREGATION
  slim_bool content_aggregation_flag;
  slim_char *content_aggregation_path;
  slim_int content_aggregation_path_selection_mode;
  slim_int content_aggregation_db_size;
  slim_bool content_aggregation_purge_enable;
  slim_int content_aggregation_purge_time;
  slim_int content_aggregation_rescan_time;
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */


#define ACCESS_CONF_MEDIA_JPEG_RESCALE_LINE_BY_LINE 0
#define ACCESS_CONF_MEDIA_JPEG_RESCALE_WHOLE_IMAGE 1
  slim_word media_jpeg_rescale_method;
  slim_word media_jpeg_rescale_memory_limit;
  slim_int downloadSupport;
  slim_int uploadDeviceOption;
  slim_int uploadFolderSelectionMode;
  slim_int jpegScaleLRG;
  slim_int jpegScaleMED;
  slim_int jpegScaleSM;
  slim_int jpegScaleTN;
  slim_word maxStorageCount;

} access_config_t;

enum {
    DMSCONFIG_CHANGE_FRIENDLYNAME	 = 0x01,
    DMSCONFIG_CHANGE_UDN             = 0x02,
    DMSCONFIG_CHANGE_IF_INTERFACE    = 0x04,
    DMSCONFIG_CHANGE_CONTENSFILENAME = 0x10,
    DMSCONFIG_CHANGE_CATEGORYNAMES   = 0x20,
    DMSCONFIG_CHANGE_TIMER           = 0x40,
    DMSCONFIG_CHANGE_OTHER           = 0x80,

    DMSCONFIG_CHANGE_VALUE_MAX      // use DMSCONFIG_CHANGE_VALUE_MAX-1
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void access_conf_update_presentation_url(slim_int session_socket, void* doc);
access_config_t* access_conf_alloc(slim_char* access_conf_dir, slim_char* access_cfg_file);
void access_conf_free(access_config_t* access_cfg);

slim_int
access_conf_update_element (const slim_char *access_conf_dir,
    const slim_char *element_name, const slim_char *new_value);

slim_int
access_conf_write_language (const slim_char *access_conf_dir, const slim_char *new_value );

slim_int
access_conf_write_sessions_limit (const slim_char *access_conf_dir, const slim_char *new_value );

slim_int
access_conf_write_upload_path_selection_mode (const slim_char *access_conf_dir, const slim_char *new_value);

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
slim_int
access_conf_write_ca_flag (const slim_char *access_conf_dir, const slim_char *new_value);

slim_int
access_conf_write_ca_path (const slim_char *access_conf_dir, const slim_char *new_value);

slim_int
access_conf_write_ca_db_limit (const slim_char *access_conf_dir, const slim_char *new_value);

slim_int
access_conf_write_ca_purge_time (const slim_char *access_conf_dir, const slim_char *new_value);

slim_int
access_conf_write_ca_rescan_interval (const slim_char *access_conf_dir, const slim_char *new_value);
#endif /* DEVELOPMENT_CONTENT_AGGREGATION */

slim_int
access_conf_write_server_state (const slim_char *access_conf_dir, slim_int new_value);

slim_int access_conf_refresh_config(access_config_t *old_config, access_config_t *new_config);
slim_int access_conf_update(access_config_t* access_cfg, slim_char* access_conf_dir, slim_char* access_cfg_file);

/*DMS: Default values for entries in access_conf.xml - if reading access_conf.xml
 *fails, the DMS tries to fill the structs with this values. If this fails also:
 *Good luck. */

#define DEFAULT_SLASH_STR						 "/"
#define DEFAULT_DMSCONFIG_ID_DELIM               "$"
#define DEFAULT_DMSCONFIG_ID_DELIM_CHAR          '$'

#define DEFAULT_DMSCONFIG_ID_PHOTO               "Photo"
#define DEFAULT_DMSCONFIG_ID_MUSIC               "Music"
#define DEFAULT_DMSCONFIG_ID_VIDEO               "Video"
#define DEFAULT_DMSCONFIG_ID_DOCUMENT            "Documents"
#define DEFAULT_DMSCONFIG_ID_PLAYLIST            "Playlists"
#define DEFAULT_DMSCONFIG_ID_ALLPHOTO            "All Photos"
#define DEFAULT_DMSCONFIG_ID_ALLMUSIC            "All Music"
#define DEFAULT_DMSCONFIG_ID_ALLVIDEO            "All Videos"
#define DEFAULT_DMSCONFIG_ID_ALLDOCUMENT         "All Document"
#define DEFAULT_DMSCONFIG_ID_GENRE               "Genre"
#define DEFAULT_DMSCONFIG_ID_ALBUM               "Album"
#define DEFAULT_DMSCONFIG_ID_ARTIST              "Artist"
#define DEFAULT_DMSCONFIG_ID_ACTOR               "Actor"
#define DEFAULT_DMSCONFIG_ID_DATE                "By Date"
#define DEFAULT_DMSCONFIG_ID_YEAR                "By Year"
#define DEFAULT_DMSCONFIG_ID_FOLDER              "Folder"
#define DEFAULT_DMSCONFIG_ID_RATING              "Rating"
#define DEFAULT_DMSCONFIG_ID_ARTIST_INDEX        "Artist Index"
#define DEFAULT_DMSCONFIG_ID_ARTIST_ALBUM        "Artist/Album"
#define DEFAULT_DMSCONFIG_ID_GENRE_ALBUM         "Genre/Album"
#define DEFAULT_DMSCONFIG_ID_GENRE_ARTIST        "Genre/Artist"
#define DEFAULT_DMSCONFIG_ID_GENRE_SONG          "Genre/Song"
#define DEFAULT_DMSCONFIG_ID_SLIDESHOW           "Slideshow"
#define DEFAULT_DMSCONFIG_ID_LAST_PLAYED         "LastPlayed"
#define DEFAULT_DMSCONFIG_ID_MOST_PLAYED         "MostPlayed"
#define DEFAULT_DMSCONFIG_ID_RECENTLY_ADDED      "RecentlyAdded"
#define DEFAULT_DMSCONFIG_ID_STORAGE             "Storage"
#define DEFAULT_DMSCONFIG_ID_UNKNOWN             "Unknown"
#define DEFAULT_DMSCONFIG_ID_OTHER               "Other"

#define DEFAULT_DMSCONFIG_ID_GEOTAGGED           "Geo Tagged"
#define DEFAULT_DMSCONFIG_ID_GEOAREA             "Geo Area"

#define DEFAULT_DMSCONFIG_ID_PVRCONTENT         "PVR Content"

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
#define DEFAULT_DMSCONFIG_ID_PREMIUM             "PremiumContentID"
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

#define DEFAULT_DMSCONFIG_ID_PHOTO_ALL           DEFAULT_DMSCONFIG_ID_ALLPHOTO""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_ALBUM         DEFAULT_DMSCONFIG_ID_ALBUM""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_GEOTAGGED     DEFAULT_DMSCONFIG_ID_GEOTAGGED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_GEOAREA       DEFAULT_DMSCONFIG_ID_GEOAREA""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_MUSIC_ALL           DEFAULT_DMSCONFIG_ID_ALLMUSIC""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_GENRE         DEFAULT_DMSCONFIG_ID_GENRE""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_ALBUM         DEFAULT_DMSCONFIG_ID_ALBUM""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_ARTIST        DEFAULT_DMSCONFIG_ID_ARTIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_PLAYLIST      DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_VIDEO_ALL           DEFAULT_DMSCONFIG_ID_ALLVIDEO""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_GENRE         DEFAULT_DMSCONFIG_ID_GENRE""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_ALBUM         DEFAULT_DMSCONFIG_ID_ALBUM""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_ACTOR         DEFAULT_DMSCONFIG_ID_ACTOR""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO

#ifdef ENABLE_MOVIEDB_MOVIECOVER
#define DEFAULT_DMSCONFIG_ID_VIDEO_COVERART	"Movies-CoverArt"DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/


#define DEFAULT_DMSCONFIG_ID_CONTAINER_INTERNET "Container"DEFAULT_DMSCONFIG_ID_DELIM"Internet"
#define DEFAULT_DMSCONFIG_ID_CONTAINER_IMPORT   "Container"DEFAULT_DMSCONFIG_ID_DELIM"Import"

#define DEFAULT_DMSCONFIG_ID_PHOTO_DATE           DEFAULT_DMSCONFIG_ID_DATE""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_YEAR           DEFAULT_DMSCONFIG_ID_YEAR""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_FOLDER         DEFAULT_DMSCONFIG_ID_FOLDER""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_SLIDESHOW      DEFAULT_DMSCONFIG_ID_SLIDESHOW""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_LAST_PLAYED    DEFAULT_DMSCONFIG_ID_LAST_PLAYED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_SLIDESHOW""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_MOST_PLAYED    DEFAULT_DMSCONFIG_ID_MOST_PLAYED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_SLIDESHOW""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO
#define DEFAULT_DMSCONFIG_ID_PHOTO_RECENTLY_ADDED DEFAULT_DMSCONFIG_ID_RECENTLY_ADDED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_SLIDESHOW""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PHOTO

#define DEFAULT_DMSCONFIG_ID_MUSIC_RATING        DEFAULT_DMSCONFIG_ID_RATING""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_ARTIST_ALBUM  DEFAULT_DMSCONFIG_ID_ARTIST_ALBUM""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_FOLDER        DEFAULT_DMSCONFIG_ID_FOLDER""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_ARTIST_INDEX  DEFAULT_DMSCONFIG_ID_ARTIST_INDEX""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_GENRE_ALBUM   DEFAULT_DMSCONFIG_ID_GENRE_ALBUM""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_GENRE_ARTIST  DEFAULT_DMSCONFIG_ID_GENRE_ARTIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_LAST_PLAYED   DEFAULT_DMSCONFIG_ID_LAST_PLAYED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_MOST_PLAYED   DEFAULT_DMSCONFIG_ID_MOST_PLAYED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC
#define DEFAULT_DMSCONFIG_ID_MUSIC_RECENTLY_ADDED   DEFAULT_DMSCONFIG_ID_RECENTLY_ADDED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_MUSIC

#define DEFAULT_DMSCONFIG_ID_VIDEO_RATING         DEFAULT_DMSCONFIG_ID_RATING""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_DATE           DEFAULT_DMSCONFIG_ID_DATE""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_YEAR           DEFAULT_DMSCONFIG_ID_YEAR""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_FOLDER         DEFAULT_DMSCONFIG_ID_FOLDER""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_PLAYLIST       DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_LAST_PLAYED    DEFAULT_DMSCONFIG_ID_LAST_PLAYED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_MOST_PLAYED    DEFAULT_DMSCONFIG_ID_MOST_PLAYED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO
#define DEFAULT_DMSCONFIG_ID_VIDEO_RECENTLY_ADDED DEFAULT_DMSCONFIG_ID_RECENTLY_ADDED""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_PLAYLIST""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_VIDEO

#define DEFAULT_DMSCONFIG_ID_DOCUMENT_FOLDER      DEFAULT_DMSCONFIG_ID_FOLDER""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_DOCUMENT
#define DEFAULT_DMSCONFIG_ID_DOCUMENT_ALL         DEFAULT_DMSCONFIG_ID_ALLDOCUMENT""DEFAULT_DMSCONFIG_ID_DELIM""DEFAULT_DMSCONFIG_ID_DOCUMENT

/*________________________________*/
/* Default runtime configuration settings */
/*________________________________*/

#define DEFAULT_DMSCONFIG_REFRESH_FREQ			"120"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO			"Photo"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_T_ALL		"All Photos"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_ALBUM		"Album"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_DATE              "By Date"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_YEAR              "By Year"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_FOLDER            "Folder"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_SLIDESHOW         "Slideshow"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_LAST_PLAYED       "Last Viewed"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_MOST_PLAYED       "Most Viewed"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_RECENTLY_ADDED    "Recently Added"

#define DEFAULT_DMSCONFIG_TITLE_PHOTO_GEOTAGGED		"Geo Tagged"
#define DEFAULT_DMSCONFIG_TITLE_PHOTO_GEOAREA		"Geo Area"

#ifdef ENABLE_MOVIEDB_MOVIECOVER
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_COVERART		"Movies-CoverArt"
#endif /*ENABLE_MOVIEDB_MOVIECOVER*/

#define DEFAULT_DMSCONFIG_TITLE_MUSIC                   "Music"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_ALL               "All Music"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_GENRE             "Genre"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_GENRE_ALBUM       "Genre/Album"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_GENRE_ARTIST      "Genre/Artist"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_ALBUM             "Album"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_ARTIST            "Artist"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_ARTIST_INDEX      "Artist Index"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_ARTIST_ALBUM      "Artist/Album"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_RATING            "Rating"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_DATE              "By Date"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_YEAR              "By Year"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_FOLDER            "Folder"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_PLAYLIST	         "Playlist"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_LAST_PLAYED       "Last Played"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_MOST_PLAYED       "Most Played"
#define DEFAULT_DMSCONFIG_TITLE_MUSIC_RECENTLY_ADDED    "Recently Added"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO                   "Video"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_ALL               "All Video"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_GENRE             "Genre"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_ALBUM             "Album"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_ACTOR             "Actor"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_RATING            "Rating"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_DATE              "By Date"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_YEAR              "By Year"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_FOLDER            "Folder"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_PLAYLIST          "Playlist"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_LAST_PLAYED       "Last Played"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_MOST_PLAYED       "Most Played"
#define DEFAULT_DMSCONFIG_TITLE_VIDEO_RECENTLY_ADDED    "Recently Added"
#define DEFAULT_DMSCONFIG_TITLE_STORAGE                 "Storage"
#define DEFAULT_DMSCONFIG_TITLE_UNKNOWN                 "Unknown"
#define DEFAULT_DMSCONFIG_TITLE_OTHER                   "Other"
#define DEFAULT_DMSCONFIG_TITLE_DOCUMENT                "Documents"
#define DEFAULT_DMSCONFIG_TITLE_DOCUMENT_ALL            "All Documents"
//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
#define DEFAULT_DMSCONFIG_TITLE_PREMIUM                 "Premium"
#define DEFAULT_DMSCONFIG_TITLE_LIVE_CONTENT            "LiveContent"
#define DEFAULT_DMSCONFIG_TITLE_ONLINE_CONTENT          "OnlineContent"
#define DEFAULT_DMSCONFIG_TITLE_RECORDED_CONTENT        "RecordedContent"
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

#define DEFAULT_DMSCONFIG_UUID				"bc329e00-1dd8-11b2-9a85-148f4a294852"
#define DEFAULT_DMSCONFIG_INDEX_MODE_MANUAL		"1"
#define DEFAULT_DMSCONFIG_SHARE_MODE    		"1"
#define DEFAULT_DMSCONFIG_SHARE_OPTION			"1"

#define DEFAULT_DMSCONFIG_DOWNLOAD_SUPPORT                      "1"
#define DEFAULT_DMSCONFIG_UPLOAD_OPTION                         "1"
#define DEFAULT_DMSCONFIG_UPLOAD_FOLDER_DEFAULT_SELECTION_MODE  "0"

#define DEFAULT_DMSCONFIG_JPEG_SCALE_LRG     "0"
#define DEFAULT_DMSCONFIG_JPEG_SCALE_MED     "1"
#define DEFAULT_DMSCONFIG_JPEG_SCALE_SM      "0"
#define DEFAULT_DMSCONFIG_JPEG_SCALE_TN      "1"
#define DEFAULT_DMSCONFIG_SHARE_PRI			"1"
#define DEFAULT_DMSCONFIG_XMMRR_SUPPORT                 "1"
#define DEFAULT_DMSCONFIG_ENABLED			"1"
#define DEFAULT_DMSCONFIG_SSDP_NOTIFY_INTERVAL          "870"   /*seconds*/
#define DEFAULT_DMSCONFIG_SSDP_NOTIFY_MSG_DELAY         "200"    /*milliseconds*/
#define DEFAULT_DMSCONFIG_SSDP_NOTIFY_MAXAGE            "1800"  /*seconds*/
#define DEFAULT_DMSCONFIG_SSDP_NOTIFY_MSG_COPY_COUNT    "1"
#define DEFAULT_DMSCONFIG_MEMCHECK_MEMORY_LIMIT         "512" /*MegaBytes*/
#define DEFAULT_DMSCONFIG_MEMCHECK_REPEAT_COUNT         "100"
#define DEFAULT_DMSCONFIG_MPE_SERVER_RESPONSE_TIMEOUT	"60" /*In Seconds*/
#define DEFAULT_DMSCONFIG_DATABASE_CHECKPOINT_TRIGGER   "100" /* Number of indexed items */
#define DEFAULT_LOCAL_DB_JOURNAL_WAL                    "1"
#define DEFAULT_MAX_STORAGE_COUNT                       "50"
#define DEFAULT_EMPTY_CONTAINER_DISABLED                 0 /*BOOL*/
#define DEFAULT_MINIMUM_THUMBNAIL_TIME			 15 /*In Seconds*/
#define DEFAULT_MINIMUM_THUMBNAIL_PERCENTAGE		 25  /*In PERCENTAGE*/
#define DEFAULT_PARTIAL_INDEXING_THUMBNAIL              1
#define DEFAULT_THUMBNAIL_REINDEXING_INTERVAL             120 /* in seconds*/

//#ifdef DEVELOPMENT_ENABLE_PUBLISH_CONTENT
#ifdef DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API
#define ELEMENT_NAME_PREMIUM_CONTENT_DB      "onlineContentDB"
#endif /* DEVELOPMENT_PUBLISH_ONLINE_RECORDED_CONTENT_API */

#define ELEMENT_NAME_DOWNLOAD_SUPPORT             "downloadSupport"
#define ELEMENT_NAME_UPLOAD_OPTION                "uploadDeviceOption"
#define ELEMENT_NAME_UPLOAD_FOLDER_SELECTION_MODE "uploadFolderSelectionMode"

#define ELEMENT_NAME_JPEG_SCALE_LRG         "jpegScaleLRG"
#define ELEMENT_NAME_JPEG_SCALE_MED         "jpegScaleMED"
#define ELEMENT_NAME_JPEG_SCALE_SM          "jpegScaleSM"
#define ELEMENT_NAME_JPEG_SCALE_TN          "jpegScaleTN"
#define ELEMENT_NAME_MAX_STORAGE_COUNT      "maxStorageCount"
#define ELEMENT_NAME_XMMRR                              "xmmrr"
#define ELEMENT_NAME_SSDP_NOTIFY_INTERVAL               "ssdpNotifyInterval"
#define ELEMENT_NAME_SSDP_MAX_AGE                       "ssdpNotifyMaxAge"
#define ELEMENT_NAME_SSDP_NOTIFY_MSG_DELAY              "ssdpNotifyMsgDelay"
#define ELEMENT_NAME_SSDP_NOTIFY_MSG_COPY_COUNT         "ssdpNotifyMsgCopyCount"
#define ELEMENT_NAME_MEMCHECK_MEMORY_LIMIT              "memCheckMemoryLimit"
#define ELEMENT_NAME_MEMCHECK_REPEAT_COUNT              "memCheckRepeatCount"

#define ELEMENT_STORAGE_MESSAGE_FIFO  "storageMessageFifo"

#define ELEMENT_STREAM_SESSIONS_LIMIT			"maxStreamSessions"

#ifdef DEVELOPMENT_CONTENT_AGGREGATION
#define ELEMENT_NAME_CA_ENABLED               "contentAggregationEnable"
#define ELEMENT_NAME_CA_PATH                  "contentAggregationPath"
#define ELEMENT_NAME_CA_PATH_SELECTION_MODE   "contentAggregationPathSelectionMode"
#define ELEMENT_NAME_CA_DATABASE_LIMIT        "contentAggregationDatabaseLimit"
#define ELEMENT_NAME_CA_PURGE_ENABLE          "contentAggregationPurgeEnable"
#define ELEMENT_NAME_CA_PURGE                 "contentAggregationPurgeTime"
#define ELEMENT_NAME_CA_RESCAN                "contentAggregationRescanTime"

/*! \def CA_PATH_SELECTION_MODE_AUTO
 *  \hideinitializer
 *  \brief when CA path selection mode is auto then if path is not set,
 * the first storage is selected for CA path.
 * Process is triggered automatically when new device is plugged to dms
 */
/*! \def CA_PATH_SELECTION_MODE_MANUAL
 *  \hideinitializer
 *  \brief when CA path selection mode is manual then if no path is specified,
 * user needs to explicitly set new path for newly plugged devices
 */
#define CA_PATH_SELECTION_MODE_AUTO         0
#define CA_PATH_SELECTION_MODE_MANUAL       1

#define DEFAULT_DMSCONFIG_CONTENT_AGGREGATION     1
#define DEFAULT_DMSCONFIG_CA_PATH_SELECTION_MODE  CA_PATH_SELECTION_MODE_AUTO
#define DEFAULT_DMSCONFIG_CA_TIMEOUT        1800
#define DEFAULT_DMSCONFIG_CA_PURGE_ENABLE   0
#define DEFAULT_DMSCONFIG_CA_PURGE_TIME     1
#define DEFAULT_DMSCONFIG_CA_RESCAN_TIME    600
#endif

#define ELEMENT_NAME_DEFAULT_PICTURE_THUMBNAIL_PATH "defaultPictureThumbnailPath"
#define ELEMENT_NAME_DEFAULT_MUSIC_THUMBNAIL_PATH   "defaultMusicThumbnailPath"
#define ELEMENT_NAME_DEFAULT_VIDEO_THUMBNAIL_PATH   "defaultVideoThumbnailPath"
#define ELEMENT_NAME_DEFAULT_PICTURE_MED_THUMBNAIL_PATH "defaultPictureMedThumbnailPath"
#define ELEMENT_NAME_DEFAULT_MUSIC_MED_THUMBNAIL_PATH   "defaultMusicMedThumbnailPath"
#define ELEMENT_NAME_DEFAULT_VIDEO_MED_THUMBNAIL_PATH   "defaultVideoMedThumbnailPath"

#define DEFAULT_TIMEOUT_INTERVAL_NAME "thumbnailRebuildInterval"

/*DEF_VAR_NET_INTERFACE can switch to different states at the same time, according
 * to network devices and is therefore implemented as array*/
#define DEF_VAR_NET_INTERFACE char *default_usbgeneralconfig_netinterfaces[] = 	{"br0", slim_nil}
/*DEVICE_LAN can have different states, but the code supports just one state at the
 * same time*/
#define ELEMENT_NAME_MAXCONTENTPERPAGE			"maxContentPerPage"
#define ELEMENT_NAME_MAXCONTENTLIST			"maxContentList"
#define DEFAULT_USBGENERALCONFIG_DEVICE_LAN		"br0"
#define DEFAULT_WEB_PRESENTATION_URL  			""
#define DEFAULT_WEB_CONTENT_LIST_MAX_RANGE		1000
#define DEFAULT_WEB_CONTENT_LIST_MAX_VALUE		"50"
#define DEFAULT_WEB_CONTENT_PER_PAGE			"5"
#define DEFAULT_WEB_WEB_SERVER_PORT			"8080"

#define ELEMENT_NAME_LANGUAGE "language"
#define ELEMENT_NAME_CONTAINERS "containers"
#define CONTAINERS_DEFAULT_LANGUAGE "english"

#ifdef DEVELOPEMENT_EXTRACTION_EMBEDDED_ALBUM_ARTS
#define ELEMENT_NAME_EMBEDDED_ALBUM_ARTS_STORAGE "storeEmbeddedAlbumArtsOnDisc"
#endif /*DEVELOPEMENT_EXTRACTION_EMBEDDED_ALBUM_ARTS*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif/*_ACCESS_CONF_H*/
