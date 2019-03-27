/* 
 * File:   KWPMsgHandler_Types.h
 * Author: Benjamin
 *
 * Created on 2019. március 20., 20:12
 */

#ifndef KWPMSGHANDLER_TYPES_H
#define	KWPMSGHANDLER_TYPES_H

#include "types.h"

typedef enum EnumSmKwp
{
    KWP_Init,
    KWP_WaitForInitResponse,
}dtEnumSmKwp;

typedef struct sKWPMsgHandler
{
    dtEnumSmKwp SM;
    uint16      Timeout;
} dtKWPMsgHandler;


#endif	/* KWPMSGHANDLER_TYPES_H */

