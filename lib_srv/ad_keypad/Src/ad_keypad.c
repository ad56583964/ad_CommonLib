/*
 * ad_keypad.c
 *
 *  Created on: 2021年2月13日
 *      Author: ad565
 */
#include "../Inc/ad_keypad.h"
#include "../../ad_print/Inc/ad_print.h"

static volatile uint32_t key_event_cnt = 0;

void Key_Addr_Init()
{
    //uint8_t Pad_x = 0;
}

void Key_X_Write(AD_GPIO_Handle **X_GPIO, uint16_t *X_PIN, AD_GPIO_State PinState)
{
    uint8_t KEY_X = 0;
    for(KEY_X = 0; KEY_X < KEY_SCALE; KEY_X ++)
    {
        AD_GPIO_Write(X_GPIO[KEY_X], X_PIN[KEY_X], PinState);
    }

}

void Key_Y_PULL(AD_GPIO_Handle **Y_GPIO, uint16_t *Y_PIN, AD_Pull_State PullState)
{
    uint8_t KEY_Y = 0;
    for(KEY_Y = 0; KEY_Y < KEY_SCALE; KEY_Y ++)
    {
        AD_GPIO_PULL(Y_GPIO[KEY_Y], Y_PIN[KEY_Y], PullState);
    }

}

void Key_Pad_Scan()
{

}


