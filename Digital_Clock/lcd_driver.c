#include <LPC21xx.H>
#include "header.h"
#define LCD 0x00FF0000 //P1.16 to P1.23
#define RS (1<<26)	   //P1.26
#define EN (1<<27)	   //P1.27


void lcd_cmd(unsigned char cmd)
 {
  IOCLR1=0xFF<<16;	
  IOSET1 = cmd << 16;
  IOCLR1 = RS;	
  IOSET1 = EN;
  delay_ms(2);
  IOCLR1 = EN; 	
 }	
 
void lcd_data(unsigned char data)
 {
  IOCLR1=0xFF<<16;		
  IOSET1 = data<<16;
  IOSET1 = RS;	
  IOSET1 = EN;
  delay_ms(2);	
  IOCLR1 = EN; 	
 }
 
void lcd_init()
{ 
 IODIR1 |= LCD | RS | EN;	 
 lcd_cmd(0x38);
 lcd_cmd(0x01);
 lcd_cmd(0x0C);
 lcd_cmd(0x80);
}	

void lcd_string(char *s)
{
	while(*s)
		{
			lcd_data(*s++);
			delay_ms(1);
		}	
}

void display_string_with_delay(char *s,int ms)
{
	while(*s)
	{
		lcd_data(*s++);
		delay_ms(ms);
	}	
}


