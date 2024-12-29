# STM32 Button Controlled LED

STM32F446RE Nucleo Board LED Control with Button

---

## Project Overview

This project demonstrates how to control the onboard LED of the STM32F446RE Nucleo board using a push-button, with bare-metal programming. The LED is connected to pin PA5 (GPIO pin 5), and a button is connected to pin PC13 (GPIO pin 13). 

The implementation directly accesses hardware registers without using any external libraries or frameworks, such as HAL or CMSIS. When the button is pressed (logic low on PC13), the LED toggles ON; when the button is released, the LED turns OFF.

---

## Hardware Requirements
- STM32F446RE Nucleo board
- USB cable for power and programming
- Push-button connected to GPIO pin PC13

---

## Software Requirements
- A C compiler (e.g., ARM GCC toolchain or any suitable compiler for STM32)
- STM32CubeIDE
- OpenOCD or similar tool for flashing (if not using an IDE)

---

## Code Explanation

### 1. **Register Definitions**:
   - `RCC_AHB1ENR`: Enables the clock for GPIO peripherals.
   - `GPIOA_MODER`: Configures the mode (input, output, etc.) for GPIO pins.
   - `GPIOA_ODR`: Controls the output data for GPIO pins.
   - `GPIOC_MODER`: Configures GPIOC pins.
   - `GPIOC_IDR`: Reads the input data from GPIOC pins (button state).

### 2. **Initialization**:
   - Enable the GPIOA and GPIOC clocks by setting the appropriate bits in `RCC_AHB1ENR`.
   - Configure PA5 as output by setting the appropriate bits in `GPIOA_MODER`.
   - Configure PC13 as input by clearing the corresponding bits in `GPIOC_MODER`.

### 3. **Button and LED Control**:
   - Check the state of the button (PC13) using `GPIOC_IDR`.
   - If the button is pressed (logic low), set bit 5 of `GPIOA_ODR` to turn ON the LED.
   - If the button is not pressed (logic high), clear bit 5 of `GPIOA_ODR` to turn OFF the LED.

### 4. **Code Flow**:
   - The program runs in an infinite loop, constantly checking the button state and controlling the LED accordingly.

---

## Code Structure
   - Copy the `main.c` file to the `src` folder in STM32CubeIDE and build the project.

---

## How It Works
1. Enable the GPIO clock for GPIOA and GPIOC.
2. Set PA5 as output mode for controlling the LED.
3. Set PC13 as input mode for reading the button state.
4. In an infinite loop, check the state of the button and toggle the LED based on the button press.

---

## Key Registers Used
| Register         | Address       | Description                                |
|------------------|---------------|--------------------------------------------|
| RCC_AHB1ENR      | 0x40023830    | Enables the AHB1 peripheral clock for GPIO |
| GPIOA_MODER      | 0x40020000    | Configures GPIOA pin modes                 |
| GPIOA_ODR        | 0x40020014    | Controls output data for GPIOA pins        |
| GPIOC_MODER      | 0x40020800    | Configures GPIOC pin modes                 |
| GPIOC_IDR        | 0x40020810    | Reads input data from GPIOC pins           |

---

## Contributing
Feel free to fork this repository, submit pull requests, or suggest improvements.

---

## Author
**void Embedded()**  
YouTube: [Demo Video](https://youtube.com/shorts/oDW3sFN8Ufs?si=VdQ8GjmIyv7x8tQI)  
YouTube: [Void Embedded()](https://youtube.com/@void_embedded?si=LfwY5p6dR7dW5s0p)

/***************************************************************************************************************/

# STM32 LED Blink via UART

STM32F446RE Nucleo Board LED Control Using UART Communication

---

## Project Overview

This project demonstrates how to control an onboard LED of the STM32F446RE Nucleo board and send messages over UART communication. The LED is connected to pin PA5 (GPIO pin 5). Using UART2 configured on PA2 (TX), the board transmits a simple "Hello from STM32F446RE" message to a serial terminal.

This implementation uses **bare-metal programming** to directly manipulate hardware registers without relying on external libraries like HAL or CMSIS. The project focuses on understanding the UART initialization and GPIO control.

---

## Hardware Requirements

- STM32F446RE Nucleo board  
- USB cable for power, programming, and UART communication  
- Computer with a terminal program (e.g., PuTTY, Tera Term)  

---

## Software Requirements

- ARM GCC toolchain or any compatible compiler  
- STM32CubeIDE for development and debugging  
- OpenOCD or similar flashing tool  

---

## Code Explanation

### 1. **UART Configuration**
- UART2 is configured with a baud rate of 115200.  
- PA2 (USART2 TX) is set to alternate function mode for UART transmission.  
- The alternate function type for PA2 is configured to **AF7**.  

### 2. **GPIO Configuration**
- The GPIO clock for GPIOA is enabled to access the pins.  
- PA5 is set as output mode to control the onboard LED.  

### 3. **UART Communication**
- The UART2 peripheral is enabled by configuring the USART2 registers.  
- A simple function, `Uart2_Write()`, transmits data byte-by-byte.  
- The `printf` function is redirected to use the UART for message output.  

### 4. **Code Flow**
1. Initialize UART2 and configure PA5 as output.  
2. In an infinite loop, periodically send a message ("Hello from STM32F446RE") via UART.  

---

## Code Structure

- `main.c`: Contains the main application logic, including UART initialization and message transmission.  
- `uart.c`: Contains UART-specific functions, including initialization and data transmission.  
- `uart.h`: Header file declaring UART functions and macros.  

---

## How It Works

1. Enable the GPIOA clock for UART and LED control.  
2. Configure PA5 as output to control the LED.  
3. Initialize UART2 on PA2 with a baud rate of 115200.  
4. In an infinite loop:  
   - Transmit "Hello from STM32F446RE" via UART.  
   - Optionally toggle the LED for visual feedback.  

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
