#include "main.hpp"


void setup() 
{
  samrt_cane_app_main();
}

void loop() 
{
  vTaskDelay(10 / portTICK_PERIOD_MS);
}
