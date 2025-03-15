#include <AFMotor.h>

#define lefts A0
#define rights A1

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);

  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);

  Serial.begin(9600);
}

void loop() {
  int leftVal = analogRead(lefts);
  int rightVal = analogRead(rights);

  Serial.print("Left: ");
  Serial.print(leftVal);
  Serial.print(" | Right: ");
  Serial.println(rightVal);

  if (leftVal <= 350 && rightVal <= 350) {
    // Move forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } 
  else if (leftVal <= 350 && rightVal > 350) {
    // Turn left
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  } 
  else if (rightVal <= 350 && leftVal > 350) {
    // Turn right
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } 
  else {
    // Stop if no line is detected
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }

  delay(100);
}
