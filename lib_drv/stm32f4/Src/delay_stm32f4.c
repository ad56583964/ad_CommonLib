/*
 * delay_stm32f4.c
 *
 *  Created on: 2021年2月21日
 *      Author: ad565
 */

#include "../Inc/delay_stm32f4.h"


void AD_Delay_ms(AD_DELAY_MS ms)
{
    HAL_Delay(ms);
}

void AD_Delay_us(AD_DELAY_US us)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 10000000 * us);
    for (;delay;delay--);

}
