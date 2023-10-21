/**
 ******************************************************************************
 * @file    6step_conf.c
 * @author  IPC Rennes & Motor Control SDK, ST Microelectronics
 * @brief   6-step library configuration and interface file
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

/* Includes ------------------------------------------------------------------*/
#include "6step_core.h"
#include "6step_conf.h"
#include "ihm16m1_conf.h"
#include "main.h"

/** @addtogroup MIDDLEWARES
  * @brief  Middlewares Layer
  * @{
  */

/** @addtogroup MC_LIB_6STEP
  * @{
  */

/** @defgroup MC_6STEP_CONF
  * @brief 6step conf module
  * @{
  */

/** @defgroup MC_6STEP_CONF_Private_Variables
  * @{
  */
MC_Handle_t Motor_Device1;

/**
  * @} end MC_6STEP_CONF_Private_Variables
  */

/** @defgroup MC_6STEP_CONF_LL_DRIVER_CALLBACKS
  * @{
  */

/*******************************************************************************
                   LL Driver Callbacks (HAL/LL -> 6-step library)
*******************************************************************************/

/**
  * @brief     ADC conversion complete callback
  * @param[in] hadc ADC handle pointer
  * @retval None
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* For several motors, this function should be modified to select the motor device and the timer pointer according to the ADC channel used */
    MC_Core_ProcessAdcMeasurement(&Motor_Device1, (uint32_t*)hadc, (uint16_t) __HAL_TIM_GET_COUNTER((TIM_HandleTypeDef *) ((&Motor_Device1)->plf_timer)), (uint16_t) HAL_ADC_GetValue(hadc));
}

/**
  * @brief  Systick callback
  * @param[in]  None
  * @retval None
  */
void HAL_SYSTICK_Callback()
{
  /* For several motors, this function should be modified to call MC_Core_MediumFrequencyTask for each motor device */
  MC_Core_MediumFrequencyTask(&Motor_Device1);
}

/**
  * @brief     timer period elapsed callback
  * @param[in] htim TIM handle pointer
  * @retval    None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* For several motors, this function should be modified to call MC_Core_NextStep for each motor device */
  MC_Core_NextStep(&Motor_Device1, 0);
}

/**
  * @brief  EXT callback
  * @param  GPIO_Pin
  * @retval None
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == Motor_Device1.button_user.gpio_pin)
  {
    if (Motor_Device1.button_user.enabled != 0)
    {
      MC_Status_t status;
      status = MC_Core_GetStatus(&Motor_Device1);
      if (status == MC_RUN)
      {
        MC_Core_Stop(&Motor_Device1);
      }
      else if (status == MC_STOP)
      {
        MC_Core_Start(&Motor_Device1);
      }
    }
  }
}

/**
  * @brief This function is called to increment the time base of each motor
  *        device.
  * @retval None
  */
void HAL_IncTick(void)
{
  Motor_Device1.uw_tick_cnt++;
}

/**
  * @} end MC_6STEP_CONF_LL_DRIVER_CALLBACKS
  */

/** @defgroup MC_6STEP_CONF_LL_DRIVER_INTERFACE
  * @{
  */

/*******************************************************************************
                   LL Driver Interface (6-step library -> HAL/LL)
*******************************************************************************/

/**
  * @brief  MC_Core_LL_EnableChannelsHfPwmsStep14
  * @retval None
  */
void MC_Core_LL_EnableChannelsHfPwmsStep14(uint32_t *pHfTimer)
{
  LL_TIM_CC_EnableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH1 | LL_TIM_CHANNEL_CH1N | LL_TIM_CHANNEL_CH2 | LL_TIM_CHANNEL_CH2N | LL_TIM_CHANNEL_CH4);
  LL_TIM_CC_DisableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH3 | LL_TIM_CHANNEL_CH3N);
}

/**
  * @brief  MC_Core_LL_EnableChannelsHfPwmsStep25
  * @retval None
  */
