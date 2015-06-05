/*
 * mposition.c
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */

#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <pthread.h>
#include "debuglog.h"
#include "errocode.h"
#include "mposition.h"

stPositionStatus PositionStatus;

//Function: Init the position module
//Parameters:
//	pCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fPosition_Init(stPositionCfg *pCfg)
{
	int rt;
	char pSql[512];
	char *pErrMsg=NULL;

	if(pCfg==NULL){
		return ILLEGAL_INPUT;
	}

	memset(&PositionStatus,0,sizeof(stPositionStatus));

	//Init database table
	if(pCfg->pDBHandle==NULL){
		return ILLEGAL_INPUT;
	}
	PositionStatus.pDBHandle=pCfg->pDBHandle;
	//创建表position
	snprintf(pSql,512,"CREATE TABLE IF NOT EXISTS position (\
		SYSTEMID			INTEGER NOT NULL, \
		STATE				INTEGER NOT NULL, \
		POSITION_EW_F		TEXT, \
		POSITION_EW_V		DOUBLE, \
		POSITION_NS_F		TEXT, \
		POSITION_NS_V		DOUBLE, \
		TIME				INTEGER, \
		PRIMARY KEY (SYSTEMID)); \
		");
	rt=sqlite3_exec(PositionStatus.pDBHandle, pSql, 0, 0, &pErrMsg);
	if(rt!=SQLITE_OK){
		DEBUGLOG2(3,"Error, CREATE TABLE position failed %d: %s.\n",rt,pErrMsg);
		return DATABASE_FAILURE;
	}

	//初始化position表
	snprintf(pSql,512,"INSERT OR REPLACE INTO position VALUES (%d,%d,'%s',%f,'%s',%f,%d);",0,0,"E",0.0,"N",0.0,0);
	rt=sqlite3_exec(PositionStatus.pDBHandle, pSql, 0, 0, &pErrMsg);
	if(rt!=SQLITE_OK){
		DEBUGLOG2(3,"Error, init table position failed %d: %s.\n",rt,pErrMsg);
		return DATABASE_FAILURE;
	}

	//开串口服务线程

	return SUCCESS;
}

//Function: Get current position and time
//Parameters:
//	pPosition - Used to return position data (The caller is responsible for mem allocation before calling)
//return:
//	0 - succeed, both position and time are available
//	1 - not all succeed, only time is available
//  2 - failed, neither position nor time is available, due to lost of satellite connection
//	else - consult the errocode.h
int fPosition_GetCurrentPosition(stPosition *pPosition)
{
	if(pPosition==NULL){
		return ILLEGAL_INPUT;
	}

	DEBUGLOG0(3,"Error, this func has not been implemented yet.\n");
	return FAILURE;
}



