/*
 * app.h
 *
 * Created: 4/7/2023 3:44:46 AM
 *  Author: atef
 */ 


#ifndef APP_H_
#define APP_H_

#include "../HAL/button/button.h"
#include "../HAL/led/led.h"
#include "../MCAL/timers/timer.h"
#include "../MCAL/Interrupt/exi.h"


typedef struct ST_BLINKING_t {
	u16 ton;
	u16 toff;
}ST_BLINKING_t;

void app_start_v1();
 void app_init(void);
void app_start_v3 (void);

#endif /* APP_H_ */