void MC_Core_LL_EnableChannelsHfPwmsStep25(uint32_t *pHfTimer)
{
  LL_TIM_CC_EnableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH1 | LL_TIM_CHANNEL_CH1N | LL_TIM_CHANNEL_CH3 | LL_TIM_CHANNEL_CH3N | LL_TIM_CHANNEL_CH4);
  LL_TIM_CC_DisableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH2 | LL_TIM_CHANNEL_CH2N);
}

/**
  * @brief  MC_Core_LL_EnableChannelsHfPwmsStep36
  * @retval None
  */
void MC_Core_LL_EnableChannelsHfPwmsStep36(uint32_t *pHfTimer)
{
  LL_TIM_CC_EnableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH2 | LL_TIM_CHANNEL_CH2N | LL_TIM_CHANNEL_CH3 | LL_TIM_CHANNEL_CH3N | LL_TIM_CHANNEL_CH4);
  LL_TIM_CC_DisableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH1 | LL_TIM_CHANNEL_CH1N);
}

/**
  * @brief  MC_Core_LL_CalibrateAdc
  * @param[in] pAdc pointer to the ADC
  * @retval None
  */
void MC_Core_LL_CalibrateAdc(uint32_t *pAdc)
{
  LL_ADC_StartCalibration(((ADC_HandleTypeDef *)pAdc)->Instance, LL_ADC_SINGLE_ENDED);
  while (LL_ADC_IsCalibrationOnGoing(((ADC_HandleTypeDef *)pAdc)->Instance));
}

/**
  * @brief  MC_Core_LL_ConfigureCommutationEvent
  *         This function is mandatory to allow the update the configuration of
  *         the timer with the preloaded values at each generated event
  * @param[in] pHfTimer pointer to the HF timer
  * @param[in] pLfTimer pointer to the LF timer acting as the hall interface
  * @retval None
  */
void MC_Core_LL_ConfigureCommutationEvent(uint32_t *pHfTimer, uint32_t *pLfTimer)
{
  HAL_TIMEx_ConfigCommutEvent((TIM_HandleTypeDef *) pHfTimer, TIM_TS_NONE, TIM_COMMUTATION_SOFTWARE);
}

/**
  * @brief  MC_Core_LL_DisableIrq
  * @retval None
  */
void MC_Core_LL_DisableIrq(void)
{
  __disable_irq();
}

#if 0
/**
  * @brief  MC_Core_LL_DisableUpdateEvent
  * @param[in] pHfTimer pointer to the HF timer
  * @retval None
  */
void MC_Core_LL_DisableUpdateEvent(uint32_t *pHfTimer)
{
  LL_TIM_DisableUpdateEvent(((TIM_HandleTypeDef *) pHfTimer)->Instance);
}
#endif

/**
  * @brief  MC_Core_LL_EnableInputsHfPwmsStep14
  * @note   This function is used for 3PWM interface
  *         For several motors, this function should be modified to control different GPIOs according to the MotorDeviceId
  * @retval None
  */
void MC_Core_LL_EnableInputsHfPwmsStep14(uint8_t MotorDeviceId)
{
  LL_GPIO_ResetOutputPin(ENU_GPIO_Port, ENU_Pin|ENV_Pin|ENW_Pin);
  LL_GPIO_SetOutputPin(ENU_GPIO_Port, ENU_Pin|ENV_Pin);
}

/**
  * @brief  MC_Core_LL_EnableInputsHfPwmsStep25
  * @note   This function is used for 3PWM interface
  *         For several motors, this function should be modified to control different GPIOs according to the MotorDeviceId
  * @retval None
  */
void MC_Core_LL_EnableInputsHfPwmsStep25(uint8_t MotorDeviceId)
{
  LL_GPIO_ResetOutputPin(ENU_GPIO_Port, ENU_Pin|ENV_Pin|ENW_Pin);
  LL_GPIO_SetOutputPin(ENU_GPIO_Port, ENU_Pin|ENW_Pin);
}

