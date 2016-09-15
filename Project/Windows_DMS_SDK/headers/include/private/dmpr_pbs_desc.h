/*
 * dmpr_pbs_desc.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef DMPR_PBS_DESC_H_
#define DMPR_PBS_DESC_H_
#define DMPR_PBS_DESC SLIM_T(\
"<?xml version=\"1.0\"?>\n"\
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n"\
"<specVersion>\n"\
"<major>1</major>\n"\
"<minor>0</minor>\n"\
"</specVersion>\n"\
"<actionList>\n"\
"<action>\n"\
"<name>CreateJob</name>\n"\
"<argumentList>\n"\
"<argument>\n"\
"<name>JobName</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>JobName</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobOriginatingUserName</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>JobOriginatingUserName</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>DocumentFormat</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>DocumentFormat</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>Copies</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>Copies</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>Sides</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>Sides</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>NumberUp</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>NumberUp</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>OrientationRequested</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>OrientationRequested</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>MediaSize</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>MediaSize</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>MediaType</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>MediaType</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>PrintQuality</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>PrintQuality</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobId</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>JobId</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>DataSink</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>DataSink</relatedStateVariable>\n"\
"</argument>\n"\
"</argumentList>\n"\
"</action>\n"\
"<action>\n"\
"<name>CancelJob</name>\n"\
"<argumentList>\n"\
"<argument>\n"\
"<name>JobId</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>JobId</relatedStateVariable>\n"\
"</argument>\n"\
"</argumentList>\n"\
"</action>\n"\
"<action>\n"\
"<name>GetPrinterAttributes</name>\n"\
"<argumentList>\n"\
"<argument>\n"\
"<name>PrinterState</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>PrinterState</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>PrinterStateReasons</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>PrinterStateReasons</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobIdList</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>JobIdList</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobId</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>JobId</relatedStateVariable>\n"\
"</argument>\n"\
"</argumentList>\n"\
"</action>\n"\
"<action>\n"\
"<name>GetJobAttributes</name>\n"\
"<argumentList>\n"\
"<argument>\n"\
"<name>JobId</name>\n"\
"<direction>in</direction>\n"\
"<relatedStateVariable>JobId</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobName</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>JobName</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobOriginatingUserName</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>JobOriginatingUserName</relatedStateVariable>\n"\
"</argument>\n"\
"<argument>\n"\
"<name>JobMediaSheetsCompleted</name>\n"\
"<direction>out</direction>\n"\
"<relatedStateVariable>JobMediaSheetsCompleted</relatedStateVariable>\n"\
"</argument>\n"\
"</argumentList>\n"\
"</action>\n"\
"</actionList>\n"\
"<serviceStateTable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>PrinterName</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>PrinterLocation</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>DeviceId</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"yes\">\n"\
"<name>PrinterState</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>idle</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>idle</allowedValue>\n"\
"<allowedValue>processing</allowedValue>\n"\
"<allowedValue>stopped</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"yes\">\n"\
"<name>PrinterStateReasons</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>none</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>none</allowedValue>\n"\
"<allowedValue>attention-required</allowedValue>\n"\
"<allowedValue>media-jam</allowedValue>\n"\
"<allowedValue>paused</allowedValue>\n"\
"<allowedValue>door-open</allowedValue>\n"\
"<allowedValue>media-low</allowedValue>\n"\
"<allowedValue>media-empty</allowedValue>\n"\
"<allowedValue>output-area-almost-full</allowedValue>\n"\
"<allowedValue>output-area-full</allowedValue>\n"\
"<allowedValue>marker-supply-low</allowedValue>\n"\
"<allowedValue>marker-supply-empty</allowedValue>\n"\
"<allowedValue>marker-failure</allowedValue>\n"\
"<allowedValue>media-change-request</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>XHTMLImageSupported</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>image/jpeg</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>image/jpeg</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>ColorSupported</name>\n"\
"<dataType>boolean</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"yes\">\n"\
"<name>JobIdList</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>JobId</name>\n"\
"<dataType>i4</dataType>\n"\
"<defaultValue>0</defaultValue>\n"\
"<allowedValueRange>\n"\
"<minimum>0</minimum>\n"\
"<maximum>2147483647</maximum>\n"\
"<step>1</step>\n"\
"</allowedValueRange>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"yes\">\n"\
"<name>JobEndState</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>JobName</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>JobOriginatingUserName</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>DocumentFormat</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>unknown</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>unknown</allowedValue>\n"\
"<allowedValue>application/vnd.pwg-xhtml-print</allowedValue>\n"\
"<allowedValue>application/octet-stream</allowedValue>\n"\
"<allowedValue>text/plain</allowedValue>\n"\
"<allowedValue>text/plain;charset=utf-8</allowedValue>\n"\
"<allowedValue>application/postscript</allowedValue>\n"\
"<allowedValue>application/vnd.hp-PCL</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>Copies</name>\n"\
"<dataType>i4</dataType>\n"\
"<defaultValue>1</defaultValue>\n"\
"<allowedValueRange>\n"\
"<minimum>0</minimum>\n"\
"<maximum>2147483647</maximum>\n"\
"<step>1</step>\n"\
"</allowedValueRange>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>Sides</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>one-sided</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>one-sided</allowedValue>\n"\
"<allowedValue>two-sided-long-edge</allowedValue>\n"\
"<allowedValue>two-sided-short-edge</allowedValue>\n"\
"<allowedValue>device-setting</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>NumberUp</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>1</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>1</allowedValue>\n"\
"<allowedValue>2</allowedValue>\n"\
"<allowedValue>4</allowedValue>\n"\
"<allowedValue>device-setting</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>OrientationRequested</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>portrait</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>portrait</allowedValue>\n"\
"<allowedValue>landscape</allowedValue>\n"\
"<allowedValue>reverse-landscape</allowedValue>\n"\
"<allowedValue>reverse-portrait</allowedValue>\n"\
"<allowedValue>device-setting</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>MediaSize</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>device-setting</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>MediaType</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>stationery</allowedValue>\n"\
"<allowedValue>transparency</allowedValue>\n"\
"<allowedValue>envelope</allowedValue>\n"\
"<allowedValue>labels</allowedValue>\n"\
"<allowedValue>photographic</allowedValue>\n"\
"<allowedValue>cardstock</allowedValue>\n"\
"<allowedValue>device-setting</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>PrintQuality</name>\n"\
"<dataType>string</dataType>\n"\
"<defaultValue>normal</defaultValue>\n"\
"<allowedValueList>\n"\
"<allowedValue>draft</allowedValue>\n"\
"<allowedValue>normal</allowedValue>\n"\
"<allowedValue>high</allowedValue>\n"\
"<allowedValue>device-setting</allowedValue>\n"\
"</allowedValueList>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"no\">\n"\
"<name>DataSink</name>\n"\
"<dataType>uri</dataType>\n"\
"<defaultValue></defaultValue>\n"\
"</stateVariable>\n"\
"<stateVariable sendEvents=\"yes\">\n"\
"<name>JobMediaSheetsCompleted</name>\n"\
"<dataType>i4</dataType>\n"\
"<defaultValue>0</defaultValue>\n"\
"<allowedValueRange>\n"\
"<minimum>-1</minimum>\n"\
"<maximum>2147483647</maximum>\n"\
"<step>1</step>\n"\
"</allowedValueRange>\n"\
"</stateVariable>\n"\
"</serviceStateTable>\n"\
"</scpd>\n")

#endif /* DMPR_PBS_DESC_H_ */
