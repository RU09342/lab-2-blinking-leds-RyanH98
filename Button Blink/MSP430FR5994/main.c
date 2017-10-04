#include <msp430FR5994.h>

//The following pin assignments are for the FR5994.

#define BUTTON BIT6                 //Define "BUTTON" as bit 6.
#define LED0 BIT0                   //Define "LED0" as bit 0.
#define INP (P5IN & BUTTON)         //Define "INP" for checking if there is an input on pin 5.6
int i = 0;                          //Initialize int i for later use.

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       //Stop watchdog timer

    P1DIR |= LED0;                  //Set pin 1.0 (LED) as an output.
    P1OUT &= ~LED0;                 //Set the initial LED condition to off.

    P5DIR &= ~BUTTON;               //Set pin 5.6 (Button) as an input.
    P5REN |= BUTTON;                //Enable the pull resistor on pin 5.6.
    P5OUT |= BUTTON;                //Tell the pull resistor to pull up.
    PM5CTL0 &= ~LOCKLPM5;            //Disable high impedance mode.

    while(1) {
        if(!INP && !i){             //The first time the button is pressed, toggle the LED once and then set i = 1.
            P1OUT ^= LED0;
            i = 1;
        }
        else if(INP && i){          //Once the button is released and i = 1, set i = 0. This lets the LED toggle only once per button press.
            i = 0;
        }
    }                               //This uses polling to toggle the LED by checking for inputs constantly.
}

