#ifndef led_included
#define led_included
#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#definr LEDS (BIT0 | BIT6)

void led_init();
void led_updade();

extern unsigned char led_changed,red_on,green_on;

#endif
