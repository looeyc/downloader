/*
 * downloader_db.h
 *
 *  Created on: 2015-6-1
 *      Author: looey
 */

#ifndef DOWNLOADER_DB_H_
#define DOWNLOADER_DB_H_

#include "sqlite3.h"

//Config parameters for fDB_Init
typedef struct{
	char *pDBFilePath;//The path the .db file
}stDBConfig;

//Function: Init the database
//Parameters:
//	pCfg - Config parameter
//	ppDBHandle - Used to return sqlite3 handler (The caller is responsible for mem allocation before calling)
//return:
//	0 - succeed
//	else - consult the errocode.h
//Note:
//	A .db file will be created if no target file found.
int fDB_Init(stDBConfig *pCfg, sqlite3 **ppDBHandle);

#endif /* DOWNLOADER_DB_H_ */
