/* 
 * File:   Stepper.h
 * Author: 12050302
 *
 * Created on 9 August 2016, 2:06 PM
 */

#ifndef STEPPER_H
#define	STEPPER_H


//Define stepper motor steps

extern signed int stepPos;


void ccwMovStepMotor (unsigned int numberOfSteps);
void cwMovStepMotor (unsigned int numberOfSteps);

#endif	/* STEPPER_H */

