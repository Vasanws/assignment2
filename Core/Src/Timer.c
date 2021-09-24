/*
 * Timer.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Vasan
 */


#include "Rcc.h"
#include "Timer.h"


void timerConfigure(TimerReg *tim, TimerConfig cfg) {
  tim->CR1 = 0xFFFF & cfg;
  tim->CR2 = (cfg >> 16) & 0xFFFF;
  tim->SMCR = (cfg >> 32) & 0xFFFF;
  tim->DIER = (cfg >> 48) & 0xFFFF;
}

void timerConfigureCaptureCompare(TimerReg *tim, TimerCaptureCompareConfig cfg) {
  tim->CCMR1 = 0xFFFF & cfg;
  tim->CCMR2 = (cfg >> 16) & 0xFFFF;
  tim->CCER = (cfg >> 16) & 0xFFFF;
}


