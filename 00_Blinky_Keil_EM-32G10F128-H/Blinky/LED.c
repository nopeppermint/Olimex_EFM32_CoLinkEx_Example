/*----------------------------------------------------------------------------
 * Name:    LED.c
 * Purpose: low level LED functions
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

#include "em_cmu.h"
#include "em_gpio.h"
#include "LED.h"


/*----------------------------------------------------------------------------
  initialize LED Pins
 *----------------------------------------------------------------------------*/
void LED_Init (void) 
{

  /* Enable clock and init GPIO outputs */
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(gpioPortA, 0, gpioModePushPull, 1);

  LED_Off();                                         /* switch LED Off */
}

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void LED_On (void) 
{
    GPIO_PinOutSet(gpioPortA, 0);
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void LED_Off (void) 
{
    GPIO_PinOutClear(gpioPortA, 0);
}

