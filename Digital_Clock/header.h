
extern void delay_ms (unsigned int ms);

extern void uart0_init(int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *s);

extern void lcd_cmd(unsigned char cmd);
extern void lcd_data(unsigned char data);
extern void lcd_init(void);
extern void lcd_string(char *s);
extern void display_string_with_delay(char *s,int ms);

extern void spi_init(void);
extern void spi_write(unsigned char config);
extern unsigned short int spi_read(unsigned char config);

extern void init_adc(void);
extern unsigned int read_adc(void);

extern void i2c_byte_write(unsigned char sa, unsigned char wa,unsigned char data);
extern unsigned char i2c_byte_read(unsigned char sa,unsigned char wa);
