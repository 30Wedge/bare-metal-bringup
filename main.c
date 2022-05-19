/**
 * Goal is to just upload something to the micro to verify our tools.
 */

#include <stdint.h>

// Register definitions from "8.3 Digital I/O Registers" datasheet section.
#define P1OUT ((uint8_t *) 0x021)
#define P1DIR ((uint8_t *) 0x022)
// Watchdog control register from "10.3.1 WDTCTL, Watchdog Timer+ Register"
#define WDCTL ((uint16_t*) 0x120)

// Define the pins in port 1 connected to each LED
#define PIN_RED 0
#define PIN_GREEN 6

// Roughly how many CPU cycles to wait for a good delay time
#define CPU_DELAY 10000

// Define watchdog constants
#define WD_PW   0x5A00
#define WD_STOP 0x0080

int main() {

     // Stop the watchdog timer
     *WDCTL = WD_PW | WD_STOP;

     // Configure pin 1.0 and 1.6 direction as output
     *P1DIR |= (1 << PIN_RED) | (1 << PIN_GREEN);

     // Loop forever
     while(1)
     {
         // Set Pin 1.0 output to high and 1.6 low
         *P1OUT |= (1 << PIN_RED);
         *P1OUT &= ~(1 << PIN_GREEN);

         // wait for about 10000 CPU cycles
         for(int i = 0; i < CPU_DELAY; i++)
         {
         }

         // Set Pin 1.0 output to low and 1.6 high
         *P1OUT &= ~(1 << PIN_RED);
         *P1OUT |= (1 << PIN_GREEN);

         // wait for about 10000 CPU cycles
         for(int i = 0; i < CPU_DELAY; i++)
         {
         }
     }
     return 0;
 }
