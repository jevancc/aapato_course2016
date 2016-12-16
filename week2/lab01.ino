// Filename: lab01.ino
// Description: AaPaTo Maker Course 2016 week2 lab01 sample code
// Author: Jevan Chan <jevan0307@gmail.com>
// Last update: Dec 16, 2016

// 宣告一個長度是 3 的整數陣列，並將腳位編號放到陣列中
int led[3] = {7, 8, 12};

void setup() {
    // 初始化輸出腳位
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
}

void loop() {
    // 亮起第一顆 LED 燈
    digitalWrite(led[0], HIGH);
    delay(1000);
    // 熄滅第一顆 LED 燈
    digitalWrite(led[0], LOW);
    delay(1000);

    // 亮起第二顆 LED 燈
    digitalWrite(led[1], HIGH);
    delay(1000);
    // 熄滅第二顆 LED 燈
    digitalWrite(led[1], LOW);
    delay(1000);

    // 亮起第三顆 LED 燈
    digitalWrite(led[2], HIGH);
    delay(1000);
    // 熄滅第三顆 LED 燈
    digitalWrite(led[2], LOW);
    delay(1000);
}
