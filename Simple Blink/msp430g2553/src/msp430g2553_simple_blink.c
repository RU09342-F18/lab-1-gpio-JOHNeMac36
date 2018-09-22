#include <msp430.h>

/**
 * @file msp430g2553_simple_blink.c
 * @author John McAvoy
 * @date 19 Sep 2018
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer

    // set P1.0 to I/O
    P1SEL &= ~BIT0;
    P1SEL2 &= ~BIT0;

    // set direction of P1.0 to output (1)
    P1DIR |= BIT0;

    // set P1OUT.0 to 0
    P1OUT &= ~BIT0;

    // infinite loop
    while(1) {
        // toggle P1OUT.0
        P1OUT ^= BIT0;

        // delay
        for(unsigned int i = 0; i < 10000; i++) {
            // do nothing
        }
    }

    return 0;
}
