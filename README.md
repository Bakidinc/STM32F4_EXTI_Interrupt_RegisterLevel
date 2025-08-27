# STM32F4_EXTI_Interrupt_RegisterLevel
STM32F410RB Register-Level EXTI Interrupt Example   This project demonstrates how to configure and use EXTI (External Interrupt) on STM32F4 microcontrollers using direct register access without HAL or LL drivers.  
# STM32F410RB Register-Level EXTI Interrupt (PC7, MZ80 IR Sensor)

This project demonstrates how to configure and use **EXTI (External Interrupt)** on the **STM32F410RB** microcontroller at the **register level** without HAL/LL.  

As an example, the **MZ80 infrared sensor** is connected to pin **PC7**.  
When the sensor output changes (falling edge), an interrupt is triggered and processed by the MCU.

---

## 📂 Files
- `Read_Exti_PC7.h` → EXTI initialization function prototype.  
- `Read_Exti_PC7.c` → Register-level EXTI configuration and IRQ handler.  
- `main.c` → Project entry point. Calls `Read_Exti_PC7()` inside `main()` to enable the interrupt.  
- `README.md` → Project description.  

---

## ⚙️ Features
- Configure **PC7** as EXTI input with internal pull-up.  
- Trigger interrupt on **falling edge**.  
- Global counter `x` increments on every interrupt.  
- Modular structure (`Read_Exti_PC7.c/.h` separated).  
- Demonstrated with **MZ80 IR sensor** as the input source.  

---

## 🛠️ Hardware Setup
- **MCU**: STM32F410RB (Nucleo or custom board).  
- **Sensor**: MZ80 Infrared Obstacle Detection Sensor.  
- **Connection**:  
  - `MZ80 OUT` → `PC7` (EXTI input).  
  - `VCC` → `5V` (or `3.3V` depending on board).  
  - `GND` → `GND`.  

When the sensor detects an obstacle, its output goes LOW → generating a **falling edge** on `PC7` → EXTI interrupt fires.  

---

## 🚀 Usage in `main.c`
In your `main.c`, include the header and call the initialization inside `USER CODE BEGIN 2`:  

```c
#include "Read_Exti_PC7.h"

int main(void) {
    // HAL_Init() or system init if needed
    /* USER CODE BEGIN 2 */
    Read_Exti_PC7();   // Enable EXTI for PC7 (MZ80 sensor)
    /* USER CODE END 2 */

    while (1) {
        // main loop
    }
}


![ Görsel](https://github.com/user-attachments/assets/707a0578-1749-4515-aade-2b71222cc0a2)

