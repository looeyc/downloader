/*
 * mdlmg.c
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */

#include <stdio.h>
#include <memory.h>
#include "debuglog.h"
#include "errocode.h"
#include "mdlmg.h"

stDlmgStatus DlmgStatus;

//Function: Init the Dlmg module
//Parameters:
//	pDlmgCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fDlmg_Init(stDlmgCfg *pDlmgCfg)
{
	int rt;
	char pSql[512];
	char *pErrMsg=NULL;

	if(pDlmgCfg==NULL){
		return ILLEGAL_INPUT;
	}

	memset(&DlmgStatus,0,sizeof(stDlmgCfg));

	//Init database table
	if(pDlmgCfg->pDBHandle==NULL){
		return ILLEGAL_INPUT;
	}
	DlmgStatus.pDBHandle=pDlmgCfg->pDBHandle;
	//创建表downpacks
	snprintf(pSql,512,"CREATE TABLE IF NOT EXISTS downpacks (\
		PK_ID				INTEGER NOT NULL, \
		PK_TYPE				INTEGER NOT NULL, \
		PK_STOREPATH		TEXT NOT NULL, \
		PK_ICONPATH			TEXT NOT NULL, \
		PK_DESC				TEXT NOT NULL, \
		EXPIRE_DATE			INTEGER, \
		NEXTDSERNUM			INTEGER, \
		PRIMARY KEY (PK_ID));\
		");
	rt=sqlite3_exec(DlmgStatus.pDBHandle , pSql , 0 , 0 , &pErrMsg);
	if(rt!=SQLITE_OK){
		DEBUGLOG2(3,"Error, CREATE TABLE downpacks failed %d: %s.\n",rt,pErrMsg);
		return DATABASE_FAILURE;
	}
	//创建表downrecords
	snprintf(pSql,512,"CREATE TABLE IF NOT EXISTS downrecords (\
		DSERNUM				INTEGER NOT NULL, \
		PACKID				INTEGER NOT NULL, \
		DOWNTIME			INTEGER, \
		POSITION_EW_F		TEXT, \
		POSITION_EW_V		DOUBLE, \
		POSITION_NS_F		TEXT, \
		POSITION_NS_V		DOUBLE, \
		BROWSERINFO			TEXT, \
		PRIMARY KEY (DSERNUM,PACKID)); \
		");
	rt=sqlite3_exec(DlmgStatus.pDBHandle , pSql , 0 , 0 , &pErrMsg);
	if(rt!=SQLITE_OK){
		DEBUGLOG2(3,"Error, CREATE TABLE downrecords failed %d: %s.\n",rt,pErrMsg);
		return DATABASE_FAILURE;
	}

	return SUCCESS;
}

//Following is about packs//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function: Creat a download pack with parameters
//Parameters:
//	pPack - parameter for pack creating
//	Option -
//		DEFAULT				: Creat with default options
//		RAPLACE_IF_EXIST	: Replace if pack already existed
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_CreatPack(stDownPack *pPack, int Option)
{
	int rt,isErr=0;
	char pSql[512];
	sqlite3_stmt *pStmt=NULL;

	if(pPack==NULL){
		return ILLEGAL_INPUT;
	}

	if(DlmgStatus.pDBHandle==NULL){
		DEBUGLOG0(3,"Error, database uninitialized.\n");
		return DATABASE_FAILURE;
	}

	if((Option & DLMG_OPT_RAPLACE_IF_EXIST)){//Replace if existed
		snprintf(pSql,512,"INSERT OR REPLACE INTO downpacks VALUES (%d,%d,'%s','%s','%s',%ld,%d);",pPack->PackID,pPack->Type,pPack->StorePath,pPack->IconPath,pPack->Descript,pPack->ExpireDate,0);
	}else{//Do not replace if existed
		snprintf(pSql,512,"INSERT OR FAIL INTO downpacks VALUES (%d,%d,'%s','%s','%s',%ld,%d);",pPack->PackID,pPack->Type,pPack->StorePath,pPack->IconPath,pPack->Descript,pPack->ExpireDate,0);
	}
	rt=sqlite3_prepare_v2(DlmgStatus.pDBHandle, pSql, strlen(pSql), &pStmt, NULL);
	if(rt!=SQLITE_OK){
		DEBUGLOG1(3,"Error, sqlite3_prepare_v2 failed %d.\n",rt);
		isErr=1;
	}else{
		rt=sqlite3_step(pStmt);
		if(rt!=SQLITE_DONE){
			DEBUGLOG1(3,"Error, sqlite3_step failed %d.\n",rt);
			isErr=1;
		}
	}

	if(pStmt!=NULL){
		sqlite3_finalize(pStmt);
	}

	return (isErr)? DATABASE_FAILURE : SUCCESS;
}

//Function: Update a packet with parameters
//Parameters:
//	pPack - parameter for pack updating
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_UpdatePack(stDownPack *pPack)
{
	if(pPack==NULL){
		return ILLEGAL_INPUT;
	}
	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}

//Function: Remove a packet
//Parameters:
//	UUID - UUID of the packet to be removed
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_RemovePack(tyPackUUID PackID)
{
	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}

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
int fDlmg_GetPackIDList(tyPackUUID *pPackIDList,int PackIDListLen)
{
	if(pPackIDList==NULL){
		return ILLEGAL_INPUT;
	}
	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}

//Function: Get a specific pack by Pack UUID
//Parameters:
//	PackID - The specific UUID;
//	pPack - Used to return the pack found (The caller is responsible for mem allocation before calling)
//return:
//	0 - No pack with specific UUID was found.
//	1 - Succeed, found one.
//	else - consult the errocode.h
int fDlmg_GetPackByID(tyPackUUID PackID, stDownPack *pPack)
{
	if(pPack==NULL){
		return ILLEGAL_INPUT;
	}
	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}

//Following is about records//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function: Get the total downloading times of a specific pack
//Parameters:
//	PackID - The specific pack ID
//	TimeBegin - The number of records between TimeBegin and TimeEnd will be returned.
//	TimeEnd - The number of records between TimeBegin and TimeEnd will be returned.
//return:
//	>=0- Succeed, the downloading time
//	else - consult the errocode.h
int fDlmg_GetRecordsNum(tyPackUUID PackID, time_t TimeBegin, time_t TimeEnd)
{
	if(TimeBegin>TimeEnd){
		return ILLEGAL_INPUT;
	}

	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}

//Function: Get the specific downloading records
//Parameters:
//	PackID - The records with which PackID should be returned.
//	TimeBegin - The records between TimeBegin and TimeEnd will be returned.
//	TimeEnd - The records between TimeBegin and TimeEnd will be returned.
//	pRecord - Used to return the downloading records. (The caller is responsible for mem allocation before calling)
//return:
//	>=0- Succeed, the number of records found
//	else - consult the errocode.h
int fDlmg_GetRecords(tyPackUUID PackID, time_t TimeBegin, time_t TimeEnd, stDownRecord *pRecord)
{
	if(pRecord==NULL){
		return ILLEGAL_INPUT;
	}
	if(TimeBegin>=TimeEnd){
		return ILLEGAL_INPUT;
	}
	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}

//Function: Remove all downloading records of a specific Pack
//Parameters:
//	PackID - The specific Pack ID
//return:
//	>=0 - Succeed, the number of IDs returned.
//	else - consult the errocode.h
int fDlmg_RemoveRecordsByPackID(tyPackUUID PackID)
{
	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}


