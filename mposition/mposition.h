/*
 * mposition.h
 *
 *  Created on: 2015-5-31
 *      Author: looeyc
 */

#ifndef MPOSITION_H_
#define MPOSITION_H_

#include <time.h>

//Macro const definition
#define PATHLENMAX			128

//The config parameter of position module
typedef struct{
  char *pGPSComDev_Path;	//The COM device path of the GPS module
  int GPSComDev_Baud;		//Baudrate of the COM device
}stPositionCfg;

//Position struct
typedef struct{
  char	EW_Flag;	//'E'、'W', Longitude flag
  double  EW_Value;	//'E'、'W', Longitude value
  char NS_Flag; 	//'N'、'S', Latitude flag
  double  NS_Value;	//'N'、'S', Latitude value
}stPosition;

//Function: Init the position module
//Parameters:
//	pCfg - Config parameter
//return:
//	0 - success
//	else - consult the errocode.h
int fPosition_Init(stPositionCfg *pCfg);

//Function: Get current position
//Parameters:
//	pPosition - Used to return position data (The caller is responsible for mem allocation before calling)
//return:
//	0 - success
//	1 - Failed
//	else - consult the errocode.h
int fPosition_GetPos(stPosition *pPosition);

//Function: Get current GPS time
//Parameters:
//	pTime - Used to return current time (The caller is responsible for mem allocation before calling)
//return:
//	0 - success
//	1 - Failed
//	else - consult the errocode.h
int fPosition_GetTime(time_t *pTime);

#endif /* MPOSITION_H_ */


