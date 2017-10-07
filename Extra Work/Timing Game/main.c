#include <msp430.h> 

//Pin assignments are for the G2553 to be used on a breadboard.

#define LED0 BIT0; //Define all the LEDs as their respective bits for pins 1.0 to 1.6
#define LED1 BIT1;
#define LED2 BIT2;
#define LED3 BIT3;
#define LED4 BIT4;
#define LED5 BIT5;
#define LED6 BIT6;
#define BUTTON BIT7; //Define the button on pin 1.7

int pos = 0x01; //Initialize position variable.
int time = 0;
unsigned int speed = 10; //Initialize speed variable.
int direction = 0; //Initialize direction variable.

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    P1SEL &= 0xFF; //Select the I/O mode for pins 1.0 to 1.7

    P1DIR |= 0x7F; //Set pins 1.0 to 1.6 as outputs.
    P1DIR &= ~BUTTON; //Set pin 1.7 as an input.
    P1OUT &= 0x7F; //Set the initial LED condition to off for 1.0 to 1.6

    P1IE |= BUTTON; //Enable interrupts on P1.7
    P1IES |= BUTTON; //Set the P1.7 interrupt to trigger on a high->low edge
    P1IFG &= ~BUTTON; //Clear the interrupt flag register on P1.7

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

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void) {
    time = (time + 1) % speed;
    if (time == 0){
        if (pos == 0x40)
            direction = 0;
        else if (pos == 0x01)
            direction = 1;
        switch(direction){
            case 0:
                pos = pos >> 1;
                break;
            case 1:
                pos = pos << 1;
                break;
        }
        P1OUT = pos;
    }

}

#pragma vector=PORT1_VECTOR          //Set the port 1 interrupt routine
__interrupt void Port_1(void) {
    TA0CCTL0 &= ~CCIE; //Disable timer interrupts.
    if (pos == 0x08){
        if (TA0CCTL0 <= 32767)
            pos = 0x01;
        else
            pos = 0x80;
        if (speed >= 1)
            speed--;
        P1OUT = 0x08;
    }
    else {
        if (TA0CCTL0 <= 32767)
            pos = 0x01;
        else
            pos = 0x80;
        speed++;
        P1OUT = 0x77;
    }
    __delay_cycles(1000);
    TA0CCTL0 = CCIE; //Re-enable timer interrupts.
    P1IFG &= ~BUTTON; //Clear the interrupt flag register on P1.7
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void) {

}
