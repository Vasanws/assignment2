/*
 * Gpio.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Vasan
 */


#include "Gpio.h"

void gpioWritePin(Gpio* gpio, int pin, int state) {
	if(state) {
		gpio->BSRR = 1 << pin;
	}else {
		gpio->BSRR = (1 << (pin + 16));
	}
}

int gpioReadPin(Gpio *gpio, int pin) {
	return (gpio->IDR >> pin) & 1;

}

void gpioLockPin(Gpio *gpio, int pin) {
	gpio->LCKR = 1 << 16 | 1 << pin;
	gpio->LCKR = 1 << pin;
	gpio->LCKR = 1 << 16 | 1 << pin;
}
