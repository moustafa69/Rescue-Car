#include <Servo.h>

const int trigPin = 12;   // Ultrasonic sensor trigger pin
const int echoPin = 13;   // Ultrasonic sensor echo pin
const int servoPin = 9;   // Servo control pin

Servo myservo;
int angle = 0;            // Servo angle variable
int distance = 0;         // Distance measured by the sensor

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);   // Attaches the servo on the specified pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 1) {  // Rotate the servo from 0 to 180 degrees
    myservo.write(angle);                      // Set the servo position
    delay(15);                                 // Delay for servo movement
    
    distance = getDistance();                   // Measure the distance
    
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" degrees, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  for (angle = 180; angle >= 0; angle -= 1) {  // Rotate the servo back from 180 to 0 degrees
    myservo.write(angle);                      // Set the servo position
    delay(15);                                 // Delay for servo movement
    
    distance = getDistance();                   // Measure the distance
    
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" degrees, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  int distance = duration * 0.034 / 2;
  
  return distance;
}
