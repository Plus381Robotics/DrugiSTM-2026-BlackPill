/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "bitmap.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

int red, green, blue;
volatile int x = -1225, y = 4;
volatile float phi = -135.2;

uint8_t v1, v2, v3, v4;
uint8_t v1a = 0, v2a = 0, v3a = 0, v4a = 0;
uint8_t sisaljka_f1a = 0, sisaljka_f2a = 0, sisaljka_f3a = 0, sisaljka_f4a = 0;
uint8_t sisaljka_b1a = 0, sisaljka_b2a = 0, sisaljka_b3a = 0, sisaljka_b4a = 0;
uint8_t sisaljka_f1, sisaljka_f2, sisaljka_f3, sisaljka_f4;
uint8_t sisaljka_b1, sisaljka_b2, sisaljka_b3, sisaljka_b4;

uint8_t in;
char prviBroj, drugiBroj, treciBroj, cetvrtiBroj;
char petiBroj, sestiBroj, sedmiBroj, osmiBroj;

char cinc;
uint8_t chinchh = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_TIM9_Init();
  MX_USART1_UART_Init();
  MX_USART6_UART_Init();
  /* USER CODE BEGIN 2 */
	comm_init();
	tcs3272_init();
	enable();
	time_start();
	SSD1306_Init();
	SSD1306_DrawBitmap(64, 0, logo, 64, 64, 1);
	SSD1306_DrawBitmap(0, 0, outline, 64, 63, 1);
	SSD1306_UpdateScreen();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		vacuum1(v1);
		vacuum2(v2);
		vacuum3(v3);
		vacuum4(v4);

//		v1a = v1 + 48;
//		v2a = v2 + 48;
//		v3a = v3 + 48;
//		v4a = v4 + 48;

		F_valve1(sisaljka_f1);
		F_valve2(sisaljka_f2);
		F_valve3(sisaljka_f3);
		F_valve4(sisaljka_f4);

//		B_valve1(sisaljka_b1);
//		B_valve2(sisaljka_b2);
//		B_valve3(sisaljka_b3);
//		B_valve4(sisaljka_b4);
//
//		sisaljka_f1a = sisaljka_f1 + 48;
//		sisaljka_f2a = sisaljka_f2 + 48;
//		sisaljka_f3a = sisaljka_f3 + 48;
//		sisaljka_f4a = sisaljka_f4 + 48;
//
//		sisaljka_b1a = sisaljka_b1 + 48;
//		sisaljka_b2a = sisaljka_b2 + 48;
//		sisaljka_b3a = sisaljka_b3 + 48;
//		sisaljka_b4a = sisaljka_b4 + 48;
//
//		chich(cinc);
//		chinchh = cinc + 48;
//
//		char jedan[1];
//		*jedan = 49;
//		char dva[1];
//		char nula[1];
//		char c[1];
//		*c = 'C';
//		char y[1];
//		*y = 'Y';
//		char cetiri[1];
//		//		sprintf(jedan, "%d", 1);
//		//		sprintf(dva, "%d", 2);
//		//		sprintf(nula, "%d", 0);
//		//		sprintf(cetiri, "%d", 4);
//		//
//
//		SSD1306_GotoXY(8, 2);
//		SSD1306_Puts(&prviBroj, &Font_11x18, 1);
//		SSD1306_GotoXY(20, 2);
//		SSD1306_Puts(&drugiBroj, &Font_11x18, 1);
//		SSD1306_GotoXY(32, 2);
//		SSD1306_Puts(&treciBroj, &Font_11x18, 1);
//		SSD1306_GotoXY(44, 2);
//		SSD1306_Puts(&cetvrtiBroj, &Font_11x18, 1);
//
//		SSD1306_GotoXY(2, 21);
//		SSD1306_Puts(c, &Font_11x18, 1);
//		SSD1306_GotoXY(13, 21);
//		SSD1306_Puts(y, &Font_11x18, 1);
//		SSD1306_GotoXY(26, 21);
//		SSD1306_Puts(cetiri, &Font_11x18, 1);
//		SSD1306_GotoXY(38, 21);
//		SSD1306_Puts(dva, &Font_11x18, 1);
//		SSD1306_GotoXY(50, 21);
//		SSD1306_Puts(jedan, &Font_11x18, 1);
//
//		SSD1306_GotoXY(8, 42);
//		SSD1306_Puts(&petiBroj, &Font_11x18, 1);
//		SSD1306_GotoXY(20, 42);
//		SSD1306_Puts(&sestiBroj, &Font_11x18, 1);
//		SSD1306_GotoXY(32, 42);
//		SSD1306_Puts(&sedmiBroj, &Font_11x18, 1);
//		SSD1306_GotoXY(44, 42);
//		SSD1306_Puts(&osmiBroj, &Font_11x18, 1);
//
//		SSD1306_UpdateScreen();
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
