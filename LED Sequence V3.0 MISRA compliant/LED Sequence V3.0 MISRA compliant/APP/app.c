/*
 * app.h
 *
 * Created: 4/7/2023 3:44:35 AM
 *  Author: atef
 */ 
#define  F_CPU  8000000
#include <util/delay.h>
#include "app.h"

/*-------------------------GLOBAL STATIC VARIABLES -------------------------*/

static u64 gu64TickCounts = 0;
static u64 gu64TaskCounter = 0;
static u8 gu8TFlag = LOW;
static u8 gu8init_flag=0;
static volatile u8 LEDS_NUM=0;
u16 led_counter=0;
static volatile u16 blinking_leds_mode=0;
static volatile u8 blinking_time_mode=1;

ST_BLINKING_t blinking_times=
{.ton=100,
.toff=900}
;

void set_leds_mode (void)
{  
	static u16 leds_mode=0;
	
	if (leds_mode==7)
	{
		CLR_BIT(LEDS_NUM,leds_mode);
		leds_mode=0;
	}

	if ( leds_mode<=3)
	{
		LEDS_NUM|=(1<<(4+leds_mode));
	
		
		
	}
	else if ( leds_mode>3)
	{
		CLR_BIT(LEDS_NUM,leds_mode);
	}

	leds_mode++;

}


void set_blinking_t_mode (void)
{  
	 LEDS_N_Check();
	switch (blinking_time_mode)
	{
		case 1:	blinking_times.ton =  100;       blinking_times.toff=900;   //blinking_time_mode++;
		break;
		case 2:	blinking_times.ton  = 200;	     blinking_times.toff=800;  //blinking_time_mode++;
		break;
		case 3:	blinking_times.ton  = 300;	     blinking_times.toff=700;  //blinking_time_mode++;
		break;
		case 4:	blinking_times.ton  = 500;	     blinking_times.toff=500;  //blinking_time_mode++;
		break;
		case 5:	blinking_times.ton  = 800;	     blinking_times.toff=200;  //blinking_time_mode++;
		break;
		default:blinking_times.ton =  100;       blinking_times.toff=900; ;
		break;
	}
}



void app_start_v3 (void)
{
	while(1)
	{   
       
		
		LEDS_blink(LEDS_NUM,blinking_times.ton,blinking_times.toff);
		set_blinking_t_mode();
	}
}




 void app_init(void)
 { 
	 GLOBALE_ENABLE();
	 TIMER0_Init(TIMER0_NORMAL_MODE);
	 TIMER0_OV_InterruptEnable();
	 TIMER0_OV_SetCallBack(timer_flag);
     LED_init(LED1);
	 LED_init(LED2);
	 LED_init(LED3);
	 LED_init(LED4);
	 BUTTON_init(PC,button1);
	 BUTTON_init(PB,button2);
	 	  	EXI_Enable(EX_INT2);
	 	  	EXI_TriggerEdge(EX_INT2,RISING_EDGE);
	 	  	EXI_SetCallBack(EX_INT2,set_leds_mode);
	 	  	
PORTB=0;

	  	
 }
 
  void LEDS_N_Check ()
  {
	  u8 states;
	  BUTTON_read(PC,4,&states);
	  if (states==HIGH)
	  { 
       blinking_time_mode++;

		  
		  while(states==HIGH)
		  {
			  BUTTON_read(PC,4,&states);
		  }
	  }
  }