/**
  * @brief  MC_Core_LL_EnableInputsHfPwmsStep36
  * @note   This function is used for 3PWM interface
  *         For several motors, this function should be modified to control different GPIOs according to the MotorDeviceId
  * @retval None
  */
void MC_Core_LL_EnableInputsHfPwmsStep36(uint8_t MotorDeviceId)
{
  LL_GPIO_ResetOutputPin(ENU_GPIO_Port, ENU_Pin|ENV_Pin|ENW_Pin);
  LL_GPIO_SetOutputPin(ENU_GPIO_Port, ENV_Pin|ENW_Pin);
}

/**
  * @brief  MC_Core_LL_EnableIrq
  * @retval None
  */
void MC_Core_LL_EnableIrq(void)
{
  __enable_irq();
}

/**
  * @brief  MC_Core_LL_Error
  * @param[in] pMc pointer to the motor control handle
  * @retval None
  */
void MC_Core_LL_Error(MC_Handle_t *pMc)
{
  MC_Core_Stop(pMc);
}

/**
  * @brief  MC_Core_LL_GenerateComEvent
  * @param[in] pHfTimer pointer to the HF timer
  * @retval None
  */
void MC_Core_LL_GenerateComEvent(uint32_t *pHfTimer)
{
  LL_TIM_GenerateEvent_COM(((TIM_HandleTypeDef *) pHfTimer)->Instance);
}

/**
  * @brief  MC_Core_LL_GetGateDrivingPwmFrequency
  * @retval Gate driving pwm frequency
  */
uint32_t MC_Core_LL_GetGateDrivingPwmFrequency(uint32_t *pHfTimer)
{
  uint32_t gate_driving_pwm_frequency = 0;
  uint8_t counter_mode;
  gate_driving_pwm_frequency = (MC_Core_LL_GetSysClockFrequency()) / ((MC_Core_LL_GetTimerPeriod((uint32_t *) pHfTimer) + 1) * (MC_Core_LL_GetTimerPrescaler((uint32_t *) pHfTimer) + 1));
  counter_mode = LL_TIM_GetCounterMode(((TIM_HandleTypeDef *) pHfTimer)->Instance);
  if ((counter_mode != LL_TIM_COUNTERMODE_UP) && (counter_mode != LL_TIM_COUNTERMODE_DOWN))
  {
    gate_driving_pwm_frequency >>= 1;
  }
  return gate_driving_pwm_frequency;
}

/**
  * @brief  MC_Core_LL_GetSysClockFrequency
  * @retval System clock frequency
  */
uint32_t MC_Core_LL_GetSysClockFrequency(void)
{
  return (uint32_t) HAL_RCC_GetSysClockFreq();
}

/**
  * @brief  MC_Core_LL_GetTemperatureCalibrationData
  * @param[in] pMc pointer to the motor control handle
  * @retval None
  */
void MC_Core_LL_GetTemperatureCalibrationData(MC_Handle_t *pMc)
{
  pMc->adc_user.ts_cal_1_temp_deg_c = IHM16M1_NTC_TEMP_1_C;
  pMc->adc_user.ts_cal_2_temp_deg_c = IHM16M1_NTC_TEMP_2_C;
  pMc->adc_user.ts_cal_1 = IHM16M1_TS_CAL_1;
  pMc->adc_user.ts_cal_2 = IHM16M1_TS_CAL_2;
  pMc->adc_user.vrefint_cal = *((uint16_t*) (VREFINT_CAL_ADDR));
}

/**
  * @brief  MC_Core_LL_GetTimerPeriod
  * @param[in] pTimer pointer to relevant timer
  * @retval timer period
  */
uint16_t MC_Core_LL_GetTimerPeriod(uint32_t *pTimer)
{
  return (uint16_t) __HAL_TIM_GET_AUTORELOAD((TIM_HandleTypeDef *) pTimer);
}

