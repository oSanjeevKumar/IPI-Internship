/*  nflc_db.h
 * 
 * Copyright (C) 2010 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */
 
#ifndef _SRS_DB_H
#define _SRS_DB_H

typedef void * srs_dbhandle;

typedef struct srs_db_recordschedule_table
{
	slim_char* tablename_record_schedule;
	slim_char* tablename_record_destination;
	slim_char* tablename_scheduled_startdatetime;
	slim_char* tablename_matching_channelID;
	slim_char* tablename_matching_startdatetimerange;
	slim_char* tablename_matching_durationrange;
	slim_char* tablename_matching_ratinglimit;
} srs_db_recordschedule_table_t;

typedef struct srs_db_params
{
	slim_char* filepath;
	srs_dbhandle handle;
	srs_db_recordschedule_table_t record_schedule_table;
	slim_char* record_task_table;
}srs_db_params_t;



#define SRS_DB_FILENAME "srs.db"
#define SRS_DB_RECORDSCHEDULE_TABLE "recordschedule_table"
#define SRS_DB_RECORDDESTINATION_TABLE "recorddestination_table"
#define SRS_DB_SCHEDULED_STARTDATETIME_TABLE "scheduledstartdatetime_table"
#define SRS_DB_MATCHING_CHANNELID_TABLE "matchingchannelID_table"
#define SRS_DB_MATCHING_STARTDATETIMERANGE_TABLE "matchingstartdatetimerange_table"
#define SRS_DB_MATCHING_DURATIONRANGE_TABLE "matchingdurationrange_table"
#define SRS_DB_MATCHING_RATINGLIMIT_TABLE "matchingratinglimit_table"

#define SRS_DB_RECORDSTASK_TABLE "record_task"

#define SRS_DB_RECORDSCHEDULE_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS " \
	"SRS_DB_RECORDSCHEDULE_TABLE "\
	"("\
	"rs_ID INTEGER PRIMARY KEY, title TEXT, class TEXT, additionalStatusInfo TEXT" \
	", priority TEXT, priorityOrderedValue INTEGER, desiredPriority TEXT" \
	", desiredPriorityType TEXT, recordDestination TEXT, desiredRecordQuality TEXT" \
	", desiredRecordQuality_type TEXT, scheduledCDSObjectID TEXT, scheduleCDSObjectID_link TEXT" \
	", scheduledChannelID TEXT, scheduledChannelID_type TEXT, scheduledChannelID_distriNetworkName TEXT" \
	", scheduledChannelID_distriNetworkID TEXT, scheduledDuration TEXT, scheduledProgramCode TEXT" \
	", scheduledProgramCode_type TEXT, matchingName TEXT, matchingName_type TEXT" \
	", matchingName_subStringMatch INTEGER, matchingID TEXT, matchingIDType TEXT" \
	", matchingEpisodeType TEXT, totalDesiredRecordTasks INTEGER, scheduledStartDateTimeAdjust TEXT" \
  ", scheduledDurationAdjust TEXT, activePeriod TEXT, durationLimit TEXT" \
	", durationLimit_effect TEXT, channelMigration INTEGER, timeMigration INTEGER" \
	", allowDuplicates INTEGER, persistedRecordings INTEGER, persistedRecordings_latest INTEGER"\
  ", persistedRecordings_preAllocation INTEGER, persistedRecordings_storedLifetime TEXT"\
	", scheduleState TEXT, scheduleState_currentErrors TEXT, abnormalTasksExist INTEGER" \
 	", currentRecordTaskCount INTEGER, totalCreatedRecordTasks INTEGER" \
	", totalCompletedRecordTasks INTEGER" \
	")"

#define SRS_DB_RECORDDESTINATION_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS "\
	"SRS_DB_RECORDDESTINATION_TABLE " \
	"(" \
	"id INTEGER PRIMARY KEY, recordDestination TEXT, type TEXT" \
	", targetURL TEXT, preference INTEGER, rs_ID INTEGER" \
	")"

#define SRS_DB_SCHEDULED_STARTDATETIME_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS "\
	"SRS_DB_SCHEDULED_STARTDATETIME_TABLE " \
	"(" \
	"id INTEGER PRIMARY KEY, scheduledStartDateTime TEXT, rs_ID INTEGER" \
	")"
	
#define SRS_DB_MATCHING_CHANNELID_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS "\
	"SRS_DB_MATCHING_CHANNELID_TABLE " \
	"(" \
	"id INTEGER PRIMARY KEY, matchingChannelID TEXT, type TEXT" \
	",cdistriNetworkName TEXT, distriNetworkID TEXT, rs_ID INTEGER" \
	")"

#define SRS_DB_MATCHING_STARTDATETIMERANGE_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS "\
	"SRS_DB_MATCHING_STARTDATETIMERANGE_TABLE " \
	"(" \
	"id INTEGER PRIMARY KEY, matchingStartDateTimeRange TEXT, rs_ID INTEGER" \
	")"

#define SRS_DB_MATCHING_DURATIONRANGE_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS "\
	"SRS_DB_MATCHING_DURATIONRANGE_TABLE " \
	"(" \
	"id INTEGER PRIMARY KEY, matchingDurationRange TEXT, rs_ID INTEGER" \
	")"

#define SRS_DB_MATCHING_RATINGLIMIT_TABLE_QUERY \
	"CREATE TABLE IF NOT EXISTS "\
	"SRS_DB_MATCHING_RATINGLIMIT_TABLE " \
	"(" \
	"id INTEGER PRIMARY KEY, matchingRatingLimit TEXT, type TEXT, rs_ID INTEGER" \
	")"

slim_int
srs_db_initialize(srs_db_params_t* db_params, slim_char* srs_data_dir);

void
srs_db_free(srs_db_params_t* db_params);
			
#endif /*_SRS_DB_H*/
