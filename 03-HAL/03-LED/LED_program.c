/*
 * LED_program.c
 *
 *  Created on: Jan 2, 2021
 *      Author: Mohamed Taha
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidON(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case 0 : 	RCC_voidEnableClock(RCC_APB2,2); break; /* Enable Clock for GPIOA on the BUS APB2 */
	case 1 :	RCC_voidEnableClock(RCC_APB2,3); break; /* Enable Clock for GPIOB on the BUS APB2 */
	case 2 : 	RCC_voidEnableClock(RCC_APB2,4); break; /* Enable Clock for GPIOC on the BUS APB2 */
	default : break;
	}
	MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin , GPIO_HIGH);
}

void LED_voidOFF(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case 0 : 	RCC_voidEnableClock(RCC_APB2,2); break; /* Enable Clock for GPIOA on the BUS APB2 */
	case 1 :	RCC_voidEnableClock(RCC_APB2,3); break; /* Enable Clock for GPIOB on the BUS APB2 */
	case 2 : 	RCC_voidEnableClock(RCC_APB2,4); break; /* Enable Clock for GPIOC on the BUS APB2 */
	default : break;
	}
	MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin , GPIO_LOW);
}

void LED_voidTOGGLE(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case 0 : 	RCC_voidEnableClock(RCC_APB2,2); break; /* Enable Clock for GPIOA on the BUS APB2 */
	case 1 :	RCC_voidEnableClock(RCC_APB2,3); break; /* Enable Clock for GPIOB on the BUS APB2 */
	case 2 : 	RCC_voidEnableClock(RCC_APB2,4); break; /* Enable Clock for GPIOC on the BUS APB2 */
	default : break;
	}
	MGPIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin , GPIO_HIGH);
	u16 w = 500;
	u16 i = 0;
	for(i = 0 ; i < w ; i++)//delay
	{
		for(u16 j = 0 ; j < w ; j++)
		{
			asm("NOP");
		}
	}
	MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin , GPIO_LOW);
	for(i = 0 ; i < w ; i++)
	{
		for(u16 j = 0 ; j < w ; j++)
		{
			asm("NOP");
		}
	}

}
