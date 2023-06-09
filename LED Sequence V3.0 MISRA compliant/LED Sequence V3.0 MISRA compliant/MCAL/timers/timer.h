/*
 * timer.h
 *
 * Created: 5/12/2023 3:36:24 PM
 *  Author: atef
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../dio/dio.h"



#define TIMR0_MAX_VALUE		256
#define TIMR1_MAX_VALUE		256
#define TIMR2_MAX_VALUE		256
 
 #define TIMER0_SCALER       64



/*================================================================================================================*/
/********   TIMER0 [TCCR0] BITS   *******/
#define     CS00          0              // TIMER0 Prescaller Clock Select BIT 0
#define     CS01          1              // TIMER0 Prescaller Clock Select BIT 1
#define     CS02          2              // TIMER0 Prescaller Clock Select BIT 2
#define     WGM01         3              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     COM00         4              // Compare Match Output Mode BIT 0 (OC0) behavior
#define     COM01         5              // Compare Match Output Mode BIT 1 (OC0) behavior
#define     WGM00         6              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     FOC0          7              // Force Output Compare
/*================================================================================================================*/

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0
/*================================================================================================================*/
typedef enum {
	INVALID_PRESCALER,
	INVALID_MODE,
	INVALID_OVF,
	INVALID_VALUE,
	TIMER_OK
} EN_timerError_t;

typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;

typedef enum{
	SCALER_1=1,
	SCALER_8=8,
	SCALER_64=64,
	SCALER_256=256,
	SCALER_1024=1024
}Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;


typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;




typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;

///////////////////////////////////////////////////////////////////////////////////////////////


EN_timerError_t TIMER0_Init(Timer0Mode_type mode);
EN_timerError_t timer_InitValue(u8 timerInitValue);
EN_timerError_t timer_start(Timer0Scaler_type scaler);
EN_timerError_t TimerDelayAsych(u16 Delay);
EN_timerError_t timer_reset();
EN_timerError_t timer0_stop();
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OV_SetCallBack(void(*LocalFptr)(void));



#endif /* TIMER_H_ */