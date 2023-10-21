/**
  ******************************************************************************
  * @file    6step_init.c
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file implements 6 step application initialization
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "6step_init.h"
#include "6step_conf.h"
#include "ihm16m1_conf.h"
#include "ihm16m1.h"

/** @addtogroup MIDDLEWARES
  * @brief  Middlewares Layer
  * @{
  */

/** @addtogroup MC_LIB_6STEP
  * @{
  */

/* Initializes the Motor subsystem core according to user defined parameters */
void MCboot( MC_Handle_t* pMCIList[] )
{
  /* NUCLEO-STM32G431RB + X-NUCLEO-IHM16M1, ADC1 config */
  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(hadc1.Instance), LL_ADC_PATH_INTERNAL_VREFINT);
  /* TIM1 config */
  LL_TIM_OC_SetDeadTime(htim1.Instance, DEAD_TIME);

  /* Timers initialization */
  __HAL_DBGMCU_FREEZE_TIM1();
  __HAL_DBGMCU_FREEZE_TIM4();

  IHM16M1_MOTOR_DRIVER_Init();
  IHM16M1_MOTOR_DRIVER_SetPwrStage(STSPIN830_PWR_ENABLE);
  IHM16M1_MOTOR_DRIVER_SetStby(STSPIN830_STBY_DISABLE);

  MC_Core_AssignTimers( pMCIList[0], (uint32_t *)&htim1, (uint32_t *)&htim4, (uint32_t *)&htim3 );
  MC_Core_ConfigureBemfAdc( pMCIList[0], (uint32_t *)&hadc1, (uint32_t *)&htim1, (uint16_t)LL_TIM_CHANNEL_CH4 );
  MC_Core_ConfigureBemfAdcChannel( pMCIList[0], IHM16M1_ADC_BEMF_CH1, IHM16M1_ADC_BEMF_ST, MC_BEMF_PHASE_1 );
  MC_Core_ConfigureBemfAdcChannel( pMCIList[0], IHM16M1_ADC_BEMF_CH2, IHM16M1_ADC_BEMF_ST, MC_BEMF_PHASE_2 );
  MC_Core_ConfigureBemfAdcChannel( pMCIList[0], IHM16M1_ADC_BEMF_CH3, IHM16M1_ADC_BEMF_ST, MC_BEMF_PHASE_3 );

  MC_Core_ConfigureUserAdc( pMCIList[0], (uint32_t *)&htim1, (uint16_t)LL_TIM_CHANNEL_CH4 );
  MC_Core_ConfigureUserAdcChannel( pMCIList[0], (uint32_t *)&hadc2, IHM16M1_ADC_SPEED, IHM16M1_ADC_SPEED_ST, MC_USER_MEAS_1 );
  MC_Core_ConfigureUserAdcChannel( pMCIList[0], (uint32_t *)&hadc2, IHM16M1_ADC_CURRENT, IHM16M1_ADC_CURRENT_ST, MC_USER_MEAS_2 );
  MC_Core_ConfigureUserAdcChannel( pMCIList[0], (uint32_t *)&hadc2, IHM16M1_ADC_VBUS, IHM16M1_ADC_VBUS_ST, MC_USER_MEAS_3 );
  MC_Core_ConfigureUserAdcChannel( pMCIList[0], (uint32_t *)&hadc2, IHM16M1_ADC_TEMP, IHM16M1_ADC_TEMP_ST, MC_USER_MEAS_4 );
  MC_Core_ConfigureUserAdcChannel( pMCIList[0], (uint32_t *)&hadc1, IHM16M1_ADC_VREF, IHM16M1_ADC_VREF_ST, MC_USER_MEAS_5 );

  MC_Core_ConfigureUserButton( pMCIList[0], (uint16_t) B1_Pin, (uint16_t) 500 );

  if ( MC_Core_Init( pMCIList[0] ) != MC_FUNC_OK )
  {
    Error_Handler();
  }

}

/**
  * @}  end MC_LIB_6STEP
  */

/**
  * @}  end MIDDLEWARES
  */

/******************* (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/
