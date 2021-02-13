/*
 * timer_.c
 *
 *  Created on: Feb 8, 2021
 *      Author: ad565
 */

//引用https://blog.csdn.net/qq_26904271/article/details/83833168?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
//https://www.ibm.com/developerworks/cn/linux/l-cn-timers/index.html

#include "../Inc/ad_timer.h"


static volatile uint32_t tickCnt = 0; //时钟节拍

static AD_Timer timer[TIMER_NUM];        //软件定时器数组

/* 需在定时器中断内执行 */
void Tick_Cnt_Update(void)
{
    tickCnt++;

}

uint32_t Tick_Cnt_Get(void)
{
  return tickCnt;
}

uint8_t AD_Timer_Init()
{
    uint16_t i;
    for(i=0; i<TIMER_NUM; i++) {
        timer[i].state = AD_TIMER_STOPPED;
        timer[i].mode = MODE_ONE_SHOT;
        timer[i].match = 0;
        timer[i].period = 0;
        timer[i].cb = NULL;
        timer[i].argv = NULL;
        timer[i].argc = 0;
    }

    return 0;
}

void AD_Timer_Start(uint16_t id, Timer_Mode mode, uint32_t delay, callback *cb, void *argv, uint16_t argc)
{
    //assert_param(id < TIMER_NUM);
    //assert_param(mode == MODE_ONE_SHOT || mode == MODE_PERIODIC);

    timer[id].match = Tick_Cnt_Get() + delay;
    timer[id].period = delay;
    timer[id].state = AD_TIMER_RUNNING;
    timer[id].mode = mode;
    timer[id].cb = cb;
    timer[id].argv = argv;
    timer[id].argc = argc;
}

void AD_Timer_Update(void)
{
    uint16_t i;

    for(i=0; i<TIMER_NUM; i++) {
      switch (timer[i].state) {
          case AD_TIMER_STOPPED:
              break;

          case AD_TIMER_RUNNING:
              if(timer[i].match <= Tick_Cnt_Get()) {
                  timer[i].state = AD_TIMER_TIMEOUT;
                  timer[i].cb(timer[i].argv, timer[i].argc);       //执行回调函数
              }
              break;

          case AD_TIMER_TIMEOUT:
              if(timer[i].mode == MODE_ONE_SHOT) {
                  timer[i].state = AD_TIMER_STOPPED;
              } else {
                  timer[i].match = Tick_Cnt_Get() + timer[i].period;
                  timer[i].state = AD_TIMER_RUNNING;
              }
              break;

          default:
              while(1); //timer state error!
              break;
      }
  }
}

void AD_Timer_Stop(uint16_t id)
{
    //assert_param(id < TIMER_NUM);
    timer[id].state = AD_TIMER_STOPPED;
}

uint8_t AD_Timer_GetState(uint16_t id)
{
    return timer[id].state;
}

