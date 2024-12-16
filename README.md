# STM32F446RE Projects Repository

Welcome to the **STM32F446RE Projects Repository**! This repository showcases various projects implemented using the STM32F446RE Nucleo board. Each project demonstrates the use of peripherals, communication protocols, and advanced features of the STM32F446RE microcontroller.

---

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project List](#project-list)
- [How to Use](#how-to-use)
- [Folder Structure](#folder-structure)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

The STM32F446RE microcontroller from the STM32 family is a powerful platform for embedded system development. This repository contains a collection of hands-on projects that explore various capabilities of the STM32F446RE Nucleo board, including GPIO control, timers, interrupts, communication protocols (SPI, I2C, UART), and more advanced features like PWM generation and ADC usage.

These projects are created using **STM32CubeIDE**, the official development environment provided by STMicroelectronics, ensuring efficient and robust development.

---

## Hardware Requirements

To work with the projects in this repository, you will need:

- **STM32F446RE Nucleo Board**
- USB cable for programming and communication
- Optional peripheral components like LEDs, buttons, sensors, etc. (specific to each project)
- Breadboard, jumper wires, and other basic electronics tools

---

## Software Requirements

- [**STM32CubeIDE**](https://www.st.com/en/development-tools/stm32cubeide.html) (version 1.13.0 or later recommended)
- STM32CubeMX (integrated in STM32CubeIDE)
- Optional: [**STM32CubeProgrammer**](https://www.st.com/en/development-tools/stm32cubeprog.html)
- Drivers for the Nucleo board (available on STMicroelectronics' website)

---

## Project List

The following projects are included in this repository:

1. **Blink LED**
   - Basic GPIO control to toggle an LED.

2. **Button Controlled LED**
   - Read input from a button to control an LED.

3. **PWM Control for LED Brightness**
   - Objective: Learn to generate Pulse Width Modulation (PWM) signals.
   - Focus Area: Timers and PWM peripherals.

5. **UART Communication**
   - Objective: Interface STM32 with a PC or another microcontroller via UART.
   - Focus Area: Serial communication.

6. **I2C Communication with an EEPROM**
   - Objective: Store and retrieve data using an external EEPROM.
   - Focus Area: I2C protocol.

7. **SPI Communication with an OLED Display**
   - Objective: Display text or graphics on an SPI OLED.
   - Focus Area: SPI protocol and display interfacing.

8. **ADC with a Potentiometer**
   - Objective: Read analog data using the ADC and control an LED's brightness.
   - Focus Area: ADC peripheral.

9. **Temperature Sensing with an LM35 Sensor**
   - Objective: Measure temperature using an analog temperature sensor and display it on UART.
   - Focus Area: ADC and real-world sensor integration.

10. **DAC for Signal Generatio**
   - Objective: Generate a sine wave or triangular wave using the DAC.
   - Focus Area: DAC peripheral.

11. **Servo Motor Control**
   - Objective: Control a servo motor's position using PWM.
   - Focus Area: Timers and PWM peripherals.

12. **Real-Time Clock (RTC)**
   - Objective: Implement a real-time clock to display time on UART or an LCD.
   - Focus Area: RTC peripheral.

13. **External Interrupts with Push Buttons**
   -Objective: Trigger an LED using external interrupts.
   - Focus Area: External interrupt handling.
     
14. **DMA with ADC**
   - Objective: Stream ADC data to memory using DMA for efficiency.
   - Focus Area: DMA and ADC.

15. **CAN Communication**
   - Objective: Implement CAN communication between two STM32 boards.
   - Focus Area: Controller Area Network (CAN).

16. **USART with DMA**
   - Objective: Transmit and receive data using USART with DMA.
   - Focus Area: USART and DMA integration.

17. **DAC for Signal Generation**
   - Objective: Generate a sine wave or triangular wave using the DAC.
   - Focus Area: DAC peripheral.

18. **SD Card Data Logging**
   - Objective: Write and read data to/from an SD card.
   - Focus Area: File system and SDIO peripheral.

19. **FreeRTOS LED Blink**
   - Objective: Implement multitasking using FreeRTOS to blink multiple LEDs.
   - Focus Area: Real-Time Operating Systems (RTOS).

20. **Ultrasonic Sensor for Distance Measurement**
    - Objective: Measure distance using an ultrasonic sensor and display it on UART or an OLED.
    - Focus Area: Timers and sensor interfacing.

21. **DC Motor Control Using H-Bridge**
    - Objective: Control the direction and speed of a DC motor.
    - Focus Area: PWM, GPIO, and motor driver circuits.

22. **WiFi Communication Using ESP8266**
    - Objective: Send data from STM32 to a server via WiFi.
    - Focus Area: UART communication and IoT.
    
---

## How to Use

1. Clone this repository:
   ```bash
   git clone https://github.com/SMore1007/STM32F446RE-Projects.git
   ```

2. Open **STM32CubeIDE** and import the desired project:
   - Go to `File > Import > Existing Projects into Workspace`.
   - Select the folder containing the project files.

3. Connect the STM32F446RE Nucleo board to your computer using a USB cable.

4. Build and flash the project to the board using STM32CubeIDE.

5. Follow the project-specific instructions provided in each project folder's `README.md`.

---

## Folder Structure

```plaintext
STM32F446RE-Projects/
|
|-- Project1_Blink_LED/
|   |-- Core/
|   |-- Drivers/
|   |-- .project
|   |-- README.md
|
|-- Project2_Button_LED/
|   |-- Core/
|   |-- Drivers/
|   |-- .project
|   |-- README.md
|
|-- ProjectN_Custom_Project/
|   |-- Core/
|   |-- Drivers/
|   |-- .project
|   |-- README.md
|
|-- LICENSE
|-- README.md  <-- Main repository README file
```

Each project is stored in its own directory with its associated source code, configuration files, and a dedicated `README.md` for detailed project information.

---

## Contributing

Contributions are welcome! To contribute:

1. Fork this repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes with descriptive messages.
4. Submit a pull request.

Please ensure that your code adheres to the coding standards and is thoroughly tested.

---
## Demo Video

All the Project demo videos I have uploaded on my Youtube channel [YouTube](https://www.youtube.com/@void_Embedded).

## License

This repository is licensed under the [MIT License](LICENSE). Feel free to use and modify the code as per your requirements.

---

Happy coding! If you have any questions, feel free to open an issue or contact me through [GitHub](https://github.com/SMore1007).
