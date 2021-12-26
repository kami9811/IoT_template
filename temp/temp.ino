#define TEMP 32

float a_in=10;          // アナログ入力値(0〜203)
float temp_c = 0;  // 摂氏値( ℃ )

void setup(){
  Serial.begin(115200);  // シリA0アル通信速度
  pinMode(TEMP,INPUT);
}

void loop(){
  // アナログピンから計測値を取得(0〜203)
  a_in = analogRead(TEMP);
  // 入力値を摂氏に換算
  temp_c = ((a_in / 4096 * 3.3) - 0.6) * 100;
  // 改行しながら出力
  Serial.print( temp_c );
  Serial.println("℃");
  // 1000ms待機
  delay(1000);
}
