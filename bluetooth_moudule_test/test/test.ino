#include <SoftwareSerial.h>
#include <Servo.h>


// Ultrasonic sensor pins
const int trigPin1 = 12;
const int echoPin1 = 13;

const int trigPin2 = 7;
const int echoPin2 = 9;

//motor A pins
const int motorAPin1 = 2;
const int motorAPin2 = 3;
const int enableA = 11;
//motor B pins
const int motorBPin1 = 4;
const int motorBPin2 = 5;
const int enableB = 6;
// Servo motor pin
const int servoPin = 9;
const int buzzerPin = 13;
int distance1 = 0;
int distance2 = 0;
Servo myServo;

SoftwareSerial BTSerial(8, 10);  // RX | TX

void setup() {
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
  Serial.begin(9600);

  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

void moveForward() {
  // Set motor A pins to move forward
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  analogWrite(enableA, 150);

  // Set motor B pins to move forward
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
  analogWrite(enableB, 150);
}

// Function to move the motors backward
void moveBackward() {
  // Set motor A pins to move backward
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  analogWrite(enableA, 200);


  // Set motor B pins to move backward
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
  analogWrite(enableB, 200);
}

// Function to turn the motors left
void turnLeft() {
  // Set motor A pins to move backward
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  analogWrite(enableA, 200);

  // Set motor B pins to move forward
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
  analogWrite(enableB, 200);
}

// Function to turn the motors right
void turnRight() {
  // Set motor A pins to move forward
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  analogWrite(enableA, 200);

  // Set motor B pins to move backward
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
  analogWrite(enableB, 200);
}

void stop() {
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, LOW);
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
}
void hornON() {
  digitalWrite(buzzerPin, HIGH);
}

// ultrasonic

// int getDistanceForward() {
//   digitalWrite(trigPin1, LOW);
//   //delayMicroseconds(2);

//   digitalWrite(trigPin1, HIGH);
//   //delayMicroseconds(10);
//   digitalWrite(trigPin1, LOW);

//   long duration = pulseIn(echoPin1, HIGH);

//   // Calculate distance in cm
//   int distance = duration * 0.034 / 2;

//   return distance;
// }


// int getDistanceBackward() {
//   digitalWrite(trigPin2, LOW);
//  // delayMicroseconds(2);

//   digitalWrite(trigPin2, HIGH);
//   //delayMicroseconds(10);
//   digitalWrite(trigPin2, LOW);

//   long duration = pulseIn(echoPin2, HIGH);

//   // Calculate distance in cm
//   int distance = duration * 0.034 / 2;

//   return distance;
// }





void loop() {


  //distance1 = getDistanceForward();
  //distance2 = getDistanceBackward();

  if (BTSerial.available()) {  // read from HC-05 and send to Arduino Serial Monitor
    char signal = BTSerial.read();
    Serial.println(signal);

    if (signal == 'L') {
      turnRight();
      Serial.println("moving right");

    } else if (signal == 'R') {
      turnLeft();
      Serial.println("moving left");

    } else if (signal == 'D' ) {
      moveBackward();
      Serial.println("moving backwards");

    } else if (signal == 'D' ) {
      moveBackward();
      Serial.println("obstacle stop");

    } else if (signal == 'U' ) {
      moveForward();
      Serial.println("moving forward normally");

    } else if (signal = 'U') {
      stop();
      Serial.println("Obstacke, Stop !!");
    } else if (signal == 'S') {
      stop();
      Serial.println("stop now !!");
    } else if (signal == 'H') {
      hornON();
    }
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
