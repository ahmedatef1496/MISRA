/*
 * CFile1.c
 *
 * Created: 5/12/2023 3:36:31 PM
 *  Author: atef
 */ 
#include "timer.h"

/*************************Pointer to functions to be assigned to ISR**************************************/
static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;
static void (*Timer2_OVF_Fptr) (void)=NULLPTR;
/*********************************************************************************************************/
/*********************************************************************************************************
/                                      global variables                                                   /
/***********************************************************************************************************/
 // used in TIME_0_DELAY_MS
static double g_ovfNum  ; 
static double g_time ;

/**********************************************************/
/*                       Timer-0                          */
/**********************************************************/

EN_timerError_t TIMER0_Init(Timer0Mode_type mode)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		default:
		return INVALID_MODE;

	}
}

EN_timerError_t timer_start(Timer0Scaler_type scaler)
{ 
	switch (scaler)
	{
		case TIMER0_STOP:
		case TIMER0_SCALER_1:
		case TIMER0_SCALER_8:
		case TIMER0_SCALER_64:
		case TIMER0_SCALER_256:
		case TIMER0_SCALER_1024:
		case EXTERNALl_FALLING:
		case EXTERNAL_RISING:
		TCCR0&=0XF8;//0b11111000
		TCCR0|=scaler;
		return TIMER_OK;
	
		default:
		return INVALID_PRESCALER;
	}
}

EN_timerError_t timer_setTimerValue(u8 timerValue)
{
	TCNT0 = timerValue;
}
EN_timerError_t timer_reset()
{
	TCCR0 &= 0x00;
	CLR_BIT(TIFR, 0);
	TCNT0 = 0;

}
EN_timerError_t timer0_stop()
{
	TCCR0 &= 0x00;

}
/* Timer 0 Call Back functions*/
void TIMER0_OV_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OVF_Fptr=LocalFptr;
}
/*Timer-0 ISR functions*/
ISR(TIMER0_OVF_vect)
{   
	if(Timer0_OVF_Fptr!=NULLPTR)
	{
		Timer0_OVF_Fptr();
	}
}
/*Timer-0 Interrup*/
void TIMER0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}
void TIMER0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}





EN_timerError_t timer_delay(u16 Delay)
{
	double CPU_F = F_CPU;
	double oneTickTime = (8 / CPU_F ) * 1000; // in ms
	double maxDelay = oneTickTime * 256; // in ms
	int overflowsCount =(u32)((Delay / maxDelay));
	u8 timerInitValue;
	if (overflowsCount > 1)
	{
		timerInitValue = (u8)(256 - ((Delay - (maxDelay * (overflowsCount - 1))) / oneTickTime));
	}
	else
	{
		timerInitValue = (u8)((maxDelay - Delay)/oneTickTime);
	}
	TCNT0 = timerInitValue;

	timer_start(TIMER0_SCALER_8);


	while(overflowsCount--)
	{
		while((READ_BIT(TIFR, 0)) == 0);
		
		SET_BIT(TIFR, 0);
	}

	TCCR0 &= ~((1 << CS01) | (1 << CS00));
}