void mode2() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    rightStickTilt(0, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    rightStickTilt(180, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    rightStickTilt(270, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    rightStickTilt(90, 100);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    rightStickNeutral();
    lcd.noCursor();
  }
}
