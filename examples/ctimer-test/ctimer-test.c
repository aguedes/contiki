#include <stdio.h>

#include "contiki.h"
#include "sys/ctimer.h"

static struct ctimer timer;

static void
my_cb(void *data)
{
  printf("Callback called!\n");

  ctimer_reset(&timer);
}
PROCESS(ctimer_test_process, "Ctimer test process");
AUTOSTART_PROCESSES(&ctimer_test_process);

PROCESS_THREAD(ctimer_test_process, ev, data)
{
  PROCESS_BEGIN();

  ctimer_set(&timer, CLOCK_SECOND * 3, my_cb, NULL);

  PROCESS_END();
}
