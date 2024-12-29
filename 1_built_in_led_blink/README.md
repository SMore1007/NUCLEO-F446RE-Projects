# STM32_Led_Blink
STM32F446 Nucleo Board LED Blink


# STM32F446RE Nucleo Board - Bare-Metal LED Blink Project

## Project Overview
This project demonstrates how to blink the onboard LED of the STM32F446RE Nucleo board using bare-metal programming. 
The implementation involves directly accessing hardware registers without using any external libraries or frameworks such as HAL or CMSIS. 

The LED connected to pin PA5 (GPIO pin 5) on the STM32F446RE is toggled ON and OFF with a delay, showcasing fundamental GPIO operations and clock configuration.

---

## Hardware Requirements
- STM32F446RE Nucleo board
- USB cable for power and programming

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

### 2. **Initialization**:
   - Enable the GPIOA clock by setting bit 0 of `RCC_AHB1ENR`.
   - Configure PA5 as output by setting the appropriate bits in `GPIOA_MODER`.

### 3. **LED Control**:
   - Use `GPIOA_ODR` to toggle the LED:
     - Set bit 5 to turn ON the LED.
     - Clear bit 5 to turn OFF the LED.

### 4. **Delay Function**:
   - A simple empty loop introduces a delay. The delay duration can be adjusted for the desired blink speed.

---

## Code Structure
   - copy this main.c file to your created project on src folder in STM32cube ide

## How It Works
1. Enable the GPIO clock for GPIOA.
2. Set PA5 as output mode.
3. In an infinite loop, toggle the state of PA5 and introduce a delay for visible LED blinking.

---

## Key Registers Used
| Register         |   Address    | Description                                |
|------------------|--------------|--------------------------------------------|
| `RCC_AHB1ENR`    | `0x40023830` | Enables the AHB1 peripheral clock for GPIO |
| `GPIOA_MODER`    | `0x40020000` | Configures GPIOA pin modes                 |
| `GPIOA_ODR`      | `0x40020014` | Controls output data for GPIOA pins        |

---

## Improvements and Future Scope
- Implement configurable delays using SysTick timer instead of a busy-wait loop.
- Use structured headers for better readability and scalability.
- Expand the project to include external peripherals (e.g., buttons, sensors).

---

## Contributing
Feel free to fork this repository, submit pull requests, or suggest improvements.

---

## Author
**void Embedded()**  
YouTube: [Demo Video](https://youtube.com/shorts/jnpERZYrReI?si=CKZEfIEUdJxdNdmu)
YouTube: [Void Embedded()](https://youtube.com/@void_embedded?si=LfwY5p6dR7dW5s0p)
