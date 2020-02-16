#include "KLineHAL_Types.h"
#include "Tasking.h"
#include "../Ports/Ports.h"
#include "../Utilities/Utilities.h"

static dtTask Task;
static dtKLineState State;
static dtKLineState NextState;
static uint8 TurnOn;
static uint32 Timeout;
static uint32 Time;

void KLineHal_Init(void);
void KLineHal_Task(void);
void KLineHal_StartInit(void);
uint8 Initialization(void);

void KLineHal_Init(void)
{
    Tasking_Add(1,&KLineHal_Task);
    Tasking_Start(&KLineHal_Task);
    GpioDir(PINC5,0);
    GpioDir(PINC6,0);
    GpioDir(PINC7,1);
    
    GpioOut(PINC5,1);
    GpioOut(PINC6,1);
    
    TurnOn = 1;
    
    Time = GetTicks();
}


void KLineHal_Task(void)
{
    switch(State)
    {
        case Uninited:
            if((IsPassed(Time,1000) != 0) && (TurnOn == 1))
            {
                /* Turn on the communication */
                State = StartInit;
            }
            break;
        case StartInit:
            GpioOut(PINC6,0);
            Time = GetTicks();
            Timeout = 200;
            NextState = FirstTwoBit;
            State = WaitState;
            break;
        case FirstTwoBit:
            GpioOut(PINC6,1);
            Time = GetTicks();
            Timeout = 400;
            NextState = ThirdFourthBit;
            State = WaitState;
            break;
        case ThirdFourthBit:
            GpioOut(PINC6,0);
            Time = GetTicks();
            Timeout = 400;
            NextState = FifthSixthBit;
            State = WaitState;
            break;
        case FifthSixthBit:
            GpioOut(PINC6,1);
            Time = GetTicks();
            Timeout = 400;
            NextState = SeventhEighth;
            State = WaitState;
            break;
        case SeventhEighth:
            GpioOut(PINC6,0);
            Time = GetTicks();
            Timeout = 400;
            NextState = StopBit;
            State = WaitState;
            break;
        case StopBit:
            GpioOut(PINC6,1);
            Time = GetTicks();
            Timeout = 200;
            NextState = WaitForStartBit;
            State = WaitState;
            break;
        case WaitState:
            if(IsPassed(Time,Timeout))
            {
                State = NextState;
            }
            break;
        case WaitForStartBit:
            if(GpioIn(PINC5) != 0)
            {
                
            }
            break;
        case Inited:
            break;
    }
}

void KLineHal_StartInit(void)
{
    TurnOn = 1;
}