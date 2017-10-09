# Simple Blink
### Ryan Hare

## Background
One of the most basic functions a microprocessor can perform is repeating a very simple set of code. This part of the lab was no different. The code here simply blinks a single LED on the MSP430 microprocessor.
An essential part of blinking an LED on a microprocessor is enabling the outputs on the required pin. This is done through the use of registers. A register on the microprocessor named PxDIR assigns the pins x.0 through x.7 to be inputs (if the value is one) or outputs (if the value is zero). To blink an LED, the pin that the LED is connected to will be set as an output. Then, a value can be passed into a PxOUT register to enable or disable the output to that specific pin.
Another part of most of this code is the line:
WDTCTL = WDTPW | WDTHOLD;
This line of code disables the watchdog timer. This allows the processor to enter infinite loops and hang on code without restarting the board. While the watchdog timer has many uses, it is disabled for convinience.
## Devices
This code contains variants for five different MSP430 launchpad devices: The MSP430G2553, the MSP430FR5994, the MSP430FR6989, the MSP430FR2311, and the MSP430F5529.
## Usage
The code is run on any of the five different devices. Once loaded onto the board, the LED will begin to blink at a steady interval.
### Other Uses
This code is extremely basic. Setting the output pin is just the groundwork for interfacing with other peripherals.
### Possible Improvements
The code uses a for loop in order to delay the blinking on the LED. This could be improved by the use of an actual timer instead. The timer would allow the board to enter low power mode, using a greatly reduced amount of energy.
## Board-Specific Code Differences
All five boards have an LED on pin 1.0. As such, the code for all five boards is identical.
