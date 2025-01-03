/*
 ******************************************************************************
 * @file           : main.c
 * @author         : void Embedded()
 * @brief          : LED Blink via UART In STM32F446RE
 ******************************************************************************
 */
#include "uart.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

char Newdata[BUFFER_SIZE]; /* Buffer for Input message */
int bufferIndex = 0;        /* Index for filling the buffer */

int main(void)
{
    Uart2_Rx_Tx_init();
    LED_init();
    while (1)
    {
        // Read a single character from UART
        char receivedChar = Uart2_Read();

        // Check for newline or end-of-message delimiter
        if (receivedChar == '\n' || receivedChar == '\r') // Assuming \n or \r as the delimiter
        {
            Newdata[bufferIndex] = '\0'; // Null-terminate the string

            // Compare the received string
            if (strcmp(Newdata, "ON")== 0)
            {
            	printf("Led: ON\n");
            	LED_On();
            }
            else if (strcmp(Newdata, "OFF") == 0)
            {
            	printf("Led: OFF\n");
            	LED_Off();
            }
            else
            {
                printf("Unknown Command: %s\n", Newdata);
            }

            // Reset the buffer for the next message
            bufferIndex = 0;
        }
        else
        {
            // Add the received character to the buffer
            if (bufferIndex < BUFFER_SIZE - 1)
            {
                Newdata[bufferIndex++] = receivedChar;
            }
            else
            {
                // Handle buffer overflow
                printf("Buffer Overflow\n");
                bufferIndex = 0; // Reset buffer
            }
        }
    }

    return 0;
}
