/***************************************************/
/* Author   : Mohamed Taha                         */
/* Version  : V01                                  */
/* Date     : 29 DEC 2020                          */
/***************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Base Address from memory Map */
#define GPIOA_BASE_ADDRESS 	 0x40010800
#define GPIOB_BASE_ADDRESS 	 0x40010C00
#define GPIOC_BASE_ADDRESS 	 0x40011000

/* Register Definitions For PORTA */
#define GPIOA_CRL 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x00)) /* Base address + Offset */
#define GPIOA_CRH 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x04)) /* Base address + Offset */
#define GPIOA_IDR 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x08)) /* Base address + Offset */
#define GPIOA_ODR 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x0C)) /* Base address + Offset */
#define GPIOA_BSRR 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x10)) /* Base address + Offset */
#define GPIOA_BRR 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x14)) /* Base address + Offset */
#define GPIOA_LCKR 			 *((u32 *)(GPIOA_BASE_ADDRESS + 0x18)) /* Base address + Offset */

/* Register Definitions For PORTB */
#define GPIOB_CRL 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x00)) /* Base address + Offset */
#define GPIOB_CRH 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x04)) /* Base address + Offset */
#define GPIOB_IDR 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x08)) /* Base address + Offset */
#define GPIOB_ODR 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x0C)) /* Base address + Offset */
#define GPIOB_BSRR 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x10)) /* Base address + Offset */
#define GPIOB_BRR 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x14)) /* Base address + Offset */
#define GPIOB_LCKR 			 *((u32 *)(GPIOB_BASE_ADDRESS + 0x18)) /* Base address + Offset */

/* Register Definitions For PORTC */
#define GPIOC_CRL 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x00)) /* Base address + Offset */
#define GPIOC_CRH 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x04)) /* Base address + Offset */
#define GPIOC_IDR 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x08)) /* Base address + Offset */
#define GPIOC_ODR 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x0C)) /* Base address + Offset */
#define GPIOC_BSRR 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x10)) /* Base address + Offset */
#define GPIOC_BRR 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x14)) /* Base address + Offset */
#define GPIOC_LCKR 			 *((u32 *)(GPIOC_BASE_ADDRESS + 0x18)) /* Base address + Offset */


#endif // GPIO_PRIVATE_H
