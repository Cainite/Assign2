 
#ifndef LCD_H
#define	LCD_H

#include "config.h" 

//Define LCD 
#define	LCD_RS RE0	//;Define the pin for the LCD RS register select hardwired
#define	LCD_RW RE1	//;Define the pin for the LCD R/W read/write hardwired
#define	LCD_E  RE2	//Define the pin for the LCD E enable hardwire

#define	LCD_DATA	PORTD     //Define the pins for LCD Data Lines

extern unsigned int onesDigi;//declare fourth digit
extern unsigned int tensDigi;//declare third digit
extern unsigned int hundredthDigi;//declare second digit
extern unsigned int thousandthDigi;//declare first digit

void lcdWriteControl(unsigned char databyte);//write controls to LCD


void lcd_WriteData(unsigned char databyte);//write data to LCD


void lcdSetCursor(unsigned char address);//move the LCD cursor to a location


void lcdWrite4DigitBcd(int decimal,char sign);//function accepts char between 0 and 9999 and writes it to lcd display in 4 digits


void setupLCD(void);//function initalises the LCD module - check that ADCON1 setting doesn't conflict

#endif	/* LCD_H */

