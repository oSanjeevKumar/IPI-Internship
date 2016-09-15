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

#ifndef NFLC_UPNP_SRS_H
#define NFLC_UPNP_SRS_H

#include <srs_obj_manager.h>


#define SRS_PROPERTY_LIST_RECORDSCHEDULEPARTS                                                      \
		"srs:@id, srs:title, srs:class, srs:desiredPriority, srs:desiredPriority@type,"                \
    "srs:recordDestination, srs:recordDestination@mediaType, srs:recordDestination@targetURL,"     \
    "srs:recordDestination@preference, srs:desiredRecordQuality, srs:desiredRecordQuality@type,"   \
 		"srs:scheduledCDSObjectID, srs:scheduledChannelID, srs:scheduledChannelID@type,"               \
    "srs:scheduledStartDateTime, srs:scheduledDuration, srs:scheduledProgramCode,"                 \
    "srs:scheduledProdgramCode@type, srs:matchingName, srs:matchingName@type,"                     \
    "srs:matchingName@subStringMatch, srs:macthingID, srs:macthingID@type, srs:macthingChannelID," \
    "srs:macthingChannelID@type, srs:macthingStartDateTimeRange, srs:macthingDurationRange,"       \
    "srs:macthingRatingLimit, srs:macthingRatingLimit@type, srs:macthingEpisodeType,"              \
    "srs:totalDesiredRecordTasks, srs:scheduledStartDateTimeAdjust, srs:scheduledDurationAdjust,"  \
    "srs:activePeriod, srs:durationLimit, srs:durationLimit@effect, srs:channelMigration,"         \
    "srs:timeMigration, srs:allowDuplicates, srs:persistedRecordings,"                             \
    "srs:persistedRecordings@latest, srs:persistedRecordings@preAllocation,"                       \
    "srs:persistedRecordings@storedLifetime"

#define SRS_PROPERTY_LIST_RECORDSCHEDULE                                                           \
		"srs:@id, srs:title, srs:class, srs:additionalStatusInfo, srs:cdsReference,"                   \
		"srs:cdsReference@link, srs:priority, srs:priority@orderedValue, srs:desiredPriority,"         \
		"srs:desiredPriority@type, srs:recordDestination, srs:recordDestination@mediaType,"            \
		"srs:recordDestination@targetURL, srs:recordDestination@preference, srs:desiredRecordQuality," \
		"srs:desiredRecordQuality@type, srs:scheduledCDSObjectID, srs:scheduledCDSObjectID@link,"      \
		"srs:scheduledChannelID, srs:scheduledChannelID@type, srs:scheduledStartDateTime,"             \
    "srs:scheduledDuration, srs:scheduledProgramCode, srs:scheduledProdgramCode@type,"             \
		"srs:matchingName, srs:matchingName@type, srs:matchingName@subStringMatch, srs:macthingID,"    \
 		"srs:macthingID@type, srs:macthingChannelID, srs:macthingChannelID@type,"                      \
 		"srs:macthingStartDateTimeRange, srs:macthingDurationRange, srs:macthingRatingLimit,"          \
 		"srs:macthingRatingLimit@type, srs:macthingEpisodeType, srs:totalDesiredRecordTasks,"          \
 		"srs:scheduledStartDateTimeAdjust, srs:scheduledDurationAdjust, srs:activePeriod,"             \
 		"srs:durationLimit, srs:durationLimit@effect, srs:channelMigration, srs:timeMigration,"        \
 		"srs:allowDuplicates, srs:persistedRecordings, srs:persistedRecordings@latest,"                \
 		"srs:persistedRecordings@preAllocation, srs:persistedRecordings@storedLifetime,"               \
 		"srs:scheduleState, srs:scheduleState@currentErrors, srs:abnormalTasksExist,"                  \
 		"srs:currentRecordTaskCount, srs:totalCreatedRecordTasks, srs:totalCompletedRecordTasks"
	
#define SRS_PROPERTY_LIST_RECORDTASK                                                               \
		"srs:@id, srs:title, srs:class, srs:additionalStatusInfo, srs:cdsReference,"                   \
		"srs:cdsReference@link, srs:priority, srs:priority@orderedValue, srs:desiredPriority,"         \
		"srs:desiredPriority@type, srs:recordDestination, srs:recordDestination@mediaType,"            \
		"srs:recordDestination@targetURL, srs:recordDestination@preference, srs:desiredRecordQuality," \
		"srs:desiredRecordQuality@type, srs:recordScheduleID, srs:recordedCDSObjectID,"                \
		"srs:recordedCDSObjectID@link, srs:taskChannelID, srs:taskChannelID@type,"                     \
		"srs:taskStartDateTime, srs:taskDuration, srs:taskProgramCode, srs:taskProgramCode@type,"      \
		"srs:recordQuality, srs:recordQuality@type, srs:matchedName, srs:matchedName@type,"            \
		"srs:matchedID, srs:matchedID@type, srs:matchedRating, srs:matchedRating@type,"                \
		"srs:matchedEpisodeType, srs:taskStartDateTimeAdjust, srs:taskDurationAdjust,"                 \
		"srs:taskDurationLimit, srs:taskDurationLimit@effect, srs:taskChannelMigration,"               \
		"srs:taskTimeMigration, srs:taskState, srs:taskState@phase, srs:taskState@startDateTimeMet,"   \
		"srs:taskState@endDateTimeMet, srs:taskState@recording, srs:taskState@someBitsRecorded,"       \
		"srs:taskState@someBitsMissing, srs:taskState@firstBitsRecorded,"                              \
		"srs:taskState@lastBitsRecorded, srs:taskState@fatalError, srs:taskState@currentErrors,"       \
		"srs:taskState@errorHistory, srs:taskState@pendingErrors, srs:taskState@infoList"

