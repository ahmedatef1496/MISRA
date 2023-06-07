/*
 * dio.c
 *
 * Created: 4/13/2023 6:42:07 AM
 *  Author: atef
 */ 
#include "dio.h"


    en_dioError_t  DIO_InitPin  (DIO_Port_type port, u8 u8_PinNumber, DIO_PinStatus_type status)	
    {
	    en_dioError_t error = DIO_OK;
	    if (u8_PinNumber < PIN_MAX)
	    {

		    switch(status)
		    {
			    case OUTPUT:
			    switch(port)
			    {
				    case PA:
				    SET_BIT( DDRA,u8_PinNumber);
				    CLR_BIT( PORTA,u8_PinNumber);
				    break;
				    case PB:
				    SET_BIT( DDRB,u8_PinNumber);
				    CLR_BIT(PORTB,u8_PinNumber);
				    break;
				    case PC:
				    SET_BIT( DDRC,u8_PinNumber);
				    CLR_BIT(PORTC,u8_PinNumber);
				    break;
				    case PD:
				    SET_BIT( DDRD,u8_PinNumber);
				    CLR_BIT(PORTD,u8_PinNumber);
				    break;
				    default:
				    error = WRONG_PortNumber;
				    break;
			    }
			    break;
			    case INFREE:
			    switch(port)
			    {
				    case PA:
				    CLR_BIT(DDRA,u8_PinNumber);
				    CLR_BIT(PORTA,u8_PinNumber);
				    break;
				    case PB:
				    CLR_BIT(DDRB,u8_PinNumber);
				    CLR_BIT(PORTB,u8_PinNumber);
				    break;
				    case PC:
				    CLR_BIT(DDRC,u8_PinNumber);
				    CLR_BIT(PORTC,u8_PinNumber);
				    break;
				    case PD:
				    CLR_BIT(DDRD,u8_PinNumber);
				    CLR_BIT(PORTD,u8_PinNumber);
				    break;
				    default:
				    error = WRONG_PortNumber;
				    break;
			    }
			    break;

			    case INPULL:
			    switch(port)
			    {
				    case PA:
				    CLR_BIT(DDRA,u8_PinNumber);
				    SET_BIT(PORTA,u8_PinNumber);
				    break;
				    case PB:
				    CLR_BIT(DDRB,u8_PinNumber);
				    SET_BIT(PORTB,u8_PinNumber);
				    break;
				    case PC:
				    CLR_BIT(DDRC,u8_PinNumber);
				    SET_BIT(PORTC,u8_PinNumber);
				    break;
				    case PD:
				    CLR_BIT(DDRD,u8_PinNumber);
				    SET_BIT(PORTD,u8_PinNumber);
				    break;
				    default:
				    error = WRONG_PortNumber;
				    break;
			    }
			    break;
			    default:
			    error  = WRONG_PortNumber;
			    break;
		    }
	    }
	    else
	    {
		    error = WRONG_PinNumber;
	    }
	    return error;

    }
    en_dioError_t  DIO_WritePin (DIO_Port_type port, u8 u8_PinNumber, DIO_PinVoltage_type volt)		
    {
	    en_dioError_t error= DIO_OK;
	    if (port<PIN_MAX)
	    {
		    switch (volt)
		    {
			    case HIGH:

			    switch(port)
			    {
				    case PA:

				    SET_BIT(PORTA,u8_PinNumber);
				    break;
				    case PB:

				    SET_BIT(PORTB,u8_PinNumber);
				    break;
				    case PC:

				    SET_BIT(PORTC,u8_PinNumber);
				    break;
				    case PD:

				    SET_BIT(PORTD,u8_PinNumber);
				    break;
				    default:
				    error = WRONG_PortNumber;
				    break;
			    }
			    break;

			    case LOW:

			    switch(port)
			    {
				    case PA:

				    CLR_BIT(PORTA,u8_PinNumber);
				    break;
				    case PB:

				    CLR_BIT(PORTB,u8_PinNumber);
				    break;
				    case PC:

				    CLR_BIT(PORTC,u8_PinNumber);
				    break;
				    case PD:

				    CLR_BIT(PORTD,u8_PinNumber);
				    break;
				    default:
				    error = WRONG_PortNumber;
				    break;
			    }

			    break;

			    default:
			    error = WRONG_VALUE;
			    break;

		    }
	    }
	    else
	    {
		    error = WRONG_PinNumber;
	    }
	    return error;
    }
    en_dioError_t  DIO_TogglePin(DIO_Port_type port, u8 u8_PinNumber)						
    {
	    en_dioError_t error = DIO_OK;
	    if (u8_PinNumber< PIN_MAX)
	    {
		    switch(port)
		    {
			    case PA:
			    TGL_BIT(PORTA,u8_PinNumber);
			    break;
			    case PB:
			    TGL_BIT(PORTB,u8_PinNumber);
			    break;
			    case PC:
			    TGL_BIT(PORTC,u8_PinNumber);
			    break;
			    case PD:
			    TGL_BIT(PORTD,u8_PinNumber);
			    break;
			    default:
			    error = WRONG_PortNumber;
			    break;
		    }
	    }
	    else
	    {
		    error = WRONG_PinNumber;
	    }
	    return error;
    }
    en_dioError_t  DIO_ReadPin  (DIO_Port_type port, u8 u8_PinNumber,DIO_PinVoltage_type *volt)
    {
	    en_dioError_t error = DIO_OK;
	    if (u8_PinNumber <PIN_MAX )
	    {

		    switch(port)
		    {
			    case PA:

			    *volt=READ_BIT(PINA,u8_PinNumber);
			    break;
			    case PB:

			    *volt=READ_BIT(PINB,u8_PinNumber);
			    break;
			    case PC:

			    *volt=READ_BIT(PINC,u8_PinNumber);
			    break;
			    case PD:

			    *volt=READ_BIT(PIND,u8_PinNumber);
			    break;
			    default:
			    error = WRONG_PortNumber;
			    break;
		    }

	    }
	    else
	    {
		    error = WRONG_PinNumber;
	    }
	    return error;
    }
    en_dioError_t  DIO_WritePort(DIO_Port_type port, u8 value)
    {
	    en_dioError_t error = DIO_OK;
	    if (port < PORT_MAX)
	    {

		    switch(port)
		    {
			    case PA:

			    PORTA=value;
			    break;
			    case PB:

			    PORTB=value;
			    break;
			    case PC:

			    PORTC=value;
			    break;
			    case PD:

			    PORTD=value;
			    break;
			    default:
			    error = WRONG_PortNumber;
			    break;
		    }
	    }
	    else
	    {
		    error = WRONG_PortNumber;
	    }
		
	    return error;
    }

 