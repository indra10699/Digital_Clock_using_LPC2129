#include <LPC21xx.H>
#include "header.h"
#define sw1 (1<<14) 
#define sw2 (1<<15)
#define sw3 (1<<16)

main()
{
unsigned char h,m,s,ampm=0,dd,mm,yy;
while(1)
{
s=i2c_byte_read(0x0D,0x0);
m=i2c_byte_read(0x0D,0x1);
h=i2c_byte_read(0x0D,0x2);

lcd_cmd(0x080);
lcd_data((h/0x10)+48);
lcd_data((h%10)+48);
lcd_data(':');

lcd_data((m/0x10)+48);
lcd_data((m%10)+48);
lcd_data(':');

lcd_data((s/0x10)+48);
lcd_data((s%10)+48);
if(sw3==0)
{ 
	h=0;
	lcd_cmd(0x1);
	lcd_cmd(0x80);
	lcd_string("Enter Hours");
	lcd_cmd(0xc0);
	lcd_data((h/0x10)+48);
	lcd_data((h%10)+48);
	do
	{
	if(sw1==0)
	{
	while(sw1==0);
	h++;
	if(h==13)
	h=0;
	lcd_cmd(0x1);
	lcd_cmd(0x80);
	lcd_string("Enter Hours:");
	lcd_cmd(0xc0);
	lcd_data((h/0x10)+48);
	lcd_data((h%10)+48);
	
	}
	}while(sw2==1);
	while(sw2==0);
	m=0;
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Enter Minutes:");
	lcd_cmd(0xc0);
	lcd_data((m/0x10)+48);
	lcd_data((m%10)+48);
	 
	 while(sw1==1);
		do
		{
		if(sw1==0)
		{
		while(sw1==0);
		m++;
		if(m==60)
		m=0;
		lcd_cmd(0x1);
		lcd_cmd(0x80);
		lcd_string("Enter Minutes:");
		lcd_cmd(0xc0);
		lcd_data((m/0x10)+48);
		lcd_data((m%10)+48);
		
		}
		}while(sw2==1);
	while(sw2==0);
	s=0;
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Enter Seconds:");
	lcd_cmd(0xc0);
	lcd_data((m/0x10)+48);
	lcd_data((m%10)+48);
	 
	 while(sw1==1);
		do
		{
		if(sw1==0)
		{
		while(sw1==0);
		s++;
		if(s==60)
		s=0;
		lcd_cmd(0x1);
		lcd_cmd(0x80);
		lcd_string("Enter Seconds:");
		lcd_cmd(0xc0);
		lcd_data((s/0x10)+48);
		lcd_data((s%10)+48);
		
		}		 
		}while(sw2==1);
	while(sw2==0);
	dd=1;
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Enter Date:");
	lcd_cmd(0xc0);
	lcd_data((m/0x10)+48);
	lcd_data((m%10)+48);
	 
	 while(sw1==1);
		do
		{
		if(sw1==0)
		{
		while(sw1==0);
		dd++;
		if(dd==32)
		dd=1;
		lcd_cmd(0x1);
		lcd_cmd(0x80);
		lcd_string("Enter Date:");
		lcd_cmd(0xc0);
		lcd_data((dd/0x10)+48);
		lcd_data((dd%10)+48);
		
		}		 
		}while(sw2==1);
	while(sw2==0);
	mm=0;
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Enter Month:");
	lcd_cmd(0xc0);
	lcd_data((m/0x10)+48);
	lcd_data((m%10)+48);
	 
	 while(sw1==1);
		do
		{
		if(sw1==0)
		{
		while(sw1==0);
		h++;
		if(mm==13)
		mm=1;
		lcd_cmd(0x1);
		lcd_cmd(0x80);
		lcd_string("Enter Month:");
		lcd_cmd(0xc0);
		lcd_data((s/0x10)+48);
		lcd_data((s%10)+48);
		
		}		 
		}while(sw2==1);
	while(sw2==0);
	yy=2020;
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Enter year:");
	lcd_cmd(0xc0);
	lcd_data((yy/0x10)+48);
	lcd_data((yy%10)+48);
	 
	 while(sw1==1);
		do
		{
		if(sw1==0)
		{
		while(sw1==0);
		yy++;
		if(yy==2024)
		yy=2023;
		lcd_cmd(0x1);
		lcd_cmd(0x80);
		lcd_string("Enter Year:");
		lcd_cmd(0xc0);
		lcd_data((yy/0x10)+48);
		lcd_data((yy%10)+48);
		
		}		 
	  	}while(sw2==1);
				while(sw2==0);  




}
}
}


