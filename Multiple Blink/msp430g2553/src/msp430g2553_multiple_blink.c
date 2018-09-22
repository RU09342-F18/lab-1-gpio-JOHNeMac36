#include <msp430.h>

/**
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer

    // set P1.[2..0] to I/O
    P1SEL &= 0xf8;
    P1SEL2 &= 0xf8;

    // set direction P1.[2..0] to output (1)
    P1DIR |= 0x7;

    // start P1OUT.[2..0] at 1
    P1OUT |= 0x7;

    // infinite loop
    while(1) {
        // frequency loop
        for(unsigned int i = 0; i < 42; i++) {

            // base frequency
            if(i % 2 == 0) {
                // toggle P1OUT.0
                P1OUT ^= BIT0;
            }

            // 2/3 base frequency
            if(i % 3 == 0) {
                // toggle P1OUT.1
                P1OUT ^= BIT1;
            }

            // 2/7 base frequency
            if(i % 7 == 0) {
                // toggle P1OUT.2
                P1OUT ^= BIT2;
            }

            // delay
            for(unsigned int j = 0; j < 10000; j++) {
                // do nothing
            }
        }
    }

    return 0;
}
