void doorClose(){
  Serial.println("Door is closing...");
  lcdPrint("Smart Home","Door is closing...");
  servo.write(doorCloseAngle);
  delay(1000);
}
void doorOpen(){
  Serial.println("Door is opening...");
  lcdPrint("Smart Home","Door is opening...");
  servo.write(doorOpenAngle);
  delay(5000);
  doorClose();
}
