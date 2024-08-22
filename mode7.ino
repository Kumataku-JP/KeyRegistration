void mode7() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnLEFT) {
    holdButton(Button::LCLICK);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    holdButton(Button::RCLICK);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    releaseButton(Button::LCLICK);
    releaseButton(Button::RCLICK);
    lcd.noCursor();
  }
}
