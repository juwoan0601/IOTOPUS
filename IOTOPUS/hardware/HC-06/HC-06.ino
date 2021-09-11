#include <SoftwareSerial.h>
#define PIN1 4
#define PIN2 5
#define PIN3 6
#define PIN4 7
bool STAT1 = false;
bool STAT2 = false;
bool STAT3 = false;
bool STAT4 = false;
SoftwareSerial BTSerial(2,3);

void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
}

void loop() {
  while (BTSerial.available()){
    byte data = BTSerial.read();
    if (data == '1') {
      if (STAT1){digitalWrite(PIN1,LOW); STAT1=false;}
      else{digitalWrite(PIN1,HIGH);STAT1=true;}  
    }
    if (data == '2') {
      if (STAT2){digitalWrite(PIN2,LOW); STAT2=false;}
      else{digitalWrite(PIN2,HIGH);STAT2=true;}  
    }
    if (data == '3') {
      if (STAT3){digitalWrite(PIN3,LOW); STAT3=false;}
      else{digitalWrite(PIN3,HIGH);STAT3=true;}  
    }
    if (data == '4') {
      if (STAT4){digitalWrite(PIN4,LOW); STAT4=false;}
      else{digitalWrite(PIN4,HIGH);STAT4=true;}  
    }
    Serial.write(data);
  }
  while (Serial.available()){
    byte data = Serial.read();
    if (data == '1') {
      if (STAT1){digitalWrite(PIN1,LOW); STAT1=false;}
      else{digitalWrite(PIN1,HIGH);STAT1=true;}  
    }
    if (data == '2') {
      if (STAT2){digitalWrite(PIN2,LOW); STAT2=false;}
      else{digitalWrite(PIN2,HIGH);STAT2=true;}  
    }
    if (data == '3') {
      if (STAT3){digitalWrite(PIN3,LOW); STAT3=false;}
      else{digitalWrite(PIN3,HIGH);STAT3=true;}  
    }
    if (data == '4') {
      if (STAT4){digitalWrite(PIN4,LOW); STAT4=false;}
      else{digitalWrite(PIN4,HIGH);STAT4=true;}  
    }
    BTSerial.write(data);
  }

}
