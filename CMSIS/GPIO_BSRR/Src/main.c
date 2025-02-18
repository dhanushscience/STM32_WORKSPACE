#include"stm32f4xx.h"

#define GPIOBEN		(1U<<1)

#define PIN7		7
#define PIN14		14
#define PIN0		0

#define BLUE_LED	(1U<<PIN7)
#define RED_LED		(1U<<PIN14)
#define GREEN_LED	(1U<<PIN0)

#define PIN7_OFFSET		(2*PIN7)
#define PIN14_OFFSET	(2*PIN14)
#define PIN0_OFFSET		(2*PIN0)
#define BSRR_OFFSET_VAL 16


void delay(unsigned int ms)
{
	ms *= 1200;
	for(unsigned int x=0; x < ms; x++);
}

int main(void)
{
	RCC->AHB1ENR |= GPIOBEN;

	GPIOB->MODER |= (1U<<(PIN7_OFFSET));
	GPIOB->MODER &= ~(1U<<(PIN7_OFFSET + 1));

	GPIOB->MODER |= (1U<<(PIN14_OFFSET));
	GPIOB->MODER &= ~(1U<<(PIN14_OFFSET + 1));

	GPIOB->MODER |= (1U<<(PIN0_OFFSET));
	GPIOB->MODER &= ~(1U<<(PIN0_OFFSET + 1));

	while(1)
	{

		GPIOB->BSRR = RED_LED;
		delay(1000);

		GPIOB->BSRR = (1U<<(PIN7 + BSRR_OFFSET_VAL));
		delay(1000);

		GPIOB->BSRR = BLUE_LED;
		delay(1000);

		GPIOB->BSRR = (1U<<(PIN14 + BSRR_OFFSET_VAL));
		delay(1000);

		GPIOB->BSRR = GREEN_LED;
		delay(1000);

		GPIOB->BSRR = (1U<<(PIN0 + BSRR_OFFSET_VAL));
		delay(1000);

	}
}


