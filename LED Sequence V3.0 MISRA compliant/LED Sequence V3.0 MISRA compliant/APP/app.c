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

static volatile u8  gu8BlinkingLedSMode=0;
static volatile u8  gu8BlinkingTimeMode=1;

strBLINKINGCFG gstrBLINKINGCFG=
{
    .ton=100,
    .toff=900
}
;

void set_leds_mode (void)
{
    static u16 leds_mode=0;

    if (leds_mode==7)
    {
        CLR_BIT(gu8BlinkingLedSMode,leds_mode);
        leds_mode=0;
    }

    if ( leds_mode<=3)
    {
        gu8BlinkingLedSMode|=(1<<(4+leds_mode));



    }
    else if ( leds_mode>3)
    {
        CLR_BIT(gu8BlinkingLedSMode,leds_mode);
    }

    leds_mode++;

}


void set_blinking_t_mode (void)
{
    LEDSModeCheck();
    switch (gu8BlinkingTimeMode)
    {
    case 1:{
        gstrBLINKINGCFG.ton  = 100;
        gstrBLINKINGCFG.toff = 900;   
        break;
		   }
    case 2:{
        gstrBLINKINGCFG.ton  = 200;
        gstrBLINKINGCFG.toff = 800; 
        break;
	       }
    case 3:{
        gstrBLINKINGCFG.ton  = 300;
        gstrBLINKINGCFG.toff = 700;  
        break;
	       }
    case 4:{
        gstrBLINKINGCFG.ton  = 500;
        gstrBLINKINGCFG.toff = 500;  
        break;
	       }
    case 5:{
        gstrBLINKINGCFG.ton  = 800;
        gstrBLINKINGCFG.toff = 200;  
        break;
	       }
    default:{
        gstrBLINKINGCFG.ton  = 100;
        gstrBLINKINGCFG.toff = 900;
        gu8BlinkingTimeMode=1 ;
        break;
	        }
    }
}



void app_start_v3 (void)
{

        LEDS_blink(gu8BlinkingLedSMode,gstrBLINKINGCFG.ton,gstrBLINKINGCFG.toff);
        set_blinking_t_mode();
    
}




void app_init(void)
{
    GLOBALE_ENABLE();
    TIMER0_Init(TIMER0_NORMAL_MODE);
    TIMER0_OV_InterruptEnable();
    TIMER0_OV_SetCallBack(BlinkFlag);
    LED_init(LED1);
    LED_init(LED2);
    LED_init(LED3);
    LED_init(LED4);
    BUTTON_init(PC,button1); //change blinking seq
    BUTTON_init(PB,button2); //change led seq
    EXI_Enable(EX_INT2);
    EXI_TriggerEdge(EX_INT2,RISING_EDGE);
    EXI_SetCallBack(EX_INT2,set_leds_mode);

    PORTB=0;


}

void LEDSModeCheck ()
{
    u8 states;
    BUTTON_read(PC,button1,&states);
    if (states==HIGH)
    {
        gu8BlinkingTimeMode++;

        while(states==HIGH)
        {
            BUTTON_read(PC,button1,&states);
        }
    }
}
