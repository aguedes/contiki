#include "8051def.h"
#include "soc.h"
#include "sys/clock.h"
#include "dev/leds.h"
#include "dev/clock-isr.h"

int
main(void) CC_NON_BANKED
{
  leds_init();

  leds_off(LEDS_ALL);

  clock_init();
  soc_init();

  return 0;
}
