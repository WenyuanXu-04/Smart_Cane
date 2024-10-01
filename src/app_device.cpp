#include "main.hpp"

void setup_device()
{
  Serial.begin(115200);
}

void loop_device()
{
  Serial.println("loop device here");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}