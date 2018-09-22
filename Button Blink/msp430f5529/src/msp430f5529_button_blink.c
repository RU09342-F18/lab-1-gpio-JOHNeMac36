#include <msp430.h>

/**
 * @file msp430g2553_button_blink.c
 * @author John McAvoy
 * @date 19 Sep 2018
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer

    // set P6.0 to output (1)
    P6DIR |= BIT0;

    // set P6.1 to input (0)
    P6DIR &= ~BIT1;

    // infinite loop
    while(1) {
        // if P6IN.1 is high
        if(P6IN & BIT1) {
            // set P1OUT.0 high
            P6OUT |= BIT0;
        }
        else {
            // set P6OUT.0 low
            P6OUT &= ~BIT0;
        }
    }

    return 0;
}
