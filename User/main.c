/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2020/04/30
* Description        : Main program body.
*******************************************************************************/

/*
 *@Note
 ���ڴ�ӡ�������̣�
 USART1_Tx(PA9)��
 ��������ʾʹ�� USART1(PA9) ����ӡ���Կ������

*/

#include "debug.h"


/* Global typedef */

/* Global define */

#define LED_GPIO_Port GPIOC
#define LED_Pin GPIO_Pin_13

/* Global Variable */

void LED_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = LED_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_GPIO_Port, &GPIO_InitStructure);
}


/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Return         : None
*******************************************************************************/
int main(void) {
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);

    LED_GPIO_Init();

    printf("This is printf example111\r\n");

    while (1) {
        GPIO_WriteBit(LED_GPIO_Port, LED_Pin, 1);
        Delay_Ms(250);
        GPIO_WriteBit(LED_GPIO_Port, LED_Pin, 0);
        Delay_Ms(250);
    }
}

