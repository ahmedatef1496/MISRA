/*
 * led.c
 *
 * Created: 4/7/2023 3:38:36 AM
 *  Author: atef
 */ 

#include "led.h"

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

void LED_blink( u8 LED_N , u16 on_t, u16 off_t)
{
	LED_on(LED_N);
	timer_delay(on_t);
	LED_on(LED_N);
	timer_delay(off_t);
}
void LEDS_blink( u16 ledS_PINS , u16 on_t, u16 off_t)
{
	PORTB=ledS_PINS;
	timer_delay(on_t);
	PORTB=0;
	timer_delay(off_t);
}