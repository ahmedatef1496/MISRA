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

