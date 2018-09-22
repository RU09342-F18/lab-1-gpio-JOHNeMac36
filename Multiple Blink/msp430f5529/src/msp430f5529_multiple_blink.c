#include <msp430.h>

/**
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer

    // set direction P6.[2..0] to output (1)
    P6DIR |= BIT2 | BIT1 | BIT0;

    // start P6OUT.[2..0] at 1
    P6OUT |= BIT2 | BIT1 | BIT0;

    // infinite loop
    while(1) {
        // frequency loop
        for(unsigned int i = 0; i < 42; i++) {

            // base frequency
            if(i % 2 == 0) {
                // toggle P1OUT.0
                P6OUT ^= BIT0;
            }

            // 2/3 base frequency
            if(i % 3 == 0) {
                // toggle P1OUT.1
                P6OUT ^= BIT1;
            }

            // 2/7 base frequency
            if(i % 7 == 0) {
                // toggle P1OUT.2
                P6OUT ^= BIT2;
            }

            // delay
            for(unsigned int j = 0; j < 10000; j++) {
                // do nothing
            }
        }
    }

    return 0;
}
