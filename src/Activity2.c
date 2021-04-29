/**
 * @file Activity2.c
 * @author 259819-Preet Kamalnayan Pandit (https://github.com/259819/LnT_embeddedC.git)
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include"../inc/Activity2.h"


unsigned volatile int analog_value;
/**
 * @brief initializing ADC registers
 * 
 */
void InitADC()
{
    ADMUX=(1<<REFS0);                      //voltage reference=AVcc(+5V)
    ADCSRA=(1<<ADEN)|(7<<ADPS0);           //enable ADC, PRESCALAR= 128 (i.e., freq/128)

}
/**
 * @brief Reading the temperature value from the Selected ADC channel and returning its decimal analog reading.
 * 
 * @param ch 
 * @return uint16_t 
 */
uint16_t ReadADC(uint8_t ch)
{

analog_value=0;
ADMUX&=0xF8;
ch=ch&0b00000111;
ADMUX|=ch;                                 //selecting ADC channel

ADCSRA|=(1<<ADSC);                         //begin conversion

while(!(ADCSRA & (1<<ADIF)));              //waiting for the conversion 
ADCSRA|=(1<<ADIF);                         //conversion ends(interrupt bit=1) 

analog_value=(int)ADCL+((int)ADCH)*256;   //converting binary ADC reading into decimal value
return(analog_value);                     //returning the analog decimal value

}

int Activity2()
{
    int a=0;
    InitADC();
    a=ReadADC(0);
    return a;
}