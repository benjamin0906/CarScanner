/* 
 * File:   Utilities.h
 * Author: Benjamin
 *
 * Created on 2019. március 30., 18:16
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include "../types.h"
#include "Ports.h"

extern inline void output_toggle(uint8 *port,uint8 pin);
extern inline void output_high(uint8 *port,uint8 pin);
extern inline void output_low(uint8 *port,uint8 pin);
extern uint8 IsPassed(uint8 Time, uint8 limit);

#define PIN_A0  LAT_A,1
#define PIN_A1  LAT_A,2
#define PIN_A2  LAT_A,4
#define PIN_A3  LAT_A,8
#define PIN_A4  LAT_A,16
#define PIN_A5  LAT_A,32
#define PIN_A6  LAT_A,64
#define PIN_A7  LAT_A,128

#define PIN_B0  LAT_B,1
#define PIN_B1  LAT_B,2
#define PIN_B2  LAT_B,4
#define PIN_B3  LAT_B,8
#define PIN_B4  LAT_B,16
#define PIN_B5  LAT_B,32
#define PIN_B6  LAT_B,64
#define PIN_B7  LAT_B,128

#define PIN_C0  LAT_C,1
#define PIN_C1  LAT_C,2
#define PIN_C2  LAT_C,4
#define PIN_C3  LAT_C,8
#define PIN_C4  LAT_C,16
#define PIN_C5  LAT_C,32
#define PIN_C6  LAT_C,64
#define PIN_C7  LAT_C,128

#endif	/* UTILITIES_H */

