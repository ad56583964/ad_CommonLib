/*
 * ad_print.h
 *
 *  Created on: Feb 12, 2021
 *      Author: ad565
 */

#ifndef LIB_SRV_AD_PRINT_INC_AD_PRINT_H_
#define LIB_SRV_AD_PRINT_INC_AD_PRINT_H_

#include "../../../lib_drv/lib_drv.h"

int8_t AD_Print(UART_HandleTypeDef *huart, char *fmt, ...);

#endif /* LIB_SRV_AD_PRINT_INC_AD_PRINT_H_ */
