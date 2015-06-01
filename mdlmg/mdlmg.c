/*
 * mdlmg.c
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */

#include <stdio.h>
#include "errocode.h"
#include "mdlmg.h"

//Function: Init the Dlmg module
//Parameters:
//	pDlmgCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fDlmg_Init(stDlmgCfg *pDlmgCfg)
{
	if(pDlmgCfg==NULL){
		return ILLEGAL_INPUT;
	}

	return SUCCESS;
}

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
	if(pPack==NULL){
		return ILLEGAL_INPUT;
	}

	return SUCCESS;
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

	return SUCCESS;
}

//Function: Remove a packet
//Parameters:
//	UUID - UUID of the packet to be removed
//return:
//	0 - succeed
//	else - consult the errocode.h
int fDlmg_RemovePack(tyPackUUID PackID)
{
	return SUCCESS;
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

	return SUCCESS;
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

	return SUCCESS;
}

//Function: Get the total downloading times of a specific pack
//Parameters:
//	PackID - The specific pack ID
//return:
//	>=0- Succeed, the downloading time
//	else - consult the errocode.h
int fDlmg_GetRecordNum(tyPackUUID PackID)
{
	return 0;
}

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
int fDlmg_GetRecordIDList(tyPackUUID PackID, tyRecordID *pRecordIDList, int RecordIDListLen)
{
	if(pRecordIDList==NULL){
		return ILLEGAL_INPUT;
	}

	return SUCCESS;
}

//Function: Get the specific downloading record
//Parameters:
//	RecordID - The specific downloading record ID
//	pRecord - Used to return the downloading record (The caller is responsible for mem allocation before calling)
//return:
//	0 - No record found.
//	1 - Succeed, found one.
//	else - consult the errocode.h
int fDlmg_GetRecordByID(tyRecordID RecordID, stDownRecord *pRecord)
{
	if(pRecord==NULL){
		return ILLEGAL_INPUT;
	}

	return SUCCESS;
}

//Function: Remove all downloading records of a specific Pack
//Parameters:
//	PackID - The specific Pack ID
//return:
//	>=0 - Succeed, the number of IDs returned.
//	else - consult the errocode.h
int fDlmg_RemoveRecordsByPackID(tyPackUUID PackID)
{
	return SUCCESS;
}


