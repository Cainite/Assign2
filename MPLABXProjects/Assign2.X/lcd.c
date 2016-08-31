/*
 * File:   lcd.c
 * Author: Kenny
 *
 * Created on 12 August 2016, 9:17 AM
 */


#include "config.h"
#include "lcd.h"
#include "adc.h"

unsigned int onesDigi=0;
unsigned int tensDigi=0;
unsigned int hundredthDigi=0;
unsigned int thousandthDigi=0;

void lcdWriteControl(unsigned char databyte){
   LCD_E = 0;
    LCD_RW = 0;
    LCD_RS= 0;
    LCD_DATA=databyte;
    LCD_E = 1;
    LCD_E = 0;
    __delay_ms(2);  
}

//write data to LCD
void lcd_WriteData(unsigned char databyte){
    LCD_E = 0;
    LCD_RW = 0;
    LCD_RS= 1;
    LCD_DATA=databyte;
    LCD_E = 1;
    LCD_E = 0;
    __delay_ms(1);
}

void lcdSetCursor(unsigned char address){
    address |= 0x80;		//format address command using mask
    lcdWriteControl(address);	//write address command
}

void lcdWrite4DigitBcd(int decimal,char sign){
    if (decimal==0){
        onesDigi=0;
        tensDigi=0; 
        hundredthDigi=0;
        thousandthDigi=0;
    }
    //if input is between -10000 and -1000
    else if (decimal>-10000&& decimal<0){
        int newdecimal=decimal*-1;
        onesDigi=newdecimal;
        tensDigi=0; 
        hundredthDigi=0;
        thousandthDigi=0;
        while (onesDigi >= 10){
            onesDigi = onesDigi - 10;
            tensDigi++;
        }
       
        while (tensDigi >= 10){
            tensDigi = tensDigi - 10;
            hundredthDigi++;
        }
    
        while (hundredthDigi >= 10){
            hundredthDigi = hundredthDigi - 10;
            thousandthDigi++;
        }
    } 
    
    else if (decimal>0 && decimal<10000){
        onesDigi=decimal;
        tensDigi=0; 
        hundredthDigi=0;
        thousandthDigi=0;
        while (onesDigi >= 10){
            onesDigi = onesDigi - 10;
            tensDigi++;
        }
    
        while (tensDigi >= 10){
            tensDigi = tensDigi - 10;
            hundredthDigi++;
        }   
        while (hundredthDigi >= 10){
            hundredthDigi = hundredthDigi - 10;
            thousandthDigi++;
        }      
    }
    if(sign==1){//if a sign is wanted before the value 
        if(decimal>0){ //if decimal value is positive
            lcd_WriteData(0x2b); // display a positive sign 
            lcd_WriteData(thousandthDigi+48); 
            lcd_WriteData(hundredthDigi+48);
            lcd_WriteData(tensDigi+48);
            lcd_WriteData(onesDigi+48);
        }
        else if(decimal<0){ // if the decimal value is negative
            lcd_WriteData(0x2d);// displays a negative sign 
            lcd_WriteData(thousandthDigi+48); 
            lcd_WriteData(hundredthDigi+48);
            lcd_WriteData(tensDigi+48);
            lcd_WriteData(onesDigi+48);
        }
    
        else if(decimal==0){// if the decimal value equals 0  //no plus/minus sign                            
            lcd_WriteData(thousandthDigi+48);
            lcd_WriteData(hundredthDigi+48);
            lcd_WriteData(tensDigi+48);
            lcd_WriteData(onesDigi+48);
        }
    }
    
    else if(sign==0){//if no sign wanted before value eg adc value 
        lcd_WriteData(thousandthDigi+48);
        lcd_WriteData(hundredthDigi+48);
        lcd_WriteData(tensDigi+48);
        lcd_WriteData(onesDigi+48);
    }  
}

void setupLCD(void){
    ADCON1 = 0b00000010;	//left justified, PortE Digital, PortA Analogue

    TRISD = 0x00;		//set all pins to output
    TRISE = 0x00;		//set all pins to output
    PORTD = 0x00;				//set all pins on portd low
    PORTE = 0x00;				//set all pins on porte low

    //LCD Initialisation
    
    lcdWriteControl(0x01); //clear display
    lcdWriteControl(0x38); //set up display
    lcdWriteControl(0x0C); //turn display on
    lcdWriteControl(0x06); //move to first digit
    lcdWriteControl(0x02); //entry mode setup
    

}
