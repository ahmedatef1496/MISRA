/*
 * led.h
 *
 * Created: 4/7/2023 3:39:08 AM
 *  Author: atef
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/dio/dio.h"


typedef enum EN_LED_ERROR_t
{
	LED_OK,
	LED_ERROR
}EN_LED_ERROR_t;

	#define  LED1 4 
	#define  LED2 5
	#define  LED3 6 
	#define  LED4 7 
	
	#define LEDS_Port PB




void LED_init   (u8 LED_N);
void LED_on     (u8 LED_N);
void LED_off    (u8 LED_N);
void LED_toggel (u8 LED_N);

void LEDS_blink( u8 ledS_PINS , u16 on_t, u16 off_t);
void timer_flag();
#endif /* LED_H_ */