void lcd_introduce() {
  char phrase[] = " Welcome player  the game will    start in...   ";
  int idx = 0;
  for (int i = 0; i < 16; i++) {
    lcd.write(phrase[16 * idx + i]);
    delay(50);
  }
  idx += 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  for (int i = 0; i < 16; i++) {
    lcd.write(phrase[16 * idx + i]);
    delay(50);
  }
  idx += 1;
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.write(phrase[16 * idx + i]);
    delay(50);
  }
  lcd.clear();
  char countdown[] = " 5... 4... 3...    2...  1...         GO!!      ";
  lcd.setCursor(0, 0);
  idx = 0;
  for (int i = 0; i < 16; i++) {
    lcd.write(countdown[16 * idx + i]);
    delay(50);
  }
  idx += 1;
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.write(countdown[16 * idx + i]);
    delay(50);
  }
  idx += 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  for (int i = 0; i < 16; i++) {
    lcd.write(countdown[16 * idx + i]);
    delay(50);
  }
}