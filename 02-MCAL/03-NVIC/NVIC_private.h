/*
 * NVIC_private.h
 *
 *  Created on: Jan 5, 2021
 *      Author: Mohamed Taha
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/* Register Definitions */

#define NVIC_BASE_ADDRESS 	0xE000E100 /* Base Address of NVIC */
#define SCB_BASE_ADDRESS 	0xE000ED00 /* Base Address of SCB */

									/*     Base address + Offset */
#define NVIC_ISER0			*((u32 *)(NVIC_BASE_ADDRESS + 0x000)) /* Enable External interrupts from 0 	to 31 */
#define NVIC_ISER1			*((u32 *)(NVIC_BASE_ADDRESS + 0x004)) /* Enable External interrupts from 32 to 63 */

#define NVIC_ICER0			*((u32 *)(NVIC_BASE_ADDRESS + 0x080)) /* Disable External interrupts from 0  to 31 */
#define NVIC_ICER1			*((u32 *)(NVIC_BASE_ADDRESS + 0x084)) /* Disable External interrupts from 32 to 63 */

#define NVIC_ISPR0			*((u32 *)(NVIC_BASE_ADDRESS + 0x100)) /* Enable Interrupt Pending flag from 0  to 31 */
#define NVIC_ISPR1			*((u32 *)(NVIC_BASE_ADDRESS + 0x104)) /* Enable Interrupt Pending flag from 32 to 63 */

#define NVIC_ICPR0			*((u32 *)(NVIC_BASE_ADDRESS + 0x108))  /* Disable Interrupt Pending flag from 0  to 31 */
#define NVIC_ICPR1			*((u32 *)(NVIC_BASE_ADDRESS + 0x108))  /* Disable Interrupt Pending flag from 32 to 63 */

#define NVIC_IABR0			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x108)) /* Return Interrupts Active Flag from 0  to 31 */
#define NVIC_IABR1			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x108)) /* Return Interrupts Active Flag from 32 to 63 */

#define NVIC_IPR			 ((volatile u8  *)(NVIC_BASE_ADDRESS + 0x300)) /* u8 since this register is byte accessed */

#define SCB_AIRCR			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x00C)) /* Control groups and sub groups size */

#endif /* NVIC_PRIVATE_H_ */
