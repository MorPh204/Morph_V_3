/**
  ******************************************************************************
  * @file    		:	SC88xx_GPIO_Def.h( V_0.4) Revision 4
  * @author  		:	Morph Team
  * @brief   		:	SC8815 initialization file.
  * @Description 	:	source file contains
								1. Register address for SC8815.
								2. Register Default contents for SC8815.
								3. functions to manage SC8815(through I2C).

  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 Supralax Electronics Pvt.Ltd
  * All rights reserved
  *
  ******************************************************************************
  */
#ifndef SC88XX_GPIO_DEF_H_
#define SC88XX_GPIO_DEF_H_

#define  _GPIO_USBPD1_Def_ 1
#define  _GPIO_USBPD2_Def_ 1


/* USER CODE BEGIN POWER_Private_Constants */
typedef enum
{
    GPIO_USBPD1_CE     = 0,   /*    */
    GPIO_USBPD1_PSTOP  = 1,   /*<    */
	GPIO_USBPD1_INT	   = 2,    /*<    */
	GPIO_USBPD2_CE     = 3,   /*<    */
    GPIO_USBPD2_PSTOP  = 4,   /*<    */
	GPIO_USBPD2_INT	   = 5,    /*<    */
    GPIO_MPPT_CE       = 6,   /*<    */
    GPIO_MPPT_PSTOP    = 7,   /*< 	 */
	GPIO_MPPT_INT	   = 8,    /*<    */
    GPIO_BCHG_CE       = 9,   /*<    */
    GPIO_BCHG_PSTOP    = 10,   /*<    */
	GPIO_BCHG_INT	   = 11,    /*<    */
} GPIO_Id_Def_SC88xx;

/** @defgroup POWER_Private_Constants Private Constants
* @{
*/
/* USER CODE BEGIN POWER_Private_Constants */

#ifdef _GPIO_USBPD1_Def_
/*
 * USB PD port 0(i.e. USBPD1) related SC8815 GPIO initialization
 */
#define GPIO_USBPD1_CE_PIN                    GPIO_PIN_5  /* Port A pin 5 */
#define GPIO_USBPD1_CE_PORT                   GPIOA
#define GPIO_USBPD1_CE_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()

#define GPIO_USBPD1_PSTOP_PIN                 GPIO_PIN_6  /*  Port A pin 6 */
#define GPIO_USBPD1_PSTOP_PORT                GPIOA
#define GPIO_USBPD1_PSTOP_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()

#define GPIO_USBPD1_INT_PIN                    GPIO_PIN_7  /*  Port A pin 7 */
#define GPIO_USBPD1_INT_PORT                   GPIOA
#define GPIO_USBPD1_INT_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()
#endif

#ifdef _GPIO_USBPD2_Def_
/*
 * USB PD port 1(i.e. USBPD2) related SC8815 GPIO initialization
 */
#define GPIO_USBPD2_CE_PIN                    GPIO_PIN_11  /*  Port C pin 11 */
#define GPIO_USBPD2_CE_PORT                   GPIOC
#define GPIO_USBPD2_CE_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()

#define GPIO_USBPD2_PSTOP_PIN                 GPIO_PIN_12  /* Port C pin 12 */
#define GPIO_USBPD2_PSTOP_PORT                GPIOC
#define GPIO_USBPD2_PSTOP_CLK_ENABLE()        __HAL_RCC_GPIOC_CLK_ENABLE()

#define GPIO_USBPD2_INT_PIN                   GPIO_PIN_13  /* Port C pin 13 */
#define GPIO_USBPD2_INT_PORT                  GPIOC
#define GPIO_USBPD2_INT_CLK_ENABLE()          __HAL_RCC_GPIOC_CLK_ENABLE()
#endif


#ifdef _GPIO_MPPT_Def_
/*
 * MPPT related  related to SC8815 GPIO initialization
 */
#define GPIO_MPPT_CE_PIN                    //GPIO_PIN_1  /* PA.01 */
#define GPIO_MPPT_CE_PORT                   GPIOA
#define GPIO_MPPT_CE_CLK_ENABLE()           //__HAL_RCC_GPIOA_CLK_ENABLE()

#define GPIO_MPPT_PSTOP_PIN                    //GPIO_PIN_1  /* PA.01 */
#define GPIO_MPPT_PSTOP_PORT                 GPIOA
#define GPIO_MPPT_PSTOP_CLK_ENABLE()           //__HAL_RCC_GPIOA_CLK_ENABLE()

#define GPIO_MPPT_INT_PIN                    //GPIO_PIN_1  /* PA.01 */
#define GPIO_MPPT_INT_PORT                   GPIOA
#define GPIO_MPPT_INT_CLK_ENABLE()           //__HAL_RCC_GPIOA_CLK_ENABLE()
#endif

#ifdef _GPIO_BCHG_Def_
/*
 * Battery charging related to SC8813 GPIO initialization
 */
#define GPIO_BCHG_CE_PIN                    //GPIO_PIN_1  /* PA.01 */
#define GPIO_BCHG_CE_PORT                   //GPIOA
#define GPIO_BCHG_CE_CLK_ENABLE()           //__HAL_RCC_GPIOA_CLK_ENABLE()

#define GPIO_BCHG_PSTOP_PIN                    //GPIO_PIN_1  /* PA.01 */
#define GPIO_BCHG_PSTOP_PORT                   //GPIOA
#define GPIO_BCHG_PSTOP_CLK_ENABLE()           //__HAL_RCC_GPIOA_CLK_ENABLE()

#define GPIO_BCHG_INT_PIN                    //GPIO_PIN_1  /* PA.01 */
#define GPIO_BCHG_INT_PORT                   //GPIOA
#define GPIO_BCHG_INT_CLK_ENABLE()           //__HAL_RCC_GPIOA_CLK_ENABLE()
#endif

/* functions to initialize the GPIO*/
void     SC88xx_GPIO_Init(GPIO_Id_Def_SC88xx gpio);
void     SC88xx_GPIO_DeInit(GPIO_Id_Def_SC88xx gpio);
void     SC88xx_GPIO_On(GPIO_Id_Def_SC88xx gpio);
void     SC88xx_GPIO_Off(GPIO_Id_Def_SC88xx gpio);



#endif /* SC88XX_GPIO_DEF_H_ */
