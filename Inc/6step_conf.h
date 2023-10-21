/**
 ******************************************************************************
 * @file    6step_conf.h
 * @author  IPC Rennes & Motor Control SDK, ST Microelectronics
 * @brief   Header file for the 6step_conf.c file
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics International N.V.
 * All rights reserved.</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other
 *    contributors to this software may be used to endorse or promote products
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under
 *    this license is void and will automatically terminate your rights under
 *    this license.
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __6STEP_CONF_H
#define __6STEP_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "Motor_Configuration.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_ll_tim.h"
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_adc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @addtogroup MIDDLEWARES
  * @brief  Middlewares Layer
  * @{
  */

/** @addtogroup MC_LIB_6STEP
  * @{
  */

/** @defgroup MC_6STEP_CONF
  * @{
  */

/** @defgroup MC_6STEP_CONF_Exported_Defines
  * @{
  */

/*!< Manage the overall system configuration */
/*!< Number of motor devices */
#define NUMBER_OF_DEVICES       (1)

/*!< Motor control sensing : set one definition to 1, others to 0 */
#define SENSORS_LESS            (1)
#define HALL_SENSORS            (0)
#define SENSE_COMPARATORS       (0)

/*!< Motor control mode */
/*!< Set VOLTAGE_MODE to 1 and CURRENT_MODE to 0 or the contrary */
#define VOLTAGE_MODE            (1)
#define CURRENT_MODE            (0)

/*!< Motor control additional features */
/*!< Set independantly SPEED_LOOP either to 1 or 0 */
#define SPEED_LOOP              (1)
/*!< Set independantly SET_POINT_RAMPING either to 1 or 0 */
#define SET_POINT_RAMPING       (0)
/*!< Set independantly gate driver pwm interface THREE_PWM either to 1 or 0 */
#define THREE_PWM               (1)

/*!< Motor control user interface : set one definition to 1, others to 0 */
#define UART_INTERFACE          (0)
#define POTENTIOMETER_INTERFACE (0)
#define PWM_INTERFACE           (0)

/**
  * @} end MC_6STEP_CONF_Exported_Defines
  */

/**
  * @}  end MC_6STEP_CONF
  */

/**
  * @}  end MC_LIB_6STEP
  */

/**
  * @}  end MIDDLEWARES
  */

#ifdef __cplusplus
}
#endif

#endif /* __6STEP_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
