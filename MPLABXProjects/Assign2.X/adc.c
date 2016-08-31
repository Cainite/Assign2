/*
 * File:   adc.c
 * Author: Kenny
 *hihi
 * Created on 12 August 2016, 9:37 AM
 */


#include "config.h"
#include <xc.h>
#include "adc.h"

void setupADC(void){
    PORTA = 0;              // Clear port register
    TRISA =  0b11111111;    //set all pins to input
    ADCON0 = 0b01000001;     //switch on ADC module; sets clock to 32TOSC; input at RA0; GO bit is low 
    ADCON1 = 0b00000010;	//left justified, PortE Digital, PortA Analogue
    __delay_us(50);         // Delay for ADC aquisition
}


unsigned int getADC(void){

    volatile unsigned int adcRAW; //declare adcRAW values
  
    ADRESH  = 0; 	 	// Reset the ADRES value register
    ADRESL  = 0;

    GO=1;                   //Starts ADC conversion 
    while (GO)           //wait for Go bit     
        continue;  //continue
    

    adcRAW= ADRESH;
    adcRAW=ADRESH<<2;  
    adcRAW = adcRAW | (ADRESL>>6);
    
    
    
    GO = 0;
   

    return (adcRAW);
}

unsigned int getADCmm(void){
     //convert adc raw to centimeters 
    volatile unsigned int adcReal; //declare adcReal values 
    volatile unsigned int adcRAWs=getADC(); //declare adcReal values 


    if(adcRAWs<=568&&adcRAWs>400){      //between 150 & 300 mm first tangent line on curve
        adcReal=((10*(adcRAWs-736))/-11.2);
    }    

    else if(adcRAWs<=400&&adcRAWs>227){ // between 300 & 500 mm second tangent line on curve
        adcReal=((10*(adcRAWs-659.5))/-8.65);
    }

    else if(adcRAWs<=227&&adcRAWs>187){  // between 500 & 700 mm third tangent line on curve{
        adcReal=((10*(adcRAWs-327))/-2.0);
    }

    else if(adcRAWs<=187&&adcRAWs>150){  // between 700 & 900 mm fourth tangent line on curve
        adcReal=((10*(adcRAWs-316.5))/-1.85);
    }  

    else if(adcRAWs<=150&&adcRAWs>124){  //between 900 & 1100 mm fifth tangent line on curve
        adcReal=((10*(adcRAWs-267))/-1.3);
    } 

    else if(adcRAWs<=124&&adcRAWs>110){  //between 1100 and 1300 mm sixth tangent line on curve
        adcReal=((10*(adcRAWs-201))/-0.7);
    }

    else if(adcRAWs<=110&&adcRAWs>90){  //between 1300 and 1500 mm seventh tangent line on curve
        adcReal=((10*(adcRAWs-227.0))/-0.9);
    } 
    else {
        adcReal = 1500;
    }
    return (adcReal);
}
