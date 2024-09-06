# KeyRegistration
Arduino Leonardoに接続したLCD KeyPad Shieldのボタンを使って、ReaSnow S1にジョイスティックとして登録するためのスケッチです。

# 動作環境
動作環境は下記の通りです。
- Arduino Leonardo
- [LCD KeyPad Shield](https://amzn.to/3AsXnla)
- Arduino IDE（2.3.2）
- Arduino AVR Boards（1.8.6）

Arduino IDE は Arduino AVR Boards は最新(2024.7現在)の 1.8.6で動作確認しております。

# 使用方法
- **`NSControlLibrary`** [NSControlLibrary](https://github.com/Kumataku-JP/NSControlLibrary.git) を /document/Arduino フォルダ内にある libraries フォルダに入れてください。
- KeyRegistration フォルダを sketch フォルダに入れてください。
- Arduino Leonardoに書き込み
- Arduino Leonardo に LCD KeyPad Shieldを接続
- ReaSnow S1に接続
- ReaSnowのスマートフォンアプリを開きキー配置編集

## 操作方法
- selectボタンでモード変更でき、各ボタンが4つずつM1〜M7に割り振られています。
- LCD KeyPad Shieldに各項目が表示されます。ReaSnowアプリのキー配置編集で任意のボタンを割り当ててください。

	| SELECTボタン|   				| UPボタン  | DOWNボタン  | LEFTボタン  | RIGHTボタン  |
	|:-----------|:----------|:----------|:----------|:----------|:----------|
	|M1			 | L アナログスティック    | 前    | 後ろ    | 左    | 右    |
	|M2 			 | R アナログスティック    | 前    | 後ろ    | 左    | 右    |
	|M3			 | サイドボタン			    | L (L1) | ZR (R2) | ZL (L2) | R (R1)    |
	|M4			 | 十字ボタン    		| 上    | 下    | 左    | 右    |
	|M5			 | セレクトボタン    | タッチパッド※ | PSボタン | クリエイト※  | オプション  |
	|M6			 | アクションボタン    | △    | ×    | □    | ○    |
	|M7			 | スティックボタン    |     |     | L3    | R3    |
- ※：SwitchのコントローラーとDualSenseのコントローラーでは、マイナスボタンとキャプチャーボタンの配列がタッチパッドとクリエイティブボタンが逆になります。
	- ○×の決定キャンセルボタンが逆の仕様に合わせて、マクロスケッチで対応したコードを適応させることをおすすめします。  consoleType = 0がSwitch、 = 1がPS5仕様
	
	```
	// Nintendo Switchは"0"、PlayStation 5は"1"
	bool consoleType = 1; 
	unsigned char confirmButton;
	unsigned char cancelButton;
	unsigned int minusButton;
	unsigned int captureButton;
	
	void setup() {
	/* 決定ボタン */
  	confirmButton = (consoleType == 0) ? Button::A : Button::B;  // Switch
  	cancelButton = (consoleType == 0) ? Button::B : Button::A;   // PS5
  	/* CREATEボタン・タッチパッド／マイナスボタン・キャプチャーボタン */
  	minusButton = (consoleType == 0) ? Button::MINUS : Button::CAPTURE;    // Switch
  	captureButton = (consoleType == 0) ? Button::CAPTURE : Button::MINUS;  // PS5
	}
	```


## 修正履歴
- README説明追記
- v1.0.1  sketch修正 M3.サイドボタンのLCD表示誤植修正


# license 
MIT
