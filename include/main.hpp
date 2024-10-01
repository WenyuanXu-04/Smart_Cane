#include <Arduino.h>
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"

#define CALC_FPS(tips)                                                                                     \
  {                                                                                                        \
    static int fcnt = 0;                                                                                   \
    fcnt++;                                                                                                \
    static struct timespec ts1, ts2;                                                                       \
    clock_gettime(CLOCK_MONOTONIC, &ts2);                                                                  \
    if ((ts2.tv_sec * 1000 + ts2.tv_nsec / 1000000) - (ts1.tv_sec * 1000 + ts1.tv_nsec / 1000000) >= 1000) \
    {                                                                                                      \
      Serial.printf("%s => %d FPS \r\n", tips, fcnt);                                                      \
      ts1 = ts2;                                                                                           \
      fcnt = 0;                                                                                            \
    }                                                                                                      \
  }

void setup_power();// 电源管理初始化
void loop_power();// 电源管理主循环
void setup_device();// 外设初始化
void loop_device();// 外设主循环
void setup_process();// 业务逻辑初始化
void loop_process();// 业务逻辑主循环

void samrt_cane_app_main();// 程序入口