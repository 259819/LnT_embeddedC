/**
 * @file Activity4.c
 * @author 259819-Preet Kamalnayan Pandit (preetkd2222@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include<string.h>


#define BAUD 9600
#define F_CPU 16000000
#define BAUDRATE ((16000000)/(BAUD*16UL)-1)
#define USART_DATA_REGISTER UDR0


void USART_init(void)
{
    /*PD0 RXD PD1 TXD*/
    
    /*sET BAUD RATE TO REGISTER*/
    UBRR0H = (BAUDRATE>>8);
    UBRR0L = BAUDRATE;
    
    /*SETTING SYNCHRONOUS COMMUNICATION OF 8 BIT TRANSCIEVER*/
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    /*ENABLE THE RECIEVER AND TRANSIMTTER*/
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}

/**
 * @brief Program to write to other peripheral using UART
 * 
 * @param data 
 */
void USART_write(char data)
{
    while( !(UCSR0A & (1<<UDRE0)) );
    USART_DATA_REGISTER = data;
}

/**
 * @brief To write a string data using a loop
 * 
 * @param data 
 */
void write_string( char *string)
{
  
    int count;
    int len_string = strlen(string);
    for(count = 0 ; count < len_string; count++)
    {
        USART_write(*(string+count));
    }  
}

/**
 * @brief Program for displaying the temperature using UART
 * 
 * @param data
 */
void Activity4(char *data)
{
    USART_init();
    write_string(data);    
}