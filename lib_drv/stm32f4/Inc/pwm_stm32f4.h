/*
 * pwm_stm32f4.h
 *
 *  Created on: 2021年2月20日
 *      Author: ad565
 */

#ifndef LIB_DRV_STM32F4_INC_PWM_STM32F4_H_
#define LIB_DRV_STM32F4_INC_PWM_STM32F4_H_

#include "../_interface_stm32f4.h"

typedef uint8_t     AD_PWM_Handle;
typedef float       AD_Duty;
typedef uint8_t     AD_PWM_Static;

AD_PWM_Static AD_PWM1_Start();
AD_PWM_Static AD_PWM2_Start();
AD_PWM_Static AD_PWM3_Start();

void AD_PWM1_SET(AD_Duty PWM_Duty);
void AD_PWM2_SET(AD_Duty PWM_Duty);
void AD_PWM3_SET(AD_Duty PWM_Duty);

#endif /* LIB_DRV_STM32F4_INC_PWM_STM32F4_H_ */
