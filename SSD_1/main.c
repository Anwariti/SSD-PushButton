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

#define SWITCH_u8RELEASED 0
#define SWITCH_u8DEBOUNCING 1
#define SWITCH_u8PRESSED 2

u8 SwitchMulti_u8Check(u8 Copy_u8PinIndx);
u8 SwitchSingle_u8Check(u8 Copy_u8PinIndx);


u8 x =10U;
int main(void)
{
	DIO_voidInit();
	SSD_voidInit();
	Delay(x);
	u64 counter=123;
	u8 counter0,counter1,counter2,counter3;

	while(1)
{
counter0=(counter%10);
counter1=(counter%100)/10;
counter2=(counter%1000)/100;
counter3=(counter%10000)/1000;

u8 yy= SwitchSingle_u8Check(11);

if (yy==SWITCH_u8PRESSED)
{
counter++;
}
else{};

		SSD_u8TurnOff(0);
		SSD_u8TurnOff(1);
		SSD_u8TurnOff(2);
		SSD_u8TurnOff(3);

		SSD_u8Display(0,counter3);
		SSD_u8TurnOn(0);
		Delay(10);



		SSD_u8TurnOff(0);
		SSD_u8TurnOff(1);
		SSD_u8TurnOff(2);
		SSD_u8TurnOff(3);

		SSD_u8Display(1,counter2);
		SSD_u8TurnOn(1);
		Delay(10);

		SSD_u8TurnOff(0);
		SSD_u8TurnOff(1);
		SSD_u8TurnOff(2);
		SSD_u8TurnOff(3);

		SSD_u8Display(2,counter1);
		SSD_u8TurnOn(2);
		Delay(10);


		SSD_u8TurnOff(0);
		SSD_u8TurnOff(1);
		SSD_u8TurnOff(2);
		SSD_u8TurnOff(3);

		SSD_u8Display(3,counter0);
		SSD_u8TurnOn(3);
		Delay(10);


}
return 0;
}


u8 SwitchMulti_u8Check(u8 Copy_u8PinIndx)
{

static u8 Switch_State=SWITCH_u8RELEASED;
static u8 local_PinReading=0;
u8 local_PinReading2=0;
switch (Switch_State)
{
case SWITCH_u8RELEASED:
DIO_u8ReadPinVal(Copy_u8PinIndx,&local_PinReading);
if(local_PinReading==DIO_u8HIGH)
{Switch_State=SWITCH_u8DEBOUNCING;}
else
{Switch_State=SWITCH_u8RELEASED;}
break;

case SWITCH_u8DEBOUNCING:
Delay(50UL);
DIO_u8ReadPinVal(Copy_u8PinIndx,&local_PinReading2);
if(local_PinReading2==DIO_u8HIGH)
{Switch_State=SWITCH_u8PRESSED;}
else
{Switch_State=SWITCH_u8RELEASED;}
break;

case SWITCH_u8PRESSED:
Switch_State=SWITCH_u8RELEASED;
break;
}

return Switch_State;
}


u8 SwitchSingle_u8Check(u8 Copy_u8PinIndx)
{

static u8 Switch_State=SWITCH_u8RELEASED;
u8 local_PinReading=0;
u8 local_PinReading2=0;
u8 local_PinReading3=0;

switch (Switch_State)
{
case SWITCH_u8RELEASED:
DIO_u8ReadPinVal(Copy_u8PinIndx,&local_PinReading);
Delay(5UL);
DIO_u8ReadPinVal(Copy_u8PinIndx,&local_PinReading2);
if(local_PinReading==DIO_u8HIGH && local_PinReading==local_PinReading2)
{Switch_State=SWITCH_u8DEBOUNCING;}
else {Switch_State=SWITCH_u8RELEASED;}
break;

case SWITCH_u8DEBOUNCING:
DIO_u8ReadPinVal(Copy_u8PinIndx,&local_PinReading3);
if(local_PinReading3==DIO_u8HIGH){Switch_State=SWITCH_u8DEBOUNCING;}
else {Switch_State=SWITCH_u8PRESSED;}
break;

case SWITCH_u8PRESSED:
Switch_State=SWITCH_u8RELEASED;
}
return Switch_State;
 }


/*Delay(30);
	SSD_u8Display(0,0);
	SSD_u8Display(1,0);
	//Delay(30);
	SSD_u8Display(0,1);
	SSD_u8Display(1,1);
	Delay(30);
	SSD_u8Display(0,2);
	SSD_u8Display(1,2);
	Delay(30);
//////////////////////////
	//SSD_u8TurnOff(0);
	//SSD_u8TurnOff(1);
//////////////////////////////////
	SSD_u8Display(0,3);
	SSD_u8Display(1,3);
	Delay(30);
	SSD_u8Display(0,4);
	SSD_u8Display(1,4);
	Delay(30);
	//////////////////////////////
	//SSD_u8TurnOn(0);
	SSD_u8TurnOn(1);
	SSD_u8Display(0,5);
	SSD_u8Display(1,5);
	Delay(30);
	SSD_u8Display(0,6);
	SSD_u8Display(1,6);
	Delay(30);

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
	SSD_u8Display(1,9);
	Delay(30);
//	SSD_u8TurnOff(0);
	//Delay(30);
*/



//SSD_u8TurnOff(1);
//SSD_u8TurnOn(0);
//SSD_u8Display(0,2);
//SSD_u8Display(1,1);
//Delay(25);
//SSD_u8TurnOff(0);
//Delay(25);
/*
SSD_u8TurnOff(0);
SSD_u8TurnOn(1);
SSD_u8Display(0,2);
SSD_u8Display(1,1);
*/
//Delay(25);
