/*
 * mposition.c
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */

#include <stdio.h>
#include "errocode.h"
#include "mposition.h"

//Function: Init the position module
//Parameters:
//	pCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fPosition_Init(stPositionCfg *pCfg)
{
	if(pCfg==NULL){
		return ILLEGAL_INPUT;
	}

	return SUCCESS;
}

//Function: Get current position
//Parameters:
//	pPosition - Used to return position data (The caller is responsible for mem allocation before calling)
//return:
//	0 - success
//	1 - Failed
//	else - consult the errocode.h
int fPosition_GetPos(stPosition *pPosition)
{
	if(pPosition==NULL){
		return ILLEGAL_INPUT;
	}

	return 1;
}

//Function: Get current GPS time
//Parameters:
//	pTime - Used to return current time (The caller is responsible for mem allocation before calling)
//return:
//	0 - success
//	1 - Failed
//	else - consult the errocode.h
int fPosition_GetTime(time_t *pTime)
{
	if(pTime==NULL){
		return ILLEGAL_INPUT;
	}

	return 1;
}



