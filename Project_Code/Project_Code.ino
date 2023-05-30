#include <Servo.h>

// Ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;
//motor A pins
const int motorAPin1 = 2;
const int motorAPin2 = 3;
//const int enableA = ;
//motor B pins
const int motorBPin1 = 4;
const int motorBPin2 = 5;
//const int enableB = ;
// Servo motor pin
const int servoPin = 9;
//const int blueTXpin = ;
//const int blueRXpin = ;



Servo myServo;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor control pins as outputs
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);

  // Set trigPin as output and echoPin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach servo to the servoPin
  myServo.attach(servoPin);
  myServo.write(90); // Set servo to initial position (90 degrees)
}

void loop() {
  // Rotate servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15);

    // Measure the distance using the ultrasonic sensor
    int distance_cm = measureDistance();

    // Check if distance is 5cm or less
    if (distance_cm <= 5) {
      // Rotate servo 90 degrees to the left
      myServo.write(0);
      delay(500);

      // Rotate servo 90 degrees to the right
      myServo.write(180);
      delay(500);

      // Break the loop and continue rotating from 0 to 180 degrees
      break;
    }
  }

    if (Serial.available()) {
    // Read the incoming data
    char input = Serial.read();

    // Perform motor control based on the received command
    switch (input) {
      case 'F':
        moveForward();
        break;
      
      case 'B':
        moveBackward();
        break;

      case 'L':
        turnLeft();
        break;

      case 'R':
        turnRight();
        break;
      
      case 'S':
        stopMotors();
        break;

      case 'B':
        buzzerON();
        break;
      
      default:
        // Invalid command, do nothing
        break;
    }
  }
  
}

// Function to measure distance using ultrasonic sensor
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance_cm = duration * 0.034 / 2;
  return distance_cm;
}

void moveForward() {
  // Set motor A pins to move forward
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);

  // Set motor B pins to move forward
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
}

// Function to move the motors backward
void moveBackward() {
  // Set motor A pins to move backward
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);

  // Set motor B pins to move backward
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
}

// Function to turn the motors left
void turnLeft() {
  // Set motor A pins to move backward
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);

  // Set motor B pins to move forward
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
}

// Function to turn the motors right
void turnRight() {
  // Set motor A pins to move forward
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);

  // Set motor B pins to move backward
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
}
