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
