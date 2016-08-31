/*
 * File:   init.c
 * Author: Kenny
 *
 * Created on 11 August 2016, 10:31 PM
 */

#include "config.h"
#include "init.h"
#include "Stepper.h"
#include "adc.h"

void init(void){
    RB0 = 0; //configure PORTB
    TRISB = 0b11111100;//setup port B inputs and outputs for push buttons and LEDS
    OPTION_REG = 0B00000100;        
    TMR0 = TMR0_VAL;
    TMR0IE = 1;
    ei();
    //interrupt isr();
    initStepMotor ();
    setupADC();
} 

