#include <msp430.h> 

//Pin assignments are for the G2553 to be used on board with a breadboard for the extra LEDs.

#define LED0 BIT0; //Define all the LEDs as their respective bits for pins 1.0 to 1.7...
#define LED1 BIT1;
#define LED2 BIT2;
#define LED3 BIT4; //Skip BIT3 because that pin is the button.
#define LED4 BIT5;
#define LED5 BIT6;
#define LED6 BIT7;
#define LED7 BIT0; //...except LEDs 7 and 8, which need to be put on pins 2.0 and 2.1.
#define LED8 BIT1;
#define BUTTON BIT3;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    P1SEL &= (~LED0 & ~LED1 & ~LED2 & ~LED3 & ~LED4 & ~LED5 & ~LED6 & ~BUTTON); //Select the I/O mode for pins 1.0 to 1.7.
    P2SEL &= (~LED7 & ~LED8); //Select the I/O mode for pins 2.0 and 2.1.

    P1DIR |= LED0 | LED1 | LED2 | LED3 | LED4 | LED5 | LED6; //Set pins 1.0 to 1.7 (except 1.3) as outputs.
    P2DIR |= LED7 | LED8; //Set pins 2.0 and 2.1 as outputs.
    P1OUT &= (~LED0 & ~LED1 & ~LED2 & ~LED3 & ~LED4 & ~LED5 & ~LED6); //Set the initial LED condition to off for 1.0 to 1.7.
    P2OUT &= (~LED7 & ~LED8); //Set the initial LED condition to off for 2.0 and 2.1.

    P1DIR &= ~BUTTON; //Set pin 1.3 (Button) as an input.
    P1REN |= BUTTON; //Enable the pull resistor on pin 1.3.
    P1OUT |= BUTTON; //Tell the pull resistor to pull up.

    while(1)
    {
        P1OUT ^= LED0; //Toggle pin 1.0 (LED0).
        for(i=5000; i>0; i--); //Use a for loop to delay.
    }
}
