/*
 * main.c
 *
 *  Created on: Feb 6, 2016
 *      Author: Anwar
 */


#include"types.h"
#include"SSD_interface.h"
#include"DIO_interface.h"

#include"delay.h"

void main(void)
{
	DIO_voidInit();
while(1)
{
/*	SSD_u8Display(0,0);
	SSD_u8Display(1,0);
	Delay(30);
	SSD_u8Display(0,1);
	SSD_u8Display(1,1);
	Delay(30);
	SSD_u8Display(0,2);
	SSD_u8Display(1,2);
	Delay(30);
	SSD_u8Display(0,3);
	SSD_u8Display(1,3);
	Delay(30);
	SSD_u8Display(0,4);
	SSD_u8Display(1,4);
	Delay(30);
	SSD_u8Display(0,5);
	SSD_u8Display(1,5);
	Delay(30);
	*/
	SSD_u8Display(0,6);
	SSD_u8Display(1,6);
	Delay(30);
	SSD_u8Display(0,7);
	SSD_u8Display(1,7);
	Delay(30);
	SSD_u8Display(0,8);
	SSD_u8Display(1,8);
	Delay(30);

	SSD_u8Display(0,9);
	Delay(30);
//	SSD_u8TurnOff(0);
	//Delay(30);
}
}
