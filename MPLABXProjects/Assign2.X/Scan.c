/*
 * File:   Scan.c
 * Author: Kenny
 *
 * Created on 2 September 2016, 1:27 PM
 */


#include "Scan.h"

void singleScan(void){
    setupLCD();
    unsigned int closestStepPos = stepMm[0];
    unsigned int closestStepDisc = stepMm[1];
    
    closestStepPos = 0;
    closestStepDisc = 0
    i = 0;        
    
    while (i <= 400){
        spi_transfer(0b00001101);
        int adcVal = getADCmm();
        if (closestStepDisc == 0){//reset stepMapCm
        closestStepDisc = adcVal;//store adc value
    }else if(adcVal < closestStepDisc){
        closestStepDisc = adcVal; //store adc value
        closestStepPos = i; //store the position
    } 
    SM_STEP();
    __delay_ms(1);
        
    }
    ccwMovStepMotor(400 - closestStepPos);           // turn the stepper to the closest object
    spi_transfer(0b00001100);                        //de energise
    lcdSetCursor(0);
    lcd_WriteData('S');
    lcd_WriteData('T');
    lcd_WriteData('E');
    lcd_WriteData('P');
    lcd_WriteData(' ');
    lcdWrite4DigitBcd(closestStepPos,0);            //display the step at which the object is closest
    lcdSetCursor(40);
    lcdWrite4DigitBcd(closestStepDisc,0);           //display the distance at which the object is closest
    lcd_WriteData(' ');
    lcd_WriteData('M');
    lcd_WriteData('M');
    
    __delay_ms(5000);
}

