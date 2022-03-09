
bool gasSensor(){
  int analogSensor = analogRead(gasA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThreshold)
  {
    return true;
  }
  else
  {
    return false;
  }
}
