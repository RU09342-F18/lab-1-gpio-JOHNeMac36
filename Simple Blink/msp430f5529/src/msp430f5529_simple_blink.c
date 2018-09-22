#include <msp430.h>

/**
 * @file msp430f5529_simple_blink.c
 * @author John McAvoy
 * @date 19 Sep 2018
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer

    // set direction of P6.0 to output (1)
    P6DIR |= BIT0;

    // set P6OUT.0 to 0
    P6OUT &= ~BIT0;

    // infinite loop
    while(1) {
        // toggle P6OUT.0
        P6OUT ^= BIT0;

        // delay
        for(unsigned int i = 0; i < 10000; i++) {
            // do nothing
        }
    }

    return 0;
}
