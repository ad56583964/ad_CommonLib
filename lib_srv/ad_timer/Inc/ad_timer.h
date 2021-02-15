/*
 * ad_timer.h
 *
 *  Created on: 2021年2月13日
 *      Author: ad565
 */

#ifndef LIB_SRV_AD_TIMER_AD_TIMER_H_
#define LIB_SRV_AD_TIMER_AD_TIMER_H_

#include "../../../lib_drv/lib_drv.h"

/* 软件定时器时钟节拍单位 */
#define TIME_BASE_MS			     1    //1ms

/* 软件定时器数量 */
#define TIMER_NUM                   2

/* 定时器ID */
#define AD_TIMER_PRINT            0
#define AD_TIMER_KEYBOARD         1


typedef void callback(void *argv, uint16_t argc);

typedef struct AD_Timer {
    uint8_t state;           //状态
    uint8_t mode;            //模式
    uint32_t match;          //到期时间
    uint32_t period;         //定时周期
    callback *cb;            //回调函数指针
    void *argv;              //参数指针
    uint16_t argc;           //参数个数
}AD_Timer;


typedef enum Timer_State {
    AD_TIMER_STOPPED = 0,  //停止
    AD_TIMER_RUNNING,      //运行
    AD_TIMER_TIMEOUT       //超时
}Timer_State;

typedef enum Timer_Mode {
	MODE_ONE_SHOT = 0,       //单次模式
	MODE_PERIODIC,           //周期模式
}Timer_Mode;

void Tick_Cnt_Update(void);

uint32_t Tick_Cnt_Get(void);

uint8_t AD_Timer_Init();

void AD_Timer_Start(uint16_t id, Timer_Mode mode, uint32_t delay, callback *cb);

void AD_Timer_Update(void);

void AD_Timer_Stop(uint16_t id);

uint8_t AD_Timer_GetState(uint16_t id);

#endif /* LIB_SRV_AD_TIMER_AD_TIMER_H_ */
