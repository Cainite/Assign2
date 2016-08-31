/* 
 * File:   config.h
 * Author: 12050302
 *
 * Created on 9 August 2016, 2:08 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <xc.h> // include processor files - each processor file is guarded.  
#pragma config BOREN = OFF, CPD = OFF, WRT = OFF, FOSC = HS, WDTE = OFF, CP = OFF, LVP = OFF, PWRTE = OFF 
#define _XTAL_FREQ 20000000 //Define Oscillator  freq  20Mhz
#define TMR0_VAL 100


#endif	/* CONFIG_H */

