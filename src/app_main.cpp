#include "main.hpp"

// 电源管理线程
void TASK_POWER(void *param)
{
  setup_power();
  while (true)
  {
    loop_power();
  } 
}

// 外设线程
void TASK_DEVICE(void *param)
{
  setup_device();
  while (true)
  {
    loop_device();
  }
}

// 业务逻辑处理线程
void TASK_PROCESS(void *param)
{
  setup_process();
  while (true)
  {
    loop_process();
  } 
}

void samrt_cane_app_main()
{
  // 电源管理线程
  xTaskCreate(
    TASK_POWER,
    "Power Thread",
    8 * 1024,
    NULL,
    3,
    NULL
  );

  // 外设线程
  xTaskCreate(
    TASK_DEVICE,
    "Device Thread",
    8 * 1024,
    NULL,
    2,
    NULL
  );

  // 业务逻辑处理线程
  xTaskCreate(
    TASK_PROCESS,
    "Process Thread",
    8 * 1024,
    NULL,
    1,
    NULL
  );

}