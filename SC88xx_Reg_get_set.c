/**
  ******************************************************************************
  * @file    		:	SC88xx_Reg_get_set.c( V_0.4) Revision 4
  * @author  		:	Morph Team
  * @brief   		:	SC8815 initialization file.
  * @Description 	:	source file contains
								1. Register address for SC8815.
								2. Register Default contents for SC8815.
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

/*############################ Includes ###########################*/
#include "SC88xx_Reg_get_set.h"
#include "SC88xx_Reg_Def.h"
#include "SC88xx_GPIO_Def.h"
#include "SC8815_Default_Reg.h"
#include "SC8813_Default_Reg.h"
#include "USBPD_SC8815_HW.h"
#include "MPPT_SC8815_HW.h"
#include "SC8813_HW.h"


/*############################ Variables ##########################*/

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef i2c2;

SC8815_REG_val read_reg_val;
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ SECTION 1 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*
*  @brief : SECTION 1 consists of set of static Functions used with in this header file
*/
/* Module wise oparation for SC88XX device
	MODULE 0: (done with update)
		@brief : used to intialize the Southchip and I2C module
	MODULE 1:
		@brief : used to set the register contents of the SC8815/SC8813
	MODULE 2:
		@brief : used to read the register content from SC8815/SC8813
	MODULE 3: (done with update)
		@brief : used to set the Mode Of SC8815/SC8813
	MODULE 4:
		@brief : I2C Error Handler
*/
/*############################ 		MODULE 0	############################*/
/* primary functions to initialize I2C module */
static void I2C2_Init(void);
static void PD1_SC8815_GPIO_Init(void);
static void PD2_SC8815_GPIO_Init(void);
static void PD_GPIO_Init(uint8_t port_num);

/*############################ 		MODULE 1	############################*/
/* Primary functions to set data to SC8815/SC8813 registers*/
static void VBAT_SET_set_reg(uint8_t Vbat);
static void VBUS_INT_set_reg(uint8_t Voltage_ref, uint8_t Voltage_ref_1);
static void VBUS_EXT_set_reg(uint8_t Voltage_ref, uint8_t Voltage_ref_1);
static void IBUS_set_reg(uint8_t IBUS_current);
static void IBAT_set_reg(uint8_t IBAT_current);
static void VINREG_SET_set_reg(uint8_t Vinreg);
static void RATIO_set_reg(uint8_t Ratio);
static void CTRL0_set_reg(uint8_t Ctrl0);
static void CTRL1_set_reg(uint8_t Ctrl1);
static void CTRL2_set_reg(uint8_t Ctrl2);
static void CTRL3_set_reg(uint8_t Ctrl3);
static void MASK_set_reg(uint8_t Mask);
/*############################ 		MODULE 2	############################*/
/*primary functions to read data from SC8815/SC8813*/
static uint8_t VBAT_SET_get_reg(void);
static SC8815_REG_val VBUS_INT_get_reg(void);
static SC8815_REG_val VBUS_EXT_get_reg(void);
static uint8_t IBUS_LIM_get_reg(void);
static uint8_t IBAT_LIM_get_reg(void);
static uint8_t VINREG_SET_get_reg(void);
static uint8_t RATIO_get_reg(void);
static uint8_t CTRL0_get_reg(void);
static uint8_t CTRL1_get_reg(void);
static uint8_t CTRL2_get_reg(void);
static uint8_t CTRL3_get_reg(void);
static SC8815_REG_val VBUS_FB_get_reg(void);
static SC8815_REG_val VBAT_FB_get_reg(void);
static SC8815_REG_val IBUS_VAL_get_reg(void);
static SC8815_REG_val IBAT_VAL_get_reg(void);
static SC8815_REG_val ADIN_get_reg(void);
static uint8_t STATUS_get_reg(void);
static uint8_t MASK_get_reg(void);
/*############################ 		MODULE 3	############################*/
/*functions to set mode of SC8815 and channel to communicate*/
static void PD1_SC_standby_mode(void);
static void PD1_SC_shutdown_mode(void);
static void PD1_SC_active_mode(void);
static void PD2_SC_standby_mode(void);
static void PD2_SC_shutdown_mode(void);
static void PD2_SC_active_mode(void);
static void I2C_MUX_channel0_select(void);
static void I2C_MUX_channel1_select(void);
static void I2C_MUX_channel2_select(void);
static void I2C_MUX_channel3_select(void);
/*############################ 		MODULE 4	############################*/
static void CHG_MODE_INT(uint8_t port_num);
static void CHG_MODE_EXT(uint8_t port_num);
static void DIS_CHG_MODE_INT(uint8_t port_num);
static void DIS_CHG_MODE_EXT(uint8_t port_num);
static void SC88xx_Mode_set(uint8_t port_num, SC88xx_ModeTypedef mode);
/*############################ 		MODULE 5	############################*/
/*secondary functions to set value of the registers*/
static void CTRLx_set(uint8_t ctrl0, uint8_t ctrl1, uint8_t ctrl2, uint8_t ctrl3);
static float VBUS_ref_val_set(float VBUS_voltage);
static void VBUS_EXT_set(float VBUS_ref);
static void VBUS_INT_set(float VBUS_ref);

