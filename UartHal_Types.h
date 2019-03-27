/* 
 * File:   UartHal_Types.h
 * Author: Benjamin
 *
 * Created on 2019. március 15., 11:59
 */

#ifndef UARTHAL_TYPES_H
#define	UARTHAL_TYPES_H

#include "types.h"

#define MAX_NUM_OF_MESSAGE  11

typedef struct sUart
{
    uint8 TxBuff[MAX_NUM_OF_MESSAGE];
    uint8 RxBuff[MAX_NUM_OF_MESSAGE];
    uint8 TxIndex;
    uint8 TxAmount;
    uint8 RxIndex;
    uint8 RxArrivedAmount;
    uint8 NewArrived;
    uint8 CRC;
} dtUartHal;

#endif	/* UARTHAL_TYPES_H */

