/**
 * @file Main.c
 * @author 259819-Preet Kamalnayan Pandit
 * @brief 
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
    DDRB|=(1<<PB0);     //port B pin LED OUTPUT
    DDRD&=~(1<<PD0);    //CLEAR BIT
    DDRD&=~(1<<PD1);    //CLEAR BIT
    PORTD|=(1<<PD0);    //SET BIT -SWITCH-I INPUT
    PORTD|=(1<<PD1);    //SET BIT -SWITCH-II INPUT


    for(;;)
    {
        if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1)))
        {
            PORTB|=(1<<PB0);    //led on


        }else{
            PORTB&=~(1<<PB0);   //led off
        }
    }
}
