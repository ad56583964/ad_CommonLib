/*
 * ad_keypad.h
 *
 *  Created on: 2021年2月13日
 *      Author: ad565
 */

#ifndef LIB_SRV_AD_KEYPAD_INC_AD_KEYPAD_H_
#define LIB_SRV_AD_KEYPAD_INC_AD_KEYPAD_H_

#include "../../../lib_drv/lib_drv.h"

#define KEY_SCALE 4

typedef struct __AD_Pad_Handle
{
    uint8_t Pad_State;
    uint8_t Key_Addr;
} AD_Pad_Handle;

/*AD_GPIO_Handle *AD_X_GPIO[KEY_SCALE] = {
        GPIOA
};

uint16_t AD_X_PIN[KEY_SCALE] = {
        GPIO_PIN_5
};*/

void Key_X_Write(AD_GPIO_Handle **X_GPIO, uint16_t *X_PIN, AD_GPIO_State PinState);

void Key_Y_PULL(AD_GPIO_Handle **Y_GPIO, uint16_t *Y_PIN, AD_Pull_State PullState);

void Key_Y_Scan(AD_Pad_Handle *Pad,AD_GPIO_Handle **X_GPIO, uint16_t *X_PIN,AD_GPIO_Handle **Y_GPIO, uint16_t *Y_PIN);

#endif /* LIB_SRV_AD_KEYPAD_INC_AD_KEYPAD_H_ */
