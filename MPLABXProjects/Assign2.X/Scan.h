
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SCAN_H
#define	SCAN_H

#include "config.h"
#include "lcd.h"
#include "adc.h"
#include "SPI.h"

extern unsigned int stepMm[2];

void singleScan(void);

volatile int i;

#endif	/* SCAN_H */

