#include "KWPMsgHandler.h"
#include "../UartHal/UartHal.h"

#define WAIT_TIMEOUT    60000

dtKWPMsgHandler KWPMsgHandler;

void SetMsg(void);

uint8 SetOperational(dtOp Op)
{
    uint8 ret=0;
    if(KWPMsgHandler.SM < KWP_InitDone)
    {
        ret = 1;
    }
    else if(KWPMsgHandler.SM == KWP_InitDone)
    {
        
    }
}

uint8 CalcCheckSum(uint8 *data,uint8 len)
{
    uint8 ret = 0;
    uint8 looper;
    for(looper=0; looper<len; looper++) ret += data[looper];
    return ret;
}


void AssebleQueryMsg(uint8 Service, uint8 PID)
{
    dtMsg Tmp;
    Tmp.FormatByte = QUERY_BYTE;
    Tmp.DstAddr = INIT_DST_ADDR;
    //Tmp.DstAddr = KWPMsgHandler.ECUAddr;
    Tmp.SrcAddr = OWN_ADDRESS;
    Tmp.ServiceID = Service;
    Tmp.PID = PID;
    Tmp.CRC = CalcCheckSum(&Tmp,sizeof(dtMsg)-1);
    MyPutData(&Tmp,sizeof(dtMsg));
    KWPMsgHandler.QuerriedService = Service;
    KWPMsgHandler.QuerriedPID = PID;
    KWPMsgHandler.WaitForAnswer = true;
}



void KWPMsgHandler_Task(void)
{
    switch(KWPMsgHandler.SM)
    {
        case KWP_Init:
        {
            uint8 temp[5]={FORMAT_BYTE,INIT_DST_ADDR,OWN_ADDRESS,START_COMM_REQ};
            temp[4] = CalcCheckSum(&temp[0],4);
            MyPutData(&temp[0],5);
            KWPMsgHandler.SM = KWP_WaitForInitResponse;
            KWPMsgHandler.Timeout = Ticks;
            break;
        }
            
        case KWP_WaitForInitResponse:
            if((UartHal.NewArrived == true) && (KWPMsgHandler.Timeout <= WAIT_TIMEOUT))
            {
                UartHal.NewArrived = false;
                KWPMsgHandler.ECUAddr = UartHal.RxBuff[2];
                uint16 KeyBytes = *(uint16*)&UartHal.RxBuff[4];
                switch(KeyBytes)
                {
                    case 0x8FE9:
                    case 0xE98F:
                    case 0x8F6B:
                    case 0x6B8F:
                    case 0x8F6D:
                    case 0x6D8F:
                    case 0x8FEF:
                    case 0xEF8F:
                        AssebleQueryMsg(1,0);
                        KWPMsgHandler.SM = KWP_InitDone;
                        break;
                    case 0x0808:
                    case 0x9494:
                        break;
                }
            }
            break;
        case KWP_InitDone:
            if(KWPMsgHandler.WaitForAnswer == true)
            {
                if((UartHal.NewArrived == true) && (KWPMsgHandler.QuerriedService == (UartHal.RxBuff[3]&0x0f)) && (KWPMsgHandler.QuerriedPID == (UartHal.RxBuff[4]&0x0f)))
                {
                    SetMsg();
                }
            }
            break;
        case KWP_WaitResponse:
            if(KWPMsgHandler.WaitForAnswer == true)
            {
                if((UartHal.NewArrived == true) && (KWPMsgHandler.QuerriedService == (UartHal.RxBuff[3]&0x0f)) && (KWPMsgHandler.QuerriedPID == (UartHal.RxBuff[4]&0x0f)))
                {
                    SetMsg();
                    KWPMsgHandler.SM = KWPMsgHandler.NextSM;
                }
            }
            break;
        case KWP_GettingTroubles:
            AssebleQueryMsg(1,1);
            KWPMsgHandler.SM = KWP_WaitResponse;
            KWPMsgHandler.NextSM = KWP_GettingTroublesArrived;
            break;
        case KWP_GettingTroublesArrived:
            break;
    }
}

void CopyMsg(uint8 num)
{
	if(KWPMsgHandler.ReceivedMsgs < 4)
    {
        uint8 looper=5;
        while((looper < (UartHal.RxBuff[0]-0x80)))
        {
            looper++;
            KWPMsgHandler.Msg[KWPMsgHandler.ReceivedMsgs++] = UartHal.RxBuff[looper];
        }
    }
}

