/* 
 * File:   Utilities.h
 * Author: Benjamin
 *
 * Created on 2019. március 30., 18:16
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include "../types.h"
#include "../xc.h"

extern inline void output_toggle(uint8 *port,uint8 pin);
extern inline void output_high(uint8 *port,uint8 pin);
extern inline void output_low(uint8 *port,uint8 pin);
extern uint8 IsPassed(uint8 Time, uint8 limit);

#define PIN_A0  &LATA,1
#define PIN_A1  &LATA,2
#define PIN_A2  &LATA,4
#define PIN_A3  &LATA,8
#define PIN_A4  &LATA,16
#define PIN_A5  &LATA,32
#define PIN_A6  &LATA,64
#define PIN_A7  &LATA,128

#define PIN_B0  &LATB,1
#define PIN_B1  &LATB,2
#define PIN_B2  &LATB,4
#define PIN_B3  &LATB,8
#define PIN_B4  &LATB,16
#define PIN_B5  &LATB,32
#define PIN_B6  &LATB,64
#define PIN_B7  &LATB,128

#define PIN_C0  &LATC,1
#define PIN_C1  &LATC,2
#define PIN_C2  &LATC,4
#define PIN_C3  &LATC,8
#define PIN_C4  &LATC,16
#define PIN_C5  &LATC,32
#define PIN_C6  &LATC,64
#define PIN_C7  &LATC,128

#define PIN_D0  &LATD,1
#define PIN_D1  &LATD,2
#define PIN_D2  &LATD,4
#define PIN_D3  &LATD,8
#define PIN_D4  &LATD,16
#define PIN_D5  &LATD,32
#define PIN_D6  &LATD,64
#define PIN_D7  &LATD,128

#define PIN_E0  &LATE,1
#define PIN_E1  &LATE,2
#define PIN_E2  &LATE,4
#define PIN_E3  &LATE,8
#define PIN_E4  &LATE,16
#define PIN_E5  &LATE,32
#define PIN_E6  &LATE,64
#define PIN_E7  &LATE,128


#endif	/* UTILITIES_H */

