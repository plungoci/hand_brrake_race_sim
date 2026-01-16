# Hand Brake Race Sim

Arduino sketch for a handbrake input device that reads an analog potentiometer, normalizes the value, and sends it to a PC as a joystick Rx axis for racing simulation setups.

## Hardware

- **Board:** Arduino Pro Micro (ATmega32U4)
- **Potentiometer:** 10k linear pot
- **Connections (as wired):**
  - Pot **middle pin (wiper)** → **A0**
  - Pot **left pin** → **5V**
  - Pot **right pin** → **GND**

> If the axis moves in the opposite direction of what you expect, swap the 5V and GND wires on the outer pins.

## How it works

- Reads the analog value on **A0**.
- Maps the 0–1023 reading to a 0–1023 joystick axis range.
- Sends the value to the PC as the **Rx axis** of a USB joystick device.

## Setup

1. Install the **Arduino IDE**.
2. Install the **Arduino Joystick Library** (by MHeironimus) from the Library Manager or by adding the ZIP if needed.
3. Open `hand_break_sim.ino`.
4. Select the correct board:
   - **Board:** *Arduino Pro Micro*
   - **Processor:** *ATmega32U4 (5V, 16 MHz)* (typical for most Pro Micro boards)
5. Select the correct **Port**.
6. Click **Upload**.

## Calibration / Testing

- Open the **Windows Game Controllers** panel (or your OS joystick tester).
- Move the handbrake through its full range of travel.
- Verify the **Rx axis** moves smoothly from minimum to maximum.

## Notes

- Use a **linear** potentiometer for consistent response.
- If you need to adjust the range or add dead zones, modify the mapping logic in `hand_break_sim.ino`.
