/*
 * ATmega32 Motor Control Project
 * Control DC motor with push buttons using L293D motor driver
 * Author: Jizan Rehman
 */

#define F_CPU 8000000UL    // Define clock speed (adjust as per your MCU setup)
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Configure Data Direction Registers
    DDRA = 0x00;   // Port A as input (not used here, kept default)
    DDRB = 0x00;   // Port B as input (buttons)
    PORTB = 0x0F;  // Enable pull-up resistors for PB0, PB1, PB2

    DDRC = 0xFF;   // Port C as output (to L293D motor driver)
    DDRD = 0xFF;   // Port D as output (not used here, reserved)

    while(1)
    {
        // Button on PB0 → Motor Clockwise
        if ((PINB & 0x01) == 0)
        {
            PORTC = 0x01;
            _delay_ms(100);
        }

        // Button on PB1 → Motor Counter-Clockwise
        if ((PINB & 0x02) == 0)
        {
            PORTC = 0x02;
            _delay_ms(100);
        }

        // Button on PB2 → Motor Stop
        if ((PINB & 0x04) == 0)
        {
            PORTC = 0x00;
            _delay_ms(100);
        }
    }
}

