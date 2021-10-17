#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int JoyStick_X = A0; //x
int JoyStick_Y = A1; //y
void setup() {
  mySwitch.enableTransmit(10);
  Serial.begin(9600);
}

void loop() {
  int x, y;
  x = analogRead(JoyStick_X) / 2;
  y = analogRead(JoyStick_Y) / 2;
  mySwitch.send((999000 + x), 24);
  mySwitch.send((888000 + y), 24);
  //Serial.print(x);
  Serial.println(y);
}
