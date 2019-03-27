#include "KWPMsgHandler.h"
#include "../UartHal/UartHal.h"

dtKWPMsgHandler KWPMsgHandler;

#define WAIT_TIMEOUT    60000

uint8 CalcCheckSum(uint8 *data,uint8 len)
{
    uint8 ret = 0;
    uint8 looper;
    for(looper=0; looper<len; looper++) ret += data[looper];
    return ret;
}


void KWPMsgHandler_Task(void)
{
    switch(KWPMsgHandler.SM)
    {
        case KWP_Init:
        {
            uint8 temp[5]={FORMAT_BYTE,INIT_SOURCE_ADDR,OWN_ADDRESS,START_COMM_REQ};
            temp[4] = CalcCheckSum(&temp[0],4);
            MyPutc(&temp[0],5);
            KWPMsgHandler.SM = KWP_WaitForInitResponse;
            KWPMsgHandler.Timeout = Ticks;
            break;
        }
            
        case KWP_WaitForInitResponse:
            if((UartHal.NewArrived == true) && (KWPMsgHandler.Timeout <= WAIT_TIMEOUT))
            {
                UartHal.NewArrived = false;
                KWPMsgHandler.SM = KWP_Init;
            }
            break;
    }
}