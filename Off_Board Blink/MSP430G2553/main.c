#include <msp430.h>

//With the off board blink, we can still use pin 1.0 for the LED.

#define LED1 BIT0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= LED1;                  //Configure pin 1.0 as an output.

    int i = 0;        //Initialize int i for the for loop.

    while(1)
    {
        P1OUT ^= LED1;              //Toggle pin 1.0 (the LED).
        for(i=5000; i>0; i--);      //Use a for loop to delay.
    }
}
