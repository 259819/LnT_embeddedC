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
#include"./inc/port.h"

void port();
int main(void)
{
    port();
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
