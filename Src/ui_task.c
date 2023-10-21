/**
  ******************************************************************************
  * @file    ui_task.c
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file implementes user interface tasks definition
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

/* Includes ------------------------------------------------------------------*/
/* Pre-compiler coherency check */

#include "ui_task.h"
#include "mc_config.h"

MCP_Handle_t * pMCP = MC_NULL;
MCP_Handle_t MCP_UI_Params;

void UI_TaskInit( uint32_t* pUICfg, uint8_t bMCNum, MC_Handle_t * pMCIList[], const char* s_fwVer )
{

    pMCP = &MCP_UI_Params;
    pMCP->_Super = UI_Params;

    UFCP_Init( & pUSART );
    MCP_Init(pMCP, (FCP_Handle_t *) & pUSART, & UFCP_Send, & UFCP_Receive, & UFCP_AbortReceive, s_fwVer);
    UI_Init( &pMCP->_Super, bMCNum, pMCIList, pUICfg ); /* Initialize UI and link MC components */

}

/******************* (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/
