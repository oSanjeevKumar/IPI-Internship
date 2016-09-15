/*
 * srs_obj_manager.h
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef SRS_OBJ_MANAGER_H
#define SRS_OBJ_MANAGER_H

#include <srs_db.h>

#undef SRS_SUPPORT_ORDERED_PRIORITY

#define SRS_PATH_LEN          												(1024)     

#define SRS_OBJ_MANAGER_ERROR          -1
#define SRS_OBJ_MANAGER_NO_SUCH_OBJECT -2
#define SRS_OBJ_MANAGER_OUT_OF_MEMORY  -65535
#define SRS_OBJ_MANAGER_OK              0

/*srs Desired Priority Type Allowed Values*/
#define SRS_PRIORITY_TYPE_PREDEF 		"PREDEF"
#define SRS_PRIORITY_TYPE_OBJECTID 	"OBJECTID"

#define SRS_RECORDING_QUALITY_TYPE_DEFAULT 	"DEFAULT"
#define SRS_RECORDING_QUALITY_TYPE_ATSC 		"ATSC"
#define SRS_RECORDING_QUALITY_TYPE_QLEVEL 	"QLEVEL"

#define SRS_RECORDING_QUALITY_AUTO 				"AUTO"
#define SRS_RECORDING_QUALITY_UNKNOWN 		"UNKNOWN"
#define SRS_RECORDING_QUALITY_DEFAULT_HD 	"HD"
#define SRS_RECORDING_QUALITY_DEFAULT_ED 	"ED"
#define SRS_RECORDING_QUALITY_DEFAULT_SD 	"SD"

#define SRS_RECORDING_QUALITY_ATSC_1080p30 	"1080p30"
#define SRS_RECORDING_QUALITY_ATSC_1080p24	"1080p24"
#define SRS_RECORDING_QUALITY_ATSC_1080i60 	"1080i60"
#define SRS_RECORDING_QUALITY_ATSC_720p60 	"720p60"
#define SRS_RECORDING_QUALITY_ATSC_720p30 	"720p30"
#define SRS_RECORDING_QUALITY_ATSC_720p24 	"720p24"
#define SRS_RECORDING_QUALITY_ATSC_480p60 	"480p60"
#define SRS_RECORDING_QUALITY_ATSC_480p30 	"480p30"
#define SRS_RECORDING_QUALITY_ATSC_480p24 	"480p24"
#define SRS_RECORDING_QUALITY_ATSC_480i60 	"480i60"

#define SRS_RECORDING_QUALITY_QLEVEL_1 "Q1"
#define SRS_RECORDING_QUALITY_QLEVEL_2 "Q2"
#define SRS_RECORDING_QUALITY_QLEVEL_3 "Q3"

#define SRS_SCHEDULED_CHANNELID_TYPE_ANALOG 		"ANALOG"
#define SRS_SCHEDULED_CHANNELID_TYPE_DIGITAL 		"DIGITAL"
#define SRS_SCHEDULED_CHANNELID_TYPE_FREQUENCY 	"FREQUENCY"
#define SRS_SCHEDULED_CHANNELID_TYPE_SI 				"SI"
#define SRS_SCHEDULED_CHANNELID_TYPE_LINE 			"LINE"
#define SRS_SCHEDULED_CHANNELID_TYPE_NETWORK 		"NETWORK"

#define SRS_MATCHING_NAME_TYPE_PROGRAM 	"PROGRAM"
#define SRS_MATCHING_NAME_TYPE_SERIES 	"SERIES"

#define SRS_MATCHING_ID_TYPE_PROGRAM 	"SI_PROGRAMID"
#define SRS_MATCHING_ID_TYPE_SERIES 	"SI_SERIESID"

#define SRS_MATCHING_RATING_LIMIT_TYPE_MPAA 					"MPAA.ORG"
#define SRS_MATCHING_RATING_LIMIT_TYPE_RIAA 					"RIAA.ORG"
#define SRS_MATCHING_RATING_LIMIT_TYPE_ESRB 					"ESRB.ORG"
#define SRS_MATCHING_RATING_LIMIT_TYPE_TVGUIDELINES 	"TVGUIDELINES.ORG"

#define SRS_MATCHING_RATING_LIMIT_MPAA_GENERALAUDIENCES 				"G"
#define SRS_MATCHING_RATING_LIMIT_MPAA_PARENTALGUIDANCE 				"PG"
#define SRS_MATCHING_RATING_LIMIT_MPAA_PARENTSTRONGLYCAUTIONED 	"PG-13"
#define SRS_MATCHING_RATING_LIMIT_MPAA_RESTRICTED								"R"
#define SRS_MATCHING_RATING_LIMIT_MPAA_UNDER17RESTRICTED 				"NC-17"
#define SRS_MATCHING_RATING_LIMIT_MPAA_NOTRATEDYET 							"NR"

