#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);

void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);

}

void loop() {
  while (BTSerial.available()){
    byte data = BTSerial.read();
    Serial.write(data);
  }
  while (Serial.available()){
    byte data = Serial.read();
    BTSerial.write(data);
  }

}
