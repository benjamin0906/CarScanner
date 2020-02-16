#include "Utilities/Utilities.h"
#include "mainUtils.h"

extern uint32 Ticks;

uint32 IsPassed(uint32 Time, uint32 limit)
{
    uint32 TickTemp = GetTicks();
    uint32 Diff;
    if(Time > TickTemp) Diff = Time-TickTemp;
    else Diff = TickTemp-Time;
    if(Diff < (uint32)limit) Diff = 0;
    return Diff;
}