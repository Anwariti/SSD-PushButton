/*
 * Matrix_prog.c
 *
 *  Created on: Feb 11, 2016
 *      Author: Anwar
 */


#include "types.h"
#include "DIO_interface.h"
#include "Matrix_config.h"
void Matrx_voidDisp(u8 copy_Indx);

u8 Mtx_u8PINS[2][8]={
{MTRX_ROW0,MTRX_ROW1,MTRX_ROW2,MTRX_ROW3,MTRX_ROW4,MTRX_ROW5,MTRX_ROW6,MTRX_ROW7}
,{MTRX_COL0,MTRX_COL1,MTRX_COL2,MTRX_COL4,MTRX_COL4,MTRX_COL5,MTRX_COL6,MTRX_COL7}
};

/*rows then columns*/
/*5 letters, rows values,cols values*/

u8 Mtx_u8Val[2][8]=
{

{0,1,1,1,1,1,1,1},
{1,0,0,0,0,0,1,1}

};

void Mtx_voidDisp(u8 copy_Indx)
{
	u8 i;
for (i=0;i<8;i++)
	{
	DIO_u8WritePinVal(Mtx_u8PINS[0][i],Mtx_u8Val[0][i]);
	DIO_u8WritePinVal(Mtx_u8PINS[1][i],Mtx_u8Val[1][i]);
	}
}
