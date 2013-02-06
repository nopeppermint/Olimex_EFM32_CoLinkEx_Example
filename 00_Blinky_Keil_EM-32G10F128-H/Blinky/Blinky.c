/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *
 * Edited by S.Weber, Twitter: @nopeppermint, Switzerland, 
 * to use with Olimex EFM32G210F128H Board and Olimex ARM-JTAG-COOCOX (CoLinkEx),
 * made with Keil MDK-ARM-Lite v.4.60
 *
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <EFM32.H>
#include "em_chip.h"
#include "em_cmu.h"
#include "LED.h"

volatile uint32_t msTicks;                      /* counts 1ms timeTicks       */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;
}

/*----------------------------------------------------------------------------
  delays number of tick Systicks (happens every 1 ms)
 *----------------------------------------------------------------------------*/
void Delay (uint32_t dlyTicks) {
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) { __NOP(); }
}

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void) 
{
  CHIP_Init();

  LED_Init();

  SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) 	/* SysTick 1 ms interrupts    */
	{ 
    while (1) __NOP();                          /* Capture error              */
  }

  while(1) 																			/* Loop forever               */
	{                                    
    LED_On ();                               		/* Turn on LED 'idx'          */
    Delay(150);                                 /* Delay 150ms                */
    LED_Off();                              	 	/* Turn off LED 'idx'         */
    Delay(150);                                 /* Delay 150ms                */
  }
}
