/**
  ******************************************************************************
  * @file    		:	SC88xx_GPIO_Def.C( V_0.4) Revision 4
  * @author  		:	Morph Team
  * @brief   		:	SC8815 initialization file.
  * @Description 	:	source file contains
								

  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 Supralax Electronics Pvt.Ltd
  * All rights reserved
  *
  ******************************************************************************
  */
#include "SC88xx_GPIO_Def.h"
#include "stm32g0xx_hal.h"
#include "stm32g081xx.h"


/* USER CODE BEGIN POWER_Private_Macros */
#define USBPD_GPIOx_CLK_ENABLE(__GPIO__)   do { if((__GPIO__) == GPIO_USBPD1_CE)   GPIO_USBPD1_CE_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_USBPD1_PSTOP) GPIO_USBPD1_PSTOP_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_USBPD1_INT) GPIO_USBPD1_INT_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_USBPD2_CE)   GPIO_USBPD2_CE_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_USBPD2_PSTOP)   GPIO_USBPD2_PSTOP_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_USBPD2_INT)     GPIO_USBPD2_INT_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_MPPT_CE)     GPIO_MPPT_CE_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_MPPT_PSTOP)      GPIO_MPPT_PSTOP_CLK_ENABLE(); else \
                                          if((__GPIO__) == GPIO_MPPT_INT)      GPIO_MPPT_INT_CLK_ENABLE();else \
                                          if((__GPIO__) == GPIO_BCHG_CE)      GPIO_BCHG_CE_CLK_ENABLE();else \
                                          if((__GPIO__) == GPIO_BCHG_PSTOP)      GPIO_BCHG_PSTOP_CLK_ENABLE();else \
                                          if((__GPIO__) == GPIO_BCHG_INT)      GPIO_BCHG_INT_CLK_ENABLE();} while(0)


/* GPIO Id. / GPIO port cross table */

static GPIO_TypeDef * SC88xx_GPIO_PORT[] = {
#ifdef _GPIO_USBPD1_Def_
		GPIO_USBPD1_CE_PORT,
		GPIO_USBPD1_PSTOP_PORT,
		GPIO_USBPD1_INT_PORT,
#endif

#ifdef _GPIO_USBPD2_Def_
		GPIO_USBPD2_CE_PORT,
		GPIO_USBPD2_PSTOP_PORT,
		GPIO_USBPD2_INT_PORT,
#endif

#ifdef _GPIO_MPPT_Def_
		GPIO_MPPT_CE_PORT,
		GPIO_MPPT_PSTOP_PORT,
		GPIO_MPPT_INT_PORT,
#endif

#ifdef _GPIO_BCHG_Def_
		GPIO_BCHG_CE_PORT,
		GPIO_BCHG_PSTOP_PORT,
		GPIO_BCHG_INT_PORT
#endif
};

/* GPIO Id. / GPIO pin cross table */

static const uint16_t SC88xx_GPIO_PIN[] = {

#ifdef _GPIO_USBPD1_Def_
		GPIO_USBPD1_CE_PIN,
		GPIO_USBPD1_PSTOP_PIN,
		GPIO_USBPD1_INT_PIN,
#endif

#ifdef _GPIO_USBPD2_Def_
		GPIO_USBPD2_CE_PIN,
		GPIO_USBPD2_PSTOP_PIN,
		GPIO_USBPD2_INT_PIN,
#endif

#ifdef _GPIO_MPPT_Def_
		GPIO_MPPT_CE_PIN,
		GPIO_MPPT_PSTOP_PIN,
		GPIO_MPPT_INT_PIN,
#endif

#ifdef _GPIO_BCHG_Def_
		GPIO_BCHG_CE_PIN,
		GPIO_BCHG_PSTOP_PIN,
		GPIO_BCHG_INT_PIN
#endif
};

/**
  * @function Name  : PD2_SC8815_Init
  * @param			: None
  * @retval 		: None
  * @brief 			: CE, PSTOP & INT pins intialization for PD2 handling
  */
/**
* @brief  Configures GPIO.
* @param  gpio Specifies the GPIO Pin to be configured.
*   This parameter can be one of following parameters:
*     @arg   GPIO_USBPD1_CE_PIN
*     @arg   GPIO_USBPD1_PSTOP_PIN
*     @arg   GPIO_USBPD1_INT_PIN
*     @arg   GPIO_USBPD2_CE_PIN
*     @arg   GPIO_USBPD2_PSTOP_PIN
*     @arg   GPIO_USBPD2_INT_PIN
*     @arg   GPIO_MPPT_CE
*     @arg   GPIO_MPPT_PSTOP
*     @arg   GPIO_MPPT_INT
*     @arg   GPIO_BCHG_CE
*     @arg   GPIO_BCHG_PSTOP
*     @arg   GPIO_BCHG_INT
* @retval None
  */
