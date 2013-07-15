#include "8051def.h"
#include "soc.h"
#include "sys/clock.h"
#include "sys/etimer.h"
#include "sys/ctimer.h"
#include "sys/rtimer.h"
#include "sys/autostart.h"
#include "dev/button-sensor.h"
#include "dev/leds.h"
#include "dev/clock-isr.h"

SENSORS(&button_3_sensor, &button_4_sensor);

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

  process_start(&sensors_process, NULL);
  BUTTON_SENSOR_ACTIVATE();

  autostart_start(autostart_processes);

  while(1) {
    process_run();
  }

  return 0;
}
