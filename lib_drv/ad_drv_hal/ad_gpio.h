/*
 * ad_gpio.h
 *
 *  Created on: Feb 14, 2021
 *      Author: ad565
 */

#ifndef LIB_DRV_AD_DRV_HAL_AD_GPIO_H_
#define LIB_DRV_AD_DRV_HAL_AD_GPIO_H_

typedef enum
{
  GPIO_RESET = 0,
  GPIO_SET
}AD_GPIO_State;

typedef enum
{
  NO_PULL = 0,
  PULL_UP,
  PULL_DOWN
}AD_Pull_State;

#endif /* LIB_DRV_AD_DRV_HAL_AD_GPIO_H_ */
