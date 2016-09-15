#ifndef DMR_AVTS_DESC_H
#define DMR_AVTS_DESC_H

#if defined(DEVELOPMENT_ENABLE_GSTREAMER_SUPPORT) && !defined(DEVELOPMENT_ENABLE_UPNPTRANSPORT_SEEK)
#define SEEKMODE "<allowedValue>ABS_TIME</allowedValue>\n" \
"<allowedValue>REL_TIME</allowedValue>\n" \
"<allowedValue>TRACK_NR</allowedValue>\n" 
#else
#if defined (DEVELOPMENT_DLNA_SUPPORT_HNSO)
/* HNSO configuration */
#define SEEKMODE "<allowedValue>TRACK_NR</allowedValue>\n"
#else
/* common configuration */
#define SEEKMODE "<allowedValue>ABS_TIME</allowedValue>\n" \
"<allowedValue>REL_TIME</allowedValue>\n" \
"<allowedValue>ABS_COUNT</allowedValue>\n" \
"<allowedValue>REL_COUNT</allowedValue>\n" \
"<allowedValue>TRACK_NR</allowedValue>\n" 
#endif
#endif

#ifdef DEVELOPMENT_ENABLE_SERVER_AND_RENDERER_PLAYSPEED
#define TRANSPORT_PLAYSPEED "<dataType>string</dataType>\n"
#else /* DEVELOPMENT_ENABLE_SERVER_AND_RENDERER_PLAYSPEED */
#define TRANSPORT_PLAYSPEED "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>1/16</allowedValue>\n" \
        "<allowedValue>1/8</allowedValue>\n" \
        "<allowedValue>1/4</allowedValue>\n" \
        "<allowedValue>1/2</allowedValue>\n" \
        "<allowedValue>-1/2</allowedValue>\n" \
        "<allowedValue>-1/4</allowedValue>\n" \
        "<allowedValue>-1/8</allowedValue>\n" \
        "<allowedValue>-1/16</allowedValue>\n" \
        "<allowedValue>1</allowedValue>\n" \
        "<allowedValue>2</allowedValue>\n" \
        "<allowedValue>4</allowedValue>\n" \
        "<allowedValue>8</allowedValue>\n" \
        "<allowedValue>16</allowedValue>\n" \
        "<allowedValue>-2</allowedValue>\n" \
        "<allowedValue>-4</allowedValue>\n" \
        "<allowedValue>-8</allowedValue>\n" \
        "<allowedValue>-16</allowedValue>\n" \
      "</allowedValueList>\n"
#endif /* DEVELOPMENT_ENABLE_SERVER_AND_RENDERER_PLAYSPEED */

#ifdef DEVELOPMENT_CLOCK_SYNC

#define STATE_VARIABLE_PRESENTATION_TIME "<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_PresentationTime</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n"

#define ACTION_SYNC_STOP "<action>\n" \
"<name>SyncStop</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>ReferencePresentationTime</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PresentationTime</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"

#define ACTION_SYNC_PLAY "<action>\n" \
"<name>SyncPlay</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Speed</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>ReferencePresentationTime</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PresentationTime</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"

#define ACTION_SYNC_PAUSE "<action>\n" \
"<name>SyncPause</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>ReferencePresentationTime</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_PresentationTime</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n"

#else /* DEVELOPMENT_CLOCK_SYNC */

#define STATE_VARIABLE_PRESENTATION_TIME ""

#define ACTION_SYNC_STOP ""
#define ACTION_SYNC_PLAY ""
#define ACTION_SYNC_PAUSE ""

#endif /* DEVELOPMENT_CLOCK_SYNC */



#ifdef HAVE_SIGMA

