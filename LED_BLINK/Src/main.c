#include"gpio.h"

int main(void)
{
	gpio_init();

	for(;;)
	{
		led_on();
		led_delay();
		led_off();
	}
}
