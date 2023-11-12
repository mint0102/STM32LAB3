/*
 * nomal_traffic_light.h
 *
 *  Created on: Oct 10, 2023
 *      Author: HaHuyen
 */

#ifndef INC_NOMAL_TRAFFIC_LIGHT_H_
#define INC_NOMAL_TRAFFIC_LIGHT_H_

#include "main.h"

#define 	INIT			100
//#define		PHASE_2_GREEN 	101 //Phase 1 red
//#define		PHASE_2_YELLOW 	102 //Phase 1 red
//#define  	PHASE_1_GREEN 	103 //Phase 2 red
//#define 	PHASE_1_YELLOW	104 //Phase 2 red

extern int count_red;
extern int count_yellow;
extern int count_green;
extern num1, num2;
extern char status;

void Phase1_GreenOn();
void Phase1_GreenOff();

void Phase1_YellowOn();
void Phase1_YellowOff();

void Phase1_RedOn();
void Phase1_RedOff();

void Phase2_GreenOn();
void Phase2_GreenOff();

void Phase2_YellowOn();
void Phase2_YellowOff();

void Phase2_RedOn();
void Phase2_RedOff();

void Led_Off();
void normal_trafic();

#endif /* INC_NOMAL_TRAFFIC_LIGHT_H_ */
