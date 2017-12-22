/*
 *  2017Fall AaPaTo 卓爾榮譽學會創課營
 *  藍芽自走車範例程式碼
 *
 *  Author: JevanChan
 *  LastUpdate: 2017/12/22
 *
 */
 
#include "SoftwareSerial.h"
#include "Wire.h"

// 馬達驅動腳位
int L1 = 10, L2 = 9, R1 = 6, R2 = 5;

// =========馬達控制副程式===========
// 用 analogWrite 對左右輪輸出指定的電壓，使得單邊輪子向前或向後轉
// 參考第五週講義

// 讓左輪往前轉，用輸出 power 大小的電壓
void Left_Forward(int power){
    analogWrite(L1, power);
    analogWrite(L2, 0);
}
// 讓左輪往後轉，用輸出 power 大小的電壓
void Left_Backward(int power){
    analogWrite(L1, 0);
    analogWrite(L2, power);
}
// 讓右輪往前轉，用輸出 power 大小的電壓
void Right_Forward(int power){
    analogWrite(R1, power);
    analogWrite(R2, 0);
}
// 讓右輪往後轉，用輸出 power 大小的電壓
void Right_Backward(int power){
    analogWrite(R1, 0);
    analogWrite(R2, power);
}
// ---------馬達控制副程式-----------


// ========自走車移動副程式==========
// 組合上面的馬達控制副程式，同時控制兩個輪子讓車體能前後左右旋轉移動
// power 的數值可以依照實驗中實際情況自由調整
// 參考第六週課程講義

// 車體向左轉
void Move_Left() {
    Right_Forward(127);
    Left_Backward(127);
}
// 車體向右轉
void Move_Right() {
    Left_Forward(127);
    Right_Backward(127);
}
// 車體向前進
void Move_Forward() {
    Left_Forward(127);
    Right_Forward(127);
}
// 車體向左轉
void Move_Backward() {
    Left_Backward(127);
    Right_Backward(127);
}
// 車體停止
void Stop() {
    // keep
}
//  -------自走車移動副程式----------


// ==========藍芽指令接收程式碼==========
// 呼叫副程式從藍芽模組取得手機傳送的指令文字
// 指令文字會被儲存在變數 command 中
// 參考第六週課程講義

String command;
int insize;
// 藍芽模組腳位
SoftwareSerial I2CBT(11, 12);

void Get_BT_Command() {
    command = "";
    insize = I2CBT.available();
    if( insize > 0 ){
        for(int i = 0; i <= insize-1; i++){
          command += char(I2CBT.read());
        }
    }
}
// ----------藍芽指令接收程式碼-----------

void setup(){
    // 初始化與設定 Serial Monitor
    Serial.begin(9600);
    // 初始化與設定藍芽模組
    I2CBT.begin(9600);

    // 初始化馬達驅動腳位
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
}

void loop(){
    // 接收藍芽指令
    Get_BT_Command();

    // 根據藍芽指令執行相對應的移動副程式
    if (command == "forth") {
        Move_Forward();
    }
    else if (command == "back") {
        Move_Backward();
    }
    else if (command == "left") {
        Move_Left();
    }
    else if (command == "right") {
        Move_Right();
    }
    // ...其他你自己的指令

    delay(800);
}
