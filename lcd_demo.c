#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main(void)
{
	port_init();
	clear();
	lcd_init();
	lcd_goto(1,2);
	print("mahbub");
	lcd_goto(2,3);
	print("hossian");
	
	while(1)
	{
		blink();
	}
	
}