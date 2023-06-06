/*
 * dio.h
 *
 * Created: 4/13/2023 6:41:52 AM
 *  Author: atef
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "../../SERVIES/memmap.h"
#include "../../SERVIES/utils.h"
#include "../../SERVIES/std_typs.h"

#define  PIN_MAX     8
#define  PORT_MAX    4

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	LOW=0,
	HIGH,
}DIO_PinVoltage_type;





typedef enum dioError{
	DIO_OK,
	WRONG_PortNumber,
	WRONG_PinNumber,
	WRONG_VALUE,
	WRONG_DIRECTION
}en_dioError_t;


////////////port mode////////////////////////////////////////////////////////

  en_dioError_t  DIO_InitPin   (DIO_Port_type port, u8 pin_num, DIO_PinStatus_type status);
  en_dioError_t  DIO_WritePin  (DIO_Port_type port, u8 pin_num, DIO_PinVoltage_type volt);
  en_dioError_t  DIO_TogglePin (DIO_Port_type port, u8 pin_num);
  en_dioError_t  DIO_ReadPin   (DIO_Port_type port, u8 pin_num,DIO_PinVoltage_type *volt);
  en_dioError_t  DIO_WritePort (DIO_Port_type port, u8 value);

#endif /* DIO_H_ */