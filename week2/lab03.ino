// Filename: lab03.ino
// Description: AaPaTo Maker Course 2016 week2 lab03 sample code
// Author: Jevan Chan <jevan0307@gmail.com>
// Last update: Dec 16, 2016

// 宣告一個長度是 3 的整數陣列，並將腳位編號放到陣列中
int led[3] = {7, 8, 12};
// 整數變數紀錄現在亮的是哪一顆 LED 燈
int lightLED;
// 整數變數紀錄現在是正序亮燈還是逆序亮燈
int direction;

void setup() {
    // 初始化輸出腳位
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
}

void loop() {
    // 正序亮燈
    for(int lightLED = 0; lightLED <= 2; lightLED++){
        // 亮起 LED 燈
        digitalWrite(led[lightLED], HIGH);
        delay(1000);
        // 熄滅 LED 燈
        digitalWrite(led[lightLED], LOW);
        delay(1000);
    }

    // 逆序亮燈
    // 頭尾編號跳過，如果沒有跳過的話頭尾兩顆 LED 燈會在同一次循環中亮兩次
    for(int lightLED = 2 - 1; lightLED >= 0 + 1; lightLED--){
        // 亮起 LED 燈
        digitalWrite(led[lightLED], HIGH);
        delay(1000);
        // 熄滅 LED 燈
        digitalWrite(led[lightLED], LOW);
        delay(1000);
    }
}
