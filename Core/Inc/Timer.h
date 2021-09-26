/*
 * Timer.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Vasan
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>
#include "IO.h"


#define timGetStatus  (tim, flags) \
	((tim)->SR & (flags))				/* pass timer and flags to get the status*/
#define timGenerateEvents (tim, events) \
	((tim)->EGR = (events))

#define TIMER1_BASE_ADDRESS			  0x40010000
#define TIMER2_BASE_ADDRESS			  0x40000000
#define TIMER3_BASE_ADDRESS			  0x40000400
#define TIMER4_BASE_ADDRESS			  0x40000800
#define TIMER5_BASE_ADDRESS			  0x40000C00
#define TIMER6_BASE_ADDRESS			  0x40001000

#define timer1						((TimerReg*)TIMER1_BASE_ADDRESS)
#define timer2						((TimerReg*)TIMER2_BASE_ADDRESS)
#define timer3						((TimerReg*)TIMER3_BASE_ADDRESS)
#define timer4						((TimerReg*)TIMER4_BASE_ADDRESS)
#define timer5						((TimerReg*)TIMER5_BASE_ADDRESS)
#define timer6						((TimerReg*)TIMER6_BASE_ADDRESS)

typedef struct TimerReg_t TimerReg;
struct TimerReg_t {

	_IO_ uint32_t CR1;
	_IO_ uint32_t CR2;
	_IO_ uint32_t SMCR;
	_IO_ uint32_t DIER;
	_IO_ uint32_t SR;
	_IO_ uint32_t EGR;
	_IO_ uint32_t CCMR1;
	_IO_ uint32_t CCMR2;
	_IO_ uint32_t CCER;
	_IO_ uint32_t CNT;
	_IO_ uint32_t PSC;
	_IO_ uint32_t ARR;
	_IO_ uint32_t CCR1;
	_IO_ uint32_t CCR2;
	_IO_ uint32_t CCR3;
	_IO_ uint32_t CCR4;
	_IO_ uint32_t BDTR;
	_IO_ uint32_t DCR;
	_IO_ uint32_t DMAR;
	_IO_ uint32_t OR;
};

