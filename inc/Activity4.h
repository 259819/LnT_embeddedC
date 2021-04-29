/**
 * @file Activity4.h
 * @author 259819-Preet Kamalanayan Pandit (https://github.com/259819/LnT_embeddedC.git)
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
void USART_init();
char USART_read();
void USART_write(char data);
void write_string(char *string);
void Activity4(char *data);