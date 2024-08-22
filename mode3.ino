void mode3() {
  keys = read_LCD_buttons(analogRead(0));

  if (keys == btnUP) {
    holdButton(Button::L);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnDOWN) {
    holdButton(Button::ZR);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnLEFT) {
    holdButton(Button::ZL);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else if (keys == btnRIGHT) {
    holdButton(Button::R);
    lcd.setCursor(2, 0);
    lcd.cursor();
    delay(250);
  } else {
    releaseButton(Button::L);
    releaseButton(Button::ZR);
    releaseButton(Button::ZL);
    releaseButton(Button::R);
    lcd.noCursor();
  }
}
