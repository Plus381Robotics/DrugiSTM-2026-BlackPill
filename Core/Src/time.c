/*
 * time.c
 *
 *  Created on: Dec 28, 2025
 *      Author: Dell
 */

#include "main.h"

extern TIM_HandleTypeDef htim9;
uint32_t sys_time_ms = 0;

void time_ISR() {
	sys_time_ms += 1;
	update_tx_buffer();
	process_rx_buffer();
}

uint32_t get_time() {
	return sys_time_ms;
}

void time_start() {
	HAL_TIM_Base_Start_IT(&htim9);
}

void time_stop() {
	HAL_TIM_Base_Stop_IT(&htim9);
}
