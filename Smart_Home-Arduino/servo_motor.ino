void doorClose(){
  Serial.println("Door is closing...");
  servo.write(doorCloseAngle);
}
void doorOpen(){
  Serial.println("Door is opening...");
  servo.write(doorOpenAngle);
}
