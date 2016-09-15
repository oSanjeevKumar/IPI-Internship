#ifndef DMR_CMS_DESC_H
#define DMR_CMS_DESC_H

#ifdef RA_USE_RID_HEADER
#define RID_HEADER_ACTIONS "<action>\n" \
"<name>X_PropagatePermission</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>rid</name>\n" \
"<direction>in</direction>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>permission</name>\n" \
"<direction>in</direction>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>X_RevokePermission</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>rid</name>\n" \
"<direction>in</direction>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"
#else
#define RID_HEADER_ACTIONS "" 
#endif //#ifdef RA_USE_RID_HEADER 

#ifdef DLNA_SUPPORT_PROVISIONING
#define PROVISIONING_ACTIONS "<action>\n" \
"<name>X_PropagateProperties</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>properties</name>\n" \
"<direction>in</direction>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"
#else
#define PROVISIONING_ACTIONS "" 
#endif //#ifdef DLNA_SUPPORT_PROVISIONING 



#define DMR_CMS_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<serviceStateTable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>SourceProtocolInfo</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>SinkProtocolInfo</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>CurrentConnectionIDs</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ConnectionStatus</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>OK</allowedValue>\n" \
"<allowedValue>ContentFormatMismatch</allowedValue>\n" \
"<allowedValue>InsufficientBandwidth</allowedValue>\n" \
"<allowedValue>UnreliableChannel</allowedValue>\n" \
"<allowedValue>Unknown</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ConnectionManager</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Direction</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>Input</allowedValue>\n" \
"<allowedValue>Output</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ProtocolInfo</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_ConnectionID</name>\n" \
"<dataType>i4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_AVTransportID</name>\n" \
"<dataType>i4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_RcsID</name>\n" \
"<dataType>i4</dataType>\n" \
"</stateVariable>\n" \
"</serviceStateTable>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>GetProtocolInfo</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>Source</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SourceProtocolInfo</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Sink</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>SinkProtocolInfo</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetCurrentConnectionIDs</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ConnectionIDs</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentConnectionIDs</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetCurrentConnectionInfo</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>ConnectionID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ConnectionID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RcsID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_RcsID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>AVTransportID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_AVTransportID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>ProtocolInfo</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ProtocolInfo</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PeerConnectionManager</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ConnectionManager</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PeerConnectionID</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ConnectionID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Direction</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Direction</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Status</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_ConnectionStatus</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
RID_HEADER_ACTIONS \
PROVISIONING_ACTIONS \
"</actionList>\n" \
"</scpd>\n") 

#endif /* DMR_CMS_DESC_H */
