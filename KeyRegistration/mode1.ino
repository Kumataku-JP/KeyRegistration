void mode1() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    stickTilt(Stick::LEFT, 0, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    stickTilt(Stick::LEFT, 180, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    stickTilt(Stick::LEFT, 270, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    stickTilt(Stick::LEFT, 90, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    stickNeutral(Stick::LEFT);
    lcd.noCursor();
  }
}