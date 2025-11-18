# Pointers In C For Embedded Systems — Circuit Notes

| Signal | Suggested Pin | Notes |
| --- | --- | --- |
| Sensor Input | A0 / GPIO | Adjust according to the Embedded Systems board you own. |
| Actuator Output | D9 / PWM Pin | Use a transistor/driver for high-current loads. |
| Status LED | D13 or onboard LED | Mirrors the runtime state for quick debugging. |

## Wiring Checklist

1. Power rails first (5V / 3.3V and GND).
2. Route sensor outputs to the analog/digital pin noted above.
3. Add current-limiting resistors where appropriate.
4. Double-check common grounds between modules and the development board.

Refer to the course lecture for the exact schematic; reuse these notes as a quick reference.
