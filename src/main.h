/* 
 * File:   main.h
 * Author: Benjamin
 *
 * Created on 2019. március 11., 22:50
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "types.h"
#include "Tasking.h"
#include "UartHal/UartHal.h"
#include "KWPMsgHandler/KWPMsgHandler.h"

typedef struct
{
    uint8 BOR:1;
    uint8 POR:1;
    uint8 PD:1;
    uint8 TO:1;
    uint8 RI:1;
    uint8 :1;
    uint8 SBOREN:1;
    uint8 IPEN:1;
}dtRcon;

typedef struct
{
    uint8 RBIF:1;
    uint8 INT0IF:1;
    uint8 TMR0IF:1;
    uint8 RBIE:1;
    uint8 INT0IE:1;
    uint8 TMR0IE:1;
    uint8 PEIE_GIEL:1;
    uint8 GIE_GIEH:1;
} dtIntCon;

typedef struct
{
    uint8 T2CKPS:2;
    uint8 TMR2ON:1;
    uint8 T2OUTPS:4;
    uint8 :1;
} dtT2Con;

#endif	/* MAIN_H */

