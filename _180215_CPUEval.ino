/*--------------------------------------------------
 CPU Evaluation Program
 
 作成者：鷺ノ宮わっふる
 作成日：18/02/15
 --------------------------------------------------*/

/*--------------------------------------------------
 グローバル変数（Arduinoピン定義）
 --------------------------------------------------*/
const int CLK = 2;
const int RESET = 3;  // RESETは同期でHIGHのときアクティブ

const int IM0 = 4;
const int IM1 = 5;
const int IM2 = 6;
const int IM3 = 7;
const int IM4 = 8;

const int INST0 = 9;
const int INST1 = 10;
const int INST2 = 11;
const int INST3 = 12;
const int INST4 = 13;

const int ADDR0 = 0;
const int ADDR1 = 1;
const int ADDR2 = 2;
const int ADDR3 = 3;
const int ADDR4 = 4;

/*--------------------------------------------------
 セットアップ関数
 機能：シリアルポート設定、各ピンイニシャライズ
 --------------------------------------------------*/
void setup() {
  // シリアル通信速度を9600bpsに設定
  Serial.begin(9600);

  // 出力ピン設定
  pinMode(CLK, OUTPUT);
  pinMode(RESET, OUTPUT);

  pinMode(IM0, OUTPUT);
  pinMode(IM1, OUTPUT);
  pinMode(IM2, OUTPUT);
  pinMode(IM3, OUTPUT);
  pinMode(IM4, OUTPUT);

  pinMode(INST0, OUTPUT);
  pinMode(INST1, OUTPUT);
  pinMode(INST2, OUTPUT);
  pinMode(INST3, OUTPUT);
  pinMode(INST4, OUTPUT);


  digitalWrite(IM0, LOW);
  digitalWrite(IM1, LOW);
  digitalWrite(IM2, LOW);
  digitalWrite(IM3, LOW);
  digitalWrite(IM4, LOW);

  digitalWrite(INST0, HIGH);
  digitalWrite(INST1, HIGH);
  digitalWrite(INST2, LOW);
  digitalWrite(INST3, LOW);
  digitalWrite(INST4, LOW);

  digitalWrite(RESET, HIGH);
  delay(1000);
  digitalWrite(CLK, LOW);
  digitalWrite(CLK, HIGH);
  delay(1000);
  digitalWrite(RESET, LOW);
  digitalWrite(CLK, LOW);

}

/*--------------------------------------------------
 メインloop関数
 --------------------------------------------------*/
void loop() {

  if ( 512 >= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 0, 0, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 0, 0, 1]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 >= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 0, 1, 0]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, HIGH);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 0, 1, 1]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, HIGH);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 >= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 1, 0, 0]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, HIGH);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, HIGH);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 1, 0, 1]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, HIGH);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, HIGH);
    digitalWrite(IM4, HIGH);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 >= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 1, 1, 0]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, HIGH);

    digitalWrite(INST0, LOW);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 0, 1, 1, 1]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, HIGH);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 >= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 0, 0, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 0, 0, 1]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, HIGH);
    digitalWrite(INST4, LOW);
  } 

  if ( 512 >= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 0, 1, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, LOW);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, HIGH);
  } 

  if ( 512 <= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 0, 1, 1]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, HIGH);
  } 

  if ( 512 >= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 1, 0, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  } 

  if ( 512 <= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 1, 0, 1]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, HIGH);
    digitalWrite(INST4, LOW);
  } 

  if ( 512 >= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 1, 1, 0]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, LOW);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  } 

  if ( 512 <= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 <= analogRead(ADDR3) && 512 >= analogRead(ADDR4) ) {
    Serial.println("ADDR[0, 1, 1, 1, 1]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, HIGH);
    digitalWrite(INST4, LOW);
  } 

  if ( 512 >= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4) ) {
    Serial.println("ADDR[1, 0, 0, 0, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  } 

  if ( 512 <= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4) ) {
    Serial.println("ADDR[1, 0, 0, 0, 1]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, HIGH);
    digitalWrite(INST4, LOW);
  }

  if ( 512 >= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4) ) {
    Serial.println("ADDR[1, 0, 0, 1, 0]");

    digitalWrite(IM0, HIGH);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, HIGH);

    digitalWrite(INST0, LOW);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, HIGH);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 >= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4) ) {
    Serial.println("ADDR[1, 0, 0, 1, 1]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, HIGH);
    digitalWrite(IM3, HIGH);
    digitalWrite(IM4, HIGH);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, LOW);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, HIGH);
  }

  if ( 512 >= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4) ) {
    Serial.println("ADDR[1, 0, 1, 0, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, HIGH);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  if ( 512 <= analogRead(ADDR0) && 512 >= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4) ) {
    Serial.println("ADDR[1, 0, 1, 0, 1]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, HIGH);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, HIGH);
    digitalWrite(INST4, LOW);
  }  

  if ( 512 >= analogRead(ADDR0) && 512 <= analogRead(ADDR1) && 512 <= analogRead(ADDR2) && 512 >= analogRead(ADDR3) && 512 <= analogRead(ADDR4)  ) {
    Serial.println("ADDR[1, 0, 1, 1, 0]");

    digitalWrite(IM0, LOW);
    digitalWrite(IM1, LOW);
    digitalWrite(IM2, LOW);
    digitalWrite(IM3, LOW);
    digitalWrite(IM4, LOW);

    digitalWrite(INST0, LOW);
    digitalWrite(INST1, HIGH);
    digitalWrite(INST2, LOW);
    digitalWrite(INST3, LOW);
    digitalWrite(INST4, LOW);
  }

  delay(100);
  digitalWrite(CLK, LOW);
  digitalWrite(CLK, HIGH);
  delay(200);
  digitalWrite(CLK, LOW);
  delay(100);

}







