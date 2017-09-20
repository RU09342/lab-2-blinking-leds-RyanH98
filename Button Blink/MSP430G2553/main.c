#include <msp430.h>

#define BUTTON BIT2
#define LED1 BIT0

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer

    P1OUT &= ~LED1;
    P1DIR = LED1 & ~BUTTON;                  // configure P1.0 as output

    while(1)
    {
        if (!(BUTTON & P1IN))
            P1OUT |= LED1;
        else
            P1OUT &= ~LED1;
    }
}

