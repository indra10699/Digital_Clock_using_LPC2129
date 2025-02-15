/*EEPROM I2C Code using on-chip I2C Controller*/

#include <LPC214X.H>

#include "header.h"


#define I2EN 6

#define STO 4

#define AA 2

#define STA 5

#define SI   3

/*I2C Byte Write*/

void i2c_byte_write(unsigned char sa,unsigned char wa,unsigned char data)

{

 	//i2c_start

	I2C0CONCLR   =   1 << STO;

	I2C0CONSET   =   1 << AA;

	I2C0CONSET   =   1 << STA;//i2c enters into master mode

	delay_ms(3);

	while(I2C0STAT != 0x08);//0x08 is start transmitted

	

	I2C0CONCLR   =   1 << STO;

	I2C0DAT      =   sa;//provice slave addr

	I2C0CONCLR   =   1 << SI;		

	delay_ms(3);

	while(I2C0STAT !=0x18);//SLAVE addr + ACK

	 

	I2C0DAT      = wa;//writing word address 

	I2C0CONCLR   =   1 << STO;

	I2C0CONCLR   =   1 << STA;

	I2C0CONCLR   =   1 << SI;		

	delay_ms(3);

	while(I2C0STAT != 0x28);

	I2C0DAT      = data;

	I2C0CONCLR   =   1 << STO;

	I2C0CONCLR   =   1 << STA;

	I2C0CONCLR   =   1 << SI;		

	delay_ms(3);

	I2C0CONCLR   =   1 << STA;

	I2C0CONSET   =   1 << STO;

	I2C0CONCLR   =   1 << SI;	

	delay_ms(10);

}	




/*I2C Byte read*/

unsigned char i2c_byte_read(unsigned char sa,unsigned char wa)

{

	unsigned char temp;

	I2C0CONCLR   =   1 << STO;//i2c start condition

	I2C0CONSET   =   1 << AA;

	I2C0CONSET   =   1 << STA;//i2c enters into master mode

	delay_ms(3);

	while(I2C0STAT != 0x08);//0x08 is start transmitted

	I2C0CONCLR=1<< STO;

	I2C0CONCLR=1<< STA;

	I2C0DAT = sa;

	I2C0CONCLR=1<< SI;		

	delay_ms(3);

	while(I2C0STAT !=0x18);//SLAVE addr + ACK

	IOSET0 = 1<<7;

	I2C0DAT= wa;//reading from wa addr 

	I2C0CONCLR =1<<STO;

	I2C0CONCLR =1<<STA;

	I2C0CONCLR =1<<SI;		

	delay_ms(3);

	while(I2C0STAT!= 0x28);

	I2C0CONSET   =1 << STA;

	I2C0CONCLR   =1<< STO;

	I2C0CONCLR   =1<< SI;		

	while(I2C0STAT!= 0x10);//repeated start condition has been transmitted

	I2C0DAT      = sa | 0x01;								I2C0CONCLR   =   1 << STO;

	I2C0CONCLR   =   1 << SI;

	while(I2C0STAT!= 0x40);//SLA+R has been transmitted; ACK has been  received

	I2C0CONCLR   =1 << STA;

	I2C0CONCLR   =1 << STO;

	I2C0CONCLR   =1 << SI;	

	I2C0CONCLR   =1 << AA;

	while(I2C0STAT != 0x58);//Data byte has been received; NOT ACK has been returned

	temp = I2C0DAT;

	I2C0CONCLR   = 1 << STA;

	I2C0CONSET   = 1 << STO;

	I2C0CONCLR   = 1 << SI;

	return temp; 

}




/*main()*/

/*main()

{

	unsigned int temp;

	lcd_init();

	IODIR0 |= 1<<7; 

	PINSEL0 = 0x00000055;//SCL = P0.2,SDA = P0.3

	//Setting i2c frequency (100KHz)

	I2C0SCLH =   75; //50%duty,I2CFreq100KHz,PCLK=60MHz

	I2C0SCLL =   75;

	I2C0CONSET =  1 << I2EN;   //Enable I2C 0

	i2c_device_write(0xA0,0x01,'V'); //witting to EEPROM

	

	temp = i2c_device_read(0xA0,0x01); //reading from EEPROM

	lcd_cmd(0xC0);

	lcd_data(temp);

	while(1);

}			 */


