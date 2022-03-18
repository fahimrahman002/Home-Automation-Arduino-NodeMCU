void alarmOn() {
  digitalWrite(buzzer, HIGH);
}

void alarmOff() {
  noTone(buzzer);
  //  digitalWrite(buzzer, LOW);
}
void alarmTone() {
  tone(buzzer, 500, 300);
}
