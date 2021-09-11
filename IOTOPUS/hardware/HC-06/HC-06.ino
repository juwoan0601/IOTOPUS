#include <SoftwareSerial.h>
#define PIN1 4
#define PIN2 5
#define PIN3 6
#define PIN4 7
#define CODE_PIN1_ON '1'
#define CODE_PIN1_OFF '2'
#define CODE_PIN2_ON '3'
#define CODE_PIN2_OFF '4'
#define CODE_PIN3_ON '5'
#define CODE_PIN3_OFF '6'
#define CODE_PIN4_ON '7'
#define CODE_PIN4_OFF '8'

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
    if (data == CODE_PIN1_ON && STAT1==false) {digitalWrite(PIN1,HIGH); STAT1=true;}
    if (data == CODE_PIN1_OFF && STAT1==true) {digitalWrite(PIN1,LOW); STAT1=false;}
    if (data == CODE_PIN2_ON && STAT2==false) {digitalWrite(PIN2,HIGH); STAT2=true;}
    if (data == CODE_PIN2_OFF && STAT2==true) {digitalWrite(PIN2,LOW); STAT2=false;}
    if (data == CODE_PIN3_ON && STAT3==false) {digitalWrite(PIN3,HIGH); STAT3=true;}
    if (data == CODE_PIN3_OFF && STAT3==true) {digitalWrite(PIN3,LOW); STAT3=false;}
    if (data == CODE_PIN4_ON && STAT4==false) {digitalWrite(PIN4,HIGH); STAT4=true;}
    if (data == CODE_PIN4_OFF && STAT4==true) {digitalWrite(PIN4,LOW); STAT4=false;}
    Serial.write(data);
  }
  while (Serial.available()){
    byte data = Serial.read();
    if (data == CODE_PIN1_ON && STAT1==false) {digitalWrite(PIN1,HIGH); STAT1=true;}
    if (data == CODE_PIN1_OFF && STAT1==true) {digitalWrite(PIN1,LOW); STAT1=false;}
    if (data == CODE_PIN2_ON && STAT2==false) {digitalWrite(PIN2,HIGH); STAT2=true;}
    if (data == CODE_PIN2_OFF && STAT2==true) {digitalWrite(PIN2,LOW); STAT2=false;}
    if (data == CODE_PIN3_ON && STAT3==false) {digitalWrite(PIN3,HIGH); STAT3=true;}
    if (data == CODE_PIN3_OFF && STAT3==true) {digitalWrite(PIN3,LOW); STAT3=false;}
    if (data == CODE_PIN4_ON && STAT4==false) {digitalWrite(PIN4,HIGH); STAT4=true;}
    if (data == CODE_PIN4_OFF && STAT4==true) {digitalWrite(PIN4,LOW); STAT4=false;}
    BTSerial.write(data);
  }

}
