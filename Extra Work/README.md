# Extra Work
### Ryan Hare

## Background
For the extra work for Lab 2, I decided to go further with the off-board blink and create a little game. The wiring is very similar to the off-board blink wiring, but with more LEDs and an off-board button. The code is quite different from the off-board blink code. The code defines a much larger number of LEDs and uses both timer interrupts and button interrupts to function. The game features seven LEDs in a line. The LEDs will light up, one at a time, in a wave-like pattern. If the button is pressed when the middle (green) LED is lit, the wave pattern will speed up. If the button is pressed when any other (red) LED is lit, the pattern will slow down.
## Devices
As the MSP430G2553 is the only board of the five with a removable processor, this code is designed for (and only works on) the G2553.
## Usage
The processor was programmed and then placed onto the breadboard. The circuit diagram is shown below. It is very similar to the off-board blink wiring, however it also encorporates an off-board button and a larger number of LEDs.
The reset pin on the G2553 also needs to be set high by connecting it to Vcc to keep the board from resetting.
![alt text](https://github.com/RU09342/lab-2-blinking-leds-RyanH98/tree/master/Extra Work/Assets/GameCircuit.png)
The pins for the G2553 are shown below
![alt text](https://github.com/RU09342/lab-2-blinking-leds-RyanH98/tree/master/Extra Work/Assets/G2553Pins.png)
## Demonstration
![alt text](https://github.com/RU09342/lab-2-blinking-leds-RyanH98/tree/master/Extra Work/Assets/GameDemo.gif)
