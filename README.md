# Smart Home Automation System (ATmega32)

An embedded systems project implementing a **Smart Home Automation System** on an **ATmega32** microcontroller running at **16 MHz** using a **Layered Architecture** (MCAL, HAL, and Application layers). The system monitors ambient light, room temperature, and fire hazards to automate lighting, fan speed via PWM, LCD status feedback, and alarm alerts.

## System Architecture

The software follows a layered architecture:
- **Application Layer:** `smart_home.c` (system state logic, sensor thresholds, LCD updates, and fire alert handling)
- **HAL (Hardware Abstraction Layer):** `lcd`, `LED`, `buzzer`, `DCmotor`, `flame_sensor`, `lm35`, `LDR_sensor`
- **MCAL (Microcontroller Abstraction Layer):** `gpio`, `pwm`, `adc` (along with `std_types.h` and `common_macros.h`)

## Features & Control Logic

### 1. Automatic Lighting Control (LDR)
Reads light intensity via **ADC Channel 0 (`PA0`)** and controls three status LEDs (`PB5`, `PB6`, `PB7`):
- **Intensity < 15%:** Red, Green, and Blue LEDs **ON**
- **Intensity 16% – 50%:** Red and Green LEDs **ON**
- **Intensity 51% – 70%:** Red LED **ON**
- **Intensity > 70%:** All LEDs **OFF**

### 2. Automatic Fan Speed Control (LM35 + PWM)
Reads room temperature via **ADC Channel 1 (`PA1`)** and adjusts DC motor speed using **PWM (`PB3/OC0`)** through an **H-Bridge (`L293D`)**:
- **Temperature ≥ 40°C:** Fan **ON** at **100%** speed
- **35°C ≤ Temperature < 40°C:** Fan **ON** at **75%** speed
- **30°C ≤ Temperature < 35°C:** Fan **ON** at **50%** speed
- **25°C ≤ Temperature < 30°C:** Fan **ON** at **25%** speed
- **Temperature < 25°C:** Fan **OFF**

### 3. Fire Detection & Critical Alert (Flame Sensor)
Monitors flame detection on **`PD2`**:
- When fire is detected, triggers an alarm via the **Buzzer (`PD3`)** and displays `"Critical alert!"` on the LCD.
- Remains in alert mode until the flame condition clears.

### 4. Real-Time LCD Display (`16x2` in 8-bit Mode)
- **Row 1:** Displays `"FAN is ON"` or `"FAN is OFF"` based on fan state.
- **Row 2:** Displays temperature and light intensity (`"Temp= xxC LDR= xxx%"`).

## Hardware & Pin Mapping

| Component | Pin / Port Connection | Notes |
| :--- | :--- | :--- |
| **Microcontroller** | ATmega32 | System Clock: `16 MHz` |
| **LDR Sensor** | `PA0` (`ADC0`) | Ambient light measurement |
| **LM35 Sensor** | `PA1` (`ADC1`) | Room temperature measurement |
| **Flame Sensor** | `PD2` | Fire detection input |
| **Buzzer** | `PD3` | Alarm output (with driver stage) |
| **Motor Control (H-Bridge)** | `IN1`: `PB0`, `IN2`: `PB1`, `EN1/OC0`: `PB3` | PWM speed control + direction pins |
| **Red LED** | `PB5` | Light level indicator |
| **Green LED** | `PB6` | Light level indicator |
| **Blue LED** | `PB7` | Light level indicator |
| **16x2 LCD (8-bit)** | `RS`: `PD0`, `E`: `PD1`, `RW`: `GND`, `Data`: `PORTC` | Write-only mode (`RW` tied to ground) |

## Simulation & Tools
- **IDE / Compiler:** Eclipse IDE with AVR toolchain (`ATmega32`, `16 MHz`)
- **Simulation & Monitoring:** Proteus (including virtual oscilloscope monitoring on `PB3`)

## How to Build & Run
1. Import the project into **Eclipse IDE** using the existing `.project` and `.cproject` files.
2. Verify the target MCU is set to **ATmega32** and clock frequency to **16 MHz**.
3. Build the project to generate the `.hex` / `.elf` output file.
4. Load the generated firmware into the **ATmega32** in **Proteus** and run the simulation.
