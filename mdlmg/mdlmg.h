/*
 * mdlmg.h
 *
 *  Created on: 2015-5-30
 *      Author: looeyc
 */

#ifndef MDLMG_H_
#define MDLMG_H_

#include <time.h>
#include "sqlite3.h"
#include "mposition/mposition.h"

//Macro const definition
#define PATHLENMAX			128
#define DESCLENMAX			128
#define BROWSERINFOLENMAX	128

//For fDlmg_CreatPack()
#define DLMG_OPT_DEFAULT				0x00000000
#define DLMG_OPT_RAPLACE_IF_EXIST		0x00000001

//Data type definition
typedef unsigned int tyPackUUID; //UUID for download packets
typedef unsigned int tyDSerialNum; //Download serial number

//Module status
typedef struct{
	sqlite3 *pDBHandle;	//Database handler
}stDlmgStatus;
extern stDlmgStatus DlmgStatus;

//For fDlmg_Init()
typedef struct{
	sqlite3 *pDBHandle;	//Database handler
}stDlmgCfg;

//Type of download packs
typedef enum{
	APK, //apk for android
	APR  //apr for IOS
}enPackType;

//Downloading packs struct
typedef struct{
	tyPackUUID PackID;
	enPackType Type;
	char StorePath[PATHLENMAX];
	char IconPath[PATHLENMAX];
	char Descript[DESCLENMAX];
	time_t ExpireDate;
	tyDSerialNum NextDSerialNum;
}stDownPack;

//Downloading records struct
typedef struct{
	tyDSerialNum DSerialNum;
	tyPackUUID PackID;
	time_t DownTime;
	char BrowserInfo[BROWSERINFOLENMAX];
	stPosition Position;
}stDownRecord;

//Function: Init the Dlmg module
//Parameters:
//	pDlmgCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fDlmg_Init(stDlmgCfg *pDlmgCfg);

//Function: Creat a download pack with parameters
//Parameters:
//	pPack - parameter for pack creating
//	Option -
//		DEFAULT				: Creat with default options
//		RAPLACE_IF_EXIST	: Replace if pack already existed
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_CreatPack(stDownPack *pPack, int Option);

//Function: Update a packet with parameters
//Parameters:
//	pPack - parameter for pack updating
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_UpdatePack(stDownPack *pPack);

//Function: Remove a packet
//Parameters:
//	UUID - UUID of the packet to be removed
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_RemovePack(tyPackUUID PackID);

//Function: Get the ID list of all packs
//Parameters:
//	pPackIDList - Used to return ID list (The caller is responsible for mem allocation before calling)
//	PackIDListLen - The caller specifies the capacity of pPackIDList.
//return:
//	>=0 - Succeed, the number of IDs returned.
//	else - consult the errocode.h
//Note:
//	If there is not enough space in pPackIDList to hold all the apples found, then the maxim number of apples will be returned.
//	In other words, if you got a return vaule = PackIDListLen, then there maybe more IDs remaining.
int fDlmg_GetPackIDList(tyPackUUID *pPackIDList,int PackIDListLen);

//Function: Get a specific pack by Pack UUID
//Parameters:
//	PackID - The specific UUID;
//	pPack - Used to return the pack found (The caller is responsible for mem allocation before calling)
//return:
//	0 - No pack with specific UUID was found.
//	1 - Succeed, found one.
//	else - consult the errocode.h
int fDlmg_GetPackByID(tyPackUUID PackID, stDownPack *pPack);

//Function: Get the total downloading times of a specific pack
//Parameters:
//	PackID - The specific pack ID
//	TimeBegin - The number of records between TimeBegin and TimeEnd will be returned.
//	TimeEnd - The number of records between TimeBegin and TimeEnd will be returned.
//return:
//	>=0- Succeed, the downloading time
//	else - consult the errocode.h
int fDlmg_GetRecordsNum(tyPackUUID PackID, time_t TimeBegin, time_t TimeEnd);

//Function: Get the specific downloading records
//Parameters:
//	PackID - The records with which PackID should be returned.
//	TimeBegin - The records between TimeBegin and TimeEnd will be returned.
//	TimeEnd - The records between TimeBegin and TimeEnd will be returned.
//	pRecord - Used to return the downloading records. (The caller is responsible for mem allocation before calling)
//return:
//	>=0- Succeed, the number of records found
//	else - consult the errocode.h
int fDlmg_GetRecords(tyPackUUID PackID, time_t TimeBegin, time_t TimeEnd, stDownRecord *pRecord);

//Function: Remove all downloading records of a specific Pack
//Parameters:
//	PackID - The specific Pack ID
//return:
//	>=0 - Succeed, the number of IDs returned.
//	else - consult the errocode.h
int fDlmg_RemoveRecordsByPackID(tyPackUUID PackID);

#endif /* MDLMG_H_ */

