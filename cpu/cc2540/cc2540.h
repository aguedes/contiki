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
 *   Definitions for TI CC2540 SoC SFR registers. This header is based on
 *   cc253x.h.
 *
 *   Based on information in:
 *   "User's Guide: CC2540/41 System-on-Chip Solution for 2.4-GHz Bluetooth®
 *   low energy Applications"
 *
 *   Literature Number: SWRU191D. April 2009–Revised March 2013.
 *
 * \author
 *   Andre Guedes <andre.guedes@openbossa.org>
 */

#ifndef __CC2540_H__
#define __CC2540_H__

#include <compiler.h>

#define BIT(n) (1UL << (n))

/* Interrupt Numbers  */
#define RFERR_IRQ     0  /* RF TXFIFO underflow and RXFIFO overflow. */
#define ADC_IRQ       1  /* ADC end of conversion */
#define URX0_IRQ      2  /* USART 0 RX complete */
#define URX1_IRQ      3  /* USART 1 RX complete */
#define ENC_IRQ       4  /* AES encryption/decryption complete */
#define ST_IRQ        5  /* Sleep Timer compare */
#define P2INT_IRQ     6  /* Port 2 inputs/USB/I2C */
#define UTX0_IRQ      7  /* USART 0 TX complete */
#define DMA_IRQ       8  /* DMA transfer complete */
#define T1_IRQ        9  /* Timer 1 (16-bit) capture/compare/overflow */
#define T2_IRQ       10  /* Timer 2 (MAC Timer) */
#define T3_IRQ       11  /* Timer 3 (8-bit) compare/overflow */
#define T4_IRQ       12  /* Timer 4 (8-bit) compare/overflow */
#define P0INT_IRQ    13  /* Port 0 inputs */
#define UTX1_IRQ     14  /* USART1 TX complete */
#define P1INT_IRQ    15  /* Port 1 inputs */
#define RF_IRQ       16  /* RF general interrupts */
#define WDT_IRQ      17  /* Watchdog overflow in timer mode */

/* 8051 Internals */
SFR(P0,        0x80); /* Port 0 */
  SBIT(P0_7,     0x80, 7); /* Port 0 bit 7 */
  SBIT(P0_6,     0x80, 6); /* Port 0 bit 6 */
  SBIT(P0_5,     0x80, 5); /* Port 0 bit 5 */
  SBIT(P0_4,     0x80, 4); /* Port 0 bit 4 */
  SBIT(P0_3,     0x80, 3); /* Port 0 bit 3 */
  SBIT(P0_2,     0x80, 2); /* Port 0 bit 2 */
  SBIT(P0_1,     0x80, 1); /* Port 0 bit 1 */
  SBIT(P0_0,     0x80, 0); /* Port 0 bit 0 */
SFR(SP,        0x81); /* Stack pointer */
SFR(DPL0,      0x82); /* Data pointer 0 low byte */
SFR(DPH0,      0x83); /* Data pointer 0 high byte */
SFR(DPL1,      0x84); /* Data pointer 1 low byte */
SFR(DPH1,      0x85); /* Data pointer 1 high byte */
SFR(PCON,      0x87); /* Power mode control */
SFR(TCON,      0x88); /* Interrupt flags */
  SBIT(URX1IF,   0x88, 7); /* USART1 RX interrupt flag */
  SBIT(ADCIF,    0x88, 5); /* ADC interrupt flag */
  SBIT(URX0IF,   0x88, 3); /* USART0 RX interrupt flag */
  SBIT(IT1,      0x88, 2); /* Reserved. Must always be set to 1 */
  SBIT(RFERRIF,  0x88, 1); /* RF TXFIFO/RXFIFO interrupt flag */
  SBIT(IT0,      0x88, 0); /* Reserved. Must always be set to 1 */
