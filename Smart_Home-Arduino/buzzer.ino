void alarmOn() {
  //  tone(buzzer, 1000, 300);
  digitalWrite(buzzer, HIGH);
}

void alarmOff() {
    noTone(buzzer);
//  digitalWrite(buzzer, LOW);
}
void alarmTone(){
  tone(buzzer, 500, 300);
  }
