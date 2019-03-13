/* 
 * File:   main.h
 * Author: Benjamin
 *
 * Created on 2019. március 11., 22:50
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "types.h"

#define MAX_NUM_OF_TASKS    10

typedef struct sTask
{
    void (*Runnable)(void);
    uint8 Period;
    uint8 PeriodCounter;
    uint8 Run;
}dtTask;

#endif	/* MAIN_H */

