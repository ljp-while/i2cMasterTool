#include "time3.h"

uint32_t time3Value = 0;
uint8_t ledState = 0;
// �ж����ȼ�����
static void time3_nvic_init(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Ϊ0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
		// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn ;	
		// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	 
	  // ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

///*
// * ע�⣺TIM_TimeBaseInitTypeDef�ṹ��������5����Ա��TIM6��TIM7�ļĴ�������ֻ��
// * TIM_Prescaler��TIM_Period������ʹ��TIM6��TIM7��ʱ��ֻ���ʼ����������Ա���ɣ�
// * ����������Ա��ͨ�ö�ʱ���͸߼���ʱ������.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            ����
// *	TIM_CounterMode			     TIMx,x[6,7]û�У���������
// *  TIM_Period               ����
// *  TIM_ClockDivision        TIMx,x[6,7]û�У���������
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]����
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */
static void time3_mode_init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		
		// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	
		// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period=1000-1;
	  // ʱ��Ԥ��Ƶ��
    TIM_TimeBaseStructure.TIM_Prescaler= 71;	
		// ʱ�ӷ�Ƶ���� ��û�õ����ù�
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
		// ����������ģʽ������Ϊ���ϼ���
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 		
		// �ظ���������ֵ��û�õ����ù�
		TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	  // ��ʼ����ʱ��
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
		// ����������жϱ�־λ
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	  
		// �����������ж�
    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
		
		// ʹ�ܼ�����
    TIM_Cmd(TIM3, DISABLE);
}

void time3_Init(void)
{
	time3_nvic_init();
	time3_mode_init();		
}

void  TIM3_IRQHandler (void)
{
	if ( TIM_GetITStatus( TIM3, TIM_IT_Update) != RESET ) 
	{	
		time3Value++;
		if(time3Value >= 200)
		{
			time3Value = 0;
			ledState = !ledState;
			if(ledState == 0)
			{
				led_on();
			}
			else
			{
				led_off();
			}
		}
		TIM_ClearITPendingBit(TIM3 , TIM_FLAG_Update);  		 
	}		 	
}

