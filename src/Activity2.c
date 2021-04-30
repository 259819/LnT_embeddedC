/**
 * @file Activity2.c
 * @author 259819-Preet Kamalnayan Pandit (preetkd2222@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include"../inc/Activity2.h"

#define ADC_MULTIPLEXER            ADMUX
#define PRESCALE_SETTING           ADCSRA
#define ADC_ENABLE                 ADEN
#define VOLTAGE_REFERENCE_AVcc     REFS0
#define PRESCALE_128               ADPS0
#define BEGIN_CONVERSION           ADSC
#define LOWER_ADC_REGISTER         ADCL
#define HIGHER_ADC_REGISTER        ADCH



/**
 * @brief initializing ADC registers
 * 
 */
void InitADC()
{
    ADC_MULTIPLEXER=(1<<VOLTAGE_REFERENCE_AVcc);        //voltage reference=AVcc(+5V)
    ADCSRA=(1<<ADC_ENABLE)|(7<<PRESCALE_128);           //enable ADC, PRESCALAR= 128 (i.e., freq/128)

}
/**
 * @brief Reading the temperature value from the Selected ADC channel and returning its decimal analog reading.
 * 
 * @param ch 
 * @return uint16_t 
 */

uint16_t ReadADC(uint8_t ch)
{
unsigned volatile int analog_value=0;
ADC_MULTIPLEXER&=0xF8;
ch=ch&0b00000111;
ADC_MULTIPLEXER|=ch;                                     //selecting ADC channel

ADCSRA|=(1<<BEGIN_CONVERSION);                           //begin conversion

while(!(ADCSRA & (1<<ADIF)));                            //waiting for the conversion 
ADCSRA|=(1<<ADIF);                                       //conversion ends(interrupt bit=1) 

analog_value=(int)LOWER_ADC_REGISTER+((int)HIGHER_ADC_REGISTER)*256; 
return(analog_value);                                   //converting binary ADC reading into decimal value 
                                                        //returning the analog decimal value

}

/**
 * @brief function returning the ADC reading to main application file
 * 
 * @return int 
 */
int Activity2()
{
   unsigned volatile int a=0;
    InitADC();
    a=ReadADC(0);
    return a;
}