/*
 * uart.c
 *
 *  Created on: 28-Dec-2024
 *      Author: void Embedded()
 */

#include "uart.h"
#include<stdio.h>
static void Set_Uart_BaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t Compute_Uart_Div(uint32_t PeriphClk, uint32_t BaudRate);
int __io_putchar(int ch);

void Uart2_Rx_Tx_init()
{
   /************************UART GPIO pins*************************************************/
    RCC->AHB1ENR    |= (0x1  << 0);      /* Enable the clock access to GPIOA               */
    GPIOA->MODER    &= ~(0x3  << 4);     /* Clear the PA2                                  */
    GPIOA->MODER    |= (0x1  << 5);      /* Set the PA2 for Alternate function mode        */
    GPIOA->AFR[0]   |= (0X7  << 8);      /* Alternate function type for Ap2 -> AF07 for USART2*/

    GPIOA->MODER    &= ~(0x3  << 6);     /* Clear The PA3*/
    GPIOA->MODER    |= (0x1  << 7);      /* Set the PA3 for Alternate function mode        */
    GPIOA->AFR[0]   |= (0X7  << 12);     /* Alternate function type for PA3 -> AF07 for USART2*/

   /*************************UART Module****************************************************/
    RCC->APB1ENR |= (0x1 << 17);                  /* Enable the clock access to USART2     */
    Set_Uart_BaudRate(USART2, APB1CLK, BAUDRATE); /* Baud rate set to 115200               */
    USART2->CR1 |=  (0x1 <<  3);                  /* Enable Transmit bit*/
    USART2->CR1 |=  (0x1 <<  2);                  /* Enable Receive bit                    */
    USART2->CR1 |=  (0x1 << 13);                  /* Enable the UART                       */
   /****************************************************************************************/
}
void Uart2_init()
{
   /************************UART GPIO pins*************************************************/
    RCC->AHB1ENR    |= (0x1  << 0);      /* Enable the clock access to GPIOA               */
    GPIOA->MODER    &= ~(0x3  << 4);     /* Clear the PA2                                  */
    GPIOA->MODER    |= (0x1  << 5);      /* Set the PA2 for Alternate function mode        */
    GPIOA->AFR[0]   |= (0X7  << 8);      /* Alternate function type -> AF07 for USART2     */

   /*************************UART Module***************************************************/
    RCC->APB1ENR |= (0x1 << 17);                  /* Enable the clock access to USART2     */
    Set_Uart_BaudRate(USART2, APB1CLK, BAUDRATE); /* Baud rate set to 115200               */
    USART2->CR1  |=  (0x1 <<  3);                 /* Enable Transmit bit*/
    USART2->CR1  |= (0x1 << 13);                  /* Enable the UART                       */
   /***************************************************************************************/
}

/********************* Function to set the baud rate **************************************/
static void Set_Uart_BaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = Compute_Uart_Div(PeriphClk, BaudRate);
}

/********************* Function to calculate the baud rate *********************************/
static uint16_t Compute_Uart_Div(uint32_t PeriphClk, uint32_t BaudRate)
{
    return (PeriphClk + (BaudRate / 2U)) / BaudRate; /* Baud Rate Calculation  */
}

void Uart2_Write(int ch)
{
    while(!(USART2->SR & (0x1 << 7))){}     /* Make sure the transmit data register is empty*/
    USART2->DR = (ch & 0xFF);               /* Write to transmit data register              */
}

char Uart2_Read(void)
{
    while(!(USART2->SR & (0x1 << 5))){}     /* Make sure the Receive data register is not empty*/
    return USART2->DR;                             /* Read the Data                                   */

}

void LED_init(void)  /*Blink inbult led on PA5*/
{
	/* 1. We had enabled clock for GPIOA in Uart2_init() function */
	RCC->AHB1ENR    |= (0x1  << 0);
	/* 2. Clear the PA5 pin in mode reg*/
	GPIOA->MODER &= ~(0x3 << 10);
	/* 3. Set the mode of PA5 as output type */
	GPIOA->MODER |= (0x1 << 10);
}
void LED_On(void)
{
	GPIOA->ODR |= (0x1 << 5); // Turn On the LED
//	printf("Led: ON\n");

}
void LED_Off(void)
{
	GPIOA->ODR &= ~(0x1 << 5); // Turn Off the LED
//	printf("Led: OFF\n");
}
/* Printf function */
int __io_putchar(int ch)
{
    Uart2_Write(ch);
    return ch;
}
