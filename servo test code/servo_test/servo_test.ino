#include <Servo.h>

// Create a servo object
Servo servoMotor;

void setup() {
  // Attach the servo to pin 9
  servoMotor.attach(9);
}

void loop() {
  // Call the leftTurn() function to turn the servo 90 degrees to the left
  leftTurn();
  delay(2000);

  // Call the rightTurn() function to turn the servo 90 degrees to the right
  rightTurn();
  delay(2000);
}

void leftTurn() {
  servoMotor.write(0);  // Set servo angle to 0 degrees (leftmost position)
  delay(500);          // Wait for the servo to reach the desired position
}

void rightTurn() {
  servoMotor.write(180);  // Set servo angle to 180 degrees (rightmost position)
  delay(500);            // Wait for the servo to reach the desired position
}
