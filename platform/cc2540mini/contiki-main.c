#include "8051def.h"
#include "soc.h"
#include "clock-isr.h"
#include "sys/clock.h"
#include "sys/etimer.h"
#include "sys/ctimer.h"
#include "sys/rtimer.h"
#include "sys/autostart.h"
#include "dev/leds.h"
#include "dev/leds.h"

SENSORS(&button_3_sensor, &button_4_sensor);

void
hw_init(void)
{
  clock_init();
  rtimer_init();
  leds_init();

  soc_init();
}

int
main(void) CC_NON_BANKED
{
  hw_init();

  process_init();
  ctimer_init();
  process_start(&etimer_process, NULL);
  autostart_start(autostart_processes);

  while(1) {
    process_run();
  }

  return 0;
}
