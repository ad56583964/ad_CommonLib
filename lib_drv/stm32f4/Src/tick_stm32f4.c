/*
 * tick_stm32f4.c
 *
 *  Created on: Feb 27, 2021
 *      Author: AD_PRO13
 */

#ifndef LIB_DRV_STM32F4_SRC_TICK_STM32F4_C_
#define LIB_DRV_STM32F4_SRC_TICK_STM32F4_C_

#include "../Inc/tick_stm32f4.h"

uint32_t AD_Get_Tick_ms()
{
	return HAL_GetTick();
}

#endif /* LIB_DRV_STM32F4_SRC_TICK_STM32F4_C_ */