/**
  * @brief  MC_Core_LL_GetTimerPrescaler
  * @param[in] pTimer pointer to relevant timer
  * @retval timer period
  */
uint16_t MC_Core_LL_GetTimerPrescaler(uint32_t *pTimer)
{
  return (uint16_t) LL_TIM_GetPrescaler(((TIM_HandleTypeDef *) pTimer)->Instance);
}

/**
  * @brief  MC_Core_LL_ResetBemfGpio
  * @param[in] MotorDeviceId Motor device id
  * @retval None
  */
void MC_Core_LL_ResetBemfGpio(uint8_t MotorDeviceId)
{
  /* For several motors, this function should be modified to control a different GPIO according to the MotorDeviceId */
  HAL_GPIO_WritePin(GPIO_BEMF_GPIO_Port, GPIO_BEMF_Pin, GPIO_PIN_RESET);
}

/**
  * @brief  MC_Core_LL_SetBemfGpio
  * @param[in] MotorDeviceId Motor device id
  * @retval None
  */
void MC_Core_LL_SetBemfGpio(uint8_t MotorDeviceId)
{
  /* For several motors, this function should be modified to control a different GPIO according to the MotorDeviceId */
  HAL_GPIO_WritePin(GPIO_BEMF_GPIO_Port, GPIO_BEMF_Pin, GPIO_PIN_SET);
}

/**
  * @brief  MC_Core_LL_SetDutyCyclePwmForAdcTrig
  * @param[in] pTimer pointer to relevant timer
  * @param[in] Channel channel used to trig the ADC
  * @param[in] PulseValue pulse value of the timer channel used to trig the ADC
  * @retval None
  */
void MC_Core_LL_SetDutyCyclePwmForAdcTrig(uint32_t *pTimer, uint32_t Channel, uint16_t PulseValue)
{
  switch (Channel)
  {
    case LL_TIM_CHANNEL_CH1:
    {
      LL_TIM_OC_SetCompareCH1(((TIM_HandleTypeDef *) pTimer)->Instance, PulseValue);
    }
    break;
    case LL_TIM_CHANNEL_CH2:
    {
      LL_TIM_OC_SetCompareCH2(((TIM_HandleTypeDef *) pTimer)->Instance, PulseValue);
    }
    break;
    case LL_TIM_CHANNEL_CH3:
    {
      LL_TIM_OC_SetCompareCH3(((TIM_HandleTypeDef *) pTimer)->Instance, PulseValue);
    }
    break;
    case LL_TIM_CHANNEL_CH4:
    {
      LL_TIM_OC_SetCompareCH4(((TIM_HandleTypeDef *) pTimer)->Instance, PulseValue);
    }
    break;
  default:
    LL_TIM_OC_SetCompareCH1(((TIM_HandleTypeDef *) pTimer)->Instance, PulseValue);
  }
}

/**
  * @brief  MC_Core_LL_SetDutyCycleHfPwmForStepN
  * @param[in] pHfTimer pointer to the HF timer
  * @param[in] PulseValue pulse value of the HF timer channel corresponding to the StepNumber
  * @param[in] StepNumber step number in the 6step sequence
  * @retval None
  */
void MC_Core_LL_SetDutyCycleHfPwmForStepN(uint32_t *pHfTimer, uint16_t PulseValue, uint8_t StepNumber)
{
  uint32_t volatile* ptr = &(((TIM_HandleTypeDef *) pHfTimer)->Instance->CCR1);
  __disable_irq();
  ptr += ((--StepNumber) >> 1);
  *ptr = PulseValue;
  __enable_irq();
}

/**
  * @brief  MC_Core_LL_SetDutyCycleHfPwms
  * @param[in] pHfTimer pointer to the HF timer
  * @param[in] PulseValue1 pulse value of the HF timer channel 1
  * @param[in] PulseValue2 pulse value of the HF timer channel 2
  * @param[in] PulseValue3 pulse value of the HF timer channel 3
  * @retval None
  */
