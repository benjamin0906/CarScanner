#include "KWPMsgHandler_Types.h"

#define FORMAT_BYTE         0xC1
#define INIT_DST_ADDR    0x33
#define OWN_ADDRESS         0xF1

#define START_COMM_REQ      0x81
#define QUERY_BYTE          0xC2

extern uint32 Ticks;

extern void KWPMsgHandler_Task(void);