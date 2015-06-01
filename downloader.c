/*
 * downloader.c
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */
#include <stdio.h>
#include <unistd.h>
#include "debuglog.h"
#include "mposition/mposition.h"
#include "mdlmg/mdlmg.h"

int main(int argc,char *argv[])
{
	int rt;
	stPositionCfg PositionCfg;

	DEBUGLOG0(LOG_DEBUG,"downloader started.\n");

	//check db file
	DEBUGLOG0(LOG_DEBUG,"Checking database.\n");

	//init mposition
	DEBUGLOG0(LOG_DEBUG,"Init mposition.\n");
	PositionCfg.pGPSComDev_Path="/dev/ttyS0";
	PositionCfg.GPSComDev_Baud=9600;
	rt=fPosition_Init(&PositionCfg);
	if(rt!=0){
		DEBUGLOG0(LOG_ERROR,"Error, fPosition_Init failed.\n");
	}

	//init mdlmg
	DEBUGLOG0(LOG_DEBUG,"Init mdlmg.\n");

	while(1){
		sleep(1000);
	}
}
