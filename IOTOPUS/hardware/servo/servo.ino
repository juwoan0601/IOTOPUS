#include <Servo.h> 
#include <SoftwareSerial.h>
#define servoPinL 9
#define servoPinR 10
#define onAngle 60
#define offAngle 120
#define CODE_ON '1'
#define CODE_OFF '2'

SoftwareSerial BTSerial(2,3);
Servo servoL;
Servo servoR; 

int angle = offAngle; // servo position in degrees 0
int state = false; // on/off state

void setup() 
{ 
    Serial.begin(9600);
    BTSerial.begin(9600);
    servoL.attach(servoPinL); 
    servoR.attach(servoPinR); 
    Serial.println("Welcome to IOTOPUS - Servo system.");
} 

void loop() { 
  while (BTSerial.available()){
    byte data = BTSerial.read();
    Serial.println(data);
    if (data == CODE_OFF && state == true) {
      for(angle = offAngle; angle > onAngle; angle--) { 
        servoL.write(angle); 
        servoR.write(angle); 
        delay(10);  
      }
      state = false;
    }
    else if (data == CODE_ON && state == false) {
      for(angle = onAngle; angle < offAngle; angle++) { 
        servoL.write(angle); 
        servoR.write(angle); 
        delay(10);  
      } 
      state = true;
    }
    BTSerial.write(data);
  }
  while (Serial.available()){
    byte data = Serial.read();
    Serial.println(data);
    if (data == CODE_OFF && state == true) {
      for(angle = offAngle; angle > onAngle; angle--) {
        servoL.write(angle); 
        servoR.write(angle); 
        delay(10);  
      }
      state = false;
    }
    else if (data == CODE_ON && state == false) {
      for(angle = onAngle; angle < offAngle; angle++) { 
        servoL.write(angle); 
        servoR.write(angle); 
        delay(10);  
      }
      state = true;
    }
    BTSerial.write(data);
  }
} 
