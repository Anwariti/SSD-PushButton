/*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: Anwar
 */

#include "types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_private.h"
////////////////////////////////////////////////////////////////////////////////////////////////
static volatile u8* const DIO_u8PORTArr[] =
		{ DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD };
 static volatile u8* const  DIO_u8PINArr[] = { DIO_u8PINA, DIO_u8PINB, DIO_u8PINC, DIO_u8PIND };

 static volatile u8*  const DIO_u8DDRArr[] = { DIO_u8DDRA, DIO_u8DDRB, DIO_u8DDRC, DIO_u8DDRD };

//////////////////////////////////////////////////////////////////////////////////////////////
/*comment!:read port value*/
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrVal) {
	u8 local_u8Error;
if(Copy_u8PortIdx >NO_PORTS)
{
	local_u8Error = DIO_u8ERROR;
}
else
{
	local_u8Error = DIO_u8OK;
	*Copy_u8PtrVal=*DIO_u8PINArr[Copy_u8PortIdx];
}

	return local_u8Error;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/*comment!:write to port*/
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal) {
	u8 local_u8Error;
	if(Copy_u8PortIdx >NO_PORTS)
	{
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*DIO_u8PORTArr[Copy_u8PortIdx]=Copy_u8PortVal;
	}
	return local_u8Error;
}
////////////////////////////////////////////////////////////////////////////
extern void DIO_voidInit(void) {
	*DIO_u8DDRArr[DIO_u8PORT0] = DIO_u8PORTA_DIR;
	*DIO_u8DDRArr[DIO_u8PORT1] = DIO_u8PORTB_DIR;
	*DIO_u8DDRArr[DIO_u8PORT2] = DIO_u8PORTC_DIR;
	*DIO_u8DDRArr[DIO_u8PORT3] = DIO_u8PORTD_DIR;

	*DIO_u8PORTArr[DIO_u8PORT0] = (*DIO_u8PORTArr[DIO_u8PORT0] & ~DIO_u8PORTA_DIR) | (DIO_u8PORTA_DIR & DIO_u8PORTA_VAL); //zeroing must happen to output before oring
	*DIO_u8PORTArr[DIO_u8PORT1] = (*DIO_u8PORTArr[DIO_u8PORT1] & ~DIO_u8PORTB_DIR) | (DIO_u8PORTB_DIR & DIO_u8PORTB_VAL);
	*DIO_u8PORTArr[DIO_u8PORT2] = (*DIO_u8PORTArr[DIO_u8PORT2] & ~DIO_u8PORTC_DIR) | (DIO_u8PORTC_DIR & DIO_u8PORTC_VAL);
	*DIO_u8PORTArr[DIO_u8PORT3] = (*DIO_u8PORTArr[DIO_u8PORT3] & ~DIO_u8PORTD_DIR) | (DIO_u8PORTD_DIR & DIO_u8PORTD_VAL);
}
///////////////////////////////////////////////////////////////////////////////////////

extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx, u8 Copy_u8PinVal) {
	u8 local_u8Error;
	u8 local_u8Portno = Copy_u8PinIdx / PIN_PER_PORT;
	u8 local_u8Pinno = Copy_u8PinIdx % PIN_PER_PORT;
	if(Copy_u8PinIdx >NO_PINS)
	{
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*DIO_u8PORTArr[local_u8Portno]=ASSIGNBIT(*DIO_u8PORTArr[local_u8Portno],Copy_u8PinVal,local_u8Pinno);
	}
	return local_u8Error;
}

/////////////////////////////////////////////////////////////////////////
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx, u8* Copy_u8PtrVal) {
	u8 local_u8Error;
	u8 local_u8Portno = Copy_u8PinIdx / PIN_PER_PORT;
	u8 local_u8Pinno = Copy_u8PinIdx % PIN_PER_PORT;
	if(Copy_u8PinIdx >NO_PINS)
	{
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*Copy_u8PtrVal = GETBIT(*DIO_u8PINArr[local_u8Portno], local_u8Pinno);
	}
	return local_u8Error;
}
///////////////////////////////////////////////////////////////////////////////
/*comment!:write port direction*/
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir) {
	u8 local_u8Error;
	if(Copy_u8PortIdx >NO_PORTS)
	{
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*DIO_u8DDRArr[Copy_u8PortIdx]=Copy_u8PortDir;
	}
	return local_u8Error;
}
//////////////////////////////////////////////////////////////////////////////////
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PortDir) {
	u8 local_u8Error;
	if(Copy_u8PortIdx >NO_PORTS)
	{
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*Copy_u8PortDir=*DIO_u8DDRArr[Copy_u8PortIdx];
	}
	return local_u8Error;
}
////////////////////////////////////////////////////////////////////////////////////
/*comment!:read pin direction*/
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PinDir) {
	u8 local_u8Error;
	u8 local_u8Portno = Copy_u8PinIdx / PIN_PER_PORT;
	u8 local_u8Pinno = Copy_u8PinIdx % PIN_PER_PORT;
	if(Copy_u8PinIdx >NO_PINS)
	{
		local_u8Error = DIO_u8ERROR;
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*Copy_u8PinDir = GETBIT(*DIO_u8DDRArr[local_u8Portno], local_u8Pinno);
	}

	return local_u8Error;
}
//////////////////////////////////////////////////////////////////////////////////
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
	u8 local_u8Error;
	u8 local_u8Portno = Copy_u8PinIdx / PIN_PER_PORT;
	u8 local_u8Pinno = Copy_u8PinIdx % PIN_PER_PORT;
	if(Copy_u8PinIdx >NO_PINS)
	{
		local_u8Error = DIO_u8ERROR;
	}
	else
	{
		local_u8Error = DIO_u8OK;
		*DIO_u8DDRArr[local_u8Portno]=ASSIGNBIT(*DIO_u8PORTArr[local_u8Portno],Copy_u8PinDir,local_u8Pinno);
	}
	return local_u8Error;
}