void MC_Core_LL_SetDutyCycleHfPwms(uint32_t *pHfTimer, uint16_t PulseValue1, uint16_t PulseValue2, uint16_t PulseValue3)
{
  LL_TIM_OC_SetCompareCH1(((TIM_HandleTypeDef *) pHfTimer)->Instance, PulseValue1);
  LL_TIM_OC_SetCompareCH2(((TIM_HandleTypeDef *) pHfTimer)->Instance, PulseValue2);
  LL_TIM_OC_SetCompareCH3(((TIM_HandleTypeDef *) pHfTimer)->Instance, PulseValue3);
}

/**
  * @brief  MC_Core_LL_SetDutyCycleRefPwm
  * @param[in] pHfTimer pointer to the REF timer
  * @param[in] PulseValue pulse value of the REF timer channel used to generate the reference voltage
  * @retval None
  */
void MC_Core_LL_SetDutyCycleRefPwm(uint32_t *pRefTimer, uint16_t PulseValue)
{
  LL_TIM_OC_SetCompareCH1(((TIM_HandleTypeDef *) pRefTimer)->Instance, PulseValue);
}

/**
  * @brief  MC_Core_LL_SetPeriodTimer
  * @param[in] PeriodValue period value for the timer
  * @retval None
  */
void MC_Core_LL_SetPeriodTimer(uint32_t *pTimer, uint16_t PeriodValue)
{
  __HAL_TIM_SET_AUTORELOAD((TIM_HandleTypeDef *) pTimer, PeriodValue);
}

/**
  * @brief  MC_Core_LL_SetPrescalerLfTimer
  * @param[in] PrescalerValue prescaler value for the LF timer
  * @retval None
  */
void MC_Core_LL_SetPrescalerTimer(uint32_t *pTimer, uint16_t PrescalerValue)
{
  __HAL_TIM_SET_PRESCALER((TIM_HandleTypeDef *) pTimer, PrescalerValue);
}

/**
  * @brief  MC_Core_LL_SelectAdcChannel
  * @param[in] pAdcItToBeDisabled pointer to the ADC with the end of conversion interrupt to be disabled
  * @param[in] pAdcItToBeEnabled pointer to the ADC with the end of conversion interrupt to be enabled
  * @param[in] AdcChannel ADC channel to be selected
  * @param[in] SamplingTime ADC sampling time to be selected
  * @retval None
  */
void MC_Core_LL_SelectAdcChannel(uint32_t *pAdcItToBeDisabled, uint32_t *pAdcItToBeEnabled, uint32_t AdcChannel, uint32_t SamplingTime)
{
  __HAL_ADC_DISABLE_IT(((ADC_HandleTypeDef *)pAdcItToBeDisabled), ADC_IT_EOC);
  /* SamplingTime is not used for STM32G431RB as it is already programed in SMPRx registers */
  while (LL_ADC_REG_IsConversionOngoing(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance))
  {
    LL_ADC_REG_StopConversion(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance);
    while(LL_ADC_REG_IsStopConversionOngoing(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance));
  }
  LL_ADC_REG_SetSequencerRanks(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance, LL_ADC_REG_RANK_1, AdcChannel);
  LL_ADC_REG_StartConversion(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance);
  __HAL_ADC_CLEAR_FLAG(((ADC_HandleTypeDef *)pAdcItToBeEnabled), ADC_FLAG_EOC);
  __HAL_ADC_ENABLE_IT(((ADC_HandleTypeDef *)pAdcItToBeEnabled), ADC_IT_EOC);
}

/**
  * @brief  MC_Core_LL_SelectAdcChannelDuringCallback
  * @note   By design when the ADC channel is selected during the ADC callback
  * there is no more conversion on-going. Indeed there is always only one
  * conversion programmed in the ADC sequence. However the ADC must still be
  * stop start to ensure uncorrupted measurement on next conversion.
  * @param[in] pAdcItToBeDisabled pointer to the ADC with the end of conversion interrupt to be disabled
  * @param[in] pAdcItToBeEnabled pointer to the ADC with the end of conversion interrupt to be enabled
  * @param[in] AdcChannel ADC channel to be selected
  * @param[in] SamplingTime ADC sampling time to be selected
  * @retval None
  */
