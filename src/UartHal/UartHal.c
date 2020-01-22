#include "UartHal.h"
#include "Ports.h"
#include "../UartHal_Types.h"

dtUartHal UartHal;

void UartHal_InitUart(void)
{
    /* 32000000 MHz /64/(SPBRG+1) = baud
     * 32000000 MHz/64/(47+1) = 10416
     * 32000000 MHz/64/(51+1) = 9600 */
    //SPBRG = 47;
    *SPBRG = 51;
    
    /* TXSTA: Clock Source select | 9-Bit transmit | Transmit EN | Synch/Asynch | Send break | High/Low baud | TRMT | 9th bit
     * RCSTA: serial port EN | 9bit rcv EN | Single rcv | ... */
    *TXSTA=0b00100000;
    *RCSTA = 0b10010000;
    *BAUDCON &= 0b11110111;
    *TRISC= 0b10000000;
    *PIR1 &= 0b11011111;
    *PIE1 |= 0b00100000;
    *IPR1 &= 0b11001111;
}

void MyPutData(uint8 *data, uint8 Amount)
{
    UartHal.TxIndex=0;
    uint8 looper=0;
    for(looper = 0; looper< Amount; looper++) UartHal.TxBuff[looper] = data[looper];
    UartHal.TxAmount=Amount;
    *PIE1 |= 0b00010000;
}

void MyGetc(uint8* data)
{
    *data = *RCREG;
}

void UartHal_Handler(void)
{
    /* UART receive interrupt check */
    if((*PIR1 & 0b00100000) != 0)
    {
        uint8 received;
        MyGetc(&received);
        if(UartHal.RxIndex == 0)
        {
            /* Check if first byte received */
            if((received >= 0x81) && (received <= 0x87))
            {
                /* Besides this of the data bytes 4 other bytes arrive too. The first byte (with size), src and dst adresses, and checksum. */
                UartHal.RxArrivedAmount = received - 0x80;
                UartHal.RxBuff[UartHal.RxIndex++] = received;
                UartHal.CRC = received;
            }
        }
        else
        {
            if((UartHal.RxIndex) < (UartHal.RxArrivedAmount + 4))
            {
                if((UartHal.RxIndex) < (UartHal.RxArrivedAmount + 3))
                {
                    UartHal.RxBuff[UartHal.RxIndex++] = received;
                    UartHal.CRC += received;
                }
                else
                {
                    /* This branch is for the CRC byte */
                    if(UartHal.CRC == received) UartHal.NewArrived = true;
                    UartHal.RxIndex = 0;
                }
            }

        }
    }
    
    /* UART tx buffer empty interrupt check */
    if(((*PIE1 & 0b00010000) != 0) && ((*PIR1 & 0b00010000) != 0))
    {
        if(UartHal.TxIndex < UartHal.TxAmount) *TXREG=UartHal.TxBuff[UartHal.TxIndex++];
        else *PIE1 &= 0b11101111; 
    }
}