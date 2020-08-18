/**
  ******************************************************************************
  * @file    SC88xx_Reg_Def.h ( V_0.4) Revision 4
  * @author  Morph Team
  * @brief   SC8815 Register Address file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 Supralax Electronics Pvt.Ltd
  * All rights reserved
  *
  ******************************************************************************
  */
#ifndef SC88XX_REG_DEF_H_
#define SC88XX_REG_DEF_H_


#ifdef __cplusplus
extern "C" {
#endif


#define __SC8815__ 1
#define __SC8813__ 1
/*################################## SECTION 1 PART 1 ########################*/
/*7-bit I2C address for SC8815 */
#define SC_I2C_ADDRESS 0x74
/*SC8815 Register address*/
#define VBAT_SET_ADDRESS 0x00
#define VBUSREF_I_SET_ADDRESS 0x01
#define VBUSREF_I_SET2_ADDRESS 0x02
#define VBUSREF_E_SET_ADDRESS 0x03
#define VBUSREF_E_SET2_ADDRESS 0x04
#define IBUS_LIM_SET_ADDRESS 0x05
#define IBAT_LIM_SET_ADDRESS 0x06
#define VINREG_SET_ADDRESS 0x07
#define RATIO_ADDRESS 0x08
#define CTRL0_SET_ADDRESS 0x09
#define CTRL1_SET_ADDRESS 0x0A
#define CTRL2_SET_ADDRESS 0x0B
#define CTRL3_SET_ADDRESS 0x0C
#define VBUS_FB_VALUE_ADDRESS 0x0D
#define VBUS_FB_VALUE2_ADDRESS 0x0E
#define VBAT_FB_VALUE_ADDRESS 0x0F
#define VBAT_FB_VALUE2_ADDRESS 0x10
#define IBUS_VALUE_ADDRESS 0X11
#define IBUS_VALUE2_ADDRESS 0x12
#define IBAT_VALUE_ADDRESS 0x13
#define IBAT_VALUE2_ADDRESS 0x14
#define ADIN_VALUE_ADDRESS 0x15
#define ADIN_VALUE_2_ADDRESS 0x16
#define STATUS_ADDRESS 0x17
#define MASK_ADDRESS 0x19
/* end of the address for Register address for SC8815*/


/*################################## SECTION 2 PART 1 ########################*/
/* port number definitions*/
#define PD1_SC8815 0
#define PD2_SC8815 1
#define MPPT_SC8815 2
#define SC8813 3

/*################################## SECTION 2 PART 2 ########################*/
/* Mode selection for PD port using SC8815*/
#define SC88xx_CHG_MODE 0
#define SC88xx_DIS_CHG_MODE 1

/*#################################### SECTION 3 ##############################*/
/* #defines To concert Voltage in Volts/Amphere/Watts to mVolts/mAmps/mwatt and Vice versa*/
#define V_TO_mV(_VAL_) (_VAL_*1000)
#define mV_TO_V(_VAL_) (_VAL_/1000)

#define A_TO_mA(_VAL_) (_VAL_*1000)
#define mA_TO_A(_VAL_) (_VAL_/1000)

#define W_TO_mW(_VAL_) (_VAL_*1000)
#define mW_TO_W(_VAL_) (_VAL_/1000)
/*#################################### SECTION 4 ##############################*/
/**
  * @brief  POWER Status
  */
typedef enum
{
    SC88xx_OK = 0,
    SC88xx_ERROR=1
} SC88xx_StatusTypeDef;

/*
*@brief enum variable to check SC88xx intialization
*/
typedef enum {
    SC_NOT_INITIALIZED = 0,
    SC_INITIALIZED=1
} SC88xx_InIt_Typedef;

/*
 *@brief enum variable to set the state of SC8815
 */
typedef enum {
    CHARGE_MODE = 0,
    DISCHARGE_MODE=1
} SC88xx_ModeTypedef;

#ifdef __cplusplus
}
#endif

#endif /* SC88XX_REG_DEF_H_ */
