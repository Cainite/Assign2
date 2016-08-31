/*
 * File:   buttListener.c
 * Author: Kenny
 *
 * Created on 11 August 2016, 10:55 PM
 */


#include "interrupt.h"
#include <xc.h>
#include "Stepper.h"
#include "debounce.h"
#include "buttListener.h"

signed int stepPos=0;
int j=0;//check for odd or even, move cw when odd, move ccw when even


void buttListener(void){
       
    if(pb1Pressed){
        pb1Pressed = 0;// clear the pressed flag
        cwMovStepMotor (1); //move half step clockwise
    }
        
    if(pb2Pressed){
        pb2Pressed = 0; // clear the pressed flag
        ccwMovStepMotor (1);//move half step counter clockwise
    }
    if(pb3Pressed){
        pb3Pressed = 0;// clear the pressed flag
        j++; //increment j
        if(j% 2 == 0){ //if j is even
                ccwMovStepMotor(200); //move half step counter clockwise
       
        }
        if (j% 2 == 1) {
                cwMovStepMotor(200); //move half counter clockwise
        }
    }
        if(pb4Pressed){
        pb4Pressed = 0;// clear the pressed flag
        LED1 = !LED1;// And toggle the LED1
    }  
 
}
