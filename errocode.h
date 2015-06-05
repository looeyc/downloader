/*
 * errocode.h
 *
 *  Created on: 2015-5-30
 *      Author: looeyc
 */

#ifndef ERROCODE_H_
#define ERROCODE_H_

#define SUCCESS 			0x00000000 	// 0，Succeed
#define FAILURE				0xFFFFFFFF	//-1，General error, no specific reason
#define ILLEGAL_INPUT		0xFFFFFFFE	//-2，Illegal input parameters
#define OBJECT_NOT_FOUND	0xFFFFFFFD	//-3, Target object not found
#define DATABASE_FAILURE	0xFFFFFFFC	//-4, Target object not found

#endif /* ERROCODE_H_ */
