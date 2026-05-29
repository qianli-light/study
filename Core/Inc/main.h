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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_SIMPLE_Pin GPIO_PIN_0
#define LED_SIMPLE_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_2
#define KEY_GPIO_Port GPIOA
#define KEY_EXTI_IRQn EXTI2_IRQn
#define LED_KEY_Pin GPIO_PIN_6
#define LED_KEY_GPIO_Port GPIOA
#define EC11A_Pin GPIO_PIN_0
#define EC11A_GPIO_Port GPIOB
#define EC11A_EXTI_IRQn EXTI0_IRQn
#define EC11B_Pin GPIO_PIN_1
#define EC11B_GPIO_Port GPIOB
#define EC11B_EXTI_IRQn EXTI1_IRQn
#define OLED_SCL_Pin GPIO_PIN_8
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_9
#define OLED_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
extern uint8_t ReceiveData[2];
extern int EC_count;
extern float voltage[3];
  extern uint16_t ADC_value[3];
  extern float average;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
