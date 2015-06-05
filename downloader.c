/*
 * downloader.c
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include "debuglog.h"
#include "errocode.h"
#include "downloader_db.h"
#include "downloader_global.h"
#include "mposition/mposition.h"
#include "mdlmg/mdlmg.h"

//Global macro definitions
#define DATABASEFILE	"./downloader.db"

//Global definitions
stGlobalStatus GlobalStatus;

int main(int argc,char *argv[])
{
	int rt;
	stDBConfig DBConfig;
	stPositionCfg PositionCfg;
	stDlmgCfg DlmgCfg;

	DEBUGLOG0(LOG_DEBUG,"downloader started.\n");
	memset(&GlobalStatus,0,sizeof(stGlobalStatus));

	//check db file
	DEBUGLOG0(LOG_DEBUG,"Checking database.\n");
	DBConfig.pDBFilePath=DATABASEFILE;
	rt=fDB_Init(&DBConfig, &GlobalStatus.pDBHandle);
	if(rt!=SUCCESS){
		DEBUGLOG1(LOG_ERROR,"Error, fDB_Init failed %d.\n",rt);
	}

	//init mposition
	DEBUGLOG0(LOG_DEBUG,"Init mposition.\n");
	PositionCfg.pDBHandle=GlobalStatus.pDBHandle;
	PositionCfg.pGPSComDev_Path="/dev/ttyS0";
	PositionCfg.GPSComDev_Baud=9600;
	rt=fPosition_Init(&PositionCfg);
	if(rt!=SUCCESS){
		DEBUGLOG0(LOG_ERROR,"Error, fPosition_Init failed.\n");
	}

	//init mdlmg
	DEBUGLOG0(LOG_DEBUG,"Init mdlmg.\n");
	DlmgCfg.pDBHandle=GlobalStatus.pDBHandle;
	rt=fDlmg_Init(&DlmgCfg);
	if(rt!=SUCCESS){
		DEBUGLOG1(LOG_ERROR,"Error, fDlmg_Init failed %d.\n",rt);
	}

	while(1){
		//Test int fDlmg_CreatPack(stDownPack *pPack, int Option)
		{
			stDownPack DownPack;
			DownPack.PackID=1;
			DownPack.Type=APK;
			strncpy(DownPack.StorePath,"./packs/test1/android/test.apk",PATHLENMAX);
			strncpy(DownPack.IconPath,"./packs/test1/android/logo.jpg",PATHLENMAX);
			strncpy(DownPack.Descript,"This is a test apk.",DESCLENMAX);
			DownPack.ExpireDate=time(NULL);
			rt=fDlmg_CreatPack(&DownPack, DLMG_OPT_RAPLACE_IF_EXIST);
			if(rt!=SUCCESS){
				DEBUGLOG1(LOG_ERROR,"Error, fDlmg_CreatPack failed %d.\n",rt);
			}

			DownPack.PackID=2;
			DownPack.Type=APR;
			strncpy(DownPack.StorePath,"./packs/test1/ios/test.apr",PATHLENMAX);
			strncpy(DownPack.IconPath,"./packs/test1/ios/logo.jpg",PATHLENMAX);
			strncpy(DownPack.Descript,"This is a test apr.",DESCLENMAX);
			DownPack.ExpireDate=time(NULL);
			rt=fDlmg_CreatPack(&DownPack, DLMG_OPT_RAPLACE_IF_EXIST);
			if(rt!=SUCCESS){
				DEBUGLOG1(LOG_ERROR,"Error, fDlmg_CreatPack failed %d.\n",rt);
			}
		}

		sleep(1000);
	}
}



