/* 
 * File:   GetingTroubleCodes_Types.h
 * Author: Benjamin
 *
 * Created on 2019. március 31., 19:50
 */

#ifndef GETINGTROUBLECODES_TYPES_H
#define	GETINGTROUBLECODES_TYPES_H

#include "types.h"

typedef enum eGettingTroubleCodes
{
    Init,
            Querry,
} dtStates;

typedef struct sLcdRaws
{
    uint8 RawOne[16];
    uint8 RawTwo[16];
}dtLcdRaws;

typedef struct sGettingTroubleCodes
{
    dtStates SM;
    dtLcdRaws Lcd;
} dtGettingTroubleCodes;


#endif	/* GETINGTROUBLECODES_TYPES_H */

