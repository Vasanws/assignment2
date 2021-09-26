/*
 * experiment.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Vasan
 */


#include "Gpio.h"
#include "RCC.h"
#include "Timer.h"
#include "nvic.h"

#define counterArr 60000
#define prescaler  832

void experiment1() {
 timerConfigure(timer4, TIM_SMS_GATED | TIM_TS_TI1FP1);
 timerConfigureCaptureCompare(timer4, TIM_OC3M_PWM_1 | TIM_CC1S_INPUT_IC1_ON_TI1);
 timer4->ARR = counterArr;
 timer4->PSC = prescaler;
}

void experiment2() {
	volatile int button_state = getReadPin(gpioB, 8);
	rcc->APB1ENR = 1 << 2; // TIM4 RST
	if(button_state) {
	  timerConfigureCaptureCompare(timer4, TIM_OC3M_FORCE_ACTIV);  // FORCE_ACTIVE
	}else {
	  timerConfigureCaptureCompare(timer4, TIM_OC3M_FORCE_INACTIV); // FORCE_INACTIVE
	}
}

void experiment3() {

}

void experiment4() {


}
