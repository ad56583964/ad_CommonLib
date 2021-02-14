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


void AD_GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

int8_t AD_GPIO_Read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

void AD_GPIO_PULL(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, Pull_State PullState);



#endif /* LIB_DRV_GPIO_DRV_MCU_HAL_GPIO_STM32F1_H_ */
