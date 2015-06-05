/*
 * mposition.h
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */

#ifndef MPOSITION_H_
#define MPOSITION_H_

#include <time.h>
#include "sqlite3.h"

//Macro const definition
#define PATHLENMAX		128
#define POSITION_LOST	0
#define POSITION_OK		1

//The config parameter of position module
typedef struct{
	sqlite3 *pDBHandle;		//Database handler
	char *pGPSComDev_Path;	//The COM device path of the GPS module
	int GPSComDev_Baud;		//Baudrate of the COM device
}stPositionCfg;

//Position struct
typedef struct{
	char	EW_Flag;	//'E'、'W', Longitude flag
	double  EW_Value;	//'E'、'W', Longitude value
	char 	NS_Flag; 	//'N'、'S', Latitude flag
	double  NS_Value;	//'N'、'S', Latitude value
	time_t  Time;		//The time when getting the position
}stPosition;

//Module status
typedef struct{
	sqlite3 *pDBHandle;		//Database handler
}stPositionStatus;
extern stPositionStatus PositionStatus;

//Function: Init the position module
//Parameters:
//	pCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fPosition_Init(stPositionCfg *pCfg);

//Function: Get current position and time
//Parameters:
//	pPosition - Used to return position data (The caller is responsible for mem allocation before calling)
//return:
//	0 - succeed, both position and time are available
//	1 - not all succeed, only time is available
//  2 - failed, neither position nor time is available, due to lost of satellite connection
//	else - consult the errocode.h
int fPosition_GetCurrentPosition(stPosition *pPosition);

#endif /* MPOSITION_H_ */


