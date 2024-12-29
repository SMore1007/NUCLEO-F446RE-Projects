# STM32 LED Blink via UART

STM32F446RE Nucleo Board LED Control Using UART Communication

---

## Project Overview

This project demonstrates how to control an onboard LED of the STM32F446RE Nucleo board and send messages over UART communication. The LED is connected to pin PA5 (GPIO pin 5). Using UART2 configured on PA2 (TX) and PA3(Rx), the board read the UART messages, control the LED and ransmits a simple "Led: ON" and "Led: OFF" message to a serial terminal.

This implementation uses **bare-metal programming** to directly manipulate hardware registers without relying on external libraries like HAL. The project focuses on understanding the UART initialization and GPIO control.

---

## Hardware Requirements

- STM32F446RE Nucleo board  
- USB cable for power, programming, and UART communication  
- Computer with a terminal program (e.g., PuTTY, Tera Term)  

---

## Software Requirements

- STM32CubeIDE for development and debugging  
- OpenOCD or similar flashing tool
- Serial Monitor (I used Ardunio IDE)

---

## Code Explanation

### 1. **UART Configuration**
- UART2 is configured with a baud rate of 115200.  
- PA2 (USART2 TX) and PA3 (USART2 RX) is set to alternate function mode for UART transmission.  
- The alternate function type for PA2 and PA3 is configured to **AF7**.  

### 2. **GPIO Configuration**
- The GPIO clock for GPIOA is enabled to access the pins.  
- PA5 is set as output mode to control the onboard LED.  

### 3. **UART Communication**
- The UART2 peripheral is enabled by configuring the USART2 registers.  
- A simple function, `Uart2_Write()`, transmits data byte-by-byte and Uart2_Read(), reads data byte-by-byte.  
- The `printf` function is redirected to use the UART for message output.  

### 4. **Code Flow**
1. Initialize UART2 and configure PA5 as output.  
2. In an infinite loop, periodically read the input command and control the onboard Led and send a message ("Led: ON" or "Led: OFF") via UART.  

---

## Code Structure

- `main.c`: Contains the main application logic, including UART initialization and message transmission.  
- `uart.c`: Contains UART-specific functions, including initialization and data transmission.  
- `uart.h`: Header file declaring UART functions and macros.  

---

## How It Works

1. Enable the GPIOA clock for UART and LED control.  
2. Configure PA5 as output to control the LED.  
3. Initialize UART2 on PA2, PA3 with a baud rate of 115200.  
4. In an infinite loop:
   - Reads input message "ON", "OFF" via UART.
   - Control the inbuilt Led on PA5  
   - Transmit "Led: ON" or "Led: OFF" message via UART.
   - 
---

## Key Registers Used

| Register         | Description                                       |
|------------------|---------------------------------------------------|
| RCC_AHB1ENR      | Enables the AHB1 peripheral clock for GPIO        |
| GPIOA_MODER      | Configures GPIOA pin modes                        |
| GPIOA_AFR[0]     | Configures alternate functions for GPIOA pins     |
| RCC_APB1ENR      | Enables the APB1 peripheral clock for USART2      |
| USART2_BRR       | Configures the baud rate for USART2               |
| USART2_CR1       | Controls the main UART settings and enables USART |

---

## Contributing

Feel free to fork this repository, submit pull requests, or suggest improvements.

---

## Author

**void Embedded()**  
YouTube: [Demo Video](https://youtube.com/shorts/oDW3sFN8Ufs?si=VdQ8GjmIyv7x8tQI)  
YouTube: [Void Embedded()](https://youtube.com/@void_embedded?si=LfwY5p6dR7dW5s0p)
```
