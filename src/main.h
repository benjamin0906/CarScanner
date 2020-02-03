/* 
 * File:   main.h
 * Author: Benjamin
 *
 * Created on 2019. március 11., 22:50
 */

#ifndef MAIN_H
#define	MAIN_H

#include "types.h"
#include "Tasking.h"
#include "UartHal/UartHal.h"
#include "KWPMsgHandler/KWPMsgHandler.h"

typedef struct
{
    uint8 BOR   :1;
    uint8 POR   :1;
    uint8 PD    :1;
    uint8 TO    :1;
    uint8 RI    :1;
    uint8       :1;
    uint8 SBOREN:1;
    uint8 IPEN  :1;
}dtRCON;

typedef struct
{
    uint8 RBIF      :1;
    uint8 INT0IF    :1;
    uint8 TMR0IF    :1;
    uint8 RBIE      :1;
    uint8 INT0IE    :1;
    uint8 TMR0IE    :1;
    uint8 PEIE_GIEL :1;
    uint8 GIE_GIEH  :1;
} dtINTCON;

typedef struct
{
    uint8 T2CKPS    :2;
    uint8 TMR2ON    :1;
    uint8 T2OUTPS   :4;
    uint8           :1;
} dtT2CON;

typedef struct
{
    uint8 Period;
} dtPR2;

typedef struct
{
    uint8 TMR1IE    :1;
    uint8 TMR2IE    :1;
    uint8 CCP1IE    :1;
    uint8 SSPIE     :1;
    uint8 TXIE      :1;
    uint8 RCIE      :1;
    uint8 ADIE      :1;
    uint8 PSPIE     :1;
} dtPIE1;

typedef struct
{
    uint8 TMR1IP    :1;
    uint8 TMR2IP    :1;
    uint8 CCP1IP    :1;
    uint8 SSPIP     :1;
    uint8 TXIP      :1;
    uint8 RCIP      :1;
    uint8 ADIP      :1;
    uint8 PSPIP     :1;
} dtIPR1;

typedef struct
{
    uint8 TMR1IF    :1;
    uint8 TMR2IF    :1;
    uint8 CCP1IF    :1;
    uint8 SSPIF     :1;
    uint8 TXIF      :1;
    uint8 RCIF      :1;
    uint8 ADIF      :1;
    uint8 PSPIF     :1;
} dtPIR1;


#endif	/* MAIN_H */