SFR(P1,        0x90); /* Port 1 */
  SBIT(P1_7,     0x90, 7); /* Port 1 bit 7 */
  SBIT(P1_6,     0x90, 6); /* Port 1 bit 6 */
  SBIT(P1_5,     0x90, 5); /* Port 1 bit 5 */
  SBIT(P1_4,     0x90, 4); /* Port 1 bit 4 */
  SBIT(P1_3,     0x90, 3); /* Port 1 bit 3 */
  SBIT(P1_2,     0x90, 2); /* Port 1 bit 2 */
  SBIT(P1_1,     0x90, 1); /* Port 1 bit 1 */
  SBIT(P1_0,     0x90, 0); /* Port 1 bit 0 */
SFR(DPS,       0x92); /* Data pointer select */
SFR(S0CON,     0x98); /* Interrupt flags 2 */
  SBIT(ENCIF_1,  0x98, 1); /* AES Interrupt flag 1 */
  SBIT(ENCIF_0,  0x98, 0); /* AES Interrupt flag 0 */
SFR(IEN2,      0x9A); /* Interrupt enable 2 */
SFR(S1CON,     0x9B); /* Interrupt flags 3 */
SFR(P2,        0xA0); /* Port 2 */
  SBIT(P2_7,     0xA0, 7); /* Port 2 bit 7 */
  SBIT(P2_6,     0xA0, 6); /* Port 2 bit 6 */
  SBIT(P2_5,     0xA0, 5); /* Port 2 bit 5 */
  SBIT(P2_4,     0xA0, 4); /* Port 2 bit 4 */
  SBIT(P2_3,     0xA0, 3); /* Port 2 bit 3 */
  SBIT(P2_2,     0xA0, 2); /* Port 2 bit 2 */
  SBIT(P2_1,     0xA0, 1); /* Port 2 bit 1 */
  SBIT(P2_0,     0xA0, 0); /* Port 2 bit 0 */
SFR(IEN0,      0xA8); /* Interrupt enable 0 */
  SBIT(EA,       0xA8, 7); /* All interrupts - enable/disable */
  SBIT(STIE,     0xA8, 5); /* Sleep Timer interrupt enable */
  SBIT(ENCIE,    0xA8, 4); /* AES encryption/decryption interrupt enable */
  SBIT(URX1IE,   0xA8, 3); /* USART1 RX interrupt enable */
  SBIT(URX0IE,   0xA8, 2); /* USART0 RX interrupt enable */
  SBIT(ADCIE,    0xA8, 1); /* ADC interrupt enable */
  SBIT(RFERRIE,  0xA8, 0); /* RF TXFIFO/RXFIFO interrupt enable */
SFR(IP0,       0xA9); /* Interrupt priority 0 */
SFR(IEN1,      0xB8); /* Interrupt enable 1 */
  SBIT(P0IE,     0xB8, 5); /* Port 0 interrupt enable */
  SBIT(T4IE,     0xB8, 4); /* Timer 4 interrupt enable */
  SBIT(T3IE,     0xB8, 3); /* Timer 3 interrupt enable */
  SBIT(T2IE,     0xB8, 2); /* Timer 2 interrupt enable */
  SBIT(T1IE,     0xB8, 1); /* Timer 1 interrupt enable */
  SBIT(DMAIE,    0xB8, 0); /* DMA Transfer interrupt enable */
SFR(IP1,       0xB9); /* Interrupt priority 1 */
SFR(IRCON,     0xC0); /* Interrupt flags 4 */
  SBIT(STIF,     0xC0, 7); /* Sleep Timer interrupt flag */
  SBIT(P0IF,     0xC0, 5); /* Port 0 interrupt flag */
  SBIT(T4IF,     0xC0, 4); /* Timer 4 interrupt flag */
  SBIT(T3IF,     0xC0, 3); /* Timer 3 interrupt flag */
  SBIT(T2IF,     0xC0, 2); /* Timer 2 interrupt flag */
  SBIT(T1IF,     0xC0, 1); /* Timer 1 interrupt flag */
  SBIT(DMAIF,    0xC0, 0); /* DMA-complete interrupt flag */
SFR(PSW,       0xD0); /* Program status word */
  SBIT(CY,       0xD0, 7); /* Carry flag */
  SBIT(AC,       0xD0, 6); /* Auxiliary carry flag */
  SBIT(F0,       0xD0, 5); /* User-defined flag 1, bit addressable */
  SBIT(RS1,      0xD0, 4); /* Register bank select, bit 1 */
  SBIT(RS0,      0xD0, 3); /* Register bank select, bit 0 */
  SBIT(OV,       0xD0, 2); /* Overflow flag */
  SBIT(F1,       0xD0, 1); /* User-defined flag 0, bit addressable */
  SBIT(P,        0xD0, 0); /* Parity flag */
