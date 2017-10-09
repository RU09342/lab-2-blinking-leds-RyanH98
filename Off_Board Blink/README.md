# Off Board Blink
### Ryan Hare

## Background
For this part of the lab, something very similar to the simple blink was performed, with a slight twist. The processor was transferred to a breadboard and used to blink an LED on the breadboard. As such, the code is very similar to the normal LED blinking code. The main difference between the off board blink and the simple blink is that additional electrical wiring is needed in order to prevent the processor from being fried by excessive current.

This code also uses a timer instead of the previously used methods to blink the LED. The timer is enabled by setting the TACTL (Timer A control) register equal to TASSEL_2 + MC_2 + ID_3. This selects the clock to use (SMCLK), sets the counting mode to continuous, and enables an 8x internal divider. Whenever the timer counts up one, the interrupt is triggered, toggling the LED. This is a very useful thing because it means the processor can be idle most of the time, saving a lot of power.
## Devices
As the MSP430G2553 is the only launchpad board of the five with a removable processor, this part only contains code for the G2553.
## Usage
The G2553 can be removed from the launchpad board and placed onto a motherboard (it needs to be on the launchpad for programming, however). As such, it is necessary to know the pins in order to wire the processor.

As another note, the RST pin on the G2553 needs to be connected to the power as well, since it resets the board on a low signal and doesn't reset on a high signal.

![alt text](https://github.com/RU09342/lab-2-blinking-leds-RyanH98/tree/master/Off_Board%20Blink/Assets/G2553Pins.png)

In this specific situation, the output is on pin 1.0, 3.3 volts were put onto the Vcc pin, and Vss was grounded. In order to prevent the processor from being damaged, a special circuit was built. This circuit involved a BJT. The BJT was used to extremely limit the current draw from the processor while still allowing the pin to control the LED.

![alt text](https://github.com/RU09342/lab-2-blinking-leds-RyanH98/tree/master/Off_Board%20Blink/Assets/OffboardCircuit.png)
### Other Uses
Since the processor can be removed from the board, this has a much wider variety of applications. The processor can be integrated into any number of breadboard circuits, making use of one or several of the pins to control LEDs, read from peripherals, or any other number of uses.
## Demonstration
![alt text](https://github.com/RU09342/lab-2-blinking-leds-RyanH98/tree/master/Off_Board%20Blink/Assets/OffboardDemo.gif)
