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

void idle(void) {
    lcdWrite4DigitBcd(getADC(),1);//write the ADCRAW left justified on the first row
    lcdSetCursor(10);//move cursor to position 10 for right justified
    lcdWrite4DigitBcd(getADCmm(),0);//write the ADC converted two spaces from the left edge
    lcd_WriteData('m');
    lcd_WriteData('m');//print the unit CM left justified
    lcdSetCursor(40);//reset the cursor to 2nd row left justified
    lcdWrite4DigitBcd(stepPos,1); //display current step, with sign(+ -)
    PORTC =0b00111001;//de energise steppermotor to prevent overheat
    __delay_ms(22);//delay readings to provide less flicker
         
}
