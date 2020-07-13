/*LCD Function*/
void lcd_init(void);
void port_init();
void write_cmd(unsigned char cmd);
void write_data(unsigned char data);
void print(const char* str);
void blink(void);
void clear(void);
void lcd_goto(unsigned char x, unsigned char y);

#define 	DATA_PORT 	PORTB
#define 	DATA_DDR 	DDRB
#define 	CTRL_PORT 	PORTD
#define 	CTRL_DDR	DDRD
#define 	RS_PIN 		4
#define 	RW_PIN		5
#define 	EN_PIN	 	6

void port_init()
{
	CTRL_DDR 	= 0xFF;
	CTRL_PORT 	= 0x00;
	DATA_DDR 	= 0xFF;
	DATA_PORT 	= 0x00;
}
void lcd_init(void)
{
	_delay_ms(10);
	write_cmd(0x38);
	write_cmd(0x0E);
	write_cmd(0x01);
	_delay_ms(10);
	write_cmd(0x06);
}

void write_cmd(unsigned char cmd)
{
	DATA_PORT = cmd;
	CTRL_PORT &=~ (1<<RS_PIN); //set lcd in command mode
	CTRL_PORT &=~ (1<<RW_PIN); //set lcd in command mode
	
	CTRL_PORT |= (1<<EN_PIN); //enable lcd
	_delay_us(2);
	CTRL_PORT &=~ (1<<EN_PIN); //disable lcd
	_delay_us(100);	
}

void write_data(unsigned char data)
{
	DATA_PORT = data;
	CTRL_PORT |= (1<<RS_PIN); //set lcd in data mode
	CTRL_PORT &=~ (1<<RW_PIN);
	
	CTRL_PORT |= (1<<EN_PIN); //enable lcd
	_delay_us(2);
	CTRL_PORT &=~ (1<<EN_PIN); //disable lcd
	_delay_us(100);
}

void print(const char* str)
{
	while(*str >0) write_data(*str++);
}

void lcd_goto(unsigned char x, unsigned char y)
{
	unsigned char firstAddrress[] = {0x80,0xC0,0x94,0xD4};
	
	write_cmd(firstAddrress[y-1] + x-1);
	_delay_ms(10);
}	

void blink()
{
	write_cmd(0x08);
	_delay_ms(250);
	write_cmd(0x0C);
	_delay_ms(250);
}

void clear()
{
	write_cmd(0x01);
	_delay_ms(100);
}