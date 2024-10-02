/*  ReaSnowS1にArduinoコントローラーを登録するためのプログラム
 *  v1.1.0
 *  
 */

#include <LiquidCrystal.h>
#include <NSControlLibrary.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* ============================================================== */
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define ERRORR 6

int read_LCD_buttons(int adc_key_in) {
  if (adc_key_in < 50) return btnRIGHT;    //0   , 戻り値0, 0V
  if (adc_key_in < 250) return btnUP;      //131 , 戻り値1, 0.64V
  if (adc_key_in < 450) return btnDOWN;    //307 , 戻り値2, 1.50V
  if (adc_key_in < 650) return btnLEFT;    //479 , 戻り値3, 2.34V
  if (adc_key_in < 850) return btnSELECT;  //721 , 戻り値4, 3.52V
  if (adc_key_in > 1000) return btnNONE;   //1023, 戻り値5, 5.00V
  return btnNONE;                          //
}
/* ============================================================== */

int keys;
unsigned char modeNow;
unsigned char modeOld;
bool modeChanged = true;  // モード切り替えフラグ
unsigned long previousModeMillis = 0;
const long modeInterval = 3000;  // モード切り替えの間隔（ミリ秒）
bool isUpper = true;             // 表示が "U=U D=D" か "L=L R=R" かを判定するフラグ

//toggle制御
bool steyMode0;
int toggle;

/* ============================================================== */

// triangle
byte triangleChar[] = {
  B00000,
  B00100,
  B01010,
  B01010,
  B10001,
  B11111,
  B00000,
  B00000
};
// square
byte squareChar[] = {
  B00000,
  B11111,
  B10001,
  B10001,
  B10001,
  B11111,
  B00000,
  B00000
};
// circle
byte circleChar[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000
};
// cross
byte crossChar[] = {
  B00000,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000,
  B00000
};
// up
byte upChar[] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00000,
  B00000,
};
// down
byte downChar[] = {
  B00000,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};
// left
byte leftChar[] = {
  B00000,
  B00100,
  B01100,
  B11111,
  B01100,
  B00100,
  B00000,
  B00000,
};
// right
byte rightChar[] = {
  B00000,
  B00100,
  B00110,
  B11111,
  B00110,
  B00100,
  B00000,
  B00000,
};

/* ============================================================== */

