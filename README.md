This repository contains a foundational FreeRTOS implementation demonstrating decoupled hardware-to-software communication. Running on the Cortex-M4 core, 
this exercise focuses on safely passing data from External Interrupt Service Routines (EXTI) to RTOS tasks using Queues.
🛠️ Hardware Requirements
Target Board: STM32MP157 Discovery Kit running on the Cortex-M4 coprocessor
Inputs: 2x Push Buttons
Outputs: 3x LEDs 
⚙️ How It Works
The system utilizes two primary interaction flows:

Button 1 (The Selector): Triggered via EXTI. Pushing this button cycles an internal state machine (LED 1 -> LED 2 -> LED 3). It sends a SELECT_NEXT command to the main Queue.

Button 2 (The Executor): Triggered via EXTI. Pushing this button sends a TOGGLE_CURRENT command to the Queue. The main task reads this queue and toggles the specific LED currently selected by Button 1.
