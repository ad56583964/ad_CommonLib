/*
 * pa_FOC.h
 *
 *  Created on: Feb 27, 2021
 *      Author: AD_PRO13
 */

#ifndef LIB_APP_BLDC_INC_PA_FOC_H_
#define LIB_APP_BLDC_INC_PA_FOC_H_


#include "../../../lib_srv/lib_srv.h"


void SvpwmFoc_controlTick(float callRate_UsPerTime, float msPerRound);


#endif /* LIB_APP_BLDC_INC_PA_FOC_H_ */
