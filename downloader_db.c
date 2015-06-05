/*
 * downloader_db.c
 *
 *  Created on: 2015-6-1
 *      Author: looeyc
 */
#include "stdio.h"
#include "sqlite3.h"
#include "debuglog.h"
#include "errocode.h"
#include "downloader_db.h"

//Function: Init the database
//Parameters:
//	pCfg - Config parameter
//	ppDBHandle - Used to return sqlite3 handler (The caller is responsible for mem allocation before calling)
//return:
//	0 - succeed
//	else - consult the errocode.h
//Note:
//	A .db file will be created if no target file found.
int fDB_Init(stDBConfig *pCfg, sqlite3 **ppDBHandle)
{
	int rt;

	if((pCfg==NULL)||(ppDBHandle==NULL)){
		return ILLEGAL_INPUT;
	}

	//打开数据库
	rt=sqlite3_open(pCfg->pDBFilePath,ppDBHandle);
	if(rt!=SQLITE_OK){
		DEBUGLOG2(LOG_ERROR,"Error, sqlite3_open failed %d: %s.",rt,sqlite3_errmsg(*ppDBHandle));
		sqlite3_close(*ppDBHandle);
		return DATABASE_FAILURE;
	}
	sqlite3_busy_timeout(*ppDBHandle,3000);

	return SUCCESS;
}
