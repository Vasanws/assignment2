/*
 * experiment.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Vasan
 */


//#include "Gpio.h"
//#include "RCC.h"
#include "Timer.h"
//#include "nvic.h"

void experiment1() {
 timerConfigureX(tim4);
 timerConfigureCaptureCompare(tim4, TIM_OC3M_PWM_1 | TIM_CC1S_INPUT_IC1_ON_TI1);
 timer4->ARR = 60000;


}

void experiment2(Gpio* gpio, Gpio* pin, Gpio* state) {
	rcc->APB1ENR = 1 << 2; // TIM4 RST
	if(state) {
	  tim->CCMR1 = TIM_OC1M_FORCE_ACTIV; // FORCE_ACTIVE
	}else {
	  tim->CCMR1 = TIM_OC1M_FORCE_INACTIV; // FORCE_INACTIVE
	}
}

void experiment3() {

}

void experiment4() {


}