#define SRS_MATCHING_RATING_LIMIT_RIAA_NONEXPLICITCONTENT 			""
#define SRS_MATCHING_RATING_LIMIT_RIAA_EXPLICITCONTENT 					"PA-EC"

#define SRS_MATCHING_RATING_LIMIT_ESRB_EARLYCHILDHOOD 					"EC"
#define SRS_MATCHING_RATING_LIMIT_ESRB_EVERYONE 								"E"
#define SRS_MATCHING_RATING_LIMIT_ESRB_EVERYONE10PLUS 					"E10+"
#define SRS_MATCHING_RATING_LIMIT_ESRB_TEEN 										"T"
#define SRS_MATCHING_RATING_LIMIT_ESRB_MATURE 									"M"
#define SRS_MATCHING_RATING_LIMIT_ESRB_AUDLTSONLY 							"AO"
#define SRS_MATCHING_RATING_LIMIT_ESRB_RATINGPENDING 						"RP"

#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_ALLCHILDREN 									"TV-Y"
#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_OLDERCHILDREN 								"TV-Y7"
#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_OLDERCHILDREN_MINUS_VIOLENCE "TV-Y7FV"
#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_GENERALAUDIIENCE 						"TV-G"
#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_PARENTALGUIDANCE 						"TV-PG"
#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_PARENTSSTRONGLYCAUTIONED 		"TV-14"
#define SRS_MATCHING_RATING_LIMIT_TVGUIDELINES_MATUREAUDIENCEONLY 					"TV-MA"

#define SRS_MATCHING_EPISODE_TYPE_ALL 				"ALL"
#define SRS_MATCHING_EPISODE_TYPE_FIRSTRUN 		"FIRST-RUN"
#define SRS_MATCHING_EPISODE_TYPE_REPEAT 			"REPEAT"

#define SRS_DURATION_LIMIT_EFFECT_SKIP 	"SKIP"
#define SRS_DURATION_LIMIT_EFFECT_LAST 	"LAST"
#define SRS_DURATION_LIMIT_EFFECT_FIRST "FIRST"

#define SRS_SCHEDULE_STATE_OPERATIONAL 	"OPERATIONAL"
#define SRS_SCHEDULE_STATE_COMPLETED 		"COMPLETED"
#define SRS_SCHEUDLE_STATE_ERROR 				"ERROR"

#define SRS_TASK_STATE_IDLE_READY 												"IDLE.READY"
#define SRS_TASK_STATE_IDLE_ATRISK 												"IDLE.ATRISK"
#define SRS_TASK_STATE_ACTIVE_TRANSITION_FROM_START 			"ACTIVE.TRANSITION.FROM.START"
#define SRS_TASK_STATE_ACTIVE_TRANSITION_RESTART 					"ACTIVE.TRANSITION.RESTART"
#define SRS_TASK_STATE_ACTIVE_RECORDING_FROMSTART_OK 			"ACTIVE.RECORDING.FROMSTART.OK"
#define SRS_TASK_STATE_ACTIVE_RECORDING_FROMSTART_ATRISK 	"ACTIVE.RECORDING.FROMSTART.ATRISK"
#define SRS_TASK_STATE_ACTIVE_RECORDING_RESTART_OK 				"ACTIVE.RECORDING.RESTART.OK"
#define SRS_TASK_STATE_ACTIVE_RECORDING_RESTART_ATRISK 		"ACTIVE.RECORDING.RESTART.ATRISK"
#define SRS_TASK_STATE_ACTIVE_NOTRECORDING 								"ACTIVE.NOTRECORDING"
#define SRS_TASK_STATE_DONE_FULL 													"DONE.FULL"
#define SRS_TASK_STATE_DONE_PARTIAL 											"DONE.PARTIAL"
#define SRS_TASK_STATE_DONE_EMTPY 												"DONE.EMPTY"

#define SRS_TASK_STATE_PHASE_IDLE 				"IDLE"
#define SRS_TASK_STATE_PHASE_ACTIVE 			"ACTIVE"
#define SRS_TASK_STATE_PHASE_DONE 				"DONE"

#define SRS_CLASS_RECORDSCHEDULE_DIRECT_MANUAL 			"OBJECT.RECORDSCHEDULE.DIRECT.MANUAL"
#define SRS_CLASS_RECORDSCHEDULE_DIRECT_CDSEPG 			"OBJECT.RECORDSCHEDULE.DIRECT.CDSEPG"
#define SRS_CLASS_RECORDSCHEDULE_DIRECT_CDSNONEPG 	"OBJECT.RECORDSCHEDULE.DIRECT.CDSNONEPG"
#define SRS_CLASS_RECORDSCHEDULE_DIRECT_PROGRAMCODE "OBJECT.RECORDSCHEDULE.DIRECT.PROGRAMCODE"
#define SRS_CLASS_RECORDSCHEDULE_QUERY_CONTENTNAME 	"OBJECT.RECORDSCHEDULE.QUERY.CONTENTNAME"
#define SRS_CLASS_RECORDSCHEDULE_QUERY_CONTENTID 		"OBJECT.RECORDSCHEDULE.QUERY.CONTENTID"
#define SRS_CLASS_RECORDTASK												"OBJECT.RECORDTASK"

