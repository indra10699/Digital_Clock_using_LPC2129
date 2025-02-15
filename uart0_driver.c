#include <LPC21xx.H>  
#include "header.h"
#define THRE (U0LSR&(1<<5))	
#define RDR  (U0LSR&0x1)

void uart0_init(int baud)
{
int a[]={15,60,30,0,15};
int pclk=a[VPBDIV]*1000000,result;
result=pclk/(16*baud);
	PINSEL0|=0x5;
	U0LCR=0x83;
	U0DLL=result&0x0ff;
	U0DLM=(result>>8)&0xff;
	U0LCR=0x3;
}


void uart0_tx(unsigned char data)
{
	U0THR=data;
	while (THRE == 0);
}


unsigned char uart0_rx()
{
	while (RDR == 0);
	return U0RBR;	
} 

void uart0_tx_string(char *s)
{
	while(*s)
	uart0_tx(*s++);
}

