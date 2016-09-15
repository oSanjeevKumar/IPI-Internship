#ifndef DMR_RCS_DESC_H
#define DMR_RCS_DESC_H

#define DBVOLMIN "-32767"
#define DBVOLMAX "32767"

#ifdef HAVE_SIGMA

#define DMR_RCS_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<serviceStateTable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>PresetNameList</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\"> \n" \
"<name>LastChange</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Channel</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>Master</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_InstanceID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_PresetName</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>FactoryDefaults</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"</serviceStateTable>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>ListPresets</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentPresetNameList</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>PresetNameList</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>SelectPreset</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PresetName</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PresetName</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"</actionList>\n" \
"</scpd>\n")

#else

#define DMR_RCS_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<serviceStateTable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>PresetNameList</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\"> \n" \
"<name>LastChange</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>Mute</name>\n" \
"<dataType>boolean</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>Volume</name>\n" \
"<dataType>ui2</dataType>\n" \
"<allowedValueRange>\n" \
"<minimum>0</minimum>\n" \
"<maximum>100</maximum>\n" \
"<step>1</step>\n" \
"</allowedValueRange> \n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>VolumeDB</name>\n" \
"<dataType>i2</dataType>\n" \
"<allowedValueRange>\n" \
"<minimum>"DBVOLMIN"</minimum>\n" \
"<maximum>"DBVOLMAX"</maximum>\n" \
"<step>256</step>\n" \
"</allowedValueRange>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_Channel</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>Master</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_InstanceID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_PresetName</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>FactoryDefaults</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"</serviceStateTable>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>ListPresets</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentPresetNameList</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>PresetNameList</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>SelectPreset</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PresetName</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PresetName</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetMute</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentMute</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>Mute</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>SetMute</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>DesiredMute</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>Mute</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetVolume</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentVolume</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>Volume</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>SetVolume</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>DesiredVolume</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>Volume</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetVolumeDB</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentVolume</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>VolumeDB</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>SetVolumeDB</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>DesiredVolume</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>VolumeDB</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetVolumeDBRange</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Channel</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_Channel</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>MinValue</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>VolumeDB</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>MaxValue</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>VolumeDB</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"</actionList>\n" \
"</scpd>\n")

#endif

#endif /* DMR_RCS_DESC_H */
