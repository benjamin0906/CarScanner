#include "Tasking_Types.h"

extern void Tasking_TaskHandler(void);
extern void Tasking_Add(uint8 Period, void (*Runnable)(void));
extern void Tasking_Start(void (*Runnable)(void));
extern void Tasking_Stop(void (*Runnable)(void));
extern void Tasking_Remove(void (*Runnable)(void));