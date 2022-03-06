void lcdScrollPrint(int startIndex, int row, String text) {
  lcd.clear();
  lcd.setCursor(startIndex+1, row);
  lcd.print(text);
  int l=text.length();
  for (int positionCounter = l; positionCounter >= 0; positionCounter--) {
    lcd.scrollDisplayLeft();
    delay(500);
  }
}

void lcdPrint(int startIndex, int row, String text) {
  lcd.clear();
  lcd.setCursor(startIndex, row);
  lcd.print(text);
}
