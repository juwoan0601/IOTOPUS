#include <Servo.h> 
#include <SoftwareSerial.h>
#define servoPin 9
#define onAngle 60
#define offAngle 140

SoftwareSerial BTSerial(2,3);
Servo servo; 

int angle = onAngle; // servo position in degrees 
int state = false; // on/off state

void setup() 
{ 
    Serial.begin(9600);
    BTSerial.begin(9600);
    servo.attach(servoPin); 
    Serial.println("Welcome to IOTOPUS - Servo system.");
} 

void loop() { 
  while (BTSerial.available()){
    byte data = BTSerial.read();
    Serial.println(data);
    if (data == '0' && state == true) {
      for(angle = onAngle; angle < offAngle; angle++) { 
        servo.write(angle); 
        delay(15);  
      }
      state = false;
    }
    if (data == '1' && state == false) {
      for(angle = offAngle; angle > onAngle; angle--) { 
        servo.write(angle); 
        delay(15);  
      } 
      state = true;
    }
    BTSerial.write(data);
  }
  while (Serial.available()){
    byte data = Serial.read();
    Serial.println(data);
    if (data == '0' && state == true) {
      for(angle = onAngle; angle < offAngle; angle++) { 
        servo.write(angle); 
        delay(15);  
      }
      state = false;
    }
    if (data == '1' && state == false) {
      for(angle = offAngle; angle > onAngle; angle--) { 
        servo.write(angle); 
        delay(15);  
      }
      state = true;
    }
    BTSerial.write(data);
  }
} 
