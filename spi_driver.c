/*LPC2148 SPI Working Code. 
 MCP3204 (12bits ADC) working code.
 Using Inbuilt SPI0 Peripheral. 
Polling mechanism is used.*/

#include<lpc214x.h>	
#include <stdio.h>	  
#include "header.h"	  					  
/*SPI0 Connections*/  
#define SCK0 (1<<8) //P0.4
#define MISO (1<<10) //P0.5
#define MOSI (1<<12) //P0.6
#define SS (1<<7)  //P0.7


unsigned int dummy;
void spi_init(void)
{
 /*
	PINSEL0 |=SCK0|MISO|MOSI;
	Selecting alternative pin functionality
	P0.4=SCK0
	P0.5=MISO0
	P0.6=MOSI0
	P0.7=SSLE0
*/	
   PINSEL0 |=SCK0|MISO|MOSI;
   IODIR0=SS;//SS pin is OUTPUT pin
   IOSET0=SS;//Disable MCP3204 Chip

 /*
		S0SPCCR=150;
		***Setting SPI communication Speed***
	    SPI0_SPEED	=PCLK/S0SPCCR
					=15MHz/150
					=100000bps
					=100Kbps
	 */
	S0SPCCR=150;//Spi speed is 100Kbps
	
	/*
	S0SPCR=0x0020;
	Bit2=BitEnable=0(The SPI controller sends and receives 8 bits 
					of data per transfer)
	Bit3=CPHA=0
	Bit4=CPOL=0 (SPI Mode0 is selected)
	Bit5=MSTR=1 (The SPI operates in Master mode)				
	Bit6=LSBF=0 (SPI data is transferred MSB (bit 7) first)		
	Bit7=SPIE=0 (SPI interrupts are inhibited/disabled)

	Bits 11:8 (Dont Care if Bit2 is 0)s

	*/
S0SPCR=0x0020;
}

void spi_write(unsigned char config)
{
	S0SPDR=config;
	while(!(S0SPSR&0X80));//waiting for SPI data transfer is complete
	dummy = S0SPDR;
}

unsigned short int spi_read(unsigned char config)
{
	S0SPDR=config;
	while(!(S0SPSR&0X80));//waiting for SPI data transfer is complete
	return S0SPDR;
}

/*int main()

{

	unsigned int p,q,result;

	spi_init();

	uart0_init(9600);

	 

   while(1)

   {

		IOCLR0=SS;//enable chip

		spi_write(0x70);//writing for adc configuration

		p=spi_read(0x0);//reading B11 to B4 bits from adc MCP3204

		q=spi_read(0x0);//reading B3 to B0 bits from adc MCP3204

		IOSET0=SS;//disable chip

		result=0;

		q &=0x0F;//Masking don't care bits

		result=p<<4|q;//generating 12bits result  

		uart0_string("ADC VAL: "); 

		uart0_integer(result);//displaying result on Serial Terminal

		uart0_string("\r\n");//new line on serial terminal	 

		tdelay_ms(100);

   }

} */


