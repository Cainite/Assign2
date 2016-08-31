/* 
 * File:   Stepper.h
 * Author: 12050302
 *
 * Created on 9 August 2016, 2:06 PM
 */

#ifndef STEPPER_H
#define	STEPPER_H

//#include "config.h"


//Define stepper motor steps
#define STEP0 0b00111100 
#define STEP1 0b00101110 
#define STEP2 0b00101011 
#define STEP3 0b00100111 
#define STEP4 0b00110101 
#define STEP5 0b00010111 
#define STEP6 0b00011011 
#define STEP7 0b00011110

extern volatile int stepState ;  //stores current step

extern signed int stepPos;


void ccwMovStepMotor (int numberOfSteps);
void cwMovStepMotor (int numberOfSteps);
void initStepMotor (void);

#endif	/* STEPPER_H */

