/**
 * @file Activity3.c
 * @author 259819-Preet Kamalanayan Pandit  (https://github.com/259819/LnT_embeddedC.git)
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include"../inc/Activity3.h"
#include"../inc/Activity4.h"

unsigned volatile int count;
int Activity3(int value)
{
count =0;
TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
TCCR0B|=(1<<CS01)|(1<<CS00);
DDRD|=(1<<PD6);

    if(value>=0 && value<=200)
    {
        count=52;
       
    }if(value>=210 && value<=500)
    {
        count=102;
        
    }if(value>=510 && value<=700)
    {
        count=180;
        
    }if(value>=710 && value<=1024)
    {
        count=244;
        
    }
    return count;
}