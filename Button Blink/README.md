# Button Blink
### Ryan Hare

## Background
In the previous parts of the lab, LEDs were toggled automatically, using a delay in the software. However, automatic code is usually not the norm. More often than not, a device is useful because it accepts (and is controlled by) some form of outside input. In this part of the lab, a button on the launchpad board will be used as an input to enable or disable an LED.

In order to use a button on the MSP430 devices, the I/O registers will need to be used again. Setting the required bit to zero in PxDIR will set that specific pin as an input. However, for the button to fully work, we need to enable the pullup resistor. This is done through the use of the PxREN command, which enables the pullup resistor on a given value if the bit is set to one. Additionally, by setting the PxOUT register to a one or zero, we can tell the resistor to pull up or pull down. For this part, it will be pulling up.
## Devices
This code contains variants for five different MSP430 launchpad devices: The MSP430G2553, the MSP430FR5994, the MSP430FR6989, the MSP430FR2311, and the MSP430F5529.
## Usage
Once loaded onto the board, the button will control the state of the LED. When the button is pressed down, the LED will be on. When the button is depressed, the LED will be off.
### Other Uses
Like the LED blinking code, this code is incredibly basic. However, assigning values to the PxDIR, PxREN, PxOUT, etc. registers is the framework for using other peripherals and programming more complicated code into the MSP430 microcontrollers.
### Possible Improvements
The code uses a method called polling to check if the button is pressed or not. Polling is when the machine is constantly checking the input value to see if it is one or zero. While this works, it is very inefficient and means that the processor is running at full power all the time. This code can be vastly improved through the use of lower power mode and interrupts. The interrupts would only allow the code to run when the button is initially pressed or released, and idle the processor all other times. This would use a significantly smaller amount of energy.

An additional improvement that could be made to this code is debouncing. When the button is released (or very rarely, when it is pressed) the mechanical parts of the button will occasionally bounce and make contact more than once. This means that the processor is recieving a signal for multiple button presses when the button was only pressed once. This manifests itself in this code as the LED blinking once or twice rapidly before turning off after the button is let go.
## Board-Specific Code Differences
The code for the boards is mostly the same between them, however the pin assignments for the buttons changes by board.

For the G2553, the button is on pin 1.3

For the F5529, the button is on pin 2.1

For the FR6989, the button is on pin 1.1

For the FR5994, the button is on pin 5.6

For the FR2311, the button is on pin 1.1

Additionally, for this code to actually work on the FR5994 and F5529, another line of code was needed.

PM5CTL0 &= ~LOCKLPM5;

This code disables high impedance mode, which sets all pins to high impedance inputs. This allows the board to actually read the input of the button and toggle the LED.