#define SRS_PRIORITY_LEVEL_1 "L1"
#define SRS_PRIORITY_LEVEL_2 "L2"
#define SRS_PRIORITY_LEVEL_3 "L3"
#define SRS_PRIORITY_LEVEL_DEFAULT "L3"

#define SRS_DESIRED_PRIORITY_LEVEL_DEFAULT	"DEFAULT"
#define SRS_DESIRED_PRIORITY_LEVEL_L1				"L1"
#define SRS_DESIRED_PRIORITY_LEVEL_L2				"L2"
#define SRS_DESIRED_PRIORITY_LEVEL_L3				"L3"
#define SRS_DESIRED_PRIORITY_LEVEL_HIGHEST	"HIGHEST"
#define SRS_DESIRED_PRIORITY_LEVEL_LOWEST		"LOWEST"
#define SRS_DESIRED_PRIORITY_LEVEL_L1_HI		"L1_HI"
#define SRS_DESIRED_PRIORITY_LEVEL_L1_LO		"L1_LO"
#define SRS_DESIRED_PRIORITY_LEVEL_L2_HI		"L2_HI"
#define SRS_DESIRED_PRIORITY_LEVEL_L2_LO		"L2_LO"
#define SRS_DESIRED_PRIORITY_LEVEL_L3_HI		"L3_HI"
#define SRS_DESIRED_PRIORITY_LEVEL_L3_LO		"L3_LO"

#define SRS_SCHEDULE_STATE_CURRENT_ERROR_GENERAL_ERROR 							(100)
#define SRS_SCHEUDLE_STATE_CURRENT_ERROR_RECORD_TASK_LIMIT_REACHED 	(101)
#define SRS_SCHEUDLE_STATE_CURRENT_ERROR_EPG_INFO_NOT_AVAILABLE 		(102)
#define SRS_SCHEUDLE_STATE_CURRENT_ERROR_RECORD_SCHEDULE_DISABLED 	(103)
#define SRS_SCHEUDLE_STATE_CURRENT_ERROR_INSUFFICIENT_MEMORY 				(104)
#define SRS_SCHEUDLE_STATE_CURRENT_ERROR_GENERAL_RESOURCE_ERROR 		(105)

#define SRS_TASK_STATE_ERROR_GENERAL_PROBLEM 												(100)
#define SRS_TASK_STATE_ERROR_RECORD_TASK_DISABLED 									(101)
#define SRS_TASK_STATE_ERROR_RECORD_TASK_OVERRIDING_ENABLE_DISABLE 	(102)

#define SRS_TASK_STATE_ERROR_GENERAL_MEDIA_PROBLEM									(200)
#define SRS_TASK_STATE_ERROR_NO_MEDIA																(201)
#define SRS_TASK_STATE_ERROR_MEDIA_WRITE_PROTECT										(202)
#define SRS_TASK_STATE_ERROR_INSUFFICIENT_MEDIA_SPACE								(203)
#define SRS_TASK_STATE_ERROR_MEDIA_LOW_SPACE												(204)

#define SRS_TASK_STATE_ERROR_GENERAL_SYSTEM_PROBLEM									(300)
#define SRS_TASK_STATE_ERROR_INSUFFICIENT_SYSTEM_MEMORY							(301)
#define SRS_TASK_STATE_ERROR_INSUFFICEINT_SYSTEM_PROCESSING					(302)
#define SRS_TASK_STATE_ERROR_LOW_SYSTEM_MEMORY											(303)
#define SRS_TASK_STATE_ERROR_LOW_SYSTEM_PROCESSING									(304)
#define SRS_TASK_STATE_ERROR_SIGNAL_LOST														(305)
#define SRS_TASK_STATE_ERROR_LOW_SIGNAL															(306)
#define SRS_TASK_STATE_ERROR_NO_EPG																	(307)

#define SRS_TASK_STATE_ERROR_GENERAL_CONTENT_PROBLEM								(400)
#define SRS_TASK_STATE_ERROR_CONFLICTING_PROGRAM_LOSER							(401)
#define SRS_TASK_STATE_ERROR_CONFLICTING_PROGRAM_WINNER							(402)
#define SRS_TASK_STATE_ERROR_CONTENT_PAY_PER_VIEW										(403)
#define SRS_TASK_STATE_ERROR_CONTENT_RESCHEDULED										(404)

