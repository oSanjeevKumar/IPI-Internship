/*
 * upnp_cds.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */






/*
 * Design notes
 *
 * Response customizations based on user agent header.
 *
 *
 * How does it work?
 *
 * Core of solution is a structure _upnp_cds_user_agent_customizations. When
 * HTTP request is submitted an HTTP session object is created. HTTP session
 * is associated with instance of _upnp_cds_user_agent_customizations based
 * on header USER-AGENT.
 *
 *
 * Instance of _upnp_cds_user_agent_customizations contains objects that are
 * responsible for conducting response customizations. These object are
 * instances of customization classes.
 *
 *
 * All customization classes inherit interface _upnp_cds_user_agent_customization_base.
 * This is very simple interface that introduce only virtual destructor to the class.
 *
 * class customization_base
 * {
 * public:
 *   virtual ~customization_base() = 0;
 * };
 *
 *
 * Based on _upnp_cds_user_agent_customization_base interface of specific customizations
 * are defined. First type of customization is
 * _upnp_cds_user_agent_customization_mime_type_conversion. It introduces a method
 * to obtain "converted" mime type for given content type.
 *
 * class mime_type_conversion : public customization_base
 * {
 * public:
 *   virtual ~mime_type_conversion() = 0;
 *   virtual slim_char get_mime_type(slim_int content_type) = 0;
 * };
 *
 *
 * When the system reach a point where customization may be required it takes an instance
 * of _upnp_cds_user_agent_customizations associated with current HTTP session. From the
 * instance it takes proper object and ask it to conduct custom actions.
 *
 *
 *
 * New class ?
 *
 * To add new implementation of _upnp_cds_user_agent_customization_mime_type_conversion
 * one have to:
 * 1) add new entry to enum _upnp_cds_user_agent_mime_type_customization_type that will
 *    represent this new mime type customization class.
 * 2) create a structure which first field is of type
 *    _upnp_cds_user_agent_customization_mime_type_conversion. It would be best to call
 *     it base
 * 3) Implement functions:
 *      - _upnp_cds_user_agent_customization_free,
 *      - _upnp_cds_user_agent_mime_type_customize,
 *      - anything else needed for new class.
 * 4) Modify function upnp_cds_user_agent_customization_init so it can handle new class.
 *    One should prepare init function and add it to proper switch.
 *    <<<   upnp_cds_user_agent_customization_init will become a mess pretty fast.
 *    <<<   I am thinking about splitting it to several steps. One per customization type.
 * 5) Modify parse_user_agent_xml (file upnp_cds.c) to handle new class.
 * 6) Modify xml file to use new class.
 *
 * struct mime_type_default
 * {
 *   struct _upnp_cds_user_agent_mime_type_customization_type base;
 *
 *   // implementation specific, data etc
 * };
 *
 *
 *
 * New interface ?
 *
 * To add a new type of customization one have to:
 * 1) In this header file (upnp_cds_user_agent_customization.h) add a new structure
 *    that will be an interface for the rest of the system. Its first field should
 *    be of type _upnp_cds_user_agent_customization_base and called base.
 * 2) In this header file add a new enum similar to
 *    _upnp_cds_user_agent_mime_type_customization_type.
 * 3) Add new class to structure _upnp_cds_user_agent_customizations.
 * 4) Modify upnp_cds_user_agent_customization_free to free object of new class
 *    stored in instance of _upnp_cds_user_agent_customizations.
 * 5) Make usage of new interface in the system.
 * 6) Implement new class, at least default behavior should be prepared.
 *
 * struct new_fancy_customization_interface
 * {
 *   struct _upnp_cds_user_agent_customization_base base;
 *
 *   // methods only
 *   // ADSM: I forbid to store any data in interface :)
 * };
 */













#ifndef UPNP_CDS_USER_AGENT_CUSTOMIZATION_H_
#define UPNP_CDS_USER_AGENT_CUSTOMIZATION_H_


