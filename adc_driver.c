#include <LPC21xx.H>
#include "header.h"
#define DONE 0x80000000

void init_adc()

{

 PINSEL0 |= 0x300;//P0.4 as a AD0.6

 

 /*ADC0 configuration*/

 ADCR   = 0x00200440;

}




unsigned int read_adc()

{

 unsigned int temp = 0;	

 ADCR|=(1<<24);//start ADC0	

 while((ADDR&DONE) == 0 );

 ADCR&= ~(1<<24);//stop ADC0	

 temp=(ADDR>>6) & 0x3FF;

 return temp; 

}

	