#define SRS_PROPERTY_MAX_SIZE_ID 																		(256)
#define SRS_PROPERTY_MAX_SIZE_TITLE 																(128)
#define SRS_PROPERTY_MAX_SIZE_CLASS 																(64)
#define SRS_PROPERTY_MAX_SIZE_ADDITIONAL_INFO 											(1024)
#define SRS_PROPERTY_MAX_SIZE_CDSREFERENCE			 										(8192)
#define SRS_PROPERTY_MAX_SIZE_CDSREFERENCE_LINK 										(1024)
#define SRS_PROPERTY_MAX_SIZE_PRIORITY															(8)
#define SRS_PROPERTY_MAX_SIZE_DESIRED_PRIORITY											(1024)
#define SRS_PROPERTY_MAX_SIZE_DESIRED_PRIORITY_TYPE									(16)
#define SRS_PROPERTY_MAX_SIZE_RECORD_DESTINATION										(1024)
#define SRS_PROPERTY_MAX_SIZE_RECORD_DESTINATION_TYPE								(16)
#define SRS_PROPERTY_MAX_SIZE_DESIRED_RECORD_QUALITY								(1024)
#define SRS_PROPERTY_MAX_SIZE_DESIRED_RECORD_QUALITY_TYPE						(16)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_CDSOBJECTID									(1024)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_CDSOBJECTID_LINK						(256)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_CHANNELID										(256)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_CHANNELID_TYPE							(16)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_CHANNELID_DISTRINETWORKNAME	(32)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_CHANNELID_DISTRINETWORKID		(16)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_STARTDATETIME								(64)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_DURATION										(64)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_PROGRAMCODE									(64)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_PROGRAMCODE_TYPE						(16)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_STARTDATETIMEADJUST					(64)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULED_DURATIONADJUST							(16)
#define SRS_PROPERTY_MAX_SIZE_ACTIVEPERIOD													(64)
#define SRS_PROPERTY_MAX_SIZE_DURATIONLIMIT													(64)
#define SRS_PROPERTY_MAX_SIZE_PERSISTEDRECORDINGS_STOREDLIFETIME		(64)
#define SRS_PROPERTY_MAX_SIZE_SCHEDULESTATE													(64)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGNAME													(128)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGNAME_TYPE											(16)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGID														(256)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGID_TYPE												(16)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGCHANNELID											(256)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGCHANNELID_TYPE								(16)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGCHANNELID_DISTRINETWORKNAME		(32)
#define SRS_PROPERTY_MAX_SIZE_MATCHINGCHANNELID_DISTRINETWORKID			(16)
#define SRS_PROPERTY_MAX_SIZE_MATCHING_STARTDATETIMERANGE						(64)
#define SRS_PROPERTY_MAX_SIZE_MATCHING_DURATIONRANGE								(16)
#define SRS_PROPERTY_MAX_SIZE_MATCHING_RATINGLIMIT									(16)
#define SRS_PROPERTY_MAX_SIZE_MATCHING_RATINGLIMIT_TYPE							(32)
#define SRS_PROPERTY_MAX_SIZE_MATCHING_EPISODETYPE									(9)
#define SRS_PROPERTY_MAX_SIZE_RECORDSCHEDULEID											(256)
#define SRS_PROPERTY_MAX_SIZE_RECORDEDCDSOBJECTID										(8192)
#define SRS_PROPERTY_MAX_SIZE_RECORDEDCDSOBJECTID_LINK							(1024)
#define SRS_PROPERTY_MAX_SIZE_TASKCDSOBJECTID												(8192)
#define SRS_PROPERTY_MAX_SIZE_TASKCDSOBJECTID_LINK									(1024)
#define SRS_PROPERTY_MAX_SIZE_TASKCHANNELID													(256)
#define SRS_PROPERTY_MAX_SIZE_TASKCHANNELID_TYPE										(16)
#define SRS_PROPERTY_MAX_SIZE_TASKCHANNELID_DISTRINETWORKNAME				(32)
#define SRS_PROPERTY_MAX_SIZE_TASKCHANNELID_DISTRINETWORKID					(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_STARTDATETIME										(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_DURATION													(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_PROGRAMCODE											(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_PROGRAMCODE_TYPE									(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_RECORDQUALITY										(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_RECORDQUALITY_TYPE								(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDNAME											(128)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDNAME_TYPE									(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDID												(256)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDID_TYPE										(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDRATING										(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDRATING_TYPE								(32)
#define SRS_PROPERTY_MAX_SIZE_TASK_MATCHEDEPISODE_TYPE							(8)
#define SRS_PROPERTY_MAX_SIZE_TASK_STARTDATETIME_ADJUST							(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_DURATION_ADJUST									(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_DURATION_LIMIT										(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_DURATION_LIMIT_EFFECT						(8)
#define SRS_PROPERTY_MAX_SIZE_TASK_STATE														(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_STATE_PHASE											(16)
#define SRS_PROPERTY_MAX_SIZE_TASK_STATE_CURRENT_ERRORS									(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_STATE_ERROR_HISTORY									(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_STATE_PENDING_ERRORS									(64)
#define SRS_PROPERTY_MAX_SIZE_TASK_STATE_INFOLIST										(64)


