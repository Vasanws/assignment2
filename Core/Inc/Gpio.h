/*
 * Gpio.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Vasan
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stdint.h>
#include "IO.h"

#define PORT_A_BASE_REGISTER 			0x40020000
#define PORT_B_BASE_REGISTER 			0x40020400
#define PORT_C_BASE_REGISTER 			0x40020800
#define PORT_D_BASE_REGISTER 			0x40020C00
#define PORT_E_BASE_REGISTER 			0x40021000
#define PORT_F_BASE_REGISTER 			0x40021400
#define PORT_G_BASE_REGISTER 			0x40021800

// All GPIO pointers
#define gpioA			((Gpio *)PORT_A_BASE_REGISTER)
#define gpioB			((Gpio *)PORT_B_BASE_REGISTER)
#define gpioC			((Gpio *)PORT_C_BASE_REGISTER)
#define gpioD			((Gpio *)PORT_D_BASE_REGISTER)
#define gpioE			((Gpio *)PORT_E_BASE_REGISTER)
#define gpioF			((Gpio *)PORT_F_BASE_REGISTER)
#define gpioG			((Gpio *)PORT_G_BASE_REGISTER)

// Pin mode
#define GPIO_INPUT 	 				0
#define GPIO_OUTPUT 				1
#define GPIO_ALT_FUNC 				2
#define GPIO_ANALOG_IN 				3
#define GPIO_MODE_MASK(pin) 		(~(3 << (2 * pin)))

// Output driver speed
#define GPIO_LOW_SPEED 		  0
#define GPIO_MED_SPEED 		  1
#define GPIO_HI_SPEED 		  2
#define GPIO_VHI_SPEED 		  3
#define GPIO_SPEED_MASK(pin) (~(3 << (2 * pin)))

// Output driver types
#define GPIO_PUSH_PULL 		 0
#define GPIO_OPEN_DRAIN 	 1
#define GPIO_DRVR_MASK(pin)  (~(1 << (pin)))

#define gpioD_OSPEEDR 	(*(_IO_ int32_t*)(PORT_D_BASE_REGISTER  + 0x8))

typedef struct Gpio_t Gpio;
struct Gpio_t {
	_IO_ int32_t MODER;
	_IO_ int32_t OTYPER;
	_IO_ int32_t OSPEEDR;
	_IO_ int32_t PUPDR;
	_IO_ int32_t IDR;
	_IO_ int32_t ODR;
	_IO_ int32_t BSRR;
	_IO_ int32_t LCKR;
	_IO_ int32_t AFRL;
	_IO_ int32_t AFR[2];
};

//void gpioWritePin(Gpio* gpio, int pin, int state);
int gpioReadPin(Gpio *gpio, int pin);
void gpioLockPin(Gpio *gpio, int pin);


#endif /* INC_GPIO_H_ */
