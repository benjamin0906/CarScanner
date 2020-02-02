#include "Utilities/Utilities.h"

extern uint32 Ticks;

uint8 IsPassed(uint8 Time, uint8 limit)
{
    uint8 TickTemp = (uint8)Ticks;
    uint8 Diff;
    if(Time > TickTemp) Diff = Time-TickTemp;
    else Diff = TickTemp-Time;
    if(Diff < limit) Diff = 0;
    return Diff;
}