/* 
 * File:   Interrupt.h
 * Author: 12050302
 *
 * Created on 9 August 2016, 3:29 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include "debounce.h"
#include "config.h"


#define LED1 RB1
#define LED0 RB0


extern volatile bit rtcFlag500MS;

extern volatile unsigned int rtcCounter ;//Counter to count how many times we've been interrupted

void interrupt isr(void);

#endif	/* INTERRUPT_H */