void MC_Core_LL_SelectAdcChannelDuringCallback(uint32_t *pAdcItToBeDisabled, uint32_t *pAdcItToBeEnabled, uint32_t AdcChannel, uint32_t SamplingTime)
{
  __HAL_ADC_DISABLE_IT(((ADC_HandleTypeDef *)pAdcItToBeDisabled), ADC_IT_EOC);
  /* SamplingTime is not used for STM32G431RB as it is already programed in SMPRx registers */
  LL_ADC_REG_StopConversion(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance);
  LL_ADC_REG_SetSequencerRanks(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance, LL_ADC_REG_RANK_1, AdcChannel);
  LL_ADC_REG_StartConversion(((ADC_HandleTypeDef *)pAdcItToBeEnabled)->Instance);
  __HAL_ADC_CLEAR_FLAG(((ADC_HandleTypeDef *)pAdcItToBeEnabled), ADC_FLAG_EOC);
  __HAL_ADC_ENABLE_IT(((ADC_HandleTypeDef *)pAdcItToBeEnabled), ADC_IT_EOC);
}

/**
  * @brief  MC_Core_LL_SetAdcSamplingTime
  * @param[in] pAdc pointer to the ADC
  * @param[in] AdcChannel ADC channel to be selected
  * @param[in] SamplingTime ADC sampling time to be selected
  * @retval None
  */
void MC_Core_LL_SetAdcSamplingTime(uint32_t *pAdc, uint32_t AdcChannel, uint32_t SamplingTime)
{
  LL_ADC_SetChannelSamplingTime(((ADC_HandleTypeDef *)pAdc)->Instance, AdcChannel, SamplingTime);
}

/**
  * @brief  MC_Core_LL_StartAdcIt
  * @param[in] pAdc pointer to the ADC
  * @retval None
  */
void MC_Core_LL_StartAdcIt(uint32_t *pAdc)
{
  HAL_ADC_Start_IT((ADC_HandleTypeDef *)pAdc);
}

/**
  * @brief  MC_Core_LL_StartHfPwms
  * @param[in] pHfTimer pointer to the HF timer
  * @retval None
  */
void MC_Core_LL_StartHfPwms(uint32_t *pHfTimer)
{
  LL_TIM_EnableCounter(((TIM_HandleTypeDef *) pHfTimer)->Instance);
  LL_TIM_CC_EnableChannel(((TIM_HandleTypeDef *) pHfTimer)->Instance, LL_TIM_CHANNEL_CH1|LL_TIM_CHANNEL_CH2|LL_TIM_CHANNEL_CH3);
  LL_TIM_EnableAllOutputs(((TIM_HandleTypeDef *) pHfTimer)->Instance);
  __HAL_TIM_CLEAR_IT(((TIM_HandleTypeDef *) pHfTimer), TIM_IT_BREAK);
  __HAL_TIM_ENABLE_IT(((TIM_HandleTypeDef *) pHfTimer), TIM_IT_BREAK);
}

/**
  * @brief  MC_Core_LL_StartTimerIt
  * @retval None
  */
void MC_Core_LL_StartTimerIt(uint32_t *pTimer)
{
  __HAL_TIM_CLEAR_IT((TIM_HandleTypeDef *) pTimer, TIM_IT_UPDATE);
  HAL_TIM_Base_Start_IT((TIM_HandleTypeDef *) pTimer);
}

/**
  * @brief  MC_Core_LL_StartRefPwms
  * @param[in] pRefTimer pointer to the REF timer
  * @retval None
  */
