#include "Tasking.h"

#define MAX_NUM_OF_TASKS    10

dtTask  Tasks[MAX_NUM_OF_TASKS];
uint8   FreeSlots[MAX_NUM_OF_TASKS];

void Tasking_TaskHandler(void)
{
    uint8 looper;
    for(looper=0; looper<MAX_NUM_OF_TASKS; looper++)
    {
        if(Tasks[looper].Run != 0)
        {
            Tasks[looper].PeriodCounter++;
            if(Tasks[looper].PeriodCounter == Tasks[looper].Period)
            {
                if(Tasks[looper].Runnable != 0) Tasks[looper].Runnable();
                Tasks[looper].PeriodCounter=0;
            }
        }
    }
}

void Tasking_Add(uint8 Period, void (*Runnable)(void))
{
    uint8 looper=0;
    while((Tasks[looper].Runnable != Runnable) && (looper < MAX_NUM_OF_TASKS)) looper++;
    if(looper == MAX_NUM_OF_TASKS)
    {
        looper=0;
        while((FreeSlots[looper] != false) && (looper < MAX_NUM_OF_TASKS)) looper++;
        if(looper != MAX_NUM_OF_TASKS)
        {
            Tasks[looper].Period=Period;
            Tasks[looper].Runnable=Runnable;
            Tasks[looper].PeriodCounter=0;
            FreeSlots[looper]=true;
        }
    }
}

void Tasking_Start(void (*Runnable)(void))
{
    uint8 looper=0;
    while((Tasks[looper].Runnable != Runnable) && (looper < MAX_NUM_OF_TASKS)) looper++;
    if(looper != MAX_NUM_OF_TASKS) Tasks[looper].Run=true;
}

void Tasking_Stop(void (*Runnable)(void))
{
    uint8 looper=0;
    while((Tasks[looper].Runnable != Runnable) && (looper < MAX_NUM_OF_TASKS)) looper++;
    if(looper != MAX_NUM_OF_TASKS) Tasks[looper].Run=false;
}

void Tasking_Remove(void (*Runnable)(void))
{
    uint8 looper=0;
    while((Tasks[looper].Runnable != Runnable) && (looper < MAX_NUM_OF_TASKS)) looper++;
    if(looper != MAX_NUM_OF_TASKS)
    {
        FreeSlots[looper]=false;
        Tasks[looper].Run=0;
        Tasks[looper].Runnable=NULL;
    }
}
