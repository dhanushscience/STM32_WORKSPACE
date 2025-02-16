#include"gpio.h"

#define GPIOBEN (1U<<1)
#define GPIOCEN (1U<<2)

#define BLUE_LED 		(1U<<7)
#define BUTTON_STATE 	(1U<<13)

void gpio_init(void)
{
	/*Enable clock for the GPIO ports*/
	RCC_AHB1ENR |= GPIOBEN;
	RCC_AHB1ENR |= GPIOCEN;

	/*Set mode of the pin*/
	GPIOB_MODER |= (1U<<14);
	GPIOB_MODER &= ~(1U<<15);

	GPIOC_MODER &= ~(1U<<26);
	GPIOC_MODER &= ~(1U<<27);

	/* AND operation should be performed because when 1/0 OR 1 = 1
	But 1/0 & (~1) = 0 */
}

void delay(unsigned int ms)
{
	ms *= 1200;
	for(unsigned int x=0; x < ms; x++);
}

void led(void)
{
	GPIOB_ODR ^= BLUE_LED;
	delay(200);
}

void btn_state(void)
{
	if(GPIOC_IDR & BUTTON_STATE)
	{
		led();
	}
}
