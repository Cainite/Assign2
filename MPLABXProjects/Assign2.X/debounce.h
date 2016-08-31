/* 
 * File:   debounce.h
 * Author: 12050302
 *
 * Created on 9 August 2016, 2:18 PM
 */

#ifndef DEBOUNCE_H
#define	DEBOUNCE_H

#include "config.h"
#include <xc.h>

#define PB1 !RB2
#define PB2 !RB3
#define PB3 !RB4
#define PB4 !RB5

#define DEBOUNCE_REQ_COUNT 10

extern volatile bit pb1Pressed ;
extern volatile bit pb2Pressed ;
extern volatile bit pb3Pressed ;
extern volatile bit pb4Pressed ;

extern volatile bit pb1Released ;
extern volatile bit pb2Released ;
extern volatile bit pb3Released ;
extern volatile bit pb4Released ;

extern volatile unsigned char pb1DebounceCount ;
extern volatile unsigned char pb2DebounceCount ;
extern volatile unsigned char pb3DebounceCount ;
extern volatile unsigned char pb4DebounceCount ;

void pressbutton1(void);
void pressbutton2(void);
void pressbutton3(void);
void pressbutton4(void);

#endif	/* DEBOUNCE_H */