#define DMR_AVTS_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"<specVersion>\n" \
"<major>1</major>\n" \
"<minor>0</minor>\n" \
"</specVersion>\n" \
"<serviceStateTable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>TransportState</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>STOPPED</allowedValue>\n" \
"<allowedValue>PAUSED_PLAYBACK</allowedValue>\n" \
"<allowedValue>PLAYING</allowedValue>\n" \
"<allowedValue>TRANSITIONING</allowedValue>\n" \
"<allowedValue>NO_MEDIA_PRESENT</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>TransportStatus</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>OK</allowedValue>\n" \
"<allowedValue>ERROR_OCCURRED</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentMediaCategory</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>NO_MEDIA</allowedValue>\n" \
"<allowedValue>TRACK_AWARE</allowedValue>\n" \
"<allowedValue>TRACK_UNAWARE</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>PlaybackStorageMedium</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>NONE</allowedValue>\n" \
"<allowedValue>NETWORK</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>RecordStorageMedium</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>NOT_IMPLEMENTED</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>PossiblePlaybackStorageMedia</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>PossibleRecordStorageMedia</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentPlayMode</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>NORMAL</allowedValue>\n" \
"</allowedValueList>\n" \
"<defaultValue>NORMAL</defaultValue>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>TransportPlaySpeed</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>1</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
STATE_VARIABLE_PRESENTATION_TIME \
"<stateVariable sendEvents=\"no\">\n" \
"<name>RecordMediumWriteStatus</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>NOT_IMPLEMENTED</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentRecordQualityMode</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>NOT_IMPLEMENTED</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>PossibleRecordQualityModes</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>NumberOfTracks</name>\n" \
"<dataType>ui4</dataType>\n" \
"<allowedValueRange>\n" \
"<minimum>0</minimum>\n" \
"<maximum>65535</maximum>\n" \
"</allowedValueRange>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentTrack</name>\n" \
"<dataType>ui4</dataType>\n" \
"<allowedValueRange>\n" \
"<minimum>0</minimum>\n" \
"<maximum>65535</maximum>\n" \
"<step>1</step>\n" \
"</allowedValueRange>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentTrackDuration</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentMediaDuration</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentTrackMetaData</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>CurrentTrackURI</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>AVTransportURI</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>AVTransportURIMetaData</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>NextAVTransportURI</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>NextAVTransportURIMetaData</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>RelativeTimePosition</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>AbsoluteTimePosition</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>RelativeCounterPosition</name>\n" \
"<dataType>i4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>AbsoluteCounterPosition</name>\n" \
"<dataType>i4</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"yes\">\n" \
"<name>LastChange</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_SeekMode</name>\n" \
"<dataType>string</dataType>\n" \
"<allowedValueList>\n" \
"<allowedValue>TRACK_NR</allowedValue>\n" \
"</allowedValueList>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_SeekTarget</name>\n" \
"<dataType>string</dataType>\n" \
"</stateVariable>\n" \
"<stateVariable sendEvents=\"no\">\n" \
"<name>A_ARG_TYPE_InstanceID</name>\n" \
"<dataType>ui4</dataType>\n" \
"</stateVariable>\n" \
"</serviceStateTable>\n" \
"<actionList>\n" \
"<action>\n" \
"<name>SetAVTransportURI</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentURI</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>AVTransportURI</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentURIMetaData</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>AVTransportURIMetaData</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>SetNextAVTransportURI</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NextURI</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>NextAVTransportURI</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NextURIMetaData</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>NextAVTransportURIMetaData</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetMediaInfo</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NrTracks</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>NumberOfTracks</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>MediaDuration</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentMediaDuration</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentURI</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>AVTransportURI</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentURIMetaData</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>AVTransportURIMetaData</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NextURI</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>NextAVTransportURI</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>NextURIMetaData</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>NextAVTransportURIMetaData</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PlayMedium</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>PlaybackStorageMedium</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RecordMedium</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>RecordStorageMedium</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>WriteStatus</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>RecordMediumWriteStatus</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetTransportInfo</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentTransportState</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>TransportState</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentTransportStatus</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>TransportStatus</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>CurrentSpeed</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetPositionInfo</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Track</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentTrack</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TrackDuration</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentTrackDuration</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TrackMetaData</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentTrackMetaData</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>TrackURI</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentTrackURI</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RelTime</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>RelativeTimePosition</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>AbsTime</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>AbsoluteTimePosition</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RelCount</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>RelativeCounterPosition</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>AbsCount</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>AbsoluteCounterPosition</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetDeviceCapabilities</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PlayMedia</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>PossiblePlaybackStorageMedia</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RecMedia</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>PossibleRecordStorageMedia</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RecQualityModes</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>PossibleRecordQualityModes</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>GetTransportSettings</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>PlayMode</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentPlayMode</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>RecQualityMode</name>\n" \
"<direction>out</direction>\n" \
"<relatedStateVariable>CurrentRecordQualityMode</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>Stop</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
ACTION_SYNC_STOP \
"<action>\n" \
"<name>Play</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Speed</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
ACTION_SYNC_PLAY \
"<action>\n" \
"<name>Pause</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
ACTION_SYNC_PAUSE \
"<action>\n" \
"<name>Seek</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Unit</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SeekMode</relatedStateVariable>\n" \
"</argument>\n" \
"<argument>\n" \
"<name>Target</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_SeekTarget</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>Next</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"<action>\n" \
"<name>Previous</name>\n" \
"<argumentList>\n" \
"<argument>\n" \
"<name>InstanceID</name>\n" \
"<direction>in</direction>\n" \
"<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
"</argument>\n" \
"</argumentList>\n" \
"</action>\n" \
"</actionList>\n" \
"</scpd>\n")

