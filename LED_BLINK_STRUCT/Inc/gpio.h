/*
 * gpio.h
 *
 *  Created on: Feb 18, 2025
 *      Author: dhanushscience
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"
#include <stdint.h>

#define __IO						volatile
#define GPIO_OFFSET					(0x400UL)

#define GPIOA_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x0UL * GPIO_OFFSET)) /**/
#define GPIOB_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x1UL * GPIO_OFFSET)) /**/
#define GPIOC_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x2UL * GPIO_OFFSET))	/**/
#define GPIOD_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x3UL * GPIO_OFFSET))	/**/
#define GPIOE_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x4UL * GPIO_OFFSET))	/**/
#define GPIOF_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x5UL * GPIO_OFFSET))	/**/
#define GPIOG_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x6UL * GPIO_OFFSET))	/**/
#define GPIOH_PERIPHERAL_ADDR       (AHB1_PERIPHERAL_BASE_ADDR + (0x7UL * GPIO_OFFSET))	/**/

#define GPIOAEN	(1U<<0)
#define GPIOBEN	(1U<<1)
#define GPIOCEN	(1U<<2)
#define GPIODEN	(1U<<3)
#define GPIOEEN	(1U<<4)
#define GPIOFEN	(1U<<5)
#define GPIOGEN	(1U<<6)
#define GPIOHEN	(1U<<7)


typedef struct
{
	__IO uint32_t MODER; 	/*GPIO port mode register, 					Address offset: 0x00		*/
	__IO uint32_t OTYPER;	/*GPIO port output type register,			Address offset: 0x04		*/
	__IO uint32_t OSPEEDR;	/*GPIO port output speed register,			Address offset: 0x08		*/
	__IO uint32_t PUPDR;	/*GPIO port pull-up/pull-down register,		Address offset: 0x0C		*/
	__IO uint32_t IDR;		/*GPIO port input data register,			Address offset: 0x10		*/
	__IO uint32_t ODR;		/*GPIO port output data register,			Address offset: 0x14		*/
	__IO uint32_t BSSR;		/*GPIO port bit set/reset register,			Address offset: 0x18		*/
	__IO uint32_t LCKR;		/*GPIO port configuration lock register,	Address offset: 0x1C		*/
	__IO uint32_t AFR[2];	/*GPIO alternate function low register,		Address offset: 0x20 - 0x24	*/

} GPIO_TypeDef;


typedef struct
{
    __IO uint32_t CR;            /** RCC clock control register */
    __IO uint32_t PLLCFGR;       /** RCC PLL configuration register */
    __IO uint32_t CFGR;          /** RCC clock configuration register */
    __IO uint32_t CIR;           /** RCC clock interrupt register */
    __IO uint32_t AHB1RSTR;      /** RCC AHB1 peripheral reset register */
    __IO uint32_t AHB2RSTR;      /** RCC AHB2 peripheral reset register */
    __IO uint32_t AHB3RSTR;      /** RCC AHB3 peripheral reset register */
    uint32_t RESERVED0;          /** Reserved */
    __IO uint32_t APB1RSTR;      /** RCC APB1 peripheral reset register */
    __IO uint32_t APB2RSTR;      /** RCC APB2 peripheral reset register */
    uint32_t RESERVED1[2];       /** Reserved */
    __IO uint32_t AHB1ENR;       /** RCC AHB1 peripheral clock enable register */
    __IO uint32_t AHB2ENR;       /** RCC AHB2 peripheral clock enable register */
    __IO uint32_t AHB3ENR;       /** RCC AHB3 peripheral clock enable register */
    uint32_t RESERVED2;          /** Reserved */
    __IO uint32_t APB1ENR;       /** RCC APB1 peripheral clock enable register */
    __IO uint32_t APB2ENR;       /** RCC APB2 peripheral clock enable register */
    uint32_t RESERVED3[2];       /** Reserved */
    __IO uint32_t AHB1LPENR;     /** RCC AHB1 peripheral clock enable in low power mode register */
    __IO uint32_t AHB2LPENR;     /** RCC AHB2 peripheral clock enable in low power mode register */
    __IO uint32_t AHB3LPENR;     /** RCC AHB3 peripheral clock enable in low power mode register */
    uint32_t RESERVED4;          /** Reserved */
    __IO uint32_t APB1LPENR;     /** RCC APB1 peripheral clock enable in low power mode register */
    __IO uint32_t APB2LPENR;     /** RCC APB2 peripheral clock enable in low power mode register */
    uint32_t RESERVED5[2];       /** Reserved */
    __IO uint32_t BDCR;          /** RCC Backup domain control register */
    __IO uint32_t CSR;           /** RCC clock control & status register */
    uint32_t RESERVED6[2];       /** Reserved */
    __IO uint32_t SSCGR;         /** RCC spread spectrum clock generation register */
    __IO uint32_t PLLI2SCFGR;    /** RCC PLLI2S configuration register */
    uint32_t RESERVED7[1];       /** Reserved */
    __IO uint32_t PLLSAICFGR;    /** RCC PLLSAI configuration register */

    __IO uint32_t DCKCFGR;       /** RCC dedicated clock configuration register */
    __IO uint32_t CKGATENR;      /** RCC clock gate enable register */
    __IO uint32_t DCKCFGR2;      /** RCC dedicated clock configuration register 2 */

} RCC_TypeDef;

void gpio_init(void);
void blink(void);
void delay(void);

#endif /* GPIO_H_ */
