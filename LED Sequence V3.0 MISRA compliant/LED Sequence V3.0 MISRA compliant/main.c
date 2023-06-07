/*
 * LED Sequence V3.0 MISRA compliant.c
 *
 * Created: 6/6/2023 9:47:41 PM
 * Author : atef
 */ 

#include "APP/app.h"
void timer_flag2();
static volatile u8 gblink_state2=1;

int main(void)
{ 
	
    app_init();
    app_start_v3();

	
}

void timer_flag2()
{
	gblink_state2=1;
	LED_toggel(LED4);
	timer0_stop();
	
}
