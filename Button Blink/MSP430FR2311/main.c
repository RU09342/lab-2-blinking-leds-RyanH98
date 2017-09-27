#include <msp430.h>

//These pin assignments are for the FR2311

#define BUTTON BIT1                 //Define "BUTTON" as bit 3.
#define LED0 BIT0                   //Define "LED0" as bit 0.
#define INP (P1IN & BUTTON)         //Define "INP" for checking if there is an input on pin 1.3.
int i = 0;                          //Initialize int i for later use.

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       //Stop watchdog timer

    P1DIR |= LED0;                  //Set pin 1.0 (LED) as an output.
    P1OUT &= ~LED0;                 //Set the initial LED condition to off.

    P1DIR &= ~BUTTON;               //Set pin 1.3 (Button) as an input.
    P1REN |= BUTTON;                //Enable the pull resistor on pin 1.3.
    P1OUT |= BUTTON;                //Tell the pull resistor to pull up.
    PM5CTL0 &= ~LOCKLPM5;            //Disable high impedance mode.

    while(1) {
        if(!INP && !i){             //The first time the button is pressed, toggle the LED once and then set i = 1.
            P1OUT ^= LED0;
            i = 1;
        }
        else if(INP && i){          //Once the button is released and i = 1, set i = 0. This lets the LED toggle only once per button press.
            i = 0;
        }
    }                               //This code mostly works for toggling the button, but the lack of debouncing means that sometimes the button toggles multiple times on a press.
}