#define SRS_PROPERTY_MATCHING_RATINGLIMIT_MAXCOUNT_TOTAL						"3"
#define SRS_PROPERTY_SCHEDULED_STARTDATETIME_MAXCOUNT_TOTAL					"2"
#define SRS_PROPERTY_CDSREFERENCE_MAXCOUNT_TOTAL										"2"
#define SRS_PROPERTY_RECORDQUALITY_MAXCOUNT_TOTAL										"3"
#define SRS_PROPERTY_RECORDQUALITY_MINCOUNT_TOTAL										(3)
#define SRS_PROPERTY_RECORDQUALITY_TYPE_MINCOUNT										(3)
#define SRS_PROPERTY_RECORDQUALITY_TYPE_MAXCOUNT										"3"
#define SRS_PROPERTY_MATCHEDRATING_MAXCOUNT_TOTAL										"2"


#define SRS_PROPERTY_PRIORITYORDEREDVALUE_MINCOUNT												(1)
#define SRS_PROPERTY_PRIORITYORDEREDVALUE_ALLOWEDVALUE_RANGE_MIN					"1"
#define SRS_PROPERTY_PRIORITYORDEREDVALUE_ALLOWEDVALUE_RANGE_MAX					"64"
#define SRS_PROPERTY_PRIORITYORDEREDVALUE_ALLOWEDVALUE_RANGE_STEP					"1"

/*The Maximum count of Record Destinations allowed*/
#define SRS_PROPERTY_RECORDDESTINATION_MAXCOUNT_TOTAL															"3"
#define SRS_PROPERTY_RECORDDESTINATION_TYPE_MINLISTSIZE_TOTAL											(1)
#define SRS_PROPERTY_RECORDDESTINATION_TYPE_MAXLISTSIZE_TOTAL											"4"
#define SRS_PROPERTY_RECORDDESTINATION_TYPE_DVDDRIVE_MAX_LISTSIZE									"4"
#define SRS_PROPERTY_RECORDDESTINATION_TYPE_REMOTE_MEDIA_JUKEBOX_MAX_LISTSIZE	    "2"
#define SRS_PROPERTY_RECORDDESTINATION_PREFERENCE_ALLOWEDVALUE_RANGE_MIN  				"1"
#define SRS_PROPERTY_RECORDDESTINATION_PREFERENCE_ALLOWEDVALUE_RANGE_MAX  				"3"
#define SRS_PROPERTY_RECORDDESTINATION_PREFERENCE_ALLOWEDVALUE_RANGE_STEP 				"1"

/*Record Destinations depends on the recorder??*/
#define SRS_RECORD_DESTINATION_HARDDISK_1 						"Hard Disk 1"
#define SRS_RECORD_DESTINATION_HARDDISK_2 						"Hard Disk 2"
#define SRS_RECORD_DESTINATION_DVDDRIVE 							"DVD Drive"
#define SRS_RECORD_DESTINATION_REMOTE_MEDIA_JUKEBOX 	"Remote Media Jukebox"

#define SRS_RECORD_DESTINATION_TYPE_HDD 																"HDD"
#define SRS_RECORD_DESTINATION_TYPE_DVD_PLUS_RW 												"DVD+RW"
#define SRS_RECORD_DESTINATION_TYPE_DVD_MINUS_RW 												"DVD-RW"
#define SRS_RECORD_DESTINATION_TYPE_DVD_MINUS_R 												"DVD-R"
#define SRS_RECORD_DESTINATION_TYPE_DVD_PLUS_R 													"DVD+R"
#define SRS_RECORD_DESTINATION_TYPE_CD_MINUS_R 													"CD-R"
#define SRS_RECORD_DESTINATION_TYPE_CD_MINUS_RW 												"CD-RW"

#define SRS_PROPERTY_DESIREDRECORDQUALITY_MAX_LISTSIZE_TOTAL									"UNBOUNDED"
#define SRS_PROPERTY_DESIREDRECORDQUALITY_TYPE_DEFAULT_MAX_LISTSIZE           "4"
#define SRS_PROPERTY_DESIREDRECORDQUALITY_TYPE_ATSC_MAX_LISTSIZE           		"11"
#define SRS_PROPERTY_DESIREDRECORDQUALITY_TYPE_QLEVEL_MAX_LISTSIZE          	"4"

#define SRS_PROPERTY_SCHEDULEDSTATE_CURRENTERRORS_MAX_LISTSIZE_TOTAL							"UNBOUNDED"
#define SRS_PROPERTY_SCHEDULEDSTATE_CURRENTERRORS_ALLOWEDVALUE_RANGE_MIN					"100"
#define SRS_PROPERTY_SCHEDULEDSTATE_CURRENTERRORS_ALLOWEDVALUE_RANGE_MAX					"105"
#define SRS_PROPERTY_SCHEDULEDSTATE_CURRENTERRORS_ALLOWEDVALUE_RANGE_STEP					"1"

