/*
 * LED Sequence V3.0 MISRA compliant.c
 *
 * Created: 6/6/2023 9:47:41 PM
 * Author : atef
 */ 

#include "APP/app.h"

int main(void)
{ 
	DIO_InitPin(PB,0,OUTPUT);
	DIO_WritePin(PB,0,HIGH);
    /* Replace with your application code */
    while (1) 
    {
    }
}

