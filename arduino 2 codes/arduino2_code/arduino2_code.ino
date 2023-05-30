const int IRSensor = A1;
const int ledIR = 13;
const int ledSmoke = 12;
int IRinputVal = 0;
int smokeA0 = A0;
int buzzer = 11;
float smokeSensorValue;
const int LDR = A2;
const int ledLDR = 10;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(ledIR, OUTPUT);  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(ledSmoke, OUTPUT);
  pinMode(ledLDR, OUTPUT);
  pinMode(IRSensor, INPUT);
  pinMode(smokeA0, INPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
  //Serial.println("Gas sensor warming up!");
  //delay(20000);  // allow the MQ-6 to warm up
  noTone(buzzer);
}


void checkLDR() {
  int ldr_value = 0;
  ldr_value = analogRead(LDR);
 // Serial.println(ldr_value);
  delay(500);
  if (ldr_value < 800) {
    digitalWrite(ledLDR, HIGH);
  } else {
    digitalWrite(ledLDR, LOW);
  }
}



void checkFlame() {

  smokeSensorValue = analogRead(smokeA0);
  if (smokeSensorValue > 150) {
    //Serial.print(" | Smoke detected!");
    tone(buzzer, 1000, 200);
    digitalWrite(ledSmoke, HIGH);
  } else {
    //Serial.print(" | Smoke  not detected!");
    digitalWrite(ledSmoke, LOW);
    noTone(buzzer);
  }
  delay(2000);  // wait 2s for next reading
}


void checkIR() {
  if (analogRead(IRSensor) < 900)  //Check the sensor output
  {
    digitalWrite(ledIR, HIGH);
    // set the LED on
  } else {
    digitalWrite(ledIR, LOW);  // set the LED off
  }
  IRinputVal = analogRead(IRSensor);
  Serial.println(IRinputVal);
  delay(200);
}



void loop() {

  checkFlame();
  checkIR();
  checkLDR();
}
