/*
 * File:   SPI.c
 * Author: Kenny
 *
 * Created on 2 September 2016, 1:07 PM
 */


#include "SPI.h"

unsigned char spi_transfer(unsigned char data){
    unsigned char temp = 0;

    SSPIF = 0;
    SSPBUF = data;

    while (SSPIF == 0);
    temp = SSPBUF;
    SSPIF = 0;

    return temp;
}