typedef enum srs_dataType 
{
	SRS_DATA_TYPE_XSD_UNSIGNEDINTEGER,
  SRS_DATA_TYPE_XSD_STRING,
	SRS_DATA_TYPE_XSD_BOOLEAN,
  SRS_DATA_TYPE_XSD_CSV_INTEGER,
	SRS_DATA_TYPE_XSD_CSV_STRING,
  SRS_DATA_TYPE_XSD_CSV_BOOLEAN,
	SRS_DATA_TYPE_XSD_ANYURI
} srs_dataType_e;

typedef enum srs_dataTypeID
{
	SRS_DATA_TYPE_ID_RECORDSCHEDULEPARTS,
  SRS_DATA_TYPE_ID_RECORDSCHEDULE,
  SRS_DATA_TYPE_ID_RECORDTASK
} srs_dataTypeID_e;

struct srs_cdsReference
{
	struct srs_cdsReference *prev;
	struct srs_cdsReference *next;
	slim_char* cdsReference;
	slim_char* cdsReferencelink;
};
typedef struct srs_cdsReference srs_cdsReference_t;

typedef struct srs_base
{
	slim_char* id;
	slim_char* title;
	slim_char* srs_class;
	slim_char* additionalStatusInfo;
	List(srs_cdsReference_t*) cdsRef;
} srs_base_t;

typedef struct srs_priority
{
	slim_char* priority;
	slim_word  priorityOrderedValue;
	slim_char* desiredPriority;
	slim_char* desiredPriorityType;
} srs_priority_t;

struct srs_recordDestination
{
	struct srs_recordDestination *prev;
	struct srs_recordDestination *next;
	slim_char* destinationName;
	slim_char* mediaType;
	slim_char* targetUrl;
	slim_word  preference;
};
typedef struct srs_recordDestination srs_recordDestination_t;

typedef struct srs_outputControl
{
	List(srs_recordDestination_t*) recordDestination;
	slim_char* srs_desiredRecordQuality;
	slim_char* srs_desiredRecordQualityType;
} srs_outputControl_t;
		
typedef struct srs_scheduledChannelID
{
	slim_char* id;
	slim_char* type;
	slim_char* distriNetworkName;
	slim_char* distriNetworkID;
} srs_scheduledChannelID_t;

typedef struct srs_scheduledStrartDateTime
{
	struct srs_scheduledStrartDateTime *prev;
	struct srs_scheduledStrartDateTime *next;
	slim_char* startDateTime;
} srs_scheduledStartDateTime_t;
//typedef struct srs_scheduledStrartDateTime srs_scheduledStrartDateTime_t;

typedef struct srs_contentIdentification
{
	slim_char* srs_scheduledCDSObjectID;
	slim_char* srs_scheduledCDSObjectIDLink;
	srs_scheduledChannelID_t scheduledChannelID;
	List(srs_scheduledStartDateTime_t*) scheduledStartDateTime;
	slim_char* scheduledDuration;
	slim_char* scheduledProgramCode;
	slim_char* scheduledProgramCodetype;
} srs_contentIdentification_t;

typedef struct srs_matchingName
{
	slim_char* name;
	slim_char* type;
	slim_char* subStringMatch;
} srs_matchingName_t;

typedef struct srs_matchingID
{
	slim_char* id;
	slim_char* type;
} srs_matchingID_t;

struct srs_matchingChannelID
{
	struct srs_matchingChannelID *prev;
	struct srs_matchingChannelID *next;
	slim_char* id;
	slim_char* type;
	slim_char* distriNetworkName;
	slim_char* distriNetworkID;	
};
typedef struct srs_matchingChannelID srs_matchingChannelID_t;

struct srs_matchingStrartDateTimeRange
{
	struct srs_matchingStrartDateTimeRange *prev;
	struct srs_matchingStrartDateTimeRange *next;
	slim_char* startDateTimeRange;
};
typedef struct srs_matchingStrartDateTimeRange srs_matchingStrartDateTimeRange_t;

struct srs_matchingDurationRange
{
	struct srs_matchingDurationRange *prev;
	struct srs_matchingDurationRange *next;
	slim_char* durationRange;
};
typedef struct srs_matchingDurationRange srs_matchingDurationRange_t;

struct srs_matchingRatingLimit
{
	struct srs_matchingRatingLimit *prev;
	struct srs_matchingRatingLimit *next;
	slim_char* ratingLimit;
	slim_char* type;
};
typedef struct srs_matchingRatingLimit srs_matchingRatingLimit_t;

