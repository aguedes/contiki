/*
 * Copyright (c) 2013, Instituto Nokia de Tecnologia - INdT
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 */

/**
 * \file
 *   Implementation of Contiki's clock module for CC2540 SoC.
 *
 *   Literature Number: SWRU191D. April 2009–Revised March 2013.
 *
 * \author
 *   Andre Guedes <andre.guedes@openbossa.org>
 */

#include "cc2540.h"

#define SLEEP_TIMER_CLOCK (32*1000) /* 32 kHz */
/* Initial value which sleep timer should be loaded in order to get 32 ticks
 * per second (CLOCK_SECOND defined in core/sys/clock.h).
 */
#define SLEEP_TIMER_VALUE (SLEEP_TIMER_CLOCK / CLOCK_SECOND)

static volatile clock_time_t ticks_counter;

void
init_system_clock(void)
{
  /* According to CC2540 user guide (see reference in file header), operation
   * of the RF transceiver requires 32-MHz crystal oscillator. We also leave
   * CLKSPD equals to 000 so 32 MHz clock speed is set.
   */
  CLKCONCMD = CLKCONCMD_OSC;

  /* Set timers (1-4) speed to 500 MHz */
  CLKCONCMD |= CLKCONCMD_TICKSPD_500;

  /* Wait until changes take effect */
  while(CLKCONSTA != CLKCONCMD);
}

void
init_sleep_timer(void)
{
  /* Load initial value */
  ST2 = SLEEP_TIMER_VALUE >> 16;
  ST1 = SLEEP_TIMER_VALUE >> 8;
  ST0 = SLEEP_TIMER_VALUE;

  /* Enable sleep timer interrupt */
  STIE = 1;
}

void
sleep_timer_isr(void) __interrupt(ST_IRQ)
{
  ticks_counter++;

  ST2 = SLEEP_TIMER_VALUE >> 16;
  ST1 = SLEEP_TIMER_VALUE >> 8;
  ST0 = SLEEP_TIMER_VALUE;

  /* Clear sleep timer interrupt flag */
  STIF = 0;
}

void
clock_init(void)
{
  init_system_clock();
  init_sleep_timer();
}

CCIF clock_time_t
clock_time(void)
{
  return ticks_counter;
}

CCIF unsigned long
clock_seconds(void)
{
  return ticks_counter / CLOCK_SECOND;
}
