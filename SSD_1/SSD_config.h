/*
 * SSD_config.h
 *
 *  Created on: Feb 3, 2016
 *      Author: Anwar
 */

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_


/*******************************************************/
/**************Configuration per Display ***************/
/*******************************************************/

#define SSD_u8DISPCNT 2


/*comment:common andoe or cathode*/
#define SSD_u8DISP1TYPE SSD_u8COMMONCATHODE
#define SSD_u8DISP2TYPE SSD_u8COMMONANODE
#define SSD_u8DISP3TYPE SSD_u8COMMONCATHODE
#define SSD_u8DISP4TYPE SSD_u8COMMONCATHODE
#define SSD_u8DISP5TYPE SSD_u8COMMONCATHODE
#define SSD_u8DISP6TYPE SSD_u8COMMONCATHODE

/*comment:init value per display 0:9 */
#define SSD_u8DISPINITVAL1 SSD_u8NUM0
#define SSD_u8DISPINITVAL2 SSD_u8NUM0
#define SSD_u8DISPINITVAL3 SSD_u8NUM0
#define SSD_u8DISPINITVAL4 SSD_u8NUM0
#define SSD_u8DISPINITVAL5 SSD_u8NUM0
#define SSD_u8DISPINITVAL6 SSD_u8NUM0

/*comment:initial state on\off */
#define SSD_u8DISPINITSTATE1 SSD_u8ONSTATE
#define SSD_u8DISPINITSTATE2 SSD_u8ONSTATE
#define SSD_u8DISPINITSTATE3 SSD_u8ONSTATE
#define SSD_u8DISPINITSTATE4 SSD_u8ONSTATE
#define SSD_u8DISPINITSTATE5 SSD_u8ONSTATE
#define SSD_u8DISPINITSTATE6 SSD_u8ONSTATE


/*comment:pins connected to display1*/
#define SSD_u8DISP1SEGA DIO_u8PIN0
#define SSD_u8DISP1SEGB DIO_u8PIN1
#define SSD_u8DISP1SEGC DIO_u8PIN2
#define SSD_u8DISP1SEGD DIO_u8PIN3
#define SSD_u8DISP1SEGE DIO_u8PIN4
#define SSD_u8DISP1SEGF DIO_u8PIN5
#define SSD_u8DISP1SEGG DIO_u8PIN6
#define SSD_u8DISP1COMM DIO_u8PIN7

/*comment:pins connected to display2*/
#define SSD_u8DISP2SEGA DIO_u8PIN24
#define SSD_u8DISP2SEGB DIO_u8PIN25
#define SSD_u8DISP2SEGC DIO_u8PIN26
#define SSD_u8DISP2SEGD DIO_u8PIN27
#define SSD_u8DISP2SEGE DIO_u8PIN28
#define SSD_u8DISP2SEGF DIO_u8PIN29
#define SSD_u8DISP2SEGG DIO_u8PIN30
#define SSD_u8DISP2COMM DIO_u8PIN31



/*
#define SSD_u8DISP3COMM
#define SSD_u8DISP4COMM
#define SSD_u8DISPC5OMM
#define SSD_u8DISP6COMM

#define SSD_u8DISP3SEGA
#define SSD_u8DISP4SEGA
#define SSD_u8DISP5SEGA
#define SSD_u8DISP6SEGA

*/


#endif /* SSD_CONFIG_H_ */
