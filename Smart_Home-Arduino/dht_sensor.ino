// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float getHumidity() {
  float h = dht.readHumidity();
  if (!checkSensor(h))return -1;
  return h;
}

float getTempC() {
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  if (!checkSensor(t))return -1;
  return t;
}

float getTempF() {
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  if (!checkSensor(f))return -1;
  return f;
}
void printHumTemp() {
  if (millis() - humTempDelay >= 500) {
    float h = getHumidity();
    float t = getTempC();
    String humidityText = (String)"Hum: " + h + "%";
    String temperatureText = (String)"Temp: " + t + "C";
    if (prevHum != h || prevTemp != t) {
      lcdPrint(humidityText, temperatureText);
      prevHum = h;
      prevTemp = t;
    }
    Serial.println(humidityText);
    Serial.println(temperatureText);
    humTempDelay = millis();
  }
  
}
// Check if any reads failed and exit early (to try again).
bool checkSensor(float value) {
  if (isnan(value)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcdPrint(0, 0, "DHT module not working.");
    return false;
  } else {
    return true;
  }
}
