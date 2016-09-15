#ifndef __RUISRC_DESCR_H__
#define __RUISRC_DESCR_H__

#ifdef DEVELOPMENT_DLNA_SUPPORT_RUIHSRC
#define RUISRC_CAP "+RUIHSRC+"
#else
#define RUISRC_CAP "+RUISRC+"
#endif /* DEVELOPMENT_DLNA_SUPPORT_RUIHSRC */

#ifdef DLNA_RUISRC_SERVER_LEVEL_1

#define RUISRC_DEVDESCR  SLIM_T(\
"<device xmlns:rui=\"urn:schemas-ce-org:cea2014-server-ext-1-0\"\n" \
"        xmlns:dlna=\"urn:schemas-dlna-org:device-1-0\">\n" \
"  <dlna:X_DLNADOC>" RUISRC_CAP "/DMS-1.50</dlna:X_DLNADOC> \n" \
"  <deviceType>urn:schemas-ce-org:device:RemoteUIServerDevice:1</deviceType> \n" \
"  <friendlyName></friendlyName> \n" \
"  <manufacturer></manufacturer> \n" \
"  <manufacturerURL></manufacturerURL> \n" \
"  <modelName></modelName> \n" \
"  <modelNumber></modelNumber> \n" \
"  <modelURL></modelURL> \n" \
"  <UDN>uuid:00000000-0000-0000-0000-000000000000</UDN>\n" \
"  <rui:uiServerInfo>\n" \
"    <rui:uiListURL>/ruisrc_uilist.xml</rui:uiListURL>\n" \
"  </rui:uiServerInfo>\n" \
"  <serviceList>\n" \
"    <service>\n" \
"      <serviceType>urn:schemas-ce-org:service:RemoteUIServer:1</serviceType>\n" \
"      <serviceId>urn:ce-org:serviceId:RemoteUIServer1</serviceId>\n" \
"      <SCPDURL>/ruisrc_scpd_l1.xml</SCPDURL>\n" \
"      <controlURL />\n" \
"      <eventSubURL >event/RemoteUIServer1</eventSubURL>\n" \
"    </service>\n" \
"  </serviceList>\n" \
"  <iconList>\n" \
"    <icon>\n" \
"      <mimetype>image/jpeg</mimetype>\n" \
"      <width>48</width>\n" \
"      <height>48</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-small.jpg</url>\n" \
"    </icon>\n" \
"    <icon>\n" \
"      <mimetype>image/jpeg</mimetype>\n" \
"      <width>120</width>\n" \
"      <height>120</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-large.jpg</url>\n" \
"    </icon>\n" \
"    <icon>\n" \
"      <mimetype>image/png</mimetype>\n" \
"      <width>48</width>\n" \
"      <height>48</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-small.png</url>\n" \
"    </icon>\n" \
"    <icon>\n" \
"      <mimetype>image/png</mimetype>\n" \
"      <width>120</width>\n" \
"      <height>120</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-large.png</url>\n" \
"    </icon>\n" \
"  </iconList>\n" \
"</device>\n")

#define RUISRC_SCPD_URL SLIM_T("/ruisrc_scpd_l1.xml")

#define RUISRC_SCPD  SLIM_T(\
"<?xml version=\"1.0\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"  <actionList>\n" \
"  </actionList>\n" \
"  <serviceStateTable>\n" \
"    <stateVariable sendEvents=\"yes\" multicast=\"yes\">\n" \
"      <name>ruiEventURL</name>\n" \
"      <dataType>string</dataType>\n" \
"    </stateVariable>\n" \
"  </serviceStateTable>\n" \
"</scpd>\n")

#else /* DLNA_RUISRC_SERVER_LEVEL_1 */

