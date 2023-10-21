/**
  ******************************************************************************
  * @file    user_interface.c
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file provides firmware functions that implement the following features
  *          of the user interface component of the Motor Control SDK.
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

/* Includes ------------------------------------------------------------------*/
/* Pre-compiler coherency check */
#include "mc_type.h"
#include "mc_config.h"
#include "user_interface.h"
#include "ihm16m1_conf.h"

/** @addtogroup MCSDK
  * @{
  */

/** @defgroup MCUI Motor Control User Interface
  * @brief User Interface Components of the Motor Control SDK
  *
  * These components aim at connecting the Application with the outside. There are two categories
  * of UI Componentes:
  *
  * - Some connect the application with the Motor Conrol Monitor tool via a UART link. The Motor
  *   Control Monitor can control the motor(s) driven by the application and also read and write
  *   internal variables of the Motor Control subsystem.
  * - Others UI components allow for using the DAC(s) peripherals in
  *   order to output internal variables of the Motor Control subsystem for debug purposes.
  *
  * @{
  */

/**
  * @brief  Initialize the user interface component.
  *
  * Perform the link between the UI, MC interface and MC tuning components.

  * @param  pHandle: Pointer on Handle structure of UI component.
  * @param  bMCNum  Number of MC instance present in the list.
  * @param  pMCI Pointer on the list of MC interface component to inked with UI.
  * @param  pUICfg Pointer on the user interface configuration list.
  *         Each element of the list must be a bit field containing one (or more) of
  *         the exported configuration option UI_CFGOPT_xxx (eventually OR-ed).
  * @retval none.
  */
__weak void UI_Init(UI_Handle_t *pHandle, uint8_t bMCNum, MC_Handle_t ** pMCI, uint32_t* pUICfg)
{
  pHandle->bDriveNum = bMCNum;
  pHandle->pMCI = pMCI;
  pHandle->bSelectedDrive = 0u;
  pHandle->pUICfg = pUICfg;
}

/**
  * @brief  Allow to select the MC on which UI operates.
  * @param  pHandle: Pointer on Handle structure of UI component.
  * @param  bSelectMC: The new selected MC, zero based, on which UI operates.
  * @retval Boolean set to true if the bSelectMC is valid oterwise return false.
  */
__weak bool UI_SelectMC(UI_Handle_t *pHandle,uint8_t bSelectMC)
{
  bool retVal = true;
  if (bSelectMC  >= pHandle->bDriveNum)
  {
    retVal = false;
  }
  else
  {
    pHandle->bSelectedDrive = bSelectMC;
  }
  return retVal;
}

/**
  * @brief  Allow to retrieve the MC on which UI currently operates.
  * @param  pHandle: Pointer on Handle structure of UI component.
  * @retval Return the currently selected MC, zero based, on which UI operates.
  */
__weak uint8_t UI_GetSelectedMC(UI_Handle_t *pHandle)
{
  return (pHandle->bSelectedDrive);
}

/**
  * @brief  Retrieve the configuration of the MC on which UI currently operates.
  * @param  pHandle: Pointer on Handle structure of UI component.
  * @retval Return the currently configuration of selected MC on which UI operates.
  *         It represents a bit field containing one (or more) of
  *         the exported configuration option UI_CFGOPT_xxx (eventually OR-ed).
  */
__weak uint32_t UI_GetSelectedMCConfig(UI_Handle_t *pHandle)
{
  return pHandle->pUICfg[pHandle->bSelectedDrive];
}

/**
  * @brief  Allow to execute a SetReg command coming from the user.
  * @param  pHandle: Pointer on Handle structure of UI component.
  * @param  bRegID: Code of register to update.
  *         See MC_PROTOCOL_REG_xxx for code definition.
  * @param  wValue: New value to set.
  * @retval Return the currently selected MC, zero based, on which UI operates.
  */
__weak bool UI_SetReg(UI_Handle_t *pHandle, MC_Protocol_REG_t bRegID, int32_t wValue)
{
  MC_Handle_t * pMCI = pHandle->pMCI[pHandle->bSelectedDrive];

  bool retVal = true;
  switch (bRegID)
  {
  case MC_PROTOCOL_REG_TARGET_MOTOR:
    {
      retVal = UI_SelectMC(pHandle,(uint8_t)wValue);
    }
    break;

  case MC_PROTOCOL_REG_SPEED_REF:
    {

      pMCI->speed_target_value = wValue;

    }
    break;

  case MC_PROTOCOL_REG_RAMP_FINAL_SPEED:
    {
      (void)MC_Core_SetSpeed( pMCI, wValue );
    }
    break;

  case MC_PROTOCOL_REG_SPEED_KP:
    {
      pMCI->pid_parameters.kp = wValue;
    }
    break;

  case MC_PROTOCOL_REG_SPEED_KI:
    {
      pMCI->pid_parameters.ki = wValue;
    }
    break;

  case MC_PROTOCOL_REG_SPEED_KD:
    {
      pMCI->pid_parameters.kd = wValue;
    }
    break;

  default:
    retVal = false;
    break;
  }

  return retVal;
}

