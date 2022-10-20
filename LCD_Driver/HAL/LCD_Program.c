/*
include HAL layer interface 
include DIO layer
include liberary layer 

*/
#include <util/delay.h>
#include "LCD_Interface.h"

/*include libs*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */
#include "DIO_Interface.h"
#include "DIO_Private.h"


/* implementation file */

void LCD_Init (void){
	/* init sequence for 4 bit mode LCD : Page 14 in data sheet*/
	/* delay for more than 30 ms*/
	_delay_ms(50);
	
	/* write function set - writing high nibble three commands */
	LCD_voidSendCMD(INIT_VAL);    //0b0010 0000
    LCD_voidSendCMD(INIT_VAL);    //0b0010 0000
    LCD_voidSendCMD(FNSET);       //0bNF00 0000
	/* wait for more than 39 micro second */
	_delay_ms(1);
	
	/* Display ON/ OFF */
	LCD_voidSendCMD(ZERO);
	LCD_voidSendCMD(DIS_MODE);
	_delay_ms(1);
	
	/* Display clear */
	LCD_voidSendCMD(ZERO);
	LCD_voidSendCMD(DIS_CLR);	
	_delay_ms(2);
	
	/* Entry mode */
	LCD_voidSendCMD(ZERO);
	LCD_voidSendCMD(ENTR_MODE);
	
	
}	
	
void LCD_voidWriteData( u8 Copy_u8Data){
	/* RS High RW low*/
	DIO_voidSetPinValue(PORT_CTRL, RS , HIGH );
	DIO_voidSetPinValue(PORT_CTRL, RW , LOW );
	
	DIO_voidSetPortValue(PORT_DATA, Copy_u8Data );
	
	/*LATCH ENABLE PIN*/
	DIO_voidSetPinValue(PORT_CTRL, EN , HIGH );
   _delay_ms(2);
   DIO_voidSetPinValue(PORT_CTRL, EN , LOW );
   _delay_ms(2);

	
}

void LCD_voidSendCMD( u8 Copy_u8Cmd){
	/*changed rs to low to send a cmd*/
	DIO_voidSetPinValue(PORT_CTRL, RS , LOW );
	DIO_voidSetPinValue(PORT_CTRL, RW , LOW );
	
    DIO_voidSetPortValue(PORT_DATA, Copy_u8Cmd );
    
	/*LATCH ENABLE PIN*/

   DIO_voidSetPinValue(PORT_CTRL, EN , HIGH );
   _delay_ms(2);
   DIO_voidSetPinValue(PORT_CTRL, EN , LOW );
   _delay_ms(2);

}

/* implement a function to write a string */
void LCD_voidWriteString( u8* Copy_pu8String){
	/* what could go wrong*/
	
	while ( *Copy_pu8String != "\0"){
		/* write charachter, increment to the next char */
		LCD_voidWriteData( *Copy_pu8String );
		Copy_pu8String ++;
		
	}
}