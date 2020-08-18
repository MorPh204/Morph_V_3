/**
  ******************************************************************************
  * @file    SC8813_HW.h ( V_0.4) Revision 4
  * @author  Morph Team
  * @brief   Hardware Selections for SC8813
  *       			 NOTE : these defines strictly for SC8813
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 Supralax Electronics Pvt.Ltd
  * All rights reserved
  *
  ******************************************************************************
  */

#ifndef SC8813_HW_H_
#define SC8813_HW_H_

/*################################## SECTION 1 PART 1 ########################*/
/* RS1 is current sense resistance at VBUS side*/
#define SC8813_RS1_IN_mOHM 10
/* RS2 is current sense resistance at VBAT side*/
#define SC8813_RS2_IN_mOHM 10

/*################################## SECTION 1 PART 2 ########################*/
/* RUP and RDOWN resistance values for SC8815 on VBUS side */
#define SC8813_VBUS_RUP_IN_mOHM 0    // should be updated
#define SC8813_VBUS_RDOWN_IN_mOHM 0  // should be updated

/* RUP and RDOWN resistance values for SC8815 on VBAT side */
#define SC8813_VBAT_RUP_IN_mOHM 0    // should be updated
#define SC8813_VBAT_RDOWN_IN_mOHM 0  // should be updated

/*################################## SECTION 2 PART1##########################*/

#define SC8813_VBUS_RATIO ((SC8813_VBUS_RUP_IN_mOHM/SC8813_VBUS_RDOWN_IN_mOHM)+1)
#define SC8813_VBAT_RATIO ((SC8813_VBAT_RUP_IN_mOHM/SC8813_VBAT_RDOWN_IN_mOHM)+1)

#endif /* SC8813_HW_H_ */

