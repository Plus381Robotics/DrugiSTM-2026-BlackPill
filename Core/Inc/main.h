/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <stdio.h>
#include "ssd1306.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void time_ISR();
uint32_t get_time();
void time_start();
void time_stop();
void getRGB(int *R, int *G, int *B);
void tcs3272_init(void);
void enable(void);
void disable(void);
void vacuum1(uint16_t);
void vacuum2(uint16_t);
void vacuum3(uint16_t);
void vacuum4(uint16_t);
uint16_t sensor_1(void);
uint16_t chich();
uint16_t switch_for_side();
uint16_t switch_4();
uint16_t switch_2();
uint16_t switch_1();
void F_valve1(uint16_t state);
void F_valve2(uint16_t state);
void F_valve3(uint16_t state);
void F_valve4(uint16_t state);

void B_valve1(uint16_t state2);
void B_valve2(uint16_t state2);
void B_valve3(uint16_t state2);
void B_valve4(uint16_t state2);


void process_rx_buffer();
void update_tx_buffer();
void comm_init();

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
