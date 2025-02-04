#include"gpio.h"

#define GPIOBEN (1U<<1) // (2U)
#define GPIOB7 (1U<<7)

void gpio_init(void)
{
	/*Enable clock for the GPIO ports*/
	RCC_AHB1ENR |= GPIOBEN;

	/*Set mode of the pin*/
	GPIOB_MODER |= (1U<<14);
	GPIOB_MODER &= ~(1U<<15);
	/* AND operation should be performed because when 1/0 OR 1 = 1
	But 1/0 & (~1) = 0 */
}

void led_on(void)
{
	GPIOB_ODR |= GPIOB7; //SET BIT
}

void led_off(void)
{
	GPIOB_ODR &= ~(GPIOB7); //CLEAR BIT
}

void led_delay(void)
{
	for(int x=0; x<1800000; x++);
}
