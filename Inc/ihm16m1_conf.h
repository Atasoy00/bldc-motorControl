/**
 ******************************************************************************
 * @file    ihm16m1_conf.h
 * @author  IPC Rennes & Motor Control SDK, ST Microelectronics
 * @brief   IHM16M1 configuration file.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2019 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IHM16M1_CONF_H__
#define __IHM16M1_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "g431rb_bus.h"
#include "g431rb_errno.h"

#define DEGREE_TO_KELVIN(__DEGREE__)  (__DEGREE__ + 273)

#define IHM16M1_ADC_BEMF_CH1    LL_ADC_CHANNEL_6  /*BEMF1*/
#define IHM16M1_ADC_BEMF_CH2    LL_ADC_CHANNEL_9  /*BEMF2*/
#define IHM16M1_ADC_BEMF_CH3    LL_ADC_CHANNEL_7  /*BEMF3*/
#define IHM16M1_ADC_SPEED       LL_ADC_CHANNEL_8     /*POTENTIOMETER FOR SPEED*/
#define IHM16M1_ADC_CURRENT     LL_ADC_CHANNEL_14   /*CURRENT*/
#define IHM16M1_ADC_VBUS        LL_ADC_CHANNEL_1      /*VBUS*/
#define IHM16M1_ADC_TEMP        LL_ADC_CHANNEL_5      /*TEMPERATURE*/
#define IHM16M1_ADC_VREF        LL_ADC_CHANNEL_VREFINT      /*VOLTAGE REFERENCE*/

#define IHM16M1_ADC_BEMF_ST     LL_ADC_SAMPLINGTIME_12CYCLES_5   /*ADC Sampling Time for BEMF measurements*/
#define IHM16M1_ADC_SPEED_ST    LL_ADC_SAMPLINGTIME_12CYCLES_5   /*ADC Sampling Time for SPEED measurements*/
#define IHM16M1_ADC_CURRENT_ST  LL_ADC_SAMPLINGTIME_12CYCLES_5   /*ADC Sampling Time for CURRENT measurements*/
#define IHM16M1_ADC_VBUS_ST     LL_ADC_SAMPLINGTIME_12CYCLES_5   /*ADC Sampling Time for VBUS measurements*/
#define IHM16M1_ADC_TEMP_ST     LL_ADC_SAMPLINGTIME_12CYCLES_5   /*ADC Sampling Time for TEMPERATURE measurements*/
#define IHM16M1_ADC_VREF_ST     LL_ADC_SAMPLINGTIME_92CYCLES_5  /*ADC Sampling Time for VOLTAGE REFERENCE measurements*/

#define IHM16M1_NTC_TEMP_1_C     ((int8_t) 25)
#define IHM16M1_NTC_TEMP_2_C     ((int8_t) 50)
#define IHM16M1_NTC_R_1_OHMS     ((uint16_t) 47000)
#define IHM16M1_NTC_R_2_OHMS     ((uint16_t) 16432)
#define IHM16M1_DIV_R_OHMS       ((uint16_t) 10000)
#define IHM16M1_DIV_RATIO_1      ((uint16_t) (((uint32_t)(1000 * IHM16M1_DIV_R_OHMS)) / ((uint32_t)(IHM16M1_DIV_R_OHMS + IHM16M1_NTC_R_1_OHMS))))
#define IHM16M1_DIV_RATIO_2      ((uint16_t) (((uint32_t)(1000 * IHM16M1_DIV_R_OHMS)) / ((uint32_t)(IHM16M1_DIV_R_OHMS + IHM16M1_NTC_R_2_OHMS))))
#define IHM16M1_ADC_RESOLUTION   ((uint8_t) 12)
#define IHM16M1_ADC_FULL_SCALE   ((uint16_t) ((1<<IHM16M1_ADC_RESOLUTION)-1))
#define IHM16M1_TS_CAL_1         ((uint16_t) (((uint32_t) (IHM16M1_ADC_FULL_SCALE * IHM16M1_DIV_RATIO_1))/1000))
#define IHM16M1_TS_CAL_2         ((uint16_t) (((uint32_t) (IHM16M1_ADC_FULL_SCALE * IHM16M1_DIV_RATIO_2))/1000))

#define IHM16M1_Init            BSP_GPIO_Init
#define IHM16M1_DeInit          BSP_GPIO_DeInit
#define IHM16M1_GetPwrStage     BSP_GetPwrStage
#define IHM16M1_SetPwrStage     BSP_SetPwrStage
#define IHM16M1_GetStby         BSP_GetStby
#define IHM16M1_SetStby         BSP_SetStby

#ifdef __cplusplus
}
#endif

#endif /* __IHM16M1_CONF_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