#define SRS_DEFAULT_SORT_CAPS                                                                      \
		"+srs:title"

#define SRS_ACTION_ERROR_INVALID_SYNTAX															(701)
#define SRS_ACTION_ERROR_INVALID_VALUE															(703)
#define SRS_ACTION_ERROR_NO_SUCH_RECORDSCHEDULE_ID									(704)
#define SRS_ACTION_ERROR_ACTIVE_RECORDTASK													(705)
#define SRS_ACTION_ERROR_READ_ONLY_PROPERTY													(707)
#define SRS_ACTION_ERROR_REQUIRED_PROPERTY_IS_OMITTED								(708)
#define SRS_ACTION_ERROR_INVALID_SORT_CRITERIA											(709)
#define SRS_ACTION_ERROR_INVALID_DATATYPE_ID												(711)
#define SRS_ACTION_ERROR_NO_SUCH_RECORDTASK_ID											(713)
#define SRS_ACTION_ERROR_CANNOT_PROCESS_THE_REQUEST									(720)
#define SRS_ACTION_ERROR_CONFLICT																		(730)
#define SRS_ACTION_ERROR_PROTECTED_CONTENTS													(731)
#define SRS_ACTION_ERROR_MEDIA_IS_NOT_SPECIFIED											(732)
#define SRS_ACTION_ERROR_MEDIA_IS_WRITE_PROTECTED										(733)
#define SRS_ACTION_ERROR_MEDIA_NO_SPACE															(734)
#define SRS_ACTION_ERROR_MEDIA_ERROR																(735)
#define SRS_ACTION_ERROR_TOO_MANY_RECORDSCHEDULES										(736)
#define SRS_ACTION_ERROR_RESOURCE_ERROR															(737)
#define SRS_ACTION_ERROR_CANNOT_ENABLE_OR_DISABLE_RECORDSCHEDULE		(739)
#define SRS_ACTION_ERROR_RECORDSCHEDULE_COMPLETED										(740)
#define SRS_ACTION_ERROR_RECORDTASK_PHASE_DONE											(741)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
typedef struct upnp_srs_
{
	/* Backpoiner to the top.  */
	struct dms *top;
	
	/* SRS Object Manager.  */
	srs_obj_manager_t *obj_manager;

	/* State update ID.  */
	slim_word stateUpdateID;

	/* SOAP action.  */
	sXML *action_doc;

	/* SOAP result document.  */
	sXML *result_doc;

	void *info;
   
} upnp_srs;

/* GetRecordSchedule parameter */
struct srs_get_record_scheduled_param
{
	slim_char *RecordScheduleID;
	sXML *Filter;
	sXML *Result;
	slim_word UpdateID;
};

/* CreateRecordScheduled  parameter.  */
struct upnp_srs_create_record_schedule_param
{
	sXML *Elements;
	slim_char *RecordScheduleID;
	sXML *Result;
	slim_word UpdateID;
};

/* BrowseRecordScheduled  parameter.  */
struct srs_browse_record_scheduled_param
{
	slim_char *Filter; /*CSV*/
	slim_word StartingIndex;
	slim_word RequestedCount;
	slim_char *SortCriteria;
	sXML *Result;
	slim_word NumberReturned;
	slim_word TotalMatches;
	slim_word UpdateID;
};

upnp_srs*
upnp_srs_alloc(void *info, slim_char* srs_dir);

slim_int
upnp_srs_get_sort_capabilities(upnp_srs *s);

slim_int
upnp_srs_get_property_list(upnp_srs *s);

slim_int
upnp_srs_get_allowed_values(upnp_srs *s);

slim_int
upnp_srs_get_state_updateID(upnp_srs *s);

slim_int
upnp_srs_browse_record_schedules(upnp_srs *s);

slim_int
upnp_srs_get_browse_record_tasks(upnp_srs *s);

slim_int
upnp_srs_create_record_schedule(upnp_srs *s);

slim_int
upnp_srs_delete_record_schedule(upnp_srs *s);

slim_int
upnp_srs_get_record_schedule(upnp_srs *s);

slim_int
upnp_srs_get_record_task(upnp_srs *s);

slim_int
upnp_srs_enable_record_schedule(upnp_srs *s);

slim_int
upnp_srs_disable_record_schedule(upnp_srs *s);

slim_int
upnp_srs_delete_record_task(upnp_srs *s);

slim_int
upnp_srs_enable_record_task(upnp_srs *s);

slim_int
upnp_srs_disable_record_task(upnp_srs *s);

slim_int
upnp_srs_reset_record_task(upnp_srs *s);

slim_int
upnp_srs_get_record_schedule_conflicts(upnp_srs *s);

slim_int
upnp_srs_get_record_task_conflicts(upnp_srs *s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_UPNP_SRS_H*/