/* Used to execute a GetReg command coming from the user. */
__weak int32_t UI_GetReg(UI_Handle_t *pHandle, MC_Protocol_REG_t bRegID, bool * success)
{
  MC_Handle_t * pMCI = pHandle->pMCI[pHandle->bSelectedDrive];

  int32_t bRetVal = 0;

  if ( success != (bool *) 0 )
  {
    *success = true;
  }

  switch (bRegID)
  {
    case MC_PROTOCOL_REG_TARGET_MOTOR:
    {
      bRetVal = (int32_t)UI_GetSelectedMC(pHandle);
    }
    break;

    case MC_PROTOCOL_REG_FLAGS:
    {
      switch ( pMCI->status )
      {
        case MC_IDLE:
        case MC_STOP:
        case MC_ALIGNMENT:
        case MC_STARTUP:
        case MC_VALIDATION:
        case MC_RUN:
          bRetVal = (int32_t) 0;
          break;
        case MC_SPEEDFBKERROR:
          bRetVal = MC_SPEED_FDBK;
          break;
        case MC_OVERCURRENT:
          bRetVal = MC_BREAK_IN;
          break;
        case MC_VALIDATION_FAILURE:
          bRetVal = MC_START_UP;
          break;
        case MC_VALIDATION_BEMF_FAILURE:
          bRetVal = (MC_SW_ERROR | MC_SPEED_FDBK);
          break;
        case MC_VALIDATION_HALL_FAILURE:
          bRetVal = (MC_SW_ERROR | MC_SPEED_FDBK);
          break;
        case MC_LF_TIMER_FAILURE:
          bRetVal = MC_FOC_DURATION;
          break;
        default:
          bRetVal = MC_SW_ERROR;
		  break;
	  }
    }
	break;

    case MC_PROTOCOL_REG_STATUS:
    {
      switch ( pMCI->status )
        {
        case MC_IDLE:
          bRetVal = IDLE;
          break;
        case MC_STOP:
          bRetVal = STOP;
          break;
        case MC_ALIGNMENT:
          bRetVal = ALIGNMENT;
          break;
        case MC_STARTUP:
          bRetVal = START;
          break;
        case MC_VALIDATION:
          bRetVal = START_RUN;
          break;
        case MC_RUN:
          bRetVal = RUN;
          break;
        case MC_SPEEDFBKERROR:
        case MC_OVERCURRENT:
        case MC_VALIDATION_FAILURE:
        case MC_VALIDATION_BEMF_FAILURE:
        case MC_VALIDATION_HALL_FAILURE:
        case MC_LF_TIMER_FAILURE:
        case MC_ADC_CALLBACK_FAILURE:
          bRetVal = FAULT_OVER;
          break;
        default:
          bRetVal = FAULT_NOW;
		  break;
		}
    }
	break;

    case MC_PROTOCOL_REG_SPEED_REF:
    {
      bRetVal = (int32_t) pMCI->speed_target_command;
    }
    break;

    case MC_PROTOCOL_REG_SPEED_KP:
    {
      bRetVal = (int32_t) pMCI->pid_parameters.kp;
    }
    break;

    case MC_PROTOCOL_REG_SPEED_KI:
    {
      bRetVal = (int32_t) pMCI->pid_parameters.ki;
    }
    break;

    case MC_PROTOCOL_REG_SPEED_KD:
    {
      bRetVal = (int32_t) pMCI->pid_parameters.kd;
    }
    break;

    case MC_PROTOCOL_REG_BUS_VOLTAGE:
    {
      bRetVal = (int32_t) (3.30 / IHM16M1_ADC_FULL_SCALE / 0.0625 * pMCI->adc_user.measurement[MC_USER_MEAS_3]);
    }
    break;

    case MC_PROTOCOL_REG_HEATS_TEMP:
    {
      bRetVal = (int32_t) (3.30 / IHM16M1_ADC_FULL_SCALE / 0.0625 * pMCI->adc_user.measurement[MC_USER_MEAS_4]);
    }
    break;

    case MC_PROTOCOL_REG_SPEED_MEAS:
    {
      bRetVal = (int32_t) MC_Core_GetSpeed( pMCI );
    }
    break;

    case MC_PROTOCOL_REG_UID:
    {
      bRetVal = (int32_t)(MC_UID);
    }
    break;

    case MC_PROTOCOL_REG_CTRBDID:
    {
      bRetVal = CTRBDID;
    }
    break;

    case MC_PROTOCOL_REG_PWBDID:
    {
      bRetVal = PWBDID;
    }
    break;

    case MC_PROTOCOL_REG_PWBDID2:
    {
      bRetVal = (uint32_t) 0;
    }
    break;

    case MC_PROTOCOL_REG_TORQUE_REF:
    {
      bRetVal = (int32_t) pMCI->pulse_value;
    }
    break;

    case MC_PROTOCOL_REG_FLUX_REF:
    {
      bRetVal = (int32_t) pMCI->startup_reference;
    }
    break;

    default:
	{
      bRetVal = (int32_t) 0;
	}
    break;
  }
  return bRetVal;
}

