/*
 * ledseq_v1.c
 *
 * Created: 6/6/2023 7:42:03 PM
 * Author : atef
 */ 
#include "APP/app.h"

int main(void)
{  DIO_InitPin(PB,0,OUTPUT);
	DIO_WritePin(PB,0,HIGH);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

