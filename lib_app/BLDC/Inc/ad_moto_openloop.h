/*
 * ad_moto_openloop.h
 *
 *  Created on: Feb 27, 2021
 *      Author: AD_PRO13
 */

#ifndef LIB_APP_BLDC_INC_AD_MOTO_OPENLOOP_H_
#define LIB_APP_BLDC_INC_AD_MOTO_OPENLOOP_H_

#include "../../../lib_srv/lib_srv.h"

#include "foc_utils.h"



void SPWM_setPhaseVoltage(float Uq, float Ud, float angle_el);

void BLDCMotor_velocityOpenloop(float target_velocity);


#endif /* LIB_APP_BLDC_INC_AD_MOTO_OPENLOOP_H_ */
