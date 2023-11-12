/*
 * software_timer.c
 *
 *  Created on: Sep 21, 2023
 *      Author: HaHuyen
 */
#include "software_timer.h"
int timer_counter = 0;
int timer_flag = 0;
int timer_blink = 0;
int blink_flag = 0;

void setTimer(int duration){
	timer_counter = duration;
	timer_flag = 0;
}

void timerRun(){
	if(timer_counter > 0){
		timer_counter--;
		if(timer_counter <= 0){
			timer_flag = 1;
		}
	}
}

void setTimer_blink(){ //1s
	timer_blink = 100;
	blink_flag = 0;
}

void timerRun_blink(){
	if(timer_blink > 0){
		timer_blink--;
		if(timer_blink <= 0){
			blink_flag = 1;
		}
	}
}
