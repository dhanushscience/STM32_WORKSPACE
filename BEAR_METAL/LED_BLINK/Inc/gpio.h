#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"

#define GPIOB_MODER_OFFSET (0x00)
#define GPIOB_MODER (*(volatile unsigned int *)(GPIOB_PERIPHERAL + GPIOB_MODER_OFFSET))

#define GPIOB_ODR_OFFSET (0x14)
#define GPIOB_ODR (*(volatile unsigned int *)(GPIOB_PERIPHERAL + GPIOB_ODR_OFFSET))

#define RCC_AHB1ENR_OFFSET (0x30)
#define RCC_AHB1ENR (*(volatile unsigned int *)(RCC_PERIPHERAL + RCC_AHB1ENR_OFFSET))

/*Functions for Prototypes*/
void gpio_init(void);
void led_on(void);
void led_off(void);
void led_delay(void);


#endif
