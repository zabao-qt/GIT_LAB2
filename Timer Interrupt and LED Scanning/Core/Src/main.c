/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int timer0_counter = 0;
int timer0_flag = 0;
int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int timer3_counter = 0;
int timer3_flag = 0;
int TIMER_CYCLE = 10; // 10ms
void setTimer0(int duration) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration) {
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int duration) {
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer3(int duration) {
	timer3_counter = duration / TIMER_CYCLE;
	timer3_flag = 0;
}
void timer_run() {
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter == 0) timer0_flag = 1;
	}
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter == 0) timer1_flag = 1;
	}
	if (timer2_counter > 0) {
		timer2_counter--;
		if (timer2_counter == 0) timer2_flag = 1;
	}
	if (timer3_counter > 0) {
		timer3_counter--;
		if (timer3_counter == 0) timer3_flag = 1;
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void display7SEG (int num){
		switch (num){
		case 0:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		}
}

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index) {
	switch (index) {
		case 0:
			// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break ;
		case 1:
			// Display the second 7 SEG with led_buffer [1]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break ;
		case 2:
			// Display the third 7 SEG with led_buffer [2]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break ;
		case 3:
			// Display the forth 7 SEG with led_buffer [3]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			break ;
		default :
			break ;
	}
	display7SEG(led_buffer[index]);
}

void updateClockBuffer(int hour, int minute) {
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {b11100111, b11000011, b10011001, b10011001, b10000001, b10000001, b10011001, b10011001}; //A, binary to see it easier

void displayARow(int num) {
	uint8_t matrix = matrix_buffer [ num ];
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, (matrix >> 0) & x01 ? 1 : 0);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, (matrix >> 1) & x01 ? 1 : 0);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, (matrix >> 2) & x01 ? 1 : 0);
	HAL_GPIO_WritePin (ENM3_GPIO_Port, ENM3_Pin , (matrix >> 3) & x01 ? 1 : 0);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, (matrix >> 4) & x01 ? 1 : 0) ;
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, (matrix >> 5) & x01 ? 1 : 0) ;
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, (matrix >> 6) & x01 ? 1 : 0) ;
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, (matrix >> 7) & x01 ? 1 : 0);
}

void updateLEDMatrix ( int index ) {
	switch(index) {
		case 0:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 0);
			displayARow(index);
			break;
		case 1:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW1_Pin, 0);
			displayARow(index);
			break;
		case 2:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW2_Pin, 0);
			displayARow(index);
			break;
		case 3:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW3_Pin, 0);
			displayARow(index);
			break;
		case 4:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW4_Pin, 0);
			displayARow(index);
			break;
		case 5:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW5_Pin, 0);
			displayARow(index);
			break;
		case 6:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW6_Pin, 0);
			displayARow(index);
			break;
		case 7:
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW7_Pin, 0) ;
			displayARow(index) ;
			break;
		default:
			break;
		}
}


void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim)
{
	timer_run();
}


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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  // Init clock 15:08
  int hour = 15 , minute = 8 , second = 50;
  updateClockBuffer(hour, minute);
  // Start timers
  setTimer0(10);
  setTimer1(10);
  setTimer2(10);
  setTimer3(100);
  int LEDcounter = 0; // To check if 4 LEDs are scanned in 1s
  while (1)
  {
	  // LED-RED blinks every 2s
	  if(timer0_flag == 1) {
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		  setTimer0(2000);
	  }
	  // DOT LEDs blink every 1s
	  if(timer1_flag == 1) {
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  setTimer1(1000);
	  }
	  // Update 7SEG LEDs every 250ms
	  if(timer2_flag == 1) {
		  setTimer2(250);
		  update7SEG(index_led++);
		  LEDcounter++;
		  if(LEDcounter == 4) {
			  second++;
			  if(second >= 60) {
				  second = 0;
				  minute++;
			  }
			  if(minute >= 60) {
				  minute = 0;
				  hour++;
			  }
			  if(hour >= 24) {
				  hour = 0;
			  }
			  updateClockBuffer(hour, minute);
			  index_led = 0;
			  LEDcounter = 0;
		  }
	  }
	  if(timer3_flag == 1) {
		  setTimer3(180);
		  updateLEDMatrix(index_led_matrix++);
		  if(index_led_matrix == MAX_LED_MATRIX) {
			  index_led_matrix = 0;
		  }
	  }
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                          |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin LED_RED_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin SEG3_Pin
                           SEG4_Pin SEG5_Pin SEG6_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                          |SEG4_Pin|SEG5_Pin|SEG6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