void SC88xx_GPIO_Init(GPIO_Id_Def_SC88xx gpio)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};

  /* Enable the GPIO clock */
  USBPD_GPIOx_CLK_ENABLE(gpio);

  /* Configure the GPIO pin */
  switch (gpio)
  {
  case GPIO_USBPD1_CE:
  case GPIO_USBPD1_PSTOP:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
	  /* Set GPIO to inactive state */
	  HAL_GPIO_WritePin(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio], GPIO_PIN_SET);
	  break;
  case GPIO_USBPD1_INT:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_IT_FALLING;
	  //GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
    break;
  case GPIO_USBPD2_CE:
  case GPIO_USBPD2_PSTOP:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
	  /* Set GPIO to inactive state */
	  HAL_GPIO_WritePin(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio], GPIO_PIN_SET);

	  break;
  case GPIO_USBPD2_INT:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_IT_FALLING;
	  //GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
	  break;
  case GPIO_MPPT_CE:
  case GPIO_MPPT_PSTOP:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
	  /* Set GPIO to inactive state */
	  HAL_GPIO_WritePin(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio], GPIO_PIN_SET);
	  break;
  case GPIO_MPPT_INT:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_IT_FALLING;
	  //GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
     break;
  case GPIO_BCHG_CE:
  case GPIO_BCHG_PSTOP:
	  GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull  = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
	  /* Set GPIO to inactive state */
	  HAL_GPIO_WritePin(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio], GPIO_PIN_SET);
  	  break;
   case GPIO_BCHG_INT:
	   GPIO_InitStruct.Pin   = SC88xx_GPIO_PIN[gpio];
	   GPIO_InitStruct.Mode  = GPIO_MODE_IT_FALLING;
	   //GPIO_InitStruct.Pull  = GPIO_PULLUP;
	   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	   HAL_GPIO_Init(SC88xx_GPIO_PORT[gpio], &GPIO_InitStruct);
      break;
  }
}


/**
* @brief  Reset  GPIO configuration.
* @param  gpio Specifies the GPIO Pin .
*   This parameter can be one of following parameters:
*     @arg   GPIO_USBPD1_CE_PIN
*     @arg   GPIO_USBPD1_PSTOP_PIN
*     @arg   GPIO_USBPD1_INT_PIN
*     @arg   GPIO_USBPD2_CE_PIN
*     @arg   GPIO_USBPD2_PSTOP_PIN
*     @arg   GPIO_USBPD2_INT_PIN
*     @arg   GPIO_MPPT_CE
*     @arg   GPIO_MPPT_PSTOP
*     @arg   GPIO_MPPT_INT
*     @arg   GPIO_BCHG_CE
*     @arg   GPIO_BCHG_PSTOP
*     @arg   GPIO_BCHG_INT
* @retval None
  */
void SC88xx_GPIO_DeInit(GPIO_Id_Def_SC88xx gpio)
{
  HAL_GPIO_DeInit(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio]);
}

/**
* @brief  Turns selected GPIO On.
* @param  gpio Specifies the GPIO Pin to be configured.
*   This parameter can be one of following parameters:
*     @arg   GPIO_USBPD1_CE_PIN
*     @arg   GPIO_USBPD1_PSTOP_PIN
*     @arg   GPIO_USBPD1_INT_PIN
*     @arg   GPIO_USBPD2_CE_PIN
*     @arg   GPIO_USBPD2_PSTOP_PIN
*     @arg   GPIO_USBPD2_INT_PIN
*     @arg   GPIO_MPPT_CE
*     @arg   GPIO_MPPT_PSTOP
*     @arg   GPIO_MPPT_INT
*     @arg   GPIO_BCHG_CE
*     @arg   GPIO_BCHG_PSTOP
*     @arg   GPIO_BCHG_INT
* @retval None
  */
void SC88xx_GPIO_On(GPIO_Id_Def_SC88xx gpio)
{
	/* Configure the GPIO pin */
	HAL_GPIO_WritePin(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio], GPIO_PIN_SET);
}

/**
* @brief  Turns selected GPIO Off.
* @param  gpio Specifies the GPIO Pin to be configured.
*   This parameter can be one of following parameters:
*     @arg   GPIO_USBPD1_CE_PIN
*     @arg   GPIO_USBPD1_PSTOP_PIN
*     @arg   GPIO_USBPD1_INT_PIN
*     @arg   GPIO_USBPD2_CE_PIN
*     @arg   GPIO_USBPD2_PSTOP_PIN
*     @arg   GPIO_USBPD2_INT_PIN
*     @arg   GPIO_MPPT_CE
*     @arg   GPIO_MPPT_PSTOP
*     @arg   GPIO_MPPT_INT
*     @arg   GPIO_BCHG_CE
*     @arg   GPIO_BCHG_PSTOP
*     @arg   GPIO_BCHG_INT
* @retval None
  */
void SC88xx_GPIO_Off(GPIO_Id_Def_SC88xx gpio)
{
	HAL_GPIO_WritePin(SC88xx_GPIO_PORT[gpio], SC88xx_GPIO_PIN[gpio], GPIO_PIN_RESET);
}
