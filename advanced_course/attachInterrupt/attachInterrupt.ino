// 指定中斷編號
// Arduino Uno 上有兩個外部中斷，
// 編號 0 在 pin2，編號 1 在 pin3，
// 若把InterruptNum 改為 1 則 Button 變數須改為3
int InterruptNum = 0 ; 

// 指定 Button 與 Led 的腳位
int Button = 2 , Led = 13;
bool ButtonState = false ;

void setup() {
  pinMode(Led, OUTPUT); 
  pinMode(Button, INPUT);
  Serial.begin(9600);
  
  /* 
   連接上外部中斷， attachInterrupt(interrupt, function, mode)
   第一個引數interrupt指定要用的中段編號，在Arduino上可為 0 或 1
   第二個引數指定中斷發生時要執行的副程式，需要自行定義 ( 如最下面的TOGGLE )
   第三個引數指定什麼情況要中斷，可指定為以下幾種
      - LOW: 當pin腳輸入為LOW時觸發中斷 ( 較少使用 )
      - RISING: 當pin腳輸入從LOW變成HIGH時觸發中斷
      - FALLING: 當pin腳輸入從HIGH變成LOW時觸發中斷
      - CHANGE : 當pin腳符合RISING或FALLING時就觸發中斷
   */
   attachInterrupt(InterruptNum, TOGGLE, FALLING);  // 試著解釋這行程式碼，並觀察不同模式下LED燈的改變模式
}

void loop() {
  // do nothing
  Serial.println(ButtonState);
  delay(1000);
}

void TOGGLE(){
  if (ButtonState==true){     // ButtonState == true
    ButtonState = false;
  }
  else{                       // ButtonState == false
    ButtonState = true;
  }
  digitalWrite(Led, ButtonState);
  
}

