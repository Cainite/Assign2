
#include "config.h"
#include "init.h"
#include "buttListener.h"
#include "lcd.h"
#include "idle.h"
#include "interrupt.h"




void main(void){
    init ();//intialise port
    while(1){
        setupLCD();
        idle();//idling process
        buttListener();//activate Button Listeners
        
    }
}