/* ****** Base customization interface ****** */
struct _upnp_cds_user_agent_customization_base;

/*
 * Destructor
 */
typedef void
(* _upnp_cds_user_agent_customization_free) (
    struct _upnp_cds_user_agent_customization_base * obj);

/*
 * Interface
 */
struct _upnp_cds_user_agent_customization_base
{
  _upnp_cds_user_agent_customization_free free;
};



/* ****** Mime-type interface ****** */
struct _upnp_cds_user_agent_customization_mime_type_conversion;

/*
 * Get customized mime_type
 */
typedef slim_char *
(* _upnp_cds_user_agent_mime_type_customize) (
    struct _upnp_cds_user_agent_customization_mime_type_conversion * obj,
    slim_word contnet_type);

/*
 * Interface
 */
struct _upnp_cds_user_agent_customization_mime_type_conversion
{
  // Inherited base customization
  struct _upnp_cds_user_agent_customization_base base;


  _upnp_cds_user_agent_mime_type_customize  get;
};



/* ****** Generated playlist interface ****** */
struct _upnp_cds_user_agent_customization_playlist;

/*
 * Should playlist be generated
 */
typedef slim_word
(* _upnp_cds_user_agent_playlist_is_enabled) (
    struct _upnp_cds_user_agent_customization_playlist * obj);

/*
 * Interface
 */
struct _upnp_cds_user_agent_customization_playlist
{
  // Inherited base customization
  struct _upnp_cds_user_agent_customization_base base;


  _upnp_cds_user_agent_playlist_is_enabled is_container_enabled;
  _upnp_cds_user_agent_playlist_is_enabled is_generated_enabled;
  _upnp_cds_user_agent_playlist_is_enabled is_virtual_enabled;
};



/* ****** Reference interface ****** */
struct _upnp_cds_user_agent_customization_reference;

/*
 * Should reference be generated
 */
typedef slim_word
(* _upnp_cds_user_agent_reference_is_enabled) (
    struct _upnp_cds_user_agent_customization_reference * obj);

/*
 * Interface
 */
struct _upnp_cds_user_agent_customization_reference
{
  // Inherited base customization
  struct _upnp_cds_user_agent_customization_base base;


  _upnp_cds_user_agent_reference_is_enabled is_video_thumbnail_enabled;
};



/* ****** XML interface ****** */
struct _upnp_cds_user_agent_customization_xml;
struct contents;
struct _sXML;
struct upnp_cds_search_param;

/*
 * Is container searchable
 */
typedef slim_word
(* _upnp_cds_user_agent_xml_is_container_seachable) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    struct contents * content);

/*
 * Is max output length reached
 */
typedef slim_word
(* _upnp_cds_user_agent_xml_is_output_length_reached) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    slim_word output_length);

/*
 * Is requested count limited
 */
typedef slim_word
(* _upnp_cds_user_agent_xml_is_requested_count_limited) (
    struct _upnp_cds_user_agent_customization_xml * obj);

/*
 * Is album art required
 */
typedef slim_word
(* _upnp_cds_user_agent_xml_is_album_art_required) (
    struct _upnp_cds_user_agent_customization_xml * obj);

/*
 * Export object id
 */

enum _upnp_cds_user_agent_xml_request_type
{
  UPNP_CDS_USER_AGENT_XML_REQUEST_TYPE_BROWSE,
  UPNP_CDS_USER_AGENT_XML_REQUEST_TYPE_SEARCH,
};

typedef slim_char *
(* _upnp_cds_user_agent_xml_export_object_id) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    enum _upnp_cds_user_agent_xml_request_type request_type,
    struct _sXML * xml_doc);

typedef void
(* _upnp_cds_user_agent_escape_content_id) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    slim_char **in_object_id, struct sbuf *sbuf);

/*
 * Get upnp:class
 */
typedef slim_char *
(* _upnp_cds_user_agent_xml_get_upnp_class) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    struct contents * content,
    slim_char * buffer,
    slim_word buffer_size);

