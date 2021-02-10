/*
 * gpio_stm32f1.h
 *
 *  Created on: Feb 9, 2021
 *      Author: ad565
 */

#ifndef LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_
#define LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_

//cube_hal
#include "stm32f1xx_hal.h"

static inline void AD_GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}






#endif /* LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_ */
