/*include libs*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */
#include "DIO_Interface.h"
#include "DIO_Private.h"


/* guard */
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/* details about the LCD to ease the readability */

#define     PORT_DATA     PORTA
#define     PORT_CTRL     PORTB


/*
1- enable pin in LCD, connected on PIN 3
2- Reg. select (RS) in LCD, connected on PIN 1
3- Read and Write pin in LCD, connected on pin 2
*/
#define     RS     PIN1
#define     RW     PIN2
#define     EN     PIN3    


/* macro to init lcd, fn set reg*/
#define     FNSET         0x80

/* macro to init with zero*/
#define     ZERO          0x00

/* macro to init with one*/
#define     ONE           0x01

/* macro init for start of init 0x20 */
#define     INIT_VAL      0x20

/* Display mode macro 0b1DCB 0000  B=0  D=1  C=0 : 0b1100 0000 */
#define     DIS_MODE      0xC0

/* Display clear */
#define     DIS_CLR       0x10

/* macro for entry mode */
#define     ENTR_MODE     0x60



/*functions for the LCD driver

0- Init function
1- function to write command
2- function to write data
*/


void LCD_Init (void);

void LCD_voidWriteData( u8 Copy_u8Data);

void LCD_voidSendCMD( u8 Copy_u8Cmd);

void LCD_voidWriteString( u8* Copy_pu8String);
#endif