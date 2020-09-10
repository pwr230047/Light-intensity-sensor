/*
 * usart.c
 *
 * Created: 08.09.2020 11:33:15
 * Author : PRZEMPM
 */ 

#include "usart.h"
#include <avr/pgmspace.h>

static void uart_9600()
{
	#define BAUD 9600
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	#if USE_2X
	UCSR0A |= (1 << U2X0);
	#else
	UCSR0A &= ~(1 << U2X0);
	#endif
}

void USART_init()
{
	uart_9600();						//Ustal szybkoœæ transferu na 9600 bps
	UCSR0B=_BV(TXEN0);					//Odblokuj nadajnik
	UCSR0C=_BV(UCSZ00) | _BV(UCSZ01);	//8 bitów danych + 1 bit stopu
}

void USART_sendchar(uint8_t c)
{
	while(!(UCSR0A & (1<<UDRE0)));	//Zaczekaj na miejsce w buforze nadawczym
	UDR0=c;
}

void USART_sendstring(const char *txt)
{
	while(*txt)
	{
		USART_sendchar(*txt);
		++txt;
	}
}

void USART_send_block(const uint8_t __memx *block, uint8_t size)
{
	while(size--)
	{
		USART_sendchar(*block);
		++block;
	}
}
