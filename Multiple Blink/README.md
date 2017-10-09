# Multiple Blink
### Ryan Hare

## Background
In the previous part of the lab, the microcontroller was programmed to blink a single LED. In this part, instead of a single LED, two LEDs will be programmed to blink.
Just like the previous part, the pins will be set as outputs using the PxDIR registers, and the outputs will be enabled using the PxOUT registers.
## Devices
This code contains variants for five different MSP430 launchpad devices: The MSP430G2553, the MSP430FR5994, the MSP430FR6989, the MSP430FR2311, and the MSP430F5529.
## Usage
Once the specific code for a board has been loaded, both LEDs on the board will blink at steady intervals.
### Possible Improvements
Once again, a for loop is used as a delay. This is inefficient and could be easily replaced by a timer.
## Board-Specific Code Differences
Unlike the simple blink, there are some board-specific differences between the code. This is only due to the second LED on each board being at a different pin assignment.
For the G2553, the second LED is on pin 1.6
For the FR5994, the second LED is on pin 1.2
For the FR6989, the second LED is on pin 9.7
For the FR2311, the second LED is on pin 2.1
For the F5529, the second LED is on pin 4.7
The first LED remains the same, pin 1.0, on all five boards.