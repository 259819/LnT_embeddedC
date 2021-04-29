/**
 * @file port.c
 * @author Preet Kamalnayan Pandit (https://github.com/259819/LnT_embeddedC.git)
 * @brief  source file for port initialization
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include<avr/interrupt.h>
#include"../inc/Activity1.h"

/**
 * @brief initializing ports as input or output
 * 
 */
int Activity1()
{
    DDRD|=(1<<PD4);     //port B pin LED OUTPUT
    DDRD&=~(1<<PD0);    //CLEAR BIT
    DDRD&=~(1<<PD1);    //CLEAR BIT
    PORTD|=(1<<PD0);    //SET BIT -SWITCH-I INPUT
    PORTD|=(1<<PD1);    //SET BIT -SWITCH-II INPUT
    sei();
    if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1)))
        {
            PORTD|=(1<<PD4);    //led on     
            return 1;
        }else
        {
            PORTD&=~(1<<PD4);   //led off
            return 0;
        }
}