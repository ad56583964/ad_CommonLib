/*
 * gpio_stm32f1.h
 *
 *  Created on: Feb 9, 2021
 *      Author: ad565
 */

#ifndef LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_
#define LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_

//cube_hal
#include "../../ad_drv_hal/ad_gpio.h"
#include "../_interface_stm32f4.h"

typedef GPIO_TypeDef AD_GPIO_Handle;

void AD_GPIO_Write(AD_GPIO_Handle *GPIOx, uint16_t GPIO_Pin, AD_GPIO_State PinState);

int8_t AD_GPIO_Read(AD_GPIO_Handle *GPIOx, uint16_t GPIO_Pin);

void AD_GPIO_PULL(AD_GPIO_Handle *GPIOx, uint16_t GPIO_Pin, AD_Pull_State PullState);



#endif /* LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_ */
