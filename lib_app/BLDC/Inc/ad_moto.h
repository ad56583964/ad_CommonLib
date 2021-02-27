/*
 * ad_moto.h
 *
 *  Created on: Feb 20, 2021
 *      Author: ad565
 */

#ifndef LIB_APP_BLDC_INC_AD_MOTO_H_
#define LIB_APP_BLDC_INC_AD_MOTO_H_

#include "../../../lib_srv/lib_srv.h"

#include "foc_utils.h"

#include "ad_driver.h"

//轴角度？？
float shaft_angle;//!< current motor angle
// motor configuration parameters
float voltage_sensor_align;//!< sensor and motor align voltage parameter
float velocity_index_search;//!< target velocity for index search
int pole_pairs;//!< Motor pole pairs number

void BLDCMotor_loopFOC();

#endif /* LIB_APP_BLDC_INC_AD_MOTO_H_ */
