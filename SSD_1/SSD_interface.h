/*
 * SSD_interface.h
 *
 *  Created on: Feb 3, 2016
 *      Author: Anwar
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "types.h"

/*******************************************************/
/**************** Public Definitions *******************/
/*******************************************************/

/*comment:numbers to be displayed*/
#define SSD_u8NUM0 0
#define SSD_u8NUM1 1
#define SSD_u8NUM2 2
#define SSD_u8NUM3 3
#define SSD_u8NUM4 4
#define SSD_u8NUM5 5
#define SSD_u8NUM6 6
#define SSD_u8NUM7 7
#define SSD_u8NUM8 8
#define SSD_u8NUM9 9

/*comment:7seg index*/
#define SSD_u8DISP1 0
#define SSD_u8DISP2 1
#define SSD_u8DISP3 2
#define SSD_u8DISP4 3
#define SSD_u8DISP5 4
#define SSD_u8DISP6 5


/*comment:7segment type*/
#define SSD_u8COMMONANODE 0
#define SSD_u8COMMONCATHODE 1

/*comment:first 7seg state*/
#define SSD_u8ONSTATE 1
#define SSD_u8OFFSTATE 0

/*******************************************************/
/***********************Public Functions ***************/
/*******************************************************/

extern u8 SSD_u8Display(u8 Copy_u8DispIdx,u8 Copy_u8DispVAl);

extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx,u8* Copy_u8DispVAl);

extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx);

extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx);

extern void SSD_voidInit(void);

#endif /* SSD_INTERFACE_H_ */
