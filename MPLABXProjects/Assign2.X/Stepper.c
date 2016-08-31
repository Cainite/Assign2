
#include "config.h"
#include <xc.h>
#include "Stepper.h"
#include "lcd.h"
#include "buttListener.h"

signed int stepPos=0;

volatile int stepState;


void ccwMovStepMotor(int numberOfSteps) {

    volatile int i = 0;                                                         //i is incremented with each step. When i = numberOfSteps, the function will stop 
    //volatile int stepState = 0;                                                 //We have 8 step states (we are using half steps), this variable will count through the states and reset after each state has been used 
    
    while (i < numberOfSteps) {                                                 //This will loop for 'numberOfSteps' -> see the main function for more info
     
        if (stepState == 0) {                                                    //If this is the first step, 
            PORTC = STEP0;                                                      //Write STEP0 to PORTC -> STEP0, STEP1, STEP2 etc. are defined up top ^^^ 
        }
        else if (stepState == 1) {                                               //Same as above, but a different state
            PORTC = STEP1;
        }
        else if (stepState == 2) {                                               //etc. etc. etc. 
            PORTC = STEP2; 
        }
        else if (stepState == 3) {
            PORTC = STEP3;
        }
        else if (stepState == 4) {
            PORTC = STEP4;
        }
        else if (stepState == 5) {
            PORTC = STEP5;
        }
        else if (stepState == 6) {
            PORTC = STEP6;
        }
        else if (stepState == 7) {
            PORTC = STEP7;
        }
        __delay_ms(2);                                                         //After each step, delay for 10ms. 
        
        i++;                                                                    //Increment the counter
        stepState++;                                                            //Increment the stepState
        if (stepState > 7) {                                                    //If we've reached 8, i.e. we've cycled through all the step states
            stepState = 0;                                                      //Reset the counter
        }
        stepPos = stepPos+1; // add by 1 from the stepPos total
                lcdSetCursor(40);//configure to print on second line left justified
                lcdWrite4DigitBcd(stepPos,1); //print current stepper position live with no sign
    }
}

void cwMovStepMotor(int numberOfSteps) {

    volatile int i = 0;                                                         //i is incremented with each step. When i = numberOfSteps, the function will stop 
    //volatile int stepState = 7;                                                 //We have 8 step states (we are using half steps), this variable will count through the states and reset after each state has been used 
    
    while (i < numberOfSteps) {                                                 //This will loop for 'numberOfSteps' -> see the main function for more info
     
        if (stepState == 0) {                                                    //If this is the first step, 
            PORTC = STEP0;                                                      //Write STEP0 to PORTC -> STEP0, STEP1, STEP2 etc. are defined up top ^^^ 
        }
        else if (stepState == 1) {                                               //Same as above, but a different state
            PORTC = STEP1;
        }
        else if (stepState == 2) {                                               //etc. etc. etc. 
            PORTC = STEP2; 
        }
        else if (stepState == 3) {
            PORTC = STEP3;
        }
        else if (stepState == 4) {
            PORTC = STEP4;
        }
        else if (stepState == 5) {
            PORTC = STEP5;
        }
        else if (stepState == 6) {
            PORTC = STEP6;
        }
        else if (stepState == 7) {
            PORTC = STEP7;
        }
        __delay_ms(2);                                                         //After each step, delay for 10ms. 
        
        i++;                                                                    //Increment the counter
        --stepState;                                                            //Increment the stepState
        if (stepState < 0 ) {                                                    //If we've reached 8, i.e. we've cycled through all the step states
            stepState = 7;                                                      //Reset the counter
        }
        stepPos = stepPos-1; // add by 1 from the stepPos total
        lcdSetCursor(40);//configure to print on second line
        lcdWrite4DigitBcd(stepPos,1);//print current stepper position live with no sign
    }
}



void initStepMotor (void){
    TRISC = 0x00;// make ports C for stepper motor 
    stepState = 0;
    ccwMovStepMotor (1);//
    cwMovStepMotor (1);
}