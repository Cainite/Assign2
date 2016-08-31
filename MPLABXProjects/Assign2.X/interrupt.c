#include "interrupt.h"
#include "debounce.h"


volatile bit rtcFlag500MS = 0;

volatile unsigned int rtcCounter = 0;//Counter to count how many times we've been interrupted

void interrupt isr(void){
    //Timer 0
    if(TMR0IF){//if timer0 overflow occured
        TMR0IF = 0; //clear flag
        TMR0 = TMR0_VAL; //reset the timer0 start count 

        rtcCounter++; // Increment counter 
        
        if(rtcCounter % 500 == 0){
            rtcCounter = 0;    //reset RTC Counter
            rtcFlag500MS = 1;
            RB0 =!RB0; //Toggle led 
        }
        pressbutton1();//check if button 1 is pressed
        pressbutton2();//check if button 2 is pressed
        pressbutton3();//check if button 3 is pressed
        pressbutton4();//check if button 4 is pressed
    }
}