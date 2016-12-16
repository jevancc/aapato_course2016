// Filename: lab05.ino
// Description: AaPaTo Maker Course 2016 week2 lab05 sample code
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

    // 最開始先亮第一顆 LED
    lightLED = 0;
    // 一開始先以正序亮燈 (0號 -> 1號 -> 2號)
    direction = 1;
}

void loop() {
    // 讀取電壓數值，並存到整數變數 sensorValue
    int sensorValue = analogRead(A0);

    // 亮起 LED 燈
    digitalWrite(led[lightLED], HIGH);
    // 等待秒數與讀取到的電壓數值有關，最多等待 1023 毫秒，最少等待 0 秒
    delay(sensorValue);
    // 熄滅 LED 燈
    digitalWrite(led[lightLED], LOW);
    delay(sensorValue);

    // 判斷這次亮的是不是頭尾的 LED 燈，如果是的話切換方向
    if( lightLED == 2 ){
        direction = -1;
    }
    else if(lightLED == 0){
        direction = 1;
    }

    // 將要亮的 LED 編號移往下一個
    lightLED += direction;
}
