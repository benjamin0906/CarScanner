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
//#include "../GettingTroubleCodes.h"
#include "KLineHAL/KLineHAL.h"

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

uint32 GetTicks(void);

void __interrupt(high_priority) ISRHandler(void)
{
    Tasking_TaskHandler();
    Ticks++;
    PIR1->TMR2IF = 0;
}

void __interrupt(low_priority) ISRHandler2(void)
{
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

extern void LCDInit(void);
extern void KWPMsgHandler_Task(void);
void main(void) 
{
    {
        uint8 delay;
        uint8 delay2;
        for(delay = 0; delay < 250; delay++) for(delay2 = 0; delay2 < 250; delay2 ++);
    }
    /* Enable priority levels on interrupts */
    RCON->IPEN = 1;
    
    /* Enable globalrr interrupt */
    INTCON->GIE_GIEH = 1;
    
    /* Enable peripheral interrupt. */
    INTCON->PEIE_GIEL = 1;
    
    /* Start the tasking timer */
    TimerInit();
    
    /* Initialise the Red led */
    GpioDir(PINC4, 0);
    GpioOut(PINC4, 1);
    
    KLineHal_Init();
    
    {
        uint8 delay;
        uint8 delay2;
        for(delay = 0; delay < 250; delay++) for(delay2 = 0; delay2 < 250; delay2 ++);
    }
    KLineHal_StartInit();//*/
    
    //UartHal_InitUart();
    
    //LCDInit();
            
    //Tasking_Add(1000, &GettingTroubleCodes_Task);
    // Tasking_Start(&GettingTroubleCodes_Task);
    
    uint8 del1,del2;
    uint8 c[] = "Sziaaa! :)";
    PutStr(&c,0);
    //LcdClear();
    while(1)
    {
        for(del1=0; del1<255;del1++) for(del2=0;del2<255;del2++);
        
    }
}

uint32 GetTicks(void)
{
    return Ticks;
}

