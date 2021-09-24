/*
 * RCC.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Vasan
 */


#include "RCC.h"

void rccResetUnresetDevice(_IO_ uint32_t *io, int bitNum) {
	*io &= ~(1 << bitNum);
	*io |= 1 << bitNum;
	*io &= ~(1 << bitNum);
}

void rccClockEnable(_IO_ uint32_t *io, int bitNum) {
	*io &= ~(1 << bitNum);		// clear bit
	*io |= 1 << bitNum;			// enable clock
}

void rccUnresetAndEnableGpio(RccGpio rccGpio) {
  rccResetUnresetDevice(ahb1ResetReg, rccGpio);
  rccClockEnable(ahb1EnClkReg, rccGpio);		//enable clock-gating
}

void rccUnresetAndEnableUsart(RccUsart rccUsart) {
	if(rccUsart == RCC_USART6) {
		rccResetUnresetDevice(ahb1ResetReg, rccUsart);
		rccClockEnable(ahb1EnClkReg, rccUsart);		//enable clock-gating
	}else {
		rccResetUnresetDevice(ahb2ResetReg, rccUsart);
		rccClockEnable(ahb2EnClkReg, rccUsart); 		//enable clock-gating
	}
}


