/*
 * led_display.c
 *
 *  Created on: Oct 8, 2023
 *      Author: HaHuyen
 */
#include "led_display.h"
uint8_t led_flag = 0;
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

void display7SEG(int num);
void update7SEG(int index);
void update4Leg(int a, int b);

void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_6_Pin,GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, SEG_1_Pin|SEG_2_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_2_Pin|SEG_5_Pin,GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_4_Pin|SEG_5_Pin,GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, SEG_1_Pin|SEG_2_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_3_Pin|SEG_4_Pin,GPIO_PIN_SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_2_Pin|SEG_3_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_1_Pin|SEG_4_Pin,GPIO_PIN_SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_1_Pin,GPIO_PIN_SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_5_Pin|SEG_6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, SEG_4_Pin,GPIO_PIN_SET);
		break;
	}
}

void update7SEG(int index){
    switch (index){
        case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(led_buffer[0]);
            break;
        case 1:
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(led_buffer[1]);
            break;
        case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(led_buffer[2]);
            break;
        case 3:
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			display7SEG(led_buffer[3]);
            break;
        default:
            break;
    }
}

void update4Leg(int a, int b){
	led_buffer[0] = a/10;
	led_buffer[1] = a%10;
	led_buffer[2] = b/10;
	led_buffer[3] = b%10;
}