#define RUISRC_DEVDESCR  SLIM_T(\
"<device xmlns:rui=\"urn:schemas-ce-org:cea2014-server-ext-1-0\"\n" \
"        xmlns:dlna=\"urn:schemas-dlna-org:device-1-0\">\n" \
"  <dlna:X_DLNADOC>" RUISRC_CAP "/DMS-1.50</dlna:X_DLNADOC>\n" \
"  <deviceType>urn:schemas-upnp-org:device:RemoteUIServerDevice:1</deviceType>\n" \
"  <friendlyName></friendlyName> \n" \
"  <manufacturer></manufacturer> \n" \
"  <manufacturerURL></manufacturerURL> \n" \
"  <modelName></modelName> \n" \
"  <modelNumber></modelNumber> \n" \
"  <modelURL></modelURL> \n" \
"  <UDN>uuid:00000000-0000-0000-0000-000000000000</UDN>\n" \
"  <rui:uiServerInfo>\n" \
"    <rui:uiListURL>/ruisrc_uilist.xml</rui:uiListURL>\n" \
"  </rui:uiServerInfo>\n" \
"  <serviceList>\n" \
"    <service>\n" \
"      <serviceType>urn:schemas-upnp-org:service:RemoteUIServer:1</serviceType>\n" \
"      <serviceId>urn:upnp-org:serviceId:RemoteUIServer1</serviceId>\n" \
"      <SCPDURL>/ruisrc_scpd_l2.xml</SCPDURL>\n" \
"      <controlURL>/control/Level2RemoteUIServer1</controlURL>\n" \
"      <eventSubURL>/event/Level2RemoteUIServer1</eventSubURL>\n" \
"    </service>\n" \
"  </serviceList>\n" \
"  <iconList>\n" \
"    <icon>\n" \
"      <mimetype>image/jpeg</mimetype>\n" \
"      <width>48</width>\n" \
"      <height>48</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-small.jpg</url>\n" \
"    </icon>\n" \
"    <icon>\n" \
"      <mimetype>image/jpeg</mimetype>\n" \
"      <width>120</width>\n" \
"      <height>120</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-large.jpg</url>\n" \
"    </icon>\n" \
"    <icon>\n" \
"      <mimetype>image/png</mimetype>\n" \
"      <width>48</width>\n" \
"      <height>48</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-small.png</url>\n" \
"    </icon>\n" \
"    <icon>\n" \
"      <mimetype>image/png</mimetype>\n" \
"      <width>120</width>\n" \
"      <height>120</height>\n" \
"      <depth>24</depth>\n" \
"      <url>/icon/DMS-large.png</url>\n" \
"    </icon>\n" \
"  </iconList>\n" \
"</device>\n")

#define RUISRC_SCPD_URL SLIM_T("/ruisrc_scpd_l2.xml")

#define RUISRC_SCPD  SLIM_T(\
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n" \
"  <specVersion>\n" \
"    <major>1</major>\n" \
"    <minor>0</minor>\n" \
"  </specVersion>\n" \
"  <actionList>\n" \
"    <action>\n" \
"      <name>GetCompatibleUIs</name>\n" \
"      <argumentList>\n" \
"        <argument>\n" \
"          <name>InputDeviceProfile</name>\n" \
"          <direction>in</direction>\n" \
"          <relatedStateVariable>A_ARG_TYPE_DeviceProfile</relatedStateVariable>\n" \
"        </argument>\n" \
"        <argument>\n" \
"          <name>UIFilter</name>\n" \
"          <direction>in</direction>\n" \
"          <relatedStateVariable>A_ARG_TYPE_String</relatedStateVariable>\n" \
"        </argument>\n" \
"        <argument>\n" \
"          <name>UIListing</name>\n" \
"          <direction>out</direction>\n" \
"          <relatedStateVariable>A_ARG_TYPE_CompatibleUIs</relatedStateVariable>\n" \
"        </argument>\n" \
"      </argumentList>\n" \
"    </action>\n" \
"    <action>\n" \
"      <name>SetUILifetime</name>\n" \
"      <argumentList>\n" \
"        <argument>\n" \
"          <name>UI</name>\n" \
"          <direction>in</direction>\n" \
"          <relatedStateVariable>A_ARG_TYPE_URI</relatedStateVariable>\n" \
"        </argument>\n" \
"        <argument>\n" \
"          <name>Lifetime</name>\n" \
"          <direction>in</direction>\n" \
"          <relatedStateVariable>A_ARG_TYPE_Int</relatedStateVariable>\n" \
"        </argument>\n" \
"      </argumentList>\n" \
"    </action>\n" \
"  </actionList>\n" \
"  <serviceStateTable>\n" \
"    <stateVariable sendEvents=\"no\">\n" \
"      <name>A_ARG_TYPE_DeviceProfile</name>\n" \
"      <dataType>string</dataType>\n" \
"    </stateVariable>\n" \
"    <stateVariable sendEvents=\"no\">\n" \
"      <name>A_ARG_TYPE_URI</name>\n" \
"      <dataType>uri</dataType>\n" \
"    </stateVariable>\n" \
"    <stateVariable sendEvents=\"no\">\n" \
"      <name>A_ARG_TYPE_CompatibleUIs</name>\n" \
"      <dataType>string</dataType>\n" \
"    </stateVariable>\n" \
"    <stateVariable sendEvents=\"no\">\n" \
"      <name>A_ARG_TYPE_String</name>\n" \
"      <dataType>string</dataType>\n" \
"    </stateVariable>\n" \
"    <stateVariable sendEvents=\"no\">\n" \
"      <name>A_ARG_TYPE_Int</name>\n" \
"      <dataType>int</dataType>\n" \
"    </stateVariable>\n" \
"  </serviceStateTable>\n" \
"</scpd>\n")

#endif /* DLNA_RUISRC_SERVER_LEVEL_1 */

