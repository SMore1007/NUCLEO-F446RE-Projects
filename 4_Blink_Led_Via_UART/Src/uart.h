/*
 * uart.h
 *
 *  Created on: 28-Dec-2024
 *  Author    : void Embedded()
 */
#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stm32f446xx.h>

/* UART configuration macros */
#define SYS_FREQ   16000000
#define APB1CLK    16000000
#define BAUDRATE   115200

/* Function prototypes */
void Uart2_init(void);
void Uart2_Write(int ch);
char Uart2_Read(void);
void Uart2_Rx_Tx_init(void);
void LED_init(void);
void LED_On(void);
void LED_Off(void);
#endif // UART_H
