/*
 */

#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
    DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0); //CLEAR BIT
    DDRC&=~(1<<PC0);
    PORTD|=(1<<PD0);//SET BIT
    PORTC|=(1<<PC0);


    for(;;)
    {
        if(!(PIND&(1<<PD0)) && !(PINC&(1<<PC0)))
        {
            PORTB|=(1<<PB0);


        }else{
            PORTB&=~(1<<PB0);
        }
    }
}