#define RUISRC_UILIST_FILTER_TEMPLATE  SLIM_T(\
"<ui>\n" \
"  <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>REQUIRED</internal_visibility>\n" \
"  <uiID>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>REQUIRED</internal_visibility>\n" \
"    <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"  </uiID>\n" \
"  <name>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>REQUIRED</internal_visibility>\n" \
"    <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"  </name>\n" \
"  <description>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>OPTIONAL</internal_visibility>\n" \
"    <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"  </description>\n" \
"  <iconList>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>OPTIONAL</internal_visibility>\n" \
"    <icon>\n" \
"      <internal_type>ELEMENT</internal_type>\n" \
"      <internal_visibility>OPTIONAL</internal_visibility>\n" \
"      <mimetype>\n" \
"        <internal_type>ELEMENT</internal_type>\n" \
"        <internal_visibility>OPTIONAL</internal_visibility>\n" \
"        <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"      </mimetype>\n" \
"      <width>\n" \
"        <internal_type>ELEMENT</internal_type>\n" \
"        <internal_visibility>OPTIONAL</internal_visibility>\n" \
"        <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"      </width>\n" \
"      <height>\n" \
"        <internal_type>ELEMENT</internal_type>\n" \
"        <internal_visibility>OPTIONAL</internal_visibility>\n" \
"        <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"      </height>\n" \
"      <depth>\n" \
"        <internal_type>ELEMENT</internal_type>\n" \
"        <internal_visibility>OPTIONAL</internal_visibility>\n" \
"        <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"      </depth>\n" \
"      <url>\n" \
"        <internal_type>ELEMENT</internal_type>\n" \
"        <internal_visibility>OPTIONAL</internal_visibility>\n" \
"        <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"      </url>\n" \
"    </icon>\n" \
"  </iconList>\n" \
"  <fork>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>OPTIONAL</internal_visibility>\n" \
"    <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"  </fork>\n" \
"  <lifetime>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>OPTIONAL</internal_visibility>\n" \
"    <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"  </lifetime>\n" \
"  <protocol>\n" \
"    <internal_type>ELEMENT</internal_type>\n" \
"    <internal_visibility>REQUIRED</internal_visibility>\n" \
"    <shortName>\n" \
"      <internal_type>ATTRIBUTE</internal_type>\n" \
"      <internal_visibility>REQUIRED</internal_visibility>\n" \
"      <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"    </shortName>\n" \
"    <uri>\n" \
"      <internal_type>ELEMENT</internal_type>\n" \
"      <internal_visibility>REQUIRED</internal_visibility>\n" \
"      <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"    </uri>\n" \
"    <protocolInfo>\n" \
"      <internal_type>ELEMENT</internal_type>\n" \
"      <internal_visibility>REQUIRED</internal_visibility>\n" \
"      <relatedData>\n" \
"        <internal_type>ELEMENT</internal_type>\n" \
"        <internal_visibility>REQUIRED</internal_visibility>\n" \
"        <profilelist>\n" \
"          <internal_type>ELEMENT</internal_type>\n" \
"          <internal_visibility>REQUIRED</internal_visibility>\n" \
"          <ui_profile>\n" \
"            <internal_type>ELEMENT</internal_type>\n" \
"            <internal_visibility>REQUIRED</internal_visibility>\n" \
"            <name>\n" \
"              <internal_type>ATTRIBUTE</internal_type>\n" \
"              <internal_visibility>REQUIRED</internal_visibility>\n" \
"              <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"            </name>\n" \
"          </ui_profile>\n" \
"          <audio_profile>\n" \
"            <internal_type>ELEMENT</internal_type>\n" \
"            <internal_visibility>REQUIRED</internal_visibility>\n" \
"            <name>\n" \
"              <internal_type>ATTRIBUTE</internal_type>\n" \
"              <internal_visibility>REQUIRED</internal_visibility>\n" \
"              <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"            </name>\n" \
"            <type>\n" \
"              <internal_type>ATTRIBUTE</internal_type>\n" \
"              <internal_visibility>REQUIRED</internal_visibility>\n" \
"              <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"            </type>\n" \
"          </audio_profile>\n" \
"          <video_profile>\n" \
"            <internal_type>ELEMENT</internal_type>\n" \
"            <internal_visibility>REQUIRED</internal_visibility>\n" \
"            <name>\n" \
"              <internal_type>ATTRIBUTE</internal_type>\n" \
"              <internal_visibility>REQUIRED</internal_visibility>\n" \
"              <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"            </name>\n" \
"            <type>\n" \
"              <internal_type>ATTRIBUTE</internal_type>\n" \
"              <internal_visibility>REQUIRED</internal_visibility>\n" \
"              <internal_filter_value>NOT_AVAILABLE</internal_filter_value>\n" \
"            </type>\n" \
"          </video_profile>\n" \
"        </profilelist>\n" \
"      </relatedData>\n" \
"    </protocolInfo>\n" \
"  </protocol>\n" \
"</ui>\n")

#endif /* __RUISRC_DESCR_H__ */

