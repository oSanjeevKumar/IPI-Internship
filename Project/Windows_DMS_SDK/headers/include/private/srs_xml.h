/*
 * srs_xml.h
 * Copyright (C) 2007-2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

#ifndef NFLC_SRS_XML_H
#define NFLC_SRS_XML_H

/*SRS COMMON PROPERTIES*/
#define SRS_XML_FLAG_SRS_COMMON     						                        		(1 << 0)
#define SRS_XML_FLAG_SRS_COMMON_ID             															(1 << 1)
#define SRS_XML_FLAG_SRS_COMMON_TITLE              													(1 << 2)
#define SRS_XML_FLAG_SRS_COMMON_CLASS              													(1 << 3)
#define SRS_XML_FLAG_SRS_COMMON_ADDITIONALSTATUSINFO           							(1 << 4)
#define SRS_XML_FLAG_SRS_COMMON_CDS_REFERENCE              									(1 << 5)
#define SRS_XML_FLAG_SRS_COMMON_CDS_REFERENCE_LINK             							(1 << 6)
#define SRS_XML_FLAG_SRS_COMMON_PRIORITY                 										(1 << 7)
#define SRS_XML_FLAG_SRS_COMMON_PRIORITY_ORDEREDVALUE             					(1 << 8)
#define SRS_XML_FLAG_SRS_COMMON_DESIREDPRIORITY              								(1 << 9)
#define SRS_XML_FLAG_SRS_COMMON_DESIREDPRIORITY_TYPE                 				(1 << 10)
#define SRS_XML_FLAG_SRS_COMMON_RECORDDESTINATION              							(1 << 11)
#define SRS_XML_FLAG_SRS_COMMON_RECORDDESTINATION_MEDIATYPE             		(1 << 12)
#define SRS_XML_FLAG_SRS_COMMON_RECORDDESTINATION_TARGETURL             		(1 << 13)
#define SRS_XML_FLAG_SRS_COMMON_RECORDDESTINATION_PREFERENCE            		(1 << 14)
#define SRS_XML_FLAG_SRS_COMMON_DESIRED_RECORDQUALITY                 			(1 << 15)
#define SRS_XML_FLAG_SRS_COMMON_DESIRED_RECORDQUALITY_TYPE              		(1 << 16)

/*SRS SCCHEDULE ONLY PROPERTIES*/
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY                          						(1 << 0)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULEDCHANNELID                		(1 << 1)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULEDCHANNELID_TYPE              (1 << 2)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULEDCHANNELID_DISTRINETWORK_NAME (1 << 3)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULEDCHANNELID_DISTRINETWORK_ID  (1 << 4)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_CDSOBJECTID               	(1 << 5)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_CDSOBJECTID_LINK           (1 << 6)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_START_DATETIME             (1 << 7)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_DURATION               		(1 << 8)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_PROGRAMCODE              	(1 << 9)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_PROGRAMCODE_TYPE           (1 << 10)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_TOTAL_DESIRED_RECORDTASKS     				(1 << 11)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_STARTDATETIME_ADJUST				(1 << 12)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULED_DURATION_ADJUST      			(1 << 13)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_ACTIVEPERIOD             						(1 << 14)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_DURATIONLIMIT             						(1 << 15)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_DURATIONLIMIT_EFFECT            			(1 << 16)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_CHANNEL_MIGRATION             				(1 << 17)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_TIME_MIGRATION             					(1 << 18)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_ALLOW_DUPLICATES             				(1 << 19)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_PERSISTEDRECORDINGS									(1 << 20)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_PERSISTEDRECORDINGS_LATEST           (1 << 21)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_PERSISTEDRECORDINGS_PREALLOCATION    (1 << 22)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_PERSISTEDRECORDINGS_STORED_LIFETIME  (1 << 23)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULESTATE			             			(1 << 24)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_SCHEDULESTATE_CURRENTERRORS          (1 << 25)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_ABNORMAL_TASKS_EXISTS  								(1 << 26)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_CURRENT_RECORDTASK_COUNT 						(1 << 27)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_TOTAL_CREATED_RECORDTASKS 						(1 << 28)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_TOTAL_COMPLETED_RECORDTASKS 					(1 << 29)

/*SRS SCHEDULE ONLY MATCHING PROPERTIES*/
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING                          		(1 << 0)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_NAME               					(1 << 1)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_NAME_TYPE               		(1 << 2)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_NAME_SUBSTRING_MATCH        (1 << 3)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_MATCHINGID              		(1 << 4)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_MATCHINGID_TYPE             (1 << 5)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_MATCHINGCHANNELID			      (1 << 6)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_MATCHINGCHANNELID_TYPE      (1 << 7) 
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_MATCHINGCHANNELID_DISTRINETWORK_NAME (1 << 8)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_MATCHINGCHANNELID_DISTRINETWORK_ID (1 << 9)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_START_DATETIME_RANGE (1 << 10)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_DURATION_RANGE      (1 << 11)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_RATINGLIMIT         (1 << 12)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_RATINGLIMIT_TYPE    (1 << 13)
#define SRS_XML_FLAG_SRS_SCHEDULE_ONLY_MATCHING_EPISODE_TYPE        (1 << 14)

