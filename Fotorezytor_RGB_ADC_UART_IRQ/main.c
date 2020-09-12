/*
 * Fotorezytor_RGB_ADC_UART_IRQ.c
 *
 * Created: 08.09.2020 11:33:15
 * Author : PRZEMPM
 */ 

#include <avr/io.h>
#include "usart.h"
#include <avr/interrupt.h>
#include <util/delay.h>

void ADCInit()
{
	ADMUX=_BV(REFS0) | _BV(MUX0);   //Nap. referencyjne równe Vcc, wejœcie pierwsze multipleksera
	DIDR0=_BV(ADC1D);               //Wy³¹cz funkcjê cyfrow¹ pinu nr 1
	ADCSRB=_BV(ADTS2) | _BV(ADTS0);	//Ustaw wyzwalanie zdarzeniem timer1 compare match B
	ADCSRA=_BV(ADEN) | _BV(ADATE) | _BV(ADPS2)| _BV(ADPS1)| _BV(ADPS0)|_BV(ADIE); //Preskaler ADC - 128, w³¹cz ADC, wyzwalanie, przerwanie
}

void TMER_init()
{
	TCCR1B=_BV(CS12) | _BV(CS10) | _BV(WGM12);		// Preskaler 1024, tryb CTC
	OCR1A=7812;										// Top zliczania w trybie CTC
	OCR1B=7812;
}

volatile uint16_t ADCVal;

ISR(ADC_vect)
{
	TIFR1|=_BV(OCF1B);								//Zeruj flage przerwania timer1 compare match B
	USART_sendchar(ADCH);
	USART_sendchar(ADCL);
	ADCVal = ADC;
}

int main(void)
{
	ADCInit();								//Inicjalizacja ADC
	USART_init();							//Inicjalizacja USART
	TMER_init();							//Inicjalizacja Timera
	
	DDRD = _BV(PD2)|_BV(PD3)|_BV(PD4);		// Ustaw wyjscie DIODY RGB
	PORTD = _BV(PD2)|_BV(PD3)|_BV(PD4);		// Ustaw piny na HIGH dla RGB
	DDRD |= _BV(PD5);						// Ustaw wyjscie do anody DIODY
	PORTD |= _BV(PD5);						// Ustaw pin na HIGH dla anody DIODY
	sei();									// Odblokuj przerwania

	
    while (1) 
    {
		if (ADCVal <= 200){
			PORTD &= ~_BV(PD4);
			PORTD |= _BV(PD2) | _BV(PD3)| _BV(PD5);
		}
		else if (ADCVal <= 300){
			PORTD &= ~_BV(PD3);
			PORTD |= _BV(PD2) | _BV(PD4)| _BV(PD5);
		}
		else if (ADCVal <= 400){
			PORTD &= ~_BV(PD2);
			PORTD |= _BV(PD4) | _BV(PD3)| _BV(PD5);
		}
		else 
			PORTD |= (_BV(PD2) | _BV(PD3) | _BV(PD4));
	}
}

