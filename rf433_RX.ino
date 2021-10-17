#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

String temporaryValue ;
int x, y = 0;
void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  rx();
}
void rx() {
  if (mySwitch.available()) {
    temporaryValue = String(mySwitch.getReceivedValue());
    if (temporaryValue.substring(0, 3) == "999") {
      x = temporaryValue.substring(3).toInt() ;
    }
    if (temporaryValue.substring(0, 3) == "888") {
      y = temporaryValue.substring(3).toInt() ;
    }
    Serial.print(x);
    Serial.println(y);
    //delay(100);
    if (x < 100) {
      Serial.println("gauche");
      delay(5);
    }
    if (x > 400) {
      Serial.println("droite");
      delay(5);
    }
    if (y < 100) {
      Serial.println("avance");
      delay(5);
    }
    if (y > 400) {
      Serial.println("recule");
      delay(5);
    }
    if (x > 101 && x < 399 || y > 101 && y < 399) {
      //Stop();
    }
    //mySwitch.resetAvailable();
  }
}
