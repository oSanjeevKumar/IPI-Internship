#ifndef _CONTENT_API_H_
#define _CONTENT_API_H_

#include <dms_api.h>


slim_int
load_property_by_id(cm_t *cm, storage_config_t* uconf, slim_int id, TDMSContentProperty *out_property);

slim_int
load_usb_devices_into_content_property(cm_t *cm, storage_config_t* uconf, TDMSContentProperty *out_property);

slim_int
load_complete_usb_contents_into_content_properties(cm_t *cm, storage_config_t* uconf, TDMSContentProperty **out_properties,
                           slim_word *matches, slim_word *total, slim_word sindex, slim_word rcount);

slim_int
load_content_by_type(cm_t *cm, TDMSContentBrowseType in_type, TDMSContentProperty **out_properties,
                           slim_word *matches, slim_word *total, slim_word sindex, slim_word rcount);

slim_int
load_property_search(cm_t *cm, slim_char *criteria, TDMSContentProperty **out_properties,
                           slim_word *matches, slim_word *total, slim_word sindex, slim_word rcount);

#ifdef DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT
slim_int
load_pvr_content(cm_t *cm, TDMSContentProperty **out_properties, slim_word *matches, slim_word *total, slim_word sindex, slim_word rcount);
#endif /*DEVELOPMENT_ENABLE_PUBLISH_STREAMING_CONTENT*/

#endif /* _CONTENT_API_H_ */


