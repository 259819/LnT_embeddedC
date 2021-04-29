/**
 * @file Main.c
 * @author 259819-Preet Kamalnayan Pandit(https://github.com/259819/LnT_embeddedC.git)
 * @brief
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
#include<util/delay.h>
#include<string.h>

#include"./inc/Activity1.h"
#include"./inc/Activity2.h"
#include"./inc/Activity3.h"
#include"./inc/Activity4.h"

unsigned volatile int switch_status;
int main(void)
{  
    switch_status=0; 
     uint16_t temp=0;
    for(;;)
    {
        switch_status= Activity1();
        if(switch_status==1)
        {
             temp=Activity2();
             OCR0A= Activity3(temp);
            _delay_ms(200);

        }else
        {
            temp=0;
           // OCR0A=Activity3(temp);
        }
           if(OCR0A<=52)
           {
               Activity4("20 degree Celcius\n");
           }
           else if(OCR0A<=103)
           {
              Activity4("30 degree Celcius\n");
           }
            else if(OCR0A<=180)
           {
               Activity4("40 degree Celcius\n");
           }
           else if(OCR0A<=244)
           {
               Activity4("50 degree Celcius\n");
           }
        
    }
}