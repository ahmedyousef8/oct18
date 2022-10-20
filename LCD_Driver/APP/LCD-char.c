/* includes */

#include <util/delay.h>

#include "LCD_Interface.h"

/*include libs*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */
#include "DIO_Interface.h"
#include "DIO_Private.h"

/* the program */
int main{
	
	/* the direction of the pins and ports */
	
	DIO_voidSetPinDir(PORT_CTRL,RS,OUTPUT);
	DIO_voidSetPinDir(PORT_CTRL,RW,OUTPUT);
	DIO_voidSetPinDir(PORT_CTRL,EN,OUTPUT);
	
    DIO_voidSetPortDir(PORT_DATA,OUTPUT);
	
	u8* name_var[] = "YOUR_NAME";
	
	LCD_Init();
	while(1){
		/* program to write your name */
		LCD_voidWriteString( name_var );
		
		
	}
		
		
		
		return 0;
	}
}