/*
 * Get search type
 */
typedef slim_word
(* _upnp_cds_user_agent_xml_get_search_type) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    struct contents * content,
    struct upnp_cds_search_param * p);

/*
 * Get search type
 */
typedef struct search_exp *
(* _upnp_cds_user_agent_xml_get_search_criteria) (
    struct _upnp_cds_user_agent_customization_xml * obj,
    struct upnp_cds_search_param * p,
    slim_char ** out_buffer);

/*
 * Add special namespace
 */
typedef slim_char *
(* _upnp_cds_user_agent_xml_add_namespace)();

/*
 * Change response for wav files.
 */
typedef void
   (* _upnp_cds_change_contents_xml_audio_res)  (
       struct _upnp_cds_user_agent_customization_xml * obj,
       struct contents_manager *cm,
       struct sbuf *sbuf,
       struct contents *contents,
       slim_int ifindex,
       struct _extended_flags * ext_flags,
       struct media_protocol_information_structure* pinfo);
       
#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING
/*
 * Change protocolInfo database request.
 */
typedef slim_int
   (* _upnp_cds_user_agent_database_get_protocol_list_by_content_id)  (
       cds_database_info * database,
       slim_int content_id,
       contents_t* c);
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */

/*
 * Interface
 */
struct _upnp_cds_user_agent_customization_xml
{
  // Inherited base customization
  struct _upnp_cds_user_agent_customization_base base;


  _upnp_cds_user_agent_xml_is_container_seachable  is_container_seachable;
  _upnp_cds_user_agent_xml_is_output_length_reached is_output_length_reached;
  _upnp_cds_user_agent_xml_is_requested_count_limited is_requested_count_limited;
  _upnp_cds_user_agent_xml_is_album_art_required is_album_art_required;

  _upnp_cds_user_agent_xml_export_object_id export_object_id;
  _upnp_cds_user_agent_escape_content_id escape_content_id;

  _upnp_cds_user_agent_xml_get_upnp_class get_upnp_class;
  _upnp_cds_user_agent_xml_get_search_type get_search_type;
  _upnp_cds_user_agent_xml_get_search_criteria get_search_criteria;

  _upnp_cds_user_agent_xml_add_namespace add_namespace;

  _upnp_cds_change_contents_xml_audio_res change_audio_res;

#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING
  _upnp_cds_user_agent_database_get_protocol_list_by_content_id cds_database_get_protocol_list_by_content_id;
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */
};


/* ****** Subtitle ****** */
#ifdef ENABLE_SUBTITLE_SUPPORT
struct _upnp_cds_user_agent_customization_subtitle;
struct sbuf;
struct contents_manager;
struct contents;
struct video_subtitle;
struct _extended_flags;

/*
 * Create header
 */
typedef void
(* content_xml_desc_header)(
    struct sbuf * sbuf,
    slim_char * in_resURI);


/*
 * Create footer
 */
typedef void
(* content_xml_desc_footer)(
    struct sbuf * sbuf);

/*
 * Create subtitle xml
 */
typedef void
(* contents_xml_video_subtitle) (
    struct contents_manager * cm,
    struct contents * c,
    struct video_subtitle * video_subtitle,
    struct sbuf * sbuf,
    slim_int ifindex,
    struct _extended_flags * ext_flags);


 /*
  * Interface
  */
struct _upnp_cds_user_agent_customization_subtitle
{
  // Inherited base customization
  struct _upnp_cds_user_agent_customization_base base;

  content_xml_desc_header desc_header;
  contents_xml_video_subtitle video_subtitle_res;
  content_xml_desc_footer desc_footer;
  contents_xml_video_subtitle video_subtitle_info;
};
#endif /* ENABLE_SUBTITLE_SUPPORT */

/* ****** Collection ****** */

