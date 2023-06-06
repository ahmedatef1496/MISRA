/*
 * app.h
 *
 * Created: 4/7/2023 3:44:35 AM
 *  Author: atef
 */ 
#define  F_CPU  8000000
#include <util/delay.h>
#include "app.h"

  void app_start_v1()
  {
	  int led=0 ,flag =0;
	  DIO_PinVoltage_type data=HIGH;
	  while(1)
	  {
		  led=0;
		  while (!flag)
		  { BUTTON_read(PD,0,&data);
			  if (!data)
			  {
				  if (led>3)
				  {
					  flag=1;
					  continue;
				  }
				  
				  DIO_WritePin(PB,LED1+led,HIGH);
				  led++;
				  
				  _delay_ms(300) ;
			  }
		  }
		  led=3;
		  while (flag)
		  { BUTTON_read(PD,0,&data);
			  if  (!data)
			  {

				  LED_off(LED4-led);
				  led--;
				  if (led<0)
				  {
					  flag=0;
					  continue;
				  }
				  _delay_ms(300) ;
			  }
		  }
		  _delay_ms(300);


	  }
  }
  
 


 void app_init(void)
 {
     LED_init(LED1);
	 LED_init(LED2);
	 LED_init(LED3);
	 LED_init(LED4);
	 BUTTON_init(PD,0);


	  	
 }
 