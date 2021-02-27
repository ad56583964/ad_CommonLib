/*
 * pwm_stm32f4.c
 *
 *  Created on: 2021年2月20日
 *      Author: ad565
 */
#include "../Inc/pwm_stm32f4.h"

extern TIM_HandleTypeDef htim3;

#define __PWM1_PULSE__ 1200
#define __PWM2_PULSE__ 1200
#define __PWM3_PULSE__ 1200

AD_PWM_Static AD_PWM1_Start()
{
    return HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

AD_PWM_Static AD_PWM2_Start()
{
    return HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

AD_PWM_Static AD_PWM3_Start()
{
    return HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}

void AD_PWM1_SET(AD_Duty PWM_Duty)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (__PWM1_PULSE__)*PWM_Duty);
}

void AD_PWM2_SET(AD_Duty PWM_Duty)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, (__PWM2_PULSE__)*PWM_Duty);
}

void AD_PWM3_SET(AD_Duty PWM_Duty)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, (__PWM3_PULSE__)*PWM_Duty);
}
