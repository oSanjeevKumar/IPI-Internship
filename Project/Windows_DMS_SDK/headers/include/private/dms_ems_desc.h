#ifndef DMS_EMS_DESC_H
#define DMS_EMS_DESC_H

#define DMS_EMS_DESC SLIM_T(\
"<?xml version=\"1.0\"?>" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">" \
"<specVersion>" \
"<major>1</major>" \
"<minor>0</minor>" \
"</specVersion>" \
"<actionList>" \
"<action>" \
"<name>GetInterfaceInfo</name>" \
"<argumentList>" \
"<argument>" \
"<name>NetworkInterfaceInfo</name>" \
"<direction>out</direction>" \
"<relatedStateVariable>NetworkInterfaceInfo</relatedStateVariable>" \
"</argument>" \
"<argument>" \
"<name>ProxiedNetworkInterfaceInfo</name>" \
"<direction>out</direction>" \
"<relatedStateVariable>ProxiedNetworkInterfaceInfo</relatedStateVariable>" \
"</argument>" \
"</argumentList>" \
"</action>" \
"</actionList>" \
"<serviceStateTable>" \
"<stateVariable sendEvents=\"yes\">" \
"<name>NetworkInterfaceInfo</name>" \
"<dataType>string</dataType>" \
"</stateVariable>" \
"<stateVariable sendEvents=\"no\">" \
"<name>ProxiedNetworkInterfaceInfo</name>" \
"<dataType>string</dataType>" \
"</stateVariable>" \
"</serviceStateTable>" \
"</scpd>" \
)

#endif /* DMS_EMS_DESC_H */
