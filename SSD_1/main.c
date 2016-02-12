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

////////////////////////////////////////////////////////////
#define SWITCH_u8RELEASED 0
#define SWITCH_u8DEBOUNCING 1
#define SWITCH_u8PRESSED 2
///////////////////////////////////////////////////////////////
#define SWITCH_CHECK 1

#if SWITCH_CHECK==0
#define SWITCH_FN			SwitchSingle_u8Check(11)
#define SWITCH_LASTDELAY	Delay(3)
#elif  SWITCH_CHECK==1
#define SWITCH_FN			SwitchMulti_u8Check(11)
#define SWITCH_LASTDELAY	Delay(10)
#endif

/////////////////////////////////////////////////////////////////


u8 SwitchMulti_u8Check(u8 Copy_u8PinIndx);
u8 SwitchSingle_u8Check(u8 Copy_u8PinIndx);
//void Segments(void);
void letterA(void);
void letterN(void);
void letterR(void);
void letterW(void);



///////////////////////////////////////////////////////////
u8 x =10U;
u64 counter=123;

void (*p[5])(void);


//////////////////////////////////////////////
int main(void)
{
	DIO_voidInit();
SSD_voidInit();
p[0] = letterA;
p[1] = letterN;
p[2] = letterW;
p[3] = letterA;
p[4] = letterR;
	//Delay(x);

	while(1)
{



		DIO_u8WritePortVal(3,0b00000000);
	Delay(1000UL);
	for(u8 ii=0;ii<5;ii++)
	{
		DIO_u8WritePortVal(3,0b00000000);
		Delay(1000UL);
		for(u8 i=1;i<50;i++)
	{
	(*p[ii])();
	}
		}

}
return 0;
}

/////////////////////////////////////////////////////

void Segments(void){
	u8 counter0,counter1,counter2,counter3;
	counter0=(counter%10);
	counter1=(counter%100)/10;
	counter2=(counter%1000)/100;
	counter3=(counter%10000)/1000;
/********************************************/
//	DIO_u8WritePinVal(25,1); // calculationg fn time

//	u8 yy= SWITCH_FN ;  //(7ms 3shan btarga3 l al main :D)  (5ms blzabt :D )  //87.5 us blzabt :D in multi

//	DIO_u8WritePinVal(25,0); //calculating time fn
/*************************************/
	//if (yy==SWITCH_u8PRESSED)
//	{
	//counter++;
//	}
	//else{};

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

//			SWITCH_LASTDELAY;
}

//////////////////////////////////////////////////////
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
///////////////////////////////////////////////////
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
Delay(10UL);
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

/////////////////////////////////////////////////////////////////////////
void letterA(void)
{
	/***letter A****/
	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11111011); //row //low //
	DIO_u8WritePortVal(3,0b00011000);   //cols //high //
	Delay(5);


	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11110111); //row //low //
	DIO_u8WritePortVal(3,0b00100100);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11101111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11011111); //row //low //
	DIO_u8WritePortVal(3,0b01111110);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b10111111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b01111111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);

}
////////////////////////////////////////////////////////////////////
void letterN(void)
{
	/***letter A****/
	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11111011); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);


	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11110111); //row //low //
	DIO_u8WritePortVal(3,0b01000110);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11101111); //row //low //
	DIO_u8WritePortVal(3,0b01001010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11011111); //row //low //
	DIO_u8WritePortVal(3,0b01010010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b10111111); //row //low //
	DIO_u8WritePortVal(3,0b01100010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b01111111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);
}
////////////////////////////////////////////////////////////
void letterR(void)
{
	/***letter A****/
	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11111011); //row //low //
	DIO_u8WritePortVal(3,0b00011110);   //cols //high //
	Delay(5);


	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11110111); //row //low //
	DIO_u8WritePortVal(3,0b00100010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11101111); //row //low //
	DIO_u8WritePortVal(3,0b00100010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11011111); //row //low //
	DIO_u8WritePortVal(3,0b00011110);   //cols //high //

	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b10111111); //row //low //
	DIO_u8WritePortVal(3,0b00010010);   //cols //high //

	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b01111111); //row //low //
	DIO_u8WritePortVal(3,0b00100010);   //cols //high //

	Delay(5);
}

void letterW(void)
{
	/***letter A****/
	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11111011); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);


	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11110111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11101111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //
	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b11011111); //row //low //
	DIO_u8WritePortVal(3,0b01011010);   //cols //high //

	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b10111111); //row //low //
	DIO_u8WritePortVal(3,0b01100110);   //cols //high //

	Delay(5);

	DIO_u8WritePortVal(3,0b00000000); //switch all off
	DIO_u8WritePortVal(2,0b01111111); //row //low //
	DIO_u8WritePortVal(3,0b01000010);   //cols //high //

	Delay(5);
}
