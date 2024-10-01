#include "main.hpp"

void setup_power()
{
  Serial.println("setup power check here");
}

void loop_power()
{
  Serial.println("loop power check here");
  CALC_FPS("loop power check here");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}