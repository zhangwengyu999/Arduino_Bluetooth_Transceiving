// Made by Mike_Zhang
// https://ultrafish.cn
// 传输端有5个传感器控制接收端连接的5个舵机

// RX
// 接收端程序
#include<SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial BT(5,3); // RX:5, TX:3 实例化一个名为BT的SoftwareSerial对象
int val;
int zeroCounter = 0; // 用于000校验符的计数
Servo myServoone;
Servo myServotwo;
Servo myServothree;
Servo myServofour;
Servo myServofive;
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  myServoone.attach(0);
  myServotwo.attach(1);
  myServothree.attach(2);
  myServofour.attach(3);
  myServofive.attach(4);
}
void loop() {
    // 000校验符检测
    while (zeroCounter != 3){ // 循环直到检测到连续的000
      val = BT.read();
      if (val == 0){
        zeroCounter++; // 若检测到0, 则计数加1
        }
      else{
        zeroCounter = 0; // 若检测到不是0, 则计数直接重置为0
        }
    delay(10);
    }
    // 000校验完成后开始接收数据, 保证不会偏移
    int i = 0;
    while (i < 5){
      if (i == 0){
        val = BT.read();
        if (val != -1){
          myServoone.write(val);
          i++;
        }
      }
      if (i == 1){
        val = BT.read();
        if (val != -1){
          myServotwo.write(val);
          i++;
        }
      }
      if (i == 2){
        val = BT.read();
        if (val != -1){
          myServothree.write(val);
          i++;
        }
      }
      if (i == 3){
        val = BT.read();
        if (val != -1){
          myServofour.write(val);
          i++;
        }
      }
      if (i == 4){
        val = BT.read();
        if (val != -1){
          myServofive.write(val);
          i++;
        }
      }
    }
    zeroCounter = 0; // 一组数据接收完成后, zeroCounter重置为0, 开始下一轮000校验
    delay(50);
}
// Made by Mike_Zhang
// https://ultrafish.cn
