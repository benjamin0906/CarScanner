/* 
 * File:   main.c
 * Author: Benjamin
 *
 * Created on 2019. m�rcius 11., 22:50
 */

#include <main.h>
#include "Ports/Ports.h"
#include "Utilities/Utilities.h"
#include "DisplayHandler/DisplayHandler.h"
//#include "../GettingTroubleCodes.h"

/* Device will use the external crystal with 4x PLL */
#pragma config OSC = HSPLL
#pragma config WDT = OFF
#pragma config LVP = OFF

uint32 Ticks;
uint8 abc;

static dtRCON   *const RCON     = (dtRCON*)     0xFD0;
static dtINTCON *const INTCON   = (dtINTCON*)   0xFF2;
static dtT2CON  *const T2CON    = (dtT2CON*)    0xFCA;
static dtPR2    *const PR2      = (dtPR2*)      0xFCB;
static dtPIE1   *const PIE1     = (dtPIE1*)     0xF9D;
static dtIPR1   *const IPR1     = (dtIPR1*)     0xF9F;
static dtPIR1   *const PIR1     = (dtPIR1*)     0xF9E;


void __interrupt(high_priority) ISRHandler(void)
{
    PIR1->TMR2IF = 0;
    Tasking_TaskHandler();
    Ticks++;
    GpioToggle(PINC4);
    /*if(abc)
    {
        abc = 0;
        GpioOut(PINC4,1);
    }
    else
    {
        abc = 1;
        GpioOut(PINC4,0);
    }*/
}

void __interrupt(low_priority) ISRHandler2(void)
{
    //LATA ^= 0b100;
    UartHal_Handler();
    
    
}

/* Set up the 1 ms timer */
void TimerInit(void)
{
    T2CON->T2CKPS = 0x3;
    T2CON->T2OUTPS = 0x04;
    T2CON->TMR2ON = 1;
    PR2->Period = 124;
    PIE1->TMR2IE = 1;
    IPR1->TMR2IP = 1;
    PIR1->TMR2IF = 0;
}

void Toggle(void)
{
    //LATA ^= 0b10;
}

extern void LCDInit(void);
extern void KWPMsgHandler_Task(void);
void main(void) 
{
    {
        uint8 delay;
        for(delay = 0; delay < 250; delay++);
    }
    /* Enable priority levels on interrupts */
    RCON->IPEN = 1;
    
    /* Enable global interrupt */
    INTCON->GIE_GIEH = 1;
    
    /* Enable peripheral interrupt. */
    INTCON->PEIE_GIEL = 1;
    
    TimerInit();
    UartHal_InitUart();
    
    GpioDir(PINC4, 0);
    
    LCDInit();
    //Tasking_Add(100, &Toggle);
    //Tasking_Start(&Toggle);
    
    //Tasking_Add(1, &KWPMsgHandler_Task);
    //Tasking_Start(&KWPMsgHandler_Task);
    
    Tasking_Add(1, &DisplayHandler_Task);
    Tasking_Start(&DisplayHandler_Task);
    
            
    //Tasking_Add(1000, &GettingTroubleCodes_Task);
    // Tasking_Start(&GettingTroubleCodes_Task);
    //KWPMsgHandler_Task();*/
    
    
    
    uint8 del1,del2;
    uint8 c[] = "Szia! :)";
    PutStr(&c,0);
    //LcdClear();
    while(1)
    {
        for(del1=0; del1<255;del1++) for(del2=0;del2<255;del2++);
        
    }
}

