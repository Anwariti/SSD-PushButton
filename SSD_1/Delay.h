/*
 * Delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: Anwar
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "Delay_config.h"
//#include "types.h"

#define Delay(n) do{ u32 i; for(i=1; i <= ((n*DELAY_u32SYSCLOCK)/1000) ;i++) {  __asm__("NOP"); }  }while(0)

#endif /* DELAY_H_ */