SFR(ACC,       0xE0); /* Accumulator */
  SBIT(ACC_7,    0xE0, 7); /* Accumulator bit 7 */
  SBIT(ACC_6,    0xE0, 6); /* Accumulator bit 6 */
  SBIT(ACC_5,    0xE0, 5); /* Accumulator bit 5 */
  SBIT(ACC_4,    0xE0, 4); /* Accumulator bit 4 */
  SBIT(ACC_3,    0xE0, 3); /* Accumulator bit 3 */
  SBIT(ACC_2,    0xE0, 2); /* Accumulator bit 2 */
  SBIT(ACC_1,    0xE0, 1); /* Accumulator bit 1 */
  SBIT(ACC_0,    0xE0, 0); /* Accumulator bit 0 */
SFR(IRCON2,    0xE8); /* Interrupt flags 5 */
  SBIT(WDTIF,    0xE8, 4); /* Watchdog Timer interrupt flag */
  SBIT(P1IF,     0xE8, 3); /* Port 1 Interrupt flag */
  SBIT(UTX1IF,   0xE8, 2); /* USART1 TX interrupt flag */
  SBIT(UTX0IF,   0xE8, 1); /* USART0 TX interrupt flag */
  SBIT(P2IF,     0xE8, 0); /* Port 2 interrupt flag */
SFR(B,         0xF0); /* B Register */
  SBIT(B_7,      0xF0, 7); /* Register B bit 7 */
  SBIT(B_6,      0xF0, 6); /* Register B bit 6 */
  SBIT(B_5,      0xF0, 5); /* Register B bit 5 */
  SBIT(B_4,      0xF0, 4); /* Register B bit 4 */
  SBIT(B_3,      0xF0, 3); /* Register B bit 3 */
  SBIT(B_2,      0xF0, 2); /* Register B bit 2 */
  SBIT(B_1,      0xF0, 1); /* Register B bit 1 */
  SBIT(B_0,      0xF0, 0); /* Register B bit 0 */

/* ADC */
SFR(ADCCON1,   0xB4); /* ADC control 1 */
SFR(ADCCON2,   0xB5); /* ADC control 2 */
SFR(ADCCON3,   0xB6); /* ADC control 3 */
SFR(ADCL,      0xBA); /* ADC data low */
SFR(ADCH,      0xBB); /* ADC data high */
SFR(RNDL,      0xBC); /* Random number generator data low */
SFR(RNDH,      0xBD); /* Random number generator data high */

/* AES Coprocessor */
SFR(ENCDI,     0xB1); /* Encryption/decryption input data */
SFR(ENCDO,     0xB2); /* Encryption/decryption output data */
SFR(ENCCS,     0xB3); /* Encryption/decryption control and status */

/* DMA Controller */
SFR(DMAIRQ,    0xD1); /* DMA interrupt flag */
SFR(DMA1CFGL,  0xD2); /* DMA channel 1–4 configuration address low */
SFR(DMA1CFGH,  0xD3); /* DMA channel 1–4 configuration address high */
SFR(DMA0CFGL,  0xD4); /* DMA channel 0 configuration address low */
SFR(DMA0CFGH,  0xD5); /* DMA channel 0 configuration address high */
SFR(DMAARM,    0xD6); /* DMA channel armed */
SFR(DMAREQ,    0xD7); /* DMA channel start request and status */

