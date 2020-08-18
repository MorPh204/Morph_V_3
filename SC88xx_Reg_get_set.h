/**
  ******************************************************************************
  * @file    SC88xx_Reg_get_set.h( V_0.4) Revision 4
  * @author  Morph Team
  * @brief	 This header file include Functions that are directly act on the register(Hardware)
  * 			- Note this header file will contain functions related to Both SC8815 and SC8813
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 Supralax Electronics Pvt.Ltd
  * All rights reserved
  *
  ******************************************************************************
  */
#ifndef SC88XX_REG_GET_SET_H_
#define SC88XX_REG_GET_SET_H_

#ifdef __cplusplus
extern "C" {
#endif
/* #include files -----------------------------------------------------------*/
#include "stm32g0xx_hal.h"
/* Exported types ------------------------------------------------------------*/
#include "SC88xx_Reg_Def.h"
/* Exported constants --------------------------------------------------------*/

/*######################## SC8815 modules#########################*/
/*################################## SECTION 1 PART 1 ########################*/

typedef struct
{
	uint8_t VBUS_INT[2];
	uint8_t VBUS_EXT[2];
	uint8_t VBUS_FB[2];
	uint8_t VBAT_FB[2];
	uint8_t IBUS_VAL[2];
	uint8_t IBAT_VAL[2];
	uint8_t ADIN[2];
}SC8815_REG_val;


/*################################## SECTION 2 PART 1 ########################*/





/*################################## SECTION 3 PART 1 ########################*/
/* Initialization functions for SC8815*/
void USBPD_SC88xx_Init(uint8_t Port_num);
SC88xx_StatusTypeDef USBPD_SC88xx_Default_5V_set(uint8_t Port_num);
SC88xx_StatusTypeDef USBPD_SC_SET_V_C(uint8_t Port_num, float Voltage_IN_V, float Current_IN_C);

#ifdef __cplusplus
}
#endif

#endif /* SC88XX_REG_GET_SET_H_ */
