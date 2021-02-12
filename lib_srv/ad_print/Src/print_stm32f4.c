/*
 * ad_print.c
 *
 *  Created on: Feb 12, 2021
 *      Author: ad565
 */

#ifndef LIB_SRV_AD_PRINT_SRC_AD_PRINT_C_
#define LIB_SRV_AD_PRINT_SRC_AD_PRINT_C_

#include <stdarg.h>
#include <stdio.h>

#include "../Inc/print_stm32f4.h"

int8_t AD_Print(UART_HandleTypeDef *huart, char *fmt, ...)
{
//引用https://blog.csdn.net/windeal3203/article/details/39209003

    va_list ap;
    int len = 0;
    char buf[64];
    va_start(ap, fmt);
    len = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    int i = 0;
    for(i = 0; i < len; i++)
    {
    	AD_UART_Write(huart, buf[i], 1);
    }
    return 0;
}

#endif /* LIB_SRV_AD_PRINT_SRC_AD_PRINT_C_ */