typedef enum {
	// CR1
	TIM_CEN_EN				= 0 << 0, TIM_CEN_DIS				= 1 << 0,
	TIM_UDIS_EN				= 0 << 1, TIM_UDIS_DIS				= 1 << 1,
	TIM_URS_GENERATE		= 0 << 2, TIM_URS_COUNTER			= 1 << 2,
	TIM_OPM_COUNT_NOT_STOP	= 0 << 3, TIM_OPM_COUNT_STOP		= 1 << 3,
	TIM_DIR_COUNT_UPCOUNT	= 0 << 4, TIM_DIR_COUNT_DOWNCOUNT	= 1 << 4,
	TIM_CMS_EDGE_ALIGN		= 0 << 5, TIM_CMS_CENTER_ALIGN_M1	= 1 << 5,
	TIM_CMS_CENTER_ALIGN_M2 = 2 << 5, TIM_CMS_CENTER_ALIGN_M3	= 3 << 5,
	TIM_ARPE_REG_NOT_BUFF	= 0 << 7, TIM_ARPE_REG_BUFF			= 1 << 7,
	TIM_CKD_TIMER_CLOCK_1	= 0 << 8, TIM_CKD_TIMER_CLOCK_2		= 1 << 8,
	TIM_CKD_TIMER_CLOCK_4 	= 2 << 8,

	// CR2
	TIM_CCPC_NOT_PRELOAD	= 0 << (0 + 16), TIM_CCPC_PRELOAD		= 1 << (0 + 16),
	TIM_CCUS_COMG_BIT		= 0 << (2 + 16), TIM_CCUS_TRGI			= 1 << (2 + 16),
	TIM_CCDS_CCX			= 0 << (3 + 16), TIM_CCDS_UPDATE		= 1 << (3 + 16),
	TIM_MMS_RESET			= 0 << (4 + 16), TIM_MMS_EN				= 1 << (4 + 16),
	TIM_MMS_UPDATE			= 2 << (4 + 16), TIM_MMS_PULSE			= 3 << (4 + 16),
	TIM_MMS_OC1REF			= 4 << (4 + 16), TIM_MMS_OC2REF			= 5 << (4 + 16),
	TIM_MMS_OC3REF			= 6 << (4 + 16), TIM_MMS_OC4REF			= 7 << (4 + 16),
	TIM_TI1S_INPUT			= 0 << (7 + 16), TIM_TI1S_XOR			= 1 << (7 + 16),
	TIM_OIS1_OC1_0			= 0 << (8 + 16), TIM_OIS1_OC1_1			= 1 << (8 + 16),
	TIM_OIS1N_OC1N_0		= 0 << (9 + 16), TIM_OIS1N_OC1N_1		= 1 << (9 + 16),
	TIM_OIS2				= 1 << (10 + 16), TIM_OIS2N				= 1 << (11 + 16),
	TIM_OIS3				= 1 << (12 + 16), TIM_OIS3N				= 1 << (13 + 16),
	TIM_OIS4				= 1 << (14 + 16),

	// SMCR
	TIM_SMS_SLAVE			= 0LL << (0 + 32), TIM_SMS_ENCODER_1	= 1LL << (0 + 32),
	TIM_SMS_ENCODER_2		= 2LL << (0 + 32), TIM_SMS_ENCODER_3	= 3LL << (0 + 32),
	TIM_SMS_RESET			= 4LL << (0 + 32), TIM_SMS_GATED		= 5LL << (0 + 32),
	TIM_SMS_TRIGGER			= 6LL << (0 + 32), TIM_SMS_EXT_CLOCK	= 7LL << (0 + 32),
	TIM_TS_ITR0				= 0LL << (4 + 32), TIM_TS_ITR1			= 1LL << (4 + 32),
	TIM_TS_ITR2				= 2LL << (4 + 32), TIM_TS_ITR3			= 3LL << (4 + 32),
	TIM_TS_TI1F_ED			= 4LL << (4 + 32), TIM_TS_TI1FP1		= 5LL << (4 + 32),
	TIM_TS_TI2FP2			= 6LL << (4 + 32), TIM_TS_ETRF			= 7LL << (4 + 32),
	TIM_MSM_X_ACTION		= 0LL << (7 + 32), TIM_MSM_TRGI			= 1LL << (7 + 32),
	TIM_ETF_NO_FILTER		= 0LL << (8 + 32), TIM_ETF_FCK_INT_N2	= 1LL << (8 + 32),
	TIM_ETF_FCK_INT_N4		= 2LL << (8 + 32), TIM_ETF_FCK_INT_N8	= 3LL << (8 + 32),
	TIM_ETF_FDTS2_N6		= 4LL << (8 + 32), TIM_ETF_FDTS2_N8		= 5LL << (8 + 32),
	TIM_ETF_FDTS4_N6		= 6LL << (8 + 32), TIM_ETF_FDTS4_N8		= 7LL << (8 + 32),
	TIM_ETF_FDTS8_N6		= 8LL << (8 + 32), TIM_ETF_FDTS8_N8		= 9LL << (8 + 32),
	TIM_ETF_FDTS16_N5		= 10LL << (8 + 32), TIM_ETF_FDTS16_N6	= 11LL << (8 + 32),
	TIM_ETF_FDTS16_N8		= 12LL << (8 + 32), TIM_ETF_FDTS32_N5	= 13LL << (8 + 32),
	TIM_ETF_FDTS32_N6		= 14LL << (8 + 32), TIM_ETF_FDTS32_N8	= 15LL << (8 + 32),
	TIM_ETPS_PRESCALER_OFF	= 0LL << (12 + 32), TIM_ETPS_DIV_2		= 1LL << (12 + 32),
	TIM_ETPS_DIV_4			= 2LL << (12 + 32), TIM_ETPS_DIV_8		= 3LL << (12 + 32),
	TIM_ECE_EXT_CLK_DIS		= 0LL << (14 + 32), TIM_ECE_EXT_CLK_EN	= 1LL << (14 + 32),
	TIM_ETP_X_INVERT		= 0LL << (15 + 32), TIM_ETP_INVERT		= 1LL << (15 + 32),

	//DIER
	TIM_UIE_DIS			= 0LL << (0 + 48), TIM_UIE_EN		= 1LL << (0 + 48),
	TIM_CC1IE_DIS		= 0LL << (1 + 48), TIM_CC1IE_EN		= 1LL << (1 + 48),
	TIM_CC2IE_DIS		= 0LL << (2 + 48), TIM_CC2IE_EN		= 1LL << (2 + 48),
	TIM_CC3IE_DIS		= 0LL << (3 + 48), TIM_CC3IE_EN		= 1LL << (3 + 48),
	TIM_CC4IE_DIS		= 0LL << (4 + 48), TIM_CC4IE_EN		= 1LL << (4 + 48),
	TIM_COMIE_DIS		= 0LL << (5 + 48), TIM_COMIE_EN		= 1LL << (5 + 48),
	TIM_TIE_DIS			= 0LL << (6 + 48), TIM_TIE_EN		= 1LL << (6 + 48),
	TIM_BIE_DIS			= 0LL << (7 + 48), TIM_BIE_EN		= 1LL << (7 + 48),
	TIM_UDE_DIS			= 0LL << (8 + 48), TIM_UDE_EN		= 1LL << (8 + 48),
	TIM_CC1DE_DIS		= 0LL << (9 + 48), TIM_CC1DE_EN		= 1LL << (9 + 48),
	TIM_CC2DE_DIS		= 0LL << (10 + 48),TIM_CC2DE_EN		= 1LL << (10 + 48),
	TIM_CC3DE_DIS		= 0LL << (11 + 48), TIM_CC3DE_EN	= 1LL << (11 + 48),
	TIM_CC4DE_DIS		= 0LL << (12 + 48), TIM_CC4DE_EN	= 1LL << (12 + 48),
	TIM_COMDE_DIS		= 0LL << (13 + 48), TIM_COMDE_EN	= 1LL << (13 + 48),
	TIM_TDEE_DIS		= 0LL << (14 + 48), TIM_TDE_EN		= 1LL << (14 + 48),
}TimerConfig;

