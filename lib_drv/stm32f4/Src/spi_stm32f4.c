/*
 * spi_stm32f4.c
 *
 *  Created on: Feb 18, 2021
 *      Author: ad565
 */
#include "../Inc/spi_stm32f4.h"
extern SPI_HandleTypeDef hspi1;

inline uint8_t AD_SPI1_WriteRead(uint8_t *pTxData, uint8_t *pRxData)
{
   return HAL_SPI_TransmitReceive(&hspi1, pTxData, pRxData, 1, 1000);
}

