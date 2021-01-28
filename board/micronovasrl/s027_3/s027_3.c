// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019
 * Author(s): Giulio Benetti <giulio.benetti@benettiengineering.com>
 *
 * Some specific init for s027_3 board.
 */

#include <asm/gpio.h>

int board_early_init_r(void)
{
	int lcd_pwr_gpio;
	int ret;

	lcd_pwr_gpio = sunxi_name_to_gpio("PH18");
	if (lcd_pwr_gpio < 0)
		return lcd_pwr_gpio;

	ret = gpio_request(lcd_pwr_gpio, "lcd-pwr");
	if (ret)
		return ret;

	/* Enable LCD_PWR, it's active low */
	gpio_direction_output(lcd_pwr_gpio, 1);
	gpio_set_value(lcd_pwr_gpio, 0);

	return 0;
}
