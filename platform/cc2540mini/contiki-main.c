#include "8051def.h"
#include "soc.h"
#include "sys/clock.h"
#include "sys/etimer.h"
#include "sys/ctimer.h"
#include "sys/rtimer.h"
#include "sys/autostart.h"
#include "dev/leds.h"
#include "dev/clock-isr.h"

int
main(void) CC_NON_BANKED
{
  leds_init();

  leds_off(LEDS_ALL);

  clock_init();
  soc_init();
  rtimer_init();

  process_init();

  process_start(&etimer_process, NULL);
  ctimer_init();

  autostart_start(autostart_processes);

  while(1) {
    process_run();
  }

  return 0;
}
