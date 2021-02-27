/*
 * uart_stm32f4.h
 *
 *  Created on: 2021年2月12日
 *      Author: ad565
 */

#ifndef LIB_DRV_STM32F4_INC_UART_STM32F4_H_
#define LIB_DRV_STM32F4_INC_UART_STM32F4_H_

#include "../_interface_stm32f4.h"

#include "../../../../Core/Inc/usart.h"

typedef UART_HandleTypeDef AD_UART_Handle;



uint8_t AD_UART1_Write(uint8_t *pData, uint16_t Size);

#endif /* LIB_DRV_STM32F4_INC_UART_STM32F4_H_ */
