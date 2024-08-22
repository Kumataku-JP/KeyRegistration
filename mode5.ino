void mode5() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    holdButton(Button::MINUS);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    holdButton(Button::HOME);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    holdButton(Button::PLUS);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    holdButton(Button::CAPTURE);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    releaseButton(Button::MINUS);
    releaseButton(Button::HOME);
    releaseButton(Button::PLUS);
    releaseButton(Button::CAPTURE);
    lcd.noCursor();
  }
}
