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

#include "port.h"
#include "dev/button-sensor.h"

#define BUTTON_3_PORT 0
#define BUTTON_3_PIN  1
#define BUTTON_4_PORT 0
#define BUTTON_4_PIN  0

/* Based on platform/cc2530dk/dev/button-sensor.h */
#define BUTTON_READ(b)           PORT_READ(b##_PORT, b##_PIN)
#define BUTTON_FUNC_GPIO(b)      PORT_FUNC_GPIO(b##_PORT, b##_PIN)
#define BUTTON_DIR_INPUT(b)      PORT_DIR_INPUT(b##_PORT, b##_PIN)
#define BUTTON_IRQ_ENABLED(b)    PORT_IRQ_ENABLED(b##_PORT, b##_PIN)
#define BUTTON_IRQ_CHECK(b)      PORT_IRQ_CHECK(b##_PORT, b##_PIN)
#define BUTTON_IRQ_ENABLE(b)     PORT_IRQ_ENABLE(b##_PORT, b##_PIN)
#define BUTTON_IRQ_DISABLE(b)    PORT_IRQ_DISABLE(b##_PORT, b##_PIN)
#define BUTTON_IRQ_FLAG_OFF(b)   PORT_IRQ_FLAG_OFF(b##_PORT, b##_PIN)
#define BUTTON_IRQ_ON_PRESS(b)   PORT_IRQ_EDGE_RISE(b##_PORT, b##_PIN)
#define BUTTON_IRQ_ON_RELEASE(b) PORT_IRQ_EDGE_FALL(b##_PORT, b##_PIN)

static CC_AT_DATA struct timer debounce_timer[2];

static int
value_b3(int type)
{
  type;
  return BUTTON_READ(BUTTON_3) || !timer_expired(&debounce_timer[0]);
}

static int
status_b3(int type)
{
  switch(type) {
  case SENSORS_ACTIVE:
  case SENSORS_READY:
    return BUTTON_IRQ_ENABLED(BUTTON_3);
  }
  return 0;
}

static int
configure_b3(int type, int value)
{
  switch(type) {
  case SENSORS_HW_INIT:
    BUTTON_IRQ_ON_PRESS(BUTTON_3);
    BUTTON_FUNC_GPIO(BUTTON_3);
    BUTTON_DIR_INPUT(BUTTON_3);
    return 1;
  case SENSORS_ACTIVE:
    if(value) {
      if(!BUTTON_IRQ_ENABLED(BUTTON_3)) {
        timer_set(&debounce_timer[0], 0);
        BUTTON_IRQ_FLAG_OFF(BUTTON_3);
        BUTTON_IRQ_ENABLE(BUTTON_3);
      }
    } else {
      BUTTON_IRQ_DISABLE(BUTTON_3);
    }
    return 1;
  }
  return 0;
}

static int
value_b4(int type)
{
  type;
  return BUTTON_READ(BUTTON_4) || !timer_expired(&debounce_timer[1]);
}

static int
status_b4(int type)
{
  switch(type) {
  case SENSORS_ACTIVE:
  case SENSORS_READY:
    return BUTTON_IRQ_ENABLED(BUTTON_4);
  }
  return 0;
}

static int
configure_b4(int type, int value)
{
  switch(type) {
  case SENSORS_HW_INIT:
    BUTTON_IRQ_ON_PRESS(BUTTON_4);
    BUTTON_FUNC_GPIO(BUTTON_4);
    BUTTON_DIR_INPUT(BUTTON_4);
    return 1;
  case SENSORS_ACTIVE:
    if(value) {
      if(!BUTTON_IRQ_ENABLED(BUTTON_4)) {
        timer_set(&debounce_timer[1], 0);
        BUTTON_IRQ_FLAG_OFF(BUTTON_4);
        BUTTON_IRQ_ENABLE(BUTTON_4);
      }
    } else {
      BUTTON_IRQ_DISABLE(BUTTON_4);
    }
    return 1;
  }
  return 0;
}

void
port_0_ISR(void) __interrupt (P0INT_VECTOR)
{
  DISABLE_INTERRUPTS();
  ENERGEST_ON(ENERGEST_TYPE_IRQ);

  /* Check if the interruption was caused by BUTTON_3 */
  if(BUTTON_IRQ_CHECK(BUTTON_3)) {
    if(timer_expired(&debounce_timer[0])) {
      timer_set(&debounce_timer[0], CLOCK_SECOND / 8);
      sensors_changed(&button_3_sensor);
    }
  }

  /* Check if the interruption was caused by BUTTON_4 */
  if(BUTTON_IRQ_CHECK(BUTTON_4)) {
    if(timer_expired(&debounce_timer[1])) {
      timer_set(&debounce_timer[1], CLOCK_SECOND / 8);
      sensors_changed(&button_4_sensor);
    }
  }

  BUTTON_IRQ_FLAG_OFF(BUTTON_3);
  BUTTON_IRQ_FLAG_OFF(BUTTON_4);

  ENERGEST_OFF(ENERGEST_TYPE_IRQ);
  ENABLE_INTERRUPTS();
}

SENSORS_SENSOR(button_3_sensor, "Button 3", value_b3, configure_b3, status_b3);
SENSORS_SENSOR(button_4_sensor, "Button 4", value_b4, configure_b4, status_b4);
