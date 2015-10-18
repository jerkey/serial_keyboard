#include<SoftwareSerial.h>
SoftwareSerial RC(9, 8);// bluetooth TX,RX
char RCD;
void setup() {
  RC.begin(9600);
  Keyboard.begin();
}

void loop() {
  if (RC.available() > 0) {
    RCD = RC.read();//recieve value from serial
    RC.println((byte)RCD);
    if (RCD <= 27) {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(RCD+96);
      Keyboard.releaseAll();
    } else {
      Keyboard.write(RCD);//print char as recieved byte by byte
    }
  }
}
