/*
    Project name : Temperature and humidity sensor module DHT 11 DHT22
    Modified Date: 12-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-temperature-and-humidity-sensor-module-dht-11-dht22
*/

#include <DHT.h>

// Define the type of DHT sensor (DHT11 or DHT22)
#define DHT_TYPE DHT22

// Define the digital pin connected to the DHT sensor
#define DHT_PIN 2

// Initialize the DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature value from DHT sensor
  float temperatureC = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperatureC) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity to Serial Monitor
  Serial.print("Temperature (C): ");
  Serial.println(temperatureC);
  Serial.print("Humidity (%): ");
  Serial.println(humidity);

  // Wait a few seconds before reading again
  delay(2000);
}
