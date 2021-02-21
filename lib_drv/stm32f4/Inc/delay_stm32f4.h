/*
 * delay_stm32f4.h
 *
 *  Created on: 2021年2月21日
 *      Author: ad565
 */

#ifndef LIB_DRV_STM32F4_INC_DELAY_STM32F4_H_
#define LIB_DRV_STM32F4_INC_DELAY_STM32F4_H_

#include "../_interface_stm32f4.h"

typedef uint16_t AD_DELAY_MS;
typedef uint16_t AD_DELAY_US;

void AD_Delay_ms(AD_DELAY_MS ms);
void AD_Delay_us(AD_DELAY_US us);


#endif /* LIB_DRV_STM32F4_INC_DELAY_STM32F4_H_ */
