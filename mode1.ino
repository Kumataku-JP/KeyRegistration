void mode1() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    leftStickTilt(0, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    leftStickTilt(180, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    leftStickTilt(270, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    leftStickTilt(90, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    leftStickNeutral();
    lcd.noCursor();
  }
}