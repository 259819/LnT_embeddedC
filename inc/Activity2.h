/**
 * @file Activity2.h
 * @author 259819-Preet Kamalnayan Pandit(https://github.com/259819/LnT_embeddedC.git)
 * @brief header file for ADC conversion
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED

void InitADC();
int Activity2();
uint16_t ReadADC(uint8_t ch);

#endif // ACTIVITY2_H_INCLUDED
