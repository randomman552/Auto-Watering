#include <Arduino.h>

#define PUMP_OUT_PIN 12
#define SENSOR_DIGITAL_IN_PIN 11
#define SENSOR_ANALOG_IN_PIN 1
#define TARGET_SOIL_WATER_LEVEL 500
#define WATERING_TIME 5000
#define POST_WATERING_DELAY 20000

void pumpOn()
{
  digitalWrite(PUMP_OUT_PIN, HIGH);
}

void pumpOff()
{
  digitalWrite(PUMP_OUT_PIN, LOW);
}

int getSoilWaterLevel()
{
  return analogRead(SENSOR_ANALOG_IN_PIN);
}

void setup()
{
  // Set up pins
  pinMode(PUMP_OUT_PIN, OUTPUT);
  pinMode(SENSOR_DIGITAL_IN_PIN, INPUT);

  // Set up serial
  Serial.begin(115200);
}

void loop()
{
  auto soilWaterLevel = getSoilWaterLevel();
  Serial.println(soilWaterLevel);

  if (soilWaterLevel > TARGET_SOIL_WATER_LEVEL)
  {
    Serial.println("Water level too low, watering");
    pumpOn();
    delay(WATERING_TIME);
    Serial.println("Waiting...");
    pumpOff();
    delay(POST_WATERING_DELAY);
    Serial.println("Finished watering");
  }

  delay(1000);
}
