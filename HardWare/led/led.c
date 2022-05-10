#include "led.h"

void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
    /* enable the LED1 GPIO clock */
	RCC_APB2PeriphClockCmd(LED_CLOCK, ENABLE);	 
	/* configure LED1 GPIO port */ 
	  GPIO_InitStructure.GPIO_Pin = LED_PIN;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	  GPIO_Init(LED_PORT, &GPIO_InitStructure);
	  led_off();
}


void led_on(void)
{
	GPIO_ResetBits(LED_PORT, LED_PIN);
}

void led_off(void)
{
	GPIO_SetBits(LED_PORT, LED_PIN);
}

