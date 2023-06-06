/*
 * button.h
 *
 * Created: 4/14/2023 8:18:07 AM
 *  Author: atef
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/dio/dio.h"


typedef enum en_ButtonError_t
{
	BUTTON_OK,
	BUTTON_ERROR,
	WRONG_BUTTON_PIN
}en_buttonError_t;



typedef enum { NPRESSED  , PRESSED} enuButtonStatus_t;


en_buttonError_t BUTTON_init (DIO_Port_type port, u8 u8_PinNumber);
en_buttonError_t BUTTON_read(DIO_Port_type port, u8 u8_PinNumber , DIO_PinVoltage_type *buttonState);
en_buttonError_t BUTTON_Check(DIO_Port_type port, u8 u8_PinNumber , DIO_PinVoltage_type *buttonState);

#endif /* BUTTON_H_ */



/*button check*/
/*
BUTTON_read(button1,&button1State);
if (button1State==LOW)
{
	
	DIO_WritePort(PB,++c);
	while(button1State==LOW)
	{
		BUTTON_read(button1,&button1State);
	}
*/	