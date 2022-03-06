// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float getHumidity(){
  float h = dht.readHumidity();
  if(!checkSensor(h))return 0;
  String humidityText = (String)"Humidity: " + h + "%";
  Serial.println(humidityText);
  lcdScrollPrint(0, 1, humidityText);
  return h;
}

float getTempC(){
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  if(!checkSensor(t))return 0;
  String temperatureText = (String)"Temp: " + t + "C";
  Serial.println(temperatureText);
  lcdScrollPrint(0, 1, temperatureText);
  return t;
}

float getTempF(){
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  if(!checkSensor(f))return 0;
  String temperatureText = (String)"Temp: " + f + "F";
  Serial.println(temperatureText);
  lcdScrollPrint(0, 1, temperatureText);
  return f;
}

// Check if any reads failed and exit early (to try again).
bool checkSensor(float value){
    if (isnan(value)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcdPrint(0, 0, "DHT module not working.");
    return false;
  }else{
    return true;
  }
}
