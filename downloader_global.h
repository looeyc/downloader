/*
 * downloader_global.h
 *
 *  Created on: 2015-6-1
 *      Author: looeyc
 */

#ifndef DOWNLOADER_GLOBAL_H_
#define DOWNLOADER_GLOBAL_H_

//Global status of downloader
typedef struct {
	sqlite3 *pDBHandle;	//Database handler
}stGlobalStatus;

extern stGlobalStatus GlobalStatus;

#endif /* DOWNLOADER_GLOBAL_H_ */
