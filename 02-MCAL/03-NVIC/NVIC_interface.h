/*
 * NVIC_interface.h
 *
 *  Created on: Jan 5, 2021
 *      Author: Mohamed Taha
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void MNVIC_voidEnableInterrupt 	(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag 	(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 	 MNVIC_u8GetActiveFlag 		(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority 		(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority , u32 Copy_u32SCBGroup);

/* For Copy_u32SCBGroup */
#define 	GROUP3		0x05FA0300  // 4 bits for Group and 0 bits for sub
#define 	GROUP4		0x05FA0400  // 3 bits for Group and 1 bit  for sub
#define 	GROUP5		0x05FA0500  // 2 bits for Group and 2 bits for sub
#define 	GROUP6		0x05FA0600  // 1 bit  for Group and 3 bits for sub
#define 	GROUP7		0x05FA0700  // 0 bits for Group and 4 bits for sub

#endif /* NVIC_INTERFACE_H_ */
