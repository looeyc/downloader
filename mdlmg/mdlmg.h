/*
 * mdlmg.h
 *
 *  Created on: 2015-5-30
 *      Author: looeyc
 */

#ifndef MDLMG_H_
#define MDLMG_H_

#include <time.h>

//Macro const definition
#define PATHLENMAX			128
#define DESCLENMAX			128
#define BROWSERINFOLENMAX	128

//For fDlmg_CreatPack()
#define DEFAULT				0x00000000
#define RAPLACE_IF_EXIST	0x00000001

//Macro
typedef unsigned int tyPackUUID; //UUID for download packets
typedef unsigned int tyRecordID; //ID for download records

//For fDlmg_Init()
typedef struct{
  char DateBasePath[PATHLENMAX]; //Path of the downloader.db file
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
}stDownPack;

//Position struct
typedef struct{
  char	EW_Flag;		//'E'、'W', Longitude flag
  double  EW_Value;	//'E'、'W', Longitude value
  char NS_Flag; 	//'N'、'S', Latitude flag
  double  NS_Value;	//'N'、'S', Latitude value
}stPosition;

//Downloading records struct
typedef struct{
  tyRecordID RecordID;
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
//return:
//	>=0- Succeed, the downloading time
//	else - consult the errocode.h
int fDlmg_GetRecordNum(tyPackUUID PackID);

//Function: Get the downloading record ID list of a specific pack.
//Parameters:
//	PackID - The specific pack ID
//	pRecordIDList - Used to return the ID list (The caller is responsible for mem allocation before calling)
//	RecordIDListLen - The caller specifies the capacity of pRecordIDList.
//return:
//	>=0 - Succeed, the number of IDs returned.
//	else - consult the errocode.h
//Note:
//	If there is not enough space in pPackIDList to hold all the apples found, then the maxim number of apples will be returned.
//	In other words, if you got a return vaule = PackIDListLen, then there maybe more IDs remaining.
int fDlmg_GetRecordIDList(tyPackUUID PackID, tyRecordID *pRecordIDList, int RecordIDListLen);

//Function: Get the specific downloading record
//Parameters:
//	RecordID - The specific downloading record ID
//	pRecord - Used to return the downloading record (The caller is responsible for mem allocation before calling)
//return:
//	0 - No record found.
//	1 - Succeed, found one.
//	else - consult the errocode.h
int fDlmg_GetRecordByID(tyRecordID RecordID, stDownRecord *pRecord);

//Function: Remove all downloading records of a specific Pack
//Parameters:
//	PackID - The specific Pack ID
//return:
//	>=0 - Succeed, the number of IDs returned.
//	else - consult the errocode.h
int fDlmg_RemoveRecordsByPackID(tyPackUUID PackID);


#endif /* MDLMG_H_ */
