/*----------------------------------------------------------------------------
 * Name:    LED.h
 * Purpose: low level LED definitions
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
 * Edit vor Olimex EFM32G210F128H Board by S.Weber, Switzerland
 *----------------------------------------------------------------------------*/

#ifndef LED_H
#define LED_H

/* LED Definitions */

extern void LED_Init(void);
extern void LED_On  (void);
extern void LED_Off (void);

#endif
