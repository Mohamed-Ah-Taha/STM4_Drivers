/*
 * LED_interface.h
 *
 *  Created on: Jan 2, 2021
 *      Author: Mohamed Taha
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
/*	Port ID	*/
#define 	GPIOA	  	0
#define 	GPIOB	  	1
#define 	GPIOC	  	2
/*	Pin ID	*/
#define		PIN0	  	0
#define		PIN1	  	1
#define		PIN2	  	2
#define		PIN3	  	3
#define		PIN4	  	4
#define		PIN5	  	5
#define		PIN6	  	6
#define		PIN7	  	7
#define		PIN8	  	8
#define		PIN9	  	9
#define		PIN10	  	10
#define		PIN11	  	11
#define		PIN12	  	12
#define		PIN13	  	13
#define		PIN14	  	14
#define		PIN15	  	15

void LED_voidON(u8 Copy_u8Port , u8 Copy_u8Pin);

void LED_voidOFF(u8 Copy_u8Port , u8 Copy_u8Pin);

void LED_voidTOGGLE(u8 Copy_u8Port , u8 Copy_u8Pin);



#endif /* LED_INTERFACE_H_ */
