////////////////////////////////////////
// Ӧ�ó��򣬵���OSEK_NM�ķ���
////////////////////////////////////////
#include "OsekNM.h"
#include "Driver_Common.h" //ƽ̨��ص�����
#include "OsekNMServer.h"
#include "Timer.h"
#include "usart.h"
#include "CAN.h"
#include "delay.h"
#define PRINT
int main()
{
	/*ƽ̨��ʼ��*/
	#ifdef STM32F407
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	uart_init(115200);	//��ʼ�����ڲ�����Ϊ115200
	delay_init(168);    //��ʼ����ʱ����
	//Stm32Timer3Init();//10ms�ж�һ��
	//STM32_CAN1_Init();
		/*5.ʹ��LED0*/
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);  ///ʹ��GPIOEʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//25MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��PE3
  GPIO_SetBits(GPIOE,GPIO_Pin_3);
	#ifdef PRINT
	printf("at main\n");
	#endif
	#endif
	StartNM();
}
