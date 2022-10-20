#ifndef _BIT_MATH_H
#define _BIT_MATH_H

/*this is a file to help in pin 
operation on a bit wise level */
/* setting the pin with given pin number to be 1 in port reg */
#define SET_BIT(PORT_REG,PIN_NO)  (PORT_REG |= (1 << PIN_NO))
#define CLR_BIT(PORT_REG,PIN_NO)  (PORT_REG &=~(1 << PIN_NO))
#define TGL_BIT(PORT_REG,PIN_NO)  (PORT_REG ^=(1 << PIN_NO))

#define GET_BIT(PORT_REG,PIN_NO)  ((PORT_REG>> PIN_NO)&1)





#endif
