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
void lcdPrint(String text1, String text2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text1);
  lcd.setCursor(0, 1);
  lcd.print(text2);
}
void lcdPrint(int startIndex, int row, String text) {
  lcd.clear();
  lcd.setCursor(startIndex, row);
  lcd.print(text);
}
