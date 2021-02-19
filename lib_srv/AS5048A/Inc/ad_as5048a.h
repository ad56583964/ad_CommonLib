/*
 * ad_as5048a.h
 *
 *  Created on: Feb 17, 2021
 *      Author: ad565
 */

#ifndef LIB_SRV_AS5048A_INC_AD_AS5048A_H_
#define LIB_SRV_AS5048A_INC_AD_AS5048A_H_

#include "../../../lib_drv/lib_drv.h"

//引用https://github.com/Naxca/STM32F103_AS5048A/tree/master/USER--

uint16_t AS5048A_Read(uint16_t TxData);

float AS5048A_Get_Angle();

#endif /* LIB_SRV_AS5048A_INC_AD_AS5048A_H_ */
