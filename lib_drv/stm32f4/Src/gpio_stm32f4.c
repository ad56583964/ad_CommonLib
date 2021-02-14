/*
 * gpio_stm32f4.c
 *
 *  Created on: Feb 10, 2021
 *      Author: ad565
 */
#include "../../stm32f4/Inc/gpio_stm32f4.h"

#define GPIO_NUMBER           16U


inline void AD_GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

void AD_GPIO_PULL(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, Pull_State PullState)
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
