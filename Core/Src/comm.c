/*
 * comm.c
 *
 *  Created on: Dec 9, 2025
 *      Author: lazar
 */
#define TXBUFFERSIZE 1
#define RXBUFFERSIZE 1

#include "main.h"
extern UART_HandleTypeDef huart6;
volatile uint8_t tx_buffer[TXBUFFERSIZE], rx_buffer[RXBUFFERSIZE];
//volatile uint8_t tdbg = 0, rdbg;
volatile uint8_t chinch_waiting;
uint8_t t_dbg = 0b11111111;

void update_tx_buffer() {
	// TODO: ovde za slanje na Rpi
//	tx_buffer[0] = t_dbg;
	tx_buffer[0] = 0;
	tx_buffer[0] |= (!chich() << 0);
	tx_buffer[0] |= (switch_1() << 1);
	tx_buffer[0] |= (switch_2() << 2);
	tx_buffer[0] |= (switch_4() << 3);
	tx_buffer[0] |= (switch_for_side() << 4);
	tx_buffer[0] |= 0b11100000;

	huart6.gState = HAL_UART_STATE_READY;
	__HAL_UART_CLEAR_FLAG(&huart6, UART_FLAG_TC);
	HAL_UART_Transmit_DMA(&huart6, (uint8_t*) tx_buffer, TXBUFFERSIZE);
}

//static void rx_process_byte(uint8_t b)
//{
//    sync = (sync << 8) | b;
//
//    if (idx == 0)
//    {
//        if (sync == 0xFFFF)
//            idx = 1;
//        return;
//    }
//
//    rxb_aligned[idx - 1] = b;
//    idx++;
//
//    if (idx == 7)
//    {
//        idx = 0;
//    }
//}

//uint8_t v1dbg, v3dbg, v2dbg, v4dbg, v0dbg;
volatile uint8_t vacuum;
void process_rx_buffer() {
//	rdbg = rx_buffer[0];
	chinch_waiting = (rx_buffer[0] >> 0) & 0b1;
	vacuum = rx_buffer[0];
//	vacuum1((rx_buffer[0] >> 1) & 0b1);
//	vacuum2((rx_buffer[0] >> 2) & 0b1);
//	vacuum3((rx_buffer[0] >> 3) & 0b1);
//	vacuum4((rx_buffer[0] >> 4) & 0b1);
//
//	v1dbg = (rx_buffer[0] >> 1) & 0b1;
//	v2dbg = (rx_buffer[0] >> 2) & 0b1;
//	v3dbg = (rx_buffer[0] >> 3) & 0b1;
//	v4dbg = (rx_buffer[0] >> 4) & 0b1;
//	v0dbg = (rx_buffer[0] >> 0) & 0b1;
}

void set_vacuum() {
	vacuum1((vacuum >> 1) & 0b1);
	HAL_Delay(50);
	vacuum2((vacuum >> 2) & 0b1);
	HAL_Delay(50);
	vacuum3((vacuum >> 3) & 0b1);
	HAL_Delay(50);
	vacuum4((vacuum >> 4) & 0b1);
	HAL_Delay(50);

}

void comm_init() {

	if (HAL_UART_Receive_DMA(&huart6, (uint8_t*) rx_buffer, RXBUFFERSIZE)
			!= HAL_OK) {
		Error_Handler();
	}
//  if(HAL_UART_Transmit_DMA(&huart6, (uint8_t*)tx_buffer, TXBUFFERSIZE)!= HAL_OK)
//  {
//    Error_Handler();
//  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//    HAL_UART_Receive_DMA(&huart6, (uint8_t *)rx_buffer, RXBUFFERSIZE);
	process_rx_buffer();
}