void MC_Core_LL_StartRefPwm(uint32_t *pRefTimer)
{
  LL_TIM_EnableCounter(((TIM_HandleTypeDef *) pRefTimer)->Instance);
  LL_TIM_CC_EnableChannel(((TIM_HandleTypeDef *) pRefTimer)->Instance, LL_TIM_CHANNEL_CH1);
}

/**
  * @brief  MC_Core_LL_StopAdcIt
  * @param[in] pAdc pointer to the ADC
  * @retval None
  */
void MC_Core_LL_StopAdcIt(uint32_t *pAdc)
{
  HAL_ADC_Stop_IT((ADC_HandleTypeDef *)pAdc);
}

/**
  * @brief  MC_Core_LL_StopHfPwms
  *         This function shall not stop complementary PWM in case of
  *         a x3 PWM interface.
  * @param[in] pHfTimer pointer to the HF timer
  * @retval None
  */
void MC_Core_LL_StopHfPwms(uint32_t *pHfTimer)
{
  HAL_TIM_PWM_Stop((TIM_HandleTypeDef *) pHfTimer, TIM_CHANNEL_1); //TIM1_CH1 DISABLE
  HAL_TIM_PWM_Stop((TIM_HandleTypeDef *) pHfTimer, TIM_CHANNEL_2); //TIM1_CH2 DISABLE
  HAL_TIM_PWM_Stop((TIM_HandleTypeDef *) pHfTimer, TIM_CHANNEL_3); //TIM1_CH3 DISABLE
  HAL_TIM_PWM_Stop((TIM_HandleTypeDef *) pHfTimer, TIM_CHANNEL_4); //TIM1_CH4 DISABLE
  __HAL_TIM_SET_COUNTER(((TIM_HandleTypeDef *) pHfTimer), 0);
  __HAL_TIM_DISABLE_IT(((TIM_HandleTypeDef *) pHfTimer), TIM_IT_BREAK | TIM_IT_COM);
  __HAL_TIM_CLEAR_IT(((TIM_HandleTypeDef *) pHfTimer), TIM_IT_BREAK | TIM_IT_COM);
}

/**
  * @brief  MC_Core_LL_StopLfTimerIt
  * @retval None
  */
void MC_Core_LL_StopTimerIt(uint32_t *pTimer)
{
  HAL_TIM_Base_Stop_IT((TIM_HandleTypeDef *) pTimer);
  __HAL_TIM_CLEAR_IT((TIM_HandleTypeDef *) pTimer, TIM_IT_UPDATE);
  __HAL_TIM_SET_COUNTER((TIM_HandleTypeDef *) pTimer, 0);
}

/**
  * @brief  MC_Core_LL_StopRefPwm
  * @param[in] pHfTimer pointer to the REF timer
  * @retval None
  */
void MC_Core_LL_StopRefPwm(uint32_t *pRefTimer)
{
  HAL_TIM_PWM_Stop((TIM_HandleTypeDef *) pRefTimer, TIM_CHANNEL_1); //TIM1_CH1 DISABLE
  __HAL_TIM_SET_COUNTER(((TIM_HandleTypeDef *) pRefTimer), 0);
}

/**
  * @brief  MC_Core_LL_ToggleCommGpio
  * @retval None
  */
void MC_Core_LL_ToggleCommGpio(uint8_t MotorDeviceId)
{
  /* For several motors, this function should be modified to control a different GPIO according to the MotorDeviceId */
  HAL_GPIO_TogglePin(GPIO_COMM_GPIO_Port, GPIO_COMM_Pin);
}

/**
  * @brief  MC_Core_LL_ToggleZeroCrossingGpio
  * @retval None
  */
void MC_Core_LL_ToggleZeroCrossingGpio(uint8_t MotorDeviceId)
{
  /* For several motors, this function should be modified to control a different GPIO according to the MotorDeviceId */
  HAL_GPIO_TogglePin(GPIO_ZCR_GPIO_Port, GPIO_ZCR_Pin);
}

/**
  * @} end MC_6STEP_CONF_LL_DRIVER_INTERFACE
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

