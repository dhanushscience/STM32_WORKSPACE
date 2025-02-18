#include "gpio.h"

int main(void)
{
	gpio_init();

	for(;;)
	{
		btn_state();
	}
}
