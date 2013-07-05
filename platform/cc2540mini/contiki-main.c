#include "8051def.h"
#include "dev/leds.h"

int
main(void) CC_NON_BANKED
{
  leds_init();

  leds_off(LEDS_ALL);

  return 0;
}
