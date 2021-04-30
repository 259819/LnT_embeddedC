/**
 * @file Activity1.c
 * @author 259819-Preet Kamalnayan Pandit (preetkd2222@gmail.com)
 * @brief  source file for port initialization
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include"../inc/Activity1.h"

#define LED_OUTPUT_PIN PD4
#define LED_ON         PORTD|=(1<<PD4); 
#define LED_OFF        PORTD&=~(1<<PD4);   
#define SWITCH1_INPUT  PD0
#define SWITCH2_INPUT  PD1
/**
 * @brief initializing ports as input or output
 * 
 */
int Activity1()
{
    DDRD|=(1<<LED_OUTPUT_PIN);    
    DDRD&=~(1<<SWITCH1_INPUT);    //CLEAR BIT
    DDRD&=~(1<<SWITCH2_INPUT);    //CLEAR BIT
    PORTD|=(1<<SWITCH1_INPUT);    //SET BIT 
    PORTD|=(1<<SWITCH2_INPUT);    //SET BIT 
   // sei();
    if(!(PIND&(1<<SWITCH1_INPUT)) && !(PIND&(1<<SWITCH2_INPUT)))
        {
            LED_ON;        
            return 1;
        }else
        {
           LED_OFF;  
            return 0;
        }
}