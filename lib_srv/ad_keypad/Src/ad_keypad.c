/*
 * ad_keypad.c
 *
 *  Created on: 2021年2月13日
 *      Author: ad565
 */
#include "../Inc/ad_keypad.h"
#include "../../ad_print/Inc/ad_print.h"

static volatile uint32_t key_event_cnt = 0;

extern UART_HandleTypeDef huart1;

uint16_t Pad_Addr = 0;

#define KEY_EVENT_MAX 20

#define Pad_NO_PUSH         0
#define Pad_MAY_PUSH        1
#define Pad_IS_PUSH         2
#define Pad_SHORT_PUSH      3
#define Pad_LONG_PUSH       4

#define SHORT_PUSH   2
#define LONG_PUSH    10


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

void Key_Pad_Init(AD_GPIO_Handle **Y_GPIO, uint16_t *Y_PIN)
{
    Key_X_Write(Y_GPIO,Y_PIN,1);
    Key_Y_PULL(Y_GPIO,Y_PIN,2);
}

void Key_Y_Scan(AD_Pad_Handle *Pad, AD_GPIO_Handle **X_GPIO, uint16_t *X_PIN,AD_GPIO_Handle **Y_GPIO, uint16_t *Y_PIN)
{
    Key_X_Write(X_GPIO,X_PIN,1);
    static uint8_t Key_Addr = 0x0;
    static uint8_t KEY_Y = 0;
    static uint8_t KEY_X = 0;

    //行检测
    if(Pad->Pad_State == Pad_NO_PUSH)
    {
        for(KEY_Y = 0; KEY_Y < KEY_SCALE; KEY_Y++)
        {
            if(AD_GPIO_Read(Y_GPIO[KEY_Y], Y_PIN[KEY_Y]) == 1)
            {
                Key_Addr = KEY_Y * 4;

                //列检测
                for(KEY_X = 0; KEY_X < KEY_SCALE; KEY_X++)
                {
                    AD_GPIO_Write(X_GPIO[KEY_X], X_PIN[KEY_X], 0);
                    if(AD_GPIO_Read(Y_GPIO[KEY_Y], Y_PIN[KEY_Y]) == 0)
                    {
                        //行地址确定
                        Key_Addr += KEY_X;

                        //更新按键状态
                        Pad->Pad_State = Pad_MAY_PUSH;

                        //更新定时器
                        key_event_cnt = 0;

                        break;
                    }
                }

                //跳出嵌套
                if(Pad->Pad_State == Pad_MAY_PUSH)
                {
                    break;
                }
            }
        }
    }

    //按键消抖
    if(Pad->Pad_State == Pad_MAY_PUSH && key_event_cnt > SHORT_PUSH)
    {
        if(AD_GPIO_Read(Y_GPIO[KEY_Y], Y_PIN[KEY_Y]) == 0)
        {
            Pad->Pad_State = Pad_IS_PUSH;

            //更新定时器
            key_event_cnt = 0;
        }
        else
        {
            Pad->Pad_State = Pad_NO_PUSH;

            //更新定时器
            key_event_cnt = 0;
        }
    }


    if(Pad->Pad_State == Pad_IS_PUSH && key_event_cnt > LONG_PUSH)
    {
        if(AD_GPIO_Read(Y_GPIO[KEY_Y], Y_PIN[KEY_Y]) == 1)
        {
            Pad->Pad_State = Pad_NO_PUSH;

            //更新定时器
            key_event_cnt = 0;
        }
        else
        {
            Pad->Pad_State = Pad_LONG_PUSH;
        }
    }

    if(Pad->Pad_State == Pad_LONG_PUSH && key_event_cnt > LONG_PUSH)
    {
            Pad->Pad_State = Pad_NO_PUSH;
    }

    Pad->Key_Addr = Key_Addr;

    key_event_cnt++;
    if(key_event_cnt > KEY_EVENT_MAX)
    {
        key_event_cnt = KEY_EVENT_MAX;
    }
}


