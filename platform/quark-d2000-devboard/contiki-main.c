/*
 * Copyright (C) 2016, Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>

#include "cc2520.h"
#include "contiki-net.h"
#include "dev/watchdog.h"

static void
set_link_address(void)
{
  linkaddr_t addr = { 0 };

  addr.u8[7] = NODE_ID & 0xff;
  addr.u8[6] = NODE_ID >> 8;

  linkaddr_set_node_addr(&addr);
}
/*---------------------------------------------------------------------------*/
static void
setup_radio(void)
{
  uint8_t longaddr[8];
  uint16_t shortaddr;

  shortaddr = (linkaddr_node_addr.u8[0] << 8) +
    linkaddr_node_addr.u8[1];
  memset(longaddr, 0, sizeof(longaddr));
  linkaddr_copy((linkaddr_t *)&longaddr, &linkaddr_node_addr);

  cc2520_set_pan_addr(IEEE802154_PANID, shortaddr, longaddr);
  cc2520_set_channel(RF_CHANNEL);
 }
/*---------------------------------------------------------------------------*/
int
main(void)
{
  clock_init();
  rtimer_init();
  watchdog_init();
  process_init();

  process_start(&etimer_process, NULL);
  ctimer_init();

  set_link_address();

  queuebuf_init();
  netstack_init();

  setup_radio();

  memcpy(&uip_lladdr.addr, linkaddr_node_addr.u8,
         UIP_LLADDR_LEN > LINKADDR_SIZE ? LINKADDR_SIZE : UIP_LLADDR_LEN);

  process_start(&tcpip_process, NULL);

  watchdog_start();
  autostart_start(autostart_processes);

  while(1) {
    watchdog_periodic();

    process_run();
  }

  return 0;
}
