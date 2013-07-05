#include "cc2540mini.h"

#include "dev/leds.h"

void
leds_arch_init(void)
{
  P1SEL &= ~(LED_GREEN_MASK | LED_RED_MASK);
  P1DIR |= (LED_GREEN_MASK | LED_RED_MASK);
}

unsigned char
leds_arch_get(void)
{
  return (unsigned char)(LED_GREEN_PIN | (LED_RED_PIN << 2));
}

void
leds_arch_set(unsigned char leds)
{
  LED_GREEN_PIN = leds & LEDS_GREEN;
  LED_RED_PIN = !!(leds & LEDS_RED);
}
