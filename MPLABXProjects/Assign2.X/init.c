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
#include "SPI.h"

void init(void){
    RB0 = 0; //configure PORTB
    TRISB = 0b00000000;//setup port B inputs and outputs for push buttons and LEDS
    
    SSPSTAT = 0b01000000;
    SSPCON = 0b00100000;
    
    TRISC = 0b11010000; // setup ports C for stepper motor 
    PORTC = 0b00000011;
    
    PEIE = 1;						//enable peripheral interrupt
    GIE = 1;
    
    OPTION_REG = 0B00000100;        
    TMR0 = TMR0_VAL;
    TMR0IE = 1;
    ei();
    
    unsigned char controlByte = 0b00001101;
    spi_transfer(controlByte);
    
    ser_init();
    setupADC();
} 

