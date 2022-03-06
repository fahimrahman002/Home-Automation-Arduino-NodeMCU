int buzzer=13;
void alarmOn(){
  tone(buzzer, 1000, 300);
}

void alarmOff(){
  noTone(buzzer);
}
