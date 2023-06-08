/*
 * led.c
 *
 * Created: 4/7/2023 3:38:36 AM
 *  Author: atef
 */ 

#include "led.h"
#include "../../MCAL/timers/timer.h"
static volatile u8 gblink_state=1;
void LED_init   (u8 LED_N)
{ 
	DIO_InitPin( LEDS_Port, LED_N,OUTPUT);
}
void LED_on     (u8 LED_N)
{
	DIO_WritePin( LEDS_Port, LED_N,HIGH);
}
void LED_off    (u8 LED_N)
{
    DIO_WritePin( LEDS_Port, LED_N,LOW);	
}
void LED_toggel (u8 LED_N)
{
	DIO_TogglePin(LEDS_Port,LED_N);
}

void LEDS_blink( u8 ledS_PINS , u16 on_t, u16 off_t)
{  
	if (gblink_state==1&&ledS_PINS>0)
	{    
			PORTB = ledS_PINS;
			TimerDelayAsych(on_t);
			timer_start(TIMER0_SCALER_64);
			gblink_state++;
	}
   else if(gblink_state==3)
   {
	PORTB=0;
	TimerDelayAsych(off_t);
	timer_start(TIMER0_SCALER_64);
	gblink_state=0;
	
   }
} 

void BlinkFlag()
{  
	
	gblink_state++;
	timer0_stop();
		
}