void setup() {
  pushButton(Button::HOME, 50, 600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Key Registration");
  lcd.setCursor(0, 1);
  lcd.print("MODE SELECT");

  lcd.createChar(0, triangleChar);  // triangle 0
  lcd.createChar(1, squareChar);    // square 1
  lcd.createChar(2, circleChar);    // circle 2
  lcd.createChar(3, crossChar);     // cross  3
  lcd.createChar(4, upChar);        // up 4
  lcd.createChar(5, downChar);      // down 5
  lcd.createChar(6, leftChar);      // left 6
  lcd.createChar(7, rightChar);     // right 7
}
/* ============================================================== */

// 2列目LCD
void screenDisplay() {
  switch (toggle) {
    case 1:
    case 2:
      lcd.clear();
      if (isUpper) {
        lcd.setCursor(0, 1);
        lcd.write(byte(4));  // up 4
        lcd.print("FRONT");
        lcd.setCursor(8, 1);
        lcd.write(byte(5));  // down 5
        lcd.print("BACK");
      } else {
        lcd.setCursor(0, 1);
        lcd.write(byte(6));  // left 6
        lcd.print("LEFT");
        lcd.setCursor(8, 1);
        lcd.write(byte(7));  // right 7
        lcd.print("RIGHT");
      }
      break;
    case 3:
      lcd.clear();
      if (isUpper) {
        lcd.setCursor(0, 1);
        lcd.write(byte(4));  // up 4
        lcd.print("L(1)");
        lcd.setCursor(8, 1);
        lcd.write(byte(5));  // down 5
        lcd.print("ZR(R2)");
      } else {
        lcd.setCursor(0, 1);
        lcd.write(byte(6));  // left 6
        lcd.print("ZL(L2)");
        lcd.setCursor(8, 1);
        lcd.write(byte(7));  // right 7
        lcd.print("R(1)");
      }
      break;
    case 4:
      lcd.clear();
      if (isUpper) {
        lcd.setCursor(0, 1);
        lcd.write(byte(4));  // up 4
        lcd.print("UP");
        lcd.setCursor(8, 1);
        lcd.write(byte(5));  // down 5
        lcd.print("DOWN");
      } else {
        lcd.setCursor(0, 1);
        lcd.write(byte(6));  // left 6
        lcd.print("LEFT");
        lcd.setCursor(8, 1);
        lcd.write(byte(7));  // right 7
        lcd.print("RIGHT");
      }
      break;
    case 5:
      lcd.clear();
      if (isUpper) {
        lcd.setCursor(0, 1);
        lcd.write(byte(4));  // up 4
        lcd.print("TOUCHPAD-");
        lcd.setCursor(12, 1);
        lcd.write(byte(5));  // down 5
        lcd.print("PS");
      } else {
        lcd.setCursor(0, 1);
        lcd.write(byte(6));  // left 6
        lcd.print("CREATE");
        lcd.setCursor(8, 1);
        lcd.write(byte(7));  // right 7
        lcd.print("OPTION+");
      }
      break;
    case 6:
      lcd.clear();
      if (isUpper) {
        // lcd.print("U=TRIAN' D=CROSS");
        lcd.setCursor(0, 1);
        lcd.write(byte(4));  // up 4
        lcd.print("X(");
        lcd.write(byte(0));  // triangle 0
        lcd.print(")");
        lcd.setCursor(8, 1);
        lcd.write(byte(5));  // down 5
        lcd.print("B(");
        lcd.write(byte(3));  // cross  3
        lcd.print(")");
      } else {
        // lcd.print("L=SQUAR R=CIRCLE");
        lcd.setCursor(0, 1);
        lcd.write(byte(6));  // left 6
        lcd.print("Y(");
        lcd.write(byte(1));  // square 1
        lcd.print(")");
        lcd.setCursor(8, 1);
        lcd.write(byte(7));  // right 7
        lcd.print("A(");
        lcd.write(byte(2));  // circle 2
        lcd.print(")");
      }
      break;
    case 7:
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.write(byte(6));  // left 6
      lcd.print("L3");
      lcd.setCursor(8, 1);
      lcd.write(byte(7));  // right 7
      lcd.print("R3");
      break;
  }
  isUpper = !isUpper;
}

/* ============================================================== */

void loop() {

  modeNow = read_LCD_buttons(analogRead(0));

  //SELECTでモード切り替え
  if (modeNow == btnSELECT && modeOld == btnNONE) {
    steyMode0 = !steyMode0;
    toggle++;
    if (toggle > 7) {
      toggle = 1;
    }
    previousModeMillis = millis();  // モード切り替え時刻を記録
    modeChanged = true;             // モードが切り替わったことをフラグで示す
    delay(100);
  }

  modeOld = modeNow;

  // 1列目LCDとボタン
  switch (toggle) {
    case 1:
      mode1();
      lcd.setCursor(0, 0);
      lcd.print("M1 ");
      lcd.print("L AnalogStick");
      break;
    case 2:
      mode2();
      lcd.setCursor(0, 0);
      lcd.print("M2 ");
      lcd.print("R AnalogStick");
      break;
    case 3:
      mode3();
      lcd.setCursor(0, 0);
      lcd.print("M3 ");
      lcd.print("Side Button  ");
      break;
    case 4:
      mode4();
      lcd.setCursor(0, 0);
      lcd.print("M4 ");
      lcd.print("Hat Button   ");
      break;
    case 5:
      mode5();
      lcd.setCursor(0, 0);
      lcd.print("M5 ");
      lcd.print("Select Button");
      break;
    case 6:
      mode6();
      lcd.setCursor(0, 0);
      lcd.print("M6 ");
      lcd.print("Action Button");
      break;
    case 7:
      mode7();
      lcd.setCursor(0, 0);
      lcd.print("M7 ");
      lcd.print("Stick Button");
      break;
  }

  // 2列目LCD表示切り替え
  unsigned long currentMillis = millis();
  if (currentMillis - previousModeMillis >= modeInterval || modeChanged) {
    previousModeMillis = currentMillis;
    screenDisplay();
    modeChanged = false;
  }
}