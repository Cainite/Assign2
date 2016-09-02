
#include "config.h"
#include "Stepper.h"
#include "lcd.h"
#include "SPI.h"

signed int stepPos=0;

void ccwMovStepMotor(int numberOfSteps) {
    volatile int i = 0;                                                     //i is incremented with each step. When i = numberOfSteps, the function will stop 
    while (i <= numberOfSteps) {                                            //This will loop for 'numberOfSteps' -> see the main function for more info
        spi_transfer(0b00001111);                                           //enable counterclockwise
        SM_STEP();                                                          //toggle stepper 1 half step
        __delay_ms(1);                                                      //After each step, delay for 1ms. 
        i++;                                                                //Increment the counter
        }
    stepPos = stepPos+1; // add by 1 from the stepPos total
}


void cwMovStepMotor(int numberOfSteps) {
    volatile int i = 0;                                                     //i is incremented with each step. When i = numberOfSteps, the function will stop   
    while (i <= numberOfSteps) {                                            //This will loop for 'numberOfSteps' -> see the main function for more info
        spi_transfer(0b00001101);                                           //enable clockwise
        SM_STEP();                                                          //toggle stepper 1 half step
        __delay_ms(1);                                                      //After each step, delay for 1ms. 
        i++;                                                                //Increment the counter
    }
    stepPos = stepPos-1; // add by 1 from the stepPos total
}


