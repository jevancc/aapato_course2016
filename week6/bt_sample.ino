#include "SoftwareSerial.h"
#include "Wire.h"

String command;
int insize;
SoftwareSerial I2CBT(11, 12);

void getBTData(){
  command = "";
  insize = I2CBT.available();
  if( insize > 0 ){
    for(int i = 0; i<=insize-1; i++){  
      command += char(I2CBT.read());
    }
  }
}

void setup(){
  Serial.begin(9600);
  I2CBT.begin(9600);
}

void loop(){
  getBTData();
  
  // 印出 command 到 Serial Monitor
  Serial.print("Command size:");
  Serial.println(insize);
  Serial.print("Command:");
  Serial.println(command);
  
  delay(800);
}
