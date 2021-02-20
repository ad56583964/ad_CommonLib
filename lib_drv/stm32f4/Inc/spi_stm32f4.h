/*
 * spi_stm32f4.h
 *
 *  Created on: Feb 18, 2021
 *      Author: ad565
 */

#ifndef LIB_DRV_STM32F4_INC_SPI_STM32F4_H_
#define LIB_DRV_STM32F4_INC_SPI_STM32F4_H_

#include "../_interface_stm32f4.h"

typedef SPI_HandleTypeDef AD_SPI_Handle;

uint8_t AD_SPI1_WriteRead(uint8_t *pTxData, uint8_t *pRxData);

#endif /* LIB_DRV_STM32F4_INC_SPI_STM32F4_H_ */
