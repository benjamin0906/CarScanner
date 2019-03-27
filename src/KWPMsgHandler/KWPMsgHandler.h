#include "KWPMsgHandler_Types.h"

#define FORMAT_BYTE         0xC1
#define INIT_SOURCE_ADDR    0x33
#define OWN_ADDRESS         0xF1

#define START_COMM_REQ      0x81

extern uint32 Ticks;

extern void KWPMsgHandler_Task(void);