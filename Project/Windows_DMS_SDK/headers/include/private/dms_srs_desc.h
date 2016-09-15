#ifndef DMS_SRS_DESC_H
#define DMS_SRS_DESC_H

#define DMS_SRS_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<serviceStateTable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>SortCapabilities</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>SortLevelCapability</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>StateUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>LastChange</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_PropertyList</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_DataTypeID</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>A_ARG_TYPE_RecordSchedule</allowedValue>\n" \
"<allowedValue>A_ARG_TYPE_RecordTask</allowedValue>\n" \
"<allowedValue>A_ARG_TYPE_RecordScheduleParts</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ObjectID</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ObjectIDList</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_PropertyInfo</name>\n" \
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
"<name>A_ARG_TYPE_SortCriteria</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_RecordSchedule</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_RecordTask</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_RecordScheduleParts</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"</serviceStateTable>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>BrowseRecordSchedules</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>Filter</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PropertyList</relatedStateVariable>\n" \
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
"<relatedStateVariable>A_ARG_TYPE_RecordSchedule</relatedStateVariable>\n" \
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
"<relatedStateVariable>StateUpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>CreateRecordSchedule</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>Elements</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_RecordScheduleParts</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RecordScheduleID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_RecordSchedule</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>UpdateID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>StateUpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>DeleteRecordSchedule</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>RecordScheduleID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetRecordSchedule</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>RecordScheduleID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ObjectID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Filter</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PropertyList</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_RecordSchedule</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>UpdateID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>StateUpdateID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"</actionList>\n" \
"</scpd>\n")

#endif /* DMS_SRS_DESC_H */
