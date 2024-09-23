void mode2() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    stickTilt(Stick::RIGHT, 0, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    stickTilt(Stick::RIGHT, 180, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    stickTilt(Stick::RIGHT, 270, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    stickTilt(Stick::RIGHT, 90, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    stickNeutral(Stick::RIGHT);
    lcd.noCursor();
  }
}