void SetMsg(void)
{
	switch(KWPMsgHandler.QuerriedService)
    {
        case 0x01:
            switch(KWPMsgHandler.QuerriedPID)
            {
                case 0x00:
                case 0x01:
                case 0x0D:
                case 0x0E:
                case 0x0F:
                case 0x20:
                case 0x24:
                case 0x25:
                case 0x26:
                case 0x27:
                case 0x28:
                case 0x29:
                case 0x2A:
                case 0x2B:
                case 0x34:
				case 0x35:
				case 0x36:
				case 0x37:
				case 0x38:
				case 0x39:
				case 0x3A:
				case 0x3B:
                case 0x40:
				case 0x41:
                case 0x4F:
				case 0x50:
                case 0x60:
                case 0x80:
                case 0x9B:
                case 0x9D:
				case 0xA0:
                case 0xA4:
                case 0xA5:
				case 0xA6:
                    CopyMsg(4);
                    break;
                case 0x02:
                case 0x03:
                case 0x0C:
                case 0x10:
                case 0x14:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1A:
                case 0x1B:
                case 0x1F:
                case 0x21:
                case 0x22:
                case 0x23:
                case 0x31:
				case 0x32:
                case 0x3C:
				case 0x3D:
				case 0x3E:
				case 0x3F:
                case 0x42:
				case 0x43:
				case 0x44:
                case 0x4D:
				case 0x4E:
                case 0x53:
				case 0x54:
				case 0x55:
				case 0x56:
				case 0x57:
				case 0x58:
				case 0x59:
                case 0x5D:
				case 0x5E:
                case 0x63:
                case 0x65:
                case 0x92:
                case 0x9E:
                case 0xA2:
                    CopyMsg(2);
                    break;
                    
                case 0x04:
                case 0x05:
                case 0x06:
                case 0x07:
                case 0x08:
                case 0x09:
                case 0x0A:
                case 0x0B:
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x1C:
                case 0x1D:
                case 0x1E:
                case 0x2C:
                case 0x2D:
                case 0x2E:
                case 0x2F:
				case 0x30:
                case 0x33:
                case 0x45:
				case 0x46:
				case 0x47:
				case 0x48:
				case 0x49:
				case 0x4A:
				case 0x4B:
				case 0x4C:
                case 0x51:
				case 0x52:
                case 0x5A:
				case 0x5B:
				case 0x5C:
                case 0x5F:
                case 0x61:
				case 0x62:
                case 0x7D:
				case 0x7E:
                case 0x84:
                case 0x8D:
				case 0x8E:
                    CopyMsg(1);
                    break;
                    
				case 0x64:
                case 0x66:
                case 0x6A:
                case 0x6B:
                case 0x6C:
                case 0x6E:
                case 0x71:
                case 0x72:
				case 0x73:
				case 0x74:
                case 0x77:
                case 0x83:
                case 0x86:
				case 0x87:
                case 0x8F:
                case 0x91:
                    CopyMsg(5);
					break;

				case 0x67:
                case 0x6F:
                case 0x90:
                case 0x93:
                    CopyMsg(3);
					break;
                    
				case 0x68:
				case 0x69:
                case 0x75:
				case 0x76:
                case 0x7A:
				case 0x7B:
                case 0x8B:
                    CopyMsg(7);
					break;

				case 0x6D:
                case 0x9A:
                    CopyMsg(6);
					break;

				case 0x70:
                case 0x78:
				case 0x79:
                case 0x7C:
                case 0x98:
				case 0x99:
				case 0x9F:
				case 0xA1:
                case 0xA3:
                    CopyMsg(9);
					break;

				case 0x7F:
                case 0x88:
                    CopyMsg(13);
					break;
                   
				case 0x81:
				case 0x82:
                    CopyMsg(21);
					break;

				case 0x85:
                    CopyMsg(10);
					break;

				case 0x89:
				case 0x8A:
                    CopyMsg(41);
					break;

				case 0x8C:
                    CopyMsg(16);
					break;
             
				case 0x94:
                    CopyMsg(12);
					break;

				case 0x9C:
                    CopyMsg(17);
					break;                
            }
            break;
        case 0x02:
            break;
        case 0x03:
            break;
        case 0x04:
            break;
        case 0x05:
            break;
        case 0x09:
            break;
    }
}