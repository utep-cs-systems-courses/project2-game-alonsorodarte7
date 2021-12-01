#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char super_state;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;

  /* Update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);  // If switch up, sense down
  P2IES &= (p2val | ~SWITCHES); // If switch down, sense up
  return p2val;
}

void
switch_init() // Setup switch
{
  P2REN |= SWITCHES;   // Enables resistors for switches
  P2IE  |= SWITCHES;   // Enables interrups for switches
  P2OUT |= SWITCHES;   // Pull-ups for switches
  P2DIR |= ~SWITCHES;  // Set switches' bits for outpu
  
  switch_update_interrupt_sense();
  led_update();
 }
void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if( (p2val & SW1) == 0)       // Switch 1 was pressed
    super_state = 1;

  else if( (p2val & SW2) == 0)  // Switch 2 was pressed
    super_state = 2;

  else if( (p2val & SW3) == 0)   // Switch 3 was pressed
    super_state = 3;

  else if( (p2val & SW4) == 0)   // Switch 4 was pressed
    super_state = 4;
}


