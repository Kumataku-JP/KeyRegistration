void mode6() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    holdButton(Button::X);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    holdButton(Button::B);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    holdButton(Button::Y);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    holdButton(Button::A);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    releaseButton(Button::X);
    releaseButton(Button::B);
    releaseButton(Button::Y);
    releaseButton(Button::A);
    lcd.noCursor();
  }
}
