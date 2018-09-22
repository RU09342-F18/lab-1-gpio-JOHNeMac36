#include <msp430.h>

/**
 * @file msp430g2553_button_blink.c
 * @author John McAvoy
 * @date 19 Sep 2018
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer

    // set P1.[1..0] to I/O
    P1SEL &= BIT1 | BIT0;
    P1SEL2 &= BIT1 | BIT0;

    // set P1.0 to output (1)
    P1DIR |= BIT0;

    // set P1.1 to input (0)
    P1DIR &= ~BIT1;

    // infinite loop
    while(1) {
        // if P1IN.1 is high
        if(P1IN & BIT1) {
            // set P1OUT.0 high
            P1OUT |= BIT0;
        }
        else {
            // set P1OUT.0 low
            P1OUT &= ~BIT0;
        }
    }

    return 0;
}
