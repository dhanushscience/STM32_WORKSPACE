#include"gpio.h"

int main(void)
{
	for(;;)
	{
		gpio_init();
		blink();
		delay();
	}
}
