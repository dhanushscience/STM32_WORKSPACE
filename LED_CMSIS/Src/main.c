#include"stm32f4xx.h"

#define GPIOBEN		(1U<<1)
#define PIN14		(1U<<14)
#define LED			PIN14

#define PIN			14
#define PIN_OFFSET	2*PIN

int main(void)
{
	RCC->AHB1ENR |= GPIOBEN;

	GPIOB->MODER |= (1U<<(PIN_OFFSET));
	GPIOB->MODER &= ~(1U<<(PIN_OFFSET + 1));

	while(1)
	{
		GPIOB->ODR ^=LED;
		for(int i=0; i<1200000;i++);
	}
}
