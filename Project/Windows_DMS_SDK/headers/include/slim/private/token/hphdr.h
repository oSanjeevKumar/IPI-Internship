/*
	hphdr.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/hphdr.h 22    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_HPHDR_H
#define SLIM_TOKEN_HPHDR_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/token/hphdrid.h>

SLIM_BEGIN_C_LINKAGE

struct THTTPHeaderInfo_ {
	TToken fBase;	/* must be the first field */
	slim_int fHeaderType;
};
typedef struct THTTPHeaderInfo_ THTTPHeaderInfo;

#define SLIM_TKOFF_BASE_HPHDR0	(0)
#define SLIM_TKNAM_BASE_HPHDR0	((slim_char *)cSlim_TokenName_HPHDR)
#define SLIM_TKOFF_HPHDR_Cache_Control_	(SLIM_TKOFF_BASE_HPHDR0 + 0)
#define SLIM_TKNAM_HPHDR_Cache_Control_	(SLIM_TKNAM_BASE_HPHDR0 + 0)
#define SLIM_TKLEN_HPHDR_Cache_Control_	(14)
#define SLIM_TOKEN_HPHDR_Cache_Control_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Cache_Control_))
#define SLIM_TKOFF_HPHDR_Connection_	(SLIM_TKOFF_BASE_HPHDR0 + 15)
#define SLIM_TKNAM_HPHDR_Connection_	(SLIM_TKNAM_BASE_HPHDR0 + 15)
#define SLIM_TKLEN_HPHDR_Connection_	(11)
#define SLIM_TOKEN_HPHDR_Connection_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Connection_))
#define SLIM_TKOFF_HPHDR_Date_	(SLIM_TKOFF_BASE_HPHDR0 + 27)
#define SLIM_TKNAM_HPHDR_Date_	(SLIM_TKNAM_BASE_HPHDR0 + 27)
#define SLIM_TKLEN_HPHDR_Date_	(5)
#define SLIM_TOKEN_HPHDR_Date_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Date_))
#define SLIM_TKOFF_HPHDR_Pragma_	(SLIM_TKOFF_BASE_HPHDR0 + 33)
#define SLIM_TKNAM_HPHDR_Pragma_	(SLIM_TKNAM_BASE_HPHDR0 + 33)
#define SLIM_TKLEN_HPHDR_Pragma_	(7)
#define SLIM_TOKEN_HPHDR_Pragma_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Pragma_))
#define SLIM_TKOFF_HPHDR_Trailer_	(SLIM_TKOFF_BASE_HPHDR0 + 41)
#define SLIM_TKNAM_HPHDR_Trailer_	(SLIM_TKNAM_BASE_HPHDR0 + 41)
#define SLIM_TKLEN_HPHDR_Trailer_	(8)
#define SLIM_TOKEN_HPHDR_Trailer_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Trailer_))
#define SLIM_TKOFF_HPHDR_Transfer_Encoding_	(SLIM_TKOFF_BASE_HPHDR0 + 50)
#define SLIM_TKNAM_HPHDR_Transfer_Encoding_	(SLIM_TKNAM_BASE_HPHDR0 + 50)
#define SLIM_TKLEN_HPHDR_Transfer_Encoding_	(18)
#define SLIM_TOKEN_HPHDR_Transfer_Encoding_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Transfer_Encoding_))
#define SLIM_TKOFF_HPHDR_Upgrade_	(SLIM_TKOFF_BASE_HPHDR0 + 69)
#define SLIM_TKNAM_HPHDR_Upgrade_	(SLIM_TKNAM_BASE_HPHDR0 + 69)
#define SLIM_TKLEN_HPHDR_Upgrade_	(8)
#define SLIM_TOKEN_HPHDR_Upgrade_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Upgrade_))
#define SLIM_TKOFF_HPHDR_Via_	(SLIM_TKOFF_BASE_HPHDR0 + 78)
#define SLIM_TKNAM_HPHDR_Via_	(SLIM_TKNAM_BASE_HPHDR0 + 78)
#define SLIM_TKLEN_HPHDR_Via_	(4)
#define SLIM_TOKEN_HPHDR_Via_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Via_))
#define SLIM_TKOFF_HPHDR_Warning_	(SLIM_TKOFF_BASE_HPHDR0 + 83)
#define SLIM_TKNAM_HPHDR_Warning_	(SLIM_TKNAM_BASE_HPHDR0 + 83)
#define SLIM_TKLEN_HPHDR_Warning_	(8)
#define SLIM_TOKEN_HPHDR_Warning_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Warning_))
#define SLIM_TKOFF_HPHDR_Keep_Alive_	(SLIM_TKOFF_BASE_HPHDR0 + 92)
#define SLIM_TKNAM_HPHDR_Keep_Alive_	(SLIM_TKNAM_BASE_HPHDR0 + 92)
#define SLIM_TKLEN_HPHDR_Keep_Alive_	(11)
#define SLIM_TOKEN_HPHDR_Keep_Alive_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Keep_Alive_))
#define SLIM_TKOFF_HPHDR_Proxy_Connection_	(SLIM_TKOFF_BASE_HPHDR0 + 104)
#define SLIM_TKNAM_HPHDR_Proxy_Connection_	(SLIM_TKNAM_BASE_HPHDR0 + 104)
#define SLIM_TKLEN_HPHDR_Proxy_Connection_	(17)
#define SLIM_TOKEN_HPHDR_Proxy_Connection_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Proxy_Connection_))
#define SLIM_TKOFF_HPHDR_Accept_	(SLIM_TKOFF_BASE_HPHDR0 + 122)
#define SLIM_TKNAM_HPHDR_Accept_	(SLIM_TKNAM_BASE_HPHDR0 + 122)
#define SLIM_TKLEN_HPHDR_Accept_	(7)
#define SLIM_TOKEN_HPHDR_Accept_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Accept_))
#define SLIM_TKOFF_HPHDR_Accept_Charset_	(SLIM_TKOFF_BASE_HPHDR0 + 130)
#define SLIM_TKNAM_HPHDR_Accept_Charset_	(SLIM_TKNAM_BASE_HPHDR0 + 130)
#define SLIM_TKLEN_HPHDR_Accept_Charset_	(15)
#define SLIM_TOKEN_HPHDR_Accept_Charset_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Accept_Charset_))
#define SLIM_TKOFF_HPHDR_Accept_Encoding_	(SLIM_TKOFF_BASE_HPHDR0 + 146)
#define SLIM_TKNAM_HPHDR_Accept_Encoding_	(SLIM_TKNAM_BASE_HPHDR0 + 146)
#define SLIM_TKLEN_HPHDR_Accept_Encoding_	(16)
#define SLIM_TOKEN_HPHDR_Accept_Encoding_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Accept_Encoding_))
#define SLIM_TKOFF_HPHDR_Accept_Language_	(SLIM_TKOFF_BASE_HPHDR0 + 163)
#define SLIM_TKNAM_HPHDR_Accept_Language_	(SLIM_TKNAM_BASE_HPHDR0 + 163)
#define SLIM_TKLEN_HPHDR_Accept_Language_	(16)
#define SLIM_TOKEN_HPHDR_Accept_Language_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Accept_Language_))
#define SLIM_TKOFF_HPHDR_Authorization_	(SLIM_TKOFF_BASE_HPHDR0 + 180)
#define SLIM_TKNAM_HPHDR_Authorization_	(SLIM_TKNAM_BASE_HPHDR0 + 180)
#define SLIM_TKLEN_HPHDR_Authorization_	(14)
#define SLIM_TOKEN_HPHDR_Authorization_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Authorization_))
#define SLIM_TKOFF_HPHDR_Expect_	(SLIM_TKOFF_BASE_HPHDR0 + 195)
#define SLIM_TKNAM_HPHDR_Expect_	(SLIM_TKNAM_BASE_HPHDR0 + 195)
#define SLIM_TKLEN_HPHDR_Expect_	(7)
#define SLIM_TOKEN_HPHDR_Expect_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Expect_))
#define SLIM_TKOFF_HPHDR_From_	(SLIM_TKOFF_BASE_HPHDR0 + 203)
#define SLIM_TKNAM_HPHDR_From_	(SLIM_TKNAM_BASE_HPHDR0 + 203)
#define SLIM_TKLEN_HPHDR_From_	(5)
#define SLIM_TOKEN_HPHDR_From_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_From_))
#define SLIM_TKOFF_HPHDR_Host_	(SLIM_TKOFF_BASE_HPHDR0 + 209)
#define SLIM_TKNAM_HPHDR_Host_	(SLIM_TKNAM_BASE_HPHDR0 + 209)
#define SLIM_TKLEN_HPHDR_Host_	(5)
#define SLIM_TOKEN_HPHDR_Host_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Host_))
#define SLIM_TKOFF_HPHDR_If_Match_	(SLIM_TKOFF_BASE_HPHDR0 + 215)
#define SLIM_TKNAM_HPHDR_If_Match_	(SLIM_TKNAM_BASE_HPHDR0 + 215)
#define SLIM_TKLEN_HPHDR_If_Match_	(9)
#define SLIM_TOKEN_HPHDR_If_Match_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_If_Match_))
#define SLIM_TKOFF_HPHDR_If_Modified_Since_	(SLIM_TKOFF_BASE_HPHDR0 + 225)
#define SLIM_TKNAM_HPHDR_If_Modified_Since_	(SLIM_TKNAM_BASE_HPHDR0 + 225)
#define SLIM_TKLEN_HPHDR_If_Modified_Since_	(18)
#define SLIM_TOKEN_HPHDR_If_Modified_Since_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_If_Modified_Since_))
#define SLIM_TKOFF_HPHDR_If_None_Match_	(SLIM_TKOFF_BASE_HPHDR0 + 244)
#define SLIM_TKNAM_HPHDR_If_None_Match_	(SLIM_TKNAM_BASE_HPHDR0 + 244)
#define SLIM_TKLEN_HPHDR_If_None_Match_	(14)
#define SLIM_TOKEN_HPHDR_If_None_Match_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_If_None_Match_))
#define SLIM_TKOFF_HPHDR_If_Range_	(SLIM_TKOFF_BASE_HPHDR0 + 259)
#define SLIM_TKNAM_HPHDR_If_Range_	(SLIM_TKNAM_BASE_HPHDR0 + 259)
#define SLIM_TKLEN_HPHDR_If_Range_	(9)
#define SLIM_TOKEN_HPHDR_If_Range_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_If_Range_))
#define SLIM_TKOFF_HPHDR_If_Unmodified_Since_	(SLIM_TKOFF_BASE_HPHDR0 + 269)
#define SLIM_TKNAM_HPHDR_If_Unmodified_Since_	(SLIM_TKNAM_BASE_HPHDR0 + 269)
#define SLIM_TKLEN_HPHDR_If_Unmodified_Since_	(20)
#define SLIM_TOKEN_HPHDR_If_Unmodified_Since_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_If_Unmodified_Since_))
#define SLIM_TKOFF_HPHDR_Max_Forwards_	(SLIM_TKOFF_BASE_HPHDR0 + 290)
#define SLIM_TKNAM_HPHDR_Max_Forwards_	(SLIM_TKNAM_BASE_HPHDR0 + 290)
#define SLIM_TKLEN_HPHDR_Max_Forwards_	(13)
#define SLIM_TOKEN_HPHDR_Max_Forwards_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Max_Forwards_))
#define SLIM_TKOFF_HPHDR_Proxy_Authorization_	(SLIM_TKOFF_BASE_HPHDR0 + 304)
#define SLIM_TKNAM_HPHDR_Proxy_Authorization_	(SLIM_TKNAM_BASE_HPHDR0 + 304)
#define SLIM_TKLEN_HPHDR_Proxy_Authorization_	(20)
#define SLIM_TOKEN_HPHDR_Proxy_Authorization_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Proxy_Authorization_))
#define SLIM_TKOFF_HPHDR_Range_	(SLIM_TKOFF_BASE_HPHDR0 + 325)
#define SLIM_TKNAM_HPHDR_Range_	(SLIM_TKNAM_BASE_HPHDR0 + 325)
#define SLIM_TKLEN_HPHDR_Range_	(6)
#define SLIM_TOKEN_HPHDR_Range_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Range_))
#define SLIM_TKOFF_HPHDR_Referer_	(SLIM_TKOFF_BASE_HPHDR0 + 332)
#define SLIM_TKNAM_HPHDR_Referer_	(SLIM_TKNAM_BASE_HPHDR0 + 332)
#define SLIM_TKLEN_HPHDR_Referer_	(8)
#define SLIM_TOKEN_HPHDR_Referer_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Referer_))
#define SLIM_TKOFF_HPHDR_TE_	(SLIM_TKOFF_BASE_HPHDR0 + 341)
#define SLIM_TKNAM_HPHDR_TE_	(SLIM_TKNAM_BASE_HPHDR0 + 341)
#define SLIM_TKLEN_HPHDR_TE_	(3)
#define SLIM_TOKEN_HPHDR_TE_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_TE_))
#define SLIM_TKOFF_HPHDR_User_Agent_	(SLIM_TKOFF_BASE_HPHDR0 + 345)
#define SLIM_TKNAM_HPHDR_User_Agent_	(SLIM_TKNAM_BASE_HPHDR0 + 345)
#define SLIM_TKLEN_HPHDR_User_Agent_	(11)
#define SLIM_TOKEN_HPHDR_User_Agent_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_User_Agent_))
#define SLIM_TKOFF_HPHDR_Cookie_	(SLIM_TKOFF_BASE_HPHDR0 + 357)
#define SLIM_TKNAM_HPHDR_Cookie_	(SLIM_TKNAM_BASE_HPHDR0 + 357)
#define SLIM_TKLEN_HPHDR_Cookie_	(7)
#define SLIM_TOKEN_HPHDR_Cookie_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Cookie_))
#define SLIM_TKOFF_HPHDR_Accept_Ranges_	(SLIM_TKOFF_BASE_HPHDR0 + 365)
#define SLIM_TKNAM_HPHDR_Accept_Ranges_	(SLIM_TKNAM_BASE_HPHDR0 + 365)
#define SLIM_TKLEN_HPHDR_Accept_Ranges_	(14)
#define SLIM_TOKEN_HPHDR_Accept_Ranges_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Accept_Ranges_))
#define SLIM_TKOFF_HPHDR_Age_	(SLIM_TKOFF_BASE_HPHDR0 + 380)
#define SLIM_TKNAM_HPHDR_Age_	(SLIM_TKNAM_BASE_HPHDR0 + 380)
#define SLIM_TKLEN_HPHDR_Age_	(4)
#define SLIM_TOKEN_HPHDR_Age_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Age_))
#define SLIM_TKOFF_HPHDR_ETag_	(SLIM_TKOFF_BASE_HPHDR0 + 385)
#define SLIM_TKNAM_HPHDR_ETag_	(SLIM_TKNAM_BASE_HPHDR0 + 385)
#define SLIM_TKLEN_HPHDR_ETag_	(5)
#define SLIM_TOKEN_HPHDR_ETag_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_ETag_))
#define SLIM_TKOFF_HPHDR_Location_	(SLIM_TKOFF_BASE_HPHDR0 + 391)
#define SLIM_TKNAM_HPHDR_Location_	(SLIM_TKNAM_BASE_HPHDR0 + 391)
#define SLIM_TKLEN_HPHDR_Location_	(9)
#define SLIM_TOKEN_HPHDR_Location_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Location_))
#define SLIM_TKOFF_HPHDR_Proxy_Authenticate_	(SLIM_TKOFF_BASE_HPHDR0 + 401)
#define SLIM_TKNAM_HPHDR_Proxy_Authenticate_	(SLIM_TKNAM_BASE_HPHDR0 + 401)
#define SLIM_TKLEN_HPHDR_Proxy_Authenticate_	(19)
#define SLIM_TOKEN_HPHDR_Proxy_Authenticate_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Proxy_Authenticate_))
#define SLIM_TKOFF_HPHDR_Retry_After_	(SLIM_TKOFF_BASE_HPHDR0 + 421)
#define SLIM_TKNAM_HPHDR_Retry_After_	(SLIM_TKNAM_BASE_HPHDR0 + 421)
#define SLIM_TKLEN_HPHDR_Retry_After_	(12)
#define SLIM_TOKEN_HPHDR_Retry_After_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Retry_After_))
#define SLIM_TKOFF_HPHDR_Server_	(SLIM_TKOFF_BASE_HPHDR0 + 434)
#define SLIM_TKNAM_HPHDR_Server_	(SLIM_TKNAM_BASE_HPHDR0 + 434)
#define SLIM_TKLEN_HPHDR_Server_	(7)
#define SLIM_TOKEN_HPHDR_Server_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Server_))
#define SLIM_TKOFF_HPHDR_Vary_	(SLIM_TKOFF_BASE_HPHDR0 + 442)
#define SLIM_TKNAM_HPHDR_Vary_	(SLIM_TKNAM_BASE_HPHDR0 + 442)
#define SLIM_TKLEN_HPHDR_Vary_	(5)
#define SLIM_TOKEN_HPHDR_Vary_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Vary_))
#define SLIM_TKOFF_HPHDR_WWW_Authenticate_	(SLIM_TKOFF_BASE_HPHDR0 + 448)
#define SLIM_TKNAM_HPHDR_WWW_Authenticate_	(SLIM_TKNAM_BASE_HPHDR0 + 448)
#define SLIM_TKLEN_HPHDR_WWW_Authenticate_	(17)
#define SLIM_TOKEN_HPHDR_WWW_Authenticate_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_WWW_Authenticate_))
#define SLIM_TKOFF_HPHDR_Set_Cookie_	(SLIM_TKOFF_BASE_HPHDR0 + 466)
#define SLIM_TKNAM_HPHDR_Set_Cookie_	(SLIM_TKNAM_BASE_HPHDR0 + 466)
#define SLIM_TKLEN_HPHDR_Set_Cookie_	(11)
#define SLIM_TOKEN_HPHDR_Set_Cookie_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Set_Cookie_))
#define SLIM_TKOFF_HPHDR_Authentication_Info_	(SLIM_TKOFF_BASE_HPHDR0 + 478)
#define SLIM_TKNAM_HPHDR_Authentication_Info_	(SLIM_TKNAM_BASE_HPHDR0 + 478)
#define SLIM_TKLEN_HPHDR_Authentication_Info_	(20)
#define SLIM_TOKEN_HPHDR_Authentication_Info_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Authentication_Info_))
#define SLIM_TKOFF_HPHDR_Proxy_Authentication_Info_	(SLIM_TKOFF_BASE_HPHDR0 + 499)
#define SLIM_TKNAM_HPHDR_Proxy_Authentication_Info_	(SLIM_TKNAM_BASE_HPHDR0 + 499)
#define SLIM_TKLEN_HPHDR_Proxy_Authentication_Info_	(26)
#define SLIM_TOKEN_HPHDR_Proxy_Authentication_Info_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Proxy_Authentication_Info_))
#define SLIM_TKOFF_HPHDR_Allow_	(SLIM_TKOFF_BASE_HPHDR0 + 526)
#define SLIM_TKNAM_HPHDR_Allow_	(SLIM_TKNAM_BASE_HPHDR0 + 526)
#define SLIM_TKLEN_HPHDR_Allow_	(6)
#define SLIM_TOKEN_HPHDR_Allow_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Allow_))
#define SLIM_TKOFF_HPHDR_Content_Encoding_	(SLIM_TKOFF_BASE_HPHDR0 + 533)
#define SLIM_TKNAM_HPHDR_Content_Encoding_	(SLIM_TKNAM_BASE_HPHDR0 + 533)
#define SLIM_TKLEN_HPHDR_Content_Encoding_	(17)
#define SLIM_TOKEN_HPHDR_Content_Encoding_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Encoding_))
#define SLIM_TKOFF_HPHDR_Content_Disposition_	(SLIM_TKOFF_BASE_HPHDR0 + 551)
#define SLIM_TKNAM_HPHDR_Content_Disposition_	(SLIM_TKNAM_BASE_HPHDR0 + 551)
#define SLIM_TKLEN_HPHDR_Content_Disposition_	(20)
#define SLIM_TOKEN_HPHDR_Content_Disposition_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Disposition_))
#define SLIM_TKOFF_HPHDR_Content_Language_	(SLIM_TKOFF_BASE_HPHDR0 + 572)
#define SLIM_TKNAM_HPHDR_Content_Language_	(SLIM_TKNAM_BASE_HPHDR0 + 572)
#define SLIM_TKLEN_HPHDR_Content_Language_	(17)
#define SLIM_TOKEN_HPHDR_Content_Language_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Language_))
#define SLIM_TKOFF_HPHDR_Content_Length_	(SLIM_TKOFF_BASE_HPHDR0 + 590)
#define SLIM_TKNAM_HPHDR_Content_Length_	(SLIM_TKNAM_BASE_HPHDR0 + 590)
#define SLIM_TKLEN_HPHDR_Content_Length_	(15)
#define SLIM_TOKEN_HPHDR_Content_Length_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Length_))
#define SLIM_TKOFF_HPHDR_Content_Location_	(SLIM_TKOFF_BASE_HPHDR0 + 606)
#define SLIM_TKNAM_HPHDR_Content_Location_	(SLIM_TKNAM_BASE_HPHDR0 + 606)
#define SLIM_TKLEN_HPHDR_Content_Location_	(17)
#define SLIM_TOKEN_HPHDR_Content_Location_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Location_))
#define SLIM_TKOFF_HPHDR_Content_MD5_	(SLIM_TKOFF_BASE_HPHDR0 + 624)
#define SLIM_TKNAM_HPHDR_Content_MD5_	(SLIM_TKNAM_BASE_HPHDR0 + 624)
#define SLIM_TKLEN_HPHDR_Content_MD5_	(12)
#define SLIM_TOKEN_HPHDR_Content_MD5_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_MD5_))
#define SLIM_TKOFF_HPHDR_Content_Range_	(SLIM_TKOFF_BASE_HPHDR0 + 637)
#define SLIM_TKNAM_HPHDR_Content_Range_	(SLIM_TKNAM_BASE_HPHDR0 + 637)
#define SLIM_TKLEN_HPHDR_Content_Range_	(14)
#define SLIM_TOKEN_HPHDR_Content_Range_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Range_))
#define SLIM_TKOFF_HPHDR_Content_Type_	(SLIM_TKOFF_BASE_HPHDR0 + 652)
#define SLIM_TKNAM_HPHDR_Content_Type_	(SLIM_TKNAM_BASE_HPHDR0 + 652)
#define SLIM_TKLEN_HPHDR_Content_Type_	(13)
#define SLIM_TOKEN_HPHDR_Content_Type_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Content_Type_))
#define SLIM_TKOFF_HPHDR_Expires_	(SLIM_TKOFF_BASE_HPHDR0 + 666)
#define SLIM_TKNAM_HPHDR_Expires_	(SLIM_TKNAM_BASE_HPHDR0 + 666)
#define SLIM_TKLEN_HPHDR_Expires_	(8)
#define SLIM_TOKEN_HPHDR_Expires_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Expires_))
#define SLIM_TKOFF_HPHDR_Last_Modified_	(SLIM_TKOFF_BASE_HPHDR0 + 675)
#define SLIM_TKNAM_HPHDR_Last_Modified_	(SLIM_TKNAM_BASE_HPHDR0 + 675)
#define SLIM_TKLEN_HPHDR_Last_Modified_	(14)
#define SLIM_TOKEN_HPHDR_Last_Modified_	(HTTPHeaderInfo_GetItem(SLIM_TKID_HPHDR_Last_Modified_))
#define SLIM_TKOFF_BASE_HPHDR1	(SLIM_TKOFF_BASE_HPHDR0 + 690)
#define SLIM_TKNAM_BASE_HPHDR1	(SLIM_TKNAM_BASE_HPHDR0 + SLIM_TKOFF_BASE_HPHDR1)
#define SLIM_TKLEN_TOTAL_HPHDR	SLIM_TKOFF_BASE_HPHDR1

extern SLIM_ROM slim_char cSlim_TokenName_HPHDR[SLIM_TKLEN_TOTAL_HPHDR];

extern SLIM_ROM THTTPHeaderInfo cSlim_Token_HPHDR[SLIM_TOKEN_HPHDR_TOKENS];
#define HTTPHeaderInfo_GetItem(id)		((THTTPHeaderInfo *)&cSlim_Token_HPHDR[(id)])
#define HTTPHeaderInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_HPHDR + ((TToken *)&cSlim_Token_HPHDR[(id)])->fOffset)
#define HTTPHeaderInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_HPHDR[(id)])->fLength)

THTTPHeaderInfo *HTTPHeaderInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
