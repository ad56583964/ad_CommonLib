/*
 * ad_timer.h
 *
 *  Created on: 2021年2月13日
 *      Author: ad565
 */

#ifndef LIB_SRV_AD_TIMER_AD_TIMER_H_
#define LIB_SRV_AD_TIMER_AD_TIMER_H_


typedef struct AD_Timer {
    uint8_t state;           //状态
    uint8_t mode;            //模式
    uint32_t match;          //到期时间
    uint32_t period;         //定时周期
    callback *cb;            //回调函数指针
    void *argv;              //参数指针
    uint16_t argc;           //参数个数
}AD_Timer;


typedef enum timer_State {
    AD_TIMER_STOPPED = 0,  //停止
    AD_TIMER_RUNNING,      //运行
    AD_TIMER_TIMEOUT       //超时
}timer_State;



#endif /* LIB_SRV_AD_TIMER_AD_TIMER_H_ */
