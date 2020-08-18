/**
  ******************************************************************************
  * @file    MPPT_SC8815_HW.h ( V_0.4) Revision 4
  * @author  Morph Team
  * @brief   Hardware Selections for MPPT SC8815
  *       			 NOTE : these defines strictly for MPPT related SC8815
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 Supralax Electronics Pvt.Ltd
  * All rights reserved
  *
  ******************************************************************************
  */
#ifndef MPPT_SC8815_HW_H_
#define MPPT_SC8815_HW_H_

/*################################## SECTION 1 PART 1 ########################*/
/* RS1 is current sense resistance at VBUS side*/
#define MPPT_SC8815_RS1_IN_mOHM 10
/* RS2 is current sense resistance at VBAT side*/
#define MPPT_SC8815_RS2_IN_mOHM 10

/*################################## SECTION 1 PART 2 ########################*/
/* RUP and RDOWN resistance values for SC8815 on VBUS side */
#define MPPT_SC8815_VBUS_RUP_IN_mOHM 0    // should be updated
#define MPPT_SC8815_VBUS_RDOWN_IN_mOHM 0  // should be updated

/* RUP and RDOWN resistance values for SC8815 on VBAT side */
#define MPPT_SC8815_VBAT_RUP_IN_mOHM 0    // should be updated
#define MPPT_SC8815_VBAT_RDOWN_IN_mOHM 0  // should be updated

/*################################## SECTION 2 PART1##########################*/

#define MPPT_SC8815_VBUS_RATIO ((MPPT_SC8815_VBUS_RUP_IN_mOHM/MPPT_SC8815_VBUS_RDOWN_IN_mOHM)+1)
#define MPPT_SC8815_VBAT_RATIO ((MPPT_SC8815_VBAT_RUP_IN_mOHM/MPPT_SC8815_VBAT_RDOWN_IN_mOHM)+1)

#endif /* MPPT_SC8815_HW_H_ */