typedef struct srs_matchingQualifyingCriteria
{
	List(srs_matchingChannelID_t*) matchingChannelID;
	List(srs_matchingStrartDateTimeRange_t*) matchingStartDateTimeRange;
	List(srs_matchingDurationRange_t*) matchingDurationRange;
	List(srs_matchingRatingLimit_t*) matchingRatingLimit;
	slim_char* srs_matchingEpisodeType;
} srs_matchingQualifyingCriteria_t;

typedef struct srs_contentControl
{
	slim_word srs_totalDesiredRecordTasks;
	slim_char* srs_scheduledStartDateTimeAdjust;
	slim_char* srs_scheduledDurationAdjust;
	slim_char* srs_activePeriod;
	slim_char* srs_durationLimit;
	slim_char* srs_durationLimiteffect;
	slim_bool srs_channelMigration;
	slim_bool srs_timeMigration;
	slim_bool srs_allowDuplicates;
} srs_contentControl_t;

typedef struct srs_persistedRecordings
{
	slim_word recordingsCount;
	slim_bool latest;
	slim_bool preAllocation;
	slim_char* storedLifetime;
} srs_persistedRecordings_t;

typedef struct srs_scheduleState
{
	slim_char* srs_scheduleState;
	slim_int srs_scheduleStatecurrentErrors;
	slim_bool srs_abnormalTaskEsists;
} srs_scheduleState_t;

typedef struct srs_statistics
{
	slim_word srs_currentRecordTaskCount;
	slim_word srs_totalCreatedRecordTasks;
	slim_word srs_totalCompletedRecordTasks;
} srs_statistics_t;

typedef struct srs_taskGeneral
{
	slim_char* srs_recordScheudleID;
	slim_char* srs_recordedCDSObjectID;
	slim_char* srs_recordedCDSObjectIDlink;
} srs_taskGeneral_t;

typedef struct srs_taskChannelID
{
	slim_char* id;
	slim_char* type;
	slim_char* distiNetworkName;
	slim_char* distriNetworkID;
} srs_taskChannelID_t;

struct srs_recordQuality
{
	struct srs_recordQuality *prev;
	struct srs_recordQuality *next;
	slim_char* recordQuality;
	slim_char* type;
};
typedef struct srs_recordQuality srs_recordQuality_t;

typedef struct srs_taskContentIdentification
{
	slim_char* srs_taskCDSObjectID;
	slim_char* srs_taskCDSObjectIDlink;
	srs_taskChannelID_t taskChannelID;
	slim_char* srs_taskStartDateTime;
	slim_char* srs_taskDuration;
	slim_char* srs_taskProgramCode;
	slim_char* srs_taskProgramCodetype;
	List(srs_recordQuality_t*) taskRecordQuality;
} srs_taskContentIdentification_t;

typedef struct srs_taskMatchedContentCriteria
{
	slim_char* srs_matchedName;
	slim_char* srs_matchedNametype;
	slim_char* srs_matchedID;
	slim_char* srs_matchedIDtype;
} srs_taskMatchedContentCriteria_t;
		
struct srs_matchedRating
{
	struct srs_matchedRating *prev;
	struct srs_matchedRating *next;
	slim_char* rating;
	slim_char* type;
};
typedef struct srs_matchedRating srs_matchedRating_t;

typedef struct srs_taskMatchedQualifyingCriteria
{
	List(srs_matchedRating_t*) matchedRating;
	slim_char* srs_matchedEpisodeType;
} srs_srs_taskMatchedQualifyingCriteria;		
		
typedef struct srs_taskMatchedContentControl
{
	slim_char* srs_taskStartDateTimeAdjust;
	slim_char* srs_taskDurationAdjust;
	slim_char* srs_taskDurationLimit;
	slim_char* srs_taskDurationLimiteffect;
	slim_bool srs_taskChannelMigration;
	slim_bool srs_taskTimeMigration;
} srs_taskMatchedContentControl_t;
		
typedef struct srs_taskState
{
	slim_char* state;
	slim_char* phase;
	slim_bool startDateTimeMet;
	slim_bool endDateTimeMet;
	slim_bool recording;
	slim_bool someBitsRecorded;
	slim_bool someBitsMissing;
	slim_bool firstBitsRecorded;
	slim_bool lastBitsRecorded;
	slim_bool fatalError;
	slim_char* currentErrors; /*TODO:CSV list*/
	slim_char* errorHistory;  /*TODO:CSV list*/
	slim_char* pendingErrors; /*TODO:CSV list*/
	slim_char* infoList;      /*TODO:CSV list*/	
} srs_taskState_t;

