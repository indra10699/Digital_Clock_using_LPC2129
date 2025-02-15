#include <LPC21xx.H>
#include "header.h"
void delay_ms (unsigned int ms)

{

	T0PR=15000;//1ms

	T0TC=T0PC=0x0;//init

	T0TCR=0x1;//start timer0

	while (T0TC<ms);

	T0TCR=0x0;//stop timer0	

}