/* I/O */
SFR(P0IFG,     0x89); /* Port 0 interrupt status flag */
SFR(P1IFG,     0x8A); /* Port 1 interrupt status flag */
SFR(P2IFG,     0x8B); /* Port 2 interrupt status flag */
SFR(PICTL,     0x8C); /* Port pins interrupt mask and edge */
SFR(P0IEN,     0xAB); /* Port 0 interrupt mask */
SFR(P1IEN,     0x8D); /* Port 1 interrupt mask */
SFR(P2IEN,     0xAC); /* Port 2 interrupt mask */
SFR(P0INP,     0x8F); /* Port 0 input Mode */
SFR(PERCFG,    0xF1); /* Peripheral I/O control */
SFR(APCFG,     0xF2); /* Analog peripheral I/O configuration */
SFR(P0SEL,     0xF3); /* Port 0 function select */
SFR(P1SEL,     0xF4); /* Port 1 function select */
SFR(P2SEL,     0xF5); /* Port 2 function select */
SFR(P1INP,     0xF6); /* Port 1 input mode */
SFR(P2INP,     0xF7); /* Port 2 input mode */
SFR(P0DIR,     0xFD); /* Port 0 direction */
SFR(P1DIR,     0xFE); /* Port 1 direction */
SFR(P2DIR,     0xFF); /* Port 2 direction */
SFR(PMUX,      0xAE); /* Power-down signal mux */

/* Memory */
SFR(MPAGE,     0x93); /* Memory page select */
SFR(_XPAGE,    0x93); /* Memory page select - SDCC name */
SFR(MEMCTR,    0xC7); /* Memory system control */
SFR(FMAP,      0x9F); /* Flash-memory bank mapping */
SFR(PSBANK,    0x9F); /* Flash-memory bank mapping - SDCC name */

/* Sleep Timer */
SFR(ST0,       0x95); /* Sleep Timer 0 */
SFR(ST1,       0x96); /* Sleep Timer 1 */
SFR(ST2,       0x97); /* Sleep Timer 2 */
SFR(STLOAD,    0xAD); /* Sleep-timer load status */
SFR(SLEEPCMD,  0xBE); /* Sleep-mode control command */
SFR(SLEEPSTA,  0x9D); /* Sleep-mode control status */

/* Power Management and Clocks */
SFR(CLKCONCMD, 0xC6); /* Clock control command */
#define CLKCONCMD_OSC            BIT(6)
#define CLKCONCMD_TICKSPD_500    (BIT(5) | BIT(4))
SFR(CLKCONSTA, 0x9E); /* Clock control status */

/* Timer 1 */
SFR(T1CC0L,    0xDA); /* Timer 1 channel 0 capture/compare value low */
SFR(T1CC0H,    0xDB); /* Timer 1 channel 0 capture/compare value high */
SFR(T1CC1L,    0xDC); /* Timer 1 channel 1 capture/compare value low */
SFR(T1CC1H,    0xDD); /* Timer 1 channel 1 capture/compare value high */
SFR(T1CC2L,    0xDE); /* Timer 1 channel 2 capture/compare value low */
SFR(T1CC2H,    0xDF); /* Timer 1 channel 2 capture/compare value high */
SFR(T1CNTL,    0xE2); /* Timer 1 counter low */
SFR(T1CNTH,    0xE3); /* Timer 1 counter high */
SFR(T1CTL,     0xE4); /* Timer 1 control and status */
SFR(T1CCTL0,   0xE5); /* Timer 1 channel 0 capture/compare control */
SFR(T1CCTL1,   0xE6); /* Timer 1 channel 1 capture/compare control */
SFR(T1CCTL2,   0xE7); /* Timer 1 channel 2 capture/compare control */
SFR(T1STAT,    0xAF); /* Timer 1 status */

/* Timer 2 (MAC Timer) */
SFR(T2CTRL,    0x94); /* Timer 2 control */
SFR(T2EVTCFG,  0x9C); /* Timer 2 event configuration */
SFR(T2IRQF,    0xA1); /* Timer 2 interrupt flags */
SFR(T2M0,      0xA2); /* Timer 2 multiplexed register 0 */
SFR(T2M1,      0xA3); /* Timer 2 multiplexed register 1 */
SFR(T2MOVF0,   0xA4); /* Timer 2 multiplexed overflow register 0 */
SFR(T2MOVF1,   0xA5); /* Timer 2 multiplexed overflow register 1 */
SFR(T2MOVF2,   0xA6); /* Timer 2 multiplexed overflow register 2 */
SFR(T2IRQM,    0xA7); /* Timer 2 interrupt mask */
SFR(T2MSEL,    0xC3); /* Timer 2 multiplex select */

