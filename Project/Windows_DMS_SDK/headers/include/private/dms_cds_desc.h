#ifndef DMS_CDS_DESC_H
#define DMS_CDS_DESC_H

#if  defined DEVELOPMENT_CDS2 ||defined CDS3

#define STATE_VARIABLE_FEATURE_LIST "<stateVariable sendEvents=\"no\">\n" \
"<name>FeatureList</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n"

#define ACTION_GET_FEATURE_LIST "<action>\n" \
"<name>GetFeatureList</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>FeatureList</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>FeatureList</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"
#else /* DEVELOPMENT_CDS2 */
#define STATE_VARIABLE_FEATURE_LIST ""
#define ACTION_GET_FEATURE_LIST ""
#endif /* DEVELOPMENT_CDS2 */

#if defined CDS3
#define ACTION_GET_SERVISE_TOKEN	"<action>\n" \
"<name>GetServiceResetToken</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ResetToken</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>ServiceResetToken</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"
#else
#define ACTION_GET_SERVISE_TOKEN	""
#endif	

#if defined DLNA_SUPPORT_UPLOADER 
#define ACTION_CREATE_OBJECT	"<action>\n" \
"<name>CreateObject</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ContainerID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Elements</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>ObjectID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" 

#define ACTION_DESTROY_OBJECT	"<action>\n" \
"<name>DestroyObject</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ObjectID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" 
#else
#define ACTION_CREATE_OBJECT ""
#define ACTION_DESTROY_OBJECT ""
#endif


#if defined	(ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS)
#define STATE_VARIABLE_CONTAINER_UPDATE_IDS	"<stateVariable sendEvents=\"yes\">\n" \
"<name>ContainerUpdateIDs</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" 
#else /* ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS */
#define STATE_VARIABLE_CONTAINER_UPDATE_IDS ""
#endif /* ENABLE_CDS_1_0_CONTAINER_UPDATE_IDS */


#define DMS_CDS_DESC_UPLOAD  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>GetSearchCapabilities</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>SearchCaps</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SearchCapabilities</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetSortCapabilities</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>SortCaps</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SortCapabilities</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetSystemUpdateID</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>Id</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SystemUpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
ACTION_GET_SERVISE_TOKEN \
ACTION_GET_FEATURE_LIST \
"<action>\n" \
"<name>Browse</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ObjectID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>BrowseFlag</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_BrowseFlag</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Filter</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Filter</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>StartingIndex</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Index</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RequestedCount</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>SortCriteria</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SortCriteria</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NumberReturned</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TotalMatches</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>UpdateID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_UpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>Search</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ContainerID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>SearchCriteria</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SearchCriteria</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Filter</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Filter</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>StartingIndex</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Index</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RequestedCount</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>SortCriteria</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SortCriteria</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NumberReturned</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TotalMatches</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>UpdateID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_UpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
ACTION_CREATE_OBJECT \
ACTION_DESTROY_OBJECT \
"</actionList>\n" \
"<serviceStateTable>\n" \
STATE_VARIABLE_FEATURE_LIST \
"<stateVariable>\n" \
"<name>TransferIDs</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ObjectID</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Result</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_SearchCriteria</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_BrowseFlag</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>BrowseMetadata</allowedValue>\n" \
"<allowedValue>BrowseDirectChildren</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Filter</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_SortCriteria</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Index</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Count</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_UpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>SearchCapabilities</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>SortCapabilities</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>SystemUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
STATE_VARIABLE_CONTAINER_UPDATE_IDS \
"</serviceStateTable>\n" \
"</scpd>\n")

#define DMS_CDS_DESC_NOUPLOAD  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>GetSearchCapabilities</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>SearchCaps</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SearchCapabilities</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetSortCapabilities</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>SortCaps</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SortCapabilities</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetSystemUpdateID</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>Id</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SystemUpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
ACTION_GET_SERVISE_TOKEN \
ACTION_GET_FEATURE_LIST \
"<action>\n" \
"<name>Browse</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ObjectID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>BrowseFlag</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_BrowseFlag</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Filter</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Filter</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>StartingIndex</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Index</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RequestedCount</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>SortCriteria</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SortCriteria</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NumberReturned</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TotalMatches</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>UpdateID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_UpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>Search</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ContainerID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>SearchCriteria</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SearchCriteria</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Filter</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Filter</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>StartingIndex</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Index</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RequestedCount</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>SortCriteria</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SortCriteria</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NumberReturned</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TotalMatches</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Count</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>UpdateID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_UpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"</actionList>\n" \
"<serviceStateTable>\n" \
STATE_VARIABLE_FEATURE_LIST \
"<stateVariable>\n" \
"<name>TransferIDs</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ObjectID</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Result</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_SearchCriteria</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_BrowseFlag</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>BrowseMetadata</allowedValue>\n" \
"<allowedValue>BrowseDirectChildren</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Filter</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_SortCriteria</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Index</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Count</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_UpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>SearchCapabilities</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>SortCapabilities</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>SystemUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
STATE_VARIABLE_CONTAINER_UPDATE_IDS \
"</serviceStateTable>\n" \
"</scpd>\n")

#endif /* DMS_CDS_DESC_H */
