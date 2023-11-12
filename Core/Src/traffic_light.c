/*
 * traffic_light.c
 *
 *  Created on: Oct 9, 2023
 *      Author: HaHuyen
 */

#include "traffic_light.h"

#define NORMAL		1
#define RED			2
#define GREEN		4
#define YELLOW		3

int status_fsm = NORMAL;
int temp = 0;

void traffic_light(){
	switch (status_fsm){
		case NORMAL:
			if(blink_flag){
				setTimer_blink();
				normal_trafic();
			}
			if(isButtonMode()){
				status_fsm = RED;
				status = INIT;
				temp = count_red;
				Led_Off();
				HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
				HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);
			}
			update4Leg(num1, num2);
			break;
		case RED:
//			count_led--;
			if(blink_flag){
				setTimer_blink();
				HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
				HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
//				count_led = 10;
			}
			if(isButtonMode()){
				status_fsm = YELLOW;
				temp = count_yellow;
				Led_Off();
				HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);
				HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 1);
			}
			if(isButtonTime()){
				temp++;
			}
			if(isButtonEnter()){
				count_red = temp;
				if(count_red < count_green)
					count_yellow = count_green - count_red;
				else{
					count_green = count_red - count_yellow;
				}
			}
			update4Leg(status_fsm, temp);
			break;
		case YELLOW:
//			count_led--;
			if(blink_flag){
				setTimer_blink();
				HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
				HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
//				count_led = 10;
			}
			if(isButtonMode()){
				status_fsm = GREEN;
				temp = count_green;
				Led_Off();
				HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);
				HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 1);
			}
			if(isButtonTime()){
				temp++;
			}
			if(isButtonEnter()){
				count_yellow = temp;
				if(count_red < count_green)
					count_red = count_green - count_yellow;
				else{
					count_green = count_red - count_yellow;
				}
			}
			update4Leg(status_fsm, temp);
			break;
		case GREEN:
//			count_led--;
			if(blink_flag){
				setTimer_blink();
				HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
				HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
//				count_led = 10;
			}
			if(isButtonMode()){
				status_fsm = NORMAL;
				temp = count_red;
				Led_Off();
			}
			if(isButtonTime()){
				temp++;
			}
			if(isButtonEnter()){
				count_green = temp;
				if(count_red < count_green)
					count_red = count_green - count_yellow;
				else{
					count_yellow = count_red - count_green;
				}
			}
			update4Leg(status_fsm, temp);
			break;
		default:
			status_fsm = NORMAL;
			break;
	}
}
