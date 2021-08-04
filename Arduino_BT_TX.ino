// Made by Mike_Zhang
// https://ultrafish.cn
// 传输端有5个传感器控制接收端连接的5个舵机

// TX
// 发送端程序
#include<SoftwareSerial.h>
SoftwareSerial BT(5,3); // RX:5, TX:3 实例化一个名为BT的SoftwareSerial对象
int zero = 0;
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}
void loop() {
    // sensor one A0
    int Readone = analogRead(A0);
    int Outone = map(Readone, 1023, 880, 1, 100);

    // sensor two A1
    int Readtwo = analogRead(A1);
    int Outtwo = map(Readtwo, 270, 400, 0, 18);

    // sensor three A2
    int Readthree = analogRead(A2);
    int Outthree = map(Readthree, 280, 400, 18, 5);
    
    // sensor four A3
    int Readfour = analogRead(A3);
    int Outfour = map(Readfour, 1023, 700, 13, 5);

    // sensor five A4
    int Readfive = analogRead(A4);
    int Outfive = map(Readfive, 0, 1023, 0, 180);

    // 000 校验符号发送
    BT.write(zero);
    delay(10);
    BT.write(zero);
    delay(10);
    BT.write(zero);
    delay(10);
    
    // 传感器数据以特定顺序传输
    BT.write(Outone); // sensor one
    BT.write(Outtwo); /// sensor two
    BT.write(Outthree); // sensor three
    BT.write(Outfour); // sensor three
    BT.write(Outfive); // sensor five
    delay(50);
}
// Made by Mike_Zhang
// https://ultrafish.cn