typedef enum {
	//EGR
	TIM_UG_DIS			= 0LL << (0 + 32), TIM_UG_EN		= 1LL << (0 + 32),
	TIM_CC1G_DIS		= 0LL << (1 + 32), TIM_CC1G_EN		= 1LL << (1 + 32),
	TIM_COMG_DIS		= 0LL << (5 + 32), TIM_COMG_EN		= 1LL << (5 + 32),
	TIM_RG_DIS			= 0LL << (6 + 32), TIM_RG_EN		= 1LL << (6 + 32),
	TIM_BG_DIS			= 0LL << (7 + 32), TIM_BG_EN	    = 1LL << (7 + 32),
}TimerEventGeneration;

typedef enum {
	//SR
	TIM_UIF_X_UPDATE	= 0 << (0 + 16), TIM_UIF_UPDATE_INTERRUPT	= 1 << (0 + 16),
	TIM_CC1IF_X_MATCH	= 0 << (1 + 16), TIM_CC1IF_COUNTER			= 1 << (1 + 16),
	TIM_COMIF_X_COM		= 0 << (5 + 16), TIM_COMIF_COM_INTERRUPT	= 1 << (5 + 16),
	TIM_TIF_X_TRIG		= 0 << (6 + 16), TIM_TIF_TRIG				= 1 << (6 + 16),
	TIM_BIF_X_BREAK		= 0 << (7 + 16), TIM_BIF_ACTIVE_BREAK		= 1 << (7 + 16),
	TIM_CC1OF_X_OVERCAPTURE	 = 0 << (9 + 16), TIM_CC1OF_VALUE_CAPTURE	 = 1 << (9 + 16),
}TimerStatus;

