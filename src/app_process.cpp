#include "main.hpp"

void setup_process()
{

}

void loop_process()
{
  Serial.println("loop process here");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}