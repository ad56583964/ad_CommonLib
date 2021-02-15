/*
 * gpio_stm32f4.c
 *
 *  Created on: Feb 10, 2021
 *      Author: ad565
 */
#include "../../stm32f4/Inc/gpio_stm32f4.h"

#define GPIO_NUMBER           16U


inline void AD_GPIO_Write(AD_GPIO_Handle *GPIOx, uint16_t GPIO_Pin, AD_GPIO_State PinState)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

inline int8_t AD_GPIO_Read(AD_GPIO_Handle *GPIOx, uint16_t GPIO_Pin)
{
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

void AD_GPIO_PULL(AD_GPIO_Handle *GPIOx, uint16_t GPIO_Pin, AD_Pull_State PullState)
{
    uint32_t position;
    uint32_t ioposition = 0x00U;
    uint32_t iocurrent = 0x00U;
    uint32_t temp = 0x00U;

    /* Configure the port pins */
    for(position = 0U; position < GPIO_NUMBER; position++)
    {
        /* Get the IO position */
        ioposition = 0x01U << position;
        /* Get the current IO position */
        iocurrent = (uint32_t)(GPIO_Pin) & ioposition;

        if(iocurrent == ioposition)
        {
            temp = GPIOx->PUPDR;
            temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
            temp |= ((PullState) << (position * 2U));
            GPIOx->PUPDR = temp;
        }
    }
}
