#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


/*function prototypes         */
/* what are the dio functions?*/

/*Set Value of Direction of Port or Pin to Input or Output*/
void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir);
void DIO_voidSetPortDir(u8 Copy_u8Port,u8 Copy_u8Dir);

/*Set value of port or pin HIGH or LOW*/
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir);
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Dir);

/*Get Value of Pin or Port if it is HIGH or LOW*/
u8 DIO_u8GetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin);
u8 DIO_u8GetPortValue (u8 Copy_u8Port);



/* variable used in the functions */



#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6 
#define PIN7 7


#define HIGH 1
#define LOW 0


#define INPUT 0
#define OUTPUT 1
#endif