/*############################ 		MODULE 6	############################*/



/*############################ 		MODULE 7	############################*/
static void SC_I2C_Error_Handler(void);


/*
 * Static Function Defination starts here
 */

/*################################################################ 		MODULE 0	#########################################################################*/
/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void I2C2_Init(void){

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  i2c2.Instance = I2C2;
  i2c2.Init.Timing = 0x00303D5B;
  i2c2.Init.OwnAddress1 = 0;
  i2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  i2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  i2c2.Init.OwnAddress2 = 0;
  i2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  i2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  i2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&i2c2) != HAL_OK)
   {
	 SC_I2C_Error_Handler();
   }
   /** Configure Analogue filter
   */
   if (HAL_I2CEx_ConfigAnalogFilter(&i2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
   {
	 SC_I2C_Error_Handler();
   }
   /** Configure Digital filter
   */
   if (HAL_I2CEx_ConfigDigitalFilter(&i2c2, 0) != HAL_OK)
   {
	 SC_I2C_Error_Handler();
   }
   /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */
}

/**
  * @function Name  : PD1_SC8815_Init
  * @param			: None
  * @retval 		: None
  * @brief 			: CE, PSTOP & INT pins intialization for PD1 handling
  */
 static void PD1_SC8815_GPIO_Init(void){
	 GPIO_InitTypeDef GPIO_InitStruct = {0};

	 /* GPIO Ports Clock Enable */
	 __HAL_RCC_GPIOA_CLK_ENABLE();

	 /*Configure GPIO pin Output Level */
	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);
	 /*
	  * GPIOA & GPIO_PIN_5 configured as PD1_CE
	  * GPIOA & GPIO_PIN_6 configured as PD1_PSTOP
	  */
	  /*Configure GPIO pins : PA5 PA6 */
      GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
      /*
      * GPIOA & GPIO_PIN_7 configured as PD1_INT
       */
      /*Configure GPIO pin : PA7 */
        GPIO_InitStruct.Pin = GPIO_PIN_7;
        GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/**
  * @function Name  : PD2_SC8815_Init
  * @param			: None
  * @retval 		: None
  * @brief 			: CE, PSTOP & INT pins intialization for PD2 handling
  */
 static void PD2_SC8815_GPIO_Init(void){
	 GPIO_InitTypeDef GPIO_InitStruct = {0};
	 /* GPIO Ports Clock Enable */
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);
	  /*
	  	  * GPIOC & GPIO_PIN_11 configured as PD2_CE
	  	  * GPIOC & GPIO_PIN_12 configured as PD2_PSTOP
	  	  */
	  /*Configure GPIO pins : PC11 PC12 */
	   GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
	   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   GPIO_InitStruct.Pull = GPIO_NOPULL;
	   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	   /*
	    * GPIOC & GPIO_PIN_13 configured as PD2_INT
	     */
	    /*Configure GPIO pin : PC13 */
	      GPIO_InitStruct.Pin = GPIO_PIN_13;
	      GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	      GPIO_InitStruct.Pull = GPIO_NOPULL;
	      HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

 /**
   * @function Name  : PD_GPIO_Init
   * @param			: uint32_t port_num
   * @retval 		: None
   * @brief 			: CE, PSTOP & INT pins intialization for PD2 handling
   */
 static void PD_GPIO_Init(uint8_t port_num){
	 switch(port_num){
	 case PD1_SC8815:
		 PD1_SC8815_GPIO_Init();
		 break;
	 case PD2_SC8815:
		 PD2_SC8815_GPIO_Init();
		 break;
	 default:
		 SC_I2C_Error_Handler();
	 }

 }

 /*#################################################################	END of MODULE 0	#########################################################################*/


 /*################################################################ 		MODULE 1	#########################################################################*/

 /* Primary functions to set data to SC8815/SC8813 registers*/
 /**
   * @function Name  : VBAT_SET_set_reg
   * @param			: Vbat content to set on SC8815/SC8813
   * @retval 		: None
   * @brief 			: VBAT register to set SC8815/SC8813 to operate using External Reference
   * 						-Note: Set this Register only when PATOP of SC8815 is HIGH (i.e. in standby mode)
   */
 static void VBAT_SET_set_reg(uint8_t Vbat){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= VBAT_SET_ADDRESS;
 	data_arr[1]= Vbat;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 100)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : VBUS_INT_set_reg
   * @param			: uint8_t Voltage_ref, uint8_t Voltage_ref_1
   * @retval 		: None
   * @brief 			: Function to update VBUS internal Reference voltage
 						-Note : final Voltage depends VBUS_RATIO in RATIO register (refer Schimatic and Dataseet for more info.)
   */
 static void VBUS_INT_set_reg(uint8_t Voltage_ref, uint8_t Voltage_ref_1){
 	uint8_t data_arr[3];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= VBUSREF_I_SET_ADDRESS;
 	data_arr[1]= Voltage_ref;
 	data_arr[2]= Voltage_ref_1;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 3, 100)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : VBUS_EXT_set_reg
   * @param			: uint8_t Voltage_ref, uint8_t Voltage_ref_1
   * @retval 		: None
   * @brief 			: Function to update VBUS External Reference voltage
 						-Note : final Voltage depends Feed back connected across the VBUS. (refer Schimatic and Dataseet for more info.)
   */
 static void VBUS_EXT_set_reg(uint8_t Voltage_ref, uint8_t Voltage_ref_1){
 	uint8_t data_arr[3];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= VBUSREF_E_SET_ADDRESS;
 	data_arr[1]= Voltage_ref;
 	data_arr[2]= Voltage_ref_1;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 3, 100)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : IBUS_set_reg
   * @param			: uint8_t IBUS_current
   * @retval 		: None
   * @brief 			: Function to Update IBUS current Value.
 						-Note : final current limit depends on IBUS_RATIO in RATIO register(refer to datasheet for more info)
 						-Note : IBAT_LIM_SET must be >=300mA
   */
 static void IBUS_set_reg(uint8_t IBUS_current){
 	uint8_t data_arr[3];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= IBUS_LIM_SET_ADDRESS;
 	data_arr[1]= IBUS_current;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 100)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : IBAT_set_reg
   * @param			: uint8_t IBAT_current
   * @retval 		: None
   * @brief 			: Function to Update IBAT current Value.
 						-Note : final current limit depends on IBAT_RATIO in RATIO register(refer to datasheet for more info)
 						-IBAT_LIM_SET must be >=300mA
   */
 static void IBAT_set_reg(uint8_t IBAT_current){
 	uint8_t data_arr[3];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= IBAT_LIM_SET_ADDRESS;
 	data_arr[1]= IBAT_current;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 100)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : VINREG_SET_set_reg
   * @param			: uint8_t Vinreg
   * @retval 		: None
   * @brief 			: Vin Regulation set register.
   */
 static void VINREG_SET_set_reg(uint8_t Vinreg){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= VINREG_SET_ADDRESS;
 	data_arr[1]= Vinreg;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : RATIO_set_reg
   * @param			: uint8_t ratio
   * @retval 		: None
   * @brief 			: RATIO SET register to set IBAT_RATIO, IBUS_RATIO, VBAT_MON_RATIO & VBUS_RATIO
 						-Note: Set this Register only when PSTOP of SC8815 is HIGH (i.e. in standby mode)
   */
 static void RATIO_set_reg(uint8_t Ratio){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= RATIO_ADDRESS;
 	data_arr[1]= Ratio;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : CTRL0_set_reg
   * @param			: uint8_t Ctrl0
   * @retval 		: None
   * @brief 			: CTRL 0 set register to set EN_OTG,AC_DET(only for SC8813), VINREG_RATIO, FREQ_SET &DT_SET
 						-Note: Set this Register only when PSTOP of SC8815 is HIGH (i.e. in standby mode)
   */
 static void CTRL0_set_reg(uint8_t Ctrl0){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= CTRL0_SET_ADDRESS;
 	data_arr[1]= Ctrl0;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : CTRL1_set_reg
   * @param			: uint8_t Ctrl1
   * @retval 		: None
   * @brief 			: CTRL 1 set register to set ICHAR_SEL, DIS_Trickle, DIS_Term, FB_SEL, Trickle _SET & DIS_OVP
 						-Note: Set this Register only when PSTOP of SC8815 is HIGH (i.e. in standby mode)
   */
 static void CTRL1_set_reg(uint8_t Ctrl1){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= CTRL1_SET_ADDRESS;
 	data_arr[1]= Ctrl1;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : CTRL2_set_reg
   * @param			: uint8_t Ctrl2
   * @retval 		: None
   * @brief 			: CTRL 2 set register to set FACTORY, EN_DITHER & SLEW_SET
 						-Note: Set this Register only when PSTOP of SC8815 is HIGH (i.e. in standby mode)
   */
 static void CTRL2_set_reg(uint8_t Ctrl2){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= CTRL2_SET_ADDRESS;
 	data_arr[1]= Ctrl2;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : CTRL3_set_reg
   * @param			: uint8_t Ctrl3
   * @retval 		: None
   * @brief 			: CTRL 3 set register to set EN_PGATE, EN_PGATE, AD_START, ILIM_BW_SEL, LOOP_SET, DIS_ShortFoldBack, EOC_SET & EN_PFM
 						-Note: Set this Register only when PSTOP of SC8815 is HIGH (i.e. in standby mode)
   */
 static void CTRL3_set_reg(uint8_t Ctrl3){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= CTRL3_SET_ADDRESS;
 	data_arr[1]= Ctrl3;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /**
   * @function Name  : MASK_set_reg
   * @param			: uint8_t Mask
   * @retval 		: None
   * @brief 			: MASK set register to set
   */
 static void MASK_set_reg(uint8_t Mask){
 	uint8_t data_arr[2];
 	uint8_t *data=&data_arr[0];
 	data_arr[0]= MASK_ADDRESS;
 	data_arr[1]= Mask;
 	if (HAL_OK != HAL_I2C_Master_Transmit(&i2c2, SC_I2C_ADDRESS, data, 2, 1000)){
 		SC_I2C_Error_Handler();
 	}
 }

 /*#################################################################	END of MODULE 1	#########################################################################*/

 /*################################################################ 		MODULE 2	#########################################################################*/

 /*primary functions to read data from SC8815/SC8813*/
 /**
   * @function Name  : VBAT_SET_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: VBAT register read value
   */
 static uint8_t VBAT_SET_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, VBAT_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : VBUS_INT_get_reg
   * @param			: None
   * @retval 		: *uint8_t
   * @brief 			: VBUS_INT register read value
 							-Note : final Voltage depends VBUS_RATIO in RATIO register (refer Schimatic and Dataseet for more info.)
   */
 static SC8815_REG_val VBUS_INT_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, VBUSREF_I_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : VBUS_EXT_get_reg
   * @param			: None
   * @retval 		: *uint8_t
   * @brief 			: VBAT register read value
 						-Note : final Voltage depends Feed back connected across the VBUS. (refer Schimatic and Dataseet for more info.)
   */
 static SC8815_REG_val VBUS_EXT_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, VBUSREF_E_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : IBUS_LIM_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: IBUS register read value
 						-Note : final current limit depends on IBUS_RATIO in RATIO register(refer to datasheet for more info)
   */
 static uint8_t IBUS_LIM_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, IBUS_LIM_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : IBAT_LIM_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: IBAT register read value
 						-Note : final current limit depends on IBAT_RATIO in RATIO register(refer to datasheet for more info)
   */
 static uint8_t IBAT_LIM_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, IBAT_LIM_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : VINREG_SET_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: VINREG_SET register read value
   */
 static uint8_t VINREG_SET_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, VINREG_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : RATIO_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: RATIO register read value
   */
 static uint8_t RATIO_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, RATIO_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : CTRL0_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: CTRL0 register read value
   */
 static uint8_t CTRL0_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, CTRL0_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : CTRL1_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: CTRL1 register read value
   */
 static uint8_t CTRL1_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, CTRL1_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : CTRL2_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: CTRL2 register read value
   */
 static uint8_t CTRL2_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, CTRL2_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : CTRL3_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: CTRL3 register read value
   */
 static uint8_t CTRL3_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, CTRL3_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : VBUS_FB_get_reg
   * @param			: None
   * @retval 		: uint8_t*
   * @brief 			: VBUS_FB register read value
 						-VBUS voltage is depend on VBUS_RATIO In RATIO register
   */
 static SC8815_REG_val VBUS_FB_get_reg(void){
 	uint8_t read_size=2;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, VBUS_FB_VALUE_ADDRESS, 2, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : VBAT_FB_get_reg
   * @param			: None
   * @retval 		: uint8_t*
   * @brief 			: VBAT_FB register read value
 						-VBAT voltage is depend on VBAT_MON_RATIO In RATIO register
   */
 static SC8815_REG_val VBAT_FB_get_reg(void){
 	uint8_t read_size=2;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, VBAT_FB_VALUE_ADDRESS, 2, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : IBUS_VAL_get_reg
   * @param			: None
   * @retval 		: *uint8_t
   * @brief 			: IBUS register read value
 						-IBUS current is depend on IBUS_RATIO In RATIO register
   */
 static SC8815_REG_val IBUS_VAL_get_reg(void){
 	uint8_t read_size=2;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, IBUS_VALUE_ADDRESS, 2, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : IBAT_VAL_get_reg
   * @param			: None
   * @retval 		: *uint8_t
   * @brief 			: IBUS register read value
 						-IBUS current is depend on IBAT_RATIO In RATIO register
   */
 static SC8815_REG_val IBAT_VAL_get_reg(void){
 	uint8_t read_size=2;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, IBAT_VALUE_ADDRESS, 2, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : ADIN_get_reg
   * @param			: None
   * @retval 		: *uint8_t
   * @brief 			: ADIN register read value
   */
 static SC8815_REG_val ADIN_get_reg(void){
 	uint8_t read_size=2;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, ADIN_VALUE_ADDRESS, 2, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return read_reg_val;
 }

 /**
   * @function Name  : STATUS_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: STATUS register read value
   */
 static uint8_t STATUS_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, IBAT_LIM_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

 /**
   * @function Name  : MASK_get_reg
   * @param			: None
   * @retval 		: uint8_t
   * @brief 			: MASK register read value
   */
 static uint8_t MASK_get_reg(void){
 	uint8_t read_size=1;
 	uint8_t RX_data_arr[read_size];
 	uint8_t *data=&RX_data_arr[0];
 	 if (HAL_OK != HAL_I2C_Mem_Read_IT(&i2c2, SC_I2C_ADDRESS, IBAT_LIM_SET_ADDRESS, 1, data, read_size)){
 		 SC_I2C_Error_Handler();
 	 }
 	 return RX_data_arr[0];
 }

  /*#################################################################	END of MODULE 2	#########################################################################*/

 /*################################################################ 		MODULE 3	#########################################################################*/

 /***********************functions to control modes of SC8815************************/
 /**
   * @function Name  : PD1_SC_standby_mode
   * @param			: None
   * @retval 		: None
   * @brief 			: To set PD1 SC8815 to standby mode
   */
 static void PD1_SC_standby_mode(void){
 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);/*setting the CE pin to Low enable the SC8815 */
 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);/* setting the PSTOP pin of SC8815 to HIGH(When CE is Low) indicates the standby mode*/
 }
 /**
   * @function Name  : PD1_SC_shutdown_mode
   * @param			: None
   * @retval 		: None
   * @brief 			: To set PD1 SC8815 to Shutdown mode
   */
 static void PD1_SC_shutdown_mode(void){
 	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);/*setting the SC8815 to stop mode by setting CE  to HIGH */
 	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); /*setting the SC8815 to stop mode by setting PSTOP to HIGH */
 }
 /**
   * @function Name  : PD1_SC_active_mode
   * @param			: None
   * @retval 		: None
   * @brief 			: To set PD1 SC8815 to active mode
   */
 static void PD1_SC_active_mode(void){
 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);/*setting the CE pin to Low enable the SC8815 */
 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);/* setting the PSTOP pin of SC8815 to HIGH(When CE is Low) indicates the Active mode*/
 }
 /**
   * @function Name  : PD2_SC_standby_mode
   * @param			: None
   * @retval 		: None
   * @brief 			: To set PD1 SC8815 to standby mode
   */
 static void PD2_SC_standby_mode(void){
 	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);/*setting the CE pin to Low enable the SC8815 */
 	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);/* setting the PSTOP pin of SC8815 to HIGH(When CE is Low) indicates the standby mode*/
 }
 /**
   * @function Name  : PD1_SC_shutdown_mode
   * @param			: None
   * @retval 		: None
   * @brief 			: To set PD1 SC8815 to Shutdown mode
   */
 static void PD2_SC_shutdown_mode(void){
 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);/*setting the SC8815 to stop mode by setting CE  to HIGH */
 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET); /*setting the SC8815 to stop mode by setting PSTOP to HIGH */
 }
 /**
   * @function Name  : PD1_SC_active_mode
   * @param			: None
   * @retval 		: None
   * @brief 			: To set PD1 SC8815 to active mode
   */
 static void PD2_SC_active_mode(void){
 	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);/*setting the CE pin to Low enable the SC8815 */
 	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);/* setting the PSTOP pin of SC8815 to HIGH(When CE is Low) indicates the Active mode*/
 }
 /**
   * @function Name  : I2C_MUX_channel0_select
   * @param			: None
   * @retval 		: None
   * @brief 			: To select Channel0 for PD Power port (i.e SC8815). USBPD0 port selection
   */
 static void I2C_MUX_channel0_select(void){

 }
 /**
   * @function Name  : I2C_MUX_channel1_select
   * @param			: None
   * @retval 		: None
   * @brief 			: To select Channel1 for PD Power port (i.e SC8815). USBPD1 port selection
   */
 static void I2C_MUX_channel1_select(void){

 }
 /**
   * @function Name  : I2C_MUX_channel2_select
   * @param			: None
   * @retval 		: None
   * @brief 			: To select Channel2 for MPPT
   */
 static void I2C_MUX_channel2_select(void){

 }

 /**
   * @function Name  : I2C_MUX_channel3_select
   * @param			: None
   * @retval 		: None
   * @brief 			: To select Channel3 for SC8813 Battery charging unit
   */
 static void I2C_MUX_channel3_select(void){


 }

  /*#################################################################	END of MODULE 3	#########################################################################*/

 /*################################################################ 		MODULE 4	#########################################################################*/

 /**
   * @function Name  : CHG_MODE_INT
   * @param			: None
   * @retval 		: None
   * @brief 			: Register content setting for different modes of operation
   * 					-Note : Refer the SECTION 1 PART3 of SC8815.h.(to know more info about register setting)
   */
 static void CHG_MODE_INT(uint8_t port_num){

 	if(port_num==PD1_SC8815 || port_num==PD2_SC8815 || port_num==MPPT_SC8815){
 		CTRL0_set_reg(SC8815_CHG_INT_CTRL0);
 		CTRL1_set_reg(SC8815_CHG_INT_CTRL1);
 		VBAT_SET_set_reg(SC8815_CHG_INT_VBAT);
 	}else {
 		CTRL0_set_reg(SC8813_CHG_INT_CTRL0);
 		CTRL1_set_reg(SC8813_CHG_INT_CTRL1);
 		VBAT_SET_set_reg(SC8813_CHG_INT_VBAT);
 	}

 }

 /**
   * @function Name  : CHG_MODE_EXT
   * @param			: None
   * @retval 		: None
   * @brief 			: Register content setting for different modes of operation
   * 					-Note : Refer the SECTION 1 PART3 of SC88xx.h.(to know more info about register setting)
   */
 static void CHG_MODE_EXT(uint8_t port_num){
 	if(port_num==PD1_SC8815 || port_num==PD2_SC8815 || port_num==MPPT_SC8815){
 		CTRL0_set_reg(SC8813_CHG_INT_CTRL0);
 		CTRL1_set_reg(SC8815_CHG_INT_CTRL1);
 		VBAT_SET_set_reg(SC8815_CHG_EXT_VBAT);
 	}else {
 		CTRL0_set_reg(SC8813_CHG_INT_CTRL0);
 		CTRL1_set_reg(SC8813_CHG_INT_CTRL1);
 		VBAT_SET_set_reg(SC8813_CHG_EXT_VBAT);
 	}
 }

 /**
   * @function Name  : SC88xx_Mode_set
   * @param			: None
   * @retval 		: None
   * @brief 			: Register content setting for different modes of operation
   * 					-Note : Refer the SECTION 1 PART3 of SC8815.h.(to know more info about register setting)
   */
 static void DIS_CHG_MODE_INT(uint8_t port_num){
 	if(port_num==PD1_SC8815 || port_num==PD2_SC8815 || port_num==MPPT_SC8815){
 		CTRL0_set_reg(SC8815_DISCHG_INT_CTRL0);
 		CTRL1_set_reg(SC8815_DISCHG_INT_CTRL1);
 	}else {
 		CTRL0_set_reg(SC8813_DISCHG_INT_CTRL0);
 		CTRL1_set_reg(SC8813_DISCHG_INT_CTRL1);
 	}
 }

 /**
   * @function Name  : SC88xx_Mode_set
   * @param			: None
   * @retval 		: None
   * @brief 			: Register content setting for different modes of operation
   * 					-Note : Refer the SECTION 1 PART3 of SC8815.h.(to know more info about register setting)
   */
 static void DIS_CHG_MODE_EXT(uint8_t port_num){
 	if(port_num==PD1_SC8815 || port_num==PD2_SC8815 || port_num==MPPT_SC8815){
 		CTRL0_set_reg(SC8815_DISCHG_EXT_CTRL0);
 		CTRL1_set_reg(SC8815_DISCHG_EXT_CTRL1);
 	}else {
 		CTRL0_set_reg(SC8813_DISCHG_EXT_CTRL0);
 		CTRL1_set_reg(SC8813_DISCHG_EXT_CTRL1);
 	}
 }

 /**
   * @function Name  : SC88xx_Mode_set
   * @param 1	    : uint8_t port_num
   * @param2			: SC88xx_ModeTypedef mode (note : this to choose mode of SC88xx device)
   * @retval 		: None
   * @brief 			: To set
   */
 static void SC88xx_Mode_set(uint8_t port_num, SC88xx_ModeTypedef mode){
 	switch(port_num){
 	case PD1_SC8815:
 		PD1_SC_standby_mode();
 		/*I2C MUX channel select*/
 		I2C_MUX_channel0_select();
 		/*Discharge mode set for PD SC8815*/
 		DIS_CHG_MODE_EXT(port_num);
 		PD1_SC_shutdown_mode();
 	break;
 	case PD2_SC8815:
 		PD2_SC_standby_mode();
 		/*I2C MUX channel select*/
 		I2C_MUX_channel1_select();
 		/*Discharge mode set for PD SC8815*/
 		DIS_CHG_MODE_EXT(port_num);
 		PD2_SC_shutdown_mode();
 	break;
 	case MPPT_SC8815:
 		//MPPT SC8815 standby mode function
 		/*I2C MUX channel select*/
 		I2C_MUX_channel2_select();
 		/*Discharge mode set for PD SC8815*/
 		CHG_MODE_EXT(port_num);
 		//MPPT shutdown mode funation
 		break;
 	case SC8813:
 		//MPPT SC8815 standby mode function
 		/*I2C MUX channel select*/
 		I2C_MUX_channel3_select();
 		/*Discharge mode set for PD SC8815*/
 		if(mode ==0){
 			CHG_MODE_EXT(port_num);
 		}else{
 			DIS_CHG_MODE_EXT(port_num);
 		}
 		//MPPT shutdown mode funation
     default:
 		SC_I2C_Error_Handler();
 	}
 }

  /*#################################################################	END of MODULE 4	#########################################################################*/

 /*################################################################ 		MODULE 5	#########################################################################*/

 /**
   * @function Name  : CTRLx_sett_reg
   * @param			: uint8_t ctrl0, uint8_t ctrl1, uint8_t ctrl2, uint8_t ctrl3
   * @retval 		: None
   * @brief 			:
   */
 static void CTRLx_set(uint8_t ctrl0, uint8_t ctrl1, uint8_t ctrl2, uint8_t ctrl3){
 	CTRL0_set_reg(ctrl0);
 	CTRL1_set_reg(ctrl1);
 	CTRL2_set_reg(ctrl2);
 	CTRL3_set_reg(ctrl3);
 }

 /**
   * @function Name  : float VBUS_ref_val(float VBUS_voltage)
   * @param			: float VBUS_voltage
   * @retval 		: float
   * @brief 			: Function to calculate VBUS reference value to set externally
   * 					- Return VBUS reference value should be in the range of 0.5 to 2.048
   */

 static float VBUS_ref_val_set(float VBUS_voltage){
 	float vbus_fb_ref=0.0;
 	if(VBUS_voltage>20.0){
 		return 0;
 	}else if(VBUS_voltage<5){
 		return 0;
 	}else {
 	//vbus_fb_ref= (VBUS_voltage/(SC8815_VBUS_RATIO+1));
 	return vbus_fb_ref;
 	}
 }

 /**
   * @function Name  : void VBUS_E_reg(float VBUS_ref)
   * @param			: float VBUS_ref
   * @retval 		: void
   * @brief 			: Function to set the VBUS value based on the Reference voltage
   */
 static void VBUS_EXT_set(float VBUS_ref){
 	float vbus_ref_float=0.0;
 	unsigned int vbus_ref_int=0;
 	unsigned char vbus_reg1_val=0;
 	unsigned char vbus_reg2_val=0;
 	vbus_ref_float=((VBUS_ref/0.002)-1-0)/4;
 	vbus_ref_int =((int)vbus_ref_float);
 	vbus_reg1_val=(unsigned char)vbus_ref_int;
 	if ((vbus_ref_float-vbus_ref_int)>0.8){
 		vbus_reg2_val=0xC0;
 	}else if ((vbus_ref_float-vbus_ref_int)>0.6){
 		vbus_reg2_val=0x80;
 	}else if ((vbus_ref_float-vbus_ref_int)>0.4){
 		vbus_reg2_val=0x40;
 	}else{
 		vbus_reg2_val=0x00;
 	}
 	VBUS_EXT_set_reg(vbus_reg1_val, vbus_reg2_val);
 }

 /**
   * @function Name  : VBUS_INT_set
   * @param			: float VBUS_ref
   * @retval 		: void
   * @brief 			:  Function to set the VBUS value based on the Reference voltage
   */
 static void VBUS_INT_set(float VBUS_ref){

 }

  /*#################################################################	END of MODULE 5	#########################################################################*/

 /*################################################################ 		MODULE 6	#########################################################################*/



  /*#################################################################	END of MODULE 6	#########################################################################*/

 /*################################################################ 		MODULE 7	#########################################################################*/

 /**
   * @function Name  : SC_I2C_Error_Handler
   * @param			: None
   * @retval 		: None
   * @brief 			: SC8815 I2C ERROR handler
   */
 static void SC_I2C_Error_Handler(void){

 	while(1);

 }

  /*#################################################################	END of MODULE 7	#########################################################################*/


 /*
  * Static Function Definition Ends here
  */

 /*
  *  Global function Definition Starts here
  */

 /*
   * @function Name  : SC88xx_Init
   * @param			: None
   * @retval 		: None
   * @brief 			: USBPD_SC88xx_Init
   */
  void USBPD_SC88xx_Init(uint8_t Port_num){

 	 /* GPIO initialization based on port number*/
 	 PD_GPIO_Init(Port_num);
 	 /* I2C initialization for I2C 8815/SC8813*/
 	 I2C2_Init();
 	 /*Discharge mode setting for PD source*/
 	 SC88xx_Mode_set(Port_num, SC88xx_DIS_CHG_MODE);
 }

  /*
    * @function Name  : SC88xx_Default_set
    * @param			 : uint8_t Port_num
    * @retval 		 : SC88xx_StatusTypeDef
    * @brief 		 : Default Power profile establishment on the respective port
    */
  SC88xx_StatusTypeDef USBPD_SC88xx_Default_5V_set(uint8_t Port_num){
 	 switch(Port_num){
 	 	 case PD1_SC8815:
 	 		PD1_SC_standby_mode();
 	 		/* I2C channel selection*/
 	 		I2C_MUX_channel0_select();
 	 		/*5V default establishment based on PD2 of Source Port*/
 	 		PD1_SC_active_mode();
 	 		 break;
 	 	 case PD2_SC8815:
 	 		PD1_SC_standby_mode();
 	 		/* I2C channel selection*/
 	 		I2C_MUX_channel1_select();
 	 		/*5V default establishment based on PD2 of Source Port*/
 	 		PD2_SC_active_mode();
 	 		 break;
 	 	 default:
 	 		 SC_I2C_Error_Handler();
 	 	 }

 	 switch(Port_num){
 	 	 case PD1_SC8815:
 	 	 	PD1_SC_standby_mode();
 	 	 	/* I2C channel selection*/
 	 	 	I2C_MUX_channel2_select();
 	 	 	//should read the value from the register and should verify
 	 	 	PD1_SC_active_mode();
 	 	 	return SC88xx_OK;
 	 	 	break;
 	 	 case PD2_SC8815:
 	 	 	PD1_SC_standby_mode();
 	 	 	/* I2C channel selection*/
 	 	 	I2C_MUX_channel3_select();
 	 	 	//should read the value from the register and should verify
 	 	 	PD2_SC_active_mode();
 	 	 	return SC88xx_OK;
 	 	 	break;
 	 	 default:
 	 	   SC_I2C_Error_Handler();
 	  }

 	 return SC88xx_ERROR;
  }

  /*
     * @function Name : USBPD_SC_SET_V_C
     * @param 1		 : Port_num
     * @param 2		 : voltage value in V
     * @param 3		 : Current value in C
     * @retval 		 : SC88xx_StatusTypeDef
     * @brief 		 : Default Power profile establishment on the respective port
     */
  SC88xx_StatusTypeDef USBPD_SC_SET_V_C(uint8_t Port_num, float Voltage_IN_V, float Current_IN_C){


 	 return SC88xx_ERROR;
  }

  /*
   *  Global function Definition Ends here
   */
