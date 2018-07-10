#include <dht.h>
#include <stdio.h>
//defining pin numbers
#define Green 3
#define Yellow1 4
#define Yellow2 5
#define Red 6
#define trigPin 9
#define echoPin 10

#define DHT11 7
dht DHT;

//defining distances
#define Distance_MIN 0
#define Distance_MAX 35
#define Distance_1 50
#define Distance_2 65
#define Distance_3 80
#define Distance_4 95

void setup()
{
  pinMode(Green, OUTPUT);
  pinMode(Yellow1, OUTPUT);
  pinMode(Yellow2, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(DHT11, INPUT); // Sets the DHT11 pin as an Input
}


void loop() 
{
 
{
    //getting temperature and humidity data using a DHT-11 sensor to improve accuracy.
  int chk = DHT.read11(DHT11);
}
  
float distance, duration;
  // 10 microsecond pulse from trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns thetravel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance, where 0.0331 is the speed of sound in centimeters per microsecond. Also factoring in temperature measurements to increase accuracy. Speed of sound can vary by as much as 30 m/s in Canada's climate. The returned value is then divided by 2 to account for return journey of pulse.
  //distance = (duration*(0.0331+(0.60*DHT.temperature)))/2;
  distance = duration*0.0343/2; 
  // Perfect!
  if (distance >= Distance_MIN & distance < Distance_MAX)
  {
    digitalWrite(Green, HIGH);
    digitalWrite(Yellow1, HIGH);
    digitalWrite(Yellow2, HIGH);
    digitalWrite(Red, HIGH); 
  }
  // Almost there...
  else if (distance >= Distance_MAX & distance < Distance_1)
  {
    digitalWrite(Green, HIGH);
    digitalWrite(Yellow1, HIGH);
    digitalWrite(Yellow2, HIGH);
    digitalWrite(Red, LOW); 
  }
  // Closer...
  else if (distance >= Distance_1 & distance < Distance_2)
  {
    digitalWrite(Green, HIGH);
    digitalWrite(Yellow1, HIGH);
    digitalWrite(Yellow2, LOW);
    digitalWrite(Red, LOW); 
  }
  // Getting close
  else if (distance >= Distance_2 & distance < Distance_3)
  {
    digitalWrite(Green, HIGH);
    digitalWrite(Yellow1, LOW);
    digitalWrite(Yellow2, LOW);
    digitalWrite(Red, LOW);
  }
  // Car is in garage
  else if (distance >= Distance_3 & distance < Distance_4)
  {
    digitalWrite(Green, LOW);
    digitalWrite(Yellow1, LOW);
    digitalWrite(Yellow2, LOW);
    digitalWrite(Red, LOW);
  }
  // No car in garage or car is invisible :)
  else
  {
    digitalWrite(Green, LOW);
    digitalWrite(Yellow1, LOW);
    digitalWrite(Yellow2, LOW);
    digitalWrite(Red, LOW);   
  }
  delay(250);
}
