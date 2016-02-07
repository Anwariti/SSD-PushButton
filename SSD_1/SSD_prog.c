/*
 * SSD_prog.c
 *
 *  Created on: Feb 3, 2016
 *      Author: Anwar
 */

#include "SSD_interface.h"
#include "types.h"
#include "SSD_config.h"
#include "SSD_private.h"
#include"DIO_interface.h"

const u8 SSD_u8DISPInitState[SSD_u8DISPCNT]={SSD_u8DISPINITSTATE1,SSD_u8DISPINITSTATE2};
const u8 SSD_u8DISPInitVal[SSD_u8DISPCNT]={SSD_u8DISPINITVAL1,SSD_u8DISPINITVAL2};
const u8 SSD_u8DISPTYPE[SSD_u8DISPCNT]={SSD_u8DISP1TYPE,SSD_u8DISP2TYPE};



const u8 SSD_u8Pin[][SSD_u8NOPINS]={{SSD_u8DISP1SEGA,SSD_u8DISP1SEGB,SSD_u8DISP1SEGC,SSD_u8DISP1SEGD,SSD_u8DISP1SEGE,SSD_u8DISP1SEGF,SSD_u8DISP1SEGG,SSD_u8DISP1COMM},
				         	 	 	{SSD_u8DISP2SEGA,SSD_u8DISP2SEGB,SSD_u8DISP2SEGC,SSD_u8DISP2SEGD,SSD_u8DISP2SEGE,SSD_u8DISP2SEGF,SSD_u8DISP2SEGG,SSD_u8DISP2COMM}};



const u8 SSD_u8PinVAL[SSD_u8MAXDISPLAYVALUE][SSD_u8NOPINS]={ {DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8LOW},
															{DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8LOW,DIO_u8LOW,DIO_u8LOW,DIO_u8LOW},
															{DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8HIGH,DIO_u8LOW},

															{DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8LOW,DIO_u8HIGH,DIO_u8LOW},

															{DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW},
															{DIO_u8HIGH,DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW},
															{DIO_u8HIGH,DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW},

															{DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8LOW,DIO_u8LOW,DIO_u8LOW,DIO_u8LOW},

															{DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW},
															{DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW,DIO_u8HIGH,DIO_u8HIGH,DIO_u8LOW}};

static u8 SSD_u8LastVal[SSD_u8DISPCNT]={0};
/*comment:check if */
extern void SSD_voidInit(void)
{
	for(u8 local_u8loopindx=SSD_u8STARTDISPINDX ; local_u8loopindx<SSD_u8DISPCNT ; local_u8loopindx++)
	{
		if(SSD_u8DISPInitState==SSD_u8ONSTATE)
		{
			SSD_u8TurnOn(local_u8loopindx);
			SSD_u8Display(local_u8loopindx,SSD_u8DISPInitVal[local_u8loopindx]);
		}
		else
		{
			SSD_u8TurnOff(local_u8loopindx);
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern u8 SSD_u8Display(u8 Copy_u8DispIdx,u8 Copy_u8DispVAl)
{
	u8 local_u8error;
if (Copy_u8DispVAl<SSD_u8MAXDISPLAYVALUE)
{
	local_u8error=DIO_u8OK;
	SSD_u8LastVal[Copy_u8DispIdx]=Copy_u8DispVAl;

	for(u8 local_u8loopindx=SSD_u8STARTPINS ; local_u8loopindx<SSD_u8COMMINDX ; local_u8loopindx++)
	{
		if (SSD_u8DISPTYPE[Copy_u8DispIdx] == SSD_u8COMMONCATHODE) {
			DIO_u8WritePinVal(SSD_u8Pin[Copy_u8DispIdx][local_u8loopindx],
					SSD_u8PinVAL[Copy_u8DispVAl][local_u8loopindx]);
		} else {
			DIO_u8WritePinVal(SSD_u8Pin[Copy_u8DispIdx][local_u8loopindx],
					!SSD_u8PinVAL[Copy_u8DispVAl][local_u8loopindx]);
		}
	 }
	}
	else
{
	local_u8error=DIO_u8ERROR;
}
return local_u8error;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx)
{
	u8 local_u8error;
if (Copy_u8DispIdx< SSD_u8DISPCNT)
{
	local_u8error=DIO_u8OK;
	 if(SSD_u8DISPTYPE[Copy_u8DispIdx]==SSD_u8COMMONCATHODE)
	 {
		 DIO_u8WritePinVal(SSD_u8Pin[Copy_u8DispIdx][SSD_u8COMMINDX],DIO_u8LOW);
	 }
	 else
	 {
		 DIO_u8WritePinVal(SSD_u8Pin[Copy_u8DispIdx][SSD_u8COMMINDX],!DIO_u8LOW);
	 }

}
else
{
	local_u8error=DIO_u8ERROR;
}
return local_u8error;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx)
{
	u8 local_u8error;
if (Copy_u8DispIdx< SSD_u8DISPCNT)
{
	local_u8error=DIO_u8OK;
	 if(SSD_u8DISPTYPE[Copy_u8DispIdx]==SSD_u8COMMONCATHODE)
	 {
		 DIO_u8WritePinVal(SSD_u8Pin[Copy_u8DispIdx][SSD_u8COMMINDX],DIO_u8HIGH);
	 }
	 else
	 {
		 DIO_u8WritePinVal(SSD_u8Pin[Copy_u8DispIdx][SSD_u8COMMINDX],!DIO_u8HIGH);
	 }
}
	 else
{
	local_u8error=DIO_u8ERROR;
}
return local_u8error;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx,u8* Copy_u8DispVAl)
{
	u8 local_u8error;
if (Copy_u8DispIdx< SSD_u8DISPCNT)
{
	local_u8error=DIO_u8OK;
	*Copy_u8DispVAl=SSD_u8LastVal[Copy_u8DispIdx];
}
else
{
	local_u8error=DIO_u8ERROR;
}
return local_u8error;
}
////////////////////////////////////////////////////////////////////////////////














