/*
 * led_display.h
 *
 *  Created on: Oct 8, 2023
 *      Author: HaHuyen
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

extern int index_led;
extern int led_buffer[4];
extern const int MAX_LED;

void display7SEG(int num);
void update7SEG(int index);

void update4Leg(int a, int b);

#endif /* INC_LED_DISPLAY_H_ */
