//The purpose of this file is to test the wiring of the Arduino, breadboard, and LEDs.

#define Green 3
#define Yellow1 4
#define Yellow2 5
#define Red 6

void setup() {

pinMode(Green, OUTPUT);
  pinMode(Yellow1, OUTPUT);
  pinMode(Yellow2, OUTPUT);
  pinMode(Red, OUTPUT);

}

void loop() {
digitalWrite(Green, HIGH);
delay(500);
digitalWrite(Green, LOW);
digitalWrite(Yellow1, HIGH);
delay(500);
digitalWrite(Yellow1, LOW);
digitalWrite(Yellow2, HIGH);
delay(500);
digitalWrite(Yellow2, LOW);
digitalWrite(Red, HIGH);
delay(500);
digitalWrite(Red, LOW);
}
