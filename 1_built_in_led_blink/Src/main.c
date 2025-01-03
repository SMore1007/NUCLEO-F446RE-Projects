/**
 *
 ******************************************************************************
 * @file           : main.c
 * @author         : void Embedded()
 * @brief          : In this code  I did a Mare metal code for inbuilt LED blink on STM32F446RE nucleo board
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/*
 * Steps for LED blink
 * *******************************************************************
 * 1) Enable the clock for GPIO in AHB1ENR RCC Register
 * 2) Configure the Mode Register for GPIOA- Set to output
 * 3) Configure the output data register for GPIOA- set to output
 * ********************************************************************
 *
 * */

#include <stdint.h>

// Base addresses for RCC and GPIOA (for STM32 family)
#define RCC_AHB1ENR      ((volatile uint32_t *) 0x40023830)  // RCC AHB1 peripheral clock enable register
#define GPIOA_MODER      ((volatile uint32_t *) 0x40020000)  // GPIOA mode register
#define GPIOA_ODR        ((volatile uint32_t *) 0x40020014)  // GPIOA output data register

// Function prototypes
void init(void);
void delay(void);

void init() {
    // Enable BUS clock for GPIOA by setting the corresponding bit in RCC_AHB1ENR
    *RCC_AHB1ENR |= (1 << 0);  // Set bit 0 to 1, enabling GPIOA clock
    // Set PA5 as output mode
    *GPIOA_MODER &= ~(3 << 10); // Clear bits 10 and 11 (PA5 mode)
    *GPIOA_MODER |= (1 << 10);  // Set PA5 to output mode (binary '01' for general-purpose output)
}

void delay() {
    // Simple delay function (adjust for your clock speed for accuracy)
    for (volatile uint32_t i = 0; i < 1000000; i++) {
        // Empty loop for delay
    }
}

int main(void) {
    init();  // Initialize the GPIO and clock

    while (1) {
        // Turn on LED by setting PA5 high
        *GPIOA_ODR |= (1 << 5);   // Set bit 5 of GPIOA_ODR to 1 (LED on)
        delay();                  // Wait for some time
        // Turn off LED by setting PA5 low
        *GPIOA_ODR &= ~(1 << 5);  // Clear bit 5 of GPIOA_ODR to 0 (LED off)
        delay();                  // Wait for some time
    }
    return 0;
}