typedef enum {
	// CCMR1 (OUTPUT CAPTURE)
	//=============================CHANNEL 1==================================
	TIM_CC1S_CC1_OUTPUT 	  = 0 << 0,	 TIM_CC1S_INPUT_IC1_ON_TI1 	= 1 << 0,
	TIM_CC1S_INPUT_IC1_ON_TI2 = 2 << 0,  TIM_CC1S_INPUT_IC1_ON_TRC 	= 3 << 0,
	TIM_OC1FE_DIS_TRGI		  = 0 << 2,  TIM_OC1FE_EN_TRGI 			= 1 << 2,
	TIM_OC1PE_DIS			  = 0 << 3,  TIM_OC1PE_EN			  	= 1 << 3,
	TIM_OC1M_FROZEN           = 0 << 4,  TIM_OC1M_CH1_ACTIV       	= 1 << 4,
	TIM_OC1M_CH1_INACTIV      = 2 << 4,  TIM_OC1M_TOGGLE     	  	= 3 << 4,
	TIM_OC1M_FORCE_INACTIV    = 4 << 4,  TIM_OC1M_FORCE_ACTIV      	= 5 << 4,
	TIM_OC1M_PWM_1   		  = 6 << 4,  TIM_OC1M_PWM_2   		  	= 7 << 4,
	TIM_OC1CE_REF_X_CLEAR	  = 0 << 7,  TIM_OC1CE_REF_CLEAR	    = 1 << 7,
	//==============================CHANNEL 2==================================
	TIM_CC2S_CC2_OUTPUT		  = 0 << 8,  TIM_CC2S_INPUT_IC2_ON_TI2	= 1 << 8,
	TIM_CC2S_INPUT_IC2_ON_TI1 = 2 << 8,  TIM_CC2S_INPUT_IC2_ON_TRC 	= 3 << 8,
	TIM_OC2FE_DIS_TRGI		  = 0 << 10, TIM_OC2FE_EN_TRGI		  	= 1 << 10,
	TIM_OC2PE_DIS			  = 0 << 11, TIM_OC2PE_EN			  	= 1 << 11,
	TIM_OC2M_FROZEN			  = 0 << 12, TIM_OC2M_CH2_ACTIV		 	= 1 << 12,
	TIM_OC2M_CH2_INACTIV	  = 2 << 12, TIM_OC2M_TOGGLE	 	    = 3 << 12,
	TIM_OC2M_FORCE_INACTIV	  = 4 << 12, TIM_OC2M_FORCE_ACTIV	    = 5 << 12,
	TIM_OC2M_PWM_1	 		  = 6 << 12, TIM_OC2M_PWM_2	 		    = 7 << 12,
	TIM_OC2CE_REF_X_CLEAR	  = 0 << 15, TIM_OC2CE_REF_CLEAR	    = 1 << 15,

	// CCMR2 (OUTPUT CAPTURE)
	//============================CHANNEL 3==========================================
	TIM_CC3S_CC3_OUTPUT		  = 0 << (0 + 16),  TIM_CC3S_CC3_ON_TI3	  = 1 << (0 + 16),
	TIM_CC3S_CC3_ON_TI4		  = 2 << (0 + 16),  TIM_CC3S_CC3_ON_TRC	  = 3 << (0 + 16),
	TIM_OC3FE_DIS_TRGI		  = 0 << (2 + 16),  TIM_OC3FE_EN_TRGI	  = 1 << (2 + 16),
	TIM_PC3PE_DIS			  = 0 << (3 + 16),  TIM_PC3PE_EN		  = 1 << (3 + 16),
	TIM_OC3M_FROZEN			  = 0 << (4 + 16),  TIM_OC3M_CH3_ACTIV    = 1 << (4 + 16),
	TIM_OC3M_CH3_INACTIV	  = 2 << (4 + 16),  TIM_OC3M_TOGGLE		  = 3 << (4 + 16),
	TIM_OC3M_FORCE_INACTIV	  = 4 << (4 + 16),  TIM_OC3M_FORCE_ACTIV  = 5 << (4 + 16),
	TIM_OC3M_PWM_1		  	  = 6 << (4 + 16),  TIM_OC3M_PWM_2		  = 7 << (4 + 16),
	TIM_OC3CE_REF_X_CLEAR	  = 0 << (7 + 16),  TIM_OC3CE_REF_CLEAR	  = 1 << (7 + 16),
	//============================CHANNEL 4===========================================
	TIM_CC4S_CC4_OUTPUT		  = 0 << (8 + 16),  TIM_CC4S_CC4_ON_TI4	  = 1 << (8 + 16),
	TIM_CC4S_CC4_ON_TI3	      = 2 << (8 + 16),  TIM_CC4S_CC4_ON_TRC	  = 3 << (8 + 16),
	TIM_OC4FE_DIS_TRGI		  = 0 << (10 + 16), TIM_OC4FE_EN_TRGI	  = 1 << (10 + 16),
	TIM_OC4PE_DIS			  = 0 << (11 + 16), TIM_OC4PE_EN		  = 1 << (11 + 16),
	TIM_OC4M_FROZEN			  = 0 << (12 + 16), TIM_OC4M_CH4_ACTIV	  = 1 << (12 + 16),
	TIM_OC4M_CH4_INACTIV	  = 2 << (12 + 16), TIM_OC4M_CH4_TOGGLE	  = 3 << (12 + 16),
	TIM_OC4M_FORCE_INACTIV	  = 4 << (12 + 16), TIM_OC4M_FORCE_ACTIV  = 5 << (12 + 16),
	TIM_OC4M_PWM_1      	  = 6 << (12 + 16), TIM_OC4M_PWM_2        = 7 << (12 + 16),
	TIM_OC4CE_REF_X_CLEAR	  = 0 << (15 + 16), TIM_OC4CE_REF_CLEAR	  = 1 << (15 + 16),

	// CCER (OUTPUT CAPTURE)
	TIM_CC1E_OFF			  = 0LL << (0 + 32),  TIM_CC1E_ON			  = 1LL << (0 + 32),
	TIM_CC1P_HIGH			  = 0LL << (1 + 32),  TIM_CC1P_LOW		  = 1LL << (1 + 32),
	TIM_CC1NE_OFF			  = 0LL << (2 + 32),  TIM_CC1NE_ON		  = 1LL << (2 + 32),
	TIM_CC1NP_HIGH			  = 0LL << (3 + 32),  TIM_CC1NP_LOW		  = 1LL << (3 + 32),
	TIM_CC2E_OFF			  = 0LL << (4 + 32),  TIM_CC2E_ON			  = 1LL << (4 + 32),
	TIM_CC2P_HIGH			  = 0LL << (5 + 32),  TIM_CC2P_LOW		  = 1LL << (5 + 32),
	TIM_CC2NE_OFF			  = 0LL << (6 + 32),  TIM_CC2NE_ON		  = 1LL << (6 + 32),
	TIM_CC2NP_HIGH			  = 0LL << (7 + 32),  TIM_CC2NP_LOW		  = 1LL << (7 + 32),
	TIM_CC3E_OFF			  = 0LL << (8 + 32),  TIM_CC3E_ON			  = 1LL << (8 + 32),
	TIM_CC3P_HIGH			  = 0LL << (9 + 32),  TIM_CC3P_LOW		  = 1LL << (9 + 32),
	TIM_CC3NE_OFF			  = 0LL << (10 + 32), TIM_CC3NE_ON		  = 1LL << (10 + 32),
	TIM_CC3NP_HIGH			  = 0LL << (11 + 32), TIM_CC3NP_LOW		  = 1LL << (11 + 32),
	TIM_CC4E_OFF			  = 0LL << (12 + 32), TIM_CC4E_ON			  = 1LL << (12 + 32),
	TIM_CC4P_HIGH			  = 0LL << (13 + 32), TIM_CC4P_LOW		  = 1LL << (13 + 32),
	TIM_CC4NP_HIGH			  = 0LL << (15 + 32), TIM_CC4NP_LOW		  = 1LL << (15 + 32),
}TimerCaptureCompareConfig;

void timerConfigure(TimerReg *tim, TimerConfig cfg);
void timerConfigureCaptureCompare(TimerReg *tim, TimerCaptureCompareConfig cfg);

#endif /* INC_TIMER_H_ */
