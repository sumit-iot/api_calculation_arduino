#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int measurePin = A3; //Connect dust sensor to Arduino A0 pin
int ledPower = 8;
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 //pinMode(9,OUTPUT);
  //pinMode(10,OUTPUT);
  //pinMode(13,OUTPUT);
  //pinMode(12,OUTPUT);
  //pinMode(8,OUTPUT);
  lcd.begin(16, 2 );
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Dust");
  
  lcd.setCursor(9,11);
  lcd.print("AQI");
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int a = analogRead(A2);
  delay(100);
   voMeasured = analogRead(measurePin); // read the dust value
  

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
  calcVoltage = voMeasured * (5.0 / 1024.0);

  
  dustDensity = (170 * calcVoltage - 0.1);
  Serial.print(a);
  Serial.print("dust =  ");
  Serial.println(dustDensity);
  delay(100);
  digitalWrite(9,1);
  digitalWrite(13,1);
  digitalWrite(10,0);
  digitalWrite(12,0);
  // print out the value you read:
  
  if (a>=150){
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(9,0);
  digitalWrite(10,1);}
  else {
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(9,1);
  digitalWrite(10,0);}
    lcd.setCursor(0,0);
  lcd.print(dustDensity);
  lcd.setCursor(9,0);
  lcd.print(a);
   // delay in between reads for stability

}
