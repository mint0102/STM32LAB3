/*
 * nomal_traffic_light.c
 *
 *  Created on: Oct 9, 2023
 *      Author: HaHuyen
 */

#include "nomal_traffic_light.h"

#define 	INIT			100
#define		PHASE_2_GREEN 	101 //Phase 1 red
#define		PHASE_2_YELLOW 	102 //Phase 1 red
#define  	PHASE_1_GREEN 	103 //Phase 2 red
#define 	PHASE_1_YELLOW	104 //Phase 2 red

char status = INIT;
int count_red = 5;
int count_yellow = 2;
int count_green = 3;
int counter_normal = 0;
int num1 = 0, num2 = 0;

void Phase1_GreenOn(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
}
void Phase1_GreenOff(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
}

void Phase1_YellowOn(){
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_RESET);
}
void Phase1_YellowOff(){
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
}

void Phase1_RedOn(){
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
}
void Phase1_RedOff(){
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
}

void Phase2_GreenOn(){
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET);
}
void Phase2_GreenOff(){
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
}

void Phase2_YellowOn(){
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_RESET);
}
void Phase2_YellowOff(){
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
}

void Phase2_RedOn(){
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
}
void Phase2_RedOff(){
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
}
void Led_Off(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
}
void normal_trafic(){
	switch (status){
	case INIT:
		counter_normal = count_green;
		num1 = count_red;
		num2 = count_green;
		status = PHASE_2_GREEN;
		Phase2_RedOff();
		Phase2_YellowOff();
		Phase1_GreenOff();
		Phase1_YellowOff();
		break;
	case PHASE_2_GREEN:
		counter_normal--;
		Phase2_GreenOn();
		Phase1_RedOn();
		Phase2_RedOff();
		Phase1_YellowOff();
		if (counter_normal <= 0){
			counter_normal = count_yellow;
			num1--;
			num2 = count_yellow;
			status = PHASE_2_YELLOW;
			Phase2_GreenOff();
			Phase2_YellowOn();
			Phase1_RedOn();
		}
		else{
			num1--;
			num2--;
		}
		break;
	case PHASE_2_YELLOW:
		counter_normal--;
		Phase2_GreenOff();
		Phase2_YellowOn();
		Phase1_RedOn();
		if (counter_normal <= 0) {
			counter_normal = count_green;
			status = PHASE_1_GREEN;
			num1 = count_green;
			num2 = count_red;
			Phase1_GreenOn();
			Phase1_RedOff();
			Phase2_YellowOff();
			Phase2_RedOn();
		}
		else{
			num1--;
			num2--;
		}
	break;
	case PHASE_1_GREEN:
		counter_normal--;
		Phase1_GreenOn();
		Phase1_RedOff();
		Phase2_YellowOff();
		Phase2_RedOn();
		if (counter_normal <= 0) {
			counter_normal = count_yellow;
			status = PHASE_1_YELLOW;
			num1 = count_yellow;
			num2--;
			Phase1_GreenOff();
			Phase1_YellowOn();
			Phase2_RedOn();
		}
		else{
			num1--;
			num2--;
		}
	break;
	case PHASE_1_YELLOW:
		counter_normal--;
		Phase1_GreenOff();
		Phase1_YellowOn();
		Phase2_RedOn();
		if (counter_normal <= 0) {
			counter_normal = count_green;
			status = PHASE_2_GREEN;
			num1 = count_red;
			num2 = count_green;
			Phase2_GreenOn();
			Phase1_RedOn();
			Phase2_RedOff();
			Phase1_YellowOff();
		}
		else{
			num1--;
			num2--;
		}
	break;
	default:
		status = INIT;
		break;
	}
}