struct _upnp_cds_user_agent_customizations
{
  //Fields
  slim_char * device_name;
  struct _upnp_cds_user_agent_customization_mime_type_conversion * mime_type;
  struct _upnp_cds_user_agent_customization_playlist * generated_playlist;
  struct _upnp_cds_user_agent_customization_reference * reference;
  struct _upnp_cds_user_agent_customization_xml * xml;
#ifdef ENABLE_SUBTITLE_SUPPORT
  struct _upnp_cds_user_agent_customization_subtitle * subtitle;
#endif /* ENABLE_SUBTITLE_SUPPORT */
};


struct _upnp_cds_user_agent_customizations *
upnp_cds_user_agent_customization_alloc();


struct _upnp_cds_user_agent_mime_map_entry
{
  slim_word content_type;
  slim_char * mime_type;
};

enum _upnp_cds_user_agent_mime_type_customization_type
{
  UPNP_CDS_USER_AGENT_MIME_CUSTOMIZATION_DEFAULT = 0,
  UPNP_CDS_USER_AGENT_MIME_CUSTOMIZATION_CONVERSION,
};

struct _upnp_cds_user_agent_playlist_customization_configuration
{
  slim_word is_container_enabled;
  slim_word is_generated_enabled;
  slim_word is_virtual_enabled;
};

struct _upnp_cds_user_agent_reference_customization_configuration
{
  slim_word is_video_thumbnail_enabled;
};


enum _upnp_cds_user_agent_xml_customization_type
{
  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_DEFAULT = 0,
  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_XMMRR,


#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_MS_CERT_TOOL

  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_MS_CERT_TOOL,

#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_MS_CERT_TOOL */


  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_MEDIAROOM,

  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_SAMSUNG_TV,
#ifdef DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING
  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_SONY_BRAVIA,
#endif /* DEVELOPMENT_ENABLE_USER_AGENT_CUSTOMIZATION_SONY_BRAVIA_PROFILING */ 
//#ifdef DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE
  UPNP_CDS_USER_AGENT_XML_CUSTOMIZATION_WD_TV_LIVE_HUB,
//#endif /* DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE */
};

#ifdef ENABLE_SUBTITLE_SUPPORT
enum _upnp_cds_user_agent_subtitle_customization_type
{
  UPNP_CDS_USER_AGENT_SUBTITLE_CUSTOMIZATION_DEFAULT = 0,
#ifdef DEVELOPMENT_SAMSUNG_SUBTITLE
  UPNP_CDS_USER_AGENT_SUBTITLE_CUSTOMIZATION_SAMSUNG_TV,
#endif /* DEVELOPMENT_SAMSUNG_SUBTITLE */
#ifdef DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE
  UPNP_CDS_USER_AGENT_SUBTITLE_CUSTOMIZATION_WD_TV_LIVE_HUB,
#endif /* DEVELOPMENT_WD_TV_LIVE_HUB_SUBTITLE */
};
#endif /* ENABLE_SUBTITLE_SUPPORT */

slim_int
upnp_cds_user_agent_customization_init (
    struct _upnp_cds_user_agent_customizations * obj,
    slim_char * device_name,
    enum _upnp_cds_user_agent_mime_type_customization_type mime_customization,
    struct _upnp_cds_user_agent_mime_map_entry * mime_map,
    const slim_word mime_map_size,
    struct _upnp_cds_user_agent_playlist_customization_configuration * playlist_configuration,
    struct _upnp_cds_user_agent_reference_customization_configuration * reference_configuration,
    enum _upnp_cds_user_agent_xml_customization_type xml_type
#ifdef ENABLE_SUBTITLE_SUPPORT
    , enum _upnp_cds_user_agent_subtitle_customization_type subtitle_type
#endif /* ENABLE_SUBTITLE_SUPPORT */
);

void
upnp_cds_user_agent_customization_free(
    struct _upnp_cds_user_agent_customizations * obj);


#endif /* UPNP_CDS_USER_AGENT_CUSTOMIZATION_H_ */