/**
  * @brief  Allow to execute a command coming from the user.
  * @param  pHandle: Pointer on Handle structure of UI component.
  * @param  bCmdID: Code of command to execute.
  *         See MC_PROTOCOL_CMD_xxx for code definition.
  *  @retval Return true if the command executed succesfully, otherwise false.
*/
__weak bool UI_ExecCmd(UI_Handle_t *pHandle, uint8_t bCmdID)
{
  bool retVal = true;

  MC_Handle_t * pMCI = pHandle->pMCI[pHandle->bSelectedDrive];

  switch (bCmdID)
  {
  case MC_PROTOCOL_CMD_START_MOTOR:
    {
      MC_Status_t mc_status = MC_Core_GetStatus( pMCI );
      if ( mc_status == MC_IDLE || mc_status == MC_STOP )
      {
        (void) MC_Core_Start( pMCI );
      }
    }
    break;

  case MC_PROTOCOL_CMD_STOP_MOTOR:
  case MC_PROTOCOL_CMD_SC_STOP:
    {
      MC_Status_t mc_status = MC_Core_GetStatus( pMCI );
      if ( mc_status == MC_RUN )
      {
        (void) MC_Core_Stop( pMCI );
      }
    }
    break;

  case MC_PROTOCOL_CMD_STOP_RAMP:
    {
      MC_Status_t mc_status = MC_Core_GetStatus( pMCI );
      if ( mc_status == MC_RUN )
      {
        (void) MC_Core_Stop( pMCI );
      }
    }
    break;

  case MC_PROTOCOL_CMD_PING:
    {
	  /* Do nothing at the moment */
    }
    break;

  case MC_PROTOCOL_CMD_START_STOP:
    {
      MC_Status_t mc_status = MC_Core_GetStatus( pMCI );
      if ( mc_status == MC_IDLE || mc_status == MC_STOP )
      {
        (void) MC_Core_Start( pMCI );
      }
      else if ( mc_status == MC_RUN )
      {
        (void) MC_Core_Stop( pMCI );
      }
    }
    break;

  case MC_PROTOCOL_CMD_RESET:
    {
        (void) MC_Core_Reset( pMCI );
    }
    break;

  case MC_PROTOCOL_CMD_FAULT_ACK:
    {
      MC_Status_t mc_status = MC_Core_GetStatus( pMCI );
      if ( mc_status == MC_SPEEDFBKERROR || mc_status == MC_OVERCURRENT || mc_status == MC_VALIDATION_FAILURE ||
           mc_status == MC_VALIDATION_BEMF_FAILURE || mc_status == MC_VALIDATION_HALL_FAILURE ||
		   mc_status == MC_ADC_CALLBACK_FAILURE || mc_status == MC_LF_TIMER_FAILURE )
      {
        /* This call transitions the state to MC_STOP. Not an error state anymore and ready to start again. */
        (void) MC_Core_Stop( pMCI );
      }
    }
    break;

  case MC_PROTOCOL_CMD_ENCODER_ALIGN:
    {
	  /* Do nothing at the moment */
    }
    break;

  case MC_PROTOCOL_CMD_IQDREF_CLEAR:
    {
	  /* Do nothing at the moment */
    }
    break;

  default:
    {
    retVal = false;
	}
    break;
  }
  return retVal;
}

/**
  * @brief  Allow to execute a speed ramp command coming from the user.
  * @param  pHandle: Pointer on Handle structure of UI component.
  * @param  wFinalMecSpeedUnit: Final speed value expressed in the unit defined by #SPEED_UNIT.
  * @param  hDurationms: Duration of the ramp expressed in milliseconds.
  *         It is possible to set 0 to perform an instantaneous change in the value.
  *  @retval Return true if the command executed succesfully, otherwise false.
  */
__weak bool UI_ExecSpeedRamp(UI_Handle_t *pHandle, int32_t wFinalMecSpeedUnit, uint16_t hDurationms)
{
  MC_Handle_t * pMCI = pHandle->pMCI[pHandle->bSelectedDrive];

  if (wFinalMecSpeedUnit >= 0)
  {
    (void)MC_Core_SetDirection( pMCI, 0 );
    (void)MC_Core_SetSpeed( pMCI, wFinalMecSpeedUnit );
  }
  else
  {
    (void)MC_Core_SetDirection( pMCI, 1 );
    (void)MC_Core_SetSpeed( pMCI, (-wFinalMecSpeedUnit) );
  }
  return true;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/