typedef struct srs_recordScheduleParts
{
	slim_char* id;
	slim_char* srs_title;
	slim_char* srs_class;
	slim_word flags;
#define RECORDSCHEDULE_FLAG_DIRECT_MANUAL  			(1 << 0)
#define RECORDSCHEDULE_FLAG_DIRECT_CDSEPG  			(1 << 1)
#define RECORDSCHEDULE_FLAG_DIRECT_CDSNONEPG  	(1 << 2)
#define RECORDSCHEDULE_FLAG_DIRECT_PROGRAMCODE  (1 << 3)
#define RECORDSCHEDULE_FLAG_QUERY_CONTENTNAME   (1 << 4)
#define RECORDSCHEDULE_FLAG_QUERY_CONTENTID     (1 << 5)
	slim_char* srs_desiredPriority;
	slim_char* srs_desiredPriorityType;
	
	srs_outputControl_t outputControl;
	
	slim_char* srs_scheduledCDSObjectID;
	srs_scheduledChannelID_t scheduledChannelID;
	List(srs_scheduledStartDateTime_t*) scheduledStartDateTime;
	slim_char* scheduledDuration;
	slim_char* scheduledProgramCode;
	slim_char* scheduledProgramCodetype;
	
	srs_matchingName_t matchingName;
	srs_matchingID_t matchingID;
	List(srs_matchingChannelID_t*) matchingChannelID;
	List(srs_matchingStrartDateTimeRange_t*) matchingStartDateTimeRange;
	List(srs_matchingDurationRange_t*) matchingDurationRange;
	List(srs_matchingRatingLimit_t*) matchingRatingLimit;
	slim_char* srs_matchingEpisodeType;
	srs_contentControl_t contentControl;
	srs_persistedRecordings_t storage;
} srs_rescordScheduleParts_t;

typedef struct srs_recordSchedule
{
	srs_base_t base;
	srs_priority_t priority;
	srs_outputControl_t outputControl;
	
	slim_char* srs_scheduledCDSObjectID;
	slim_char* srs_scheduledCDSObjectIDlink;
	srs_scheduledChannelID_t scheduledChannelID;
	List(srs_scheduledStartDateTime_t*) scheduledStartDateTime;
	slim_char* scheduledDuration;
	slim_char* scheduledProgramCode;
	slim_char* scheduledProgramCodetype;
	
	srs_matchingName_t matchingName;
	srs_matchingID_t matchingID;
	List(srs_matchingChannelID_t*) matchingChannelID;
	List(srs_matchingStrartDateTimeRange_t*) matchingStartDateTimeRange;
	List(srs_matchingDurationRange_t*) matchingDurationRange;
	List(srs_matchingRatingLimit_t*) matchingRatingLimit;
	slim_char* srs_matchingEpisodeType;
	
	srs_contentControl_t contentControl;
	srs_persistedRecordings_t storage;
	srs_scheduleState_t scheduleState;
	
	slim_word srs_currentRecordTaskCount;
	slim_word srs_totalCreatedRecordTasks;
	slim_word srs_totalCompletedRecordTasks;
} srs_recordSchedule_t;

typedef struct srs_recordTask
{
	struct srs_recordTask *prev;
	struct srs_recordTask *next;
	srs_base_t base;
	srs_priority_t priority;
	srs_outputControl_t outputControl;
	srs_taskGeneral_t taskGeneral;
	srs_taskContentIdentification_t taskContentIdentification;
	srs_taskMatchedContentCriteria_t taskMatchedContentCriteria;
	srs_srs_taskMatchedQualifyingCriteria taskMatchedQualifyingCriteria;
	srs_taskMatchedContentControl_t taskMatchedContentControl;
	srs_taskState_t taskState;
} srs_recordTask_t;

typedef struct srs_obj_manager
{
	slim_word stUpdateID;
	slim_char* srs_data_dir;
#ifdef SRS_SUPPORT_ORDERED_PRIORITY
	slim_word orderedPriority;
#endif /*SRS_SUPPORT_ORDERED_PRIORITY*/
	srs_db_params_t	db_params;
	List(srs_recordTask_t*) tasks;
} srs_obj_manager_t;

typedef struct srs_digital_channel
{
	slim_char* major_channel;
	slim_char* minor_channel;
} srs_digital_channel_t;

typedef struct srs_si_channel
{
	slim_char* networkID;
	slim_char* transportstreamID;
	slim_char* serviceID;
} srs_si_channel_t;

srs_obj_manager_t*
srs_obj_manager_alloc(slim_char* srs_dir);

void
srs_obj_manager_free(srs_obj_manager_t* obj_manager);

slim_bool
srs_obj_manager_check_valid_class(slim_char* in_class, slim_int in_dataTypeID);

slim_bool
srs_obj_manager_check_valid_priority_type(slim_char* in_priority_type);

void
srs_obj_manager_recordScheduleParts_free(srs_rescordScheduleParts_t* recordScheduleParts);

srs_recordSchedule_t*
srs_obj_manager_add_recordSchedule(srs_obj_manager_t* obj_manager, 
																			 srs_rescordScheduleParts_t *recordScheduleParts);

#endif /*SRS_OBJ_MANAGER_H*/
