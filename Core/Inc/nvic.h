/*
 * nvic.h
 *
 *  Created on: Sep 7, 2021
 *      Author: Vasan
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include "IO.h"
#include "IrqNum.h"

#define NVIC_BASE_ADDRESS		0xE000E100

#define nvic					((NvicReg*)NVIC_BASE_ADDRESS)


typedef struct NvicReg_t NvicReg;
struct NvicReg_t {
	_IO_ uint32_t ISER[8];
	_IO_ uint32_t reserved0[24];
	_IO_ uint32_t ICER[8];
	_IO_ uint32_t reserved1[24];
	_IO_ uint32_t ISPR[8];
	_IO_ uint32_t reserved2[24];
	_IO_ uint32_t ICPR[8];
	_IO_ uint32_t reserved3[24];
	_IO_ uint32_t IABR[8];
	_IO_ uint32_t reserved4[56];
	_IO_ uint32_t IPR[60];
	_IO_ uint32_t reserved5[644];
	_IO_ uint32_t STIR;
};

#define nvicEnableIrq(n)								\
		nvic->ISER[(n) >> 5] |= 1 << (n) & 0x1F

#define nvicDisableIrq(n)								\
		nvic->ICER[(n) >> 5] |= 1 << (n) & 0x1F

#define nvicSetPendingIrq(n)							\
		nvic->ISPR[(n) >> 5] |= 1 << (n) & 0x1F

#define nvicClearPendingIrq(n)							\
		nvic->ICPR[(n) >> 5] |= 1 << (n) & 0x1F

#define nvicSetIrqPriority(n, priority)					 \

#define nvicTriggerIrq(n)						\
		nvic->STIR = n

#endif /* INC_NVIC_H_ */
