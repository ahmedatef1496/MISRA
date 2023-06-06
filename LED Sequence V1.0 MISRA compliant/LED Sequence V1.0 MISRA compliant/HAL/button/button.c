/*
 * button.c
 *
 * Created: 4/14/2023 8:18:20 AM
 *  Author: atef
 */ 
 #include "button.h"
en_buttonError_t BUTTON_init( DIO_Port_type port, u8 u8_PinNumber)
{
	en_buttonError_t  error = BUTTON_OK;
	
	if (u8_PinNumber <PIN_MAX && port<PORT_MAX)
	{    
				DIO_InitPin(port,u8_PinNumber,INFREE);
				error = BUTTON_OK;
	}
	else
	{
              error = WRONG_BUTTON_PIN;
	}
	
	return error;
}

en_buttonError_t BUTTON_read(DIO_Port_type port, u8 u8_PinNumber , DIO_PinVoltage_type *buttonState)
{
	en_buttonError_t  error = BUTTON_OK;
	
	if (u8_PinNumber <PIN_MAX && port<PORT_MAX)
	{
		DIO_ReadPin(port,u8_PinNumber,buttonState);
		error = BUTTON_OK;
	}
	else
	{
		error = WRONG_BUTTON_PIN;
	}
	
	return error;
} 

en_buttonError_t BUTTON_Check(DIO_Port_type port, u8 u8_PinNumber , DIO_PinVoltage_type *buttonState)
{
     BUTTON_read(port,u8_PinNumber,buttonState);
	 	
if (*buttonState==LOW)
{

	while(*buttonState==LOW)
	{
		BUTTON_read(port,u8_PinNumber,buttonState);
	}
	
}
       return PRESSED;

}