/*
 * usart.h
 *
 * Created: 08.09.2020 11:33:15
 * Author : PRZEMPM
 */ 

#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <stdbool.h>

void USART_init();
void USART_sendchar(uint8_t c);                                        //Wyœlij znak
void USART_sendstring(const char *txt);                                //Wyœlij ³añcuch
void USART_send_block(const uint8_t __memx *block, uint8_t size);      //Wyœlij blok o d³ugoœci size z pamiêci SRAM

static inline void waitforTx()            //Zaczekaj na koniec nadawania znaku
{
	while(!(UCSR0A & _BV(UDRE0)));
}

#endif /* USART_H_ */