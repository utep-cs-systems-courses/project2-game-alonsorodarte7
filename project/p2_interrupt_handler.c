#include <msp430.h>
#include "switches.h"

/* Switches on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2()
{
  if(P2IFG & SWITCHES) /* Did a button cause this interrupts */
    {
      P2IFG &= ~SWITCHES; /* Clear pending sw interrupts */
      switch_interrupt_handler(); /* Single handler for all switches */
    }
}
