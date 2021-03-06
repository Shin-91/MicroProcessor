#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


typedef unsigned char uchar;

//digit[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x67 };

uchar digit[21] = {0x00, 0x00, 0x00, 0x00, 0x3f, 0x06, 0x3f, 0x40, 0x5b, 0x7c, 0x6d, 0x4f, 0x40, 0x4f, 0x5b, 0x7c, 0x4f, 0x00, 0x00, 0x00, 0x00};
uchar location[4] = {0x08, 0x04, 0x02, 0x01};



void show(int a)
{
	for(int i=0; i< 60;i++)
	{
		for(int j=0;j<4;j++)
		{
			PORTC = digit[j+a];
			PORTG = location[j];
			_delay_ms(2);
		}
	}
	return;
}


void work()
{
	for(int i=0;i<17;i++)
	{
		show(i);
	}
	return;
}





int main()
{

	DDRC = 0xff;
	DDRG = 0x0f;

	while(1)
	{
		work();
	}

	return 0;
}