/*SRS TASK ONLY PROPERTIES*/
#define SRS_XML_FLAG_SRS_TASK_ONLY                                           	(1 << 0)
#define SRS_XML_FLAG_SRS_TASK_ONLY_RECORDSCHEDULE_ID													(1 << 1)
#define SRS_XML_FLAG_SRS_TASK_ONLY_RECORDED_CDSOBJECTID            						(1 << 2)
#define SRS_XML_FLAG_SRS_TASK_ONLY_RECORDED_CDSOBJECTID_LINK          				(1 << 3)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASKCHANNELID            									(1 << 4)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASKCHANNELID_TYPE            							(1 << 5)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASKCHANNELID_DISTRINETWORK_NAME           (1 << 6)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASKCHANNELID_DISTRINETWORK_ID            	(1 << 7)
#define SRS_XML_FLAG_SRS_TASK_ONLY_RECORDQUALITY            									(1 << 8)
#define SRS_XML_FLAG_SRS_TASK_ONLY_RECORDQUALITY_TYPE            							(1 << 9)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_CDSOBJECTID           								(1 << 10)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_CDSOBJECTID_LINK           						(1 << 11)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_STARTDATETIME           							(1 << 12)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_DURATION           										(1 << 13)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_PROGRAMCODE           								(1 << 14)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_PROGRAMCODE_TYPE           						(1 << 15)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_NAME           								(1 << 16)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_NAME_TYPE           					(1 << 17)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_ID           									(1 << 18)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_ID_TYPE           						(1 << 19)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_RATING          							(1 << 20)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_RATING_TYPE          					(1 << 21)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_MATCHED_EPISODE_TYPE          				(1 << 22)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_STARTDATETIME_ADJUST          				(1 << 23)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_DURATION_ADJUST          							(1 << 24)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_DURATION_LIMIT          							(1 << 25)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_DURATION_LIMIT_EFFECT         				(1 << 26)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_CHANNEL_MIGRATION          						(1 << 27)
#define SRS_XML_FLAG_SRS_TASK_ONLY_TASK_TIME_MIGRATION          							(1 << 28)

/*SRS TASK ONLY STATE PROPERTIES*/
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE                                      (1 << 0)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_PHASE          											(1 << 1)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_STARTDATETIME_MET         						(1 << 2)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_ENDDATETIME_MET          						(1 << 3)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_RECORDING          									(1 << 4)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_SOMEBITS_RECORDED          					(1 << 5)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_SOMEBITS_MISSING          						(1 << 6)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_FIRSTBITS_RECORDED         					(1 << 7)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_LASTBITS_RECORDED         						(1 << 8)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_FATALERROR         									(1 << 9)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_CURRENTERRORS         								(1 << 10)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_ERRORHISTORY         								(1 << 11)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_PENDINGERRORS         								(1 << 12)
#define SRS_XML_FLAG_SRS_TASK_ONLY_STATE_INFOLIST        											(1 << 13)

typedef struct srs_recordSchedule_xml_flags_
{
	slim_word common_flags;
	slim_word scheduleOnly_flags;
	slim_word scheduleOnly_matching_flags;
} srs_recordSchedule_xml_flags;

typedef struct srs_recordTask_xml_flags_
{
	slim_word common_flags;
	slim_word taskOnly_flags;
	slim_word taskOnly_state_flags;
} srs_recordTask_xml_flags;

void
srs_xml_srs_header (struct sbuf *sbuf);

void
srs_xml_srs_footer (struct sbuf *in_sbuf);

void 
srs_xml_avdt_header (struct sbuf *in_sbuf);

void
srs_xml_avdt_footer (struct sbuf *in_sbuf);

void
srs_xml_filter_check_for_common_flags(slim_char *filter, slim_char* dataTypeID, 
																			slim_word *common_flags);
																			
void
srs_xml_filter_check_for_scheduleOnly_flags(slim_char *filter, slim_char* dataTypeID, 
										slim_word *scheduleOnly_flags);

void
srs_xml_filter_check_for_scheduleOnly_matching_flags(slim_char *filter, 
		slim_word *scheduleOnly_matching_flags);

void
srs_xml_filter_check_for_taskOnly_flags(slim_char *filter, slim_word *taskOnly_flags);

void
srs_xml_filter_check_for_taskOnly_state_flags(slim_char *filter, slim_word *taskOnly_state_flags);

void
srs_xml_avdt_body_for_recordScheduleParts(struct sbuf *sbuf, slim_char* device_udn,
																					srs_recordSchedule_xml_flags *flags);

void
srs_xml_avdt_body_for_recordSchedule(struct sbuf *sbuf, slim_char* device_udn,
																				 srs_recordSchedule_xml_flags *flags);
																				 
void
srs_xml_avdt_body_for_recordTask(struct sbuf *sbuf, slim_char* device_udn,
										  srs_recordTask_xml_flags *flags);

#endif /* NFLC_SRS_XML_H */
