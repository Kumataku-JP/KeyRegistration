void mode4() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    holdHat(Hat::UP);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    holdHat(Hat::DOWN);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    holdHat(Hat::LEFT);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    holdHat(Hat::RIGHT);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    releaseHat();
    lcd.noCursor();
  }
}