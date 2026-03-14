/*
 * io.c
 *
 *  Created on: Mar 3, 2026
 *      Author: Dell
 */

#include "main.h"

void vacuum1(uint16_t state) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, state);
}
void vacuum2(uint16_t state) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, state);
}
void vacuum3(uint16_t state) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, state);
}

void vacuum4(uint16_t state) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, state);
}

uint16_t sensor_1() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)
			|| HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
}
uint16_t sensor_2() {
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15)
			|| HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14);
}
uint16_t front() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
}
uint16_t back() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
}

uint16_t chich() {
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
}
uint16_t switch_for_side() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
}
uint16_t switch_4() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
}
uint16_t switch_2() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
}
uint16_t switch_1() {
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
}

void F_valve1(uint16_t state) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, state);
}
void F_valve2(uint16_t state) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, state);
}
void F_valve3(uint16_t state) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, state);
}
void F_valve4(uint16_t state) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, state);
}

void B_valve1(uint16_t state2) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, state2);
}

void B_valve2(uint16_t state2) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, state2);
}
void B_valve3(uint16_t state2) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, state2);
}
void B_valve4(uint16_t state2) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, state2);
}