/* Timer 3 */
SFR(T3CNT,     0xCA); /* Timer 3 counter */
SFR(T3CTL,     0xCB); /* Timer 3 control */
SFR(T3CCTL0,   0xCC); /* Timer 3 channel 0 compare control */
SFR(T3CC0,     0xCD); /* Timer 3 channel 0 compare value */
SFR(T3CCTL1,   0xCE); /* Timer 3 channel 1 compare control */
SFR(T3CC1,     0xCF); /* Timer 3 channel 1 compare value */

/* Timer 4 */
SFR(T4CNT,     0xEA); /* Timer 4 counter */
SFR(T4CTL,     0xEB); /* Timer 4 control */
SFR(T4CCTL0,   0xEC); /* Timer 4 channel 0 compare control */
SFR(T4CC0,     0xED); /* Timer 4 channel 0 compare value */
SFR(T4CCTL1,   0xEE); /* Timer 4 channel 1 compare control */
SFR(T4CC1,     0xEF); /* Timer 4 channel 1 compare value */

/* Timer 1, 3, 4 join Interrupts */
SFR(TIMIF,     0xD8); /* Timers 1/3/4 joint interrupt mask/flags */
  SBIT(OVFIM,    0xD8, 6); /* Timer 1 overflow interrupt mask */
  SBIT(T4CH1IF,  0xD8, 5); /* Timer 4 channel 1 interrupt flag */
  SBIT(T4CH0IF,  0xD8, 4); /* Timer 4 channel 0 interrupt flag */
  SBIT(T4OVFIF,  0xD8, 3); /* Timer 4 overflow interrupt flag */
  SBIT(T3CH1IF,  0xD8, 2); /* Timer 3 channel 1 interrupt flag */
  SBIT(T3CH0IF,  0xD8, 1); /* Timer 3 channel 0 interrupt flag */
  SBIT(T3OVFIF,  0xD8, 0); /* Timer 3 overflow interrupt flag */

/* USART 0 */
SFR(U0CSR,     0x86); /* USART 0 control and status */
SFR(U0DBUF,    0xC1); /* USART 0 receive/transmit data buffer */
SFR(U0BAUD,    0xC2); /* USART 0 baud-rate control */
SFR(U0UCR,     0xC4); /* USART 0 UART control */
SFR(U0GCR,     0xC5); /* USART 0 generic control */

/* USART 1 */
SFR(U1CSR,     0xF8); /* USART 1 control and status */
  SBIT(MODE,     0xF8, 7); /* USART mode select */
  SBIT(RE,       0xF8, 6); /* UART receiver enable */
  SBIT(SLAVE,    0xF8, 5); /* SPI master- or slave mode select */
  SBIT(FE,       0xF8, 4); /* UART framing error status */
  SBIT(ERR,      0xF8, 3); /* UART parity error status */
  SBIT(RX_BYTE,  0xF8, 2); /* Receive byte status */
  SBIT(TX_BYTE,  0xF8, 1); /* Transmit byte status */
  SBIT(ACTIVE,   0xF8, 0); /* USART transmit/receive active status */
SFR(U1DBUF,    0xF9); /* USART 1 receive/transmit data buffer */
SFR(U1BAUD,    0xFA); /* USART 1 baud-rate control */
SFR(U1UCR,     0xFB); /* USART 1 UART control */
SFR(U1GCR,     0xFC); /* USART 1 Generic control */

/* Watchdog Timer */
SFR(WDCTL,     0xC9); /* Watchdog Timer Control */

/* Bluetooth Low Energy Radio Registers */
SFRX(RFSTAT,              0x618D); /* RF core status */
SFRX(RFC_OBS_CTRL0,       0x61AE); /* RF Observation Mux Control 0 */
SFRX(RFC_OBS_CTRL1,       0x61AF); /* RF Observation Mux Control 1 */
SFRX(RFC_OBS_CTRL2,       0x61B0); /* RF Observation Mux Control 2 */
SFRX(ATEST,               0x61A9); /* Analog Test Control */

#endif /* __CC2540_H__ */
