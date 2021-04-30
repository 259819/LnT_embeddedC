/**
 * @file Activity3.c
 * @author 259819-Preet Kamalanayan Pandit  (preetkd2222@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include"../inc/Activity3.h"
#include"../inc/Activity4.h"

#define  PWM_OUTPUT_PIN          PD6
#define  DATA_DIRECTION_REG_D    DDRD

/**
 * @brief function for calculating  the PWM duty cycle 
 * 
 * @param value 
 * @return int 
 */

int Activity3(int value)
{

unsigned volatile int count=0;

TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);  //setting non-inverting, fast PWM mode 

TCCR0B|=(1<<CS01)|(1<<CS00);                //setting  a prescaler of 128

DATA_DIRECTION_REG_D|=(1<<PWM_OUTPUT_PIN);                              

    if(value>=0 && value<=200)
    {
        count=52;

    }if(value>=210 && value<=500)
    {
         count=102;
                                            //count is the value to be stored in OCR register
    }if(value>=510 && value<=700)
    {
         count=180;

    }if(value>=710 && value<=1024)
    {
        count=244;
    }
    return count;
}