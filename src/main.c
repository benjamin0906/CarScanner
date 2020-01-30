/* 
 * File:   main.c
 * Author: Benjamin
 *
 * Created on 2019. március 11., 22:50
 */

#include <main.h>
#include "Ports/Ports.h"
#include "Utilities/Utilities.h"
#include "DisplayHandler/DisplayHandler.h"
#include "../GettingTroubleCodes.h"

#pragma config OSC = IRCIO67
#pragma config WDT = OFF
#pragma config LVP = OFF

uint32 Ticks;
uint8 abc;
#define asd LATA,1




void __interrupt(high_priority) ISRHandler(void)
{
    PIR1 &= 0b11111101;
    Tasking_TaskHandler();
    Ticks++;
    if(abc)
    {
        abc = 0;
        GpioOut(PINC4,1);
    }
    else
    {
        abc = 1;
        GpioOut(PINC4,0);
    }
}

void __interrupt(low_priority) ISRHandler2(void)
{
    //LATA ^= 0b100;
    UartHal_Handler();
    
    
}

/* Set up the 1 ms timer */
void TimerInit(void)
{
    T2CON = 0b00011111;
    PR2 = 124;
    PIE1 |= 0b10;
    IPR1 |= 0b10;
    PIR1 &= 0b11111101;
}

void Toggle(void)
{
    //LATA ^= 0b10;
}

extern void LCDInit(void);
extern void KWPMsgHandler_Task(void);
void main(void) 
{
    OSCCON=0b01110000;
    OSCTUNE = 0b01000000;
    RCON |=  0b10000000;
    //ei();
    
    TimerInit();
    UartHal_InitUart();
    
    INTCON |=0b11000000;
    TRISA=0b00000000;
    LATA=0b00000000;
    
    GpioDir(PINC4, 0);
    
    //LCDInit();
    /*LCDInit();
    Tasking_Add(100, &Toggle);
    Tasking_Start(&Toggle);
    
    Tasking_Add(1, &KWPMsgHandler_Task);
    Tasking_Start(&KWPMsgHandler_Task);
    
    Tasking_Add(1, &DisplayHandler_Task);
    Tasking_Start(&DisplayHandler_Task);
    
            
    Tasking_Add(1000, &GettingTroubleCodes_Task);
    Tasking_Start(&GettingTroubleCodes_Task);
    //KWPMsgHandler_Task();*/
    
    
    
    uint8 del1,del2;
    //LcdClear();
    while(1)
    {
        for(del1=0; del1<255;del1++) for(del2=0;del2<255;del2++);
        //MyPutc(&c,6);
    }
}

