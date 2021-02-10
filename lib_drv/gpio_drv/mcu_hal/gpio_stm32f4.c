/*
 * gpio_stm32f4.c
 *
 *  Created on: Feb 10, 2021
 *      Author: ad565
 */
#include "stm32f4xx_hal.h"
#include "./gpio_stm32f4.h"

inline void AD_GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