#else /* HAVE_SIGMA */

#define DMR_AVTS_DESC  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
  "<specVersion>\n" \
    "<major>1</major>\n" \
    "<minor>0</minor>\n" \
  "</specVersion>\n" \
  "<serviceStateTable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>TransportState</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>STOPPED</allowedValue>\n" \
        "<allowedValue>PAUSED_PLAYBACK</allowedValue>\n" \
        "<allowedValue>PLAYING</allowedValue>\n" \
        "<allowedValue>TRANSITIONING</allowedValue>\n" \
        "<allowedValue>NO_MEDIA_PRESENT</allowedValue>\n" \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>X_AT_TransportState</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>STOPPED</allowedValue>\n" \
        "<allowedValue>PAUSED_PLAYBACK</allowedValue>\n" \
        "<allowedValue>PLAYING</allowedValue>\n" \
        "<allowedValue>TRANSITIONING</allowedValue>\n" \
        "<allowedValue>NO_MEDIA_PRESENT</allowedValue>\n" \
        "<allowedValue>END_OF_MEDIA</allowedValue>\n" \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>TransportStatus</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>OK</allowedValue>\n" \
        "<allowedValue>ERROR_OCCURRED</allowedValue>\n" \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>PlaybackStorageMedium</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>NONE</allowedValue>\n" \
        "<allowedValue>NETWORK</allowedValue>\n" \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>RecordStorageMedium</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>NOT_IMPLEMENTED</allowedValue>\n" \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>PossiblePlaybackStorageMedia</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>PossibleRecordStorageMedia</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentPlayMode</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>NORMAL</allowedValue>\n" \
      "</allowedValueList>\n" \
      "<defaultValue>NORMAL</defaultValue>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>TransportPlaySpeed</name>\n" \
      TRANSPORT_PLAYSPEED \
    "</stateVariable>\n" \
	STATE_VARIABLE_PRESENTATION_TIME \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>X_DLNA_RelativeBytePosition</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>X_DLNA_AbsoluteBytePosition</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>X_DLNA_CurrentTrackSize</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>RecordMediumWriteStatus</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
        "<allowedValue>NOT_IMPLEMENTED</allowedValue>\n" \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentRecordQualityMode</name>\n" \
      "<dataType>string</dataType>\n" \
			"<allowedValueList>\n" \
				"<allowedValue>NOT_IMPLEMENTED</allowedValue>\n" \
			"</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>PossibleRecordQualityModes</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>NumberOfTracks</name>\n" \
      "<dataType>ui4</dataType>\n" \
      "<allowedValueRange>\n" \
        "<minimum>0</minimum>\n" \
        "<maximum>65535</maximum>\n" \
      "</allowedValueRange>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentTrack</name>\n" \
      "<dataType>ui4</dataType>\n" \
      "<allowedValueRange>\n" \
        "<minimum>0</minimum>\n" \
        "<maximum>65535</maximum>\n" \
      "<step>1</step>\n" \
      "</allowedValueRange>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentTrackDuration</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentMediaDuration</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentTrackMetaData</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentTrackURI</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>AVTransportURI</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>AVTransportURIMetaData</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>NextAVTransportURI</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>NextAVTransportURIMetaData</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>RelativeTimePosition</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>AbsoluteTimePosition</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>RelativeCounterPosition</name>\n" \
      "<dataType>i4</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>AbsoluteCounterPosition</name>\n" \
      "<dataType>i4</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"yes\">\n" \
      "<name>LastChange</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>A_ARG_TYPE_SeekMode</name>\n" \
      "<dataType>string</dataType>\n" \
      "<allowedValueList>\n" \
				SEEKMODE \
      "</allowedValueList>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>A_ARG_TYPE_SeekTarget</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>A_ARG_TYPE_InstanceID</name>\n" \
      "<dataType>ui4</dataType>\n" \
    "</stateVariable>\n" \
    "<stateVariable sendEvents=\"no\">\n" \
      "<name>CurrentTransportActions</name>\n" \
      "<dataType>string</dataType>\n" \
    "</stateVariable>\n" \
  "</serviceStateTable>\n" \
  "<actionList>\n" \
    "<action>\n" \
      "<name>SetAVTransportURI</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentURI</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>AVTransportURI</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentURIMetaData</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>AVTransportURIMetaData</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>SetNextAVTransportURI</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>NextURI</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>NextAVTransportURI</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>NextURIMetaData</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>NextAVTransportURIMetaData</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>GetMediaInfo</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>NrTracks</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>NumberOfTracks</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>MediaDuration</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentMediaDuration</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentURI</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>AVTransportURI</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentURIMetaData</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>AVTransportURIMetaData</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>NextURI</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>NextAVTransportURI</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>NextURIMetaData</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>NextAVTransportURIMetaData</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>PlayMedium</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>PlaybackStorageMedium</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RecordMedium</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>RecordStorageMedium</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>WriteStatus</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>RecordMediumWriteStatus</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>GetTransportInfo</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentTransportState</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>TransportState</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentTransportStatus</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>TransportStatus</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>CurrentSpeed</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>GetPositionInfo</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>Track</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentTrack</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>TrackDuration</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentTrackDuration</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>TrackMetaData</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentTrackMetaData</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>TrackURI</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentTrackURI</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RelTime</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>RelativeTimePosition</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>AbsTime</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>AbsoluteTimePosition</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RelCount</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>RelativeCounterPosition</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>AbsCount</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>AbsoluteCounterPosition</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>GetDeviceCapabilities</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>PlayMedia</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>PossiblePlaybackStorageMedia</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RecMedia</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>PossibleRecordStorageMedia</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RecQualityModes</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>PossibleRecordQualityModes</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>GetTransportSettings</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>PlayMode</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentPlayMode</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RecQualityMode</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>CurrentRecordQualityMode</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>GetCurrentTransportActions</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
        "<name>InstanceID</name>\n" \
        "<direction>in</direction>\n" \
        "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
        "<name>Actions</name>\n" \
        "<direction>out</direction>\n" \
        "<relatedStateVariable>CurrentTransportActions</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>Stop</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
	ACTION_SYNC_STOP \
    "<action>\n" \
      "<name>Play</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>Speed</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
	ACTION_SYNC_PLAY \
    "<action>\n" \
    "<name>Pause</name>\n" \
    "<argumentList>\n" \
    "<argument>\n" \
    "<name>InstanceID</name>\n" \
    "<direction>in</direction>\n" \
    "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
    "</argument>\n" \
    "</argumentList>\n" \
    "</action>\n" \
	ACTION_SYNC_PAUSE \
    "<action>\n" \
    "<name>Seek</name>\n" \
    "<argumentList>\n" \
    "<argument>\n" \
    "<name>InstanceID</name>\n" \
    "<direction>in</direction>\n" \
    "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
    "</argument>\n" \
    "<argument>\n" \
    "<name>Unit</name>\n" \
    "<direction>in</direction>\n" \
    "<relatedStateVariable>A_ARG_TYPE_SeekMode</relatedStateVariable>\n" \
    "</argument>\n" \
    "<argument>\n" \
    "<name>Target</name>\n" \
    "<direction>in</direction>\n" \
    "<relatedStateVariable>A_ARG_TYPE_SeekTarget</relatedStateVariable>\n" \
    "</argument>\n" \
    "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
    "<name>Next</name>\n" \
    "<argumentList>\n" \
    "<argument>\n" \
    "<name>InstanceID</name>\n" \
    "<direction>in</direction>\n" \
    "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
    "</argument>\n" \
    "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
    "<name>Previous</name>\n" \
    "<argumentList>\n" \
    "<argument>\n" \
    "<name>InstanceID</name>\n" \
    "<direction>in</direction>\n" \
    "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
    "</argument>\n" \
    "</argumentList>\n" \
    "</action>\n" \
    "<action>\n" \
      "<name>X_DLNA_GetBytePositionInfo</name>\n" \
      "<argumentList>\n" \
        "<argument>\n" \
          "<name>InstanceID</name>\n" \
          "<direction>in</direction>\n" \
          "<relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>TrackSize</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>X_DLNA_CurrentTrackSize</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>RelByte</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>X_DLNA_RelativeBytePosition</relatedStateVariable>\n" \
        "</argument>\n" \
        "<argument>\n" \
          "<name>AbsByte</name>\n" \
          "<direction>out</direction>\n" \
          "<relatedStateVariable>X_DLNA_AbsoluteBytePosition</relatedStateVariable>\n" \
        "</argument>\n" \
      "</argumentList>\n" \
    "</action>\n" \
  "</actionList>\n" \
"</scpd>\n")

#endif /* HAVE_SIGMA */


#endif /* DMR_AVTS_DESC_H */
