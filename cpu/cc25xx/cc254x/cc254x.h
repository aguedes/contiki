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
 *   Definitions for TI cc254x specific registers.
 *
 *   Based on information in:
 *   CC253x System-on-Chip Solution for 2.4-GHz  IEEE 802.15.4 and ZigBee®
 *   Applications
 *   CC2540/41 System-on-Chip Solution for 2.4- GHz Bluetooth® low energy
 *   Applications
 *   User's Guide
 *   Literature Number: SWRU191D. April 2009–Revised March 2013
 *
 * \author
 *         Andre Guedes - <andre.guedes@openbossa.org>
 */

#ifndef __CC254X_H__
#define __CC254X_H__

#include "cc25xx.h"

/*---------------------------------------------------------------------------
 * Bluetooth Low Energy Radio Registers
 * (Page 276)
 *---------------------------------------------------------------------------*/
SFRX(RFSTAT,              0x618D); /* RF core status */
SFRX(RFC_OBS_CTRL0,       0x61AE); /* RF Observation Mux Control 0 */
SFRX(RFC_OBS_CTRL1,       0x61AF); /* RF Observation Mux Control 1 */
SFRX(RFC_OBS_CTRL2,       0x61B0); /* RF Observation Mux Control 2 */
SFRX(ATEST,               0x61A9); /* Analog Test Control */

#endif /* __CC254X_H__ */
