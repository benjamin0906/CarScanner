#include "UartHal.h"
#include <xc.h>

uint8 TxBuff

void UartHal_InitUart(void)
{
    SPBRG = 47;
    TXSTA=0b00100000;
    RCSTA = 0b10010000;
    BAUDCON &= 0b11110111;
    TRISC= 0b10000000;
    PIR1 &= 0b11011111;
    PIE1 |= 0b00100000;
    IPR1 &= 0b11011111;
}

void MyPutc(uint8 data)
{
    while((TXSTA&10)==0);
    TXREG=data;
}

void MyGetc(uint8* data)
{
    *data = RCREG;
}

void UartHal_Handler(void)
{
    
}