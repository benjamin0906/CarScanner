/* 
 * File:   KLineHAL_Types.h
 * Author: BodnárBenjamin
 *
 * Created on 08 February 2020, 19:53
 */

#ifndef KLINEHAL_TYPES_H
#define	KLINEHAL_TYPES_H

#include "types.h"

typedef enum
{
    Uninited,
    StartInit,
    FirstTwoBit,
    ThirdFourthBit,
    FifthSixthBit,
    SeventhEighth,
    StopBit,
    WaitForStartBit,
    WaitState,
    Inited,        
} dtKLineState;


#endif	/* KLINEHAL_TYPES_H */

