
#include "main.h"
#define READ_ADDR  0x005E
#define READ_VALUE 0x4136
int main(void)
{
	uint16_t readValue = 0;
	delay_init();
	led_init();
	USART1_UART_Init(115200);
	sccb_bus_init();
	time3_Init();
	while(1)
	{
		rdSensorReg16_16(READ_ADDR,&readValue);
		if(readValue == READ_VALUE)
		{
			TIM_Cmd(TIM3, DISABLE);
			led_on();
		}
		else
		{
			TIM_Cmd(TIM3, ENABLE);
		}
		readValue = 0;
		delay_ms(10);
	}
}
