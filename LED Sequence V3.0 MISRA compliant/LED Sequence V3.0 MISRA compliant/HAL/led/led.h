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

	#define  LED1 0 
	#define  LED2 1
	#define  LED3 2 
	#define  LED4 3 
	
	#define LEDS_Port PB




void LED_init   (u8 LED_N);
void LED_on     (u8 LED_N);
void LED_off    (u8 LED_N);
void LED_toggel (u8 LED_N);


#endif /* LED_H_ */