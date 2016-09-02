/*
 * File:   idle.c
 * Author: Kenny
 *
 * Created on 12 August 2016, 9:56 AM
 */


#include "config.h"
#include <xc.h>
#include "lcd.h"
#include "Stepper.h"
#include "adc.h"
#include "SPI.h"

void idle(void) {
    lcdSetCursor(40);//move cursor to position 10 for right justified
    lcdWrite4DigitBcd(getADCmm(),0);//write the ADC converted two spaces from the left edge
    lcd_WriteData('m');
    lcd_WriteData('m');//print the unit CM left justified
    spi_transfer(0b00001100); //de energise steppermotor to prevent overheat
    __delay_ms(22);//delay readings to provide less flicker
         
}
