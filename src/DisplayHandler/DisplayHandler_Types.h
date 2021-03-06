/* 
 * File:   DisplayHandler_Types.h
 * Author: Benjamin
 *
 * Created on 2019. m�rcius 30., 17:59
 */

#ifndef DISPLAYHANDLER_TYPES_H
#define	DISPLAYHANDLER_TYPES_H

#include "types.h"
#include "../Ports/Ports.h"
#include "../Utilities/Utilities.h"

#define LCD_RS  PINC3
#define LCD_RW  PINC1
#define LCD_EN  PINC0
#define LCD_D4  PINA5
#define LCD_D5  PINB2
#define LCD_D6  PINA4
#define LCD_D7  PINA2

#define LCD_BUFFER_SIZE 30

typedef enum eStateMachine
{
    
    LcdSetPinsHighNibble,
    LcdSetPinsLowNibble,
            LcdEnter_Wait,
} dtStateMachine;

typedef struct sOutputData
{
    uint8   data;
    uint8   DataOrCmd:1;
}dtOutputData;

typedef struct sDisplayHandler
{
    uint8           Timer;
    dtStateMachine  SM;
    dtOutputData    OutputBuffer[LCD_BUFFER_SIZE];
    uint8           OutputNum;
    uint8           OutputCntr;
    uint8           NextSm;
} dtDisplayHandler;

#endif	/* DISPLAYHANDLER_TYPES_H */

