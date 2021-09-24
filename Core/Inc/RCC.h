/*
 * RCC.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Vasan
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include <stdint.h>
#include "IO.h"

#define ahb1ResetReg		(&rcc->AHB1RSTR)
#define ahb2ResetReg		(&rcc->AHB2RSTR)
#define apb1ResetReg		(&rcc->APB1RSTR)
#define apb2ResetReg		(&rcc->APB2RSTR)

#define ahb1EnClkReg		(&rcc->AHB1ENR)
#define ahb2EnClkReg		(&rcc->APB2ENR)

typedef enum {
 RCC_GPIOA	= 0,
 RCC_GPIOB	= 1,
 RCC_GPIOC	= 2,
 RCC_GPIOD	= 3,
 RCC_GPIOE	= 4,
 RCC_GPIOF	= 5,
 RCC_GPIOG	= 6,
 RCC_GPIOH	= 7,
}RccGpio;

typedef enum {
 RCC_USART1 = 4,
 RCC_USART6 = 5,
}RccUsart;


#define RCC_BASE_ADDRESS  0x40023800
#define rcc 			  ((RccReg*)RCC_BASE_ADDRESS)

typedef struct RccReg_t RccReg;
struct RccReg_t {
	_IO_ uint32_t CR;
	_IO_ uint32_t PLLCFGR;
	_IO_ uint32_t CFGR;
	_IO_ uint32_t CIR;
	_IO_ uint32_t AHB1RSTR;
	_IO_ uint32_t AHB2RSTR;
	_IO_ uint32_t reserved0[2];
	_IO_ uint32_t APB1RSTR;
	_IO_ uint32_t APB2RSTR;
	_IO_ uint32_t AHB1ENR;
	_IO_ uint32_t AHB2ENR;
	_IO_ uint32_t reserved1[2];
	_IO_ uint32_t APB1ENR;
	_IO_ uint32_t APB2ENR;
	_IO_ uint32_t AHB1LPENR;
	_IO_ uint32_t AHB2LPENR;
	_IO_ uint32_t reserved2[2];
	_IO_ uint32_t APB1LPENR;
	_IO_ uint32_t BDCR;
	_IO_ uint32_t CSR;
	_IO_ uint32_t SSCGR;
	_IO_ uint32_t PLLI2SCFGR;
	_IO_ uint32_t PLLSAICFGR;
	_IO_ uint32_t DCKCFGR;
};

void rccResetUnresetDevice(_IO_ uint32_t *io, int bitNum);
void rccUnresetAndEnableGpio(RccGpio rccGpio);
void rccUnresetAndEnableUsart(RccUsart rccUsart);

#endif /* INC_RCC_H_ */
