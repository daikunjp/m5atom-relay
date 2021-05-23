#include <M5Atom.h>

#define SWITCH 26
#define SLEEPTIME 3600000000 /* 1000000マイクロ秒 × 3600 */

void setup() {
  M5.begin(true, false, true);
  pinMode(SWITCH, OUTPUT);
  // 一回LOWにしとかないとうまく起動してくれない
  digitalWrite(SWITCH, LOW);
  Serial.print("switch low ");
  delay(1000);
  // 3秒くらいONにしないと起動しないときがある
  digitalWrite(SWITCH, HIGH);
  Serial.print("switch high");
  delay(3000);
  digitalWrite(SWITCH, LOW);
  Serial.print("switch low");
  esp_deep_sleep(SLEEPTIME);
}

void loop() {
}