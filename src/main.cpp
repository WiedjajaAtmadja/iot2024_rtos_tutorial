#include <Arduino.h>
#define LED_RED   27
#define LED_GREEN 14
#define LED_BLUE  12
void taskLedRed(void* arg)
{
  while(1)
  {
    Serial.println("Task Led Red");
    digitalWrite(LED_RED, HIGH);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(LED_RED, LOW);
    vTaskDelay(900 / portTICK_PERIOD_MS);
  }
}

void taskLedGreen(void* arg)
{
  while(1)
  {
    Serial.println("Task Led Green");
    digitalWrite(LED_GREEN, HIGH);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    digitalWrite(LED_GREEN, LOW);
    vTaskDelay(800 / portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  xTaskCreate(taskLedRed, "taskLedRed", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  xTaskCreate(taskLedGreen, "taskLedGreen", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  // xTaskCreatePinnedToCore(taskLedRed, "taskLedRed", 1024, NULL, 1, NULL, 1);
}

void loop() {
  Serial.println("Hello World!");

  digitalWrite(LED_BLUE, HIGH);
  delay(300); // this speeds up the simulation
  digitalWrite(LED_BLUE, LOW);
  delay(800);
}
