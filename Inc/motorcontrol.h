/**
  ******************************************************************************
  * @file    motorcontrol.h
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   Motor Control Subsystem initialization functions.
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
  * @ingroup MCAPI
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MOTORCONTROL_H
#define __MOTORCONTROL_H

/* Initializes the Motor Control Subsystem */
#include "6step_core.h"

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

void MX_MotorControl_Init(void);

#ifdef __cplusplus
}
#endif /* __cpluplus */

#endif /* __MOTORCONTROL_H */
/******************* (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/
