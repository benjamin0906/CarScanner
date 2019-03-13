/* 
 * File:   Tasking_Types.h
 * Author: Benjamin
 *
 * Created on 2019. március 12., 22:30
 */

#ifndef TASKING_TYPES_H
#define	TASKING_TYPES_H

#include "../types.h"

typedef struct sTask
{
    void (*Runnable)(void);
    uint8 Period;
    uint8 PeriodCounter;
    uint8 Run;
}dtTask;

#endif	/* TASKING_TYPES_H */

