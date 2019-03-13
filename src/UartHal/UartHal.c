#include "UartHal.h"
#include <xc.h>

void UartHal_InitUart(void)
{
    SPBRG = 47;
    TXSTA=0b00100000;
    RCSTA = 0b10010000;
    BAUDCON &= 0b11110111;
    TRISC= 0b10000000;
    PIE1 |= 0b01000000;
}

void MyPutc(uint8 data)
{
    while((TXSTA&10)==0);
    TXREG=data;
}