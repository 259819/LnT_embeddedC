/**
 * @file port.c
 * @author Preet Kamalnayan Pandit (https://github.com/259819/LnT_embeddedC.git)
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void port()
{
    DDRB|=(1<<PB0);     //port B pin LED OUTPUT
    DDRD&=~(1<<PD0);    //CLEAR BIT
    DDRD&=~(1<<PD1);    //CLEAR BIT
    PORTD|=(1<<PD0);    //SET BIT -SWITCH-I INPUT
    PORTD|=(1<<PD1);    //SET BIT -SWITCH-II INPUT
    sei();
}
