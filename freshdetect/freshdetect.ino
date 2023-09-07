#include <DHT.h>

// Define the pin for the DHT11 sensor
const int DHT_PIN = D1;

// Set the threshold temperature for detecting spoiled fruit
const float spoiledTemperatureThreshold = 32.0;

// Initialize the DHT sensor object
DHT dht(DHT_PIN, DHT11);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read the temperature from the DHT11 sensor
  float fruitTemperature = dht.readTemperature();

  // Check if the temperature reading is valid
  if (isnan(fruitTemperature)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
  }

  // Print the temperature reading
  Serial.print("Fruit Temperature: ");
  Serial.print(fruitTemperature);
  Serial.println(" °C");

  // Check if the fruit is spoiled
  if (fruitTemperature > spoiledTemperatureThreshold) {
    Serial.println("Fruit is Spoiled!");
    // Add your spoiled fruit handling code here
  } else {
    Serial.println("Fruit is Fresh");
    // Add your fresh fruit handling code here
  }

  // Delay between readings
  delay(2000);
}

