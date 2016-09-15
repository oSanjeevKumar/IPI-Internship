#ifndef DMS_XMMRR_DESC_H
#define DMS_XMMRR_DESC_H


#if defined DLNA_SUPPORT_XMMRR

#define DMS_XMMRR_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<serviceStateTable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Result</name>\n" \
"<dataType>int</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_DeviceID</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>AuthorizationGrantedUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>AuthorizationDeniedUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_RegistrationRespMsg</name>\n" \
"<dataType>bin.base64</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_RegistrationReqMsg</name>\n" \
"<dataType>bin.base64</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>ValidationSucceededUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>ValidationRevokedUpdateID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"</serviceStateTable>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>IsAuthorized</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>DeviceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_DeviceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>RegisterDevice</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>RegistrationReqMsg</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_RegistrationReqMsg</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RegistrationRespMsg</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_RegistrationRespMsg</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>IsValidated</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>DeviceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_DeviceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Result</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Result</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"</actionList>\n" \
"</scpd>\n")
#endif /* DLNA_SUPPORT_XMMRR */

#endif /* DMS_XMMRR_DESC_H */
