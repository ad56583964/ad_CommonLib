/*
 * ad_keypad.c
 *
 *  Created on: 2021年2月13日
 *      Author: ad565
 */
#include "../Inc/ad_keypad.h"
#include "../../ad_print/Inc/ad_print_stm32f4.h"

static volatile uint32_t key_event_cnt = 0;

static struct Pad_GPIO
{
    GPIO_TypeDef * GROUP;
    uint16_t PIN;
};

void Key_Addr_Init()
{
    uint8_t Pad_x = 0;

}

void Key_X_Write()
{

}

void Key_Pad_Scan()
{
    uint8_t Pad_x = 0;
    for(Pad_x = 0; Pad_x < KEY_SCALE; Pad_x ++)
    {

    }
}


