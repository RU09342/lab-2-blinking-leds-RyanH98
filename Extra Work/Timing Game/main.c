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
#define buttonIn (P1IN & BUTTON);

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    P1SEL &= 0xFF; //Select the I/O mode for pins 1.0 to 1.7.
    P2SEL &= 0x03; //Select the I/O mode for pins 2.0 and 2.1.

    P1DIR |= 0xF7; //Set pins 1.0 to 1.7 (except 1.3) as outputs.
    P2DIR |= 0x03; //Set pins 2.0 and 2.1 as outputs.
    P1OUT &= 0xF7; //Set the initial LED condition to off for 1.0 to 1.7.
    P2OUT &= 0x03; //Set the initial LED condition to off for 2.0 and 2.1.

    P1DIR &= ~BUTTON; //Set pin 1.3 (Button) as an input.
    P1REN |= BUTTON; //Enable the pull resistor on pin 1.3.
    P1OUT |= BUTTON; //Tell the pull resistor to pull up.

    CCTL0 = CCIE; //Enable interrupts for the first capture/compare register.
    TACTL = TASSEL_2 + MC_2; //Set the Clock_A control to:
                             //1. TASSEL_2 which selects SMCLK, the internal 1MHz clock.
                             //2. MC_2 which selects the continuous counting mode.

    int state = 0x00; //Initialize state machine variables.
    int nextState = 0x01;
    int speed = 0; //Initialize speed variable.

    __enable_interrupt();           //Enable interrupts.

    __bis_SR_register(LPM0 + GIE);  //Enter low power mode with interrupts.

    while(1)
    {
        //I need to use a state machine for this.
        //Intial State
        //State 1
        //State 2
        //State 3
        //State 4
        //State 5
        //State 6
        //State 7
        //State 8
        //State 9
        //Win State
        //Lose State
    }
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void) {

}
