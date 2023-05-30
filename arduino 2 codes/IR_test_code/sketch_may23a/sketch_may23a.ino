const int IRSensor = A0;
int IRinputVal = 0;
const int ledIR = 13;
const int ledSmoke = 12;


void setup() {
  pinMode(ledIR, OUTPUT);    // Pin 13 has an LED connected on most Arduino boards:
  pinMode(IRSensor, INPUT);  //Pin 2 is connected to the output of proximity sensor
  pinMode(ledSmoke, OUTPUT)
    Serial.begin(9600);
}

void loop() {
  if (digitalRead(IRSensor) == HIGH)  //Check the sensor output
  {
    digitalWrite(ledIR, HIGH);  // set the LED on
  } else {
    digitalWrite(ledIR, LOW);  // set the LED off
  }
  IRinputVal = analogRead(IRSensor);
  Serial.println(IRinputVal);
  delay(1000);  // wait for a second
}


