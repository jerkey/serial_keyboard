// serial_keyboard.ino for emulating a keyboard with serial input
// use it when you forgot a keyboard, or need one computer to type
// into another.  Or use it with a serial bluetooth dongle.
//
// originally keyboard_bt.ino
// by http://github.com/jerkey
// from http://www.instructables.com/id/Using-Arduino-Leonardo-as-mouse-and-keyboard-contr/
// (unfortunately the program above does not work with enter, backspace, etc :)
// see also:
// http://joshfire-tech.tumblr.com/post/65032568887/arduino-keyboard-emulation-send-real-key-codes
// https://www.arduino.cc/en/Reference/KeyboardModifiers

#include<SoftwareSerial.h>
SoftwareSerial RC(9, 8);// on black CP2102 board,  RX=PB5  TX=PB4
char RCD;
void setup() {
  RC.begin(9600);
  Keyboard.begin();
}

void loop() {
  if (RC.available() > 0) {
    RCD = RC.read();
    RC.println((byte)RCD); //serial print the ASCII code as recieved, byte by byte
    if (RCD <= 27) { // if user typed a control character
      Keyboard.press(KEY_LEFT_CTRL); // press control
      Keyboard.press(RCD+96); // and then the corresponding letter
      Keyboard.releaseAll();
    } else { // otherwise just send the key pressed
      Keyboard.write(RCD);
    }
  }
}
