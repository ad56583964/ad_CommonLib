/*
 * uart_stm32f4.c
 *
 *  Created on: 2021年2月12日
 *      Author: ad565
 */

#include "../Inc/uart_stm32f4.h"

uint8_t AD_UART_Write(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	return HAL_UART_Transmit(huart, pData, Size, 1000);

}


