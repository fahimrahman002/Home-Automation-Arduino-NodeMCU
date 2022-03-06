
void gasSensor(){
  int analogSensor = analogRead(gasA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThreshold)
  {
    redLedOn();
    alarmOn();
  }
  else
  {
    redLedOff();
    alarmOff();
  }
}
