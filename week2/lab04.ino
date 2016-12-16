// Filename: lab04.ino
// Description: AaPaTo Maker Course 2016 week2 lab04 sample code
// Author: Jevan Chan <jevan0307@gmail.com>
// Last update: Dec 16, 2016

// 宣告一個長度是 5 的整數陣列，分別代表不同的亮度
int bright[5] = {0, 255, 511, 767, 1023};
// 輸出腳位
int led = 9;

void setup() {
    // 初始化輸出腳位
    pinMode(led, OUTPUT);
}

void loop() {
    // 用 for 迴圈依次亮五個不同的強度
    for(int i = 0; i < 5; i++){
        analogWrite(led, bright[i]);
        delay(1000);
    }
}
