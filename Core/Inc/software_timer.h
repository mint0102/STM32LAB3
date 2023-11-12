/*
 * software_timer.h
 *
 *  Created on: Sep 21, 2023
 *      Author: HaHuyen
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag;
extern int blink_flag;

void setTimer(int duration);
void timerRun();
void setTimer_blink();
void timerRun_blink();
#endif /* INC_SOFTWARE_TIMER_H_ */
