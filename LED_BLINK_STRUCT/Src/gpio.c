/*
 * gpio.c
 *
 *  Created on: Feb 18, 2025
 *      Author: @dhanushscience
 */
#include"gpio.h"

#define RCC		((RCC_TypeDef*) 	RCC_PERIPHERAL)
#define GPIOB	((GPIO_TypeDef*) 	GPIOB_PERIPHERAL_ADDR)

#define GPIOB7 (1U<<7)
#define LED_PIN GPIOB7
#define BLUE_LED 7
#define BLUE_LED_SHIFT (2 * BLUE_LED)

void gpio_init(void)
{
	RCC ->AHB1ENR |= GPIOBEN;

	GPIOB ->MODER |= (1U<<(BLUE_LED_SHIFT));
	GPIOB ->MODER &= ~(1U<<(BLUE_LED_SHIFT+1));

}

void blink(void)
{
	GPIOB->ODR ^= LED_PIN;
}

void delay(void)
{
	for(int x=0; x<1200000; x++);
}
