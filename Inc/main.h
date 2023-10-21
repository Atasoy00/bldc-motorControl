/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32g4xx_hal.h"

#include "motorcontrol.h"

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
#define DEAD_TIME 30
#define SYSCLOCK_FREQUENCY 85000000
#define HF_TIMX_PSC 0
#define GATE_DRIVING_PWM_FREQUENCY 50000
#define HF_TIMX_ARR (SYSCLOCK_FREQUENCY/(GATE_DRIVING_PWM_FREQUENCY*(HF_TIMX_PSC+1))-1)
#define BSP_HF_TIMx_COUNTER_MODE 0
#define LF_TIMX_PSC 21
#define LF_TIMX_ARR 65535
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define BEMF1_Pin GPIO_PIN_0
#define BEMF1_GPIO_Port GPIOC
#define BEMF3_Pin GPIO_PIN_1
#define BEMF3_GPIO_Port GPIOC
#define SPEED_Pin GPIO_PIN_2
#define SPEED_GPIO_Port GPIOC
#define BEMF2_Pin GPIO_PIN_3
#define BEMF2_GPIO_Port GPIOC
#define BUSV_Pin GPIO_PIN_0
#define BUSV_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define DAC_DEBUG_Pin GPIO_PIN_5
#define DAC_DEBUG_GPIO_Port GPIOA
#define Temperature_feedback_Pin GPIO_PIN_4
#define Temperature_feedback_GPIO_Port GPIOC
#define GPIO_COMM_Pin GPIO_PIN_0
#define GPIO_COMM_GPIO_Port GPIOB
#define Curr_fdbk2_Pin GPIO_PIN_11
#define Curr_fdbk2_GPIO_Port GPIOB
#define EN_FAULT_Pin GPIO_PIN_12
#define EN_FAULT_GPIO_Port GPIOB
#define ENU_Pin GPIO_PIN_13
#define ENU_GPIO_Port GPIOB
#define ENV_Pin GPIO_PIN_14
#define ENV_GPIO_Port GPIOB
#define ENW_Pin GPIO_PIN_15
#define ENW_GPIO_Port GPIOB
#define GPIO_ZCR_Pin GPIO_PIN_7
#define GPIO_ZCR_GPIO_Port GPIOC
#define GPIO_BEMF_Pin GPIO_PIN_9
#define GPIO_BEMF_GPIO_Port GPIOC
#define INU_Pin GPIO_PIN_8
#define INU_GPIO_Port GPIOA
#define INV_Pin GPIO_PIN_9
#define INV_GPIO_Port GPIOA
#define INW_Pin GPIO_PIN_10
#define INW_GPIO_Port GPIOA
#define CURRENT_REF_Pin GPIO_PIN_4
#define CURRENT_REF_GPIO_Port GPIOB
#define STBY_RESET_Pin GPIO_PIN_5
#define STBY_RESET_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
