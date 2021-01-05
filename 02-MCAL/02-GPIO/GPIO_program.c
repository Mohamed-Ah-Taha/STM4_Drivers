/***************************************************/
/* Author   : Mohamed Taha                         */
/* Version  : V01                                  */
/* Date     : 29 DEC 2020                          */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"

/* MCAL GPIO */

void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
					/* Checking on the Pin number since we have 2 Registers for the Port (CRL and CRH) */		
					if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7) //CRL Register has 8 Pins from Pin0 to Pin7
					{
						/* Resetting the bits of the pin that the user choose to set direction of */
						GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4));/* Here i need to first reset the mode which is there already , put the register is having 8 pins , so if i want to clear the 4 bits of a specific mode use clear bit &= ~(1111). Then i have to use shift left to go to the specific pin and here each pin has 4 bits so i must use pin_number*4 */
						
						/* Setting the bits */
						GPIOA_CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));/* Here we are using SET_BIT technique */
					}
					
					else if(Copy_u8Pin > 7 && Copy_u8Pin <= 15) //CRH Register has 8 Pins from Pin8 to Pin15
					{
						Copy_u8Pin = Copy_u8Pin - 8; //15*4 = 60 wrong so i need (15-8)*4 = 28 right
						/* Resetting the bits of the pin that the user choose to set direction of */
						GPIOA_CRH &= ~((0b1111) << ((Copy_u8Pin) * 4));
						
						/* Setting the bits */
						GPIOA_CRH |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
					}
					else
					{
						/* Return Error */
					}
					break ;
		case GPIOB :
							/* Checking on the Pin number since we have 2 Registers for the Port (CRL and CRH) */		
					if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7) //CRL Register has 8 Pins from Pin0 to Pin7
					{
						/* Resetting the bits of the pin that the user choose to set direction of */
						GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4));/* Here i need to first reset the mode which is there already , put the register is having 8 pins , so if i want to clear the 4 bits of a specific mode use clear bit &= ~(1111). Then i have to use shift left to go to the specific pin and here each pin has 4 bits so i must use pin_number*4 */
						
						/* Setting the bits */
						GPIOB_CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));/* Here we are using SET_BIT technique */
					}
					
					else if(Copy_u8Pin > 7 && Copy_u8Pin <= 15) //CRH Register has 8 Pins from Pin8 to Pin15
					{
						Copy_u8Pin = Copy_u8Pin - 8; //15*4 = 60 wrong so i need (15-8)*4 = 28 right
						/* Resetting the bits of the pin that the user choose to set direction of */
						GPIOB_CRH &= ~((0b1111) << ((Copy_u8Pin) * 4));
						
						/* Setting the bits */
						GPIOB_CRH |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
					}
					else
					{
						/* Return Error */
					}
					break ;
		case GPIOC :
							/* Checking on the Pin number since we have 2 Registers for the Port (CRL and CRH) */		
					if(Copy_u8Pin >= 0 && Copy_u8Pin <= 7) //CRL Register has 8 Pins from Pin0 to Pin7
					{
						/* Resetting the bits of the pin that the user choose to set direction of */
						GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin * 4));/* Here i need to first reset the mode which is there already , put the register is having 8 pins , so if i want to clear the 4 bits of a specific mode use clear bit &= ~(1111). Then i have to use shift left to go to the specific pin and here each pin has 4 bits so i must use pin_number*4 */
						
						/* Setting the bits */
						GPIOC_CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));/* Here we are using SET_BIT technique */
					}
					
					else if(Copy_u8Pin > 7 && Copy_u8Pin <= 15) //CRH Register has 8 Pins from Pin8 to Pin15
					{
						Copy_u8Pin = Copy_u8Pin - 8; //15*4 = 60 wrong so i need (15-8)*4 = 28 right
						/* Resetting the bits of the pin that the user choose to set direction of */
						GPIOC_CRH &= ~((0b1111) << ((Copy_u8Pin) * 4));
						
						/* Setting the bits */
						GPIOC_CRH |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
					}
					else
					{
						/* Return Error */
					}
					break ;
		default  : break ;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
					if(Copy_u8Value == GPIO_HIGH)
					{
						GPIOA_BSRR = (1 << Copy_u8Pin);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						GPIOA_BRR = (1 << Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
					break ;
		case GPIOB :
					if(Copy_u8Value == GPIO_HIGH)
					{
						GPIOB_BSRR = (1 << Copy_u8Pin);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						GPIOB_BRR = (1 << Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
					break ;
		case GPIOC :
					if(Copy_u8Value == GPIO_HIGH)
					{
						GPIOC_BSRR = (1 << Copy_u8Pin);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						GPIOC_BRR = (1 << Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
					break ;
		default : break;
	}
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0 ;
	switch(Copy_u8Port)
	{
		case GPIOA :LOC_u8Result = GET_BIT(GPIOA_IDR ,Copy_u8Pin);
					break ;
		case GPIOB :LOC_u8Result = GET_BIT(GPIOB_IDR ,Copy_u8Pin);
					break ;
		case GPIOC :LOC_u8Result = GET_BIT(GPIOC_IDR ,Copy_u8Pin);
					break ;
		default : break;
	}
	return LOC_u8Result;
}
