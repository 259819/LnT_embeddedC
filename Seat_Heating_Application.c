/**
 * @file Seat_Heating_Application.c
 * @author 259819-Preet Kamalnayan Pandit(preetkd2222@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
#include<string.h>



#include"./inc/Activity1.h"
#include"./inc/Activity2.h"
#include"./inc/Activity3.h"
#include"./inc/Activity4.h"

#define OUTPUT_COMPARE_REGISTER  OCR0A


/**
 * @brief PROGRAM for complete Seat Heating Application
 * 
 * @return int 
 */
int main(void)
{  
    unsigned volatile int switch_status=0;
                                                                 //variable to check if both switches are ON or OFF
    uint16_t temp=0;                                           //variable to store the ADC readings
    while(1)
    {
        switch_status= Activity1();
        if(switch_status==1)                                    //if both switches are on, then only ADC will work
        {                                     
             temp=Activity2();                   
             OUTPUT_COMPARE_REGISTER=Activity3(temp);           //PWM pulses will be generated only if adc is working else the pulses will be of default duty cycle
                                                                //passing the ADC reading for the display of temperature using UART 
        }else
        {
            OUTPUT_COMPARE_REGISTER=0x00;
        }
        if(OUTPUT_COMPARE_REGISTER>=0 && OUTPUT_COMPARE_REGISTER<=52)
        {
               Activity4("20 degree Celcius\n");
        }
        else if(OUTPUT_COMPARE_REGISTER>52 && OUTPUT_COMPARE_REGISTER<=103)
        {
              Activity4("25 degree Celcius\n");                 //passing the temperature for displaying using UART
        }
        else if(OUTPUT_COMPARE_REGISTER>103 && OUTPUT_COMPARE_REGISTER<=180)
        {
               Activity4("29 degree Celcius\n");
        }
        else if(OUTPUT_COMPARE_REGISTER>180 && OUTPUT_COMPARE_REGISTER<=244)
        {
               Activity4("33 degree Celcius\n");
        }
 
    }
}